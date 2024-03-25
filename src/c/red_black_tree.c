
#include "red_black_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct rb_node nil = { .key = 0, .val = 0, .l = 0, .r = 0, .p = 0 };
const int red   = 1;
const int black = 0;

void init_rb(struct rb_tree * t) {
   t->size = 0; 
   t->root = &nil;
   t->nil = &nil;
}

void left_rotate(struct rb_node * x, struct rb_tree * t) {
   struct rb_node * y = x->r;
   x->r = y->l;
   if (y->l != &nil) {
      y->l->p = x;
   }
   y->p = x->p;
   if (x->p == &nil) {
      t->root = y;
   }
   else if (x == x->p->l) {
      x->p->l = y;
   }
   else x->p->r = y;
   y->l = x;
   x->p = y;
}

void rght_rotate(struct rb_node * y, struct rb_tree * t) {
   struct rb_node * x = y->l;
   y->l = x->r;
   if (x->r != &nil) {
      x->r->p = y;
   }
   x->p = y->p;
   if (y->p== &nil) {
      t->root = x;
   }
   else if (y == y->p->l) {
      y->p->l = x;
   }
   else y->p->r = x;
   x->r = y;
   y->p = x;
}

void rb_insert_fixup(struct rb_node * z, struct rb_tree * t) {
   while (z->p->color == red) {
      if (z->p == z->p->p->l) {
         struct rb_node * y = z->p->p->r;
         if (y->color == red) {
            z->p->color = black;
            y->color = black;
            z->p->p->color = red;
            z = z->p->p;
         }
         else if (z == z->p->r) {
            z = z->p;
            left_rotate(z,t);
            z->p->color = black;
            z->p->p->color = red;
            rght_rotate(z->p->p,t);
         }
         else {
            z->p->p->color = red;
            rght_rotate(z->p->p,t);
            if (z->p->p->l == z->p)
               z->p->p->r->color = red;
            else z->p->p->l->color = red;
         }
      }
      else {
         struct rb_node * y = z->p->p->l;
         if (y->color == red) {
            z->p->color = black;
            y->color = black;
            z->p->p->color = red;
            z = z->p->p;
         }
         else if (z == z->p->l) {
            z = z->p;
            rght_rotate(z,t);
            z->p->color = black;
            z->p->p->color = red;
            left_rotate(z->p->p,t);
         }
         else {
            z->p->p->color = red;
            left_rotate(z->p->p,t);
            if (z->p->p->r == z->p)
               z->p->p->l->color = red;
            else z->p->p->r->color = red;
         }
      }
   }
   t->root->color = black;
}

void insert_rb(int key, int val, struct rb_tree * t) {
   struct rb_node * z = malloc(sizeof(struct rb_node));
   if (!z) { printf("malloc fail\n"); perror(0); exit(1); };
   z->key = key; z->val = val;
   struct rb_node * y = &nil;
   struct rb_node * x = t->root;
   while (x != &nil) {
      y = x;
      if (z->key < x->key) {
         x = x->l;
      }
      else x = x->r;
   }
   z->p = y;
   if (y == &nil) {
      t->root = z;
   }
   else if (z->key < y->key) {
      y->l = z;
   }
   else y->r = z;
   z->l = &nil;
   z->r = &nil;
   z->color = red;
   rb_insert_fixup(z,t);
}

void in_order_print_helper_rb(struct rb_node * n) {
   if (n == &nil) return;
   printf("l");
   in_order_print_helper_rb(n->l);
   printf("%d:%d ",n->color,n->key);
   printf("r");
   in_order_print_helper_rb(n->r);
}

void in_order_print_rb(struct rb_tree * t) {
   in_order_print_helper_rb(t->root);
   printf("\n");
}

void destroy_helper_rb(struct rb_node * n) {
   if (n == &nil) return;
   destroy_helper_rb(n->l);
   destroy_helper_rb(n->r);
   free(n);
}

void destroy_rb(struct rb_tree * t) {
   destroy_helper_rb(t->root);
   free(t);
}
