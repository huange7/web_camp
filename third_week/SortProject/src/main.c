
#include"../inc/qgsort.h"

int main()
{
	int *a = (int *)malloc(sizeof(int)*10000);
	int *b = (int *)malloc(sizeof(int)*50000);
	int *c = (int *)malloc(sizeof(int)*200000);
	generate(a ,b,c);
	system("pause");
	return 0;
}
