
import java.util.Random;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

/**
 * Functionality tests for the implimented trees
 * @author Caleb Pollock
 */
class TreeTests {
   private RedBlackTree rb;
   private BinarySearchTree bs;
   private GenericBinarySearchTree<Integer,Integer> gbs;
   private GenericRedBlackTree<Integer,Integer> grb;

   @BeforeEach
   public void reset() {
      rb = new RedBlackTree();
      bs = new BinarySearchTree();
      gbs = new GenericBinarySearchTree<Integer,Integer>();
      grb = new GenericRedBlackTree<Integer,Integer>();
   }

   @Test
   public void testAddRedBlack() {
      rb.insert(1,1);
      assertEquals(1,rb.get(1));

      for (int i = 0; i < 10; i++) {
         rb.insert(i,i);
         assertEquals(i,rb.get(i));
      }

      for (int i = -10; i < 0; i++) {
         rb.insert(i,i);
         assertEquals(i,rb.get(i));
      }
   }

   @Test
   public void testAddFixupCasesRedBlack() {
      int addList1[] = { 11, 14, 2, 15, 1, 7, 8, 5, 4 };
      int addList2[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17 };
      int addList3[] = { 11, 5, 15, 17, 19 };
      int addList4[] = { 11, 5, 15, 4, 3, 17, 19, 6, 7, 8, 9, 10 };
      int addList5[] = { 20, 10, 25, 27, 2, 19, 22, 1, 3, 18, 17,
                         16, 15, 14, 13, 12, 11 };

      for (int i = 0; i < addList1.length; i++) {
         rb.insert(addList1[i],i);
      }

      for (int i = 0; i < addList1.length; i++) {
         assertEquals(i,rb.get(addList1[i]));
      }

      reset();
      
      for (int i = 0; i < addList2.length; i++) {
         rb.insert(addList2[i],i);
      }

      for (int i = 0; i < addList2.length; i++) {
         assertEquals(i,rb.get(addList2[i]));
      }

      reset();

      for (int i = 0; i < addList3.length; i++) {
         rb.insert(addList3[i],i);
      }

      for (int i = 0; i < addList3.length; i++) {
         assertEquals(i,rb.get(addList3[i]));
      }

      reset();
      
      for (int i = 0; i < addList4.length; i++) {
         rb.insert(addList4[i],i);
      }

      for (int i = 0; i < addList4.length; i++) {
         assertEquals(i,rb.get(addList4[i]));
      }

      reset();

      for (int i = 0; i < addList5.length; i++) {
         rb.insert(addList5[i],i);
      }

      for (int i = 0; i < addList5.length; i++) {
         assertEquals(i,rb.get(addList5[i]));
      }

      reset();
   }

   @Test
   public void testDeleteRedBlack() {
      for (int i = 0; i < 10; i++) {
         rb.insert(i,i);
      }
      for (int i = -10; i < 0; i++) {
         rb.insert(i,i);
      }
      for (int i = -10; i < 10; i++) {
         rb.delete(i);
         assertEquals(-1,rb.get(i));
      }
   }

