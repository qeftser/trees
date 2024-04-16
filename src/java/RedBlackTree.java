
/**
 * Red Black Tree Implimentation
 * @author Caleb Pollock
 */
public class RedBlackTree {
   private int size;
   private RBNode root;
   private RBNode nil;
   private final int red = 1;
   private final int black = 0;

   /**
    * Container for elements in the tree
    */
   private class RBNode {
      public int key;
      public int val;
      public int color;
      public RBNode l;
      public RBNode r;
      public RBNode p;

      public RBNode(int key, int val) {
         this.key = key;
         this.val = val;
         this.color = black;
         this.l = nil;
         this.r = nil;
         this.p = nil;
      }
   }

   public RedBlackTree() {
      size = 0;
      nil = new RBNode(0,0);
      nil.l = nil.r = nil.p = null;
      root = nil;
   }

   /**
    * Perform a left rotation on the given node
    * @param x - the node to left rotate
    */
   private void leftRotate(RBNode x) {
      RBNode y = x.r;
      x.r = y.l;
      if (y.l != nil) {
         y.l.p = x;
      }
      y.p = x.p;
      if (x.p == nil) {
         root = y;
      }
      else if (x == x.p.l) {
         x.p.l = y;
      }
      else x.p.r = y;
      y.l = x;
      x.p = y;
   }

   /**
    * Perform a right rotation on the given node
    * @param x - the node to right rotate
    */
   private void rightRotate(RBNode y) {
      RBNode x = y.l;
      y.l = x.r;
      if (x.r != nil) {
         x.r.p = y;
      }
      x.p = y.p;
      if (y.p == nil) {
         root = x;
      }
      else if (y == y.p.l) {
         y.p.l = x;
      }
      else y.p.r = x;
      x.r = y;
      y.p = x;
   }

   /**
    * Does maintenance on the tree to ensure that
    * the red-black properties are upheld
    * @param z - the node to start from
    */
   private void insertFixup(RBNode z) {
      while (z.p.color == red) {
         if (z.p == z.p.p.l) {
            RBNode y = z.p.p.r;
            if (y.color == red) {
               z.p.color = black;
               y.color = black;
               z.p.p.color = red;
               z = z.p.p;
            }
            else {
               if (z == z.p.r) {
                  z = z.p;
                  leftRotate(z);
               }
               z.p.color = black;
               z.p.p.color = red;
               rightRotate(z.p.p);
            }
         }
         else {
            RBNode y = z.p.p.l;
            if (y.color == red) {
               z.p.color = black;
               y.color = black;
               z.p.p.color = red;
               z = z.p.p;
            }
            else {
               if (z == z.p.l) {
                  z = z.p;
                  rightRotate(z);
               }
               z.p.color = black;
               z.p.p.color = red;
               leftRotate(z.p.p);
            }
         }
      }
      root.color = black;
   }

   /**
    * Add an element to the tree.
    * @param key - the key to add
    * @param val - the value associated with the key
    */
   public void insert(int key, int val) {
      RBNode z = new RBNode(key,val);
      RBNode y = nil;
      RBNode x = root;
      while (x != nil) {
         if (x.key == key) {
            x.val = val; return;
         }
         y = x;
         if (z.key < x.key) {
            x = x.l;
         }
         else x = x.r;
      }
      z.p = y;
      if (y == nil) {
         root = z;
      }
      else if (z.key < y.key) {
         y.l = z;
      }
      else y.r = z;
      z.l = nil;
      z.r = nil;
      z.color = red;
      size++;
      insertFixup(z);
   }

   /**
    * move new node to old node's position, updating 
    * pointers.
    * @param old - old node
    * @param new - new node
    */
   private void transplant(RBNode old, RBNode newv) {
      if (old.p == nil) {
         root = newv;
      }
      else if (old == old.p.l) {
         old.p.l = newv;
      }
      else old.p.r = newv;
      newv.p = old.p;
   }

