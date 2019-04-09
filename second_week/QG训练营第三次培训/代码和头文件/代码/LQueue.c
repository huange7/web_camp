#include"../head/LQueue.h"

void memu()//展示用户界面
{
    printf("\n\n*********************************************************************************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("****************************数 据 结 构 之 链 式 队 列 程 序 设 计**************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         1.  判断队列是否为空        \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         2.  得到队头元素            \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         3.  销毁队列                 \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         4.  确定队列长度              \t\t\t\t\t\t*\n");;
    printf("*\t\t\t\t         5.  清空队列              \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         6.  入队                    \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         7.  出队                    \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         8.  遍历队列                 \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*********************************************************************************************************\n");
}

void inputCheck(void *val ,int type)
{
        char n[50]={0};
        int i = 0, flag = 0, minus = 0;
        scanf("%s", n);
        getchar();
        if(strlen(n)>20)
                flag = 1;
        if(flag == 1)
        {
            printf("\n输入错误！请重新输入:");
            inputCheck(val, type);
            flag = 0;
        }
		if (type == INT)
		{
            if(strlen(n)>10)
                {
                    flag = 1;
                }
            for(int j = 0; n[j] != '\0'; j++)
                {
                    if((n[j] < '0'||n[j] > '9')&&(n[j] != '-'))
                        flag = 1;
                    if(n[j] == '-')
                        minus ++;
                }
            if(minus>1)
                flag = 1;
		}
		else if(type == CHAR)
        {
            if(strlen(n) > 1)
                flag = 1;
        }
        else if(type == DOUBLE)
        {
            int pointNum = 0;
            //用于计算字符串中的小数点数量
            for(int j = 0; n[j] != '\0';j++)
            {
                if(n[j] == '.')
                    pointNum++;
                if((n[j] < '0'||n[j] > '9')&&n[j]!='.'&&(n[j]== '-'&& j!=0 ))
                    flag = 1;
            }
        }
        if(flag == 1)
            {
                printf("\n输入错误！请重新输入:");
                inputCheck(val, type);
            }
		else
		{
			if (type == INT)
			{
				int temp = 0;
				//记录是否有负号
				int minus = 0;
				if(n[0] == '-')
                    minus = 1;
				for (int j = minus; n[j] != '\0'; j++)
					temp = temp*10 + (n[j] - 48);
                if(minus == 1)
                    temp*=(-1);
				memcpy(val, &temp, 4);
			}
			else if (type == DOUBLE)
			{
				double temp = 0;
				//记录小数点位置
				int k = -1;
				//记录是否有负数
				int minus = 0;
				if(n[0] == '-')
                    minus = 1;
				for (int j = minus; n[j] != '\0'; j++)
				{
					if (n[j] == '.')
					{
						k = j;
						continue;
					}
					if (k == -1)
						temp = temp * 10 + (n[j] - 48);
					else
						temp = temp + (n[j] - 48)*pow(10, k - j);
				}
				if(minus == 1)
                    temp*= -1;
				memcpy(val, &temp, 8);
			}
			else if (type == CHAR)
			{
				memcpy(val, n, 1);
			}
			else
				memcpy(val, n, 20);
		}
}

void mainfun(LQueue *Q)
{
    InitLQueue(Q);
    char a='y';
    while(a=='y'||a=='Y')
    {
        int n;
        memu();
        printf("请输入你的选择\n");
        inputCheck(&n, INT);
        while(n < 1 || n > 8)
        {
            printf("\n输入错误！请重输:");
            inputCheck(&n, INT);
        }
        switch(n)
        {
            case 1:
                IsEmptyLQueue(Q);
                break;
            case 2:
               {
				if(IsEmptyLQueue(Q))
					break;
                switch(Q->front->type)
                {
					case INT:
					{
						int a;
						GetHeadLQueue(Q, &a);
						printf("队列头元素是： %d\n", (int)a);
						break;
					}
					 case CHAR:
					{
						 char a;
						 GetHeadLQueue(Q, &a);
						 printf("队列头元素是： %c\n", (char)a);
						 break;
					}
					case DOUBLE:
					{
						double a ;
						GetHeadLQueue(Q, &a);
						printf("队列头元素是： %.2lf\n", (double)a);
						break;
					}
					case STRING:
					{
						char a[20] = {0};
						GetHeadLQueue(Q, a);
						printf("队列头元素是： %s\n", (char*)a);
						break;
					}
                }
				break;
            }
            case 3:
                DestoryLQueue(Q);
                break;
            case 4:
                LengthLQueue(Q);
                break;
            case 5:
                ClearLQueue(Q);
                break;
            case 6:
            {
					int t;
                    printf("你想入队哪种类型？:\n");
                    printf("1. 整型 2. 字符型 3. 浮点型(精确到小数点后2位) 4. 字符串\n");
                    inputCheck(&t, INT);
                    while(t<1 || t>4)
                    {
                        printf("应输入在[1,4]之间的整数！\n请重输：");
                        inputCheck(&t, INT);
                    }
					printf("想入队的数据 :");
                    switch(t)
                    {
                    case INT:{
							int a;
							inputCheck(&a, INT);
							EnLQueue(Q, &a, INT);
							break;
						}
						case CHAR: {
							char a ;
							inputCheck(&a, CHAR);
							EnLQueue(Q, &a, CHAR);
							break;
						}
                        case DOUBLE:{
							double a ;
							inputCheck(&a, DOUBLE);
							EnLQueue(Q, &a, DOUBLE);
							break;
						}
                        case STRING:{
							char a[20];
							printf("最大长度为20哦！\n");
							inputCheck(&a, STRING);
							EnLQueue(Q, a, STRING);
							break;
						}
                    }
					break;
            }
            case 7:
                DeLQueue(Q);
                break;
            case 8:
                {
                    void (*p)(void *q,int type);
                    p=LPrint;
                    TraverseLQueue(Q, p);
                    break;
                }

        }
        printf("是否继续。是为Y，否为其他字符\n");
		inputCheck(&a, CHAR);
    }
}


//队列初始化
void InitLQueue(LQueue* q)
{
    q->front=NULL;
    q->rear=NULL;
    q->length=0;
}
//销毁队列
void DestoryLQueue(LQueue *Q)
{
    while(Q->front!=Q->rear)
    {
        Node *destory=Q->front;
        Q->front=Q->front->next;
        free(destory);
    }
    printf("销毁成功\n");
    printf("是否要重新初始化(否将退出程序)？是输入Y,否输入其他字符,\n");
    char n;
    n=getchar();
    if(n=='y'||n=='Y')
    {
        InitLQueue(Q);
        getchar();
    }
    else
    {
        printf("没有重新初始化，队列销毁，无法继续操作队列\n");
        exit(0);
    }

}
//判断队列是否为空
Status IsEmptyLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("队列为空\n");
        return TRUE;
    }

    else
        printf("队列不为空\n");
        return FALSE;
}
//得到队头元素
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(Q->length==0)
    {
        printf("当前队列为空\n");
        return FALSE;
    }
    memcpy(e, Q->front->data, sizeof(Q->front->type));
    return TRUE;
}
//得到队列长度
int LengthLQueue(LQueue *Q)
{
    if(Q->length!=0)
        printf("当前队列长度%d\n",Q->length);
    else
        printf("当前队列为空\n");
}

