typedef struct
{
	DataType list[MaxSize];
	int size;
}Seqlist;

void ListInitiate(Seqlist* L) //初始化顺序表L
{
	L->size = 0;
}

//在顺序表L的第i(0 <= i <= size)个位置前插入数据元素值x
int ListInsert(Seqlist* L, int i, DataType x)  
{
	int j;
	if (L->size >= MaxSize)
	{
		printf("顺序表已满无法插入！");
		return 0;
	}
	else if (i < 0 || i > L->size)
	{
		printf("参数i不合法！\n");
		return 0;
	}
	else
	{
		//从后往前依次后移数据，为插入作准备
		for (j = L->size; j > i; j--)
		{
			L->list[j] = L->list[j - 1];  //f当j = i + 1时,j - 1 = i,将i的位置同样后移
			//才能空出i的位置，便于插入
		}
		L->list[i] = x;
		L->size++;
		return 1;
	}
}

//返回顺序表中元素个数
int ListLength(Seqlist L)
{
	return L.size;
}

//删除顺序表L中第i(0 <= i <= size - 1)个位置处的数据元素并保存在xz中
int ListDelete(Seqlist* L, int i, DataType* x)
{
	int j;
	if (L->size == 0)
	{
		printf("顺序表已空无数据可删除！\n");
		return 0;
	}
	else if (i < 0 || i > L->size - 1)  //L->size-1为当前线性表最后一个元素下标
	{
		printf("参数i不合法!!！\n");
		return 0;
	}
	else
	{
		*x = L->list[i];
		for (j = i + 1; j < L->size; j++)  //从前向后依次前移
		{
			L->list[j - 1] = L->list[j];
		}
		L->size--;
		return 1;
	}
}

//取顺序表L中第i个数据元素存于x中
int ListGet(Seqlist L, int i, DataType* x)
{
	if (i < 0 || i > L.size - 1)
	{
		printf("参数i不合法！!");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}