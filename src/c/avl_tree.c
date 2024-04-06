
#include "avl_tree.h"
#include <stdio.h>
#include <stdlib.h>

void init_avl(struct avl_tree * t) {
   t->size = 0;
   t->root = 0;
}

void ll_rotate(struct avl_node * x, struct avl_tree * t) {
   struct avl_node * y = x->r;
   x->r = y->l;
   if (y->l) {
      y->l->p = x;
   }
   y->p = x->p;
   if (!x->p) {
      t->root = y;
   }
   else if (x == x->p->l) {
      x->p->l = y;
   }
   else if (x == x->p->l) {
      x->p->l = y;
   }
   else x->p->r = y;
   y->l = x;
   x->p = y;
}

void rr_rotate(struct avl_node * y, struct avl_tree * t) {
   struct avl_node * x = y->l;
   y->l = x->r;
   if (x->r) {
      x->r->p = y;
   }
   x->p = y->p;
   if (!y->p) {
      t->root = x;
   }
   else if (y == y->p->l) {
      y->p->l = x;
   }
   else y->p->r = x;
   x->r = y;
   y->p = x;

}

void rl_rotate(struct avl_node * y, struct avl_tree * t) {
   rr_rotate(y,t);
   ll_rotate(y->p->p,t);
}

void lr_rotate(struct avl_node * x, struct avl_tree * t) {
   ll_rotate(x,t);
   rr_rotate(x->p->p,t);
}

void insert_avl(int key, int val, struct avl_tree * t) {
   struct avl_node * z = malloc(sizeof(struct avl_node));
   z->l = z->r = z->p = 0; z->key = key; z->val = val; z->diff = 0;
   if (!t->root) {
      t->root = z;
      return;
   }
   
   /* decend and add node */
   struct avl_node * y, * w, * x = t->root;
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
   { y->l = z; z->p = y; w = y->r; }
   else
   { y->r = z; z->p = y; w = y->l; }

   if (y->diff) {
      y->diff--;
      return;
   }

   if (!y->p && !y->diff) {
      y->diff++;
      return;
   }

   // TODO fixup procedure
}

void in_order_print_helper_avl(struct avl_node * n) {
   if (n) {
      putchar('l');
      in_order_print_helper_avl(n->l);
      printf("<%d:%d> ",n->key,n->diff);
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
