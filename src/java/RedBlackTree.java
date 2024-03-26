
public class RedBlackTree<K extends Comparable<K>, V> implements BinaryTreeInterface<K,V> {

   private int size;
   private int depth; /* this will only really grow - there is not a good way to decrease it */
   private int totalQueries;
   private int totalTraversals;
   private RBNode<K,V> head;
   private RBNode<K,V> nil;

   private class RBNode<K extends Comparable<K>,V> {
      public boolean color; // red is true, black is false
      public K key;
      public V value;
      public RBNode<K,V> parent;
      public RBNode<K,V> right;
      public RBNode<K,V> left;

      RBNode(K key, V value) {
         this.color = true; // start red
         this.key = key;
         this.value = value;
         this.parent = null;
         this.right = null;
         this.left = null;
      }
   }

   RedBlackTree() {
      size = 0;
      depth = 0;
      totalQueries = 0;
      totalTraversals = 0;
      nil = new RBNode<K,V>(null,null);
      nil.color = false;
      head = nil;
   }
           
   public int getSize() {
      return this.size;
   }

   public int getDepth() {
      return this.depth;
   }

   public V get(K key) {
      if (head == nil || key == null) {
         return null;
      }

      RBNode<K,V> currNode = this.head;

      while (currNode != nil) {
         if (currNode.key.equals(key)) {
            return currNode.value;
         }
         else if (currNode.key.compareTo(key) > 0) {
            currNode = currNode.left;
         }
         else currNode = currNode.right;
      }

      return null;
   }

   private void leftRotate(RBNode<K,V> x) {
      RBNode<K,V> y = x.right;
      x.right = y.left;
      if (y.left != nil) {
         y.left.parent = x;
      }
      y.parent = x.parent;
      if (x.parent == nil) {
         head = y;
      }
      else if (x == x.parent.left) {
         x.parent.left = y;
      }
      else x.parent.right = y;
      y.left = x;
      x.parent = y;
   }

   private void rightRotate(RBNode<K,V> y) {
      RBNode<K,V> x = y.left;
      y.left = x.right;
      if (x.right == nil) {
         x.right.parent = y;
      }
      x.parent = y.parent;
      if (y.parent == nil) {
         head = x;
      }
      else if (y == y.parent.left) {
         y.parent.left = x;
      }
      else y.parent.right = x;
      x.right = y;
      y.parent = x;
   }

   private void insertFixup(RBNode<K,V> z) {
      while (z.parent.color) {
         if (z.parent == z.parent.parent.left) {
            RBNode<K,V> y = z.parent.parent.right;
            if (y.color) {
               z.parent.color = false;
               y.color = false;
               z.parent.parent.color = true;
               z = z.parent.parent;
            }
            else {
               if (z == z.parent.right) {
                  z = z.parent;
                  leftRotate(z);
               }
               z.parent.color = false;
               z.parent.parent.color = true;
               rightRotate(z.parent.parent);
            }
         }
         else {
            RBNode<K,V> y = z.parent.parent.left;
            if (y.color) {
               z.parent.color = false;
               y.color = false;
               z.parent.parent.color = true;
               z = z.parent.parent;
            }
            else {
               if (z == z.parent.left) {
                  z = z.parent;
                  rightRotate(z);
               }
               z.parent.color = false;
               z.parent.parent.color = true;
               leftRotate(z.parent.parent);
            }
         }
      }
      head.color = false;
   }

   public void insert(K key, V value) {
      RBNode<K,V> z = new RBNode<K,V>(key,value);
      RBNode<K,V> y = nil;
      RBNode<K,V> x = head;
      int currDepth = 0;
      size++;
      while (x != nil) {
         currDepth++;
         y = x;
         if (z.key.equals(x.key)) {
            x.value = z.value;
            size--;
            return;
         }
         else if (z.key.compareTo(x.key) < 0) {
            x = x.left;
         }
         else x = x.right;
      }
      if (currDepth > depth) depth = currDepth;
      z.parent = y;
      if (y == nil) {
         head = z;
      }
      else if (z.key.compareTo(y.key) < 0) {
         y.left = z;
      }
      else y.right = z;
      z.left = nil;
      z.right = nil;
      z.color = true;
      insertFixup(z);
   }

   private void transplant(RBNode<K,V> u, RBNode<K,V> v) {
      if (u.parent == nil) {
         head = v;
      }
      else if (u == u.parent.left) {
         u.parent.left = v;
      }
      else {
         u.parent.right = v;
      }
      v.parent = u.parent;
   }

   private RBNode<K,V> minimum(RBNode<K,V> from) {
      while (from.left != nil) from = from.left;
      return from;
   }
   
   private RBNode<K,V> maximum(RBNode<K,V> from) {
      while (from.right != nil) from = from.right;
      return from;
   }

   private void deleteFixup(RBNode<K,V> x) {
      while (x.key != head && !x.color) {
         if (x == x.parent.left) {
            RBNode<K,V> w = x.parent.right;
            if (w.color) {
               w.color = false;
               leftRotate(x.parent);
               w = x.parent.right;
            }
            if (!w.left.color && !w.right.color) {
               w.color = true;
               x = x.parent;
            }
            else {
               if (!w.right.color) {
                  w.left.color = false;
                  w.color = false;
                  rightRotate(w);
                  w = x.parent.right;
               }
               w.color = x.parent.color;
               x.parent.color = false;
               w.right.color = false;
               leftRotate(x.parent);
               x = head;
            }
         }
         else {
            RBNode<K,V> w = x.parent.left;
            if (w.color) {
               w.color = false;
               x.parent.color = true;
               rightRotate(x.parent);
               w = x.parent.left;
            }
            if (!w.right.color && !w.left.color) {
               w.color = true;
               x = x.parent;
            }
            else {
               if (!w.left.color) {
                  w.right.color = false;
                  w.color = true;
                  leftRotate(w);
                  w = x.parent.left;
               }
               w.color = x.parent.color;
               x.parent.color = false;
               w.left.color = false;
               rightRotate(x.parent);
               x = head;
            }
         }
      }
      x.color = false;
   }


   public V delete(K key) {
      RBNode<K,V> z = head;
      V ret = null;
      while (z != nil) {
         if (key.equals(z.key)) {
            ret = z.value;
            break;
         }
         else if (z.key.compareTo(key) > 0) {
            z = z.left;
         }
         else z = z.right;
      }
      if (z == nil) return null;
      size--;

      RBNode<K,V> x,y = z;
      boolean yOGColor = y.color;

      if (z.left == nil) {
         x = z.right;
         transplant(z,z.right);
      }
      else if (z.right == nil) {
         x = z.left;
         transplant(z,z.left);
      }
      else {
         y = maximum(z.left);
         yOGColor = y.color;
         x = y.left;
         if (y.parent == z) {
            x.parent = y;
         }
         else {
            transplant(y,y.left);
            y.left = z.left;
            y.left.parent = y;
         }
         transplant(z,y);
         y.right = z.right;
         y.right.parent = y;
         y.color = z.color;
      }
      if (!yOGColor) // is black
         deleteFixup(x);
      return ret;
   }

   private void printInOrderHelper(RBNode<K,V> c) {
      if (c == nil) return;

      System.out.print("l");
      printInOrderHelper(c.left);
      System.out.print(c.color + "<" + c.key.toString() + "," + c.value.toString() + ">" + c.parent.key + " ");
      System.out.print("r");
      printInOrderHelper(c.right);
   }

   public void printInOrder() {
      printInOrderHelper(head);
      System.out.println();
   }

}
