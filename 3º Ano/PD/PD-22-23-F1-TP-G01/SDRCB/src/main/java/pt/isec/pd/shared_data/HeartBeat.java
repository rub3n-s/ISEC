package pt.isec.pd.shared_data;

import pt.isec.pd.utils.Constants;

import java.io.Serializable;
import java.util.Date;
import java.util.Objects;

public class HeartBeat implements Serializable,Comparable<HeartBeat> {
    private int portTcp;
    private boolean status;
    private int dbVersion;
    private int activeConnections;
    private String ip;
    private Date timeout;

    public HeartBeat(int portTcp, boolean status, int dbVersion, int activeConnections,String ip) {
        this.portTcp = portTcp;
        this.status = status;
        this.dbVersion = dbVersion;
        this.ip = ip;
        this.activeConnections = activeConnections;
        this.timeout = addTimeStamp(new Date());
    }

    public Date addTimeStamp(Date currentTime) {
        currentTime.setSeconds(currentTime.getSeconds() + Constants.TIMESTAMP);
        timeout = currentTime;
        return timeout;
    }

    public int getPortTcp() {
        return portTcp;
    }

    public void setPortTcp(int portTcp) {
        this.portTcp = portTcp;
    }

    public boolean isStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

    public int getDbVersion() {
        return dbVersion;
    }

    public void setDbVersion(int dbVersion) {
        this.dbVersion = dbVersion;
    }

    public int getActiveConnections() {
        return activeConnections;
    }

    public void setActiveConnections(int activeConnections) {
        this.activeConnections = activeConnections;
    }

    public Date getTimeout() {
        return timeout;
    }

    public void setTimeout(Date timeout) {
        this.timeout = timeout;
    }

    public String getIp() {
        return ip;
    }

    public void setIp(String ip) {
        this.ip = ip;
    }

    @Override
    public int compareTo(HeartBeat o) {
        return activeConnections - o.activeConnections;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        HeartBeat that = (HeartBeat) o;
        return portTcp == that.portTcp;
    }

    @Override
    public int hashCode() {
        return Objects.hash(portTcp);
    }

    @Override
    public String toString() {
        return  "tcp port: " + portTcp + " activeConnection: " + activeConnections +  " dbVersion: " + dbVersion +"\n";
    }
}