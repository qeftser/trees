
/**
 * An implementation of a generic binary search tree.
 *
 * @param <K> Type to use as key
 * @param <V> Type to store as value
 *
 * @author Caleb Pollock
 */
public class BinarySearchTree<K extends Comparable<K>,V> {

   private int size;
   private int depth; /* this will only really grow - there is not a good way to decrease it */
   private int totalQueries;
   private int totalTraversals;
   private BSTNode<K,V> head;

   private class BSTNode<K extends Comparable<K>,V> {
      public K key;
      public V value;
      public BSTNode<K,V> parent;
      public BSTNode<K,V> right;
      public BSTNode<K,V> left;

      BSTNode(K key,V value) {
         this.key = key;
         this.value = value;
         parent = null;
         right = null;
         left = null;
      }

      BSTNode(K key) {
         this.key = key;
         this.value = null;
         parent = null;
         right = null;
         left = null;
      }

      BSTNode() {
         this.key = null;
         this.value = null;
         parent = null;
         right = null;
         left = null;
      }
   }

   BinarySearchTree() {
      size = 0;
      depth = 0;
      totalQueries = 0;
      totalTraversals = 0;
      head = null;
   }

   /**
    * @return int - total elements in tree
    */
   public int getSize() {
      return this.size;
   }

   /**
    * @return int - the highest depth the tree has reached
    * @note May not return the current depth of the tree.
    */
   public int getDepth() {
      return this.depth;
   }

   /**
    * Adds the given value to the tree under the given key.
    * If the given key already exists the value held is
    * updated
    * @param key - the key to store the value under
    * @param value - the value to store
    */
   public void add(K key, V value) {
      BSTNode<K,V> newNode = new BSTNode<K,V>(key,value);
      int currDepth = 0;
      BSTNode<K,V> currNode = this.head;
      this.size++;

      if (currNode == null) {
         head = newNode;
         return;
      }

      while (true) {
         if (currNode.key.equals(key)) {
            currNode.value = value;
            size--;
            return;
         }
         else if (currNode.key.compareTo(key) < 0) {
            if (currNode.left == null) {
               currNode.left = newNode;
               newNode.parent = currNode;
               if (++currDepth > depth) depth = currDepth;
               return;
            }
            currNode = currNode.left;
            currDepth++;
         }
         else {
            if (currNode.right == null) {
               currNode.right = newNode;
               newNode.parent = currNode;
               if (++currDepth > depth) depth = currDepth;
               return;
            }
            currNode = currNode.right;
            currDepth++;
         }
      }
   }

   /**
    * @return The value associated with the given key, or null if the key is not found
    * @param key - the key to search for
    */
   public V get(K key) {
      if (head == null || key == null) {
         return null;
      }

      BSTNode<K,V> currNode = this.head;

      while (currNode != null) {
         if (currNode.key.equals(key)) {
            return currNode.value;
         }
         else if (currNode.key.compareTo(key) < 0) {
            currNode = currNode.left;
         }
         else currNode = currNode.right;
      }

      return null;
   }

   /**
    * @return the node that is the predecessor to the given node
    * @param start - the node to search from
    */
   private BSTNode<K,V> getPredecessor(BSTNode<K,V> start) {
      if (start == null || start.left == null) return null;
      BSTNode<K,V> currNode = start.left;
      while (currNode.right != null) {
         currNode = currNode.right;
      }

      return currNode;
   }

   /**
    * @return the node that is the successor to the given node
    * @param start - the node to search from
    */
   private BSTNode<K,V> getSuccessor(BSTNode<K,V> start) {
      if (start == null || start.right == null) return null;
      BSTNode<K,V> currNode = start.right;
      while (currNode.left != null) {
         currNode = currNode.left;
      }

      return currNode;
   }

   /**
    * Removes the node under the given key from the tree
    * @param key - the key to search for
    * @return the value of the node removed, or null if the given key was not present in the tree
    */
   public V remove(K key) {
      if (head == null) {
         return null;
      }
      BSTNode<K,V> toRemove = head;
      while (toRemove != null) {
         if (toRemove.key.equals(key)) {
            break;
         }
         else if (toRemove.key.compareTo(key) < 0) {
            toRemove = toRemove.left;
         }
         else toRemove = toRemove.right;
      }

      if (toRemove == null) {
         return null;
      }

      size--;

      BSTNode<K,V> replacement = getPredecessor(toRemove);
      if (replacement == null) {
         replacement = getSuccessor(toRemove);
         if (replacement == null) {
            if (toRemove == head) {
               head = null;
            }
            else if (toRemove.parent.left == toRemove) {
               toRemove.parent.left = null;
            }
            else {
               toRemove.parent.right = null;
            }
            return toRemove.value;
         }
      }

      V oldValue = toRemove.value;
      toRemove.value = replacement.value;
      toRemove.key = replacement.key;

      if (replacement.parent.right == replacement) {
         if (replacement.left == null) {
            replacement.parent.right = replacement.right;
         }
         else replacement.parent.right = replacement.left;
      }
      else {
         if (replacement.right == null) {
            replacement.parent.left = replacement.left;
         }
         else replacement.parent.left = replacement.right;
      }
      return oldValue;
   }

}
