#define MAXSIZE 100
typedef int ElementType;
#include <malloc.h>
#include "LNode.h"


int main()
{
	List mylist = MakeEmpty();

	int i = 1;

	for (i = 1; i < 10; i++)
		Insert(i, i, mylist);
		//Insert(i, i, mylist);
		//Insert(i+1, i+1, mylist); 
	//
	Show(mylist);
	printf("\n");
	Delete(3, mylist);
	printf("last = %d\n", mylist->Last);
	Show(mylist);
}