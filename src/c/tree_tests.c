
#include "red_black_tree.h"
#include "binary_search_tree.h"
#include "generic_binary_search_tree.h"
#include "generic_red_black_tree.h"
#include "avl_tree.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define RESET() destroy_helper_rb(t.root); init_rb(&t)
#define RESETAVL() destroy_helper_avl(v.root); init_avl(&v)
#define RESETGRB() destroy_helper_grb(grb.root,&grb); \
                   init_grb(compare_int_wrappers,free_int_wrapper,free_int_wrapper,&grb)


#define TEST(name,condition) \
   printf("TEST %03x: [ %-30s ] ",tests++,name); \
   res = condition; \
   if (res) printf("\033[32mPASSED\033[0m\n"); \
   else printf("\033[31mFAILED\033[0m\n")

struct int_wrapper { int i; };

int compare_int_wrappers(const void * a, const void * b) {
   struct int_wrapper * real_a = (struct int_wrapper *)a;
   struct int_wrapper * real_b = (struct int_wrapper *)b;
   if (real_a->i < real_b->i)
      return -1;
   if (real_a->i > real_b->i)
      return 1;
   return 0;
}

void free_int_wrapper(void * a) {
   free(a);
}

struct int_wrapper * new_int_wrapper(int i) {
   struct int_wrapper * ret = malloc(sizeof(struct int_wrapper));
   ret->i = i;
   return ret;
}


