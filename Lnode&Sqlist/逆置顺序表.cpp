#include<iostream>
using namespace std;
#define MAX_SIZE 1000
typedef int Elemtype; 
typedef struct Sqlist{
	Elemtype Data[MAX_SIZE];
	int Len;
}Sqlist;
void Reverse(Sqlist &a){
	int i, j;
	for(i=0,j=a.Len-1; i < j; ++i, --j){
		char temp;
		temp = a.Data[i];
		a.Data[i] = a.Data[j];
		a.Data[j] = temp; 
	}
}
int main()
{
	int i, j;
	Sqlist a;
	scanf("%d", &a.Len);
	for( i=0; i < a.Len; ++i){
		scanf("%d", &a.Data[i]);
	}
	Reverse(a);
	for(i=0; i < a.Len; ++i){
		printf("%d", a.Data[i]);
	}
	return 0;
	
}
