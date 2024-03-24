
public interface BinaryTreeInterface<K,V> {
   /**
    * @return int - total elements in tree
    */
   public int getSize(); 

   /**
    * @return int - the highest depth the tree has reached
    * @note May not return the current depth of the tree.
    */
   public int getDepth();

   /**
    * Adds the given value to the tree under the given key.
    * If the given key already exists the value held is
    * updated
    * @param key - the key to store the value under
    * @param value - the value to store
    */
   public void add(K key, V value);
   
   /**
    * @return The value associated with the given key, or null if the key is not found
    * @param key - the key to search for
    */
   public V get(K key);
   
   /**
    * Removes the node under the given key from the tree
    * @param key - the key to search for
    * @return the value of the node removed, or null if the given key was not present in the tree
    */
   public V remove(K key);
   
   /**
    * Print the contents of the binary search tree
    * in the order of the key values
    */
   public void printInOrder();
}
