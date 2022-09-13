package pt.isec.pa.model.data;

public class ModelData {
    String message;
    int number;

    public ModelData() {
        message = "none";
        number  = 0;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public int getNumber() {
        return number;
    }

    public void setNumber(int number) {
        this.number = number;
    }
}
