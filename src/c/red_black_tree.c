
#include "red_black_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct rb_node nil = { .key = 0, .val = 0, .l = 0, .r = 0, .p = 0 };

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
   printf("x: %c\n",x->key);
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
