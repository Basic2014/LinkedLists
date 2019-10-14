//C Implementation
#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *first = nullptr;

void CreateLinkedList(int A[],int n)
{
  int i;

  Node *temp;
  Node *last;

  first = new Node;
  first->data = A[0];
  first->next = nullptr;
  last = first;

  for(i = 1;i<n;i++)
  {
    temp = new Node;
    temp->data = A[i];
    temp->next = nullptr;
    last->next = temp;
    last = temp;
  }

}

//Method #1 O(n)
void Reverse1( Node *p)
{
 int *A;
 i=0;
 struct Node *q=p;

 A=new int;

 while(q!=NULL)
 {
   A[i]=q->data;
   q=q->next;
   i++;
 }

 q=p;
 i--;

 while(q!=NULL)
 {
 q->data=A[i];
 q=q->next;
 i--;
 }
}

//sliding pointers
void Reverse2( Node *p)
{

 Node *q=NULL,*r=NULL;

 while(p!=NULL)
 {
 r=q;
 q=p;
 p=p->next;
 q->next=r;
 }
 first=q;
}

void Reverse3( Node *q, Node *p)
{
 if(p)
 {
 Reverse3(p,p->next);
 p->next=q;
 }
 else
 first=q;
}

Node *LSearch(Node *p,int key)
{
  while(p!=NULL)
  {
    if(p->data == key)
    {
      return p;
    }
    p=p->next;
  }
  return NULL;
}

//Move to Head for Linear Search for improvement
Node *LSearch_M(Node *p,int key)
{
  Node *q;
  while(p!=NULL)
  {
    if(p->data == key)
    {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    q=p;
    p=p->next;
  }
  return NULL;
}
Node *RSearch(Node *p,int key)
{
    if(p==NULL)
      return NULL;

    if(p->data == key)
    {
      return p;
    }
    else
    {
      return RSearch(p->next,key);
    }

}


int Count(Node *p)
{
  int count{0};
  while(p)
  {
    ++count;
    p = p->next;
  }
  return count;

}

//Dizi boş olsada LL yaratır
void Insert(Node *p,int index,int x)
{
  Node *t;
  if(index<0 || index > Count(p))
  return;

  t= new Node;
  t->data = x;

  if(index == 0)
  {
    t->next = first;
    first = t;
  }
  else
  {
    int i;

    for(i=0;i<index-1;i++) //  for(i=0;i<index-1 && p ;i++)  soldakinde p değeri sürekli artıp alakasız bir adresi göstermesin...
    {
      p=p->next;
    }
    t->next = p->next;
    p->next=t;

  }
}
int Delete(Node *p,int index)
{
    Node *q {nullptr};
    int x = -1;

    if(index<1 || index > Count(p))
      return -1;
    if(index == 1)
    {
      x = first->data;
      q = first;
      first = first->next;
      delete q;
      return x;
    }
    else
    {
      for (size_t i = 0; i < index-1; i++)
      {
            q = p;
            p = p->next;
      }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }

}


int RCount(Node *p)
{
  if(p==nullptr)
    return 0;
  else
    return RCount(p->next) + 1;
}

int Sum(Node *p)
{
  int sum{0};
  while(p!=nullptr)
  {
    sum += p->data;
    p=p->next;
  }
return sum;
}

int RSum(Node *p)
{
  if(p==nullptr)
    return 0;
  else
    return RSum(p->next) + p->data;
}

int Max(Node *p)
{
  int max = INT32_MIN;
  while(p!=nullptr)
  {
    if(p->data > max)
    {
      max = p->data;
      p=p->next;
    }
  }
  return max;
}

int RMax(Node *p)
{
  int x {0};

  if(p==nullptr)
    return INT32_MIN;
  else
  {
    x = RMax(p->next);
    // return (x>p->data)?x:p->data; Alttaki ile aynı işi yapar
    if(x > p->data)
    {
      return x;
    }
    else
    {
      return p->data;
    }
  }

}


//O(n)
void Display(Node *p)
{
  while(p!=nullptr)
  {
    cout<<p->data<<" ";
    p = p->next;
  }
}

//Recursive version
//O(n) prints reversed
void RecursiveDisplay(Node *p)
{
  if(p!=nullptr)
  {
    Recursive(p->next);
    cout<<p->data<<" ";
  }
}

void SortedInsert(Node *p,int x)
{
  Node *t = new Node;
  Node *q=nullptr;

  t->data = x;
  t->next = NULL;

  if(first == NULL)
  {
    first = t;
  }

  else
  {
    while(p && p->data <x)
    {
      q = p;
      p= p->next;
    }
    if(p == first)
    {
      t->next = first;
      first = t;
    }
    else
    {
      t->next = q->next;
      q->next = t;
    }
  }

}

int IsSorted(Node *p)
{
  int x {-65536};
  while(p!=nullptr)
  {
    if(p->data < x)
    return 0;
    else
    {
      x = p->data;
      p= p->next;

    }
  }
  return 1;
}


void RemoveDuplicates(Node *p)
{
  Node *q = p->next;

  while(q!=NULL)
  {
    if(p->data != q->data)
    {
      p = q;
      q = q->next;
    }
    else
    {
      p = q->next;
      delete q;
      q = p->next;
    }
  }
}

int isLoop( Node *f)
{
  Node *p,*q;
  p=f;
  q=f;

 do
 {
 p=p->next;
 q=q->next;
 q= q != NULL ? q->next : q; // if(q!=null) {q = q->next;}

 }
 while(p && q && p != q);

 if(p==q)
 return 1;
 else
 return 0;
}

int main()
{
  Node *temp;
  int A[] {3,5,7,8,10};

  CreateLinkedList(A,5);

   if(isLoop(first)) { cout<<"Loop\n";}
   else{cout<<"Linear\n";}



  /*
  if(IsSorted(first))
  {
    cout<<"Sorted List\n";
  }
  else
  {
    cout<<"Not Sorted List\n";
  }
  cout<<endl;

  Reverse3(NULL,first);
  Display(first);
  cout<<endl;
  Recursive(first);
  cout<<endl;
  cout<<"Count : "<<Count(first)<<endl;
  cout<<"Sum : "<<Sum(first)<<endl;
  cout<<"Count : "<<RCount(first)<<endl;
  cout<<"Sum : "<<RSum(first)<<endl;
  cout<<"Max : "<<Max(first)<<endl;
  //cout<<"Max : "<<RMax(first)<<endl;
  temp = LSearch(first,12);
  if(temp)
  {
    cout<<temp->data<<" is found"<<endl;
  }
  else
  {
    cout<<"Key not found"<<endl;
  }
  Display(first);
  cout<<endl;
  SortedInsert(first,2);
  cout<<endl;
  Display(first);

  Insert(first,2,20);
  int x{0};
  x = Delete(first,2);
  if(x!=-1)
  {
    cout<<x<<" is deleted\n";
  }
  else
  {
    cout<<"Out of range\n";
  }
  */
  return 0;
}
