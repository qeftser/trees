
#include "red_black_tree.h"
#include <stdio.h>

int main(void) {

   struct rb_tree t;
   init_rb(&t);

   struct rb_node a = {.key = 97, .val = 0 };
   struct rb_node b = {.key = 98, .val = 1 };
   struct rb_node c = {.key = 99, .val = 2 };
   struct rb_node y = {.key = 121, .val = 4, .l = &b, .r = &c };
   struct rb_node x = {.key = 120, .val = 3, .p = t.nil, .l = &a, .r = &y };
   y.p = &x; a.p = &x; b.p = &y; c.p = &y;

   printf("=== test left_rotate ===\n");
   printf("xl: %c  xr: %c  yl: %c yr = %c\n",x.l->key,x.r->key,y.l->key,y.r->key);
   printf("ap: %c  bp: %c  cp: %c\n",a.p->key,b.p->key,c.p->key);
   printf("rotating...\n");
   left_rotate(&x,&t);
   printf("xl: %c  xr: %c  yl: %c yr = %c\n",x.l->key,x.r->key,y.l->key,y.r->key);
   printf("ap: %c  bp: %c  cp: %c\n",a.p->key,b.p->key,c.p->key);

   printf("\n");

   printf("=== test rght_rotate ===\n");
   printf("xl: %c  xr: %c  yl: %c yr = %c\n",x.l->key,x.r->key,y.l->key,y.r->key);
   printf("ap: %c  bp: %c  cp: %c\n",a.p->key,b.p->key,c.p->key);
   printf("rotating...\n");
   rght_rotate(&y,&t);
   printf("xl: %c  xr: %c  yl: %c yr = %c\n",x.l->key,x.r->key,y.l->key,y.r->key);
   printf("ap: %c  bp: %c  cp: %c\n",a.p->key,b.p->key,c.p->key);

   printf("nice nice\n\n");

   return 0;
}
