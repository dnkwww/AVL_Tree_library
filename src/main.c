#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AVLTree.h"

// 資料節點
typedef struct myElement
{
    avl_node_t treeNode;
    char ID[10];
    int math;
    int eng;
} student_t;

// 用來比較節點的function
int compareID(void *elementA, void *elementB)
{
    int i;
    int aid = ((student_t *)elementA)->math;
    int bid = ((student_t *)elementB)->math;
    if(aid>bid)
    {
        return 1;
    }
    else if(aid<bid)
    {
        return -1;
    }
    return 0;
}

// 用來將結點印出的function
void print(void *element)
{
    student_t *cur = (student_t *)element;
    printf("ID = %s, math=%d, eng=%d\n", cur->ID, cur->math, cur->eng);
}


int main()
{
    avl_node_t *treeRoot = NULL;

    // 宣告資料節點1
    student_t *node1 = (student_t *)malloc(sizeof(student_t));
    strcpy(node1->ID, "C120308001");
    node1->math = 90;
    node1->eng = 100;
    node1->treeNode.left = NULL;
    node1->treeNode.right = NULL;
    treeRoot = insert(node1, treeRoot, compareID); // 插入進去樹裡

    // 資料節點2
    student_t *node2 = (student_t *)malloc(sizeof(student_t));
    strcpy(node2->ID, "B220406001");
    node2->math = 80;
    node2->eng = 90;
    node2->treeNode.left = NULL;
    node2->treeNode.right = NULL;
    treeRoot = insert(node2, treeRoot, compareID);

    // 資料節點3
    student_t *node3 = (student_t *)malloc(sizeof(student_t));
    strcpy(node3->ID, "D120306001");
    node3->math = 70;
    node3->eng = 95;
    node3->treeNode.left = NULL;
    node3->treeNode.right = NULL;
    treeRoot = insert(node3, treeRoot, compareID);

    // 資料節點4
    student_t *node4 = (student_t *)malloc(sizeof(student_t));
    strcpy(node4->ID, "A220407001");
    node4->math = 60;
    node4->eng = 90;
    node4->treeNode.left = NULL;
    node4->treeNode.right = NULL;
    treeRoot = insert(node4, treeRoot, compareID);

    // 資料節點5
    student_t *node5 = (student_t *)malloc(sizeof(student_t));
    strcpy(node5->ID, "D220506001");
    node5->math = 65;
    node5->eng = 70;
    node5->treeNode.left = NULL;
    node5->treeNode.right = NULL;
    treeRoot = insert(node5, treeRoot, compareID);

    // 資料節點6
    student_t *node6 = (student_t *)malloc(sizeof(student_t));
    strcpy(node6->ID, "A120406001");
    node6->math = 67;
    node6->eng = 90;
    node6->treeNode.left = NULL;
    node6->treeNode.right = NULL;
    treeRoot = insert(node6, treeRoot, compareID);

    printf("\npre order:\n");
    preOrder(treeRoot, print);

    printf("\nIn order:\n");
    inOrder(treeRoot, print);

    free(node1);
    free(node2);
    free(node3);
    free(node4);
    free(node5);
    free(node6);

    return 0;
}
