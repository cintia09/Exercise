/*************************************************************************
    > File Name: chuff.c
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Tue 14 Mar 2017 04:29:12 PM CST
 ************************************************************************/

#include<stdio.h>

typedef struct node
{
	struct node *parrent;
	struct node *lchild;
	struct node *rchild;
	unsigned int weight;
	unsigned int value;
} chuff_node;



void chuff_select()
{
}
