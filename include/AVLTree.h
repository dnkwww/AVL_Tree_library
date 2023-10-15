#ifndef __AVLTREE_H__
#define __AVLTREE_H__

typedef struct avl_node
{
	struct avl_node *left;
    struct avl_node *right;
	int height; // tree height
} avl_node_t; //avl tree root

avl_node_t * insert(void * element, avl_node_t * root, int (*compare)(void * elementA, void * elementB));
avl_node_t * delete(void * element, avl_node_t * root, int (*compare)(void * elementA, void * elementB));
avl_node_t * find(void * element, avl_node_t * root, int (*compare)(void * elementA, void * elementB));


static avl_node_t *rotateright(avl_node_t *);
static avl_node_t *rotateleft(avl_node_t *);
static avl_node_t *RR(avl_node_t *);
static avl_node_t *LL(avl_node_t *);
static avl_node_t *LR(avl_node_t *);
static avl_node_t *RL(avl_node_t *);
static int max(int a, int b);
static int height( avl_node_t *);
static int balanceFactor(avl_node_t *);
static avl_node_t * findMinNode(avl_node_t *);
static void updateNodeHeight(avl_node_t *);
static avl_node_t * updateTreeBalance(avl_node_t *);
void preOrder(avl_node_t *root, void (*print)(void *element));
void inOrder(avl_node_t *root, void (*print)(void *element));

#endif // AVLTREE_H_INCLUDED
