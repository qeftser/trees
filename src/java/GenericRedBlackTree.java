
/**
 * Red Black Tree Implimentation
 * @author Caleb Pollock
 */
public class GenericRedBlackTree<K extends Comparable<K>, V> {

   private int size;
   private RBNode<K,V> root;
   private RBNode<K,V> nil;
   private final int red = 1;
   private final int black = 0;

   /**
    * Container for elements in the tree
    */
   private class RBNode<K extends Comparable<K>, V> {
      public K key;
      public V val;
      public int color;
      public RBNode<K,V> l;
      public RBNode<K,V> r;
      public RBNode<K,V> p;

      public RBNode(K key, V val) {
         this.key = key;
         this.val = val;
         this.color = black;
      }
   }

   /**
    * Sets the pointers of the passed node to nil
    * @param n - the node to modfiy
    */
   private void setPointersNil(RBNode<K,V> n) {
      n.l = nil; n.r = nil; n.p = nil;
   }

   public GenericRedBlackTree() {
      size = 0;
      nil = new RBNode<K,V>(null,null);
      nil.l = nil.r = nil.p = null;
      root = nil;
   }

   /**
    * Perform a left rotation on the given node
    * @param x - the node to left rotate
    */
   private void leftRotate(RBNode<K,V> x) {
      RBNode<K,V> y = x.r;
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
   private void rightRotate(RBNode<K,V> y) {
      RBNode<K,V> x = y.l;
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
   private void insertFixup(RBNode<K,V> z) {
      while (z.p.color == red) {
         if (z.p == z.p.p.l) {
            RBNode<K,V> y = z.p.p.r;
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
            RBNode<K,V> y = z.p.p.l;
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
   public void insert(K key, V val) {
      RBNode<K,V> z = new RBNode<K,V>(key,val);
      setPointersNil(z);
      RBNode<K,V> y = nil;
      RBNode<K,V> x = root;
      while (x != nil) {
         if (x.key.compareTo(key) == 0) {
            x.val = val; return;
         }
         y = x;
         if (z.key.compareTo(x.key) < 0) {
            x = x.l;
         }
         else x = x.r;
      }
      z.p = y;
      if (y == nil) {
         root = z;
      }
      else if (z.key.compareTo(y.key) < 0) {
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
   private void transplant(RBNode<K,V> old, RBNode<K,V> newv) {
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
   private RBNode<K,V> minimum(RBNode<K,V> s) {
      while (s.l != nil) {
         s = s.l;
      }
      return s;
   }

   /**
    * @param s - the subtree root
    * @return the maximum value in a subtree rooted at s
    */
   private RBNode<K,V> maximum(RBNode<K,V> s) {
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
   private void deleteFixup(RBNode<K,V> x) {
      while (x != root && x.color == black) {
         if (x == x.p.l) {
            RBNode<K,V> w = x.p.r;
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
            RBNode<K,V> w = x.p.l;
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
   public V delete(K key) {
      RBNode<K,V> z = root;
      while (z != nil) {
         if (key.compareTo(z.key) == 0) break;
         else if (key.compareTo(z.key) < 0) z = z.l;
         else z = z.r;
      }

      if (z == nil) return null;

      RBNode<K,V> x, y = z;
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
   public V get(K key) {
      RBNode<K,V> z = root;
      while (z != nil) {
         if (key.compareTo(z.key) == 0) return z.val;
         else if (key.compareTo(z.key) < 0) z = z.l;
         else z = z.r;
      }
      return null;
   }

   /**
    * helper method for inOrderPrint
    */
   private void inOrderPrintHelper(RBNode<K,V> n) {
      if (n == nil) return;
      System.out.print("l");
      inOrderPrintHelper(n.l);
      System.out.printf("%d:%s ",n.color,n.key.toString());
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
