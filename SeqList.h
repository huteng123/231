
typedef struct
{
	DataType list[MaxSize] ;
	int size ;
}SeqList;

void ListInitiate(SeqList *L)    /* 初始化顺序表L*/
{
	L->size = 0;
}

/*********************************************
* 函数作用：求当前元素个数
**********************************************/
int ListLength(SeqList L)       /* 返回顺序表L的当前数据元素个数*/
{
	return L.size;
}

/*********************************************
* 函数作用：插入数据元素
**********************************************/
int ListInsert(SeqList *L, int i, DataType x)
/* 在顺序表L的第i(0 <= i = size)个位置前插入数据元素值x*/
/* 插入成功返回1，插入失败返回0*/
{
	int j;
	//cout<<i<<"应有的数字"<<endl;
	if(L->size >= MaxSize)
	{
		printf("顺序表已满无法插入!\n");
		return 0;
	}
	else if(i < 0 || i > L->size)
	{
		printf("参数i不合法!\n");
		return 0;
	}
	else
	{
		/*为插入做准备*/
		for(j = L->size; j > i; j--)
				L->list[j] = L->list[j-1];
		
		L->list[i] = x;
		//cout<<x<<" ";
		//cout<<x<<"hao"<<endl;
		L->size++;   	//元素个数加1
		//cout<<L->size<<" ";
		return 1;		
	}
}

/*********************************************
* 函数作用：删除数据元素
**********************************************/
int ListDelete(SeqList *L, int i, DataType *x)
/*删除顺序表L中位置为i的数据元素并存放到x中*/
/*删除成功返回1，失败返回0*/
{
	int j;
	if(L->size <= 0)
	{
		printf("顺序表已空无数据元素可删!\n");
		return 0;
	}
	else if(i < 0 || i > L->size-1 )
	{
		printf("参数i不合法!\n");
		return 0 ;
	}
	else
	{
		*x = L->list[i];  /*保存删除的元素到x中*/
		/*依次前移*/
		for(j = i+1; j <= L->size-1; j++)
			L->list[j-1] = L->list[j];
		L->size--;        //元素个数减1
		return 1;
	}
}

/*********************************************
* 函数作用：取数据元素
**********************************************/
int ListGet(SeqList L, int i, DataType *x)
/*取顺序表L中第i个数据元素存于x中，成功返回1，失败返回0*/
{
	if(i < 0 || i > L.size-1)
	{
		printf("参数i不合法!\n");
		return 0;
	}
	else
	{
		*x = L.list[i];
		return 1;
	}
}

