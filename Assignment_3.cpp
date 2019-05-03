/*
Name:Saumitra Kulkarni
Roll no:222004
Gr No:17u255
Batch:B1
*/

#include <iostream>
#include<queue>
using namespace std;

class list
{
private:list *next;
        list *head;
        int data;
public:
        list()
	   {
        head=NULL;
	   }
 void insert_end(int);
 void display();

};

void list::insert_end(int x)
{
	list *nn=new list;
	nn->data=x;
	nn->next=NULL;


	if(head==NULL)
	{
	  head=nn;
    }

	else
	{
	  list *temp;
	  temp=head;
	  while(temp->next!=NULL)
	  temp=temp->next;
	  temp->next=nn;
	}
}

void list::display()
{
   list *temp;
   temp=head;
   while(temp!=NULL)
   {
	   cout<<"\t";
	   cout<<temp->data;
	   temp=temp->next;
   }
}


int main()
{
cout<<endl;
int n;
int x;
int no;

list k;

cout<<"Enter the no. of vertices:";
cin>>n;
int int_arr[n][100];

for(int k=0;k<n;k++)
{
for(int l=0;l<n;l++)
{
int_arr[k][l]=0;
}
}


list arr[n];
int i=0;
while(i<n)
{
	int j=0;
	cout<<"Enter no. of vertices adjacent to "<<i<<":";
    cin>>no;
    cout<<endl;
    arr[i].insert_end(i);
    while(j<no)
    {
    cout<<"Enter vertices adjacent to "<<i<<":";
    cin>>x;
    arr[i].insert_end(x);
    j++;
    int_arr[i][x]=1;
    int_arr[x][i]=1;
    }
    i++;
	cout<<endl;
}

 i=0;


cout<<endl<<"Displaying Adjacency List:"<<endl;
while(i<n)
{
	arr[i].display();
	cout<<endl;
	i++;
}

cout<<endl<<"Displaying Adjacency Matrix:"<<endl;
for(int k=0;k<n;k++)
{
for(int l=0;l<n;l++)
{
cout<<int_arr[k][l]<<"\t";
}
cout<<endl;
}


return 0;
}
