package pt.isec.pd.server.data.database;

import javafx.util.Pair;
import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.client.model.data.ClientData;
import pt.isec.pd.shared_data.*;
import pt.isec.pd.shared_data.Responses.*;
import pt.isec.pd.utils.Log;
import pt.isec.pd.utils.Utils;

import javax.swing.plaf.synth.SynthUI;
import java.io.*;
import java.sql.*;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.Date;
import java.util.concurrent.TimeUnit;

public class DBHandler {
    private final Log LOG = Log.getLogger(DBHandler.class);
    private Connection connection;

    public DBHandler(String path) {
        try {
            connection = DriverManager.getConnection("jdbc:sqlite:" + path);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public int getCurrentVersion() {
        int version = 0;

        try {
            Statement statement = connection.createStatement();
            String sqlQuery = "PRAGMA user_version;";
            ResultSet resultSet = statement.executeQuery(sqlQuery);

             version = resultSet.getInt(1);

            statement.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return version;
    }


    public void updateVersion(List<String> listQuery) throws SQLException {
        Statement statement = connection.createStatement();

        int currentVersion = getCurrentVersion();

        String sqlQuery = "PRAGMA user_version = " + (currentVersion + 1);
        statement.execute(sqlQuery);

        for (String query : listQuery) {
            statement.executeUpdate("INSERT INTO versao (id,[query]) " +
                    " VALUES ('"+  (currentVersion + 1) + "'," +
                    "\""+ query + "\"\n" +
                    ");");
        }

        statement.close();
    }

    public void updateToNewVersion(Map<Integer,List<String>> versionQuerys) throws SQLException {
        Statement statement = connection.createStatement();

        for (var version : versionQuerys.entrySet()) {
            List<String> querys = version.getValue();
            updateVersion(querys);
            for (var query : querys) {
                statement.executeUpdate(query);
            }
        }
        LOG.log("Done updating...");
        statement.close();
    }

    public Map<Integer,List<String>> getListOfQuery(int myVersion, int newVersion) throws SQLException {
        Statement statement = connection.createStatement();
        Map<Integer,List<String>> versionQuerys = new HashMap<>();
        myVersion++;

        for (int i = myVersion; i <= newVersion; i++) {
            ResultSet result = statement.executeQuery("SELECT id," +
                    "\"query\"" +
                    " FROM versao WHERE id = " + i + " ORDER BY key asc;");
            versionQuerys.put(i,new ArrayList<>());
            while(result.next()) {
                result.getInt("id");
                versionQuerys.get(i).add(result.getString("query"));
            }

            result.close();
        }
        //Returns all needed updates

        statement.close();

        return versionQuerys;
    }

    //======================  ACTIONS ======================
    public synchronized Pair<Object,List<String>> register(ClientData clientData) throws IOException {
        int id = 0;     // 'id' is defined earlier because the users table can be empty
        int isAdmin = 0;
        int isAuthenticated = 0;
        boolean requestAccepted = true;
        String msg = "";
        String query;

        List<String> listQuery = new ArrayList<>();

        RegisterResponse response = new RegisterResponse();

        // Receives clients register data (format: username, name, password)
        Triple<String, String, String> data = (Triple<String, String, String>) clientData.getData();

        try {
            // Create a statement
            Statement statement = connection.createStatement();

            // Execute a query
            ResultSet result = statement.executeQuery(
                    "SELECT username,nome FROM utilizador"
            );

            // Verify if admin is registered
            if (data.getFirst().equalsIgnoreCase("admin") &&
                    data.getSecond().equalsIgnoreCase("admin"))
                isAdmin = 1;

            // If table has registered users, verify if username and name are unique
            while (result.next()) {
                String username = result.getString("username");
                String name = result.getString("nome");

                // Validate client username & name
                if (username.equals(data.getFirst())) {
                    msg = "User[" + data.getFirst() + "] already exists";
                    LOG.log(msg);
                    requestAccepted = false;
                    break;
                }
            }

            ResultSet nomeSet = statement.executeQuery(
                    "SELECT id FROM utilizador where nome='" + data.getSecond() + "'"
            );

            if (nomeSet.next()) {
                msg = "Name[" + data.getSecond() + "] already exists";
                LOG.log(msg);
                requestAccepted = false;
            }

            if (requestAccepted) {
                result = statement.executeQuery(
                        "SELECT max(id) from utilizador"
                );

                // Register user
                query = "INSERT INTO utilizador(id,username,nome,password,administrador,autenticado)"
                        + "VALUES("
                        + "'" + (result.getInt(1) + 1) + "',"
                        + "'" + data.getFirst() + "',"
                        + "'" + data.getSecond() + "',"
                        + "'" + data.getThird() + "',"
                        + "'" + isAdmin + "',"
                        + "'" + isAuthenticated + "')";

                msg = "User[" + data.getFirst() + "] has registered successfully";
                LOG.log(msg);
                clientData.setId(id);
                response.setMsg(msg);
                response.setSuccess(true);
                listQuery.add(query);

                statement.close();
                result.close();
                return new Pair<>(response,listQuery);
            }
        } catch (SQLException e) {
            msg = "Unable to get data from the database";
            LOG.log(msg);
        }

        response.setSuccess(false);
        response.setMsg(msg);

        return new Pair<>(response,listQuery);
    }

    public synchronized Pair<Object,List<String>> login(ClientData clientData) throws IOException {
        boolean requestAccepted = false;
        int isAuthenticated = 0;
        boolean isAdmin = false;
        String msg;
        String query;
        List<String> listQuery = new ArrayList<>();
        LoginResponse response = new LoginResponse();

            // Receives clients data (format: username, password)
            Pair<String, String> loginData = (Pair<String, String>) clientData.getData();

            try {
                // Database search
                Statement statement = connection.createStatement();
                ResultSet result = statement.executeQuery(
                        "SELECT id, username, password, administrador, autenticado FROM utilizador"
                );

                // If table has registered users
                while (result.next()) {
                    int id = result.getInt("id");
                    String username = result.getString("username");
                    String password = result.getString("password");
                    isAdmin = result.getBoolean("administrador");
                    boolean authenticated = result.getBoolean("autenticado");
                    // Validate login data and authentication
                    if (username.equals(loginData.getKey()) && password.equals(loginData.getValue()) && authenticated) {
                        isAuthenticated = 1;
                        break;
                    }
                    // Validate username & password
                    else if (username.equals(loginData.getKey()) && password.equals(loginData.getValue()) && !authenticated) {
                        requestAccepted = true;
                        clientData.setId(id);
                        break;
                    }
                }

                response.setId(clientData.getId());

                // The user was not found
                if (requestAccepted) {
                    query = "UPDATE utilizador SET autenticado = 1 WHERE id = '" + clientData.getId() + "'";

                    msg = "User[" + loginData.getKey() + "]  logged in successfully";
                    LOG.log(msg);
                    listQuery.add(query);
                    response.setMsg(msg);
                    response.setSuccess(true);
                    response.setAdmin(isAdmin);

                    statement.close();
                    result.close();

                    return new Pair<>(response,listQuery);
                }

                if (isAuthenticated == 0) {
                    msg = "The username " + loginData.getKey() + " or password are incorrect";
                    LOG.log(msg);
                } else {
                    msg = "This user " + loginData.getKey() + " is already authenticated";
                    LOG.log(msg);
                }

                response.setMsg(msg);
                response.setSuccess(false);
                statement.close();
                result.close();
            } catch(SQLException e) {
                msg = "Unable to get data from the database";
                LOG.log(msg);
                response.setMsg(msg);
                response.setSuccess(false);
            }

        return new Pair<>(response,listQuery);
    }

    public synchronized Pair<Object,List<String>> editClientData(ClientData clientData) throws IOException {
        boolean requestAccepted = true;
        String msg;
        String query;

        List<String> listQuery = new ArrayList<>();
        EditResponse response = new EditResponse();

        try {
            // Receive the new value from client
            String newValue = (String) clientData.getData();


                // Create statement
                Statement statement = connection.createStatement();

                switch (clientData.getAction()) {
                    case EDIT_NAME -> {
                        ResultSet result = statement.executeQuery(
                                "SELECT nome FROM utilizador"
                        );

                        while (result.next()) {
                            // Verify if its a unique username
                            if (newValue.equals(result.getString("nome"))) {
                                msg = "This name[" + newValue + "] already exists...";
                                LOG.log(msg);
                                response.setMsg(msg);
                                response.setSuccess(false);
                                requestAccepted = false;
                            }
                        }

                        // if unique=true, update value
                        if (requestAccepted) {
                            try {
                                query = "UPDATE utilizador SET nome = '" + newValue + "' WHERE id = '" + clientData.getId() + "'";
                                int rs = statement.executeUpdate(query);
                                if (rs == 1) {
                                    msg = "Name updated successfully";
                                    LOG.log(msg);
                                    response.setMsg(msg);
                                    response.setSuccess(true);
                                    listQuery.add(query);
                                }
                            } catch (SQLException e) {
                                msg = "Unable to update name[" + newValue + "]";
                                LOG.log(msg);
                                response.setMsg(msg);
                                response.setSuccess(false);
                            } finally {
                                result.close();
                            }
                        }
                    }
                    case EDIT_USERNAME -> {
                        ResultSet result = statement.executeQuery(
                                "SELECT username FROM utilizador"
                        );

                        while (result.next()) {
                            // Verify if its a unique username
                            if (newValue.equals(result.getString("username"))) {
                                msg = "This username[" + newValue + "] already exists...";
                                LOG.log(msg);
                                response.setMsg(msg);
                                response.setSuccess(false);
                                requestAccepted = false;
                            }
                        }

                        // if unique=true, update value
                        if (requestAccepted) {
                            try {
                                query = "UPDATE utilizador SET username = '" + newValue + "' WHERE id = '" + clientData.getId() + "'";
                                int rs = statement.executeUpdate(query);
                                if (rs == 1) {
                                    msg = "Username updated successfully";
                                    LOG.log(msg);
                                    response.setMsg(msg);
                                    response.setSuccess(true);
                                    listQuery.add(query);
                                }
                            } catch (SQLException e) {
                                msg = "Unable to update username[" + newValue + "]";
                                LOG.log(msg);
                                response.setMsg(msg);
                                response.setSuccess(false);
                            } finally {
                                result.close();
                            }
                        }

                        result.close();
                    }
                    case EDIT_PASSWORD -> {
                        ResultSet result = statement.executeQuery(
                                "SELECT password FROM utilizador WHERE id = '" + clientData.getId() + "'"
                        );

                        // Verify if the password it's the same
                        if (newValue.equals(result.getString("password"))) {
                            msg = "The password cant be the same";
                            LOG.log(msg);
                            response.setMsg(msg);
                            response.setSuccess(false);
                            requestAccepted = false;
                        }

                        // Update password
                        if (requestAccepted) {
                            try {
                                query = "UPDATE utilizador SET password = '" + newValue + "' WHERE id = '" + clientData.getId() + "'";
                                int rs = statement.executeUpdate(query);
                                if (rs == 1) {
                                    msg = "Password updated successfully";
                                    LOG.log(msg);
                                    response.setMsg(msg);
                                    response.setSuccess(true);
                                    listQuery.add(query);
                                }
                            } catch (SQLException e) {
                                msg = "Unable to update password";
                                LOG.log(msg);
                                response.setMsg(msg);
                                response.setSuccess(false);
                            } finally {
                                result.close();
                            }
                        }
                    }
                }

                if (statement != null) statement.close();
            } catch(SQLException e) {
                msg = "Unable to get data from the database";
                LOG.log(msg);
                response.setMsg(msg);
                response.setSuccess(false);
            }


        return new Pair<>(response,listQuery);
    }

    public synchronized Pair<Object,List<String>> consultPaymentsAwaiting(ClientData clientData) throws SQLException, IOException, ClassNotFoundException {
        List<Reserve> reserves = new ArrayList<>();
        ConsultUnpayedReservationResponse response = new ConsultUnpayedReservationResponse();
        Statement statement = connection.createStatement();

        // Execute query to get the clients name
        ResultSet clientResult = statement.executeQuery(
                "SELECT username FROM utilizador WHERE id = '" + clientData.getId() + "'"
        );

        String clientName = clientResult.getString(1);

        clientResult.close();

        // Execute query to search reserves
        ResultSet result = statement.executeQuery(
                "SELECT id,data_hora,id_utilizador,id_espetaculo FROM reserva where id_utilizador= " + clientData.getId() + " and pago= 0"
        );

        while(result.next()) {
            int id = result.getInt("id");
            String date = result.getString("data_hora");
            int userId = result.getInt("id_utilizador");
            int showId = result.getInt("id_espetaculo");

            reserves.add(new UnPayedReserve(
                    id,
                    date,
                    false,
                    userId,
                    showId,
                    "----"
            ));
        }

        result.close();

        for (Reserve reserve : reserves) {
            List<Seat> seats = new ArrayList<>();
            ResultSet lugar = statement.executeQuery("SELECT id,fila,assento,preco,espetaculo_id FROM lugar where id in "
                    + "(SELECT id_lugar FROM reserva_lugar WHERE id_reserva =" + reserve.getId() + ")");
            while(lugar.next()) {
                int id = lugar.getInt(1);
                String fila = lugar.getString(2);
                String assento = lugar.getString(3);
                double preco = lugar.getDouble(4);
                int espetaculo_id = lugar.getInt(5);
                seats.add(new Seat(id,fila,assento,preco,espetaculo_id));
            }
            reserve.setSeats(seats);
            lugar.close();
        }


        for (Reserve reserve : reserves) {
            ResultSet espetaculo = statement.executeQuery("SELECT data_hora FROM espetaculo where id = "+ reserve.getShowId() +";");
            reserve.setDateShow(espetaculo.getString(1));
            espetaculo.close();
        }


        if (reserves.isEmpty())
            LOG.log("No payments awaiting from user [" + clientName + "]");

        // Set response
        response.setReserves(reserves);

        statement.close();
        result.close();
        clientResult.close();

        return new Pair<>(response,null);
    }

    public synchronized Pair<Object,List<String>> consultPayedReservations(ClientData clientData) throws IOException {
        // Stores reserves awaiting payment to be sent to the user
        ArrayList<Reserve> reserves = new ArrayList<>();
        String msg;

        ConsultPayedReservationResponse response = new ConsultPayedReservationResponse();

        try {
            Statement statement = connection.createStatement();

            // Execute query to get the clients name
            ResultSet clientName = statement.executeQuery(
                    "SELECT username FROM utilizador WHERE id = '" + clientData.getId() + "'"
            );

            String name = clientName.getString(1);

            // Execute query to search reserves
            ResultSet result = statement.executeQuery(
                    "SELECT id,data_hora,id_utilizador,id_espetaculo FROM reserva where id_utilizador= " + clientData.getId() + " and pago=1"
            );

            while(result.next()) {
                int id = result.getInt("id");
                String date = result.getString("data_hora");
                int userId = result.getInt("id_utilizador");
                int showId = result.getInt("id_espetaculo");

                reserves.add(new UnPayedReserve(
                        id,
                        date,
                        false,
                        userId,
                        showId,
                        "----"
                ));
            }

            result.close();

            for (Reserve reserve : reserves) {
                List<Seat> seats = new ArrayList<>();
                ResultSet lugar = statement.executeQuery("SELECT id,fila,assento,preco,espetaculo_id FROM lugar where id in "
                        + "(SELECT id_lugar FROM reserva_lugar WHERE id_reserva =" + reserve.getId() + ")");
                while(lugar.next()) {
                    int id = lugar.getInt(1);
                    String fila = lugar.getString(2);
                    String assento = lugar.getString(3);
                    double preco = lugar.getDouble(4);
                    int espetaculo_id = lugar.getInt(5);
                    seats.add(new Seat(id,fila,assento,preco,espetaculo_id));
                }
                reserve.setSeats(seats);
                lugar.close();
            }


            for (Reserve reserve : reserves) {
                ResultSet espetaculo = statement.executeQuery("SELECT data_hora FROM espetaculo where id = "+ reserve.getShowId() +";");
                reserve.setDateShow(espetaculo.getString(1));
                espetaculo.close();
            }


            response.setReserves(reserves);

            if (reserves.isEmpty())
                LOG.log("No payments awaiting from user [" + name + "]");

            statement.close();
            result.close();
            clientName.close();
        } catch(SQLException e) {
            msg = "Unable to get data from the database";
            LOG.log(msg);
        }

        return new Pair<>(response,null);
    }

    public synchronized Pair<Object,List<String>> consultShows(ClientData clientData) throws IOException {
        // stores reserves to be sent to the user
        ArrayList<Show> shows = new ArrayList<>();
        ConsultShowsFilterResponse response = new ConsultShowsFilterResponse();
        StringBuilder query = new StringBuilder();

        // Received filters from user
        HashMap<String, String> filters = (HashMap<String, String>) clientData.getData();
        try {
            Statement statement = connection.createStatement();

            ResultSet clientName = statement.executeQuery(
                    "SELECT username FROM utilizador WHERE id = '" + clientData.getId() + "'"
            );

            // Verify the type of info the user pretends to be searched
            var filtersEntry = filters.entrySet().iterator();
            while(filtersEntry.hasNext()) {
                Map.Entry<String,String> filter = filtersEntry.next();
                query.append(filter.getKey()).append(" LIKE '%").append(filter.getValue()).append("%' ");
                if (filtersEntry.hasNext()) {
                    query.append(" and ");
                } else {
                    query.append(";");
                }
            }

            ResultSet result = statement.executeQuery("SELECT * FROM espetaculo WHERE " + query);

            while (result.next()) {
                shows.add(new Show(
                        result.getInt("id"),
                        result.getString("descricao"),
                        result.getString("tipo"),
                        result.getString("data_hora"),
                        result.getInt("duracao"),
                        result.getString("local"),
                        result.getString("localidade"),
                        result.getString("pais"),
                        result.getString("classificacao_etaria"),
                        result.getBoolean("visivel"))
                );
            }
            result.close();

            shows.removeIf(item -> !item.isVisible());
            response.setShows(shows);

            if (shows.isEmpty())
                LOG.log("Shows not found based on the received filters");

            statement.close();
            clientName.close();
        } catch (SQLException e) {
            LOG.log("Unable to get data from the database");
        }


        return new Pair<>(response,null);
    }

    public synchronized Pair<Object,List<String>> consultShowsAdmin() throws IOException {
        // stores reserves to be sent to the user
        ArrayList<Show> shows = new ArrayList<>();
        ShowsResponse response = new ShowsResponse();


        try {
            Statement statement = connection.createStatement();
            ResultSet result = statement.executeQuery("SELECT * FROM espetaculo");

            while (result.next()) {
                shows.add(new ShowAdmin(
                        result.getInt("id"),
                        result.getString("descricao"),
                        result.getString("tipo"),
                        result.getString("data_hora"),
                        result.getInt("duracao"),
                        result.getString("local"),
                        result.getString("localidade"),
                        result.getString("pais"),
                        result.getString("classificacao_etaria"),
                        result.getBoolean("visivel"))
                );
            }

            if (shows.isEmpty())
                LOG.log("Shows not found based on the received filters");

            response.setAction(ClientAction.CONSULT_SHOWS_ALL);
            response.setShows(shows);

            result.close();
            statement.close();
        } catch (SQLException e) {
            LOG.log("Unable to get data from the database");
        }


        return new Pair<>(response,null);
    }

    public synchronized Pair<Object,List<String>> selectShows() throws IOException {
        ArrayList<Show> availableShows = new ArrayList<>();
        ShowsResponse response = new ShowsResponse();

        try {
            Statement statement = connection.createStatement();

            ResultSet result = statement.executeQuery(
                    "SELECT * FROM espetaculo"
            );

            while (result.next()) {
                int id = result.getInt("id");
                String description = result.getString("descricao");
                String type = result.getString("tipo");
                String date = result.getString("data_hora");
                int duration = result.getInt("duracao");
                String local = result.getString("local");
                String locality = result.getString("localidade");
                String country = result.getString("pais");
                String ageClassification = result.getString("classificacao_etaria");
                boolean visible = result.getBoolean("visivel");

                if (visible) {
                    try {
                        // Get the show date (assuming its formatted: "yyyy-MM-dd HH:mm:ss")
                        Date showDate = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").parse(date);

                        Date currentDate = new Date();

                        long  diffInMillis = showDate.getTime() - currentDate.getTime();
                        if (diffInMillis > 0) {
                            long diff = TimeUnit.MILLISECONDS.toHours(diffInMillis);

                            if (diff >= 24) {
                                availableShows.add(new Show(
                                        id,
                                        description,
                                        type,
                                        date,
                                        duration,
                                        local,
                                        locality,
                                        country,
                                        ageClassification,
                                        true
                                ));
                            }
                        }
                    } catch(ParseException e) {
                        LOG.log("Unable to format the show Date");
                    }
                }
            }

            // Send available shows to user
            response.setAction(ClientAction.SELECT_SHOWS);
            response.setShows(availableShows);
            if (availableShows.isEmpty())
                LOG.log("No shows available at the moment");

            statement.close();
            result.close();
        } catch (SQLException e) {
            LOG.log( "Unable to get data from the database");
        }

        return new Pair<>(response,null);
    }

    public synchronized Pair<Object,List<String>> viewSeatsAndPrices(ClientData clientData) throws IOException {
        SeatsResponse seatsResponse = new SeatsResponse();
        List<Seat> available = new ArrayList<>();

        // At this moment the client has already selected the show, so we search by the show id
        // Receive show id
        int recShowId = clientData.getShowId();
        seatsResponse.setShowId(recShowId);

        // Get unavailable seats ids
        ArrayList<Integer> unavailable = new ArrayList<>();

        try {
            Statement statement = connection.createStatement();
            ResultSet reservedSeats = statement.executeQuery("SELECT id_lugar FROM reserva_lugar");

            while (reservedSeats.next()) {
                int reservedSeatId = reservedSeats.getInt("id_lugar");
                unavailable.add(reservedSeatId);
            }

            ResultSet availableSeats = statement.executeQuery("SELECT * FROM lugar");

            while (availableSeats.next()) {
                int seatId = availableSeats.getInt("id");
                String row = availableSeats.getString("fila");
                String seat = availableSeats.getString("assento");
                double price = availableSeats.getDouble("preco");
                int showId = availableSeats.getInt("espetaculo_id");

                if (showId == recShowId) {
                    Seat newSeat = new Seat(
                            seatId,
                            row,
                            seat,
                            price,
                            showId
                    );

                    if (unavailable.contains(seatId))
                        newSeat.setReserved(true);

                    available.add(newSeat);
                }
            }

            seatsResponse.setSeats(available);

            statement.close();
            availableSeats.close();
            reservedSeats.close();
        } catch(SQLException e) {
            LOG.log("Unable to get data from the database");
        }

        return new Pair<>(seatsResponse,null);
    }

    public synchronized Pair<Object,List<String>> submitReservation(ClientData clientData) throws IOException {
        Date currentTime = new Date();
        int isPaid = 0;
        String query;
        List<String> listQuery = new ArrayList<>();
        SubmitReservationResponse response = new SubmitReservationResponse();

        // Receive reserve from client  (format: showId, List<Seat>)
        SubmitReservation reserve = (SubmitReservation) clientData.getData();

        try {
            Statement statement = connection.createStatement();

            // Execute a query to get all reserves id
            ResultSet reserves = statement.executeQuery("SELECT id FROM reserva");

            // Execute a query to get the clients name
            ResultSet usernameResult = statement.executeQuery("SELECT username FROM utilizador WHERE id = '" + clientData.getId() + "'");

            String username = usernameResult.getString(1);

            DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
            String dateString = dateFormat.format(currentTime);

            boolean check = false;
            for (Seat seat : reserve.getSeats()) {
                ResultSet checkSeats = statement.executeQuery("SELECT id FROM lugar WHERE fila= '" + seat.getRow() + "'" + " and assento='"
                        + seat.getNumber() + "' and espetaculo_id='" + seat.getShowId() + "'");
                int id = checkSeats.getInt(1);
                checkSeats.close();
                if (id != 0) {
                    ResultSet seatReserve = statement.executeQuery("SELECT id_reserva FROM reserva_lugar WHERE id_lugar ='" + id + "'");
                    if (seatReserve.getInt(1) != 0) {
                        check = true;
                    }
                }
            }

            if (check) {
                LOG.log("The seat is already being used");
                response.setSuccess(false);
                return new Pair<>(response,null);
            }

            LOG.log("The seats are available");

            try {
                // Insert reserve
                ResultSet result = statement.executeQuery("SELECT max(id) FROM reserva");
                int id = result.getInt(1) + 1;

                query = "INSERT INTO reserva(id,data_hora,pago,id_utilizador,id_espetaculo)" +
                        "VALUES(" +
                        "'" + id + "'," +
                        "'" + dateString + "','"
                        + isPaid + "','"
                        + clientData.getId() + "','"
                        + reserve.getShowId() + "')";

                listQuery.add(query);

                // Insert seats
                for (var s : reserve.getSeats()) {
                    query = "INSERT INTO reserva_lugar (" +
                            " id_reserva," +
                            " id_lugar)" +
                            " VALUES (" +
                            id +  " ," +
                            s.getId() + ");";
                    listQuery.add(query);
                }

                LOG.log("Reservation submitted with success from user[" + username + "]");
                clientData.setData(id);
                response.setSuccess(true);
                response.setResId(id);

                return new Pair<>(response,listQuery);
            } catch (SQLException e) {
                LOG.log("Unable to submit reservation from user[" + username + "]");
                response.setSuccess(false);
                return new Pair<>(response,listQuery);
            } finally {
                statement.close();
                reserves.close();
                usernameResult.close();
            }
        } catch(SQLException e) {
            LOG.log("Unable to get data from the database");
            return null;
        }

    }

    public synchronized Pair<Object,List<String>> deleteUnpaidReservation(ClientData clientData) throws IOException {
        DeleteReservationResponse response = new DeleteReservationResponse();
        String query;
        List<String> listQuery = new ArrayList<>();
        List<Reserve> reserves = new ArrayList<>();


        // Read the ID of the reserve to be deleted
        Integer reservationId = (Integer) clientData.getData();
        try {
            // Create statement
            Statement statement = connection.createStatement();

            // Execute a query to get the clients name
            ResultSet usernameSet = statement.executeQuery(
                    "SELECT username FROM utilizador WHERE id = '" + clientData.getId() + "'"
            );

            String username = usernameSet.getString(1);

            ResultSet result = statement.executeQuery(
                    "SELECT id,pago, id_utilizador FROM reserva"
            );

            while (result.next()) {
                // If the IDs match & paid=false, delete row
                int idReserva = result.getInt("id");
                boolean pago = result.getBoolean("pago");
                int idUtilizador = result.getInt("id_utilizador");

                if (reservationId == idReserva && !pago && clientData.getId() == idUtilizador) {
                    query = "DELETE FROM reserva WHERE id = '" + reservationId + "';";
                    listQuery.add(query);
                    query = "DELETE FROM reserva_lugar WHERE id_reserva = '" + reservationId + "';";
                    listQuery.add(query);

                    LOG.log("User[" + username + "] deleted unpaid successfully reservation id[" + reservationId + "]");
                    response.setSuccess(true);
                    if (reserves.isEmpty())
                        LOG.log("No payments awaiting from user [" + username + "]");

                    response.setReserves(reserves);

                    statement.close();
                    result.close();
                    if (username != null) usernameSet.close();
                }
            }
        } catch(SQLException e) {
            LOG.log("Unable to get data from the database");
        }

        return new Pair<>(response,listQuery);
    }

    public synchronized Pair<Object,List<String>> payReservation(ClientData clientData) throws IOException {
        List<String> listQuery = new ArrayList<>();
        String query;

        PayReservationResponse response = new PayReservationResponse();

        // Receive reserve ID for payment
        Integer resId = (Integer) clientData.getData();

        try {
            Statement statement = connection.createStatement();

            // Search reserve by id
            ResultSet result = statement.executeQuery(
                    "SELECT * FROM reserva WHERE id = '" + resId + "'"
            );

            // Verify if the reservation exists
            if (result.next()) {
                // Get username
                ResultSet usernameRes = statement.executeQuery(
                        "SELECT username FROM utilizador WHERE id = '" + clientData.getId() + "'"
                );
                String username = usernameRes.getString("username");

                // Set paid=true
                query = "UPDATE reserva SET pago = '" + 1 + "' WHERE id = '" + resId + "'";

                listQuery.add(query);
                LOG.log("Reservation from user [" + username + "] was paid successfully...");
                response.setSuccess(true);

                statement.close();
                result.close();
                usernameRes.close();
            }

        } catch (SQLException e) {
            LOG.log("Unable to get data from the database");
        }

        return new Pair<>(response,listQuery);
    }

    public synchronized Pair<Object,List<String>> showVisible(ClientData clientData) throws IOException {
        Integer showId = clientData.getShowId();
        String query;
        String msg;

        List<String> listQuery = new ArrayList<>();

        HandleVisibleShowResponse response = new HandleVisibleShowResponse();

        try {
            Statement statement = connection.createStatement();

            ResultSet visivel = statement.executeQuery(
                    "SELECT visivel FROM espetaculo WHERE id = '" + showId + "'");

            if(visivel.getBoolean(1)) {
                msg = "This show is visible";

                query = "UPDATE espetaculo SET visivel = 0 WHERE id = '" + showId + "'";
                listQuery.add(query);

                LOG.log(msg);
                response.setSuccess(true);
                response.setMsg(msg);
                return new Pair<>(response,listQuery);
            }

            query = "UPDATE espetaculo SET visivel = 1 WHERE id = '" + showId + "'";
            listQuery.add(query);

            msg = "The show is now visible";
            LOG.log(msg);
            response.setSuccess(true);
            response.setMsg("The show is now visible");
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return new Pair<>(response,listQuery);
    }


    public synchronized Pair<Object,List<String>> insertShows(ClientData clientData) throws IOException {
        String msg;
        InsertShowResponse response = new InsertShowResponse();

        List<String> listQuery = new ArrayList<>();
        String query;

        try {
            String filePath = (String) clientData.getData();
            Triple<Show, Map<String, List<Seat>>, String> mapShows = Utils.readFile(filePath);

            if (mapShows == null || !mapShows.getThird().isEmpty()) {
                response.setSuccess(false);
                msg = mapShows.getThird();
                LOG.log(msg);
                response.setMsg(msg);
                return new Pair<>(response,listQuery);
            }
            // Create connection
            Statement statement = connection.createStatement();

            //Check if the show exists
            ResultSet idExist = statement.executeQuery(
                    "SELECT id FROM espetaculo WHERE descricao = '" + mapShows.getFirst().getDescription() + "'"
            );

            if (idExist.next()) {
                response.setSuccess(false);
                response.setMsg("This show already exists in the database");
                return new Pair<>(response,listQuery);
            }

            ResultSet maxId = statement.executeQuery(
                    "SELECT max(id) FROM espetaculo"
            );

            int id = maxId.getInt(1) + 1;

            query = "INSERT INTO espetaculo(id,descricao,tipo,data_hora,duracao,local,localidade,pais,classificacao_etaria) "
                    + "VALUES("
                    + "'" + id + "',"
                    + "'" + mapShows.getFirst().getDescription() + "',"
                    + "'" + mapShows.getFirst().getType() + "',"
                    + "'" + mapShows.getFirst().getDateHour() + "',"
                    + "'" + mapShows.getFirst().getDuration() + "',"
                    + "'" + mapShows.getFirst().getLocation() + "',"
                    + "'" + mapShows.getFirst().getLocality() + "',"
                    + "'" + mapShows.getFirst().getCountry() + "',"
                    + "'" + mapShows.getFirst().getAgeClassification() + "')";

            listQuery.add(query);

            //Get id of show

            Map<String, List<Seat>> seats = mapShows.getSecond();

            ResultSet maxIdSeatSet = statement.executeQuery(
                    "SELECT max(id) FROM lugar"
            );

            int maxIdSeat = maxIdSeatSet.getInt(1);

                        //Go through all the rows
            for (String key : seats.keySet()) {
                //Go through all the seats
                List<Seat> seatsList = seats.get(key);
                for (Seat seat : seatsList) {
                    query = "INSERT INTO lugar(id,fila,assento,preco,espetaculo_id) "
                            + "VALUES ("
                            + "'" + ++maxIdSeat + "',"
                            + "'" + seat.getRow() + "',"
                            + "'" + seat.getNumber() + "',"
                            + "'" + seat.getPrice() + "',"
                            + "'" + id + "')";

                    listQuery.add(query);
                }
            }

            response.setSuccess(true);
            response.setMsg("The show was successfully added");
        } catch(SQLException e) {
            msg = "Unable to get data from the database";
            LOG.log(msg);

            response.setSuccess(true);
            response.setMsg(msg);
        }

        return new Pair<>(response,listQuery);
    }

    public synchronized Pair<Object,List<String>> deleteShow(ClientData clientData) throws IOException {
        boolean hasPaidReserve = false;
        String msg;
        List<String> listQuery = new ArrayList<>();
        String query;
        DeleteResponse response = new DeleteResponse();

        try {
            // Create statement
            Statement statement = connection.createStatement();

            // Execute a query to get the clients data
            ResultSet isAdmin = statement.executeQuery(
                    "SELECT username, nome FROM utilizador WHERE id = '" + clientData.getId() + "'"
            );

            // Verify if the client has admin privilege
            if (isAdmin.getString("username").equalsIgnoreCase("admin") &&
                    isAdmin.getString("nome").equalsIgnoreCase("admin")) {
                // Receive from client the ID of the show to be deleted
                int deleteShowId = clientData.getShowId();

                // Search reservations
                ResultSet reservations = statement.executeQuery(
                        "SELECT pago from reserva WHERE id_espetaculo = '" + deleteShowId + "'");

                // If there are no reservations associated


                // Search reservations and verify if a paid reservation exists
                while (reservations.next()) {
                    boolean pago = reservations.getBoolean("pago");
                    // If a paid reserve exists, the show can't be deleted
                    if (pago) {
                        msg = "Show[" + deleteShowId + "] already has a paid reservation...";
                        LOG.log(msg);
                        response.setSuccess(false);
                        response.setMsg(msg);
                        hasPaidReserve = true;
                    }
                }

                // If there are no paid reservations associated, the show can be deleted
                if (!hasPaidReserve) {
                    try {
                        ResultSet reserva = statement.executeQuery(
                                "SELECT id from reserva WHERE id_espetaculo = '" + deleteShowId + "'");

                        while (reserva.next()) {
                            int id = reserva.getInt("id");

                            query = "DELETE from reserva_lugar WHERE id_reserva = "+ id + ";";
                            listQuery.add(query);
                        }

                        query = "DELETE from reserva WHERE id_espetaculo = "+ deleteShowId + ";";
                        listQuery.add(query);

                        query = "DELETE FROM espetaculo WHERE id = '" + deleteShowId + "'";
                        listQuery.add(query);

                        query = "DELETE from lugar WHERE espetaculo_id = "+ deleteShowId + ";";
                        listQuery.add(query);

                        msg = "Show[" + deleteShowId + "] was deleted successfully...";
                        LOG.log(msg);

                        listQuery.add(query);
                        response.setSuccess(true);
                        response.setMsg(msg);
                    } finally {
                        statement.close();
                        reservations.close();
                        isAdmin.close();
                    }
                }

            } else {
                msg = "Unable to delete show. Only the admin can execute this function";
                LOG.log(msg);
                response.setSuccess(false);
                response.setMsg(msg);
                statement.close();
                isAdmin.close();
            }
        } catch(SQLException e) {
            msg = "Unable to get data from the database";
            LOG.log(msg);
            response.setSuccess(false);
            response.setMsg(msg);
        }

        return new Pair<>(response,listQuery);
    }

    public synchronized Pair<Object,List<String>> disconnect(ClientData clientData) throws SQLException, IOException, ClassNotFoundException {
        String query;
        List<String> listQuery = new ArrayList<>();
        DisconnectResponse response = new DisconnectResponse();

        try {
            // Create statement
            Statement statement = connection.createStatement();
            // Execute a query to get the clients data
            ResultSet result = statement.executeQuery(
                    "SELECT id,username, nome, autenticado FROM utilizador"
            );

            while (result.next()) {
                int id = result.getInt("id");
                String username = result.getString("username");
                boolean authenticated = result.getBoolean("autenticado");

                // User found and its authenticated
                if (clientData.getId() == id && authenticated) {
                    query = "UPDATE utilizador SET autenticado = 0 WHERE id = '" + id + "'";
                    // Update authenticated value

                    listQuery.add(query);

                    LOG.log("User[" + username + "] logged out successfully");

                    statement.close();
                    result.close();
                }
            }
        } catch(SQLException e) {
            LOG.log( "Unable to get data from the database");
        }

        return new Pair<>(response,listQuery);
    }

    public synchronized void updateDataBase(List<String> sqlCommand) {
        try {
            Statement statement = connection.createStatement();
            for (String command : sqlCommand) {
                statement.executeUpdate(command);
            }
            updateVersion(sqlCommand);
            LOG.log("Database updated");
        } catch (SQLException e) {
            LOG.log("Error updating database " + e);
        }
    }
}