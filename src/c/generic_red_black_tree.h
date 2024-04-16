
#ifndef GENERIC_RED_BLACK_TREE

#define GENERIC_RED_BLACK_TREE

struct grb_node { int color; void * key; void * val; struct grb_node *l; struct grb_node *r; struct grb_node *p; };
struct grb_tree { int size; struct grb_node * root; struct grb_node * nil;
                  int (* compar)(const void *, const void *); void (* release_key)(void *); void (*release_val)(void *); };

void init_grb(int (*)(const void *, const void *), void (*)(void *), void (*)(void *), struct grb_tree *); 
void insert_grb(void *, void *, struct grb_tree *);
void * get_grb(void *, struct grb_tree *);
void * delete_grb(void *, struct grb_tree *);
void destroy_helper_grb(struct grb_node *, struct grb_tree *);
void destroy_grb(struct grb_tree *);

#endif
