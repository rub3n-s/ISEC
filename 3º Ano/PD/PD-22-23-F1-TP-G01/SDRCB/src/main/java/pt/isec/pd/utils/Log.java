package pt.isec.pd.utils;

import java.text.SimpleDateFormat;
import java.util.Date;

public class Log {
    private static Log Log;
    private static String owner;
    private Log() {}

    public static <T> Log getLogger(Class<T> type) {
        if (Log == null) {
            Log = new Log();
        }
        owner = type.getSimpleName();
        return Log;
    }

    private String getDate() {
        SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
        return sdf.format(new Date());
    }

    public void log(String msg) {
        System.out.println("[" + owner + " " + getDate() + "] - " + msg);
    }
}