
#ifndef AVL_SEARCH_TREE

#define AVL_SEARCH_TREE

struct avl_node { int diff; int key; int val; struct avl_node *l; struct avl_node *r; struct avl_node *p; };
struct avl_tree { int size; struct avl_node * root; };

void init_avl(struct avl_tree *);
void insert_avl(int, int, struct avl_tree *);
int get_avl(int, struct avl_tree *);
int delete_avl(int, struct avl_tree *);
void destroy_avl(struct avl_tree *);
void destroy_helper_avl(struct avl_node *);

void ll_rotate(struct avl_node *, struct avl_tree *);
void rr_rotate(struct avl_node *, struct avl_tree *);
void rl_rotate(struct avl_node *, struct avl_tree *);
void lr_rotate(struct avl_node *, struct avl_tree *);

void in_order_print_avl(struct avl_tree *);

#endif