   /**
    * @param s - the subtree root
    * @return the minimum value in a subtree rooted at s
    */
   private RBNode minimum(RBNode s) {
      while (s.l != nil) {
         s = s.l;
      }
      return s;
   }

   /**
    * @param s - the subtree root
    * @return the maximum value in a subtree rooted at s
    */
   private RBNode maximum(RBNode s) {
      while (s.r != nil) {
         s = s.r;
      }
      return s;
   }

   /**
    * Does maintenance on the tree to ensure that
    * the red-black properties are upheld
    * @param z - the node to start from
    */
   private void deleteFixup(RBNode x) {
      while (x != root && x.color == black) {
         if (x == x.p.l) {
            RBNode w = x.p.r;
            if (w.color == red) {
               w.color = black;
               x.p.color = red;
               leftRotate(x.p);
               w = x.p.r;
            }
            if (w.l.color == black && w.r.color == black) {
               w.color = red;
               x = x.p;
            }
            else {
               if (w.r.color == black) {
                  w.l.color = black;
                  w.color = red;
                  rightRotate(w);
                  w = x.p.r;
               }
               w.color = x.p.color;
               x.p.color = black;
               w.r.color = black;
               leftRotate(x.p);
               x = root;
            }
         }
         else {
            RBNode w = x.p.l;
            if (w.color == red) {
               w.color = black;
               x.p.color = red;
               rightRotate(x.p);
               w = x.p.l;
            }
            if (w.r.color == black && w.l.color == black) {
               w.color = red;
               x = x.p;
            }
            else {
               if (w.l.color == black) {
                  w.r.color = black;
                  w.color = red;
                  leftRotate(w);
                  w = x.p.l;
               }
               w.color = x.p.color;
               x.p.color = black;
               w.l.color = black;
               rightRotate(x.p);
               x = root;
            }
         }
      }
      x.color = black;
   }

   /**
    * delete the node with the associated
    * key if it exists
    * @param key - the key to look for
    * @return the value associated with the key
    *         or -1 if no element is found
    */
   public int delete(int key) {
      RBNode z = root;
      int ret_val = -1;
      while (z != nil) {
         if (key == z.key) break;
         else if (key < z.key) z = z.l;
         else z = z.r;
      }

      if (z == nil) return -1;

      RBNode x, y = z;
      int y_og_color = y.color;
      if (z.l == nil) {
         x = z.r;
         transplant(z,z.r);
      }
      else if (z.r == nil) {
         x = z.l;
         transplant(z,z.l);
      }
      else {
         y = maximum(z.l);
         y_og_color = y.color;
         x = y.l;
         if (y.p == z) x.p = y;
         else {
            transplant(y,y.l);
            y.l = z.l;
            y.l.p = y;
         }
         transplant(z,y);
         y.r = z.r;
         y.r.p = y;
         y.color = z.color;
      }
      if (y_og_color == black) {
         deleteFixup(x);
      }
      size--;
      return z.val;
   }

   /**
    * query the tree for an element
    * @param key - the key to look for
    * @return the value associated with the key
    *         or -1 if no element is found
    */
   public int get(int key) {
      RBNode z = root;
      while (z != nil) {
         if (key == z.key) return z.val;
         else if (key < z.key) z = z.l;
         else z = z.r;
      }
      return -1;
   }

   /**
    * helper method for inOrderPrint
    */
   private void inOrderPrintHelper(RBNode n) {
      if (n == nil) return;
      System.out.print("l");
      inOrderPrintHelper(n.l);
      System.out.printf("%d:%d ",n.color,n.key);
      System.out.print("r");
      inOrderPrintHelper(n.r);
   }

   /**
    * Print the elements as well as left and right decension 
    * markers for the binary search tree.
    */
   public void inOrderPrint() {
      inOrderPrintHelper(root);
      System.out.println();
   }
}

