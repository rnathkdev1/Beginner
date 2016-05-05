#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//Towers of Hanoi
void hanoi(int disc,int source,int sink, int temp)
{
if (disc==1)
{
cout<<"Move disc from "<<source<<" to "<<sink<<'\n';
return;
}
else 
{
hanoi(disc-1,source,temp,sink);
hanoi(1,source, sink,temp);
hanoi(disc-1,temp,sink,source);
}

}

int main()
{

int  num=4,source=1,sink=3,temp=2;
//cout<<"Enter the number of discs (atleast 2)\n";
//cin>>num;

hanoi(num,source,sink,temp);
}
