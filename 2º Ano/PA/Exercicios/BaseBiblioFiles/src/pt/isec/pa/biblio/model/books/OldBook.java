package pt.isec.pa.biblio.model.books;

import java.util.List;

public class OldBook extends Book {
    private int nr_copies;
    public OldBook(String title, List<String> authors,int nr_copies) {
        super(title, authors);
        this.nr_copies = nr_copies;
    }

    public int getNr_copies() {
        return nr_copies;
    }

    public void setNr_copies(int nr_copies) {
        this.nr_copies = nr_copies;
    }

    @Override
    public String toString() {
        return "*Old Book* " +super.toString()+
                ", #Copies:" + nr_copies;
    }
}
