#include"BinaryTree.h"

int main()
{
    int i;
    BiTree *T = (BiTree*)malloc(sizeof(BiTree));
    InitBiTree(T);
    while(1)
    {
        memu(T);
        printf("你想继续吗？(1: 继续/ 其他：否)");
        scanf("%d", &i);
        if(i != 1)
            break;
    }
    DestroyBiTree(*T);
    free(T);
    return 0;
}
