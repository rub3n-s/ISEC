package pt.isec.pd.ex9;

import java.io.IOException;
import java.io.Serial;
import java.io.Serializable;

public class FicheiroByteArray implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;

    private byte[] chunk;
    private int nBytes;
    private boolean complete;

    public FicheiroByteArray() {
        complete = false;
    }

    public void setArrayBytes(byte[] chunk, int nBytes) throws IOException {
        this.chunk = chunk;
        this.nBytes = nBytes;
    }

    public byte[] getArray() { return chunk; }

    public int getNBytes() { return nBytes; }

    public boolean isComplete() { return complete; }

    public void setComplete() { complete = true; }
}
