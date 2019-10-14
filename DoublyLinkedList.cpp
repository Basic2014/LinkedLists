#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *next;
  Node *previous;
};

Node *first = nullptr;

void create(int A[],int n)
{
  int i;

  Node *temp;
  Node *last;

  first = new Node;
  first->data = A[0];
  first->next = nullptr;
  first->previous = nullptr;
  last = first;

  for(i = 1;i<n;i++)
  {
    temp = new Node;
    temp->data = A[i];
    temp->next = last->next;
    temp->previous = last;
    last->next = temp;
    last = temp;
  }

}

void Display(Node *p)
{
  while(p)
  {
    cout<<p->data<<" ";
    p = p->next;
  }

}
int Length(Node *p)
{
  int len{0};
  while(p)
  {
    ++len;
    p = p->next;
  }
  return len;

}

void Reverse( Node *p)
{
  Node *temp;

 //switching previous and next nodes.Then increment p= p->previous means that go to next
 while(p!=NULL)
 {
 temp=p->next;
 p->next = p->previous;
 p->previous =temp;
 p = p->previous; //
 if(p!=NULL && p->next==NULL)
 {
  first=p;
  cout<<p->next<<endl;
 }

 }
}


void Insert(Node *p,int index,int x)
{
  Node *t;
  if(index<0 || index > Length(p))
  return;

  if(index == 0)
  {
    t= new Node;
    t->data = x;
    t->next = first;
    t->previous = NULL;
    first->previous = t;
    first = t;
  }
  else
  {
    int i;
    for(i=0;i<index-1;i++) //  for(i=0;i<index-1 && p ;i++)  soldakinde p değeri sürekli artıp alakasız bir adresi göstermesin...
    {
      p=p->next;
    }
    t= new Node;
    t->data = x;

    t->next = p->next;
    t->previous = p;
    if(p->next)
    {
      p->next->previous = t;
    }
    p->next =t;

  }
}
int Delete(Node *p,int index)
{

    int x = -1;

    if(index < 1 || index > Length(p))
      return -1;
    if(index == 1)
    {
      first = first->next;
      if(first)
      {
        first->previous = NULL;

      }
      x = p->data;
      delete p;
      return x;
    }
    else
    {
      for (size_t i = 0; i < index-1; i++)
      {
            p = p->next;
      }
        p->previous->next = p->next;
        if(p->next)
        {
          p->next->previous = p->previous;

        }
        x = p->data;
        delete p;
        return x;
    }
  }
int main()
{
  int A[] {3,5,7,8,10};
  create(A,5);
  Reverse(first);
//  cout<<Delete(first,3)<<" is deleted\n";
  Display(first);
}
