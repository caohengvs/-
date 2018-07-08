#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
#define MaxSize 100
typedef struct Lnode{
	int data;
	struct Lnode *next;
}Lnode;

//void CreatListL(Lnode *&C, int a[], int n);//ͷ�巨���������� 
void CreatListR(Lnode *&C, int a[], int n);//β�巨����������
//void merge(Lnode *A, Lnode *B, Lnode *&C);//˳��-����鲢
void merge(Lnode *A, Lnode *B, Lnode *&C);//reverse-merge two table
int FindElem(Lnode *&C, int x, int n);//Find an element and delete it
int main()
{
	Lnode *headA = NULL;
	//Lnode *headB = NULL;
	//Lnode *headC = NULL;
	int i, n, e;
	int a[MaxSize];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d",&a[i]);
	} 
	CreatListR(headA, a, n);
	scanf("%d", &e);
	e = FindElem(headA, e, n);
	
	//CreatListR(headB ,a, n);
	//CreatListL(head, a, n);
	//merge(headA, headB, headC);
	headA = headA->next;
	while(headA != NULL){
		printf("%2d",headA->data);
		headA = headA->next;
	}
	printf("\n");
	printf("%d", e);
	return 0;
}
/*β�巨*/ 
void CreatListR(Lnode *&C, int a[], int n)
{
	Lnode *s, *r;
	int i;
	C = (Lnode *)malloc(sizeof(Lnode));
	C->next = NULL;
	r = C;
	for (i = 0; i < n; ++i){
		s = (Lnode *)malloc(sizeof(Lnode));
		s->data = a[i];
		r->next = s;
		r = r->next;
		
	}
	r->next = NULL;
}
/*ͷ�鷨*/
void CreatListL(Lnode *&C, int a[], int n)
{
	int i;
	Lnode *s;//����ָ�������ڵ�
	C = (Lnode *)malloc(sizeof(Lnode));
	C->next = NULL;
	for (i = 0; i < n; ++i){
		s = (Lnode *)malloc(sizeof(Lnode));
		s->data = a[i];
		s->next = C->next;
		C->next = s;
	}
 } 
// void merge(Lnode *A, Lnode *B, Lnode *&C)
// {
// 	Lnode *p = A->next;
// 	Lnode *q = B->next;
// 	Lnode *r;
// 	C = A;
// 	C->next = NULL;
// 	free(B);
// 	r = C;
// 	while (p != NULL && q != NULL){
// 		if (p->data <= q->data){
//			r->next = p;p = p->next;
//			r = r->next;
//		 }
//		 else {
//		 	r->next = q;q = q->next;
//		 	r = r->next;
//		 }
//	 }
//	 r->next = NULL;
//	 if (p != NULL) r->next = p;
//	 else r->next = q;	
// }
void merge(Lnode *A, Lnode *B, Lnode *&C)
{
	Lnode *p = A->next;
	Lnode *q = B->next;
	Lnode *s;
	C=A;
	C->next = NULL;
	free(B);
	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data){
			s = p;p = p->next;
			s->next = C->next;
			C->next = s;
		}
		else {
			s = q;q = q->next;
			s->next = C->next;
			C->next = s;
		}
	}
	while (p != NULL) {
		s = p;p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q != NULL) {
		s = q;q = q->next;
		s->next = C->next;
		C->next = s;
	}
}
int FindElem(Lnode *&C, int x, int n)
{
	Lnode *s;
	Lnode *p = C;
	while (p->next != NULL){
		if (p->next->data == x)
			break;
		p = p->next;
	}
	if (p->next == NULL)
		return 0;
	else {
		s = p->next;
		p->next = p->next->next;
		free(s);
		return 1;
	}
}
