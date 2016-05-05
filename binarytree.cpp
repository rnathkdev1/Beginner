
#include <iostream>
using namespace std;

struct node
{
int data;
struct node *left, *right;
};

struct queue
{
	int front,rear,size;
	struct node **array;
};


void createqueue(struct queue *myqueue,int cap)
{
	myqueue->front=0;
	myqueue->rear=-1;
	myqueue->size=cap;
	myqueue->array=new node*;
	return;
}


void enqueue(struct queue *myqueue, struct node*data)
{
	//cout<<myqueue->rear;
	myqueue->rear+=1;
	//cout<<myqueue->rear;
	myqueue->array[myqueue->rear]=data;
	//cout<<data->data;
	return;
}


int isempty(struct queue *myqueue)
{
	if (myqueue->front>myqueue->rear)
	return 1;
	else return 0;

}

struct node* dequeue(struct queue *myqueue)
{
	struct node*returnnode;
	returnnode=myqueue->array[myqueue->front];
	myqueue->front+=1;
	return returnnode;
}

void createtree(struct node *head)
{
struct node *templeft,*tempright, *ptrleft,*ptrright;
templeft = new node;
tempright = new node;
ptrleft=new node;
ptrright= new node;

head->data = 1;
templeft->data=2;
tempright->data=3;
head->left=templeft;
head->right=tempright;
ptrleft=head;
ptrright = head;
ptrleft=ptrleft->left;
ptrright=ptrright->right;

ptrleft->left=new node;
ptrleft->left->data=4;
ptrleft->left->left=NULL;
ptrleft->left->right=NULL;

ptrleft->right=new node;
ptrleft->right->data =5;
ptrleft->right->left= NULL;
ptrleft->right->right-NULL;

ptrright->left=new node;
ptrright->left->data=6;
ptrright->left->left = NULL;
ptrright->left->right=NULL;

ptrright->right=new node;
ptrright->right->data=7;
ptrright->right->left = NULL;
ptrright->right->right = NULL;

} 


void preorder(struct node *head)
{
struct node *ptr;
ptr=new node;
ptr=head;

if (ptr ==NULL) 
return;

cout<<ptr->data;

preorder(ptr->left);
preorder(ptr->right);
}


void inorder(struct node *head)
{
struct node *ptr;
ptr=new node;
ptr=head;

if (ptr ==NULL) 
return;

inorder(ptr->left);
cout<<ptr->data;
inorder(ptr->right);
}

void postorder(struct node *head)
{
struct node *ptr;
ptr=new node;
ptr=head;

if (ptr ==NULL) 
return;

postorder(ptr->left);
postorder(ptr->right);
cout<<ptr->data;
}




void levelorder(struct node*root)
{
struct node*temp;
struct queue*myqueue;
myqueue = new queue;
createqueue(myqueue,100);

temp=root;

enqueue(myqueue,temp);

while (!isempty(myqueue))
{
	temp=dequeue(myqueue);
	cout<<temp->data;

	if (temp->left) enqueue(myqueue,temp->left);
	if (temp->right) enqueue(myqueue,temp->right);
}

}


int main()
{
struct node *root;
root = new node;
createtree(root);

preorder(root);
cout<<"\n";
inorder(root);
cout<<"\n";
postorder(root);
cout<<"\n";
levelorder(root);
cout<<"\n";

return 0;
}
