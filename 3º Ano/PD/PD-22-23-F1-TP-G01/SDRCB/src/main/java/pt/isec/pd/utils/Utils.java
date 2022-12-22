package pt.isec.pd.utils;

import javafx.util.Pair;
import pt.isec.pd.shared_data.Seat;
import pt.isec.pd.shared_data.Show;
import pt.isec.pd.shared_data.Triple;

import java.io.*;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public class Utils {
    public static byte[] serializeObject(Object object) throws IOException {
        ByteArrayOutputStream baos = new ByteArrayOutputStream();
        ObjectOutputStream oss = new ObjectOutputStream(baos);
        oss.writeObject(object);
        return baos.toByteArray();
    }

    public static <T> T deserializeObject(byte[] data) {
        try {
            ByteArrayInputStream bais = new ByteArrayInputStream(data);
            ObjectInputStream ois = new ObjectInputStream(bais);
            return (T) ois.readObject();
        } catch (IOException | ClassNotFoundException ignored) {
        }
        return null;
    }

    public static Triple<Show,Map<String,List<Seat>>, String> readFile(String path) {
        Show show = new Show();
        Map<String,List<Seat>> seatsMap = new HashMap<>();
        String msgerror;
        try (Scanner input = new Scanner(new FileReader(path))) {
            while(input.hasNext()){
                input.useDelimiter(";|:|\n");
                input.useLocale(Locale.US);
                String key = processString(input.next());
                switch (key) {
                    case "Designação" -> show.setDescription(processString(input.nextLine()));
                    case "Tipo" -> show.setType(processString(input.nextLine()));
                    case "Data" -> {

                        //dia
                        String day = processString(input.next());
                        try {
                            Integer.parseInt(day);
                        } catch (NumberFormatException e) {
                            msgerror = "O dia no ficheiro está errado! Não é um inteiro válido!";
                            return new Triple<>(null,null,msgerror);
                        }

                        if (Integer.parseInt(day) >= 99){
                            msgerror = "O dia no ficheiro está errado! Dias só podem ter dois dígitos!";
                            return new Triple<>(null,null,msgerror);
                        }

                        //mes
                        String month = processString(input.next());
                        try {
                            Integer.parseInt(month);
                        } catch (NumberFormatException e) {
                            msgerror = "O mês no ficheiro está errado! Não é um inteiro válido!";
                            return new Triple<>(null,null,msgerror);
                        }

                        if (Integer.parseInt(month) >= 99){
                            msgerror = "O mês no ficheiro está errado! Meses só podem ter dois dígitos!";
                            return new Triple<>(null,null,msgerror);
                        }

                        //ano
                        String year = processString(input.next());
                        try {
                            Integer.parseInt(year);
                        } catch (NumberFormatException e) {
                            msgerror = "O ano no ficheiro está errado! Não é um inteiro válido!";
                            return new Triple<>(null,null,msgerror);
                        }

                        if (Integer.parseInt(year) >= 9999){
                            msgerror = "O ano no ficheiro está errado! Só são aceites 4 digitos!";
                            return new Triple<>(null,null,msgerror);
                        }

                        //hora e minutos

                        input.next();

                        //hora

                        String hours = processString(input.next());

                        try {
                            Integer.parseInt(hours);
                        } catch (NumberFormatException e) {
                            msgerror = "A hora no ficheiro está errada! Não é um inteiro válido!";
                            return new Triple<>(null,null,msgerror);
                        }

                        if (Integer.parseInt(hours) >= 99){
                            msgerror = "A hora no ficheiro está errada! Só pode ter 2 digitos!";
                            return new Triple<>(null,null,msgerror);
                        }

                        //minutos

                        String minutes = processString(input.next());

                        try {
                            Integer.parseInt(hours);
                        } catch (NumberFormatException e) {
                            msgerror = "Os minutos no ficheiro estao errados! Não é um inteiro válido!";
                            return new Triple<>(null,null,msgerror);
                        }

                        if (Integer.parseInt(hours) >= 99){
                            msgerror = "Os minutos no ficheiro estao errados! Só pode ter 2 digitos!";
                            return new Triple<>(null,null,msgerror);
                        }

                        SimpleDateFormat format = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                        Date date = format.parse(year + "-" + month + "-" + day + " " + hours + ":" + minutes + ":00");
                        show.setDateHour(year + "-" + month + "-" + day + " " + hours + ":" + minutes + ":00");
                    }
                    case "Duração" -> {

                        String Duration = processString(input.next());

                        try {
                            Integer.parseInt(Duration);
                        } catch (NumberFormatException e) {
                            msgerror = "A duração no ficheiro está errada! Não é um inteiro válido!";
                            return new Triple<>(null,null,msgerror);
                        }

                        show.setDuration(Integer.parseInt(Duration));

                    }

                    case "Local" -> show.setLocation(processString(input.nextLine()));
                    case "Localidade" -> show.setLocality(processString(input.next()));
                    case "País" -> show.setCountry(processString(input.next()));
                    case "Classificação etária" -> {

                        String ClassEtaria = processString(input.next());

                        try {
                            Integer.parseInt(ClassEtaria);
                        } catch (NumberFormatException e) {
                            msgerror = "A classificação etária no ficheiro está errada! Não é um inteiro válido!";
                            return new Triple<>(null,null,msgerror);
                        }

                        show.setAgeClassification(ClassEtaria);

                    }

                    case "Fila" -> {
                        input.nextLine();
                        while(input.hasNext()) {
                            setsReader(input,seatsMap);
                        }
                    }
                }
            }
        } catch (FileNotFoundException | ParseException e) {
            msgerror = "O ficheiro não existe!";
            return new Triple<>(null,null,msgerror);
        }
        return new Triple<>(show,seatsMap,"");
    }

    private static String processString(String value) {
        return value.replace(";","").replace("“","").replace("\"","").replace("”","").replace(":","").trim();
    }

    private static void setsReader(Scanner input, Map<String,List<Seat>> seatsMap) {
        String row = input.nextLine();
        String[] seats = row.split(";");
        row = processString(seats[0]);
        seatsMap.put(processString(seats[0]),new ArrayList<>());
        for (int i = 1;i < seats.length; i++) {
            String[] details = seats[i].split(":");
            seatsMap.get(processString(seats[0])).add(new Seat(row,processString(details[0]),Double.parseDouble(processString(details[1]))));
        }
    }


}
