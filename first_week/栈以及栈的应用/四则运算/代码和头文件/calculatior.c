#include "calculatior.h"
Status initLStack(LinkStack *s)   //初始化
{
    s->count = 0;
    s->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if(s->top == NULL)
    {
        printf("\t\t\t\t动态分配内存失败!\n");
        return ERROR;
    }
    else
    {
        s->top = NULL;
    }
    return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
    if(s->count == 0)
    {
        return SUCCESS;
    }
    return ERROR;
}

Status destroyLStack(LinkStack *s)   //销毁栈
{
    if(isEmptyLStack(s))
        return ERROR;
    while(s->top != NULL)
    {
        LinkStackPtr p = s->top;
        s->top = s->top->next;
        free(p);
    }
    s->count = 0;
    return SUCCESS;
}

Status pushLStackdouble(LinkStack *s,double data)   //入栈
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if(p == NULL)
    {
        printf("\t\t\t\t动态分配内存失败!\n");
        return ERROR;
    }
    p->data = data;
    p->next = s->top;
    s->top = p;
    s->count ++;
    return SUCCESS;
}

Status pushLStackchar(LinkStack *s,char data)   //入栈
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    if(p == NULL)
    {
        printf("\t\t\t\t动态分配内存失败!\n");
        return ERROR;
    }
    p->cData = data;
    p->next = s->top;
    s->top = p;
    s->count ++;
    return SUCCESS;
}

Status popLStackdouble(LinkStack *s,double *data)   //出栈
{
    if(isEmptyLStack(s))
        return ERROR;
    *data = s->top->data;
    LinkStackPtr p = s->top;
    s->top = p->next;
    free(p);
    p = NULL;
    s->count--;
    return SUCCESS;
}

Status popLStackchar(LinkStack *s,char *data)   //出栈
{
    if(isEmptyLStack(s))
        return ERROR;
    *data = s->top->cData;
    LinkStackPtr p = s->top;
    s->top = p->next;
    free(p);
    p = NULL;
    s->count--;
    return SUCCESS;
}

void inputString(char s[])
{
    int i=0;
    printf("请输入表达式:");
    scanf("%s", s);
    getchar();
    while(1)
    {
        if((s[i] < '0'||s[i] > '9')&&(s[i] != '+'&&s[i] != '-'&&s[i] != '*'&&s[i] != '/'&&s[i] != '.'&&s[i]!= '('&&s[i] != ')'))
        {
            printf("请输入正确的表达式！");
            scanf("%s", s);
            i = 0;
        }else
        {
            i++;
        }
        if(s[i] == '\0')
            break;
    }
    checkString(s);
}

Status checkString(char s[])  //检查字符串的输入
{
    int i,j = 0;
    char a[20] = {0};         //存放运算符
    int flag = 0;       // 用于判断该数是否为负数  例如：5*-3，则3的实际为-3
    int bracket = 0;    // 检测括号的配对关系
    for(i = 0; s[i] != '\0'; i++)
    {
        //将数字间的运算符存储起来
        if(s[i] == '+'||s[i] == '-'||s[i] == '*'||s[i] == '/')
        {
            a[j++] = s[i];
        }
        //判断括号是否匹配
        if(s[i] == '(')
            bracket = 1;
        if(s[i] == ')'&&bracket == 1)
            bracket = 0;
        //将数字间的字符进行运算并判断是否正确
        if((s[i+1] >= '0'&&s[i+1] <= '9')||s[i+1] == '(')
        {
            char c = a[0];
            for(int k = 1;k < j; k++)
            {
                if((c =='+'&& a[k]=='-')||(c == '-'&&a[k] == '+'))
                    c = '-';
                else if(c == '-'&& a[k] == '-')
                {
                    c = '+';
                }
                else if(c =='*' &&a[k] == '+')
                {
                    c = '*';
                }
                else if((c == '*'||c == '/')&& a[k] == '-')
                {
                    if(flag == 0)
                        flag = 1;
                    else
                        flag = 0;
                }
                else if((c == '+'||c == '-')&&(a[k] == '*'||a[k] == '/'))
                {
                    printf("输入表达式错误！请重新输入：");
                    inputString(s);
                }
            }
            if(c == '+'||c == '-'|| c == '*'|| c == '/')
            {
               s[i-j+1] = c;
               for(int k = i-j+2;s[k] != '\0'; k++)
                    s[k] = s[k+j-1];
               i = i-j+2;
            }
          for(int k = 0; k < j; k++)
                a[k] = '\0';
            j = 0;
        }
    }
    if(s[i-1] == '+'||s[i-1] == '-'||s[i-1] == '*'||s[i-1] == '/'||bracket != 0)
    {
        printf("表达式输入错误!请重新输入：");
        inputString(s);
    }
	printf("\n最终的表达式为:");
    for(int k = 0; s[k] != '\0'; k++)
        printf("%c" ,s[k]);
        printf("\n");
        printf("bra = %d\n", bracket);
    return SUCCESS;
}

double getTopLStackdouble(LinkStack *s)  //得到栈顶元素
{
    if(isEmptyLStack(s))
        return 0;
    return (s->top->data);
}

char getTopLStackchar(LinkStack *s)  //得到栈顶元素
{
    if(isEmptyLStack(s))
        return '\0';
    return (s->top->cData);
}

