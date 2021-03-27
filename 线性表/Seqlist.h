typedef struct
{
	DataType list[MaxSize];
	int size;
}Seqlist;

void ListInitiate(Seqlist* L) //��ʼ��˳���L
{
	L->size = 0;
}

//��˳���L�ĵ�i(0 <= i <= size)��λ��ǰ��������Ԫ��ֵx
int ListInsert(Seqlist* L, int i, DataType x)  
{
	int j;
	if (L->size >= MaxSize)
	{
		printf("˳��������޷����룡");
		return 0;
	}
	else if (i < 0 || i > L->size)
	{
		printf("����i���Ϸ���\n");
		return 0;
	}
	else
	{
		//�Ӻ���ǰ���κ������ݣ�Ϊ������׼��
		for (j = L->size; j > i; j--)
		{
			L->list[j] = L->list[j - 1];  //f��j = i + 1ʱ,j - 1 = i,��i��λ��ͬ������
			//���ܿճ�i��λ�ã����ڲ���
		}
		L->list[i] = x;
		L->size++;
		return 1;
	}
}

//����˳�����Ԫ�ظ���
int ListLength(Seqlist L)
{
	return L.size;
}

//ɾ��˳���L�е�i(0 <= i <= size - 1)��λ�ô�������Ԫ�ز�������xz��
int ListDelete(Seqlist* L, int i, DataType* x)
{
	int j;
	if (L->size == 0)
	{
		printf("˳����ѿ������ݿ�ɾ����\n");
		return 0;
	}
	else if (i < 0 || i > L->size - 1)  //L->size-1Ϊ��ǰ���Ա����һ��Ԫ���±�
	{
		printf("����i���Ϸ�!!��\n");
		return 0;
	}
	else
	{
		*x = L->list[i];
		for (j = i + 1; j < L->size; j++)  //��ǰ�������ǰ��
		{
			L->list[j - 1] = L->list[j];
		}
		L->size--;
		return 1;
	}
}

//ȡ˳���L�е�i������Ԫ�ش���x��
int ListGet(Seqlist L, int i, DataType* x)
{
	if (i < 0 || i > L.size - 1)
	{
		printf("����i���Ϸ���!");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}