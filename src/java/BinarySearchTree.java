
/**
 * An implementation of a generic binary search tree.
 *
 * @param <K> Type to use as key
 * @param <V> Type to store as value
 *
 * @author Caleb Pollock
 */
public class BinarySearchTree<K extends Comparable<K>,V> implements BinaryTreeInterface<K,V> {

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
   }

   BinarySearchTree() {
      size = 0;
      depth = 0;
      totalQueries = 0;
      totalTraversals = 0;
      head = null;
   }

   public int getSize() {
      return this.size;
   }

   public int getDepth() {
      return this.depth;
   }

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
         else if (currNode.key.compareTo(key) > 0) {
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

   public V get(K key) {
      if (head == null || key == null) {
         return null;
      }

      BSTNode<K,V> currNode = this.head;

      while (currNode != null) {
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

   private BSTNode<K,V> getPredecessor(BSTNode<K,V> start) {
      if (start == null || start.left == null) return null;
      BSTNode<K,V> currNode = start.left;
      while (currNode.right != null) {
         currNode = currNode.right;
      }

      return currNode;
   }

   private BSTNode<K,V> getSuccessor(BSTNode<K,V> start) {
      if (start == null || start.right == null) return null;
      BSTNode<K,V> currNode = start.right;
      while (currNode.left != null) {
         currNode = currNode.left;
      }

      return currNode;
   }

   public V remove(K key) {
      if (head == null) {
         return null;
      }

      BSTNode<K,V> toRemove = head;
      while (toRemove != null) {
         if (toRemove.key.equals(key)) {
            break;
         }
         else if (toRemove.key.compareTo(key) > 0) {
            toRemove = toRemove.left;
         }
         else {
            toRemove = toRemove.right;
         }
      }
      
      if (toRemove == null) {
         return null;
      }

      BSTNode<K,V> replace = getSuccessor(toRemove);
      if (replace == null) replace = getPredecessor(toRemove);
      if (replace == null) {
         if (head == toRemove) {
            head = null;
         }
         else if (toRemove.parent.left == toRemove) {
            if (toRemove.parent.key == head.key) {
              head.left = null;
            }
            else {
               toRemove.parent.left = null;
            }
         }
         else {
            if (toRemove.parent.key == head.key) {
               head.right = null;
            }
            else {
               toRemove.parent.right = null;
            }
         }
         size--;
         return toRemove.value;
      }

      V retVal = toRemove.value;

      if (replace.parent.left == replace) {
         if (replace.right == null) {
            if (replace.parent.key == head.key) {
               toRemove.value = replace.value;
               toRemove.key = replace.key;
               head.left = replace.left;
            }
            else {
               toRemove.value = replace.value;
               toRemove.key = replace.key;
               replace.parent.left = replace.left;
            }
         }
         else {
            toRemove.value = replace.value;
            toRemove.key = replace.key;
            replace.parent.left = replace.right;
         }
      }
      else {
         if (replace.left == null) {
            if (replace.parent.key == head.key) {
               toRemove.value = replace.value;
               toRemove.key = replace.key;
               head.right = replace.right;
            }
            else {
               toRemove.value = replace.value;
               toRemove.key = replace.key;
               replace.parent.right = replace.right;
            }
         }
         else {
            toRemove.value = replace.value;
            toRemove.key = replace.key;
            replace.parent.right = replace.left;
         }
      }
      
      size--;
      return retVal;
   }

   private void printInOrderHelper(BSTNode<K,V> c) {
      if (c == null) return;

      printInOrderHelper(c.left);
      System.out.print("<" + c.key.toString() + "," + c.value.toString() + "> ");
      printInOrderHelper(c.right);
   }

   public void printInOrder() {
      printInOrderHelper(head);
      System.out.println();
   }

}
