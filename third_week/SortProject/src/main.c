
#include"../inc/qgsort.h"

int main()
{
	long *a = (long*)malloc(sizeof(long)*10000);
	generate(a);
	Catalogue(a, 9999);
	system("pause");
	return 0;
}
