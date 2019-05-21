#include"BinaryTree.h"
Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return SUCCESS;
}

void enterQueue(TreeQueue *q, BiTree t)
{
	if (q->rear == MAX) {
		return;
	}
	else {
		q->data[q->rear] = t;
		q->rear++;
	}
}
BiTree delQueue(TreeQueue *q)
{
	if (q->front == q->rear) {
		return NULL;
	}
	else {
		q->front++;
		return q->data[q->front - 1];
	}
}

//操作结果：构造空二叉树T
Status DestroyBiTree(BiTree T)
{
    if(T != NULL)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
        free(T);
    }
    return SUCCESS;
}
//初始条件：二叉树T存在
//操作结果：摧毁二叉树T
Status CreateBiTree(BiTree *T, char* definition)
{
    BiTree q = *T;
	int leaves, childs, len;
	int i;
	if(definition[0] == '\0')return ERROR;
	if(definition[0] == '#')
	{
		*T = NULL;
		return SUCCESS;
	}
	*T = q = (BiTree)malloc(sizeof(BiTNode));
	q->data = definition[0];
	CreateBiTree(&q->lchild, definition + 1);
	leaves = 0;
	childs = 0;
	len = strlen(definition);
	for(i = 1; i < len; i++)
	{
		if(definition[i] == '#')
		{
			leaves ++;
		}
		else
		{
			childs ++;
		}
		if(childs + 1 == leaves)
		{
			if(CreateBiTree(&q->rchild, definition + leaves + childs + 1) == ERROR)
			{
				return ERROR;
			}
			return SUCCESS;
		}
	}
	return ERROR;
}
//初始条件： definition给出二叉树的定义
//操作结果：按definition构造二叉树T


//以下部分函数定义未指定参数类型
Status PreOrderTraverse(BiTNode *T, Status (*visit)(TElemType e))
{
    if(T != NULL)
    {
        visit(T->data);
        PreOrderTraverse(T->lchild, visit);
        PreOrderTraverse(T->rchild, visit);
    }
    return SUCCESS;
}
//初始条件：二叉树T存在，visit为对结点的操作的应用函数
//操作结果：先序遍历T，对每个结点调用visit函数一次且仅一次，一旦visit失败，则操作失败
Status InOrderTraverse(BiTNode *T, Status (*visit)(TElemType e))
{
    if(T != NULL)
    {
        InOrderTraverse(T->lchild, visit);
        visit(T->data);
        InOrderTraverse(T->rchild, visit);
    }
    return SUCCESS;
}
Status PostOrderTraverse(BiTNode *T, Status (*visit)(TElemType e))
{
    if(T != NULL)
    {
        PostOrderTraverse(T->lchild, visit);
        PostOrderTraverse(T->rchild, visit);
        visit(T->data);
    }
    return SUCCESS;
}
Status LevelOrderTraverse(BiTNode *T, Status (*visit)(TElemType e))
{
	TreeQueue q;
	BiTree temp;
	q.front = q.rear = 0;
	if (!T) {
		printf("the tree is empty\n");
		return;
	}
	enterQueue(&q, T);
	while (q.front != q.rear) {
		T = delQueue(&q);
		visit(T->data);
		if (T->lchild) {
			enterQueue(&q, T->lchild);
		}
		if (T->rchild) {
			enterQueue(&q, T->rchild);
		}
	}
}
int Value(BiTNode *T)
{
	if (T == NULL)
		return 0;
	//左子树与右子树的值
	int left, right;

	left = Value(T->lchild);
	right = Value(T->rchild);
	//叶子结点，返回其自身的值
	if (T->lchild == NULL && T->rchild == NULL)
		return T->data - '0';
	else
	{
		//不是叶子结点，返回其左右子树与其对应运算符运算的值
		return caculate(left, right, T->data);
	}
}
Status visit(TElemType e)
{
    printf("%c", e);
    return SUCCESS;
}

Status addWell(char *ch)
{
	char s[MAX], c;
	int i = 0, j = 0;
	BiTree T = NULL;
	for (i = 0; ch[i] != '\0'; i++)
	{
		if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/')
		{
			s[j++] = ch[i];
		}
		else if (ch[i] >= '0' && ch[i] <= '9')
		{
			s[j++] = ch[i];
			int temp = 1;
			while (temp <= 2)
			{
				s[j++] = '#';
				temp++;
			}
		}
		else
		{
			printf("error!\n");
			return ERROR;
		}
	}
	s[j] = '\0';
	char *tev = s;
	CreateBiTree(&T, tev);
	int answer = Value(T);
	printf("前缀表达式的值为:%d\n", answer);
	return SUCCESS;
}


void memu(BiTree *T)//展示用户界面
{
    printf("\n\n*********************************************************************************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("********************************数 据 结 构 之 二 叉 树 程 序 设 计**************************************\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         1.  输入表达式            \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         2.  三种遍历              \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         3.  计算表达式            \t\t\t\t\t\t*\n");
    printf("*\t\t\t\t         4.  销毁二叉树            \t\t\t\t\t\t*\n");;
    printf("*\t\t\t\t\t\t\t\t\t\t\t\t\t\t*\n");
    printf("*********************************************************************************************************\n");
    select(T);
}

int caculate(int a, int b, char symbol)
{
	switch (symbol)
	{
	case '+':
		return a + b;
	case '-':
		return a - b;
	case '*':
		return a * b;
	case '/':
		return a / b;
	}
}

void select(BiTree*T)
{
    printf("请输入你的选择:");
    int n;
    inputCheck(&n);
    while( n<1 || n > 4)
    {
        printf("输入错误!请重输:");
        inputCheck(&n);
    }
    switch(n)
    {
    case 1:
        {
            char s[MAX];
            printf("请输入字符串创建二叉树:");
            scanf("%s", s);
            while(CreateBiTree(T, s) == ERROR)
            {
                printf("输入错误!请重输:");
                scanf("%s", s);
            }
            break;
        }
    case 2:
        {
            if(*T == NULL)
            {
                printf("树为空!\n");
                break;
            }
            printf("\n先序排序为:\n");
            PreOrderTraverse(*T, visit);
            printf("\n-------------------");
            printf("\n中序排序为:\n");
            InOrderTraverse(*T, visit);
            printf("\n-------------------");
            printf("\n后序排序为:\n");
            PostOrderTraverse(*T, visit);
            printf("\n-------------------");
            printf("\n层序排序为:\n");
            LevelOrderTraverse(*T, visit);
            printf("\n-------------------");
            printf("\n");
            break;
        }
    case 3:
        {
            char c[MAX];
            int flag = 0;
            do
            {
                printf("请输入前缀表达式:");
                scanf("%s", c);
                flag = addWell(c);
            }while(flag == ERROR);
            break;
        }
    case 4:
        {
            if(*T == NULL)
            {
                printf("本身已为空！");
                break;
            }
            DestroyBiTree(*T);
            *T = NULL;
            break;
        }
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
		printf("\n输入错误!请重新输入:");
		inputCheck(val);
	}
	int temp = 0;
	for (int j = 0; n[j] != '\0'; j++)
		temp = temp * 10 + (n[j] - 48);
	*val = temp;
}
