package report;

import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.management.AttributeChangeNotificationFilter;

public class Report {
    private static final String DELIMITADORS = " \t\n,.!?"; // para usar com StringTokanizer
    private int qtAuthors;
    String titulo;
    //String []autores;
    ArrayList<String> autores;
    StringBuilder texto;

    public Report(String title) {
        this.titulo = title;
        autores = new ArrayList<>();
        texto = new StringBuilder();
        qtAuthors = 0;
    }

    // acrescentar gets/sets -> titulo/text

    // acrescentar autor
    public boolean addAuthor(String autor) {
        if (autor != null) {
            // if (autores.contains(autor))
            //     return false;
            for (String s : autores) {
                if (s.equalsIgnoreCase(autor)) {
                    System.out.println("Já existe um autor com o nome '" + autor + "'.");
                    return false;
                }                    
            }
            autores.add(autor);
            System.out.println("Autor " + autor + " foi adicionado com sucesso!");
            qtAuthors++;
            return true;
        }
        return false;
    }

    // remover autor
    public boolean removeAuthor(String autor) {
        for (String s : autores) {
            if (s.equalsIgnoreCase(autor)) {
                autores.remove(s);
                System.out.println("Autor " + autor + " foi removido com sucesso!");
                return true;
            }
        }
        return false;
    }

    // adicionar texto
    public boolean addText(String text) {
        if (texto != null) {
            texto.append(text);
            return true;
        }
        return false;
    }

    // substituir p/ letras maiusculas primeira letras depois de ". "
    public void capitalizeSentences() {
        boolean changeNext = true;
        for (int i = 0; i < texto.length(); i++) {
            char c = texto.charAt(i);
            if (changeNext && Character.isLetter(c)) {
                texto.setCharAt(i, Character.toUpperCase(c));
                changeNext = false;
            } else if (".!?".indexOf(c) >= 0) { //.indexOf devolve -1 se o char não existir
                changeNext = true;
            }
        }

        // Pattern p = Pattern.compile("[. \\w-]+");
        // Matcher m = p.matcher(". ");
        // boolean b = m.matches();

        // if (b) {
        //     String arr[] = texto.toString().split("[. \\w]+");
        //     for (int i = 0; i < arr.length; i++) {
        //         arr[i].toUpperCase();
        //     }
        // }
    }

    // contar palavras do texto
    public int getNumberOfWords() {
        // versão 1
        // int counter = 0;
        // Scanner stext.useDelimiter("[\\s,.!?]+");
        // while(stext.hasNext()) {
        //     counter++;
        //     stext.next();
        // }
        // counter = 0;

        // versão 2 - split
        if (texto != null) {
            String []arr = texto.toString().split("[\\s,]+");
            return arr.length;
        }

        // versão 3 
        //int counter = 0;
        // Pattern p = Pattern.compile("[\\w-]+");
        // Matcher m = p.matcher(texto.toString());
        // while(m.find()) {
        //     counter++;
        // }
        // return counter;
        

        // versão 4
        // StringTokenizer st = new StringTokenizer(texto.toString(), DELIMITADORS);
        // return st.countTokens();

        return 0;
    }

    // contar ocorrencias de uma determinada palavra
    public int getNumberOfOccurrences(String word) {
        // StringTokenizer st = new StringTokenizer(texto.toString(), DELIMITADORS);
        // while(st.hasMoreTokens()) {
        //     if (word.equalsIgnoreCase(st.nextToken()) {
        //         counter++;
        //     }
        // }
        // return st.countTokens();

        int ocorrencias = 0;

        if (word != null) {
            String []arr = texto.toString().split("[\\s,]+");

            for (int i = 0; i < arr.length; i++)
                if (word.equalsIgnoreCase(arr[i]))
                    ocorrencias++;

            return ocorrencias;
        }
        return 0;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder("Report\n");
        sb.append(String.format("Title : %s\n", titulo));
        sb.append("Authors: ");
        if (qtAuthors > 0) {
            for (int i = 0; i < autores.size(); i++) {
                if (i > 0)
                    sb.append(", ");
                sb.append(autores.get(i));
            }
        }
        sb.append("\nText: ");
        sb.append(texto);
        return sb.toString();
    }
}
