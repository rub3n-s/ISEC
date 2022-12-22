package pt.isec.ed.ficha7.ex1;

import java.util.*;

public class Main {
    public static void main(String[] args) {
        BinaryTree<String> bTree = new BinaryTree<>();

        // Insert Nodes
        bTree.insert("D");
        bTree.insert("B");
        bTree.insert("E");
        bTree.insert("A");
        bTree.insert("C");
        bTree.insert("F");
        bTree.insert("H");
        bTree.insert("G");

        // Contains a Node
        System.out.println(bTree.contains("A"));

        // Deepness of a Node
        System.out.println(bTree.deepness("B"));

        // Print
        System.out.println("\nIn order");
        bTree.printOrder();

        // Ex4
        Comparator c = new Comparator<String>() {
            public int compare(String s1, String s2) {
                return s1.length() - s2.length();
            }
        };

        BinaryTree<String> bTree2 = new BinaryTree<>(c);

        // Insert Nodes
        bTree2.insert("D");
        bTree2.insert("BB");
        bTree2.insert("EEE");
        bTree2.insert("AAAA");
        bTree2.insert("CCCCC");
        bTree2.insert("FFFFFF");
        bTree2.insert("HHHHHHH");
        bTree2.insert("GGGGGGGG");        

        System.out.println("\nStrings Order");
        bTree2.printOrder();

        // Print By Levels
        bTree2.printByLevels();

        // Remove node
        bTree2.remove("CCCCC");

        bTree2.printByLevels();

        // Remove single nodes
        BinaryTree<String> bTree3 = new BinaryTree<>();

        // Insert Nodes
        bTree3.insert("B");
        bTree3.insert("A");
        bTree3.insert("C");
        bTree3.insert("D");

        // Before removing
        bTree3.printByLevels();

        bTree3.removeSingleNodes();

        // After removing
        bTree3.printByLevels();

        // Exercicio 6
        int a, b, hl;
        Integer temp;
        final int length = 1000000;
        BinaryTree<Integer> bTree4 = new BinaryTree<>();
        ArrayList<Integer> list = new ArrayList<>();

        for (int i = 0; i < length; i++)
            list.add(i);

        //Collections.shuffle(list);
        Random r = new Random();
        hl = length/2;      // experimentar length/2 e outros valores
        for (int i = 0; i < hl; i++) {  // baralhar metade do array
            a = r.nextInt(length);
            b = r.nextInt(length);

            temp = list.get(a);

            list.set(a,list.get(b));
            list.set(b,temp);
        }

        Iterator listIt = list.iterator();
        while(listIt.hasNext())
            bTree4.insert((Integer)listIt.next());

        System.out.println("bTree4 deepness: " + bTree4.treeDeepness());
        System.out.println("bTree4 elements: " + bTree4.size());
        System.out.println("Should have this levels: " + Math.log(length)/Math.log(2));
    }
}
