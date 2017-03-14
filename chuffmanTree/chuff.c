/*************************************************************************
    > File Name: chuff.c
    > Author: WangMing
    > Mail: wangming_ch@126.com
    > Created Time: Tue 14 Mar 2017 04:29:12 PM CST
 ************************************************************************/

#include<stdio.h>

typedef unsigned int size_u32;

#define ASCII_N 127
#define NUM_CHAR (ASCII_N*2)

typedef struct node
{
	int	parrent;
	int lchild;
	int rchild;
	int weight;
	int ch;
} chuff_node;

chuff_node chuff[NUM_CHAR - 1];
size_u32 encode[1000];
char decode[1000];

void chuff_search(int m, int *l, int *r);

void chuff_create(void)
{
	int i, j, k;
	
	for (i = 0;i < ASCII_N;i++)
	{
		chuff[i].parrent = chuff[i].lchild = chuff[i].rchild = -1;
		chuff[i].weight = chuff[i].ch = i;
	}

	for (i = 0;i < ASCII_N - 1;i++)
	{
		chuff_search(i + ASCII_N, &j, &k);
		chuff[i + ASCII_N].lchild = j;
		chuff[i + ASCII_N].rchild = k;
		chuff[i + ASCII_N].weight = chuff[j].weight + chuff[k].weight;
		chuff[j].parrent = chuff[k].parrent = i + ASCII_N;
	}
}


void chuff_search(int m, int *l, int *r)
{
	int i, minl, minr;

	*l = 0;
	*r = 1;

	for (i = 0;i < m;++i)
	{
		minl = minr = 0xffffff;
		if (chuff[i].parrent == -1)
		{
			if (chuff[i].weight < minr)
			{
				minl = minr;
				minr = chuff[i].weight;
				*l = *r;
				*r = i;
			}
			else if (chuff[i].weight < minl)
			{
				minl = chuff[i].weight;
				*l = i;
			}
		}
	}

	printf("minl=%d, minr=%d, m=%d, ", *l, *r, m);
}


void chuff_encode(char ch, int *bit, int *code)
{
	int i, j, k = 0;
	for (i = 0;i < ASCII_N;i++)
	{
		if ((char)chuff[i].ch == ch)
			break;
	}

	do
	{
		if (chuff[chuff[i].parrent].lchild == i)
		{
			k |= ((~(-1) + 1) << j); 
		}

		i = chuff[i].parrent;
		j++;
	}while (chuff[i].parrent != -1);

	*bit = j;
	*code = k;
}

void chuff_decode(void)
{
	int i, j = 0, k = 0, m = 0;
	char ch;

	do
	{
		i = NUM_CHAR - 1;
		while (1)
		{
			if (i == -1)
			{
				break;
			}

			if (k > 31)
			{
				k = 0;
				j++;
			}

			ch = chuff[i].ch;
			if (encode[j] & (1 << k))
				i = chuff[i].lchild;
			else
				i = chuff[i].rchild;

			k++;
		}

		decode[m] = ch;

	}while (ch != '\0');
}

int main(void)
{
	char ch;	
	int bit = 0, code = 0, i, j = 0, k = 0, m = 0;

	chuff_create();

	for (i = 0;i < NUM_CHAR - 1;i++)
		printf("\"%c\", p=%d, l=%d, r=%d, w=%d, i = %d\n", chuff[i].ch, chuff[i].parrent, chuff[i].lchild, chuff[i].rchild, chuff[i].weight, i);

	printf("Please enter for encoding or enter q for quit:\n");

	while (1)
	{
		if ((ch = getchar()) == '\n')
			continue;
		else if (ch == 'q')
			break;

		do
		{
			m++;
			if (ch == '\n')
				ch = '\0';
			chuff_encode(ch, &bit, &code);
			for (i = 0, m = bit - 1;i < bit;i++,m--)
			{
				if (k >  31)
				{
					j++;
					k = 0;
				}
				encode[j] |= (((code >> m) & (~(-1) + 1)) << k);
				k++;
			}

			if (ch == '\0')
				break;
		}
		while ((ch = getchar()));

		printf("The encode is:\n");

		for (i = 0;i < m;i++)
			printf("0x%0x ", encode[i]);
		printf("\n");

		j = 0;
		k = 0;

		chuff_decode();
		printf("The decode is:\n");

		i = 0;
		while (ch = decode[i++])
		{
			printf("0x%0x ", ch);
		}
		printf("\n");
	}

	return 0;
}


