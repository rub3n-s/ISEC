package pt.isec.pd.shared_data.Responses;

import pt.isec.pd.shared_data.Reserve;
import pt.isec.pd.shared_data.Show;

import java.util.List;

public class ConsultShowsFilterResponse extends Response{
    List<Show> shows;

    public List<Show> getShows() {
        return shows;
    }

    public void setShows(List<Show> shows) {
        this.shows = shows;
    }
}
