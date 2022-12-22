package pt.isec.pd.shared_data.Responses;

import pt.isec.pd.shared_data.Reserve;

import java.util.List;

public class ConsultPayedReservationResponse extends Response{
    List<Reserve> reserves;

    public List<Reserve> getReserves() {
        return reserves;
    }

    public void setReserves(List<Reserve> reserves) {
        this.reserves = reserves;
    }
}
