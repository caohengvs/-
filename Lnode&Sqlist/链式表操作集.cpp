#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
Position Find( List L, ElementType X )
{
  while (L != NULL){
    if (L->Data == X) return L;
    else {
      L = L->Next;
    }
  }
  return ERROR;
}
List Insert(List L, ElementType X, Position P)
{
	List q, s;
	q = L;
	while (q->Next != P){
		q = q->Next;
	}
	if (q->Next == P) {
		s = (List)malloc(sizeof(List));
		s->Data = X;
		s->Next = P;
		q->Next = s;
		return L;
	}	
	return ERROR;
}
  return L;
  }
 List Delete( List L, Position P )
  {
    List s;
    List q;
    q = L;
    while (q->Next != P)
      q = q->Next;
    if (q->Next == P){
      s = P;
      q->Next = P->Next;
      free(s);
      return L;
    }
    else
    {
Printf("Wrong Position for Deletion");
return ERROR;
}
     
  }
