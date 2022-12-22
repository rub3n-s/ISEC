package pt.isec.pd.server.data.database;

import pt.isec.pd.server.data.Server;
import pt.isec.pd.utils.Log;

import java.sql.*;

public class CreateDataBase {
    private final Log LOG = Log.getLogger(Server.class);

    public CreateDataBase(String path) {
        create(path);
    }

    private void create(String path) {
        Connection c;
        Statement stmt;

        try {
            Class.forName("org.sqlite.JDBC");
            c = DriverManager.getConnection("jdbc:sqlite:" + path);

            stmt = c.createStatement();
            String espetaculo = """
                    CREATE TABLE espetaculo (
                        id                   INTEGER PRIMARY KEY AUTOINCREMENT
                                                     NOT NULL,
                        descricao            TEXT    NOT NULL,
                        tipo                 TEXT    NOT NULL,
                        data_hora            TEXT    NOT NULL,
                        duracao              INTEGER NOT NULL,
                        local                TEXT    NOT NULL,
                        localidade           TEXT    NOT NULL,
                        pais                 TEXT    NOT NULL,
                        classificacao_etaria TEXT    NOT NULL,
                        visivel              INTEGER NOT NULL
                                                     DEFAULT (0)\s
                    );
                    """;

            String utilizador = """
                    CREATE TABLE utilizador (
                        id            INTEGER PRIMARY KEY AUTOINCREMENT
                                              NOT NULL,
                        username      TEXT    UNIQUE
                                              NOT NULL,
                        nome          TEXT    UNIQUE
                                              NOT NULL,
                        password      TEXT    NOT NULL,
                        administrador INTEGER NOT NULL
                                              DEFAULT (0),
                        autenticado   INTEGER NOT NULL
                                              DEFAULT (0)\s
                    );
                    """;

            String lugar = """
                    CREATE TABLE lugar (
                        id            INTEGER PRIMARY KEY AUTOINCREMENT
                                              NOT NULL,
                        fila          TEXT    NOT NULL,
                        assento       TEXT    NOT NULL,
                        preco         REAL    NOT NULL,
                        espetaculo_id INTEGER REFERENCES espetaculo (id)\s
                                              NOT NULL
                    );
                    """;

            String reserva = """
                    CREATE TABLE reserva (
                        id            INTEGER PRIMARY KEY AUTOINCREMENT
                                              NOT NULL,
                        data_hora     TEXT    NOT NULL,
                        pago          INTEGER NOT NULL
                                              DEFAULT (0),
                        id_utilizador INTEGER REFERENCES utilizador (id)\s
                                              NOT NULL,
                        id_espetaculo INTEGER REFERENCES espetaculo (id)\s
                                              NOT NULL
                    );
                    """;

            String reserva_lugar = """
                    CREATE TABLE reserva_lugar (
                        id_reserva INTEGER REFERENCES reserva (id)\s
                                           NOT NULL,
                        id_lugar   INTEGER REFERENCES lugar (id)\s
                                           NOT NULL,
                        PRIMARY KEY (
                            id_reserva,
                            id_lugar
                        )
                    );""";


            stmt.executeUpdate(espetaculo);
            stmt.executeUpdate(utilizador);
            stmt.executeUpdate(lugar);
            stmt.executeUpdate(reserva);
            stmt.executeUpdate(reserva_lugar);
            stmt.close();

            String admin = "INSERT INTO utilizador (" +
                    "                           username," +
                    "                           nome," +
                    "                           password," +
                    "                           administrador," +
                    "                           autenticado" +
                    "                       )" +
                    "                       VALUES (" +
                    "                           'admin'," +
                    "                           'admin'," +
                    "                           'admin'," +
                    "                           '1'," +
                    "                           '0'" +
                    "                       );";

            String versao = "CREATE TABLE \"versao\" (\n" +
                    "\t\"id\"\tINTEGER NOT NULL,\n" +
                    "\t\"query\"\tTEXT NOT NULL,\n" +
                    "\t\"key\"\tINTEGER,\n" +
                    "\tPRIMARY KEY(\"key\" AUTOINCREMENT)\n" +
                    ");";

            stmt.executeUpdate(admin);
            stmt.executeUpdate(versao);

            String initialVersion = "PRAGMA user_version = 1";

            stmt.execute(initialVersion);
            c.close();
            stmt.close();
        } catch ( Exception e ) {
            System.err.println( e.getClass().getName() + ": " + e.getMessage() );
            System.exit(0);
        }

        LOG.log("DataBase created successfully");
    }
}