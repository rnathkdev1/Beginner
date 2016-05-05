#include <iostream>
using namespace std;

struct queue
{
	int front,rear,size;
	int *array;
};

void createqueue(struct queue *myqueue,int cap)
{
	myqueue->front=0;
	myqueue->rear=-1;
	myqueue->size=cap;
	myqueue->array=new int[cap];
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
	struct queue *myqueue;
	myqueue=new queue;
	createqueue(myqueue,10);
	int nelem=1;
	for (int i=0;i<nelem;++i)
	enqueue(myqueue,i);
	display(myqueue);
	cout<<"\n";
	dequeue(myqueue);
	display(myqueue);
	if (isempty(myqueue))
	cout<<"Empty\n";
return 0;
}
