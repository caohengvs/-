#include<iostream>
using namespace std;
#include<stdio.h>
#include"SqStack.h"
int main()
{
	SqStack st;
	initStack(st);
	int n;
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		push(st, x);
	} 
	while(st.top >= 0){
		printf("%d", pop(st));
	}
	return 0;
}
