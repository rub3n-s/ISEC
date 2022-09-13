package model.fsm;

public class ModelLog {
    private static ModelLog instance = null;
    StringBuilder sb;

    public static ModelLog getInstance() {
        if (instance == null)
            instance = new ModelLog();
        return instance;
    }

    protected ModelLog() {
        sb = new StringBuilder("\n__________________\n\tLog\n__________________\n");
    }

    public boolean addMessage(String msg) {
        if (msg != null) {
            sb.append(msg+"\n");
            return true;
        }
        return false;
    }

    public boolean delMessages() {
        if (!sb.isEmpty()) {
            sb.delete(0, sb.length());
            return true;
        }
        return false;
    }

    public boolean showMessages() {
        if (!sb.isEmpty()) {
            System.out.println(sb.toString());
            return true;
        }
        return false;
    }
}
