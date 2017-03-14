/*************************************************************************
    > File Name: chuff.c
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Tue 14 Mar 2017 04:29:12 PM CST
 ************************************************************************/

#include<stdio.h>

typedef unsigned int size_u32;
typedef ASCII_N 127


typedef struct node
{
	struct node *parrent;
	struct node *lchild;
	struct node *rchild;
	struct node *next;
	unsigned int weight;
	unsigned int value;
} chuff_node, *chuff_p;

chuff_p chuffTree, chuffTail;

int chuff_create(chuff_p chuff_tree, chuff_p chuff_tail)
{
	size_u32 ch[30];
	chuff_p p;
	size_u32 i;
	
	p = malloc(sizeof(struct node));
	chuff_tree = p;
	p->weight = 0;
	p->parrent = p->lchild = p->rchild = p->next = NULL;
	p->value = '\0';

	for (i = 0;i < ASCII_N - 1;i++)
	{
		p->next = malloc(sizeof(struct node));
		p->weight = 0;
		p->parrent = p->lchild = p->rchild = p->next = NULL;
		p->value = i +1;
		p = p->next;
	}

	chuff_tail = p;
	return 0;
}

int chuff_create(chuff_p chuff_tree, chuff_p chuff_tail)
{
	size_u32 ch;


}

void chuff_select(chuff_p chuff_tree, size_u32 k, chuff_p lchild, chuff_p rchild)
{
	size_u32 i, min = 0;
	for (i = 0;i < k;++i)
	{
		if (chuff_tree)
	}
}



