
#include "generic_red_black_tree.h"
#include <stdio.h>
#include <stdlib.h>

struct grb_node gnil = { .key = 0, .val = 0, .l = 0, .r = 0, .p = 0 };
const int gred   = 1;
const int gblack = 0;

void init_grb(int (* compar)(const void *, const void *), void (* r1)(void *), void (* r2)(void *), struct grb_tree * t) {
   t->size = 0; 
   t->root = &gnil;
   t->nil = &gnil;
   t->compar = compar;
   t->release_key = r1;
   t->release_val = r2;
}

void left_rotate_grb(struct grb_node * x, struct grb_tree * t) {
   struct grb_node * y = x->r;
   x->r = y->l;
   if (y->l != &gnil) {
      y->l->p = x;
   }
   y->p = x->p;
   if (x->p == &gnil) {
      t->root = y;
   }
   else if (x == x->p->l) {
      x->p->l = y;
   }
   else x->p->r = y;
   y->l = x;
   x->p = y;
}

void rght_rotate_grb(struct grb_node * y, struct grb_tree * t) {
   struct grb_node * x = y->l;
   y->l = x->r;
   if (x->r != &gnil) {
      x->r->p = y;
   }
   x->p = y->p;
   if (y->p== &gnil) {
      t->root = x;
   }
   else if (y == y->p->l) {
      y->p->l = x;
   }
   else y->p->r = x;
   x->r = y;
   y->p = x;
}

void grb_insert_fixup(struct grb_node * z, struct grb_tree * t) {
   while (z->p->color == gred) {
      if (z->p == z->p->p->l) {
         struct grb_node * y = z->p->p->r;
         if (y->color == gred) {
            z->p->color = gblack;
            y->color = gblack;
            z->p->p->color = gred;
            z = z->p->p;
         }
         else {
            if (z == z->p->r) {
               z = z->p;
               left_rotate_grb(z,t);
            }
            z->p->color = gblack;
            z->p->p->color = gred;
            rght_rotate_grb(z->p->p,t);
         }
      }
      else {
         struct grb_node * y = z->p->p->l;
         if (y->color == gred) {
            z->p->color = gblack;
            y->color = gblack;
            z->p->p->color = gred;
            z = z->p->p;
         }
         else {
            if (z == z->p->l) {
               z = z->p;
               rght_rotate_grb(z,t);
            }
            z->p->color = gblack;
            z->p->p->color = gred;
            left_rotate_grb(z->p->p,t);
         }
      }
   }
   t->root->color = gblack;
}

void insert_grb(void * key, void * val, struct grb_tree * t) {
   struct grb_node * y = &gnil;
   struct grb_node * x = t->root;
   while (x != &gnil) {
      if (t->compar(x->key,key) == 0) {
         t->release_key(key);
         t->release_val(x->val);
         x->val = val;
         return;
      }
      y = x;
      if (t->compar(key,x->key) < 0) {
         x = x->l;
      }
      else x = x->r;
   }

   struct grb_node * z = malloc(sizeof(struct grb_node));
   if (!z) { printf("malloc fail\n"); perror(0); exit(1); };
   z->key = key; z->val = val;
   z->p = y;
   if (y == &gnil) {
      t->root = z;
   }
   else if (t->compar(z->key,y->key) < 0) {
      y->l = z;
   }
   else y->r = z;
   z->l = &gnil;
   z->r = &gnil;
   z->color = gred;
   t->size++;
   grb_insert_fixup(z,t);
}

void transplant_grb(struct grb_node * old, struct grb_node * new, struct grb_tree * t) {
   if (old->p == &gnil) {
      t->root = new;
   }
   else if (old == old->p->l) {
      old->p->l = new;
   }
   else old->p->r = new;
   new->p = old->p;
}

struct grb_node * minimum_grb(struct grb_node * s) {
   while (s->l != &gnil) {
      s = s->l;
   }
   return s;
}

struct grb_node * maximum_grb(struct grb_node * s) {
   while (s->r != &gnil) {
      s = s->r;
   }
   return s;
}

