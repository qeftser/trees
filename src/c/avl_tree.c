
#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

/* 
 * Shout out wikipedia!
 * https://en.wikipedia.org/wiki/AVL_tree
 */

void init_avl(struct avl_tree * t) {
   t->size = 0;
   t->root = 0;
}

struct avl_node * ll_rotate(struct avl_node * x, struct avl_node * z) {
   struct avl_node * y = z->l;
   x->r = y;
   if (y) {
      y->p = x;
   }
   z->l = x;
   x->p = z;
   if (z->diff == 0) {
      x->diff = +1;
      z->diff = -1;
   }
   else {
      x->diff = 0;
      z->diff = 0;
   }
   return z;
}

struct avl_node * rr_rotate(struct avl_node * x, struct avl_node * z) {
   struct avl_node * y = z->r;
   x->l = y;
   if (y) {
      y->p = x;
   }
   z->r = x;
   x->p = z;
   if (z->diff == 0) {
      x->diff = -1;
      z->diff = +1;
   }
   else {
      x->diff = 0;
      z->diff = 0;
   }
   return z;
}

struct avl_node * rl_rotate(struct avl_node * x, struct avl_node * z) {
   struct avl_node * y = z->l;
   struct avl_node * t3 = y->r;
   struct avl_node * t2 = y->l;
   z->l = t3;
   if (t3) {
      t3->p = z;
   }
   y->r = z;
   z->p = y;
   x->r = t2;
   if (t2) {
      t2->p = x;
   }
   y->l = x;
   x->p = y;
   if (y->diff == 0) {
      x->diff = 0;
      z->diff = 0;
   }
   else if (y->diff > 0) {
      x->diff = -1;
      z->diff = 0;
   }
   else {
      x->diff = 0;
      z->diff = +1;
   }
   y->diff = 0;
   return y;
}

struct avl_node * lr_rotate(struct avl_node * x, struct avl_node * z) {
   struct avl_node * y = z->r;
   struct avl_node * t3 = y->l;
   struct avl_node * t2 = y->r;
   z->r = t3;
   if (t3) {
      t3->p = z;
   }
   y->l = z;
   z->p = y;
   y->l = t2;
   if (t2) {
      t2->p = x;
   }
   y->r = x;
   x->p = y;
   if (y->diff == 0) {
      x->diff = 0;
      z->diff = 0;
   }
   else if (y->diff < 0) {
      x->diff = +1;
      z->diff = 0;
   }
   else {
      x->diff = 0;
      z->diff = -1;
   }
   y->diff = 0;
   return y;
}

void transplant_avl(struct avl_node * old, struct avl_node * new, struct avl_tree * t) {
   if (new == 0) {
      printf("old: %p\n",old);
      printf("old->p: %p\n",old->p);
      if (old->p)
         printf("old->p->l: %p\n",old->p->l);
      if (old->p == 0) {
         printf("old->p: %p\n",old->p);
         t->root = 0;
      }
      else if (old->p->l == old) {
         printf("old->p: %p\n",old->p);
         old->p->l = 0;
      }
      else old->p->r = 0;
      return;
   }
   if (old->p == 0) {
      t->root = new;
   }
   else if (old == old->p->l) {
      old->p->l = new;
   }
   else old->p->r = new;
   new->p = old->p;
   //new->l = old->l;
   //new->r = old->r;
   new->diff = old->diff;
}

struct avl_node * minimum_avl(struct avl_node * s) {
   while (s->l) {
      s = s->l;
   }
   return s;
}

struct avl_node * maximum_avl(struct avl_node * s) {
   while (s->r) {
      s = s->r;
   }
   return s;
}

void insert_fixup_avl(struct avl_node * z, struct avl_tree * t) {
   struct avl_node * n, * g, * x;
   for (x = z->p; x; x = z->p) {
      if (z == x->r) {
         if (x->diff > 0) {
            g = x->p;
            if (z->diff < 0) {
               n = rl_rotate(x,z);
            }
            else {
               n = ll_rotate(x,z);
            }
         }
         else {
            if (x->diff < 0) {
               x->diff = 0;
               break;
            }
            x->diff = +1;
            z = x;
            continue;
         }
      }
      else {
         if (x->diff < 0) {
            g = x->p;
            if (z->diff > 0) {
               n = lr_rotate(x,z);
            }
            else {
               n = rr_rotate(x,z);
            }
         }
         else {
            if (x->diff > 0) {
               x->diff = 0;
               break;
            }
            x->diff = -1;
            z = x;
            continue;
         }
      }
      n->p = g;
      if (g) {
         if (x == g->l) {
            g->l = n;
         }
         else {
            g->r = n;
         }
      }
      else {
         t->root = n;
      }
      break;
   }
}