//入队
Status EnLQueue(LQueue *Q ,void *data, int type)
{
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = (void *)malloc(20);
	p->type = type;
	memcpy(p->data, data, 20);
	p->next = NULL;
	if (Q->rear == NULL)
	{
		Q->front = p;
		Q->rear = p;
	}
	else
	{
		if (Q->front->next == NULL)
			Q->front->next = p;
		Q->rear->next = p;
		Q->rear = p;
	}
	Q->length++;
	return TRUE;
}
//清空队列
void ClearLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("该队列为空，无需清空\n");
        return FALSE;
    }
    else
    {
        while(Q->front!=Q->rear)
        {
            Node *destory=Q->front;
            Q->front=Q->front->next;
            free(destory);
        }
        free(Q->front);
        Q->front=NULL;
        Q->rear=NULL;
        Q->length=0;
        printf("清空完毕\n");
        return TRUE;
    }

}
//出队
Status DeLQueue(LQueue *Q)
{
    if(Q->length==0)
    {
        printf("队列为空，无法出队\n");
    }
    Node *destory=Q->front;
	if (Q->length == 1)
		Q->front = Q->rear;
	else
		Q->front=Q->front->next;
    free(destory);
    Q->length--;
    printf("出队完毕！\n");
}
//遍历队列，打印队列元素
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int type))
{
    if(Q->length==0)
    {
        printf("队列为空,无元素\n");
        return  FALSE;
    }
    Node *p = (void*)malloc(10);
    p = Q->front;
    while(p!=NULL)
    {
        foo(p->data, p->type);
        p = p->next;
    }
    return TRUE;
}
void LPrint(void *q, int type)
{
    if(type == DOUBLE)
        printf("--> %.2lf", *(double*)q);
    if(type == CHAR)
        printf("--> %c", *(char*)q);
    if(type == INT)
        printf("--> %d ", *(int*)q);
    if(type == STRING)
        printf("--> %s ", (char*)q);
}

void ChooseMenu()
{
    printf("----------------------------\n");
    printf("****************************\n");
    printf("1--整型--2--字符--3--浮点型 4--字符串(10个字符以内)\n");
    printf("****************************\n");
    printf("----------------------------\n");
}