void delete_fixup_grb(struct grb_node * x, struct grb_tree * t) {
   while (x != t->root && x->color == gblack) {
      if (x == x->p->l) {
         struct grb_node * w = x->p->r;
         if (w->color == gred) {
            w->color = gblack;
            x->p->color = gred;
            left_rotate_grb(x->p,t);
            w = x->p->r;
         }
         if (w->l->color == gblack && w->r->color == gblack) {
            w->color = gred;
            x = x->p;
         }
         else {
            if (w->r->color == gblack) {
               w->l->color = gblack;
               w->color = gred;
               rght_rotate_grb(w,t);
               w = x->p->r;
            }
            w->color = x->p->color;
            x->p->color = gblack;
            w->r->color = gblack;
            left_rotate_grb(x->p,t);
            x = t->root;
         }
      }
      else {
         struct grb_node * w = x->p->l;
         if (w->color == gred) {
            w->color = gblack;
            x->p->color = gred;
            rght_rotate_grb(x->p,t);
            w = x->p->l;
         }
         if (w->r->color == gblack && w->l->color == gblack) {
            w->color = gred;
            x = x->p;
         }
         else {
            if (w->l->color == gblack) {
               w->r->color = gblack;
               w->color = gred;
               left_rotate_grb(w,t);
               w = x->p->l;
            }
            w->color = x->p->color;
            x->p->color = gblack;
            w->l->color = gblack;
            rght_rotate_grb(x->p,t);
            x = t->root;
         }
      }
   }
   x->color = gblack;
}

void * delete_grb(void * key, struct grb_tree * t) {
   struct grb_node * z = t->root;
   void * ret_val = (void *)-1;
   while (z != &gnil) {
      if (t->compar(key,z->key) == 0) break;
      else if (t->compar(key,z->key) < 0) z = z->l;
      else z = z->r;
   }

   if (z == &gnil) {
      t->release_key(key);
      return (void *)-1;
   }

   struct grb_node * x, * y = z;
   int y_og_color = y->color;
   if (z->l == &gnil) {
      x = z->r;
      transplant_grb(z,z->r,t);
   }
   else if (z->r == &gnil) {
      x = z->l;
      transplant_grb(z,z->l,t);
   }
   else {
      y = maximum_grb(z->l);
      y_og_color = y->color;
      x = y->l;
      if (y->p == z) x->p = y;
      else {
         transplant_grb(y,y->l,t);
         y->l = z->l;
         y->l->p = y;
      }
      transplant_grb(z,y,t);
      y->r = z->r;
      y->r->p = y;
      y->color = z->color;
   }
   if (y_og_color == gblack) {
      delete_fixup_grb(x,t);
   }
   ret_val = z->val;
   t->release_key(z->key);
   free(z);
   t->size--;
   return ret_val;
}

void * get_grb(void * key, struct grb_tree * t) {
   struct grb_node * z = t->root;
   while (z != &gnil) {
      if (t->compar(key,z->key) == 0) return z->val;
      else if (t->compar(key,z->key) < 0) z = z->l;
      else z = z->r;
   }
   return (void *)-1;
}

/*
void in_order_print_helper_grb(struct rb_node * n) {
   if (n == &gnil) return;
   printf("l");
   in_order_print_helper_grb(n->l);
   printf("%d:%d ",n->color,n->key);
   printf("r");
   in_order_print_helper_grb(n->r);
}

void in_order_print_grb(struct rb_tree * t) {
   in_order_print_helper_grb(t->root);
   printf("\n");
}
*/

void destroy_helper_grb(struct grb_node * n, struct grb_tree * t) {
   if (n == &gnil) return;
   destroy_helper_grb(n->l,t);
   destroy_helper_grb(n->r,t);
   t->release_key(n->key);
   t->release_val(n->val);
   free(n);
}

void destroy_grb(struct grb_tree * t) {
   destroy_helper_grb(t->root,t);
   free(t);
}
