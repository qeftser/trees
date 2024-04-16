import java.util.Random;

public class TreeTests {

   public static void main(String args[]) {

      Random rand = new Random();
      final int cycles = 10000000;
      int elements[] = new int[cycles];

      for (int i = 0; i < cycles; i++) {
         elements[i] = Math.abs(rand.nextInt());
      }
      
      System.out.println("==== Binary Search Tree ====");

      BinarySearchTree t = new BinarySearchTree();

      System.out.println("before");
      for (int i = 0; i < cycles; i++) {
         t.insert(elements[i],i);
      }
      t.inOrderPrint();
      for (int i = 0; i < cycles; i++) {
         t.delete(elements[i]);
      }
      System.out.println("after");
      t.inOrderPrint();

      System.out.println("==== Red Black Tree ====");

      RedBlackTree r = new RedBlackTree();

      for (int i = 0; i < cycles; i++) {
         r.insert(elements[i],i);
      }
      System.out.println("before");
      r.inOrderPrint();
      for (int i = 0; i < cycles; i++) {
         r.delete(elements[i]);
      }
      System.out.println("after");
      r.inOrderPrint();

   }
}
