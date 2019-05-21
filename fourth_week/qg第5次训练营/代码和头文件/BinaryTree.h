#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>


typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct  BiTNode {
    TElemType  data;     // ������
    struct BiTNode  *lchild,*rchild;  // ���Һ���ָ��
} BiTNode,*BiTree;   // ��������

#define MAX 1000
typedef struct TreeQueue {
	BiTree data[MAX];
	int front;
	int rear;
}TreeQueue;



typedef enum Status{
	SUCCESS,
	ERROR
}Status;


Status InitBiTree(BiTree *T);
//�������������ն�����T
Status DestroyBiTree(BiTree T);
//��ʼ������������T����
//����������ݻٶ�����T
Status CreateBiTree(BiTree *T, char* definition);
//��ʼ������ definition�����������Ķ���
//�����������definition���������T


//���²��ֺ�������δָ����������
Status PreOrderTraverse(BiTNode *T, Status (*visit)(TElemType e));
//��ʼ������������T���ڣ�visitΪ�Խ��Ĳ�����Ӧ�ú���
//����������������T����ÿ��������visit����һ���ҽ�һ�Σ�һ��visitʧ�ܣ������ʧ��
Status InOrderTraverse(BiTNode *T, Status (*visit)(TElemType e));	//�������
Status PostOrderTraverse(BiTNode *T, Status (*visit)(TElemType e));	//�������
Status LevelOrderTraverse(BiTNode *T, Status (*visit)(TElemType e));	//�������
int Value(BiTNode *T);			//������Ķ�������ֵ
/*
��ʾ�����ڽ��ṹ�������ø�Tagֵ��־������������������������
�ɸ�����Ҫ�������Ӳ���.
*/
/*
	����ڵ����ݲ���
*/
Status visit(TElemType e);
/*
	��ǰ׺���ʽ���м������
*/
Status addWell(char *ch);
/*
	ѡ�����
*/
void select(BiTree *t);
/*
	Ŀ¼
*/
void memu(BiTree *T);
/*
	�������
*/
int caculate(int a, int b, char symbol);
/*
	����û��������
*/
void inputCheck(int *val);
