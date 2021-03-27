#include <stdio.h>

typedef struct LNode *List;
struct LNode {
	ElementType Data[MAXSIZE];
	int Last;  //�������һ��Ԫ�ص��±�
};

//���Ա�ĳ���Last + 1

//��ʼ���������յ�˳���)
List MakeEmpty()
{
	List Ptrl;
	Ptrl = (List)malloc(sizeof(LNode));
	Ptrl->Last = -1;  //�������һ��Ԫ��
	return Ptrl;
}

//����
int Find(ElementType X, List Ptrl) {
	int i = 0;
	while (i <= Ptrl->Last && Ptrl->Data[i] != X) //�˳�whileѭ�����������������������ж���������������˳�
		i++;
	if (i > Ptrl->Last) return -1;
	else return i;
}

//���루��i(1 <= i <= n+1)��λ��(��ȷ��λ�ã������±�)����һ��ֵΪX����Ԫ��) n��ʾ���Ա�ĳ���
void Insert(ElementType X, int i, List Ptrl) {
	int j;
	if (Ptrl->Last == MAXSIZE - 1) {  
		printf("������\n");
		return;
	}
	if (i < 1 || i > Ptrl->Last + 2) {
		printf("����λ�ò��Ϸ���\n");
		return;
	}
	for (j = Ptrl->Last; j >= i - 1; j--)   //��ΪҪ�ŵ����Ա���i-1��λ�ã��±�Ϊi-1��ʵ�����ǵ�i��Ԫ��
		Ptrl->Data[j + 1] = Ptrl->Data[j];
	Ptrl->Data[i - 1] = X;
	Ptrl->Last++;
	return;
}

//ɾ��
void Delete(int i, List Ptrl) {
	int j;
	if (Ptrl->Last == -1) {
		printf("���,��Ԫ�ؿ�ɾ����");
		return;
	}
	if (i < 1 || i > Ptrl->Last + 1) {
		printf("ɾ��Ԫ���±겻�Ϸ�!");
		return;
	}
	for (j = i - 1; j <= Ptrl->Last; j++)      //for( j = i ;i <= Ptrl->Last;j++
		Ptrl->Data[j] = Ptrl->Data[j + 1];			//Ptrl->Data[j - 1] = Ptrl->Data[j];
	
	Ptrl->Last--;
	return; 
}

//���
void Show(List Ptrl) {
	int i;
	for (i = 0; i <= Ptrl->Last; i++) {
		printf("%d\t", Ptrl->Data[i]);
	}
}

