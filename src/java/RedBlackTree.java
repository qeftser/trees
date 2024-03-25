
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
      System.out.println("lr");
      RBNode<K,V> y = x.right;
      x.right = y.left;
      if (x.right != nil) {
         x.right.parent = x;
      }
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

   private void rightRotate(RBNode<K,V> x) {
      System.out.println("rr");
      RBNode<K,V> y = x.left;
      x.left = y.right; 
      if (x.left != nil) {
         x.left.parent = x;
      }
      if (y.right != nil) {
         y.left.parent = x;
      }
      y.parent = x.parent;
      if (x.parent == nil) {
         head = y;
      }
      else if (x == x.parent.right) {
         x.parent.right = y;
      }
      else x.parent.left = y;
      y.right = x; 
      x.parent = y;
   }

   private void addFixup(RBNode<K,V> z) {
      while (z.parent.color) { // is red - nil must be black for this to work
         if (z.parent == z.parent.parent.left) {
         System.out.println("nahhhhhh - 2");
            RBNode<K,V> y = z.parent.parent.right;
            if (y.color) { // is red - now we have red with red child
               System.out.println("asf");
               z.parent.color = false; // we fix by swapping the child colors
               y.color = false;        // of the grandfather to black and the
               z = z.parent.parent;    // grandfather to red. This implies we
               z.color = true;         // already know the grandfather is black
               System.out.println("asffffffffffffff");
            }
            else if (z == z.parent.right) { // somehow we know that this violates condition 4
               z = z.parent;
               leftRotate(z); // rotation introduces another case 4 violation
               z.parent.color = false;
               z.parent.parent.color = true;
               rightRotate(z.parent.parent); // correct introduced violation
            }
            else {
               z = z.parent;
               rightRotate(z.parent);
               z.left.parent = z;
               z.color = false;
               z.right.color = true;
            }
         }
         else {
            if (z.parent == z.parent.parent.right) {
         System.out.println("nahhhhhh - 1");
               RBNode<K,V> y = z.parent.parent.left;
               if (y.color) { // is red
                  System.out.println("asg");
                  z.parent.color = false; // same regardless of side
                  y.color = false;
                  z = z.parent.parent;
                  z.color = true;
                  System.out.println("asggggggggggggg");
               }
               else if (z == z.parent.left) {
                  z = z.parent;
                  rightRotate(z);
                  z.parent.color = false;
                  z.parent.parent.color = true;
                  leftRotate(z.parent.parent);
               }
               else {
                  z = z.parent;
                  leftRotate(z.parent);
                  z.right.parent = z;
                  z.color = false;
                  z.left.color = true;
               }
            }
         }
      }
      head.color = false;
   }

   public void add(K key, V value) {
      RBNode<K,V> z = new RBNode<K,V>(key,value);
      RBNode<K,V> y = nil;
      RBNode<K,V> x = head;
      z.parent = nil;
      int currDepth = 0;
      size++;
      while (x != nil) {
         System.out.println("nah");
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
      z.left = z.right = nil;
      z.color = true;
      addFixup(z);
      System.out.println("sdafsfdsfas");
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

   private void removeFixup(RBNode<K,V> x) {
      System.out.println("hi " + x.key);
      RBNode<K,V> w;
      while (x != head && !x.color) { // x is black
         if (x == x.parent.left) {
            w = x.parent.right;
            if (w.color) { // is red
               w.color = false;
               x.parent.color = true;
               leftRotate(x.parent);
               w.right.parent = w;
               w = x.parent.right;
            }
            if (!w.left.color && !w.right.color) { // both black
               w.color = true;
               x = x.parent;
            }
            else if (!w.right.color) {
               w.left.color = false;
               w.color = true;
               rightRotate(w);
               w = x.parent.right;
               w.color = x.parent.color;
               x.parent.color = false;
               w.right.color = false;
               leftRotate(x.parent);
               x = head;
            }
            else {
               x = w.parent;
               leftRotate(x);
               w.right.parent = w;
               w.left.color = w.right.color = false;
               w.color = true;
               x = x.parent.parent;
            }
         }
         else {
            w = x.parent.left;
            if (w.color) { // is red
               w.color = false;
               x.parent.color = true;
               rightRotate(x.parent);
               w.left.parent = w; 
               w = x.parent.left;
            }
            if (!w.right.color && !w.left.color) { // both black
               w.color = true;
               x = x.parent;
            }
            else if (!w.left.color) {
               w.right.color = false;
               w.color = true;
               leftRotate(w);
               w = x.parent.left;
               w.color = x.parent.color;
               x.parent.color = false;
               w.left.color = false;
               rightRotate(x.parent);
               x = head;
            }
            else {
               x = w.parent;
               rightRotate(x);
               w.left.parent = w;
               w.left.color = w.right.color = false;
               w.color = true;
               x = x.parent.parent;
            }
         }
      }
      x.color = false;
   }

   public V remove(K key) {
      System.out.println("<<< " + key + " >>>");
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
         System.out.println(z.key + " " + z.parent.key);
      }
      else if (z.right == nil) {
         x = z.left;
         transplant(z,z.left);
      }
      else {
         y = minimum(z.right);
         yOGColor = y.color;
         x = y.right;
         if (y.parent == z) {
            x.parent = y;
         }
         else {
            transplant(y,y.right);
            y.right = z.right;
            y.right.parent = y;
         }
         transplant(z,y);
         y.left = z.left;
         y.left.parent = y;
         y.color = z.color;
      }
      printInOrder();
      if (!yOGColor) // is black
         removeFixup(x);
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
