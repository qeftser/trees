
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

void transplant(struct rb_node * old, struct rb_node * new, struct rb_tree * t) {
   if (old->p == &nil) {
      t->root = new;
   }
   else if (old == old->p->l) {
      old->p->l = new;
   }
   else old->p->r = new;
   new->p = old->p;
}

struct rb_node * minimum(struct rb_node * s) {
   while (s->l != &nil) {
      s = s->l;
   }
   return s;
}

struct rb_node * maximum(struct rb_node * s) {
   while (s->r != &nil) {
      s = s->r;
   }
   return s;
}

void delete_fixup_rb(struct rb_node * x, struct rb_tree * t) {
   while (x != t->root && x->color == black) {
      if (x == x->p->l) {
         struct rb_node * w = x->p->r;
         if (w->color == red) {
            w->color = black;
            x->p->color = red;
            left_rotate(x->p,t);
            w = x->p->r;
         }
         if (w->l->color == black && w->r->color == black) {
            w->color = red;
            x = x->p;
         }
         else if (w->r->color == black) {
            w->l->color = black;
            w->color = red;
            rght_rotate(w,t);
            w = x->p->r;
            w->color = x->p->color;
            x->p->color = black;
            w->r->color = black;
            left_rotate(x->p,t);
            x = t->root;
         }
         else if (w->color == black) {
            w->color = w->p->color;
            left_rotate(w->p,t);
            w->r->color = black;
            w->l->color = black;
            if (w->p->p->color == black && w->p->p != &nil) { x = w->p->p; printf("hi2\n"); } // currently incorrect
            else x = w->p;
         }
      }
      else {
         struct rb_node * w = x->p->l;
         if (w->color == red) {
            w->color = black;
            x->p->color = red;
            rght_rotate(x->p,t);
            w = x->p->l;
         }
         if (w->r->color == black && w->l->color == black) {
            w->color = red;
            x = x->p;
         }
         else if (w->l->color == black) {
            w->r->color = black;
            w->color =red;
            left_rotate(w,t);
            w = x->p->l;
            w->color = x->p->color;
            x->p->color = black;
            w->l->color = black;
            rght_rotate(x->p,t);
            x = t->root;
         }
         else if (w->color == black) {
            w->color = w->p->color;
            rght_rotate(w->p,t);
            w->l->color = black;
            w->r->color = black;
            if (w->p->p->color == black && w->p->p != &nil) { x = w->p->p; printf("hi1\n"); } // currently incorrect
            else x = w->p;
         }
      }
   }
   x->color = black;
}

int delete_rb(int key, struct rb_tree * t) {
   struct rb_node * z = t->root;
   while (z != &nil) {
      if (key == z->key) break;
      else if (key < z->key) z = z->l;
      else z = z->r;
   }

   if (z == &nil) return -1;

   struct rb_node * x, * y = z;
   int y_og_color = y->color;
   if (z->l == &nil) {
      x = z->r;
      transplant(z,z->r,t);
   }
   else if (z->r == &nil) {
      x = z->l;
      transplant(z,z->l,t);
   }
   else {
      y = maximum(z->l);
      y_og_color = y->color;
      x = y->l;
      if (y->p == z) x->p = y;
      else {
         transplant(y,y->l,t);
         y->l = z->l;
         y->l->p = y;
      }
      transplant(z,y,t);
      y->r = z->r;
      y->r->p = y;
      y->color = z->color;
   }
   if (y_og_color == black) {
      delete_fixup_rb(x,t);
   }
   return z->val;
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