int main(int argc, char ** argv) {
   if (argc != 2 || (argv[1][0] != '1' && argv[1][0] != '2')) {
      printf("usage: ./%s [1|2]\n",argv[0]);
      exit(1);
   }

   int mode = argv[1][0] - '0';

   int tests = 0;
   int res = 0;

   if (mode == 1) // functional tests
   {
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


   printf("\n======= TEST GENERIC BINARY SEARCH TREE =======\n\n");


   struct gbs_tree gs;
   init_gbs(compare_int_wrappers,free_int_wrapper,free_int_wrapper,&gs);

   struct int_wrapper test_key;

   test_key.i = 5;
   insert_gbs(new_int_wrapper(5),new_int_wrapper(5),&gs);
   TEST("insert 5",(((struct int_wrapper *)(get_gbs(&test_key,&gs)))->i == test_key.i));
   test_key.i = 2;
   insert_gbs(new_int_wrapper(2),new_int_wrapper(4),&gs);
   TEST("insert 2",(((struct int_wrapper *)(get_gbs(&test_key,&gs)))->i == 4));
   test_key.i = 4;
   insert_gbs(new_int_wrapper(4),new_int_wrapper(3),&gs);
   TEST("insert 4",(((struct int_wrapper *)(get_gbs(&test_key,&gs)))->i == 3));
   test_key.i = 3;
   insert_gbs(new_int_wrapper(3),new_int_wrapper(2),&gs);
   TEST("insert 3",(((struct int_wrapper *)(get_gbs(&test_key,&gs)))->i == 2));
   test_key.i = 1;
   insert_gbs(new_int_wrapper(1),new_int_wrapper(1),&gs);
   TEST("insert 1",(((struct int_wrapper *)(get_gbs(&test_key,&gs)))->i == 1));
   test_key.i = 7;
   insert_gbs(new_int_wrapper(7),new_int_wrapper(6),&gs);
   TEST("insert 7",(((struct int_wrapper *)(get_gbs(&test_key,&gs)))->i == 6));
   test_key.i = 6;
   insert_gbs(new_int_wrapper(6),new_int_wrapper(7),&gs);
   TEST("insert 6",(((struct int_wrapper *)(get_gbs(&test_key,&gs)))->i == 7));
   test_key.i = 8;
   insert_gbs(new_int_wrapper(8),new_int_wrapper(8),&gs);
   TEST("insert 8",(((struct int_wrapper *)(get_gbs(&test_key,&gs)))->i == 8));
   test_key.i = 9;
   insert_gbs(new_int_wrapper(9),new_int_wrapper(9),&gs);
   TEST("insert 9",(((struct int_wrapper *)(get_gbs(&test_key,&gs)))->i == 9));

   test_key.i = 5;
   free(delete_gbs(&test_key,&gs));
   TEST("delete 5",get_gbs(&test_key,&gs) == (void *)-1);
   test_key.i = 1;
   free(delete_gbs(&test_key,&gs));
   TEST("delete 1",get_gbs(&test_key,&gs) == (void *)-1);
   test_key.i = 9;
   free(delete_gbs(&test_key,&gs));
   TEST("delete 9",get_gbs(&test_key,&gs) == (void *)-1);
   test_key.i = 7;
   free(delete_gbs(&test_key,&gs));
   TEST("delete 7",get_gbs(&test_key,&gs) == (void *)-1);
   test_key.i = 6;
   free(delete_gbs(&test_key,&gs));
   TEST("delete 6",get_gbs(&test_key,&gs) == (void *)-1);
   test_key.i = 2;
   free(delete_gbs(&test_key,&gs));
   TEST("delete 2",get_gbs(&test_key,&gs) == (void *)-1);
   test_key.i = 4;
   free(delete_gbs(&test_key,&gs));
   TEST("delete 4",get_gbs(&test_key,&gs) == (void *)-1);
   test_key.i = 3;
   free(delete_gbs(&test_key,&gs));
   TEST("delete 3",get_gbs(&test_key,&gs) == (void *)-1);
   test_key.i = 8;
   free(delete_gbs(&test_key,&gs));
   TEST("delete 8",get_gbs(&test_key,&gs) == (void *)-1);

   insert_gbs(new_int_wrapper(10),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(5),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(3),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(4),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(1),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(2),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(0),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(7),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(9),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(8),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(6),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(15),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(13),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(12),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(11),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(18),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(20),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(19),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(17),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(16),new_int_wrapper(1),&gs);
   insert_gbs(new_int_wrapper(14),new_int_wrapper(1),&gs);

   for (int i = 20; i; i--) {
      test_key.i = i;
      TEST("get i",((struct int_wrapper *)(get_gbs(&test_key,&gs)))->i == 1);
      free(delete_gbs(&test_key.i,&gs));
      TEST("delete i",get_gbs(&test_key,&gs) == (void *)-1);
   }

   destroy_helper_gbs(gs.root,&gs);

   printf("\n======= GENERIC RED BLACK TREE TESTS =======\n\n");

   struct grb_tree grb;
   init_grb(compare_int_wrappers,free_int_wrapper,free_int_wrapper,&grb);

   test_key.i = 11;
   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   TEST("insert 11",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 14;
   insert_grb(new_int_wrapper(14),new_int_wrapper(1),&grb);
   TEST("insert 14",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 2;
   insert_grb(new_int_wrapper(2),new_int_wrapper(1),&grb);
   TEST("insert 2",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 15;
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);
   TEST("insert 15",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 1;
   insert_grb(new_int_wrapper(1),new_int_wrapper(1),&grb);
   TEST("insert 1",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 7;
   insert_grb(new_int_wrapper(7),new_int_wrapper(1),&grb);
   TEST("insert 7",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 8;
   insert_grb(new_int_wrapper(8),new_int_wrapper(1),&grb);
   TEST("insert 8",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 5;
   insert_grb(new_int_wrapper(5),new_int_wrapper(1),&grb);
   TEST("insert 5",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 4;
   insert_grb(new_int_wrapper(4),new_int_wrapper(1),&grb);
   TEST("insert 4",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);

   RESETGRB();

   test_key.i = 11;
   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   TEST("insert 11",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 2;
   insert_grb(new_int_wrapper(2),new_int_wrapper(1),&grb);
   TEST("insert 2",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 20;
   insert_grb(new_int_wrapper(20),new_int_wrapper(1),&grb);
   TEST("insert 20",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 1;
   insert_grb(new_int_wrapper(1),new_int_wrapper(1),&grb);
   TEST("insert 1",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 21;
   insert_grb(new_int_wrapper(21),new_int_wrapper(1),&grb);
   TEST("insert 21",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 15;
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);
   TEST("insert 15",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 14;
   insert_grb(new_int_wrapper(14),new_int_wrapper(1),&grb);
   TEST("insert 14",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 16;
   insert_grb(new_int_wrapper(16),new_int_wrapper(1),&grb);
   TEST("insert 16",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 17;
   insert_grb(new_int_wrapper(17),new_int_wrapper(1),&grb);
   TEST("insert 17",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);

   RESETGRB();

   test_key.i = 11;
   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   TEST("insert 11",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 5;
   insert_grb(new_int_wrapper(5),new_int_wrapper(1),&grb);
   TEST("insert 5",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 15;
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);
   TEST("insert 15",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 17;
   insert_grb(new_int_wrapper(17),new_int_wrapper(1),&grb);
   TEST("insert 17",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 19;
   insert_grb(new_int_wrapper(19),new_int_wrapper(1),&grb);
   TEST("insert 19",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);

   RESETGRB();
   
   test_key.i = 11;
   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   TEST("insert 11",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 5;
   insert_grb(new_int_wrapper(5),new_int_wrapper(1),&grb);
   TEST("insert 5",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 15;
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);
   TEST("insert 15",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 4;
   insert_grb(new_int_wrapper(4),new_int_wrapper(1),&grb);
   TEST("insert 4",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 3;
   insert_grb(new_int_wrapper(3),new_int_wrapper(1),&grb);
   TEST("insert 3",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 17;
   insert_grb(new_int_wrapper(17),new_int_wrapper(1),&grb);
   TEST("insert 17",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 19;
   insert_grb(new_int_wrapper(19),new_int_wrapper(1),&grb);
   TEST("insert 19",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 6;
   insert_grb(new_int_wrapper(6),new_int_wrapper(1),&grb);
   TEST("insert 6",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 7;
   insert_grb(new_int_wrapper(7),new_int_wrapper(1),&grb);
   TEST("insert 7",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 8;
   insert_grb(new_int_wrapper(8),new_int_wrapper(1),&grb);
   TEST("insert 8",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 9;
   insert_grb(new_int_wrapper(9),new_int_wrapper(1),&grb);
   TEST("insert 9",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 10;
   insert_grb(new_int_wrapper(10),new_int_wrapper(1),&grb);
   TEST("insert 10",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);

   RESETGRB();

   test_key.i = 20;
   insert_grb(new_int_wrapper(20),new_int_wrapper(1),&grb);
   TEST("insert 20",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 10;
   insert_grb(new_int_wrapper(10),new_int_wrapper(1),&grb);
   TEST("insert 10",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 25;
   insert_grb(new_int_wrapper(25),new_int_wrapper(1),&grb);
   TEST("insert 25",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 27;
   insert_grb(new_int_wrapper(27),new_int_wrapper(1),&grb);
   TEST("insert 27",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 2;
   insert_grb(new_int_wrapper(2),new_int_wrapper(1),&grb);
   TEST("insert 2",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 19;
   insert_grb(new_int_wrapper(19),new_int_wrapper(1),&grb);
   TEST("insert 19",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 22;
   insert_grb(new_int_wrapper(22),new_int_wrapper(1),&grb);
   TEST("insert 22",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 1;
   insert_grb(new_int_wrapper(1),new_int_wrapper(1),&grb);
   TEST("insert 1",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 3;
   insert_grb(new_int_wrapper(3),new_int_wrapper(1),&grb);
   TEST("insert 3",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 18;
   insert_grb(new_int_wrapper(18),new_int_wrapper(1),&grb);
   TEST("insert 18",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 17;
   insert_grb(new_int_wrapper(17),new_int_wrapper(1),&grb);
   TEST("insert 17",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 16;
   insert_grb(new_int_wrapper(16),new_int_wrapper(1),&grb);
   TEST("insert 16",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 15;
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);
   TEST("insert 15",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 14;
   insert_grb(new_int_wrapper(14),new_int_wrapper(1),&grb);
   TEST("insert 14",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 13;
   insert_grb(new_int_wrapper(13),new_int_wrapper(1),&grb);
   TEST("insert 13",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 12;
   insert_grb(new_int_wrapper(12),new_int_wrapper(1),&grb);
   TEST("insert 12",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   test_key.i = 11;
   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   TEST("insert 11",((struct int_wrapper *)(get_grb(&test_key,&grb)))->i == 1);
   
   RESETGRB();

   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(5),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);

   test_key.i = 5;
   free(delete_grb(&test_key,&grb));
   TEST("delete 5",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 15;
   free(delete_grb(&test_key,&grb));
   TEST("delete 15",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 11;
   free(delete_grb(&test_key,&grb));
   TEST("delete 11",get_grb(&test_key,&grb) == (void *)-1);
   
   RESETGRB();

   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(2),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(20),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(1),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(21),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(14),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(16),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(17),new_int_wrapper(1),&grb);
   
   test_key.i = 11;
   free(delete_grb(&test_key,&grb));
   TEST("delete 11",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 2;
   free(delete_grb(&test_key,&grb));
   TEST("delete 2",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 20;
   free(delete_grb(&test_key,&grb));
   TEST("delete 20",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 1;
   free(delete_grb(&test_key,&grb));
   TEST("delete 1",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 17;
   free(delete_grb(&test_key,&grb));
   TEST("delete 17",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 16;
   free(delete_grb(&test_key,&grb));
   TEST("delete 16",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 14;
   free(delete_grb(&test_key,&grb));
   TEST("delete 14",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 15;
   free(delete_grb(&test_key,&grb));
   TEST("delete 15",get_grb(&test_key,&grb) == (void *)-1);

   RESETGRB();

   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(2),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(20),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(1),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(21),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(14),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(16),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(17),new_int_wrapper(1),&grb);

   test_key.i = 15;
   free(delete_grb(&test_key,&grb));
   TEST("delete 15",get_grb(&test_key,&grb) == (void *)-1);

   RESETGRB();

   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(2),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(20),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(1),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(21),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(14),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(16),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(17),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(18),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(19),new_int_wrapper(1),&grb);

   test_key.i = 15;
   free(delete_grb(&test_key,&grb));
   TEST("delete 15",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 14;
   free(delete_grb(&test_key,&grb));
   TEST("delete 14",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 17;
   free(delete_grb(&test_key,&grb));
   TEST("delete 17",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 16;
   free(delete_grb(&test_key,&grb));
   TEST("delete 16",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 11;
   free(delete_grb(&test_key,&grb));
   TEST("delete 11",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 2;
   free(delete_grb(&test_key,&grb));
   TEST("delete 2",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 20;
   free(delete_grb(&test_key,&grb));
   TEST("delete 20",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 19;
   free(delete_grb(&test_key,&grb));
   TEST("delete 19",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 18;
   free(delete_grb(&test_key,&grb));
   TEST("delete 18",get_grb(&test_key,&grb) == (void *)-1);

   RESETGRB();
   
   insert_grb(new_int_wrapper(20),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(10),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(25),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(27),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(2),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(19),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(22),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(1),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(3),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(18),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(17),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(16),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(14),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(13),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(12),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);

   test_key.i = 18;
   free(delete_grb(&test_key,&grb));
   TEST("delete 18",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 17;
   free(delete_grb(&test_key,&grb));
   TEST("delete 17",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 15;
   free(delete_grb(&test_key,&grb));
   TEST("delete 15",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 19;
   free(delete_grb(&test_key,&grb));
   TEST("delete 19",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 27;
   free(delete_grb(&test_key,&grb));
   TEST("delete 27",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 11;
   free(delete_grb(&test_key,&grb));
   TEST("delete 11",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 20;
   free(delete_grb(&test_key,&grb));
   TEST("delete 20",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 12;
   free(delete_grb(&test_key,&grb));
   TEST("delete 12",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 22;
   free(delete_grb(&test_key,&grb));
   TEST("delete 22",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 14;
   free(delete_grb(&test_key,&grb));
   TEST("delete 14",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 13;
   free(delete_grb(&test_key,&grb));
   TEST("delete 13",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 10;
   free(delete_grb(&test_key,&grb));
   TEST("delete 10",get_grb(&test_key,&grb) == (void *)-1);

   RESETGRB();

   insert_grb(new_int_wrapper(20),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(19),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(21),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(18),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(22),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(17),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(23),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(16),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(24),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(15),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(25),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(14),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(26),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(13),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(27),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(12),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(28),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(29),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(11),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(30),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(10),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(31),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(9),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(32),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(8),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(33),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(7),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(34),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(6),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(35),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(5),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(36),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(4),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(37),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(3),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(38),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(2),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(39),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(1),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(40),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(0),new_int_wrapper(1),&grb);
   
   test_key.i = 33;
   free(delete_grb(&test_key,&grb));
   TEST("delete 33",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 34;
   free(delete_grb(&test_key,&grb));
   TEST("delete 34",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 25;
   free(delete_grb(&test_key,&grb));
   TEST("delete 25",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 35;
   free(delete_grb(&test_key,&grb));
   TEST("delete 35",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 36;
   free(delete_grb(&test_key,&grb));
   TEST("delete 36",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 38;
   free(delete_grb(&test_key,&grb));
   TEST("delete 38",get_grb(&test_key,&grb) == (void *)-1);

   RESETGRB();

   insert_grb(new_int_wrapper(5),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(7),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(4),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(2),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(3),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(1),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(0),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(9),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(6),new_int_wrapper(1),&grb);
   insert_grb(new_int_wrapper(8),new_int_wrapper(1),&grb);

   test_key.i = 0;
   free(delete_grb(&test_key,&grb));
   TEST("delete 0",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 1;
   free(delete_grb(&test_key,&grb));
   TEST("delete 1",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 6;
   free(delete_grb(&test_key,&grb));
   TEST("delete 6",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 8;
   free(delete_grb(&test_key,&grb));
   TEST("delete 8",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 9;
   free(delete_grb(&test_key,&grb));
   TEST("delete 9",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 3;
   free(delete_grb(&test_key,&grb));
   TEST("delete 3",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 2;
   free(delete_grb(&test_key,&grb));
   TEST("delete 2",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 4;
   free(delete_grb(&test_key,&grb));
   TEST("delete 4",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 7;
   free(delete_grb(&test_key,&grb));
   TEST("delete 7",get_grb(&test_key,&grb) == (void *)-1);
   test_key.i = 5;
   free(delete_grb(&test_key,&grb));
   TEST("delete 5",get_grb(&test_key,&grb) == (void *)-1);

   destroy_helper_grb(grb.root,&grb);


   /*
   printf("\n======= TEST AVL SEARCH TREE =======\n\n");

   struct avl_tree v;

   v.root = 0;

   / same insert tests from red black tree /

   insert_avl(11,1,&v);
   TEST("insert 11",get_avl(11,&v));
   insert_avl(14,1,&v);
   TEST("insert 14",get_avl(14,&v));
   insert_avl(2,1,&v);
   TEST("insert 2",get_avl(2,&v));
   insert_avl(15,1,&v);
   TEST("insert 15",get_avl(15,&v));
   insert_avl(1,1,&v);
   TEST("insert 1",get_avl(1,&v));
   insert_avl(7,1,&v);
   TEST("insert 7",get_avl(7,&v));
   insert_avl(8,1,&v);
   TEST("insert 8",get_avl(8,&v));
   insert_avl(5,1,&v);
   TEST("insert 5",get_avl(5,&v));
   insert_avl(4,1,&v);
   TEST("insert 4",get_avl(4,&v));

   RESETAVL();

   insert_avl(11,1,&v);
   TEST("insert 11",get_avl(11,&v));
   insert_avl(2,1,&v);
   TEST("insert 2",get_avl(2,&v));
   insert_avl(20,1,&v);
   TEST("insert 20",get_avl(20,&v));
   insert_avl(1,1,&v);
   TEST("insert 1",get_avl(1,&v));
   insert_avl(21,1,&v);
   TEST("insert 21",get_avl(21,&v));
   insert_avl(15,1,&v);
   TEST("insert 15",get_avl(15,&v));
   insert_avl(14,1,&v);
   TEST("insert 14",get_avl(14,&v));
   insert_avl(16,1,&v);
   TEST("insert 16",get_avl(16,&v));
   insert_avl(17,1,&v);
   TEST("insert 17",get_avl(17,&v));

   RESETAVL();

   insert_avl(11,1,&v);
   TEST("insert 11",get_avl(11,&v));
   insert_avl(5,1,&v);
   TEST("insert 5",get_avl(5,&v));
   insert_avl(15,1,&v);
   TEST("insert 15",get_avl(15,&v));
   insert_avl(17,1,&v);
   TEST("insert 17",get_avl(17,&v));
   insert_avl(19,1,&v);
   TEST("insert 19",get_avl(19,&v));
   
   RESETAVL();

   insert_avl(11,1,&v);
   TEST("insert 11",get_avl(11,&v));
   insert_avl(5,1,&v);
   TEST("insert 5",get_avl(5,&v));
   insert_avl(15,1,&v);
   TEST("insert 15",get_avl(15,&v));
   insert_avl(4,1,&v);
   TEST("insert 4",get_avl(4,&v));
   insert_avl(3,1,&v);
   TEST("insert 19",get_avl(3,&v));
   insert_avl(17,1,&v);
   TEST("insert 17",get_avl(17,&v));
   insert_avl(19,1,&v);
   TEST("insert 19",get_avl(19,&v));
   insert_avl(6,1,&v);
   TEST("insert 6",get_avl(6,&v));
   insert_avl(7,1,&v);
   TEST("insert 7",get_avl(7,&v));
   insert_avl(8,1,&v);
   TEST("insert 8",get_avl(8,&v));
   insert_avl(9,1,&v);
   TEST("insert 9",get_avl(9,&v));
   insert_avl(10,1,&v);
   TEST("insert 10",get_avl(10,&v));
   

   RESETAVL();

   insert_avl(20,1,&v);
   TEST("insert 20",get_avl(20,&v));
   insert_avl(10,1,&v);
   TEST("insert 10",get_avl(10,&v));
   insert_avl(25,1,&v);
   TEST("insert 25",get_avl(25,&v));
   insert_avl(27,1,&v);
   TEST("insert 27",get_avl(27,&v));
   insert_avl(2,1,&v);
   TEST("insert 2",get_avl(2,&v));
   insert_avl(19,1,&v);
   TEST("insert 19",get_avl(19,&v));
   insert_avl(22,1,&v);
   TEST("insert 22",get_avl(22,&v));
   insert_avl(1,1,&v);
   TEST("insert 1",get_avl(1,&v));
   insert_avl(3,1,&v);
   TEST("insert 3",get_avl(3,&v));
   insert_avl(18,1,&v);
   TEST("insert 18",get_avl(18,&v));
   insert_avl(17,1,&v);
   TEST("insert 17",get_avl(17,&v));
   insert_avl(16,1,&v);
   TEST("insert 16",get_avl(16,&v));
   insert_avl(15,1,&v);
   TEST("insert 15",get_avl(15,&v));
   insert_avl(14,1,&v);
   TEST("insert 14",get_avl(14,&v));
   insert_avl(13,1,&v);
   TEST("insert 13",get_avl(13,&v));
   insert_avl(12,1,&v);
   TEST("insert 12",get_avl(12,&v));
   insert_avl(11,1,&v);
   TEST("insert 11",get_avl(11,&v));

   RESETAVL();

   / test double rotation case /

   insert_avl(15,1,&v);
   TEST("insert 15",get_avl(11,&v));
   insert_avl(7,1,&v);
   TEST("insert 7",get_avl(7,&v));
   insert_avl(20,1,&v);
   TEST("insert 20",get_avl(20,&v));
   insert_avl(9,1,&v);
   TEST("insert 9",get_avl(9,&v));
   insert_avl(8,1,&v);
   TEST("insert 8",get_avl(8,&v));
   insert_avl(6,1,&v);
   TEST("insert 6",get_avl(6,&v));
   insert_avl(5,1,&v);
   TEST("insert 5",get_avl(5,&v));
   insert_avl(4,1,&v);
   TEST("insert 4",get_avl(4,&v));

   RESETAVL();

   insert_avl(15,1,&v);
   TEST("insert 15",get_avl(15,&v));
   insert_avl(20,1,&v);
   TEST("insert 20",get_avl(20,&v));
   insert_avl(7,1,&v);
   TEST("insert 7",get_avl(7,&v));
   insert_avl(16,1,&v);
   TEST("insert 16",get_avl(16,&v));
   insert_avl(17,1,&v);
   TEST("insert 17",get_avl(17,&v));
   insert_avl(21,1,&v);
   TEST("insert 21",get_avl(21,&v));
   insert_avl(18,1,&v);
   TEST("insert 18",get_avl(18,&v));
   insert_avl(19,1,&v);
   TEST("insert 19",get_avl(19,&v));

   RESETAVL();

   insert_avl(11,1,&v);
   insert_avl(5,1,&v);
   insert_avl(15,1,&v);

   in_order_print_avl(&v);
   delete_avl(5,&v);
   TEST("delete 5",get_avl(5,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(15,&v);
   TEST("delete 15",get_avl(15,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(11,&v);
   TEST("delete 11",get_avl(11,&v) == -1);
   in_order_print_avl(&v);

   RESETAVL();

   insert_avl(11,1,&v);
   insert_avl(2,1,&v);
   insert_avl(20,1,&v);
   insert_avl(1,1,&v);
   insert_avl(21,1,&v);
   insert_avl(15,1,&v);
   insert_avl(14,1,&v);
   insert_avl(16,1,&v);
   insert_avl(17,1,&v);

   delete_avl(11,&v);
   in_order_print_avl(&v);
   TEST("delete 11",get_avl(11,&v) == -1);
   delete_avl(2,&v);
   in_order_print_avl(&v);
   TEST("delete 2",get_avl(2,&v) == -1);
   delete_avl(20,&v);
   in_order_print_avl(&v);
   TEST("delete 20",get_avl(20,&v) == -1);
   delete_avl(1,&v);
   in_order_print_avl(&v);
   TEST("delete 1",get_avl(1,&v) == -1);
   delete_avl(17,&v);
   TEST("delete 17",get_avl(17,&v) == -1);
   delete_avl(16,&v);
   TEST("delete 16",get_avl(16,&v) == -1);
   delete_avl(14,&v);
   TEST("delete 14",get_avl(14,&v) == -1);
   delete_avl(15,&v);
   TEST("delete 15",get_avl(15,&v) == -1);

   RESETAVL();

   insert_avl(11,1,&v);
   insert_avl(2,1,&v);
   insert_avl(20,1,&v);
   insert_avl(1,1,&v);
   insert_avl(21,1,&v);
   insert_avl(15,1,&v);
   insert_avl(14,1,&v);
   insert_avl(16,1,&v);
   insert_avl(17,1,&v);


   delete_avl(15,&v);
   TEST("delete 15",get_avl(15,&v) == -1);
   RESETAVL();

   insert_avl(11,1,&v);
   insert_avl(2,1,&v);
   insert_avl(20,1,&v);
   insert_avl(1,1,&v);
   insert_avl(21,1,&v);
   insert_avl(15,1,&v);
   insert_avl(14,1,&v);
   insert_avl(16,1,&v);
   insert_avl(17,1,&v);
   insert_avl(18,1,&v);
   insert_avl(19,1,&v);

   delete_avl(15,&v);
   TEST("delete 15",get_avl(15,&v) == -1);
   delete_avl(14,&v);
   TEST("delete 14",get_avl(14,&v) == -1);
   delete_avl(17,&v);
   TEST("delete 17",get_avl(17,&v) == -1);
   delete_avl(16,&v);
   TEST("delete 16",get_avl(16,&v) == -1);
   delete_avl(11,&v);
   TEST("delete 11",get_avl(11,&v) == -1);
   delete_avl(2,&v);
   TEST("delete 12",get_avl(2,&v) == -1);
   delete_avl(20,&v);
   TEST("delete 20",get_avl(20,&v) == -1);
   delete_avl(19,&v);
   TEST("delete 19",get_avl(19,&v) == -1);
   delete_avl(18,&v);
   TEST("delete 18",get_avl(18,&v) == -1);

   RESETAVL();
   
   insert_avl(20,1,&v);
   insert_avl(10,1,&v);
   insert_avl(25,1,&v);
   insert_avl(27,1,&v);
   insert_avl(2,1,&v);
   insert_avl(19,1,&v);
   insert_avl(22,1,&v);
   insert_avl(1,1,&v);
   insert_avl(3,1,&v);
   insert_avl(18,1,&v);
   insert_avl(17,1,&v);
   insert_avl(16,1,&v);
   insert_avl(15,1,&v);
   insert_avl(14,1,&v);
   insert_avl(13,1,&v);
   insert_avl(12,1,&v);
   insert_avl(11,1,&v);

   delete_avl(18,&v);
   TEST("delete 18",get_avl(18,&v) == -1);
   delete_avl(17,&v);
   TEST("delete 17",get_avl(17,&v) == -1);
   delete_avl(15,&v);
   TEST("delete 15",get_avl(15,&v) == -1);
   delete_avl(19,&v);
   TEST("delete 19",get_avl(19,&v) == -1);
   delete_avl(27,&v);
   TEST("delete 27",get_avl(27,&v) == -1);
   delete_avl(11,&v);
   TEST("delete 11",get_avl(11,&v) == -1);
   delete_avl(20,&v);
   TEST("delete 20",get_avl(20,&v) == -1);
   delete_avl(12,&v);
   TEST("delete 12",get_avl(12,&v) == -1);
   delete_avl(22,&v);
   TEST("delete 22",get_avl(22,&v) == -1);
   delete_avl(14,&v);
   TEST("delete 14",get_avl(14,&v) == -1);
   delete_avl(13,&v);
   TEST("delete 13",get_avl(13,&v) == -1);
   delete_avl(10,&v);
   TEST("delete 10",get_avl(10,&v) == -1);

   RESETAVL();
   
   insert_avl(20,1,&v);
   insert_avl(19,1,&v);
   insert_avl(21,1,&v);
   insert_avl(18,1,&v);
   insert_avl(22,1,&v);
   insert_avl(17,1,&v);
   insert_avl(23,1,&v);
   insert_avl(16,1,&v);
   insert_avl(24,1,&v);
   insert_avl(15,1,&v);
   insert_avl(25,1,&v);
   insert_avl(14,1,&v);
   insert_avl(26,1,&v);
   insert_avl(13,1,&v);
   insert_avl(27,1,&v);
   insert_avl(12,1,&v);
   insert_avl(28,1,&v);
   insert_avl(11,1,&v);
   insert_avl(29,1,&v);
   insert_avl(11,1,&v);
   insert_avl(30,1,&v);
   insert_avl(10,1,&v);
   insert_avl(31,1,&v);
   insert_avl(9,1,&v);
   insert_avl(32,1,&v);
   insert_avl(8,1,&v);
   insert_avl(33,1,&v);
   insert_avl(7,1,&v);
   insert_avl(34,1,&v);
   insert_avl(6,1,&v);
   insert_avl(35,1,&v);
   insert_avl(5,1,&v);
   insert_avl(36,1,&v);
   insert_avl(4,1,&v);
   insert_avl(37,1,&v);
   insert_avl(3,1,&v);
   insert_avl(38,1,&v);
   insert_avl(2,1,&v);
   insert_avl(39,1,&v);
   insert_avl(1,1,&v);
   insert_avl(40,1,&v);
   insert_avl(0,1,&v);

   delete_avl(33,&v);
   TEST("delete 33",get_avl(33,&v) == -1);
   delete_avl(34,&v);
   TEST("delete 34",get_avl(34,&v) == -1);
   delete_avl(25,&v);
   TEST("delete 25",get_avl(25,&v) == -1);
   delete_avl(35,&v);
   TEST("delete 35",get_avl(35,&v) == -1);
   delete_avl(36,&v);
   TEST("delete 36",get_avl(36,&v) == -1);
   delete_avl(38,&v);
   TEST("delete 38",get_avl(38,&v) == -1);

   RESETAVL();

   insert_avl(5,5,&v);
   insert_avl(7,5,&v);
   insert_avl(4,5,&v);
   insert_avl(2,5,&v);
   insert_avl(3,5,&v);
   insert_avl(1,5,&v);
   insert_avl(0,5,&v);
   insert_avl(9,5,&v);
   insert_avl(6,5,&v);
   insert_avl(8,5,&v);

   in_order_print_avl(&v);
   delete_avl(0,&v);
   TEST("delete 0",get_avl(0,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(1,&v);
   TEST("delete 1",get_avl(1,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(6,&v);
   TEST("delete 6",get_avl(6,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(8,&v);
   TEST("delete 8",get_avl(8,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(9,&v);
   TEST("delete 9",get_avl(9,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(3,&v);
   TEST("delete 3",get_avl(3,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(2,&v);
   TEST("delete 2",get_avl(2,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(4,&v);
   TEST("delete 4",get_avl(4,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(7,&v);
   TEST("delete 7",get_avl(7,&v) == -1);
   in_order_print_avl(&v);
   delete_avl(5,&v);
   TEST("delete 5",get_avl(5,&v) == -1);
   in_order_print_avl(&v);

   destroy_helper_avl(v.root);
   */

   }
   else if (mode == 2) 
   {

   int cycles = 100;
   clock_t start;
   double res[2];

   while (cycles < 0x0fffffff) {
      printf("\n======= TIMING %d TREE INSERTIONS =======\n",cycles);
      struct rb_tree t;
      struct bs_tree s;
      init_bs(&s);
      init_rb(&t);


      printf("\n=== RANDOM INPUT ===\n");
      int * elements = malloc(sizeof(int)*cycles);
      for (int i = 0; i < cycles; i++) {
         elements[i] = rand(); // ensure fairness
      }

      printf("Results:\n");

      start = clock();
      for (int i = 0; i < cycles; i++) {
         insert_bs(elements[i],i,&s);
      }
      res[0] = (double)(clock() - start)/CLOCKS_PER_SEC;

      start = clock();
      for (int i = 0; i < cycles; i++) {
         insert_rb(elements[i],i,&t);
      }
      res[1] = (double)(clock() - start)/CLOCKS_PER_SEC;

      printf("Binary Search Tree (Inserts)   :");
      if (res[0] > res[1]) printf("\033[31m"); else printf("\033[32m");
      printf(" %f\033[0m\n",res[0]);
      printf("Red Black Tree     (Inserts)   :"); 
      if (res[1] > res[0]) printf("\033[31m"); else printf("\033[32m");
      printf(" %f\033[0m\n",res[1]);

      start = clock();
      for (int i = 0; i < cycles; i++) {
         get_bs(elements[i],&s);
      }
      res[0] = (double)(clock() - start)/CLOCKS_PER_SEC;

      start = clock();
      for (int i = 0; i < cycles; i++) {
         get_rb(elements[i],&t);
      }
      res[1] = (double)(clock() - start)/CLOCKS_PER_SEC;

      printf("Binary Search Tree (Queries)   :");
      if (res[0] > res[1]) printf("\033[31m"); else printf("\033[32m");
      printf(" %f\033[0m\n",res[0]);
      printf("Red Black Tree     (Queries)   :"); 
      if (res[1] > res[0]) printf("\033[31m"); else printf("\033[32m");
      printf(" %f\033[0m\n",res[1]);

      start = clock();
      for (int i = 0; i < cycles; i++) {
         delete_bs(elements[i],&s);
      }
      res[0] = (double)(clock() - start)/CLOCKS_PER_SEC;

      start = clock();
      for (int i = 0; i < cycles; i++) {
         delete_rb(elements[i],&t);
      }
      res[1] = (double)(clock() - start)/CLOCKS_PER_SEC;

      printf("Binary Search Tree (Deletes)   :");
      if (res[0] > res[1]) printf("\033[31m"); else printf("\033[32m");
      printf(" %f\033[0m\n",res[0]);
      printf("Red Black Tree     (Deletes)   :"); 
      if (res[1] > res[0]) printf("\033[31m"); else printf("\033[32m");
      printf(" %f\033[0m\n",res[1]);

      destroy_helper_rb(t.root);
      destroy_helper_bs(s.root);
      init_bs(&s);
      init_rb(&t);

      if (cycles < 10000000) {

         printf("\n=== ORDERED INPUT ===\n");

         printf("Results:\n");

         start = clock();
         for (int i = 0; i < cycles; i++) {
            insert_bs(i,i,&s);
         }
         res[0] = (double)(clock() - start)/CLOCKS_PER_SEC;

         start = clock();
         for (int i = 0; i < cycles; i++) {
            insert_rb(i,i,&t);
         }
         res[1] = (double)(clock() - start)/CLOCKS_PER_SEC;

         printf("Binary Search Tree (Inserts)   :");
         if (res[0] > res[1]) printf("\033[31m"); else printf("\033[32m");
         printf(" %f\033[0m\n",res[0]);
         printf("Red Black Tree     (Inserts)   :"); 
         if (res[1] > res[0]) printf("\033[31m"); else printf("\033[32m");
         printf(" %f\033[0m\n",res[1]);

         start = clock();
         for (int i = 0; i < cycles; i++) {
            get_bs(i,&s);
         }
         res[0] = (double)(clock() - start)/CLOCKS_PER_SEC;

         start = clock();
         for (int i = 0; i < cycles; i++) {
            get_rb(i,&t);
         }
         res[1] = (double)(clock() - start)/CLOCKS_PER_SEC;

         printf("Binary Search Tree (Queries)   :");
         if (res[0] > res[1]) printf("\033[31m"); else printf("\033[32m");
         printf(" %f\033[0m\n",res[0]);
         printf("Red Black Tree     (Queries)   :"); 
         if (res[1] > res[0]) printf("\033[31m"); else printf("\033[32m");
         printf(" %f\033[0m\n",res[1]);

         start = clock();
         for (int i = 0; i < cycles; i++) {
            delete_bs(i,&s);
         }
         res[0] = (double)(clock() - start)/CLOCKS_PER_SEC;

         start = clock();
         for (int i = 0; i < cycles; i++) {
            delete_rb(i,&t);
         }
         res[1] = (double)(clock() - start)/CLOCKS_PER_SEC;

         printf("Binary Search Tree (Deletes)   :");
         if (res[0] > res[1]) printf("\033[31m"); else printf("\033[32m");
         printf(" %f\033[0m\n",res[0]);
         printf("Red Black Tree     (Deletes)   :"); 
         if (res[1] > res[0]) printf("\033[31m"); else printf("\033[32m");
         printf(" %f\033[0m\n",res[1]);

      }

      free(elements);
      destroy_helper_rb(t.root);
      destroy_helper_bs(s.root);
      cycles *= 10;
   }

   }

   return 0;
}
