#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct DLnode{
	int data;
	struct DLnode *prior;
	struct DLnode *next;
}DLnode;
DLnode* FindNode(DLnode *C, int x); 
/*判断是否在表中*/
void JudgeMan(DLnode *C){
	int x;
	scanf("%d", &x);
 	if ( FindNode(C, x) != NULL) 
		printf("%d",FindNode(C, x)->data);
 	else 
 		printf("你查找的元素不在表中\n");
 	}
/*从头遍历显示链表*/
void Display(DLnode *C)
{
	while (C->next != NULL){
		printf("%d", C->next->data);
		C = C->next;
	}
}
/*向链表中插入结点*/
void InsertNode(DLnode *&C)
{
	DLnode *p, *s;
	int x;
	p = C;
	printf("你要插入的位置\n");
	scanf("%d", &x);
	for (int i = 0; i < x; i++)
		p = p->next;
	s = (DLnode *)malloc(sizeof(DLnode));
	scanf("%d", &s->data);
	s->next = p->next;
	p->next = s;
	s->prior = p;
	s->next->prior = s;
}
/*删除链表中的结点*/
void DeleteNode(DLnode *&C)
{
	int x;
	DLnode *p, *s;
	p = C;
	printf("你要删除的位置\n"); 
	scanf("%d", &x);
	for (int i = 0; i < x; i++)
		p = p->next;
	s = p->next;
	p->next = s->next;
	s->next->prior = p;
	free(s); 
}
/*查找链表中元素的值，并返回位置*/ 
DLnode* FindNode(DLnode *C, int x)
{
	DLnode *p;
	p = C->next;
	while (p != NULL){
		if (p->data == x){
			break;
		} 
		p = p->next;
	}
	return p;
 } 
/*创建一个双向链表*/
void CreateList(DLnode *&C, int n)
{
	DLnode *s, *r;
	C = (DLnode *)malloc(sizeof(DLnode));
	C->next = NULL;
	C->prior = NULL;
	r = C;
	for(int i = 0; i < n; i++){
		s = (DLnode *)malloc(sizeof(DLnode));
		scanf("%d",&s->data);
		s->next = r->next;
		r->next = s;
		s->prior = r;
		r = r->next;
	}
	r->next = NULL;
} 
 int main()
 {
 	int x;
 	DLnode *head;
 	CreateList(head, 5);
 	InsertNode(head);
 	Display(head);
 	JudgeMan(head);
 	DeleteNode(head);
	Display(head); 
 	return 0;
}