void insert_avl(int key, int val, struct avl_tree * t) {
   struct avl_node * z = malloc(sizeof(struct avl_node));
   z->l = z->r = z->p = 0; z->key = key; z->val = val; z->diff = 0;
   if (!t->root) {
      t->root = z;
      return;
   }
   
   /* decend and add node */
   struct avl_node * y, * x = t->root;
   while (x) {
      y = x;
      if (key < x->key) {
         x = y->l;
      }
      else {
         x = y->r;
      }
   }
   if (key < y->key)
   { y->l = z; z->p = y; }
   else
   { y->r = z; z->p = y; }

   if (y->diff) {
      y->diff--;
      return;
   }

   if (!y->p && !y->diff) {
      y->diff++;
      return;
   }
   insert_fixup_avl(z,t);
}

int get_avl(int key, struct avl_tree * t) {
   struct avl_node * z = t->root;
   while (z) {
      if (z->key == key) {
         return z->val;
      }
      else if (z->key > key) {
         z = z->l;
      }
      else z = z->r;
   }
   return -1;
}

void delete_fixup_avl(struct avl_node * n, struct avl_tree * t) {
   struct avl_node * x, * z, * g;
   int b;
   for (x = n->p; x; x = g) {
      g = x->p;
      if (n == x->l) {
         if (x->diff > 0) {
            z = x->r;
            b = z->diff;
            if (b < 0) {
               printf("1\n");
               n = rl_rotate(x,z);
            }
            else {
               printf("2\n");
               n= ll_rotate(x,z);
            }
         }
         else {
            if (x->diff == 0) {
               printf("3\n");
               x->diff = +1;
               break;
            }
            printf("4\n");
            n = x;
            printf("n: %d\n",x->key);
            n->diff = 0;
            continue;
         }
      }
      else {
         if (x->diff < 0) {
            z = x->l;
            b = z->diff;
            if (b > 0) {
               n = lr_rotate(x,z);
               printf("5\n");
            }
            else {
               printf("6\n");
               n = rr_rotate(x,z);
            }
         }
         else {
            if (x->diff == 0) {
               printf("7\n");
               x->diff = -1;
               break;
            }
            printf("8\n");
            n = x;
            n->diff = 0;
            continue;
         }
      }
      n->p = g;
      if (g) {
         if (x == g->l) {
            g->l = n;
         }
         else {
            g->r = n;
         }
      }
      else {
         t->root = n;
      }
      if (b == 0) 
         break;
   }
}

int delete_avl(int key, struct avl_tree * t) {
   struct avl_node * z = t->root;
   int ret_val = -1;
   while (z) {
      if (key == z->key) {
         break;
      }
      else if (key < z->key) {
         z = z->l;
      }
      else z = z->r;
   }

   if (z == 0) return -1;

   struct avl_node * x, * n, * y = z;

   if (z->l == 0) {
      transplant_avl(z,z->r,t);
   }
   else if (z->r == 0) {
      transplant_avl(z,z->l,t);
   }
   else {
      y = maximum_avl(z->l);
      delete_fixup_avl(y,t);
      x = y->l;
      printf("x: %p\n",x);
      if (y->p == z) { if (x) x->p = y; }
      else {
         transplant_avl(y,y->l,t);
         y->l = z->l;
         y->l->p = y;
      }
      transplant_avl(z,y,t);
      y->r = z->r;
      if (y->r) y->r->p = y;
      y->diff = z->diff;
   }
   ret_val = z->val;
   free(z);
   return ret_val;
}

void in_order_print_helper_avl(struct avl_node * n) {
   if (n) {
      putchar('l');
      in_order_print_helper_avl(n->l);
      printf("<%d:%d:%d> ",n->key, (n->p)?n->p->key:0,n->diff);
      putchar('r');
      in_order_print_helper_avl(n->r);
   }
}

void in_order_print_avl(struct avl_tree * t) {
   in_order_print_helper_avl(t->root);
   putchar('\n');
}

void destroy_helper_avl(struct avl_node * n) {
   if (n) {
      destroy_helper_avl(n->l);
      destroy_helper_avl(n->r);
      free(n);
   }
}

void destroy_avl(struct avl_tree * t) {
   destroy_helper_avl(t->root);
   free(t);
}
