
#include"../inc/qgsort.h"


/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(long *a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = a[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (k >= a[i-1])
				break;
			if (k >= a[j])
			{
				a[j + 1] = k;
				break;
			}
			else
			{
				a[j + 1] = a[j];
				if (j == 0)
					a[j] = k;
			}
		}
	}
}

/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(long *a, int begin, int mid, int end, long *temp)
{
	//将数组分成两个部分
	int index = begin;
	int i = begin, j = mid+1;
	while (i <= mid&&j <= end)
	{
		if (a[i] < a[j])
			temp[index++] = a[i++];
		else
			temp[index++] = a[j++];
	}

	while (i<=mid)
	{
		temp[index++] = a[i++];
	}

	while (j <= end)
	{
		temp[index++] = a[j++];
	}
	for (i = begin; i <= end; i++)
		a[i] = temp[i];
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(long *a, int begin, int end, long *temp)
{
	if (begin >= end)
		return;
	//找到中间位置
	int mid = (begin + end) / 2;
	MergeSort(a, begin, mid, temp);
	MergeSort(a, mid+1, end, temp);
	MergeArray(a, begin, mid, end, temp);
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(long *a, int begin, int end)
{
	int pos;
	if (begin < end)
	{
		pos = Partition(a, begin, end);
		QuickSort_Recursion(a, begin, pos - 1);
		QuickSort_Recursion(a, pos + 1, end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(long *a, int size)
{
    int begin = 0;
    int end = size;
    Stack *s;
    s=(Stack *)malloc(sizeof(Stack));
    initStack(s,10000);
    pushStack(s,begin);
    pushStack(s,end);
    while(!isEmptyStack(s))
    {
        popStack(s,&end);
        popStack(s,&begin);
        int index = Partition(a, begin, end);
        if (index - 1 > begin)
        {
            pushStack(s, begin);
            pushStack(s,index-1);
        }
        if (index + 1 < end)
        {
            pushStack(s, index+1);
            pushStack(s,end);
        }
    }
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(long *a, int begin, int end)
{
	int t = a[begin];
	while (begin < end)
	{
		while (begin < end&&a[end] >= t)
			end--;
		a[begin] = a[end];
		while (begin < end&&a[begin] <= t)
			begin++;
		a[end] = a[begin];
	}
	a[begin] = t;
	return begin;
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(long *a, int size, int max)
{
    int count=0;
    int min=FindExtreme(a,size,MIN);
    int range=max-min+1;
    long * temp=(long*)malloc(sizeof(long)*range);
     if (temp == NULL)
        return;
    memset(temp,0,sizeof(long)*range);
    for(int i=0;i<size;i++)
    {
        temp[a[i]-min]++;
    }
    for(int i=0;i<range;i++)
    {
        while(temp[i]--)
        {
            a[count++]=i+min;
        }
    }
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(long *a, int size)
{
	long *temp[10];
	for (int i = 0; i < 10; i++)
	{
		temp[i] = (long *)malloc(sizeof(long) * (size + 1));
		temp[i][0] = 0;
	}

	for (int pos = 1; pos <= 6; pos++)
	{
		for (int i = 0; i < size; i++)
		{
			int num = GetNumInPos(a[i], pos);
			int index = ++temp[num][0];
			temp[num][index] = a[i];
		}

		for (int i = 0, j = 0; i < 10; i++)
		{
			for (int k = 1; k <= temp[i][0]; k++)
				a[j++] = temp[i][k];
			temp[i][0] = 0;
		}
	}
}

int GetNumInPos(long num, int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;

	return (num / temp) % 10;
}
void PrintArray(long *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%ld\t", a[i]);
		if (i!=0 && i % 15 == 0)
			printf("\n");
	}
	printf("\n");
}

long FindExtreme(long *a,int size,int type)
{
	long extreme = a[0];
	for (int i = 0; i < size; i++)
	{
		if (type == MAX && a[i] > extreme)
			extreme = a[i];
		else if (type == MIN && a[i] < extreme)
			extreme = a[i];
	}
	return extreme;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(long *a, int size)
{
	int i, p1=0, p2=size;
	for (i = 0; i < p2; i++)
	{
		if (a[i] == 0)
		{
			swap(&a[i], &a[p1]);
			p1++;
		}
		else if (a[i] == 2)
		{
			p2--;
			swap(&a[i], &a[p2]);
			i--;
		}
	}
}

void swap(long *a,long *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大的数
 *  @param       : 数组指针a，数组长度size
 */
int FindData(long *a, int size)
{
	int n;
	int begin = 0;
	int end = size;
	printf("你想查第几小的数？");
	inputCheck(&n);
	while(n<1||n>10000)
    {
        printf("输入错误！请在有效范围内输入：");
        inputCheck(&n);
    }
	while (1)
	{
		int pos = Partition(a, begin, end);
		if (pos + 1 == n)
			return a[n-1];
		else if (pos + 1 > n)
			end = pos - 1;
		else
			begin = pos + 1;
	}
}

void inputCheck(int *val)
{
	char n[50] = { 0 };
	int i = 0, flag = 0, minus = 0;
	scanf("%s", n);
	getchar();
	for (int j = 0; n[j] != '\0'; j++)
	{
		if (n[j] < '0' || n[j] > '9')
			flag = 1;
	}
	if(flag == 1)
	{
		printf("\n输入错误！请重新输入:");
		inputCheck(val);
	}
	int temp = 0;
	for (int j = 0; n[j] != '\0'; j++)
		temp = temp * 10 + (n[j] - 48);
	*val = temp;
}


void Catalogue(long *a,int size)
{
	while (1)
	{


		int i;
		printf("\n\n*********************************************************************************************************\n");
		printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
		printf("****************************数 据 结 构 之 排 序 算 法 程 序 设 计***************************************\n");
		printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
		printf("********************************作者：黄煜淇(3118004962) 软工一班****************************************\n");
		printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
		printf("*\t\t\t\t         1.  插入排序                \t\t\t\t\t\t*\n");
		printf("*\t\t\t\t         2.  归并排序                \t\t\t\t\t\t*\n");
		printf("*\t\t\t\t         3.  快速排序(递归版)        \t\t\t\t\t\t*\n");
		printf("*\t\t\t\t         4.  快速排序(非递归版)      \t\t\t\t\t\t*\n");;
		printf("*\t\t\t\t         5.  计数排序                \t\t\t\t\t\t*\n");
		printf("*\t\t\t\t         6.  基数排序                \t\t\t\t\t\t*\n");
		printf("*\t\t\t\t         7.  颜色排序                \t\t\t\t\t\t*\n");
		printf("*\t\t\t\t         8.  找到第K值               \t\t\t\t\t\t*\n");
		printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
		printf("*********************************************************************************************************\n");
		SelectOpe(a, size);
		printf("\n\n你想继续吗?(1：继续/  其他： 退出)");
		inputCheck(&i);
		if (i != 1)
			break;
	}
}

void SelectOpe(long *a, int size)
{
	int n;
	printf("\n你想执行那个操作 ?");
	inputCheck(&n);
	while (n < 0 || n > 8)
	{
		printf("\n输入错误！请重输：");
		inputCheck(&n);
	}
	switch (n)
	{
		case 1:insertSort(a,size);PrintArray(a,size); break;
		case 2:
		{
			int temp[10000];
			MergeSort(a, 0, size, temp);
			PrintArray(a,size);
			break;
		}
		case 3:
			QuickSort_Recursion(a, 0, size);
			PrintArray(a,size);
			break;
		case 4:
		{
            QuickSort(a, size);
            PrintArray(a,size);
			break;
		}
		case 5:
		{
			int max = FindExtreme(a, size, MAX);
			CountSort(a, size, max);
			PrintArray(a,size);
			break;
		}
		case 6:
		{
			RadixCountSort(a, size);
			PrintArray(a,size);
			break;
		}
		case 7:
		{
			long *temp = (long*)malloc(sizeof(long)*10000);
			for(int i=0;i<10000;i++)
			temp[i]=rand()%3;
			PrintArray(temp,size);
			printf("上面是刚刚生成的数组，按任意键开始颜色排序！\n");
			getchar();
			ColorSort(temp, size);
			PrintArray(temp,size);
			break;
		}
		case 8:
		{
            int t = FindData(a, size);
			printf("这个值是：%d\n", t);
			break;
		}
	}
}

void generate(long *a)
{
	printf("\n\n*********************************************************************************************************\n");
	printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
	printf("*\t\t\t\t         你想生成的数组的类型：      \t\t\t\t\t\t*\n");
	printf("*\t\t\t\t         使用系统自带数组：          \t\t\t\t\t\t*\n");
	printf("*\t\t\t\t 1. 0-10000   2. 0-50000  3.0-200000 \t\t\t\t\t\t*\n");
	printf("*\t\t\t\t         使用现场生成数组：          \t\t\t\t\t\t*\n");
	printf("*\t\t\t\t 4. 0-10000   5. 0-50000  6.0-200000 \t\t\t\t\t\t*\n");
	printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
	printf("*********************************************************************************************************\n");
	int n;
	inputCheck(&n);
	while(n<1||n>6)
    {
        printf("输入错误！请重输:");
        inputCheck(&n);
    }
	FILE *fp;
	switch (n)
	{
	case 1: {
		if ((fp = fopen("FirstLayer.txt", "r")) == NULL)
		{
			printf("无法打开该文件！\n");
			exit(0);
		}
		for (int i = 0; i < 10000; i++)
		{
			fscanf(fp, "%ld\t", &a[i]);
		}
		fclose(fp);
		printf("导入成功！\n");
		break;
	}
	case 2: {
		if ((fp = fopen("SecendLayer.txt", "r")) == NULL)
		{
			printf("无法打开该文件！\n");
			exit(0);
		}
		for (int i = 0; i < 10000; i++)
		{
			fscanf(fp, "%ld\t", &a[i]);
		}
		fclose(fp);
		printf("导入成功！\n");
		break;
	}
	case 3: {
		if ((fp = fopen("ThirdLayer.txt", "r")) == NULL)
		{
			printf("无法打开该文件！\n");
			exit(0);
		}
		for (int i = 0; i < 10000; i++)
		{
			fscanf(fp, "%ld\t", &a[i]);
		}
		fclose(fp);
		printf("导入成功！\n");
		break;
	}
	case 4: {
		if ((fp = fopen("FirstLayer.txt", "w+")) == NULL)
		{
			printf("无法打开该文件！\n");
			exit(0);
		}
		for (int i = 0; i < 10000; i++)
		{
			a[i] = rand() % (10001);
			fprintf(fp, "%ld\t", a[i]);
			if (i != 0&&i % 9 == 0)
				fprintf(fp, "\n");
			printf("%ld\t", a[i]);
		}
		fclose(fp);
		printf("生成成功！\n");
		break;
	}
	case 5: {
		if ((fp = fopen("SecendLayer.txt", "w+")) == NULL)
		{
			printf("无法打开该文件！\n");
			exit(0);
		}
		for (int i = 0; i < 10000; i++)
		{
			a[i] = (rand() % 50001 )*1.526;
			fprintf(fp, "%ld\t", a[i]);
			if (i != 0 && i % 9 == 0)
				fprintf(fp, "\n");
			printf("%ld\t", a[i]);
		}
		fclose(fp);
		printf("生成成功！\n");
		break;
	}
	case 6: {
		if ((fp = fopen("ThirdLayer.txt", "w+")) == NULL)
		{
			printf("无法打开该文件！\n");
			exit(0);
		}
		for (int i = 0; i < 10000; i++)
		{
			a[i] = (rand() % 50001)*6.1038;
			fprintf(fp, "%ld\t", a[i]);
			if (i != 0 && i % 9 == 0)
				fprintf(fp, "\n");
			printf("%ld\t", a[i]);
		}
		fclose(fp);
		printf("生成成功！\n");
		break;
	}
	}
}

Status initStack(Stack *s,int sizes)  //初始化栈
{
        s->data=( int * )malloc( sizes * sizeof(int));
        if(NULL==s->data)
            return ERROR;
        s->top=-1;
        s->size = sizes;
        return SUCCESS;
}


Status isEmptyStack(Stack *s)   //判断栈是否为空
{
    if(s->top<0)
    {
        return SUCCESS;
    }
    else
    {
        return ERROR;
    }
}
Status getTopStack(Stack *s,int *e)   //得到栈顶元素
{
    if(isEmptyStack(s)||s->data[s->top])
    {
        return ERROR;
    }
    else
    {
        e=s->data;
    }

    return SUCCESS;
}

Status pushStack(Stack *s,int data)  //入栈
{
    if(s==NULL||s->top>=s->size-1)
    {
        return ERROR;
    }
    s->top++;
    s->data[s->top]=data;
    return SUCCESS;
}
Status popStack(Stack *s,int *data)   //出栈
{
    if(s==NULL||isEmptyStack(s))
    {
        return ERROR;
    }
    *data=s->data[s->top];
    s->top--;
    return SUCCESS;
}
