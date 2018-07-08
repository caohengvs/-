#include<iostream>
using namespace std;
#define MaxSize 100
typedef struct Sqlist{
		int date[MaxSize];
		int length;
	}Sqlist;
//int findElem(Sqlist , int );
int deleteElem(Sqlist &,int , int &);
int insertElem(Sqlist &,int , int);	
int main()
{
	Sqlist A;
	int i, x, p, e;
	
	scanf("%d", &x);
	scanf("%d", &p); 
	
	A.length = 5;
	for (i = 0; i < A.length ; ++i)
		scanf("%d",&A.date[i]);
	insertElem(A, p, x);
	for(i = 0; i < A.length; ++i)
		printf("%2d", A.date[i]);
	scanf("%d", &p);
	deleteElem(A, p, e);
	printf("%d\n",e); 
	for(i = 0; i < A.length; ++i)
		printf("%2d", A.date[i]);
	return 0;
 } 
// int findElem(Sqlist L,int x)
// {
// 	int i;
// 	for (i = 0; i < L.length; ++i) {
// 		if (x < L.date[i])
// 			return i;
//	 }
//	 return i;
// }
 int  insertElem(Sqlist &L, int p, int e)
 {
 	int i;
 	if (p < 0 || p > L.length || L.length == MaxSize)
 		return 0;
 	for (i = L.length -1; i >= p; --i)
 		L.date[i+1] = L.date[i];
	L.date[p] = e;
	++(L.length);
	return 1; 
 }
 int deleteElem(Sqlist &L, int p, int &e)
 {
 	int i;
 	if (p < 0 || p > L.length -1)
 		return 0;
 	e = L.date[p];
 	for (i = p; i < L.length - 1; ++i)
 		L.date[i] = L.date[i+1];
 	--(L.length);
 	return 1;
 }
