#include <iostream>
using namespace std;

void makebinary(int n,char A[10])
{
if (n==0)
{ 
//A[n-1]='0';
//cout<<A[n-1]<<"\n";
//A[n-1]=1;
//cout<<A[n-1]<<"\n";
cout<<A<<'\n';
return;
}

else
{
A[n-1]='1';
makebinary(n-1,A);
//cout<<"\n";
A[n-1]='0';
makebinary(n-1,A);
//cout<<'\n';
}
}


int main()
{
int nbit=3;
char A[nbit];
for (int i=0;i<nbit;++i)
A[i]='0';

makebinary(nbit,A);

}
