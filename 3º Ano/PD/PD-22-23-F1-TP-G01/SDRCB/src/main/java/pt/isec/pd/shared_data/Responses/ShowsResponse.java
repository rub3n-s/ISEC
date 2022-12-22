package pt.isec.pd.shared_data.Responses;

import pt.isec.pd.client.model.data.ClientAction;
import pt.isec.pd.shared_data.Show;

import java.io.Serializable;
import java.util.List;

public class ShowsResponse implements Serializable {
    ClientAction action;
    List<Show> shows;
    int showId;

    public ClientAction getAction() {
        return action;
    }

    public void setAction(ClientAction action) {
        this.action = action;
    }

    public List<Show> getShows() {
        return shows;
    }

    public int getShowId() {
        return showId;
    }

    public void setShowId(int showId) {
        this.showId = showId;
    }

    public void setShows(List<Show> shows) {
        this.shows = shows;
    }
}
