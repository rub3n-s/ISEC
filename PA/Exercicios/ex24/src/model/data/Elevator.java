package model.data;

public class Elevator {
    private int currentFloor;
    public Elevator(int currentFloor) {
        this.currentFloor = currentFloor;
    }

    public int getCurrentFloor() {
        return currentFloor;
    }

    public void setCurrentFloor(int currentFloor) {
        this.currentFloor = currentFloor;
    }

    @Override
    public String toString() {
        return "Elevador -> CurrentFloor: " + currentFloor;
    }
}