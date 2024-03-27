
#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdio.h>

void init_bs(struct bs_tree * t) {
   t->size = 0;
   t->root = 0;
}

void insert_bs(int key, int val, struct bs_tree * t) {
   struct bs_node * y, * z = t->root;
   if (!z) {
      t->root = malloc(sizeof(struct bs_node));
      t->root->key = key; t->root->val = val;
      t->root->l = t->root->r = 0;
      t->size++;
      return;
   }
   while (z) {
      y = z;
      if (key == z->key) {
         z->val = val;
         return;
      }
      if (key < z->key) {
         z = z->l;
      }
      else z = z->r;
   }

   z = malloc(sizeof(struct bs_node));
   z->key = key; z->val = val;
   z->l = 0; z->r = 0;

   if (key < y->key) {
      y->l = z;
   }
   else y->r = z;

   t->size++;
}

int get_bs(int key, struct bs_tree * t) {
   struct bs_node * z = t->root;
   while (z) {
      if (key == z->key) return z->val;
      else if (key < z->key) z = z->l;
      else z = z->r;
   }
   return -1;
}

void transplant_bs(struct bs_node * u, struct bs_node * up, struct bs_node * v, struct bs_tree * t) {
   if (!up) {
      t->root = v;
   }
   else if (u == up->l) up->l = v;
   else up->r = v;
}

int delete_bs(int key, struct bs_tree * t) {
   struct bs_node * zp = 0, * z = t->root;
   while (z) {
      if (key == z->key) break;
      zp = z;
      if (key < z->key) z = z->l;
      else z = z->r;
   }
   if (!z) return -1;

   struct bs_node * sp = 0, * s;
   if (z->r && !z->r->l) {
      s = z->r;
      transplant_bs(z,zp,s,t);
      s->l = z->l;
   }
   else { 
      s = z->l;
      if (s) while(s->r) { sp = s; s = s->r; }
      if (sp) sp->r = s->l;
      transplant_bs(z,zp,s,t);
      if (s) {
         if (z->l != s) s->l = z->l;
         s->r = z->r;
      }
   }

   int ret = z->val;
   free(z);
   t->size--;
   return ret;
}

void destroy_helper_bs(struct bs_node * n) {
   if (n == 0) return;
   destroy_helper_bs(n->l);
   destroy_helper_bs(n->r);
   free(n);
}

void in_order_print_helper_bs(struct bs_node * n) {
   if (n == 0) return;
   printf("l");
   in_order_print_helper_bs(n->l);
   printf("%d ",n->key);
   printf("r");
   in_order_print_helper_bs(n->r);
}

void destroy_bs(struct bs_tree * t) {
   destroy_helper_bs(t->root);
   free(t);
}

void in_order_print_bs(struct bs_tree * t) {
   in_order_print_helper_bs(t->root);
   printf("\n");
}