   @Test
   public void testDeleteFixupCasesRedBlack() {
      int list1[] = { 11, 5, 15 };
      int list2[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17 };
      int list3[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17, 18, 19 };
      int list4[] = { 20, 10, 25, 27, 2, 19, 22, 1, 3, 18, 17, 16,
                      15, 14, 13, 12, 11 };
      int list5[] = { 20, 19, 21, 18, 22, 17, 23, 16, 24, 15, 25, 14,
                      26, 13, 27, 12, 28, 11, 30, 10, 31, 9, 32, 8, 33,
                      7, 34, 6, 35, 5, 36, 4, 37, 3, 38, 2, 39, 1, 40, 0 };
      int list6[] = { 5, 7, 4, 2, 3, 1, 0, 9, 6, 8 };
      int deleteOrder1[] = { 5, 15, 11 };
      int deleteOrder2[] = { 11, 2, 20, 1, 17, 16, 14, 15 };
      int deleteOrder3[] = { 15, 14, 17, 16, 11, 2, 20, 19, 18 };
      int deleteOrder4[] = { 18, 17, 15, 19, 27, 11, 20, 12, 22, 14, 13, 10 };
      int deleteOrder5[] = { 33, 34, 25, 35, 36, 38 };
      int deleteOrder6[] = { 0, 1, 6, 8, 9, 3, 2, 4, 7, 5};

      for (int i = 0; i < list1.length; i++) {
         rb.insert(list1[i],i);
      }

      for (int i = 0; i < deleteOrder1.length; i++) {
         rb.delete(deleteOrder1[i]);
         assertEquals(-1,rb.get(deleteOrder1[i]));
      }

      reset();

      for (int i = 0; i < list2.length; i++) {
         rb.insert(list2[i],i);
      }

      for (int i = 0; i < deleteOrder2.length; i++) {
         rb.delete(deleteOrder2[i]);
         assertEquals(-1,rb.get(deleteOrder2[i]));
      }

      reset();
      
      for (int i = 0; i < list3.length; i++) {
         rb.insert(list3[i],i);
      }

      for (int i = 0; i < deleteOrder3.length; i++) {
         rb.delete(deleteOrder3[i]);
         assertEquals(-1,rb.get(deleteOrder3[i]));
      }

      reset();
      
      for (int i = 0; i < list4.length; i++) {
         rb.insert(list4[i],i);
      }

      for (int i = 0; i < deleteOrder4.length; i++) {
         rb.delete(deleteOrder4[i]);
         assertEquals(-1,rb.get(deleteOrder4[i]));
      }

      reset();
      
      for (int i = 0; i < list5.length; i++) {
         rb.insert(list5[i],i);
      }

      for (int i = 0; i < deleteOrder5.length; i++) {
         rb.delete(deleteOrder5[i]);
         assertEquals(-1,rb.get(deleteOrder5[i]));
      }
      
      reset();
      
      for (int i = 0; i < list6.length; i++) {
         rb.insert(list6[i],i);
      }

      for (int i = 0; i < deleteOrder6.length; i++) {
         rb.delete(deleteOrder6[i]);
         assertEquals(-1,rb.get(deleteOrder6[i]));
      }
   }

   @Test
   public void stressTestRedBlack() {
      Random r = new Random();
      int cycles = 1000000;

      int elements[] = new int[cycles];

      for (int i = 0; i < cycles; i++) {
         elements[i] = Math.abs(r.nextInt());
      }

      for (int i = 0; i < cycles; i++) {
         rb.insert(elements[i],i);
         assertEquals(i,rb.get(elements[i]));
      }

      for (int i = 0; i < cycles; i++) {
         rb.delete(elements[i]);
         assertEquals(-1,rb.get(elements[i]));
      }
   }

   @Test
   public void testAddBinarySearch() {
      bs.insert(1,1);
      assertEquals(1,bs.get(1));

      for (int i = 0; i < 10; i++) {
         bs.insert(i,i);
         assertEquals(i,bs.get(i));
      }

      for (int i = -10; i < 0; i++) {
         bs.insert(i,i);
         assertEquals(i,bs.get(i));
      }
   }

   @Test
   public void testAddFixupCasesBinarySearch() {
      int addList1[] = { 11, 14, 2, 15, 1, 7, 8, 5, 4 };
      int addList2[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17 };
      int addList3[] = { 11, 5, 15, 17, 19 };
      int addList4[] = { 11, 5, 15, 4, 3, 17, 19, 6, 7, 8, 9, 10 };
      int addList5[] = { 20, 10, 25, 27, 2, 19, 22, 1, 3, 18, 17,
                         16, 15, 14, 13, 12, 11 };

      for (int i = 0; i < addList1.length; i++) {
         bs.insert(addList1[i],i);
      }

      for (int i = 0; i < addList1.length; i++) {
         assertEquals(i,bs.get(addList1[i]));
      }

      reset();
      
      for (int i = 0; i < addList2.length; i++) {
         bs.insert(addList2[i],i);
      }

      for (int i = 0; i < addList2.length; i++) {
         assertEquals(i,bs.get(addList2[i]));
      }

      reset();

      for (int i = 0; i < addList3.length; i++) {
         bs.insert(addList3[i],i);
      }

      for (int i = 0; i < addList3.length; i++) {
         assertEquals(i,bs.get(addList3[i]));
      }

      reset();
      
      for (int i = 0; i < addList4.length; i++) {
         bs.insert(addList4[i],i);
      }

      for (int i = 0; i < addList4.length; i++) {
         assertEquals(i,bs.get(addList4[i]));
      }

      reset();

      for (int i = 0; i < addList5.length; i++) {
         bs.insert(addList5[i],i);
      }

      for (int i = 0; i < addList5.length; i++) {
         assertEquals(i,bs.get(addList5[i]));
      }

      reset();
   }

