import java.util.Random;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Tests for Binary Search tree implimentations
 * @author Caleb Pollock
 */
class TestTrees {

   private BinarySearchTree<Integer,Integer> bst;
   Random r = new Random();

   @BeforeEach
   public void init() {
      bst = new BinarySearchTree<Integer,Integer>();
   }

   @AfterEach
   public void close() {
      /* do nothing */
   }

   @Test
   public void testGetEmptyBST() {
      assertEquals(bst.get(5),null);
      assertEquals(bst.get(7),null);
      assertEquals(bst.get(null),null);
   }

   @Test
   public void testAddBST() {
      bst.add(5,5);
      assertEquals(1,bst.getSize());
      assertEquals(0,bst.getDepth());
      bst.add(7,5);
      assertEquals(2,bst.getSize());
      assertEquals(1,bst.getDepth());
      bst.add(5,7);
      assertEquals(2,bst.getSize());
      assertEquals(1,bst.getDepth());
      bst.add(4,7);
      assertEquals(3,bst.getSize());
      assertEquals(bst.getDepth(),1);
      bst.add(3,7);
      assertEquals(4,bst.getSize());
      assertEquals(2,bst.getDepth());
      bst.add(2,7);
      assertEquals(5,bst.getSize());
      assertEquals(3,bst.getDepth());
      bst.add(9,7);
      assertEquals(6,bst.getSize());
      assertEquals(3,bst.getDepth());
      bst.add(6,7);
      assertEquals(7,bst.getSize());
      assertEquals(3,bst.getDepth());
      bst.add(8,7);
      assertEquals(8,bst.getSize());
      assertEquals(3,bst.getDepth());
      bst.add(10,7);
      assertEquals(9,bst.getSize());
      bst.add(0,7);
      assertEquals(10,bst.getSize());
      bst.add(1,7);
      assertEquals(11,bst.getSize());
      bst.add(14,7);
      assertEquals(12,bst.getSize());
      bst.add(16,7);
      assertEquals(13,bst.getSize());
      bst.add(11,7);
      assertEquals(14,bst.getSize());
      bst.add(12,7);
      assertEquals(15,bst.getSize());
      bst.add(13,7);
      assertEquals(16,bst.getSize());
   }

   @Test 
   public void testGetBST() {
      bst.add(5,5);
      bst.add(7,5);
      bst.add(5,7);
      bst.add(4,4);
      bst.add(3,3);
      bst.add(2,2);
      bst.add(1,1);
      bst.add(0,0);
      bst.add(9,9);
      bst.add(6,6);
      bst.add(8,8);

      assertEquals(7,bst.get(5));
      assertEquals(5,bst.get(7));
      assertEquals(4,bst.get(4));
      assertEquals(3,bst.get(3));
      assertEquals(2,bst.get(2));
      assertEquals(1,bst.get(1));
      assertEquals(0,bst.get(0));
      assertEquals(9,bst.get(9));
      assertEquals(6,bst.get(6));
      assertEquals(8,bst.get(8));
   }

   @Test
   public void testRemoveNoChildrenBST() {
      bst.add(5,5);
      bst.add(7,5);
      bst.add(5,7);
      bst.add(4,4);
      bst.add(2,2);
      bst.add(3,3);
      bst.add(1,1);
      bst.add(0,0);
      bst.add(9,9);
      bst.add(6,6);
      bst.add(8,8);

      assertEquals(0,bst.remove(0));
      assertEquals(null,bst.get(0));
      assertEquals(1,bst.remove(1));
      assertEquals(null,bst.get(1));
      assertEquals(6,bst.remove(6));
      assertEquals(null,bst.get(6));
      assertEquals(8,bst.remove(8));
      assertEquals(null,bst.get(8));
      assertEquals(9,bst.remove(9));
      assertEquals(null,bst.get(9));
      assertEquals(3,bst.remove(3));
      assertEquals(null,bst.get(3));
      assertEquals(2,bst.remove(2));
      assertEquals(null,bst.get(2));
      assertEquals(4,bst.remove(4));
      assertEquals(null,bst.get(4));
      assertEquals(5,bst.remove(7));
      assertEquals(null,bst.get(7));
      assertEquals(7,bst.remove(5));
      assertEquals(null,bst.get(5));
   }

   @Test
   public void testRemoveBST() {
      bst.add(5,5);
      bst.add(7,7);
      bst.add(4,4);
      bst.add(2,2);
      bst.add(3,3);
      bst.add(1,1);
      bst.add(0,0);
      bst.add(9,9);
      bst.add(20,20);
      bst.add(6,6);
      bst.add(8,8);

      bst.printInOrder();
      assertEquals(11,bst.getSize());
      assertEquals(4,bst.remove(4));
      bst.printInOrder();
      assertEquals(10,bst.getSize());
      assertEquals(null,bst.get(4));
      assertEquals(3,bst.get(3));
      assertEquals(2,bst.get(2));
      assertEquals(3,bst.remove(3));
      bst.printInOrder();
      assertEquals(9,bst.getSize());
      assertEquals(null,bst.get(3));
      assertEquals(2,bst.get(2));
      assertEquals(1,bst.get(1));
      assertEquals(20,bst.get(20));
      assertEquals(20,bst.remove(20));
      assertEquals(8,bst.getSize());
      assertEquals(null,bst.get(20));
      bst.printInOrder();
      assertEquals(5,bst.remove(5)); 
      bst.printInOrder();
      assertEquals(7,bst.getSize());
      assertEquals(null,bst.get(5));
      assertEquals(2,bst.get(2));
      assertEquals(7,bst.get(7));
      assertEquals(9,bst.remove(9));
      assertEquals(6,bst.getSize());
      assertEquals(null,bst.get(9));
      bst.printInOrder();
      assertEquals(8,bst.get(8));
      assertEquals(6,bst.get(6));
      assertEquals(7,bst.remove(7));
      assertEquals(5,bst.getSize());
      assertEquals(null,bst.get(7));
      bst.printInOrder();
      assertEquals(8,bst.get(8));
      assertEquals(6,bst.get(6));
      assertEquals(6,bst.remove(6));
      bst.printInOrder();
      assertEquals(4,bst.getSize());
      assertEquals(null,bst.get(6));
      assertEquals(8,bst.get(8));
      assertEquals(8,bst.remove(8));
      assertEquals(3,bst.getSize());
      assertEquals(null,bst.get(8));
      bst.printInOrder();
      assertEquals(2,bst.remove(2));
      bst.printInOrder();
      assertEquals(2,bst.getSize());
      assertEquals(null,bst.get(2));
      assertEquals(1,bst.get(1));
      assertEquals(0,bst.get(0));
      assertEquals(0,bst.remove(0));
      bst.printInOrder();
      assertEquals(1,bst.getSize());
      assertEquals(null,bst.get(0));
      assertEquals(1,bst.get(1));
      assertEquals(1,bst.remove(1));
      assertEquals(0,bst.getSize());
      bst.printInOrder();
      assertEquals(null,bst.get(1));
      assertEquals(null,bst.remove(1));
   }

   @Test
   public void stressTestBST() {
      for (int i = 0; i < 100; i++) {
         System.out.println(i);
         bst.add(Math.abs(r.nextInt()%1000),i);
      }
      bst.printInOrder();
      for (int i = 0; i < 1000; i++) {
         System.out.println(i);
         if (null != bst.remove(i)) {
            assertEquals(null,bst.get(i));
         }
      }
      bst.printInOrder();
      assertEquals(0,bst.getSize());
   }
}
