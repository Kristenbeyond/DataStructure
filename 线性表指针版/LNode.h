#include <stdio.h>

typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	int Last;  //代表最后一个元素的下标
};

//线性表的长度Last + 1

//初始化（建立空的顺序表)
List MakeEmpty()
{
	List Ptrl;
	Ptrl = (List)malloc(sizeof(LNode));
	Ptrl->Last = -1;  //代表最后一个元素
	return Ptrl;
}

//查找
int Find(ElementType X, List Ptrl) {
	int i = 0;
	while (i <= Ptrl->Last && Ptrl->Data[i] != X) //退出while循环有两种情况，在下面进行判断是哪种情况导致退出
		i++;
	if (i > Ptrl->Last) return -1;
	else return i;
}

//插入（第i(1 <= i <= n+1)个位置(是确切位置，不是下标)插入一个值为X的新元素) n表示线性表的长度
void Insert(ElementType X, int i, List Ptrl) {
	int j;
	if (Ptrl->Last == MAXSIZE - 1) {  
		printf("表满！\n");
		return;
	}
	if (i < 1 || i > Ptrl->Last + 2) {
		printf("插入位置不合法！\n");
		return;
	}
	for (j = Ptrl->Last; j >= i - 1; j--)   //因为要放到线性表中i-1的位置，下标为i-1，实际上是第i个元素
		Ptrl->Data[j + 1] = Ptrl->Data[j];
	Ptrl->Data[i - 1] = X;
	Ptrl->Last++;
	return;
}

//删除
void Delete(int i, List Ptrl) {
	int j;
	if (Ptrl->Last == -1) {
		printf("表空,无元素可删除！");
		return;
	}
	if (i < 1 || i > Ptrl->Last + 1) {
		printf("删除元素下标不合法!");
		return;
	}
	for (j = i - 1; j <= Ptrl->Last; j++)      //for( j = i ;i <= Ptrl->Last;j++
		Ptrl->Data[j] = Ptrl->Data[j + 1];			//Ptrl->Data[j - 1] = Ptrl->Data[j];
	
	Ptrl->Last--;
	return; 
}

//输出
void Show(List Ptrl) {
	int i;
	for (i = 0; i <= Ptrl->Last; i++) {
		printf("%d\t", Ptrl->Data[i]);
	}
}

