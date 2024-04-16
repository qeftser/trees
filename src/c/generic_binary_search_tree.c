
#include "generic_binary_search_tree.h"
#include <stdlib.h>
#include <stdio.h>

void init_gbs(int (* compar)(const void *, const void *), void (* release)(void *), void (* release2)(void *), struct gbs_tree * t) {
   t->size = 0;
   t->root = 0;
   t->compar = compar;
   t->release_key = release;
   t->release_val = release2;
}

void insert_gbs(void * key, void * val, struct gbs_tree * t) {
   struct gbs_node * y, * z = t->root;
   if (!z) {
      t->root = malloc(sizeof(struct gbs_node));
      t->root->key = key; t->root->val = val;
      t->root->l = t->root->r = 0;
      t->size++;
      return;
   }
   while (z) {
      y = z;
      if (t->compar(key,z->key) == 0) {
         t->release_key(key);
         t->release_val(z->val);
         z->val = val;
         return;
      }
      if (t->compar(key,z->key) < 0) {
         z = z->l;
      }
      else z = z->r;
   }

   z = malloc(sizeof(struct gbs_node));
   z->key = key; z->val = val;
   z->l = 0; z->r = 0;

   if (t->compar(key,y->key) < 0) {
      y->l = z;
   }
   else y->r = z;

   t->size++;
}

void * get_gbs(void * key, struct gbs_tree * t) {
   struct gbs_node * z = t->root;
   while (z) {
      if (t->compar(key,z->key) == 0) return z->val;
      else if (t->compar(key,z->key) < 0) z = z->l;
      else z = z->r;
   }
   return (void *)-1;
}

void transplant_gbs(struct gbs_node * u, struct gbs_node * up, struct gbs_node * v, struct gbs_tree * t) {
   if (!up) {
      t->root = v;
   }
   else if (u == up->l) up->l = v;
   else up->r = v;
}

void * delete_gbs(void * key, struct gbs_tree * t) {
   struct gbs_node * zp = 0, * z = t->root;
   while (z) {
      if (t->compar(key,z->key) == 0) break;
      zp = z;
      if (t->compar(key,z->key) < 0) z = z->l;
      else z = z->r;
   }
   if (!z) {
      t->release_val(key);
      return (void *)-1;
   }

   struct gbs_node * sp = 0, * s;
   if (z->r && !z->r->l) {
      s = z->r;
      transplant_gbs(z,zp,s,t);
      s->l = z->l;
   }
   else { 
      s = z->l;
      if (s) while(s->r) { sp = s; s = s->r; }
      if (sp) sp->r = s->l;
      transplant_gbs(z,zp,s,t);
      if (s) {
         if (z->l != s) s->l = z->l;
         s->r = z->r;
      }
   }

   void * ret = z->val;
   t->release_key(z->key);
   free(z);
   t->size--;
   return ret;
}

void destroy_helper_gbs(struct gbs_node * n, struct gbs_tree * t) {
   if (n == 0) return;
   destroy_helper_gbs(n->l,t);
   destroy_helper_gbs(n->r,t);
   t->release_key(n->key);
   t->release_val(n->val);
   free(n);
}

/*
void in_order_print_helper_gbs(struct gbs_node * n) {
   if (n == 0) return;
   printf("l");
   in_order_print_helper_gbs(n->l);
   printf("%d ",n->key);
   printf("r");
   in_order_print_helper_gbs(n->r);
}
*/

void destroy_gbs(struct gbs_tree * t) {
   destroy_helper_gbs(t->root,t);
   free(t);
}

/*
void in_order_print_gbs(struct gbs_tree * t) {
   in_order_print_helper_gbs(t->root);
   printf("\n");
}
*/
