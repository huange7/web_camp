
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
enum {
	MAX=1,MIN
};

typedef enum Status {
	ERROR = 0, SUCCESS = 1
} Status;

typedef struct SqStack {
	int *data;
	int top;
	int size;
} Stack;

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int  *a,int begin,int mid,int end,int  *temp);


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int  *temp);


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end);


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size);


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int FindData(int *a, int size);

 /**
  *  @name        : int FindExtreme(int *a, int size, int type)
  *  @description : 找到一个数组中的极大/极小值
  *  @param       : 数组指针a，数组长度size， 需找到的类型（极大/极小）
  */
int  FindExtreme(int  *a, int size, int type);

/**
 *  @name        : void PrintArray(int *a, int size)
 *  @description : 打印数组
 *  @param       : 数组指针a，数组长度size
 */
void PrintArray(int *a, int size);

void swap(int  *a, int  *b);

int GetNumInPos(int  num, int pos);

void Catalogue(int  *a,int *b,int *c,int size1,int size2,int size3);

void SelectOpe(int  *a,int *b,int *c,int size1,int size2,int size3);

void generate(int *a,int *b,int *c);

void inputCheck(int *val);

Status initStack(Stack *s,int sizes);//初始化栈
Status isEmptyStack(Stack *s);//判断栈是否为空
Status getTopStack(Stack *s,int *e); //得到栈顶元素
Status pushStack(Stack *s,int data);//入栈
Status popStack(Stack *s,int *data);//出栈

void randomArray(int *temp, int size);
#endif // QUEUE_H_INCLUDED
