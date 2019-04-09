#include"../head/LQueue.h"
int main()
{
    LQueue *Q=(LQueue*)malloc(sizeof(LQueue));
    mainfun(Q);
    DestoryLQueue(Q);
    free(Q);
    return 0;
}
