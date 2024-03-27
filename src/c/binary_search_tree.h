
#ifndef BINARY_SEARCH_TREE

#define BINARY_SEARCH_TREE

struct bs_node { int key; int val; struct bs_node * l; struct bs_node * r; };
struct bs_tree { int size; struct bs_node * root; };

void init_bs(struct bs_tree *);
void insert_bs(int, int, struct bs_tree *);
int get_bs(int, struct bs_tree *);
int delete_bs(int, struct bs_tree *);
void destroy_bs(struct bs_tree *);
void destroy_helper_bs(struct bs_node *);

void in_order_print_bs(struct bs_tree *);

#endif