   @Test
   public void testDeleteBinarySearch() {
      for (int i = 0; i < 10; i++) {
         bs.insert(i,i);
      }
      for (int i = -10; i < 0; i++) {
         bs.insert(i,i);
      }
      for (int i = -10; i < 10; i++) {
         bs.delete(i);
         assertEquals(-1,bs.get(i));
      }
   }

   @Test
   public void testDeleteFixupCasesBinarySearch() {
      int list1[] = { 11, 5, 15 };
      int list2[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17 };
      int list3[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17, 18, 19 };
      int list4[] = { 20, 10, 25, 27, 2, 19, 22, 1, 3, 18, 17, 16,
                      15, 14, 13, 12, 11 };
      int list5[] = { 20, 19, 21, 18, 22, 17, 23, 16, 24, 15, 25, 14,
                      26, 13, 27, 12, 28, 11, 30, 10, 31, 9, 32, 8, 33,
                      7, 34, 6, 35, 5, 36, 4, 37, 3, 38, 2, 39, 1, 40, 0 };
      int list6[] = { 5, 7, 4, 2, 3, 1, 0, 9, 6, 8 };
      int deleteOrder1[] = { 5, 15, 11 };
      int deleteOrder2[] = { 11, 2, 20, 1, 17, 16, 14, 15 };
      int deleteOrder3[] = { 15, 14, 17, 16, 11, 2, 20, 19, 18 };
      int deleteOrder4[] = { 18, 17, 15, 19, 27, 11, 20, 12, 22, 14, 13, 10 };
      int deleteOrder5[] = { 33, 34, 25, 35, 36, 38 };
      int deleteOrder6[] = { 0, 1, 6, 8, 9, 3, 2, 4, 7, 5};

      for (int i = 0; i < list1.length; i++) {
         bs.insert(list1[i],i);
      }

      for (int i = 0; i < deleteOrder1.length; i++) {
         bs.delete(deleteOrder1[i]);
         assertEquals(-1,bs.get(deleteOrder1[i]));
      }

      reset();

      for (int i = 0; i < list2.length; i++) {
         bs.insert(list2[i],i);
      }

      for (int i = 0; i < deleteOrder2.length; i++) {
         bs.delete(deleteOrder2[i]);
         assertEquals(-1,bs.get(deleteOrder2[i]));
      }

      reset();
      
      for (int i = 0; i < list3.length; i++) {
         bs.insert(list3[i],i);
      }

      for (int i = 0; i < deleteOrder3.length; i++) {
         bs.delete(deleteOrder3[i]);
         assertEquals(-1,bs.get(deleteOrder3[i]));
      }

      reset();
      
      for (int i = 0; i < list4.length; i++) {
         bs.insert(list4[i],i);
      }

      for (int i = 0; i < deleteOrder4.length; i++) {
         bs.delete(deleteOrder4[i]);
         assertEquals(-1,bs.get(deleteOrder4[i]));
      }

      reset();
      
      for (int i = 0; i < list5.length; i++) {
         bs.insert(list5[i],i);
      }

      for (int i = 0; i < deleteOrder5.length; i++) {
         bs.delete(deleteOrder5[i]);
         assertEquals(-1,bs.get(deleteOrder5[i]));
      }
      
      reset();
      
      for (int i = 0; i < list6.length; i++) {
         bs.insert(list6[i],i);
      }

      for (int i = 0; i < deleteOrder6.length; i++) {
         bs.delete(deleteOrder6[i]);
         assertEquals(-1,bs.get(deleteOrder6[i]));
      }
   }

   @Test
   public void stressTestBinarySearch() {
      Random r = new Random();
      int cycles = 1000000;

      int elements[] = new int[cycles];

      for (int i = 0; i < cycles; i++) {
         elements[i] = Math.abs(r.nextInt());
      }

      for (int i = 0; i < cycles; i++) {
         bs.insert(elements[i],i);
         assertEquals(i,bs.get(elements[i]));
      }

      for (int i = 0; i < cycles; i++) {
         bs.delete(elements[i]);
         assertEquals(-1,bs.get(elements[i]));
      }
   }

