
#include"../inc/qgsort.h"


/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a, int n)
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
void MergeArray(int *a, int begin, int mid, int end, int  *temp)
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
void MergeSort(int  *a, int begin, int end, int  *temp)
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
void QuickSort_Recursion(int  *a, int begin, int end)
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
void QuickSort(int  *a, int size)
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
int Partition(int  *a, int begin, int end)
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
void CountSort(int  *a, int size, int max)
{
    int count=0;
    int min=FindExtreme(a,size,MIN);
    int range=max-min+1;
    int  * temp=(int *)malloc(sizeof(int)*range);
     if (temp == NULL)
        return;
    memset(temp,0,sizeof(int)*range);
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
void RadixCountSort(int  *a, int size)
{
	int  *temp[10];
	for (int i = 0; i < 10; i++)
	{
		temp[i] = (int  *)malloc(sizeof(int ) * (size + 1));
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

int GetNumInPos(int num, int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;

	return (num / temp) % 10;
}
void PrintArray(int  *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d\t", a[i]);
		if (i!=0 && i % 15 == 0)
			printf("\n");
	}
	printf("\n");
}

int  FindExtreme(int  *a,int size,int type)
{
	int  extreme = a[0];
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
void ColorSort(int  *a, int size)
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

void swap(int *a,int  *b)
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
int FindData(int  *a, int size)
{
	int n;
	int begin = 0;
	int end = size;
	printf("你想查第几小的数?");
	inputCheck(&n);
	while(n<1||n>10000)
    {
        printf("输入错误！请在有效范围内输入:");
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


void Catalogue(int  *a,int *b,int *c,int size1,int size2,int size3)
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
		SelectOpe(a,b,c,size1,size2,size3);
}

void SelectOpe(int  *a,int *b,int *c,int size1,int size2,int size3)
{
        int n, time;
        int start, finally;
        int temp[100];
        printf("\n你想执行那个操作 ?");
        inputCheck(&n);
        while (n < 0 || n > 8)
        {
            printf("\n输入错误！请重输:");
            inputCheck(&n);
        }
        switch (n)
        {
            case 1:{
                start = clock();
                insertSort(a,size1);
                finally = clock()-start;
                printf("%d位数字排序所用时间为%dms\n",size1+1,finally);
                start = clock();
                insertSort(b,size2);
                finally = clock()-start;
                printf("%d位数字排序所用时间为%dms\n",size2+1,finally);
                start = clock();
                insertSort(c,size3);
                finally = clock()-start;
                printf("%d位数字排序所用时间为%dms\n",size3+1,finally);
                start = clock();
                for(time = 0;time<100000;time++)
                {
                        randomArray(temp,100);
                        insertSort(temp, 99);
                }
                finally = clock()-start;
                printf("100*100k排序所用时间为%dms\n",finally);
                break;
                }
            case 2:
            {
                int *temp1 = (int*)malloc(sizeof(int)*10000);
                start = clock();
                MergeSort(a, 0, size1, temp1);
                finally = clock()-start;
                printf("%d位数字排序所用时间为%dms\n",size1+1,finally);
                int *temp2 = (int*)malloc(sizeof(int)*50000);
                start = clock();
                MergeSort(b,0,size2,temp2);
                finally = clock()-start;
                printf("%d位数字排序所用时间为%dms\n",size2+1,finally);
                int *temp3 = (int*)malloc(sizeof(int)*200000);
                start = clock();
                MergeSort(c, 0, size3, temp3);
                finally = clock()-start;
                printf("%d位数字排序所用时间为%dms\n",size3+1,finally);
                start = clock();
                for(time = 0;time<100000;time++)
                {
                        randomArray(temp,100);
                        MergeSort(temp, 0, 99, temp1);
                }
                finally = clock()-start;
                printf("100*100k排序所用时间为%dms\n",finally);
                free(temp1);
                free(temp2);
                free(temp3);
                break;
            }
            case 3:
            {
                start = clock();
                QuickSort_Recursion(a, 0, size1);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size1+1, finally);
                start = clock();
                QuickSort_Recursion(b, 0, size2);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size2+1, finally);
                start = clock();
                QuickSort_Recursion(c, 0, size3);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size3+1, finally);
                start = clock();
                for(time = 0;time<100000;time++)
                {
                        randomArray(temp,100);
                        QuickSort_Recursion(temp, 0 , 99);
                }
                finally = clock()-start;
                printf("100*100k排序所用时间为%dms\n",finally);
                break;
            }
            case 4:
            {
                start = clock();
                QuickSort(a, size1);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size1+1, finally);
                start = clock();
                QuickSort(b, size2);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size2+1, finally);
                start = clock();
                QuickSort(c, size3);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size3+1, finally);
                start = clock();
                for(time = 0;time<10000;time++)
                {
                        randomArray(temp,100);
                        QuickSort(temp, 99);
                }
                finally = clock()-start;
                printf("程序处理100*100k的数据会崩溃，所以这里只用了100*10k\n");
                printf("100*10k排序所用时间为%dms\n",finally);
                break;
            }
            case 5:
            {
                start = clock();
                int max = FindExtreme(a, size1, MAX);
                CountSort(a, size1, max);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size1+1, finally);
                start = clock();
                max = FindExtreme(b, size2, MAX);
                CountSort(b, size2, max);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size2+1, finally);
                start = clock();
                max = FindExtreme(c, size3, MAX);
                CountSort(c, size3, max);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size3+1, finally);
                start = clock();
                for(time = 0;time<100000;time++)
                {
                        randomArray(temp,100);
                        max = FindExtreme(temp,99,MAX);
                        CountSort(temp,99,max);
                }
                finally = clock()-start;
                printf("100*100k排序所用时间为%dms\n",finally);
                break;
            }
            case 6:
            {
                start = clock();
                RadixCountSort(a, size1);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size1+1, finally);
                start = clock();
                RadixCountSort(b, size2);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size2+1, finally);
                start = clock();
                RadixCountSort(c, size3);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size3+1, finally);
                start = clock();
                for(time = 0;time<100000;time++)
                {
                        randomArray(temp,100);
                        RadixCountSort(temp, 99);
                }
                finally = clock()-start;
                printf("100*100k排序所用时间为%dms\n",finally);
                break;
            }
            case 7:
            {
                int  *temp1 = (int *)malloc(sizeof(int)*10000);
                for(int i=0;i<10000;i++)
                temp1[i]=rand()%3;
                start = clock();
                ColorSort(temp1, size1);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size1+1, finally);
                int* temp2 = (int*)malloc(sizeof(int)*50000);
                for(int i=0;i<50000;i++)
                temp2[i]=rand()%3;
                start = clock();
                ColorSort(temp2, size2);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size2+1, finally);
                int* temp3 = (int*)malloc(sizeof(int)*200000);
                for(int i=0;i<200000;i++)
                temp3[i]=rand()%3;
                start = clock();
                ColorSort(temp3, size3);
                finally = clock()-start;
                printf("%d 位所用时间为%d ms\n", size3+1, finally);
                start = clock();
                for(time = 0;time<100000;time++)
                {
                        for(int i = 0; i<100;i++)
                            temp[i]=rand()%3;
                        ColorSort(temp, 99);
                }
                finally = clock()-start;
                printf("100*100k排序所用时间为%dms\n",finally);
                break;
            }
            case 8:
            {
                int t = FindData(a, size1);
                printf("%d位的这个值是：%d\n",t);
                t = FindData(b, size2);
                printf("%d位的这个值是：%d\n",t);
                t = FindData(c, size3);
                printf("%d位的这个值是：%d\n",t);
                break;
            }
        }
}

