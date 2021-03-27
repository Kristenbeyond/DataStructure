#include <stdio.h>
#define MaxSize 100
typedef int DataType;
#include "Seqlist.h"

int main()
{
	Seqlist mylist;
	int i, x;

	ListInitiate(&mylist);
	for (i = 0; i < 10; i++) 
		ListInsert(&mylist, i, i + 1);

	for (i = 0; i < ListLength(mylist); i++)
	{
		ListGet(mylist, i, &x);
		printf("%d\t", x);
	}
	printf("\n");

	ListDelete(&mylist, 6, &x);

	for (i = 0; i < ListLength(mylist); i++)
	{
		ListGet(mylist, i ,&x);
		printf("%d\t",x);
	}
	return 0;
}