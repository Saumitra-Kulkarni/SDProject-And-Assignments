/*
Name:Saumitra Kulkarni
Roll no:222004
Gr No:17u255
Batch:B1
*/

#include<iostream>
using namespace std;

#define max 30

void create(int set[])
{
  int size;
  cout<<"\nEnter the size of set:";
  cin>>size;
  set[0]=size;
  cout<<"\nEnter the values:\n";
  for(int i=1;i<=size;i++)
  {
    cin>>set[i];
  }
  cout<<endl;
}

void display(int set[])
{
  cout<<"is: "<<endl;
  int size=set[0];
  for(int i=1;i<=size;i++)
  {
    cout<<set[i]<<"\t";
  }
  cout<<endl;
}

int member(int set[],int x)
{
  int size=set[0];
  for(int i=1;i<=size;i++)
  {
    if(set[i]==x)
    return 1;
  }
  return 0;
}

void union1(int set1[],int set2[],int set3[])
{
  int size=set1[0];
   for(int i=1;i<=size;i++)
   {
     set3[i]=set1[i];
   }

    set3[0]=size;
    size=set2[0];
   for(int i=1;i<=size;i++)
   {
    if(!member(set3,set2[i]))
    {
      set3[0]++;
      set3[set3[0]]=set2[i];;
    }
   }
}

void intersection(int set1[],int set2[],int set3[])
{
  int size=set1[0];
  set3[0]=0;

  for(int i=1;i<=size;i++)
  {
    if(member(set2,set1[i]))
    {
      set3[0]++;
      set3[set3[0]]=set1[i];
    }
  }
}

void difference(int set1[],int set2[],int set3[])
{
  int size=set1[0];
  set3[0]=0;
  for(int i=1;i<=size;i++)
  {
    if(!member(set2,set1[i]))
    {
      set3[0]++;
      set3[set3[0]]=set1[i];
    }
  }
}

void subset(int set1[],int set2[])
{
  int size1=set1[0];
  int size2=set2[0];
  int count=0;

  if(size1>size2)
  {
    for(int i=1;i<=size1;i++)
    {
      if(member(set1,set2[i]))
      {
        count++;
      }
    }
  if(count==size2)
  {
    cout<<"\nset 2 is subset of set 1\n"<<endl;
  }
  else
  {
    cout<<"\nset2 is not a subset of set 1\n"<<endl;
  }
  }
  else
  {
    cout<<"\nset2 is not a subset of set 1\n"<<endl;
  }
}

void insert(int set[])
{
  int num;
  cout<<"\nEnter the element:";
  cin>>num;
  set[0]++;
  set[set[0]]=num;
}

void delete1(int set[])
{
  int num,size,i;
  size=set[0];
  cout<<"Enter the element you want to delete:";
  cin>>num;

  for(i=1;i<=size;i++)
  {
    if(set[i]==num)
    break;
  }
  if(i<=size)
  {
    set[0]--;
    size=set[0];

    for(int j=i;j<=size;j++)
    {
      set[j]=set[j+1];
    }
  }
  else
  {
    cout<<"\nElement not found\n";
  }
}
int main()
{
  cout<<"-------OPERATIONS ON SET-------"<<endl<<endl;
  int set1[max],set2[max],set3[max];
  int opt;
  int setno;
  do
  {
    cout<<"\n1.Create\n2.Display\n3.Union\n4.Intersection";
    cout<<"\n5.Difference\n6.Subset\n7.Insert Element";
    cout<<"\n8.Remove\n9.Search\n10.Size\n11.Exit\n\n";
    cout<<"Your Option:";
    cin>>opt;
    cout<<endl;

    switch(opt)
    {
      case 1:cout<<"\nSet 1: ";
             create(set1);
             cout<<"\nSet 2: ";
             create(set2);
             break;
      case 2:cout<<"\nSet 1 ";
             display(set1);
             cout<<"\nSet 2 ";
             display(set2);
             break;
      case 3:union1(set1,set2,set3);
             cout<<"Union ";
             display(set3);
             break;
      case 4:intersection(set1,set2,set3);
             cout<<"Intersection ";
             display(set3);
             break;
      case 5:difference(set1,set2,set3);
             cout<<"Difference ";
             display(set3);
             break;
      case 6:subset(set1,set2);break;
      case 7:cout<<"\nSelect the set:";
             cin>>setno;
             cout<<endl;
             if(setno==1)
             {
               insert(set1);
             }
             else
             {
               insert(set2);
             }
             break;
      case 8:cout<<"\nSelect the set:";
             cin>>setno;
             cout<<endl;
             if(setno==1)
             {
               delete1(set1);
             }
             else
             {
               delete1(set2);
             }
             break;
      case 9:int num;
             cout<<"\nSelect the set:";
             cin>>setno;
             cout<<endl;
             cout<<"Enter the element:";
             cin>>num;
             cout<<endl;
             if(setno==1)
             {
               if(member(set1,num))
               {
                 cout<<"\nElement is Present\n";
               }
               else
               {
                 cout<<"\nElement not present\n";
               }
             }
             else
             {
               if(member(set1,num))
               {
                 cout<<"\nElement is Present\n";
               }
               else
               {
                 cout<<"\nElement not present\n";
               }
             }
              break;
      case 10:cout<<"\nSelect the set:";
             cin>>setno;
             cout<<endl;
             if(setno==1)
             {
               cout<<"\nSize of set 1 is: "<<set1[0]<<endl;
             }
             else
             {
               cout<<"\nSize of set 2 is: "<<set2[0]<<endl;
             }
             break;
      case 11:cout<<"\n---Exiting the Program---\n";
              break;
      default:cout<<"\n---Wrong Choice---\n";
    }
  }
  while(opt!=11);
  return 0;
}
