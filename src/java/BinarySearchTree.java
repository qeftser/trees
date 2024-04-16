
public class BinarySearchTree {
   private int size;
   private BSNode root;

   private class BSNode {
      public int key;
      public int val;
      public BSNode l;
      public BSNode r;

      public BSNode(int key, int val) {
         this.key = key;
         this.val = val;
         l = r = null;
      }
   }

   public void insert(int key, int val) {
      BSNode y = null, z = root;
      if (z == null) {
         root = new BSNode(key,val);
         size++;
         return;
      }
      while (z != null) {
         y = z;
         if (key == z.key) {
            z.val = val;
            return;
         }
         if (key < z.key) {
            z = z.l;
         }
         else z = z.r;
      }

      z = new BSNode(key,val);

      if (key < y.key) {
         y.l = z;
      }
      else y.r = z;

      size++;
   }

   public int get(int key) {
      BSNode z = root;
      while (z != null) {
         if (key == z.key) return z.val;
         else if (key < z.key) z = z.l;
         else z = z.r;
      }
      return -1;
   }

   private void transplant(BSNode u, BSNode up, BSNode v) {
      if (up == null) {
         root = v;
      }
      else if (u == up.l) up.l = v;
      else up.r = v;
   }

   public int delete(int key) {
      BSNode zp = null, z = root;
      while (z != null) {
         if (key == z.key) break;
         zp = z;
         if (key < z.key) z = z.l;
         else z = z.r;
      }
      if (z == null) return -1;

      BSNode sp = null, s;
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

   private void inOrderPrintHelper(BSNode n) {
      if (n == null) return;
      System.out.print("l");
      inOrderPrintHelper(n.l);
      System.out.printf("%d ",n.key);
      System.out.print("r");
      inOrderPrintHelper(n.r);
   }

   public void inOrderPrint() {
      inOrderPrintHelper(root);
      System.out.println();
   }
}
