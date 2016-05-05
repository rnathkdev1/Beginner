#include <iostream>
using namespace std;

struct node
	{
	int data;
	struct node*next;
	};


void addend(struct node*head,int num)
{
struct node *ptr,*temp;
temp = new node;
ptr=head;
while (ptr->next!=NULL)
{
ptr=ptr->next;
} 
temp->data=num;
temp->next=NULL;
ptr->next=temp;
}


void display(struct node*head)
{
struct node *ptr;
ptr=head;
do
{

cout<<ptr->data<<'\n';
ptr=ptr->next;
}while (ptr!=NULL); 
}


void deleteend(struct node*head)
{
struct node *ptr,*temp;
temp = new node;
ptr=head;
while (ptr->next->next!=NULL)
{
ptr=ptr->next;
}
temp=ptr->next;
delete(temp);
ptr->next=NULL;

}

void createlist(struct node*head)
{

head->data = 1;
head->next=NULL;
for (int i=2;i<8;++i)
addend(head,i);
}


int main()
{
//Here we are going to input a general linked list as follows;
struct node*head;
head =new node;
createlist(head);
//display(head);
deleteend(head);
display(head);
return 0;
}
