package pt.isec.pd.server.threads.client;

import pt.isec.pd.client.model.data.ClientData;

import java.util.TimerTask;

public class Submission {
    ClientData submit;
    TimerTask task;

    public Submission(ClientData submit, TimerTask task) {
        this.submit = submit;
        this.task = task;
    }

    public ClientData getSubmit() {
        return submit;
    }

    public void setSubmit(ClientData submit) {
        this.submit = submit;
    }

    public TimerTask getTask() {
        return task;
    }

    public void setTask(TimerTask task) {
        this.task = task;
    }
}
