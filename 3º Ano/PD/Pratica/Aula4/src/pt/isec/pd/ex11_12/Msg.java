package pt.isec.pd.ex11_12;

import java.io.Serializable;

public class Msg implements Serializable {
    protected String msg;
    protected String nickname;

    public Msg(String nickname,String msg) {
        this.msg = msg;
        this.nickname = nickname;
    }

    public String getNickname() {
        return nickname;
    }

    public String getMsg() {
        return msg;
    }

    @Override
    public String toString() {
        return nickname + " " + msg;
    }
}
