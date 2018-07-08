//Ñ­»·×óÒÆpÎ»
#include<iostream>
#define N 50
using namespace std;
void Reverse(int l, int r, int a[]) //ÄæĞò
{
	int i, p, temp;
	for (i = l, p = r; i < p; ++i,--p)
		{
			 temp = a[i];
			 a[i] = a[p];
			 a[p] = temp;
		 } 
} 
void Clp(int p, int n,int a[])
{
	if (p <= 0 || p >= n)
		cout << "error"<<endl;
	else {
		Reverse(0,p-1,a);
		Reverse(p,n-1,a);
		Reverse(0,n-1,a);
		
	}
}
int main() 
{
	int a[N], p, n, i;
	cin >> p >> n;
	for (i = 0; i < n; ++i)
		cin >> a[i];
	Clp(p,n,a);
	for (i = 0; i < n; ++i)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
	
}
