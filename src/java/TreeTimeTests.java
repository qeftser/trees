import java.util.Random;

/**
 * Timing Tests for the implimented trees
 * @author Caleb Pollock
 */
public class TreeTimeTests {

   private static RedBlackTree rb;
   private static BinarySearchTree bs;

   public static void reset() {
      rb = new RedBlackTree();
      bs = new BinarySearchTree();
   }

   public static void main(String args[]) {

      int cycles = 100;
      long start;
      double res[] = new double[2];
      Random rand = new Random();
      long clocksPerNanoSecond = 1000000000L;

      reset();

      while (cycles < 0x0fffffff) {
         System.out.printf("\n======= TIMING %d TREE INSERTIONS =======\n",cycles);

         System.out.println("\n=== RANDOM INPUT ===");
         int elements[] = new int[cycles];
         for (int i = 0; i < cycles; i++) {
            elements[i] = Math.abs(rand.nextInt());
         }

         System.out.println("Results:");

         start = System.nanoTime();
         for (int i = 0; i < cycles; i++) {
            bs.insert(elements[i],i);
         }
         res[0] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

         start = System.nanoTime();
         for (int i = 0; i < cycles; i++) {
            rb.insert(elements[i],i);
         }
         res[1] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

         System.out.print("Binary Search Tree (Inserts)   :");
         if (res[0] > res[1]) System.out.print("\033[31m"); else System.out.print("\033[32m");
         System.out.printf(" %f\033[0m\n",res[0]);
         System.out.print("Red Black Tree     (Inserts)   :");
         if (res[1] > res[0]) System.out.print("\033[31m"); else System.out.print("\033[32m");
         System.out.printf(" %f\033[0m\n",res[1]);

         start = System.nanoTime();
         for (int i = 0; i < cycles; i++) {
            bs.get(elements[i]);
         }
         res[0] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

         start = System.nanoTime();
         for (int i = 0; i < cycles; i++) {
            rb.get(elements[i]);
         }
         res[1] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

         System.out.print("Binary Search Tree (Queries)   :");
         if (res[0] > res[1]) System.out.print("\033[31m"); else System.out.print("\033[32m");
         System.out.printf(" %f\033[0m\n",res[0]);
         System.out.print("Red Black Tree     (Queries)   :");
         if (res[1] > res[0]) System.out.print("\033[31m"); else System.out.print("\033[32m");
         System.out.printf(" %f\033[0m\n",res[1]);

         start = System.nanoTime();
         for (int i = 0; i < cycles; i++) {
            bs.delete(elements[i]);
         }
         res[0] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

         start = System.nanoTime();
         for (int i = 0; i < cycles; i++) {
            rb.delete(elements[i]);
         }
         res[1] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

         System.out.print("Binary Search Tree (Deletes)   :");
         if (res[0] > res[1]) System.out.print("\033[31m"); else System.out.print("\033[32m");
         System.out.printf(" %f\033[0m\n",res[0]);
         System.out.print("Red Black Tree     (Deletes)   :");
         if (res[1] > res[0]) System.out.print("\033[31m"); else System.out.print("\033[32m");
         System.out.printf(" %f\033[0m\n",res[1]);

         reset();

         if (cycles < 10000000) {

            System.out.println("\n=== ORDERED INPUT ===");

            System.out.println("Results:");

            start = System.nanoTime();
            for (int i = 0; i < cycles; i++) {
               bs.insert(i,i);
            }
            res[0] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

            start = System.nanoTime();
            for (int i = 0; i < cycles; i++) {
               rb.insert(i,i);
            }
            res[1] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

            System.out.print("Binary Search Tree (Inserts)   :");
            if (res[0] > res[1]) System.out.print("\033[31m"); else System.out.print("\033[32m");
            System.out.printf(" %f\033[0m\n",res[0]);
            System.out.print("Red Black Tree     (Inserts)   :");
            if (res[1] > res[0]) System.out.print("\033[31m"); else System.out.print("\033[32m");
            System.out.printf(" %f\033[0m\n",res[1]);

            start = System.nanoTime();
            for (int i = 0; i < cycles; i++) {
               bs.get(i);
            }
            res[0] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

            start = System.nanoTime();
            for (int i = 0; i < cycles; i++) {
               rb.get(i);
            }
            res[1] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

            System.out.print("Binary Search Tree (Queries)   :");
            if (res[0] > res[1]) System.out.print("\033[31m"); else System.out.print("\033[32m");
            System.out.printf(" %f\033[0m\n",res[0]);
            System.out.print("Red Black Tree     (Queries)   :");
            if (res[1] > res[0]) System.out.print("\033[31m"); else System.out.print("\033[32m");
            System.out.printf(" %f\033[0m\n",res[1]);

            start = System.nanoTime();
            for (int i = 0; i < cycles; i++) {
               bs.delete(i);
            }
            res[0] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

            start = System.nanoTime();
            for (int i = 0; i < cycles; i++) {
               rb.delete(i);
            }
            res[1] = (double)(System.nanoTime() - start)/clocksPerNanoSecond;

            System.out.print("Binary Search Tree (Deletes)   :");
            if (res[0] > res[1]) System.out.print("\033[31m"); else System.out.print("\033[32m");
            System.out.printf(" %f\033[0m\n",res[0]);
            System.out.print("Red Black Tree     (Deletes)   :");
            if (res[1] > res[0]) System.out.print("\033[31m"); else System.out.print("\033[32m");
            System.out.printf(" %f\033[0m\n",res[1]);

            reset();
         }

         cycles *= 10;
      }
   }
}
