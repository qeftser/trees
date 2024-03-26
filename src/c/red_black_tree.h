
#ifndef RED_BLACK_TREE

#define RED_BLACK_TREE
/* i will change the color representation later - maybe */
struct rb_node { int color; int key; int val; struct rb_node *l; struct rb_node *r; struct rb_node *p; };
struct rb_tree { int size; struct rb_node * root; struct rb_node * nil; };


void init_rb(struct rb_tree *);
void insert_rb(int, int, struct rb_tree *);
int get_rb(int, struct rb_tree *);
int delete_rb(int, struct rb_tree *);
void destroy_helper_rb(struct rb_node *);
void destroy_rb(struct rb_tree *);

void left_rotate(struct rb_node *, struct rb_tree *);
void rght_rotate(struct rb_node *, struct rb_tree *);
void transplant(struct rb_node *, struct rb_node *, struct rb_tree *);
struct rb_node * minimum(struct rb_node * x);
struct rb_node * maximum(struct rb_node * x);

void in_order_print_rb(struct rb_tree *);

#endif
