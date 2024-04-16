
/**
 * Binary search tree data structure
 * @author Caleb Pollock
 */
public class GenericBinarySearchTree<K extends Comparable<K>, V> {
   private int size;
   private BSNode<K,V> root;

   /**
    * Container nodes for the tree
    */
   private class BSNode<K extends Comparable<K>, V> {
      public K key;
      public V val;
      public BSNode<K,V> l;
      public BSNode<K,V> r;

      public BSNode(K key, V val) {
         this.key = key;
         this.val = val;
         l = r = null;
      }
   }

   /**
    * Add an element to the tree.
    * @param key - the key to add
    * @param val - the value associated with the key
    */
   public void insert(K key, V val) {
      BSNode<K,V> y = null, z = root;
      if (z == null) {
         root = new BSNode<K,V>(key,val);
         size++;
         return;
      }
      while (z != null) {
         y = z;
         if (key.compareTo(z.key) == 0) {
            z.val = val;
            return;
         }
         if (key.compareTo(z.key) < 0) {
            z = z.l;
         }
         else z = z.r;
      }

      z = new BSNode<K,V>(key,val);

      if (key.compareTo(y.key) < 0) {
         y.l = z;
      }
      else y.r = z;

      size++;
   }

   /**
    * query the tree for an element
    * @param key - the key to look for
    * @return the value associated with the key
    *         or null if no element is found
    */
   public V get(K key) {
      BSNode<K,V> z = root;
      while (z != null) {
         if (key.compareTo(z.key) == 0) return z.val;
         else if (key.compareTo(z.key) < 0) z = z.l;
         else z = z.r;
      }
      return null;
   }

   /**
    * move new node to old node's position, updating 
    * pointers.
    * @param u - old node
    * @param up - old node parent
    * @param v - new node
    */
   private void transplant(BSNode<K,V> u, BSNode<K,V> up, BSNode<K,V> v) {
      if (up == null) {
         root = v;
      }
      else if (u == up.l) up.l = v;
      else up.r = v;
   }

   /**
    * delete the node with the associated
    * key if it exists
    * @param key - the key to look for
    * @return the value associated with the key
    *         or null if no element is found
    */
   public V delete(K key) {
      BSNode<K,V> zp = null, z = root;
      while (z != null) {
         if (key.compareTo(z.key) == 0) break;
         zp = z;
         if (key.compareTo(z.key) < 0) z = z.l;
         else z = z.r;
      }
      if (z == null) return null;

      BSNode<K,V> sp = null, s;
      if (z.r != null && z.r.l == null) {
         s = z.r;
         transplant(z,zp,s);
         s.l = z.l;
      }
      else {
         s = z.l;
         if (s != null) while(s.r != null) { sp = s; s = s.r; }
         if (sp != null) sp.r = s.l;
         transplant(z,zp,s);
         if (s != null) {
            if (z.l != s) s.l = z.l;
            s.r = z.r;
         }
      }

      size--;
      return z.val;
   }

   /**
    * helper method for inOrderPrint
    */
   private void inOrderPrintHelper(BSNode<K,V> n) {
      if (n == null) return;
      System.out.print("l");
      inOrderPrintHelper(n.l);
      System.out.print(n.key.toString() + " ");
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
