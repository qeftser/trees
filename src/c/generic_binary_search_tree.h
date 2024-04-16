
#ifndef GENERIC_BINARY_SEARCH_TREE

#define GENERIC_BINARY_SEARCH_TREE

struct gbs_node { void * key; void * val; struct gbs_node * l; struct gbs_node * r; };
struct gbs_tree { int size; struct gbs_node * root; 
                          int (* compar)(const void *, const void *); 
                          void (* release_key)(void *);
                          void (* release_val)(void *); };
/* 
 * compar is the key comparison function
 * release is the free function to call on
 * the key when removing it form the tree 
 */

void init_gbs(int (*)(const void *, const void *), void (*)(void *), void (*)(void *), struct gbs_tree *);
void insert_gbs(void *, void *, struct gbs_tree *);
void * get_gbs(void *, struct gbs_tree *);
void * delete_gbs(void *, struct gbs_tree *);
void destroy_helper_gbs(struct gbs_node *, struct gbs_tree *);
void destroy_gbs(struct gbs_tree *);

/* I would have to pass a print function for this */
/* void in_order_print_gbs(struct gbs_tree *); */

#endif
