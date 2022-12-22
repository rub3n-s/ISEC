package pt.isec.pd.shared_data;

import java.io.Serializable;
import java.util.List;

public class UpdateDb implements Serializable {
    private List<String> commands;

    public List<String> getCommands() {
        return commands;
    }

    public void setCommands(List<String> commands) {
        this.commands = commands;
    }
}
