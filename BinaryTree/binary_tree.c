/*************************************************************************
    > File Name: binary_tree.c
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Thu 16 Mar 2017 04:38:03 PM CST
 ************************************************************************/

#include<stdio.h>

typedef struct Node
{
	struct Node *pre;
	struct Node *next;
} BtreeNode, * BtreeP;

BtreeP RootTree;


