
#include "red_black_tree.h"
#include "binary_search_tree.h"
#include <stdio.h>

#define RESET() destroy_helper_rb(t.root); init_rb(&t)

int main(void) {

   printf("\n======= RED BLACK TREE TESTS =======\n");

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

   init_rb(&t);

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

   printf("=== test delete ===\n");
   
   in_order_print_rb(&t);
   insert_rb(11,1,&t);
   in_order_print_rb(&t);
   insert_rb(5,1,&t);
   in_order_print_rb(&t);
   insert_rb(15,1,&t);
   in_order_print_rb(&t);

   delete_rb(5,&t);
   in_order_print_rb(&t);
   delete_rb(15,&t);
   in_order_print_rb(&t);
   delete_rb(11,&t);
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

   delete_rb(11,&t);
   in_order_print_rb(&t);
   delete_rb(2,&t);
   in_order_print_rb(&t);
   delete_rb(20,&t);
   in_order_print_rb(&t);
   delete_rb(1,&t);
   in_order_print_rb(&t);
   delete_rb(17,&t);
   in_order_print_rb(&t);
   delete_rb(16,&t);
   in_order_print_rb(&t);
   delete_rb(14,&t);
   in_order_print_rb(&t);
   delete_rb(15,&t);
   in_order_print_rb(&t);

   printf("\n\n");

   RESET();
<<<<<<< HEAD:src/c/red_black_test.c
=======

   printf("\n\nThere is no coverage for this case in intro to algorithms\n\n");
>>>>>>> bc180e2 (binary search tree - plugged memory leak):src/c/tree_tests.c

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

   delete_rb(15,&t);
   in_order_print_rb(&t);
   RESET();
   
   printf("\n\n");

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
   insert_rb(18,1,&t);
   in_order_print_rb(&t);
   insert_rb(19,1,&t);
   in_order_print_rb(&t);

   delete_rb(15,&t);
   in_order_print_rb(&t);
   delete_rb(14,&t);
   in_order_print_rb(&t);
   delete_rb(17,&t);
   in_order_print_rb(&t);
   delete_rb(16,&t);
   in_order_print_rb(&t);
   delete_rb(11,&t);
   in_order_print_rb(&t);
   delete_rb(2,&t);
   in_order_print_rb(&t);
   delete_rb(20,&t);
   in_order_print_rb(&t);
   delete_rb(19,&t);
   in_order_print_rb(&t);
   delete_rb(18,&t);
   in_order_print_rb(&t);

   RESET();
   
   printf("\n\n");

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

   delete_rb(18,&t);
   in_order_print_rb(&t);
   delete_rb(17,&t);
   in_order_print_rb(&t);
   delete_rb(15,&t);
   in_order_print_rb(&t);
   delete_rb(19,&t);
   in_order_print_rb(&t);
   delete_rb(27,&t);
   in_order_print_rb(&t);
   delete_rb(11,&t);
   in_order_print_rb(&t);
   delete_rb(20,&t);
   in_order_print_rb(&t);
   delete_rb(12,&t);
   in_order_print_rb(&t);
   delete_rb(22,&t);
   in_order_print_rb(&t);
   delete_rb(14,&t);
   in_order_print_rb(&t);
   delete_rb(13,&t);
   in_order_print_rb(&t);
   delete_rb(10,&t);
   in_order_print_rb(&t);

   RESET();
   
   printf("\n\n");

   in_order_print_rb(&t);
   insert_rb(20,1,&t);
   in_order_print_rb(&t);
   insert_rb(19,1,&t);
   in_order_print_rb(&t);
   insert_rb(21,1,&t);
   in_order_print_rb(&t);
   insert_rb(18,1,&t);
   in_order_print_rb(&t);
   insert_rb(22,1,&t);
   in_order_print_rb(&t);
   insert_rb(17,1,&t);
   in_order_print_rb(&t);
   insert_rb(23,1,&t);
   in_order_print_rb(&t);
   insert_rb(16,1,&t);
   in_order_print_rb(&t);
   insert_rb(24,1,&t);
   in_order_print_rb(&t);
   insert_rb(15,1,&t);
   in_order_print_rb(&t);
   insert_rb(25,1,&t);
   in_order_print_rb(&t);
   insert_rb(14,1,&t);
   in_order_print_rb(&t);
   insert_rb(26,1,&t);
   in_order_print_rb(&t);
   insert_rb(13,1,&t);
   in_order_print_rb(&t);
   insert_rb(27,1,&t);
   in_order_print_rb(&t);
   insert_rb(12,1,&t);
   in_order_print_rb(&t);
   insert_rb(28,1,&t);
   in_order_print_rb(&t);
   insert_rb(11,1,&t);
   in_order_print_rb(&t);
   insert_rb(29,1,&t);
   in_order_print_rb(&t);
   insert_rb(11,1,&t);
   in_order_print_rb(&t);
   insert_rb(30,1,&t);
   in_order_print_rb(&t);
   insert_rb(10,1,&t);
   in_order_print_rb(&t);
   insert_rb(31,1,&t);
   in_order_print_rb(&t);
   insert_rb(9,1,&t);
   in_order_print_rb(&t);
   insert_rb(32,1,&t);
   in_order_print_rb(&t);
   insert_rb(8,1,&t);
   in_order_print_rb(&t);
   insert_rb(33,1,&t);
   in_order_print_rb(&t);
   insert_rb(7,1,&t);
   in_order_print_rb(&t);
   insert_rb(34,1,&t);
   in_order_print_rb(&t);
   insert_rb(6,1,&t);
   in_order_print_rb(&t);
   insert_rb(35,1,&t);
   in_order_print_rb(&t);
   insert_rb(5,1,&t);
   in_order_print_rb(&t);
   insert_rb(36,1,&t);
   in_order_print_rb(&t);
   insert_rb(4,1,&t);
   in_order_print_rb(&t);
   insert_rb(37,1,&t);
   in_order_print_rb(&t);
   insert_rb(3,1,&t);
   in_order_print_rb(&t);
   insert_rb(38,1,&t);
   in_order_print_rb(&t);
   insert_rb(2,1,&t);
   in_order_print_rb(&t);
   insert_rb(39,1,&t);
   in_order_print_rb(&t);
   insert_rb(1,1,&t);
   in_order_print_rb(&t);
   insert_rb(40,1,&t);
   in_order_print_rb(&t);
   insert_rb(0,1,&t);
   in_order_print_rb(&t);

   delete_rb(33,&t);
   in_order_print_rb(&t);
   delete_rb(34,&t);
   in_order_print_rb(&t);
   delete_rb(25,&t);
   in_order_print_rb(&t);
   delete_rb(35,&t);
   in_order_print_rb(&t);
   delete_rb(36,&t);
   in_order_print_rb(&t);
   delete_rb(38,&t);
   in_order_print_rb(&t);

<<<<<<< HEAD:src/c/red_black_test.c
   printf("\n\n");

   RESET();

   insert_rb(5,5,&t);
   insert_rb(7,5,&t);
   insert_rb(4,5,&t);
   insert_rb(2,5,&t);
   insert_rb(3,5,&t);
   insert_rb(1,5,&t);
   insert_rb(0,5,&t);
   insert_rb(9,5,&t);
   insert_rb(6,5,&t);
   insert_rb(8,5,&t);

   delete_rb(0,&t);
   delete_rb(1,&t);
   delete_rb(6,&t);
   delete_rb(8,&t);
   delete_rb(9,&t);
   delete_rb(3,&t);
   delete_rb(2,&t);
   delete_rb(4,&t);
   delete_rb(7,&t);
   in_order_print_rb(&t);
   delete_rb(5,&t);

=======
>>>>>>> bc180e2 (binary search tree - plugged memory leak):src/c/tree_tests.c
   destroy_helper_rb(t.root);

   printf("\n======= TEST BINARY SEARCH TREE =======\n\n");

   struct bs_tree s;
   init_bs(&s);

   printf("=== test insert ===\n");

   in_order_print_bs(&s);
   insert_bs(5,5,&s);
   in_order_print_bs(&s);
   insert_bs(2,4,&s);
   in_order_print_bs(&s);
   insert_bs(4,3,&s);
   in_order_print_bs(&s);
   insert_bs(3,2,&s);
   in_order_print_bs(&s);
   insert_bs(1,1,&s);
   in_order_print_bs(&s);
   insert_bs(7,6,&s);
   in_order_print_bs(&s);
   insert_bs(6,7,&s);
   in_order_print_bs(&s);
   insert_bs(8,8,&s);
   in_order_print_bs(&s);
   insert_bs(9,9,&s);
   in_order_print_bs(&s);
   
   printf("\n\n");

   printf("=== test delete ===\n");

   delete_bs(5,&s);
   in_order_print_bs(&s);
   delete_bs(1,&s);
   in_order_print_bs(&s);
   delete_bs(9,&s);
   in_order_print_bs(&s);
   delete_bs(7,&s);
   in_order_print_bs(&s);
   delete_bs(6,&s);
   in_order_print_bs(&s);
   delete_bs(2,&s);
   in_order_print_bs(&s);
   delete_bs(4,&s);
   in_order_print_bs(&s);
   delete_bs(3,&s);
   in_order_print_bs(&s);
   delete_bs(8,&s);
   in_order_print_bs(&s);

   printf("\n\n");

   insert_bs(10,1,&s);
   insert_bs(5,1,&s);
   insert_bs(3,1,&s);
   insert_bs(4,1,&s);
   insert_bs(1,1,&s);
   insert_bs(2,1,&s);
   insert_bs(0,1,&s);
   insert_bs(7,1,&s);
   insert_bs(9,1,&s);
   insert_bs(8,1,&s);
   insert_bs(6,1,&s);
   insert_bs(15,1,&s);
   insert_bs(13,1,&s);
   insert_bs(12,1,&s);
   insert_bs(11,1,&s);
   insert_bs(18,1,&s);
   insert_bs(20,1,&s);
   insert_bs(19,1,&s);
   insert_bs(17,1,&s);
   insert_bs(16,1,&s);
   in_order_print_bs(&s);

   for (int i = 20; i; i--) {
      delete_bs(i,&s);
      in_order_print_bs(&s);
   }

   printf("\n\n");

   destroy_helper_bs(s.root);

   return 0;
}
