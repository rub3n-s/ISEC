package report.ui;

import report.Report;
import utils.PAInput;

public class ReportUI {
    Report report;

    public void menu() {
        int option;
        do {
            option = PAInput.chooseOption("Report", "Create report","Edit report","Show report","Exit");
            switch (option) {
                case 1:
                    String title = PAInput.readString("Report title: ", false);
                    report = new Report(title);
                    menuReport();
                    break;
                case 2:
                    if (report == null)
                        System.out.println("You must create a report first.");
                    else
                        menuReport();
                    break;
                case 3:
                    showReport();
                    break;
            }
        } while (option != 4);

    }

    private void menuReport() {
        int option;
        String [] options = {
                "Add author",
                "Remove author",
                "Add text",
                "Capitalize sentences",
                "Count all the words",
                "Number of occurrences of a word",
                "Show report",
                "Return to the main menu"
        };
        do {
            option = PAInput.chooseOption("Edit report", options);
            switch (option) {
                case 1 -> addAuthor();
                case 2 -> removeAuthor();
                case 3 -> addText();
                case 4 -> capitalizeSentences();
                case 5 -> countWords();
                case 6 -> countOccurrences();
                case 7 -> showReport();
            }
        } while (option!=options.length);
    }

    private void showReport() {
        if (report==null) {
            System.out.println("You must create a report first.");
            return;
        }
        System.out.println();
        System.out.println(report.toString());
        System.out.println();
    }

    private void addAuthor() {
        String author = PAInput.readString("New author: ", false);
        report.addAuthor(author);
    }

    private void removeAuthor() {
        String author = PAInput.readString("Author to remove: ", false);
        report.removeAuthor(author);
    }
    
    private void addText() {
        String text = PAInput.readString("New sentence: ", false);
        report.addText(text);
    }    

    private void capitalizeSentences() {
        report.capitalizeSentences();
    }

    private void countWords() {
        System.out.printf("\nNumber of words: %d\n\n",report.getNumberOfWords());
    }

    private void countOccurrences() {
        String word = PAInput.readString("Word to search: ", true);
        System.out.printf("\nNumber of occurrences of the word \"%s\": %d\n\n",word,report.getNumberOfOccurrences(word));
    }
}
