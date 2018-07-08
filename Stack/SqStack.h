typedef int Elemtype;
#define max_size 8
typedef struct{
	Elemtype data[max_size];
	Elemtype top; 
}SqStack;
void initStack(SqStack &s){
	s.top = -1;
}
int isEmpty(SqStack s){
	if(s.top == -1){
		return 1;
	}
	else{
		return 0;
	}
}
int push(SqStack &s, Elemtype x){
	if(s.top == max_size-1){
		return 0; 
	}
	else{
		s.data[++s.top] = x;
		return 1;
	}
}
int pop(SqStack &s){
	Elemtype x;
	if(s.top == -1){
		return 0;
	}
	else{
		x = s.data[--s.top];
		return x;
	}
}
