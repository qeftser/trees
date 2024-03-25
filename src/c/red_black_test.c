
#include "red_black_tree.h"
#include <stdio.h>

#define RESET() destroy_helper_rb(t.root); init_rb(&t)

int main(void) {

   struct rb_tree t;
   init_rb(&t);

   struct rb_node a = {.key = 97, .val = 0, .l = t.nil, .r = t.nil };
   struct rb_node b = {.key = 98, .val = 1, .l = t.nil, .r = t.nil };
   struct rb_node c = {.key = 99, .val = 2, .l = t.nil, .r = t.nil };
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

   RESET();

   printf("=== test insert ===\n");
   in_order_print_rb(&t);
   insert_rb(11,1,&t);
   in_order_print_rb(&t);
   insert_rb(14,1,&t);
   in_order_print_rb(&t);
   insert_rb(2,1,&t);
   in_order_print_rb(&t);
   insert_rb(15,1,&t);
   in_order_print_rb(&t);
   insert_rb(1,1,&t);
   in_order_print_rb(&t);
   insert_rb(7,1,&t);
   in_order_print_rb(&t);
   insert_rb(8,1,&t);
   in_order_print_rb(&t);
   insert_rb(5,1,&t);
   in_order_print_rb(&t);
   insert_rb(4,1,&t);
   in_order_print_rb(&t);

   printf("\n\n");

   RESET();

   in_order_print_rb(&t);
   insert_rb(11,1,&t);
   in_order_print_rb(&t);
   insert_rb(2,1,&t);
   in_order_print_rb(&t);
   insert_rb(20,1,&t);
   in_order_print_rb(&t);
   insert_rb(1,1,&t);
   in_order_print_rb(&t);
   insert_rb(21,1,&t);
   in_order_print_rb(&t);
   insert_rb(15,1,&t);
   in_order_print_rb(&t);
   insert_rb(14,1,&t);
   in_order_print_rb(&t);
   insert_rb(16,1,&t);
   in_order_print_rb(&t);
   insert_rb(17,1,&t);
   in_order_print_rb(&t);

   printf("\n\n");

   RESET();

   in_order_print_rb(&t);
   insert_rb(11,1,&t);
   in_order_print_rb(&t);
   insert_rb(5,1,&t);
   in_order_print_rb(&t);
   insert_rb(15,1,&t);
   in_order_print_rb(&t);
   insert_rb(17,1,&t);
   in_order_print_rb(&t);
   insert_rb(19,1,&t);
   in_order_print_rb(&t);

   printf("\n\n");

   RESET();

   in_order_print_rb(&t);
   insert_rb(11,1,&t);
   in_order_print_rb(&t);
   insert_rb(5,1,&t);
   in_order_print_rb(&t);
   insert_rb(15,1,&t);
   in_order_print_rb(&t);
   insert_rb(4,1,&t);
   in_order_print_rb(&t);
   insert_rb(3,1,&t);
   in_order_print_rb(&t);
   insert_rb(17,1,&t);
   in_order_print_rb(&t);
   insert_rb(19,1,&t);
   in_order_print_rb(&t);
   insert_rb(6,1,&t);
   in_order_print_rb(&t);
   insert_rb(7,1,&t);
   in_order_print_rb(&t);
   insert_rb(8,1,&t);
   in_order_print_rb(&t);
   insert_rb(9,1,&t);
   in_order_print_rb(&t);
   insert_rb(10,1,&t);
   in_order_print_rb(&t);

   printf("\n\n");

   RESET();

   in_order_print_rb(&t);
   insert_rb(20,1,&t);
   in_order_print_rb(&t);
   insert_rb(10,1,&t);
   in_order_print_rb(&t);
   insert_rb(25,1,&t);
   in_order_print_rb(&t);
   insert_rb(27,1,&t);
   in_order_print_rb(&t);
   insert_rb(2,1,&t);
   in_order_print_rb(&t);
   insert_rb(19,1,&t);
   in_order_print_rb(&t);
   insert_rb(22,1,&t);
   in_order_print_rb(&t);
   insert_rb(1,1,&t);
   in_order_print_rb(&t);
   insert_rb(3,1,&t);
   in_order_print_rb(&t);
   insert_rb(18,1,&t);
   in_order_print_rb(&t);
   insert_rb(17,1,&t);
   in_order_print_rb(&t);
   insert_rb(16,1,&t);
   in_order_print_rb(&t);
   insert_rb(15,1,&t);
   in_order_print_rb(&t);
   insert_rb(14,1,&t);
   in_order_print_rb(&t);
   insert_rb(13,1,&t);
   in_order_print_rb(&t);
   insert_rb(12,1,&t);
   in_order_print_rb(&t);
   insert_rb(11,1,&t);
   in_order_print_rb(&t);

   printf("\nyes all of this was manually verified xD\n");
   printf("\n\n");

   RESET();



   destroy_rb(&t);
   return 0;
}
