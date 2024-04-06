
#include "red_black_tree.h"
#include "binary_search_tree.h"
#include "avl_tree.h"
#include <stdio.h>

#define RESET() destroy_helper_rb(t.root); init_rb(&t)


#define TEST(name,condition) \
   printf("TEST %02x: [ %-30s ] ",tests++,name); \
   res = condition; \
   if (res) printf("\033[32mPASSED\033[0m\n"); \
   else printf("\033[31mFAILED\033[0m\n")



int main(void) {
   int tests = 0;
   int res = 0;

   printf("\n======= RED BLACK TREE TESTS =======\n\n");

   struct rb_tree t;
   init_rb(&t);

   struct rb_node a = {.key = 97, .val = 0, .l = t.nil, .r = t.nil };
   struct rb_node b = {.key = 98, .val = 1, .l = t.nil, .r = t.nil };
   struct rb_node c = {.key = 99, .val = 2, .l = t.nil, .r = t.nil };
   struct rb_node y = {.key = 121, .val = 4, .l = &b, .r = &c };
   struct rb_node x = {.key = 120, .val = 3, .p = t.nil, .l = &a, .r = &y };
   y.p = &x; a.p = &x; b.p = &y; c.p = &y;

   /*
   printf("=== test left_rotate ===\n");
   printf("xl: %c  xr: %c  yl: %c yr = %c\n",x.l->key,x.r->key,y.l->key,y.r->key);
   printf("ap: %c  bp: %c  cp: %c\n",a.p->key,b.p->key,c.p->key);
   printf("rotating...\n");
   */
   left_rotate(&x,&t);
   /*
   printf("xl: %c  xr: %c  yl: %c yr = %c\n",x.l->key,x.r->key,y.l->key,y.r->key);
   printf("ap: %c  bp: %c  cp: %c\n",a.p->key,b.p->key,c.p->key);
   */
   TEST("left rotate",(x.l->key == 'a' && x.r->key == 'b' && y.l->key == 'x' && y.r->key == 'c' &&
                       a.p->key == 'x' && b.p->key == 'x' && c.p->key == 'y'));

   //printf("\n");


   /*
   printf("=== test rght_rotate ===\n");
   printf("xl: %c  xr: %c  yl: %c yr = %c\n",x.l->key,x.r->key,y.l->key,y.r->key);
   printf("ap: %c  bp: %c  cp: %c\n",a.p->key,b.p->key,c.p->key);
   printf("rotating...\n");
   */
   rght_rotate(&y,&t);
   /*
   printf("xl: %c  xr: %c  yl: %c yr = %c\n",x.l->key,x.r->key,y.l->key,y.r->key);
   printf("ap: %c  bp: %c  cp: %c\n",a.p->key,b.p->key,c.p->key);
   */
   TEST("rght rotate",(x.l->key == 'a' && x.r->key == 'y' && y.l->key == 'b' && y.r->key == 'c' &&
                       a.p->key == 'x' && b.p->key == 'y' && c.p->key == 'y'));

   //printf("nice nice\n\n");

   init_rb(&t);

   //printf("=== test insert ===\n");
   //in_order_print_rb(&t);
   insert_rb(11,1,&t);
   TEST("insert 11",get_rb(11,&t));
   //in_order_print_rb(&t);
   insert_rb(14,1,&t);
   TEST("insert 14",get_rb(14,&t));
   //in_order_print_rb(&t);
   insert_rb(2,1,&t);
   TEST("insert 2",get_rb(2,&t));
   //in_order_print_rb(&t);
   insert_rb(15,1,&t);
   TEST("insert 15",get_rb(15,&t));
   //in_order_print_rb(&t);
   insert_rb(1,1,&t);
   TEST("insert 1",get_rb(1,&t));
   //in_order_print_rb(&t);
   insert_rb(7,1,&t);
   TEST("insert 7",get_rb(7,&t));
   //in_order_print_rb(&t);
   insert_rb(8,1,&t);
   TEST("insert 8",get_rb(8,&t));
   //in_order_print_rb(&t);
   insert_rb(5,1,&t);
   TEST("insert 5",get_rb(5,&t));
   //in_order_print_rb(&t);
   insert_rb(4,1,&t);
   TEST("insert 4",get_rb(4,&t));
   //in_order_print_rb(&t);

   //printf("\n\n");

   RESET();

   //in_order_print_rb(&t);
   insert_rb(11,1,&t);
   TEST("insert 11",get_rb(11,&t));
   //in_order_print_rb(&t);
   insert_rb(2,1,&t);
   TEST("insert 2",get_rb(2,&t));
   //in_order_print_rb(&t);
   insert_rb(20,1,&t);
   TEST("insert 20",get_rb(20,&t));
   //in_order_print_rb(&t);
   insert_rb(1,1,&t);
   TEST("insert 1",get_rb(1,&t));
   //in_order_print_rb(&t);
   insert_rb(21,1,&t);
   TEST("insert 21",get_rb(21,&t));
   //in_order_print_rb(&t);
   insert_rb(15,1,&t);
   TEST("insert 15",get_rb(15,&t));
   //in_order_print_rb(&t);
   insert_rb(14,1,&t);
   TEST("insert 14",get_rb(14,&t));
   //in_order_print_rb(&t);
   insert_rb(16,1,&t);
   TEST("insert 16",get_rb(16,&t));
   //in_order_print_rb(&t);
   insert_rb(17,1,&t);
   TEST("insert 17",get_rb(17,&t));
   //in_order_print_rb(&t);

   //printf("\n\n");

   RESET();

   //in_order_print_rb(&t);
   insert_rb(11,1,&t);
   TEST("insert 11",get_rb(11,&t));
   //in_order_print_rb(&t);
   insert_rb(5,1,&t);
   TEST("insert 5",get_rb(5,&t));
   //in_order_print_rb(&t);
   insert_rb(15,1,&t);
   TEST("insert 15",get_rb(15,&t));
   //in_order_print_rb(&t);
   insert_rb(17,1,&t);
   TEST("insert 17",get_rb(17,&t));
   //in_order_print_rb(&t);
   insert_rb(19,1,&t);
   TEST("insert 19",get_rb(19,&t));
   //in_order_print_rb(&t);

   //printf("\n\n");

   RESET();

   //in_order_print_rb(&t);
   insert_rb(11,1,&t);
   TEST("insert 11",get_rb(11,&t));
   //in_order_print_rb(&t);
   insert_rb(5,1,&t);
   TEST("insert 5",get_rb(5,&t));
   //in_order_print_rb(&t);
   insert_rb(15,1,&t);
   TEST("insert 15",get_rb(15,&t));
   //in_order_print_rb(&t);
   insert_rb(4,1,&t);
   TEST("insert 4",get_rb(4,&t));
   //in_order_print_rb(&t);
   insert_rb(3,1,&t);
   TEST("insert 19",get_rb(3,&t));
   //in_order_print_rb(&t);
   insert_rb(17,1,&t);
   TEST("insert 17",get_rb(17,&t));
   //in_order_print_rb(&t);
   insert_rb(19,1,&t);
   TEST("insert 19",get_rb(19,&t));
   //in_order_print_rb(&t);
   insert_rb(6,1,&t);
   TEST("insert 6",get_rb(6,&t));
   //in_order_print_rb(&t);
   insert_rb(7,1,&t);
   TEST("insert 7",get_rb(7,&t));
   //in_order_print_rb(&t);
   insert_rb(8,1,&t);
   TEST("insert 8",get_rb(8,&t));
   //in_order_print_rb(&t);
   insert_rb(9,1,&t);
   TEST("insert 9",get_rb(9,&t));
   //in_order_print_rb(&t);
   insert_rb(10,1,&t);
   TEST("insert 10",get_rb(10,&t));
   //in_order_print_rb(&t);

   //printf("\n\n");

   RESET();

   //in_order_print_rb(&t);
   insert_rb(20,1,&t);
   TEST("insert 20",get_rb(20,&t));
   //in_order_print_rb(&t);
   insert_rb(10,1,&t);
   TEST("insert 10",get_rb(10,&t));
   //in_order_print_rb(&t);
   insert_rb(25,1,&t);
   TEST("insert 25",get_rb(25,&t));
   //in_order_print_rb(&t);
   insert_rb(27,1,&t);
   TEST("insert 27",get_rb(27,&t));
   //in_order_print_rb(&t);
   insert_rb(2,1,&t);
   TEST("insert 2",get_rb(2,&t));
   //in_order_print_rb(&t);
   insert_rb(19,1,&t);
   TEST("insert 19",get_rb(19,&t));
   //in_order_print_rb(&t);
   insert_rb(22,1,&t);
   TEST("insert 22",get_rb(22,&t));
   //in_order_print_rb(&t);
   insert_rb(1,1,&t);
   TEST("insert 1",get_rb(1,&t));
   //in_order_print_rb(&t);
   insert_rb(3,1,&t);
   TEST("insert 3",get_rb(3,&t));
   //in_order_print_rb(&t);
   insert_rb(18,1,&t);
   TEST("insert 18",get_rb(18,&t));
   //in_order_print_rb(&t);
   insert_rb(17,1,&t);
   TEST("insert 17",get_rb(17,&t));
   //in_order_print_rb(&t);
   insert_rb(16,1,&t);
   TEST("insert 16",get_rb(16,&t));
   //in_order_print_rb(&t);
   insert_rb(15,1,&t);
   TEST("insert 15",get_rb(15,&t));
   //in_order_print_rb(&t);
   insert_rb(14,1,&t);
   TEST("insert 14",get_rb(14,&t));
   //in_order_print_rb(&t);
   insert_rb(13,1,&t);
   TEST("insert 13",get_rb(13,&t));
   //in_order_print_rb(&t);
   insert_rb(12,1,&t);
   TEST("insert 12",get_rb(12,&t));
   //in_order_print_rb(&t);
   insert_rb(11,1,&t);
   TEST("insert 11",get_rb(11,&t));
   //in_order_print_rb(&t);

   //printf("\nyes all of this was manually verified xD\n");
   //printf("\n\n");

   RESET();

   //printf("=== test delete ===\n");
   
   //in_order_print_rb(&t);
   insert_rb(11,1,&t);
   //in_order_print_rb(&t);
   insert_rb(5,1,&t);
   //in_order_print_rb(&t);
   insert_rb(15,1,&t);
   //in_order_print_rb(&t);

   delete_rb(5,&t);
   TEST("delete 5",get_rb(5,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(15,&t);
   TEST("delete 15",get_rb(15,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(11,&t);
   TEST("delete 11",get_rb(11,&t) == -1);
   //in_order_print_rb(&t);

   //printf("\n\n");

   RESET();

   //in_order_print_rb(&t);
   insert_rb(11,1,&t);
   //in_order_print_rb(&t);
   insert_rb(2,1,&t);
   //in_order_print_rb(&t);
   insert_rb(20,1,&t);
   //in_order_print_rb(&t);
   insert_rb(1,1,&t);
   //in_order_print_rb(&t);
   insert_rb(21,1,&t);
   //in_order_print_rb(&t);
   insert_rb(15,1,&t);
   //in_order_print_rb(&t);
   insert_rb(14,1,&t);
   //in_order_print_rb(&t);
   insert_rb(16,1,&t);
   //in_order_print_rb(&t);
   insert_rb(17,1,&t);
   //in_order_print_rb(&t);

   delete_rb(11,&t);
   TEST("delete 11",get_rb(11,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(2,&t);
   TEST("delete 2",get_rb(2,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(20,&t);
   TEST("delete 20",get_rb(20,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(1,&t);
   TEST("delete 1",get_rb(1,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(17,&t);
   TEST("delete 17",get_rb(17,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(16,&t);
   TEST("delete 16",get_rb(16,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(14,&t);
   TEST("delete 14",get_rb(14,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(15,&t);
   TEST("delete 15",get_rb(15,&t) == -1);
   //in_order_print_rb(&t);

   //printf("\n\n");

   RESET();

   //in_order_print_rb(&t);
   insert_rb(11,1,&t);
   //in_order_print_rb(&t);
   insert_rb(2,1,&t);
   //in_order_print_rb(&t);
   insert_rb(20,1,&t);
   //in_order_print_rb(&t);
   insert_rb(1,1,&t);
   //in_order_print_rb(&t);
   insert_rb(21,1,&t);
   //in_order_print_rb(&t);
   insert_rb(15,1,&t);
   //in_order_print_rb(&t);
   insert_rb(14,1,&t);
   //in_order_print_rb(&t);
   insert_rb(16,1,&t);
   //in_order_print_rb(&t);
   insert_rb(17,1,&t);
   //in_order_print_rb(&t);

   delete_rb(15,&t);
   TEST("delete 15",get_rb(15,&t) == -1);
   //in_order_print_rb(&t);
   RESET();

   //printf("\n\n");

   //in_order_print_rb(&t);
   insert_rb(11,1,&t);
   //in_order_print_rb(&t);
   insert_rb(2,1,&t);
   //in_order_print_rb(&t);
   insert_rb(20,1,&t);
   //in_order_print_rb(&t);
   insert_rb(1,1,&t);
   //in_order_print_rb(&t);
   insert_rb(21,1,&t);
   //in_order_print_rb(&t);
   insert_rb(15,1,&t);
   //in_order_print_rb(&t);
   insert_rb(14,1,&t);
   //in_order_print_rb(&t);
   insert_rb(16,1,&t);
   //in_order_print_rb(&t);
   insert_rb(17,1,&t);
   //in_order_print_rb(&t);
   insert_rb(18,1,&t);
   //in_order_print_rb(&t);
   insert_rb(19,1,&t);
   //in_order_print_rb(&t);

   delete_rb(15,&t);
   TEST("delete 15",get_rb(15,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(14,&t);
   TEST("delete 14",get_rb(14,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(17,&t);
   TEST("delete 17",get_rb(17,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(16,&t);
   TEST("delete 16",get_rb(16,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(11,&t);
   TEST("delete 11",get_rb(11,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(2,&t);
   TEST("delete 12",get_rb(2,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(20,&t);
   TEST("delete 20",get_rb(20,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(19,&t);
   TEST("delete 19",get_rb(19,&t) == -1);
   //in_order_print_rb(&t);
   delete_rb(18,&t);
   TEST("delete 18",get_rb(18,&t) == -1);
   //in_order_print_rb(&t);

   RESET();
   
   //printf("\n\n");

   //in_orderer_print_rb(&t);
   insert_rb(20,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(10,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(25,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(27,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(2,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(19,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(22,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(1,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(3,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(18,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(17,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(16,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(15,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(14,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(13,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(12,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(11,1,&t);
   //in_orderer_print_rb(&t);

   delete_rb(18,&t);
   TEST("delete 18",get_rb(18,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(17,&t);
   TEST("delete 17",get_rb(17,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(15,&t);
   TEST("delete 15",get_rb(15,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(19,&t);
   TEST("delete 19",get_rb(19,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(27,&t);
   TEST("delete 27",get_rb(27,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(11,&t);
   TEST("delete 11",get_rb(11,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(20,&t);
   TEST("delete 20",get_rb(20,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(12,&t);
   TEST("delete 12",get_rb(12,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(22,&t);
   TEST("delete 22",get_rb(22,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(14,&t);
   TEST("delete 14",get_rb(14,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(13,&t);
   TEST("delete 13",get_rb(13,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(10,&t);
   TEST("delete 10",get_rb(10,&t) == -1);
   //in_orderer_print_rb(&t);

   RESET();
   
   //printf("\n\n");

   //in_orderer_print_rb(&t);
   insert_rb(20,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(19,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(21,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(18,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(22,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(17,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(23,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(16,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(24,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(15,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(25,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(14,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(26,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(13,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(27,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(12,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(28,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(11,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(29,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(11,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(30,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(10,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(31,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(9,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(32,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(8,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(33,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(7,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(34,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(6,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(35,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(5,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(36,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(4,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(37,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(3,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(38,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(2,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(39,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(1,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(40,1,&t);
   //in_orderer_print_rb(&t);
   insert_rb(0,1,&t);
   //in_orderer_print_rb(&t);

   delete_rb(33,&t);
   TEST("delete 33",get_rb(33,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(34,&t);
   TEST("delete 34",get_rb(34,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(25,&t);
   TEST("delete 25",get_rb(25,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(35,&t);
   TEST("delete 35",get_rb(35,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(36,&t);
   TEST("delete 36",get_rb(36,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(38,&t);
   TEST("delete 38",get_rb(38,&t) == -1);
   //in_orderer_print_rb(&t);

   //printf("\n\n");

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
   TEST("delete 0",get_rb(0,&t) == -1);
   delete_rb(1,&t);
   TEST("delete 1",get_rb(1,&t) == -1);
   delete_rb(6,&t);
   TEST("delete 6",get_rb(6,&t) == -1);
   delete_rb(8,&t);
   TEST("delete 8",get_rb(8,&t) == -1);
   delete_rb(9,&t);
   TEST("delete 9",get_rb(9,&t) == -1);
   delete_rb(3,&t);
   TEST("delete 3",get_rb(3,&t) == -1);
   delete_rb(2,&t);
   TEST("delete 2",get_rb(2,&t) == -1);
   delete_rb(4,&t);
   TEST("delete 4",get_rb(4,&t) == -1);
   delete_rb(7,&t);
   TEST("delete 7",get_rb(7,&t) == -1);
   //in_orderer_print_rb(&t);
   delete_rb(5,&t);
   TEST("delete 5",get_rb(5,&t) == -1);

   destroy_helper_rb(t.root);

   printf("\n======= TEST BINARY SEARCH TREE =======\n\n");

   struct bs_tree s;
   init_bs(&s);

   //printf("=== test insert ===\n");

   //in_order_print_bs(&s);
   insert_bs(5,5,&s);
   TEST("insert 5",get_bs(5,&s));
   //in_order_print_bs(&s);
   insert_bs(2,4,&s);
   TEST("insert 2",get_bs(2,&s));
   //in_order_print_bs(&s);
   insert_bs(4,3,&s);
   TEST("insert 4",get_bs(4,&s));
   //in_order_print_bs(&s);
   insert_bs(3,2,&s);
   TEST("insert 3",get_bs(3,&s));
   //in_order_print_bs(&s);
   insert_bs(1,1,&s);
   TEST("insert 1",get_bs(1,&s));
   //in_order_print_bs(&s);
   insert_bs(7,6,&s);
   TEST("insert 7",get_bs(7,&s));
   //in_order_print_bs(&s);
   insert_bs(6,7,&s);
   TEST("insert 6",get_bs(6,&s));
   //in_order_print_bs(&s);
   insert_bs(8,8,&s);
   TEST("insert 8",get_bs(8,&s));
   //in_order_print_bs(&s);
   insert_bs(9,9,&s);
   TEST("insert 9",get_bs(9,&s));
   //in_order_print_bs(&s);
   
   //printf("\n\n");

   //printf("=== test delete ===\n");

   delete_bs(5,&s);
   TEST("delete 5",get_bs(5,&s) == -1);
   //in_order_print_bs(&s);
   delete_bs(1,&s);
   TEST("delete 1",get_bs(5,&s) == -1);
   //in_order_print_bs(&s);
   delete_bs(9,&s);
   TEST("delete 9",get_bs(5,&s) == -1);
   //in_order_print_bs(&s);
   delete_bs(7,&s);
   TEST("delete 7",get_bs(5,&s) == -1);
   //in_order_print_bs(&s);
   delete_bs(6,&s);
   TEST("delete 6",get_bs(5,&s) == -1);
   //in_order_print_bs(&s);
   delete_bs(2,&s);
   TEST("delete 2",get_bs(5,&s) == -1);
   //in_order_print_bs(&s);
   delete_bs(4,&s);
   TEST("delete 4",get_bs(5,&s) == -1);
   //in_order_print_bs(&s);
   delete_bs(3,&s);
   TEST("delete 2",get_bs(5,&s) == -1);
   //in_order_print_bs(&s);
   delete_bs(8,&s);
   TEST("delete 8",get_bs(5,&s) == -1);
   //in_order_print_bs(&s);

   //printf("\n\n");

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
   //in_order_print_bs(&s);

   for (int i = 20; i; i--) {
      delete_bs(i,&s);
      TEST("delete i",get_bs(i,&s) == -1);
      //in_order_print_bs(&s);
   }

   //printf("\n\n");

   destroy_helper_bs(s.root);

   printf("\n======= TEST AVL SEARCH TREE =======\n\n");

   struct avl_tree v;

   struct avl_node aa = {.key = 97, .val = 0, .l = 0, .r = 0 };
   struct avl_node bb = {.key = 98, .val = 1, .l = 0, .r = 0 };
   struct avl_node cc = {.key = 99, .val = 2, .l = 0, .r = 0 };
   struct avl_node dd = {.key = 100, .val = 3, .l = 0, .r = 0 };
   struct avl_node yy = {.key = 121, .val = 5, .l = &bb, .r = &cc };
   struct avl_node xx = {.key = 120, .val = 6, .p = 0, .l = &aa, .r = &yy };
   struct avl_node zz = {.key = 122, .val = 7, .p = 0, .l = 0, .r = 0 };
   yy.p = &xx; aa.p = &xx; bb.p = &yy; cc.p = &yy;

   ll_rotate(&xx,&v);

   TEST("ll rotate",(xx.l->key == 'a' && xx.r->key == 'b' && yy.l->key == 'x' && yy.r->key == 'c' &&
                       aa.p->key == 'x' && bb.p->key == 'x' && cc.p->key == 'y'));

   rr_rotate(&yy,&v);

   TEST("rr rotate",(xx.l->key == 'a' && xx.r->key == 'y' && yy.l->key == 'b' && yy.r->key == 'c' &&
                     aa.p->key == 'x' && bb.p->key == 'y' && cc.p->key == 'y'));

   xx.l = &aa; aa.p = &xx; zz.p = &xx; xx.r = &zz; yy.p = &zz; 
   zz.l = &yy; dd.p = &zz; zz.r = &dd; yy.l = &bb; yy.r = &cc;
   cc.p = &yy; bb.p = &yy;

   rl_rotate(&zz,&v);

   TEST("rl rotate",(xx.l->key == 'a' && xx.r->key == 'b' && xx.p->key == 'y' && 
                     zz.l->key == 'c' && zz.r->key == 'd' && zz.p->key == 'y' &&
                     yy.l->key == 'x' && yy.r->key == 'z' && yy.p == 0));

   xx.r = &dd; dd.p = &xx; zz.p = &xx; xx.l = &zz; yy.p = &zz;
   zz.r = &yy; aa.p = &zz; zz.l = &aa; yy.l = &bb; yy.r = &cc;
   cc.p = &yy; bb.p = &yy; xx.p = 0;

   lr_rotate(&zz,&v);

   TEST("lr rotate",(xx.p->key == 'y' && zz.p->key == 'y' && yy.p == 0 &&
                     xx.l->key == 'c' && zz.l->key == 'a' && yy.l->key == 'z' &&
                     xx.r->key == 'd' && zz.r->key == 'b' && yy.r->key == 'x'));

   v.root = 0;

   in_order_print_avl(&v);
   insert_avl(5,3,&v);
   in_order_print_avl(&v);
   insert_avl(3,1,&v);
   in_order_print_avl(&v);
   insert_avl(7,1,&v);
   in_order_print_avl(&v);
   insert_avl(8,1,&v);
   in_order_print_avl(&v);
   insert_avl(9,1,&v);
   in_order_print_avl(&v);
   insert_avl(10,1,&v);
   in_order_print_avl(&v);


   return 0;
}
