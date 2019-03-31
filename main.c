#include "calculatior.h"

int main()
{
    char aExpression1[100] = {0};
    char aExpression2[100] = {0};
    LinkStack *symbol = (LinkStack *)malloc(sizeof(LinkStack));
    LinkStack *number = (LinkStack *)malloc(sizeof(LinkStack));
    initLStack(symbol);
    initLStack(number);
    inputString(aExpression1);
    convertString(aExpression1,aExpression2,symbol);
    double temp = computeString(number,aExpression2);
    printf("\n 结果为-->%.2lf\n", temp);
    destroyLStack(symbol);
    destroyLStack(number);
    free(symbol);
    free(number);
    return 0;
}
