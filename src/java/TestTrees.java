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

   @BeforeEach
   public void init() {
      bst = new BinarySearchTree<Integer,Integer>();
   }

   @AfterEach
   public void close() {
      /* do nothing */
   }

   @Test
   public void testGetEmpty() {
      assertEquals(bst.get(5),null);
      assertEquals(bst.get(7),null);
      assertEquals(bst.get(null),null);
   }

   @Test
   public void testAdd() {
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
   }

   @Test 
   public void testGet() {
      bst.add(5,5);
      bst.add(7,5);
      bst.add(5,7);
      bst.add(4,4);
      bst.add(3,3);
      bst.add(2,2);
      bst.add(1,1);
      bst.add(0,0);
      bst.add(9,9);

      assertEquals(7,bst.get(5));
      assertEquals(5,bst.get(7));
      assertEquals(4,bst.get(4));
      assertEquals(3,bst.get(3));
      assertEquals(2,bst.get(2));
      assertEquals(1,bst.get(1));
      assertEquals(0,bst.get(0));
      assertEquals(9,bst.get(9));
   }

   @Test
   public void testRemove() {
      bst.add(5,5);
      bst.add(7,5);
      bst.add(5,7);
      bst.add(4,4);
      bst.add(3,3);
      bst.add(2,2);
      bst.add(1,1);
      bst.add(0,0);
      bst.add(9,9);

      assertEquals(0,bst.remove(0));
      assertEquals(null,bst.get(0));
      assertEquals(7,bst.remove(5));
      assertEquals(null,bst.get(5));
      assertEquals(5,bst.remove(7));
      assertEquals(null,bst.get(7));
      assertEquals(4,bst.remove(4));
      assertEquals(null,bst.get(4));
      assertEquals(3,bst.remove(3));
      assertEquals(null,bst.get(3));
      assertEquals(1,bst.remove(1));
      assertEquals(null,bst.get(1));
      assertEquals(9,bst.remove(9));
      assertEquals(null,bst.get(9));
      assertEquals(2,bst.remove(2));
      assertEquals(null,bst.get(2));
   }
}