   @Test
   public void testAddGenericBinarySearch() {
      gbs.insert(1,1);
      assertEquals(1,gbs.get(1));

      for (int i = 0; i < 10; i++) {
         gbs.insert(i,i);
         assertEquals(i,gbs.get(i));
      }

      for (int i = -10; i < 0; i++) {
         gbs.insert(i,i);
         assertEquals(i,gbs.get(i));
      }
   }

   @Test
   public void testAddFixupCasesGenericBinarySearch() {
      int addList1[] = { 11, 14, 2, 15, 1, 7, 8, 5, 4 };
      int addList2[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17 };
      int addList3[] = { 11, 5, 15, 17, 19 };
      int addList4[] = { 11, 5, 15, 4, 3, 17, 19, 6, 7, 8, 9, 10 };
      int addList5[] = { 20, 10, 25, 27, 2, 19, 22, 1, 3, 18, 17,
                         16, 15, 14, 13, 12, 11 };

      for (int i = 0; i < addList1.length; i++) {
         gbs.insert(addList1[i],i);
      }

      for (int i = 0; i < addList1.length; i++) {
         assertEquals(i,gbs.get(addList1[i]));
      }

      reset();
      
      for (int i = 0; i < addList2.length; i++) {
         gbs.insert(addList2[i],i);
      }

      for (int i = 0; i < addList2.length; i++) {
         assertEquals(i,gbs.get(addList2[i]));
      }

      reset();

      for (int i = 0; i < addList3.length; i++) {
         gbs.insert(addList3[i],i);
      }

      for (int i = 0; i < addList3.length; i++) {
         assertEquals(i,gbs.get(addList3[i]));
      }

      reset();
      
      for (int i = 0; i < addList4.length; i++) {
         gbs.insert(addList4[i],i);
      }

      for (int i = 0; i < addList4.length; i++) {
         assertEquals(i,gbs.get(addList4[i]));
      }

      reset();

      for (int i = 0; i < addList5.length; i++) {
         gbs.insert(addList5[i],i);
      }

      for (int i = 0; i < addList5.length; i++) {
         assertEquals(i,gbs.get(addList5[i]));
      }

      reset();
   }

   @Test
   public void testDeleteGenericBinarySearch() {
      for (int i = 0; i < 10; i++) {
         gbs.insert(i,i);
      }
      for (int i = -10; i < 0; i++) {
         gbs.insert(i,i);
      }
      for (int i = -10; i < 10; i++) {
         gbs.delete(i);
         assertEquals(null,gbs.get(i));
      }
   }

