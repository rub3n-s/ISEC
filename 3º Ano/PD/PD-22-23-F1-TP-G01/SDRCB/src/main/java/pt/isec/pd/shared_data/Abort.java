package pt.isec.pd.shared_data;

import java.io.Serial;
import java.io.Serializable;

public class Abort implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    private final int nextVersion;

    public Abort(int nextVersion) {
        this.nextVersion = nextVersion;
    }

    public int getNextVersion() {
        return nextVersion;
    }
}
