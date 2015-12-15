#include <stdio.h>

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct Node* head;

void insert(int,int);
void delete(int);
void reverse();
void print();

int main()
{
  head = NULL; //Empty list
  int data,pos;
  char choice='y';
  while(choice=='y'||choice=='Y')
  {
    printf("Enter the data to be inserted and\nPosition of insertion: ");
    scanf("%d%d",&data,&pos);
    insert(data,pos);
    printf("\nThe list is:\n");
    display();
    printf("Do you want to insert more elements?(y/n): ");
    scanf(" %c",&choice);
  }
  do
  {
    printf("\nThe list is:\n");
    display();
    printf("Enter the nPosition of deletion: ");
    scanf("%d",&pos);
    delete(pos);
    printf("Do you want to delete more elements?(y/n): ");
    scanf(" %c",&choice);
  }while(choice=='y'||choice=='Y');
  printf("The list is:\n");
  display();
  printf("The list after reversal is:\n");
  reverse();
  display();
}

void insert(int x,int n)
{
  struct Node *t1 = (struct Node*)malloc(sizeof(struct Node));
  struct node *t2 = head;
  int i;
  t1->data = x;
  t1->next = NULL;
  t1->prev = NULL;
  if(n==0)
  {
    head = t1;
    return;
  }
  for(i=0;i<n-1;i++)
    t2 = t2->next;
  t1->next = t2->next;
  t1->prev = t2;
  t2->next = t1;
}

void delete(int n)
{
  struct Node *t1 = head;
  int i;
  for(i=0;i<n-1;i++)
    t1 = t1->next;
  t1->prev->next = t1->next;
  free(t1);
}

void print()
{
  struct Node *t1 = head;
  while(t1!=NULL)
  {
    printf("%d->",t1->data);
    t = t->next;
  }
  printf("!!!\n");
}

void reverse()
{
  struct Node *current=head,*next;
  while(current!=NULL)
  {
    next = current->next;
    current->next = current->prev;
    current = next;
  }
  head = current->prev;
}