   @Test
   public void testDeleteFixupCasesGenericBinarySearch() {
      int list1[] = { 11, 5, 15 };
      int list2[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17 };
      int list3[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17, 18, 19 };
      int list4[] = { 20, 10, 25, 27, 2, 19, 22, 1, 3, 18, 17, 16,
                      15, 14, 13, 12, 11 };
      int list5[] = { 20, 19, 21, 18, 22, 17, 23, 16, 24, 15, 25, 14,
                      26, 13, 27, 12, 28, 11, 30, 10, 31, 9, 32, 8, 33,
                      7, 34, 6, 35, 5, 36, 4, 37, 3, 38, 2, 39, 1, 40, 0 };
      int list6[] = { 5, 7, 4, 2, 3, 1, 0, 9, 6, 8 };
      int deleteOrder1[] = { 5, 15, 11 };
      int deleteOrder2[] = { 11, 2, 20, 1, 17, 16, 14, 15 };
      int deleteOrder3[] = { 15, 14, 17, 16, 11, 2, 20, 19, 18 };
      int deleteOrder4[] = { 18, 17, 15, 19, 27, 11, 20, 12, 22, 14, 13, 10 };
      int deleteOrder5[] = { 33, 34, 25, 35, 36, 38 };
      int deleteOrder6[] = { 0, 1, 6, 8, 9, 3, 2, 4, 7, 5};

      for (int i = 0; i < list1.length; i++) {
         gbs.insert(list1[i],i);
      }

      for (int i = 0; i < deleteOrder1.length; i++) {
         gbs.delete(deleteOrder1[i]);
         assertEquals(null,gbs.get(deleteOrder1[i]));
      }

      reset();

      for (int i = 0; i < list2.length; i++) {
         gbs.insert(list2[i],i);
      }

      for (int i = 0; i < deleteOrder2.length; i++) {
         gbs.delete(deleteOrder2[i]);
         assertEquals(null,gbs.get(deleteOrder2[i]));
      }

      reset();
      
      for (int i = 0; i < list3.length; i++) {
         gbs.insert(list3[i],i);
      }

      for (int i = 0; i < deleteOrder3.length; i++) {
         gbs.delete(deleteOrder3[i]);
         assertEquals(null,gbs.get(deleteOrder3[i]));
      }

      reset();
      
      for (int i = 0; i < list4.length; i++) {
         gbs.insert(list4[i],i);
      }

      for (int i = 0; i < deleteOrder4.length; i++) {
         gbs.delete(deleteOrder4[i]);
         assertEquals(null,gbs.get(deleteOrder4[i]));
      }

      reset();
      
      for (int i = 0; i < list5.length; i++) {
         gbs.insert(list5[i],i);
      }

      for (int i = 0; i < deleteOrder5.length; i++) {
         gbs.delete(deleteOrder5[i]);
         assertEquals(null,gbs.get(deleteOrder5[i]));
      }
      
      reset();
      
      for (int i = 0; i < list6.length; i++) {
         gbs.insert(list6[i],i);
      }

      for (int i = 0; i < deleteOrder6.length; i++) {
         gbs.delete(deleteOrder6[i]);
         assertEquals(null,gbs.get(deleteOrder6[i]));
      }
   }

   @Test
   public void stressTestGenericBinarySearch() {
      Random r = new Random();
      int cycles = 1000000;

      int elements[] = new int[cycles];

      for (int i = 0; i < cycles; i++) {
         elements[i] = Math.abs(r.nextInt());
      }

      for (int i = 0; i < cycles; i++) {
         gbs.insert(elements[i],i);
         assertEquals(i,gbs.get(elements[i]));
      }

      for (int i = 0; i < cycles; i++) {
         gbs.delete(elements[i]);
         assertEquals(null,gbs.get(elements[i]));
      }
   }


   @Test
   public void testAddGenericRedBlack() {
      grb.insert(1,1);
      assertEquals(1,grb.get(1));

      for (int i = 0; i < 10; i++) {
         grb.insert(i,i);
         assertEquals(i,grb.get(i));
      }

      for (int i = -10; i < 0; i++) {
         grb.insert(i,i);
         assertEquals(i,grb.get(i));
      }
   }

   @Test
   public void testAddFixupCasesGenericRedBlack() {
      int addList1[] = { 11, 14, 2, 15, 1, 7, 8, 5, 4 };
      int addList2[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17 };
      int addList3[] = { 11, 5, 15, 17, 19 };
      int addList4[] = { 11, 5, 15, 4, 3, 17, 19, 6, 7, 8, 9, 10 };
      int addList5[] = { 20, 10, 25, 27, 2, 19, 22, 1, 3, 18, 17,
                         16, 15, 14, 13, 12, 11 };

      for (int i = 0; i < addList1.length; i++) {
         grb.insert(addList1[i],i);
      }

      for (int i = 0; i < addList1.length; i++) {
         assertEquals(i,grb.get(addList1[i]));
      }

      reset();
      
      for (int i = 0; i < addList2.length; i++) {
         grb.insert(addList2[i],i);
      }

      for (int i = 0; i < addList2.length; i++) {
         assertEquals(i,grb.get(addList2[i]));
      }

      reset();

      for (int i = 0; i < addList3.length; i++) {
         grb.insert(addList3[i],i);
      }

      for (int i = 0; i < addList3.length; i++) {
         assertEquals(i,grb.get(addList3[i]));
      }

      reset();
      
      for (int i = 0; i < addList4.length; i++) {
         grb.insert(addList4[i],i);
      }

      for (int i = 0; i < addList4.length; i++) {
         assertEquals(i,grb.get(addList4[i]));
      }

      reset();

      for (int i = 0; i < addList5.length; i++) {
         grb.insert(addList5[i],i);
      }

      for (int i = 0; i < addList5.length; i++) {
         assertEquals(i,grb.get(addList5[i]));
      }

      reset();
   }

