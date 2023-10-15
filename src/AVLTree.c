#include "AVLTree.h"
#include <stdio.h>
#include <stdlib.h>

avl_node_t * insert(void * element, avl_node_t * root, int (*compare)(void * elementA, void * elementB))  //插入值
{
    if (root == NULL) //在BST新增一個節點（原先此樹可能是空的，或是已經到達枝葉位置），回傳節點位置
    {
        root = (avl_node_t*)element;
    }
    else if(compare(element,root) == 1) // element > root，向樹的右邊搜尋
    {
        root -> right = insert(element,root -> right,compare);

        if (balanceFactor(root) == -2)
        {
            if (compare(element,root->right))
            {
                root = rotateleft(root);
            }
            else
            {
                root -> right = rotateright(root -> right);
                root = rotateleft(root);
            }
        }
    }
    else if(compare(element,root) == -1) // element < root，向樹的左邊搜尋
    {
        root -> left = insert(element,root -> left,compare);

        if (balanceFactor(root) == 2)
        {
            if (compare(element,root->left))
            {
                root = rotateright(root);
            }
            else
            {
                root -> left = rotateleft(root -> left);
                root = rotateright(root);
            }
        }
    }

    root -> height = height(root);
    return root;

}
avl_node_t * delete(void * element, avl_node_t * root, int (*compare)(void * elementA, void * elementB))  //刪除值
{
    avl_node_t * temp;
    if(root == NULL) // 此樹可能是空的，或是直至枝葉位置都搜尋不到該筆資料，直接回傳root（NULL）
        return NULL;
    else if(compare(element,root) == 1) // element > root，向樹的右邊搜尋
    {
        root -> right = delete(element,root -> right, compare);
        if (balanceFactor(root) == 2)
        {
            if (balanceFactor(root -> left) >= 0)
            {
                root = rotateright(root);
            }
            else
            {
                root -> left = rotateleft(root -> left);
                root = rotateright(root);
            }
        }

    }
    else if(compare(element,root) == -1) // element < root，向樹的左邊搜尋
    {
        root -> left = delete(element,root -> left, compare);
        if (balanceFactor(root) == -2)
        {
            if (balanceFactor(root->right) <= 0)
            {
                root = rotateleft(root);
            }
            else
            {
                root -> right = rotateright(root -> right);
                root = rotateleft(root);
            }
        }
    }
    else if(compare(element,root) == 0) // 找到element的位置
    {
        if(root -> left == NULL)  // 如果不存在左子樹，刪右子
        {
            temp = root;
            root = root -> right;
            free(temp);
        }
        else if(root -> right ==NULL) // 如果不存在右子樹，刪左子
        {
            temp = root;
            root = root -> left;
            free(temp);
        }
        if (balanceFactor(root) == 2)
        {
            if (balanceFactor(root -> left) >= 0)
            {
                root = rotateright(root);
            }
            else
            {
                root -> left = rotateleft(root->left);
                root = rotateright(root);
            }
        }
    }
    else
    {
        return (root -> left);
    }

    root-> height = height(root);
    return root;


}
avl_node_t* find(void * element, avl_node_t * root, int(*compare)(void * elementA, void * elementB))
{
    if(root == NULL) //此樹可能是空的，或是直至枝葉位置都搜尋不到該筆資料，直接回傳root（NULL）
    {
    }
    else
    {
        if(compare(element, root) == -1) //element < root，向樹的左邊搜尋
        {
            root->left = find(element, root->left, compare);
        }
        else if(compare(element, root) == 1) //element > root，向樹的右邊搜尋
        {
            root->right = find(element, root->right, compare);
        }
    } //element == root時表示找到該筆資料，回傳節點位置
    return root;
}

static avl_node_t *rotateright(avl_node_t *root)
{
    avl_node_t* left_child = root -> left;
    root -> left = left_child -> right;
    left_child -> right = root;

    root -> height = height(root);
    left_child -> height = height(left_child);

    return left_child;

}
static avl_node_t *rotateleft(avl_node_t *root)
{
    avl_node_t* right_child = root -> right;
    root -> right = right_child -> left;
    right_child -> left = root;

    root -> height = height(root);
    right_child -> height = height(right_child);

    return right_child;

}
static avl_node_t *RR(avl_node_t *root)
{
    avl_node_t *temp,*pivot,*pivot_next,*pivot_prev;
    pivot_next = pivot -> right;
    temp = pivot_next -> left;
    pivot_next -> left = pivot;
    pivot -> right = temp;

    if(pivot == root)
        root =  pivot_next;
    else if(pivot_prev -> left == pivot)
        pivot_prev -> left = pivot_next;
    else
        pivot_prev -> right = pivot_next;

}
static avl_node_t *LL(avl_node_t *root)
{
    avl_node_t *temp,*pivot,*pivot_next,*pivot_prev;

    pivot_next = pivot -> left;
    temp = pivot_next -> right;
    pivot_next -> right = pivot;
    pivot -> left = temp;

    if(pivot == root)
        root =  pivot_next;
    else if(pivot_prev -> left == pivot)
        pivot_prev -> left = pivot_next;
    else
        pivot_prev -> right = pivot_next;
}
static avl_node_t *LR(avl_node_t *root)
{
    avl_node_t *temp,*pivot,*pivot_next,*pivot_prev;
    pivot_next = pivot -> left;
    temp = pivot_next -> right;
    pivot -> left = temp -> right;
    pivot_next -> right = temp -> left;
    temp -> left = pivot_next;
    temp -> right = pivot;


    if(pivot == root)
        root =  temp;
    else if(pivot_prev -> left == pivot)
        pivot_prev -> left = temp;
    else
        pivot_prev -> right = temp;


}
static avl_node_t *RL(avl_node_t *root)
{
    avl_node_t *temp,*pivot,*pivot_next,*pivot_prev;
    pivot_next = pivot -> right;
    temp = pivot_next -> left;
    pivot -> right = temp -> left;
    pivot_next -> left = temp -> right;
    temp -> right = pivot_next;
    temp -> left = pivot;

    if(pivot == root)
        root =  temp;
    else if(pivot_prev -> left == pivot)
        pivot_prev -> left = temp;
    else
        pivot_prev -> right = temp;

}
static int height(avl_node_t *root)  // calculate the height of the node
{
    int lheight, rheight;
    if (root == NULL)
    {
        return 0;
    }
    if (root -> left == NULL)
        lheight = 0;
    else
        lheight = 1 + root -> left -> height;
    if (root -> right == NULL)
        rheight = 0;
    else
        rheight = 1 + root -> right -> height;

    if (lheight > rheight)
        return lheight;
    return rheight;
}
static int balanceFactor(avl_node_t *root)  // calculates the balance factor of a node
{
    int lheight, rheight;
    if (root == NULL)
        return 0;
    if (root -> left == NULL)
        lheight = 0;
    else
        lheight = 1 + root -> left -> height;
    if (root -> right == NULL)
        rheight = 0;
    else
        rheight = 1 + root -> right -> height;
    return lheight - rheight;

}

void preOrder(avl_node_t *root, void (*print)(void *element))
{
    if(root != NULL)
    {
        print(root);
        preOrder(root->left, print);
        preOrder(root->right, print);
    }
}

void inOrder(avl_node_t *root, void (*print)(void *element)) //列印出BST根據中序追蹤法每個節點內容
{
    if(root)
    {
        inOrder(root->left, print);
        print(root);
        inOrder(root->right, print);
    }
}
