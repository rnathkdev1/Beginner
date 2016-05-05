
#include <iostream>
using namespace std;



void printarray(int *num)
{	
	for (int i=0;i<100;++i)
	cout<<*(num+i)<<"\n";
	return;
	
}


void printnewarray(int **num)
{	
	for (int i=0;i<100;++i)
	cout<<*(*num+i)<<"\n";
	return;
	
}


void enqueue(struct queue *myqueue, int num)
{
	myqueue->rear+=1;
	myqueue->array[myqueue->rear]=num;
	return;
}

void display(struct queue*myqueue)
{
	for (int i=myqueue->front;i<=myqueue->rear;++i)
	cout<<myqueue->array[i];
	return;

}

void dequeue(struct queue *myqueue)
{
	myqueue->front+=1;
	return;
}


int isempty(struct queue *myqueue)
{
	if (myqueue->front>myqueue->rear)
	return 1;
	else return 0;

}



int main()
{
	int array[100];
	int *newarray[100];

	for (int i=0;i<100;++i)
	array[i]=i;
	printarray(array);
	*newarray=array;
	printnewarray(newarray);
	return 0;
}


