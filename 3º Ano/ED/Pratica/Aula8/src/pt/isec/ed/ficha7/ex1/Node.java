package pt.isec.ed.ficha7.ex1;

public class Node<T> implements Comparable<T> {
    private T data;
    private Node<T> left, right;

    public Node(T data) {
        this.data = data;
    }

    public T getData() { return data; }

    public Node getLeft() { return left; }

    public Node getRight() { return right; }

    public void setData(T data) { this.data = data; }

    public void setLeft(Node left) { this.left = left; }

    public void setRight(Node right) { this.right = right; }

    @Override
    public int compareTo(T o) {
        return this.compareTo(o);
    }
}
