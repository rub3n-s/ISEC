package pt.isec.ed.ficha7.ex1;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.ListIterator;

public class BinaryTree<T extends Comparable<? super T>> {
    private Node rootNode;
    private Comparator<T> comparator;
    private int numElements;

    BinaryTree(Comparator<T> comparator) {
        this.comparator = comparator;
    }

    BinaryTree() {
        this.comparator = new Comparator<T>() {
            @Override
            public int compare(T o1, T o2) {
                return o1.compareTo(o2);
            }
        };
    }

    public void insert(T t) { Node n = new Node<>(t); rootNode = insert(rootNode,n);}

    private Node<T> insert(Node<T> rootNode, Node<T> newNode) {     // metodo privado recursivo
        if (rootNode == null) return newNode;                       // novo no passa a ser raiz da arvore
        int cmp = comparator.compare(rootNode.getData(), newNode.getData());
        if (cmp == 0) throw new RuntimeException();     // valor duplicado
        if (cmp > 0)
            rootNode.setLeft(insert(rootNode.getLeft(),newNode));
        else
            rootNode.setRight(insert(rootNode.getRight(),newNode));
        return rootNode;
    }

    // 1 b) b)
    public boolean contains(T value) {
        return containsRecursive(rootNode,value);
    }

    private boolean containsRecursive(Node<T> node, T value) {
        if (node == null)
            return false;

        int cmp = comparator.compare(value, node.getData());
        if (cmp == 0) return true;  // esta no nó recorrente

        // está do lado esquerdo
        if (cmp < 0) return containsRecursive(node.getLeft(),value);

        // apenas resta estar do lado direito
        return containsRecursive(node.getRight(),value);
    }

    // 1 b) c)
    public int deepness(T value) {
        return deepnessRecursive(rootNode,value);
    }

    private int deepnessRecursive(Node<T> node, T value) {
        int d;

        if (node == null)
            return 0;
        
        if (value.compareTo(node.getData()) == 0) return 1;
        
        d = deepnessRecursive(node.getLeft(),value);
        if (d > 0)
            return d+1;

        d = deepnessRecursive(node.getRight(),value);
        if (d > 0)
            return d+1;
        return 0;
    }

    public void preOrder(Node<T> root) {
        if (root == null) return;
        System.out.println(root.getData());
        preOrder(root.getLeft());
        preOrder(root.getRight());
    }

    public void postOrder(Node<T> root,List<T> storageList) {
        if (root == null) return;
        preOrder(root.getLeft());
        preOrder(root.getRight());
        System.out.println(root.getData());
    }

    // Outro exemplo
    public void printOrder() {
        List<T> inOrderList = new ArrayList<>();
        order(rootNode,inOrderList);
        printList(inOrderList);
    }

    private void order(Node<T> root, List<T> storageList) {
        if (root == null) return;
        order(root.getLeft(),storageList);
        storageList.add(root.getData());
        order(root.getRight(),storageList);
    }

    public void printList(List<T> list) {
        for (T item : list)
            System.out.println(item);
    }

    // Profundidade da arvore
    public int treeDeepness() {
        return treeDeepness(rootNode);
    }

    private int treeDeepness(Node<T> node) {
        if (node == null) return 0;        
        int dl = treeDeepness(node.getLeft());
        int dr = treeDeepness(node.getRight());
        return dl > dr ? dl + 1 : dr + 1;
    }

    // Numero de valores armazenados
    public int size() { 
        return size(rootNode);
    }

    private int size(Node<T> node) {
        if (node == null) return 0;
        return 1 + size(node.getLeft()) + size(node.getRight());
    }

    // Imprimir niveis
    public void printLevel() {
        List<Node<T>> list = new ArrayList<>();

        list.add(rootNode);

        System.out.println("======== Conteúdo da Árvore ========");

        while(!list.isEmpty()) {
            Node<T> n = list.remove(0);

            System.out.println(n.getData() + " "); // mostra valor

            if (n.getLeft() != null) list.add(n.getLeft());
            if (n.getRight() != null) list.add(n.getRight());
        }
    }

    public void printLevel_v2(Node<T> t, List<T> lst, int level) {
        T item;
        System.out.println("------ Nível " + level + " -----");
        ListIterator li = lst.listIterator();
        while (li.hasNext()) {
            item = (T) li.next();
            if (deepnessRecursive(rootNode,item) == level)
                System.out.println("[" + level + "]" + item);
        }
    }

    public void printByLevels() {
        int l = treeDeepness(rootNode);
        List<T> lst = new ArrayList<>();
        order(rootNode,lst);
        System.out.println("====== Conteudo da Arvore ======");
        for (int j = 1; j <= l; j++)
            printLevel_v2(rootNode,lst,j);
        System.out.println();
    }


    // Exercicio 7
    public void remove(T value) { rootNode = remove(rootNode,value); }

    private Node<T> remove(Node<T> node, T value) {
        if (node == null) return null;
        int cmp = comparator.compare(value, node.getData());

        // cmp == 0 - Apagar aqui
        if (cmp < 0) { node.setLeft(remove(node.getLeft(), value)); return node; }
        if (cmp > 0) { node.setRight(remove(node.getRight(), value)); return node; }

        // Pelo menos um dos filhos não é null
        if (node.getLeft() == null) return node.getRight();
        if (node.getRight() == null) return node.getLeft();

        // Tem 2 filhos
        System.out.println("tem 2 filhos, o " + node.getData());
        Node<T> min = minimumElement(node.getRight());
        node.setData(min.getData());
        node.setRight(remove(node.getRight(),min.getData()));
        return node;
    }

    private Node<T> minimumElement(Node<T> root) {
        if (root.getLeft() == null) return root;
        return minimumElement(root.getLeft());
    }

    // Exercicio 8
    public void removeSingleNodes() { rootNode = removeSingleNodes(rootNode); }

    private Node<T> removeSingleNodes(Node<T> node) {
        if (node == null) return null;

        // nao tem descendentes
        if (node.getRight() == null && node.getLeft() == null)
            return node;

        // tem dois descendentes
        if (node.getLeft() != null && node.getRight() != null) {
            node.setLeft(removeSingleNodes(node.getLeft()));
            node.setRight(removeSingleNodes(node.getRight()));
            return node;
        }

        if (node.getLeft() == null) return removeSingleNodes(node.getRight());  // só descendente direito

        return removeSingleNodes(node.getLeft());   // só descendente esquerdo
    }
}