void generate(int  *a, int *b, int *c)
{
	while(1)
    {
        printf("\n\n*********************************************************************************************************\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("*\t\t\t\t         你想生成的数组的类型：      \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t       1.    使用系统自带数          \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t       2.    使用现场生成数组：      \t\t\t\t\t\t*\n");
        printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
        printf("*********************************************************************************************************\n");
        int n;
        inputCheck(&n);
        while(n<1||n>2)
        {
            printf("输入错误！请重输:");
            inputCheck(&n);
        }
        FILE *fp;
        switch (n)
        {
        case 1: {
            if ((fp = fopen("Output.txt", "r")) == NULL)
            {
                printf("无法打开该文件！\n");
                exit(0);
            }
            for (int i = 0; i < 10000; i++)
            {
                fscanf(fp, "%d\t", &a[i]);
            }
            for (int i = 0; i < 50000; i++)
            {
                fscanf(fp, "%d\t", &b[i]);
            }
            for (int i = 0; i < 200000; i++)
            {
                fscanf(fp, "%d\t", &c[i]);
            }
            fclose(fp);
            printf("导入成功！\n");
            break;
        }
        case 2: {
            if ((fp = fopen("Input.txt", "w+")) == NULL)
            {
                printf("无法打开该文件！\n");
                exit(0);
            }
            for (int i = 0; i < 10000; i++)
            {
                a[i] = rand();
                fprintf(fp, "%d\t", a[i]);
            }
            for (int i = 0; i < 50000; i++)
            {
                b[i] = rand();
                fprintf(fp, "%d\t", b[i]);
            }
            for (int i = 0; i < 200000; i++)
            {
                c[i] = rand();
                fprintf(fp, "%d\t", c[i]);
            }
            fclose(fp);
            printf("生成成功！\n");
            break;
        }
        }
    Catalogue(a,b,c,9999,49999,199999);
    printf("你想继续吗？\n");
    inputCheck(&n);
    if(n != 1)
    break;
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

void randomArray(int *temp,int size)
{
    for(int i = 0; i<size; i++)
        temp[i] = rand();
}