Status convertString(char s1[],char s2[],LinkStack *s)//将中缀表达式转化为后缀表达式
{
    int i = 0 , j = 0;
    int flag = 0;                                //用于分隔右括号和运算符
    char c;
    while(s1[i] != '\0')
    {
        if((s1[i] >= '0'&&s1[i] <= '9')||s1[i] == '.')
            {
                s2[j++] = s1[i];
                if(s1[i] >= '0'&&s1[i] <= '9')
                    printf("是数字，直接赋值：%.2lf\n",(double)(s1[i]-48));
                else
                    printf("是小数点，直接赋值！\n");
            }
        if(s1[i+1] == ')')
        {
            if(s1[i+2] == '+'||s1[i+2] == '-'||s1[i+2] == '*'||s1[i+2] == '/'||s1[i+2] == '\0'||s1[i+2] == ')')
            {
                if(flag == 0)
               {
                    flag = 1;
                    s2[j++] = ',';
                    printf("数字转化完毕！加个逗号\n");
               }
            }
        }
        if(s1[i+1] == '+'||s1[i+1] == '-'||s1[i+1] == '*'||s1[i+1] == '/'||s1[i+1] == '\0')
            {
                if(flag == 1)
               {
                    flag = 0;
               }
                else
                {
                    s2[j++] = ',';
                    printf("数字转化完毕，加个逗号!\n");
                }
            }
        if(s1[i] == '+'||s1[i] == '-'||s1[i] == '*'||s1[i] == '/')
        {
            if(isEmptyLStack(s))
                {
                    pushLStackchar(s, s1[i]);
                    printf("空栈或者遇到左括号，直接放入\n");
                }
            else
            {
                switch(judgePriority(s1[i], getTopLStackchar(s)))
                {
                case -1:
                    {
                        pushLStackchar(s , s1[i]);
                        printf("运算符优先级比栈顶高，入栈！\n");
                        break;
                    }
                case 0:
                case 1:
                    {
                        while(judgePriority(s1[i], getTopLStackchar(s)) != -1)
                        {
                            popLStackchar(s , &s2[j++]);
                            printf("运算符优先级比栈顶低或者相等，出栈！\n");
                            if(isEmptyLStack(s))
                                {
                                    printf("空栈！暂停比较！\n");
                                    break;
                                }
                        }
                        if(!isEmptyLStack(s)&&(judgePriority(s1[i], getTopLStackchar(s)) == -1))
                            {
                                printf("栈不空！并且运算符优先级比栈顶高！直接入栈！\n");
                                pushLStackchar(s, s1[i]);
                            }
                        if(isEmptyLStack(s))
                            {
                                printf("空栈！直接压栈！\n");
                                pushLStackchar(s , s1[i]);
                            }
                        break;
                    }
                }
            }
        }
        if(s1[i] == '(')
            {
                pushLStackchar(s, s1[i]);
                printf("遇到左括号，压栈！\n");
            }
        if(s1[i] == ')')
        {
            printf("遇到右括号！开始出栈！\n");
            while(1)
            {
                popLStackchar(s, &s2[j++]);
                if(s->top == NULL||s->top->cData == '(')
                    break;
            }
            popLStackchar(s, &c);
            printf("出栈完毕！栈顶元素为:%c\n", getTopLStackchar(s));
        }
        i++;
    }
    while(!isEmptyLStack(s))
        {
            printf("s1扫描完毕，将栈中元素全部给s2\n");
            popLStackchar(s, &s2[j++]);
        }
    printf("转换完成的后缀表达式为:");
    for(i = 0;s2[i] != '\0'; i++)
        printf("%c", s2[i]);
    printf("\n");
    return SUCCESS;
}

int judgePriority(char a, char b)                  //判断符号优先级
{
    if((( a == '+'|| a == '-')&&(  b == '+'|| b == '-'))||((a == '*'||a == '/')&&(b == '*'||b == '/')))
        return 1;                                 //代表二者优先级相等
    else if((a == '+'||a == '-')&&(b == '*'||b == '/'))
        return 0;                                 //代表右边优先级高
    else
        return -1;                                 //代表左边优先级高
}

double computeString(LinkStack *s1,char s[])
{
    double temp = 0;
    int flag = 0;
    for(int i = 0;s[i] != '\0'; i++)
    {
        if(s[i] == '.')
            flag = 1;
        if(s[i] >= '0'&&s[i] <= '9')
        {
            if(flag != 0)
            {
                temp += (double)(s[i]-48)*pow(10,-flag);
                flag ++;
            }
            else
                temp = temp*10 + (double)(s[i]-48);
        }
        if(s[i] == ',')
        {
            pushLStackdouble(s1, temp);
            temp = 0;
            flag = 0;
        }
        if(s[i] == '+'||s[i] == '-'||s[i] == '*'||s[i] == '/')
        {
            double a,b,temp2;
            popLStackdouble(s1, &a);
            popLStackdouble(s1, &b);
            switch(s[i])
            {
            case '+':temp2 = a + b;pushLStackdouble(s1, temp2);temp2 = 0;break;
            case '-':temp2 = b - a;pushLStackdouble(s1, temp2);temp2 = 0;break;
            case '*':temp2 = b * a;pushLStackdouble(s1, temp2);temp2 = 0;break;
            case '/':temp2 = b / a;pushLStackdouble(s1, temp2);temp2 = 0;break;
            }
        }
    }
    popLStackdouble(s1, &temp);
    return temp;
}