   @Test
   public void testDeleteGenericRedBlack() {
      for (int i = 0; i < 10; i++) {
         grb.insert(i,i);
      }
      for (int i = -10; i < 0; i++) {
         grb.insert(i,i);
      }
      for (int i = -10; i < 10; i++) {
         grb.delete(i);
         assertEquals(null,grb.get(i));
      }
   }

   @Test
   public void testDeleteFixupCasesGenericRedBlack() {
      int list1[] = { 11, 5, 15 };
      int list2[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17 };
      int list3[] = { 11, 2, 20, 1, 21, 15, 14, 16, 17, 18, 19 };
      int list4[] = { 20, 10, 25, 27, 2, 19, 22, 1, 3, 18, 17, 16,
                      15, 14, 13, 12, 11 };
      int list5[] = { 20, 19, 21, 18, 22, 17, 23, 16, 24, 15, 25, 14,
                      26, 13, 27, 12, 28, 11, 30, 10, 31, 9, 32, 8, 33,
                      7, 34, 6, 35, 5, 36, 4, 37, 3, 38, 2, 39, 1, 40, 0 };
      int list6[] = { 5, 7, 4, 2, 3, 1, 0, 9, 6, 8 };
      int deleteOrder1[] = { 5, 15, 11 };
      int deleteOrder2[] = { 11, 2, 20, 1, 17, 16, 14, 15 };
      int deleteOrder3[] = { 15, 14, 17, 16, 11, 2, 20, 19, 18 };
      int deleteOrder4[] = { 18, 17, 15, 19, 27, 11, 20, 12, 22, 14, 13, 10 };
      int deleteOrder5[] = { 33, 34, 25, 35, 36, 38 };
      int deleteOrder6[] = { 0, 1, 6, 8, 9, 3, 2, 4, 7, 5};

      for (int i = 0; i < list1.length; i++) {
         grb.insert(list1[i],i);
      }

      for (int i = 0; i < deleteOrder1.length; i++) {
         grb.delete(deleteOrder1[i]);
         assertEquals(null,grb.get(deleteOrder1[i]));
      }

      reset();

      for (int i = 0; i < list2.length; i++) {
         grb.insert(list2[i],i);
      }

      for (int i = 0; i < deleteOrder2.length; i++) {
         grb.delete(deleteOrder2[i]);
         assertEquals(null,grb.get(deleteOrder2[i]));
      }

      reset();
      
      for (int i = 0; i < list3.length; i++) {
         grb.insert(list3[i],i);
      }

      for (int i = 0; i < deleteOrder3.length; i++) {
         grb.delete(deleteOrder3[i]);
         assertEquals(null,grb.get(deleteOrder3[i]));
      }

      reset();
      
      for (int i = 0; i < list4.length; i++) {
         grb.insert(list4[i],i);
      }

      for (int i = 0; i < deleteOrder4.length; i++) {
         grb.delete(deleteOrder4[i]);
         assertEquals(null,grb.get(deleteOrder4[i]));
      }

      reset();
      
      for (int i = 0; i < list5.length; i++) {
         grb.insert(list5[i],i);
      }

      for (int i = 0; i < deleteOrder5.length; i++) {
         grb.delete(deleteOrder5[i]);
         assertEquals(null,grb.get(deleteOrder5[i]));
      }
      
      reset();
      
      for (int i = 0; i < list6.length; i++) {
         grb.insert(list6[i],i);
      }

      for (int i = 0; i < deleteOrder6.length; i++) {
         grb.delete(deleteOrder6[i]);
         assertEquals(null,grb.get(deleteOrder6[i]));
      }
   }

   @Test
   public void stressTestGenericRedBlack() {
      Random r = new Random();
      int cycles = 1000000;

      int elements[] = new int[cycles];

      for (int i = 0; i < cycles; i++) {
         elements[i] = Math.abs(r.nextInt());
      }

      for (int i = 0; i < cycles; i++) {
         grb.insert(elements[i],i);
         assertEquals(i,grb.get(elements[i]));
      }

      for (int i = 0; i < cycles; i++) {
         grb.delete(elements[i]);
         assertEquals(null,grb.get(elements[i]));
      }
   }
}
