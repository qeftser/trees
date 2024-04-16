
public class RedBlackTree {
   private int size;
   private RBNode root;
   private RBNode nil;
   private final int red = 1;
   private final int black = 0;

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

   public void insert(int key, int val) {
      RBNode z = new RBNode(key,val);
      RBNode y = nil;
      RBNode x = root;
      while (x != nil) {
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
      insertFixup(z);
   }

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

   private RBNode minimum(RBNode s) {
      while (s.l != nil) {
         s = s.l;
      }
      return s;
   }

   private RBNode maximum(RBNode s) {
      while (s.r != nil) {
         s = s.r;
      }
      return s;
   }

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
      ret_val = z.val;
      return ret_val;
   }

   public int get(int key) {
      RBNode z = root;
      while (z != nil) {
         if (key == z.key) return z.val;
         else if (key < z.key) z = z.l;
         else z = z.r;
      }
      return -1;
   }

   private void inOrderPrintHelper(RBNode n) {
      if (n == nil) return;
      System.out.print("l");
      inOrderPrintHelper(n.l);
      System.out.printf("%d:%d ",n.color,n.key);
      System.out.print("r");
      inOrderPrintHelper(n.r);
   }

   public void inOrderPrint() {
      inOrderPrintHelper(root);
      System.out.println();
   }

   
}

