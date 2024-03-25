
#ifndef RED_BLACK_TREE

#define RED_BLACK_TREE
struct rb_node { int key; int val; struct rb_node *l; struct rb_node *r; struct rb_node *p; };
struct rb_tree { int size; struct rb_node * root; struct rb_node * nil; };


void init_rb(struct rb_tree *);
void insert_rb(int key, int val, struct rb_tree *);
int get_rb(int key, struct rb_tree *);
int remove_rb(int key, struct rb_tree *);
void destroy_rb(struct rb_tree *);

void left_rotate(struct rb_node * x, struct rb_tree * t);
void rght_rotate(struct rb_node * y, struct rb_tree * t);
void transplant(struct rb_node * x, struct rb_node * y);
struct rb_node * minimum(struct rb_node * x);
struct rb_node * maximum(struct rb_node * x);

void in_order_print_rb(struct rb_tree *);

#endif
