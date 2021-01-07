#include <stdio.h>
#include <stdlib.h>

//defines the structure of a linked list node
struct Node
{
  int data;
  struct Node* next;
};

//prints the node by printing then going to the next value the pointer points to
void printList(struct Node* n)
{
  printf("Linked list\n");
  while (n != NULL)
  {
    printf(" %d ", n -> data);
    n = n -> next;
  }
  printf("\n");
}

void append(struct Node* n)
{
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   if (n = NULL)
   {
      
   }
   new_node -> data = new_data;

}

void prepend(struct Node* n)
{
  
}
void delete(struct Node* n)
{
  
}

int main()
{
  //initializes the nodes
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;
  struct Node* final = NULL;

  //sets the sizes to the necessary size for the int and the pointer
  head = (struct Node*)malloc(sizeof(struct Node));
  second = (struct Node*)malloc(sizeof(struct Node));
  third = (struct Node*)malloc(sizeof(struct Node));
  final = (struct Node*)malloc(sizeof(struct Node));

  //defines value and sets pointer ot the next value in the list
  head -> data = 1;
  head -> next = second;
  
  second -> data = 2;
  second -> next = third;

  third -> data = 3;
  third -> next = final;

  //final value ends pointing to null, as it is the last value in the list
  final -> data = 4;
  final -> next = NULL;

  printList(head);

  return 0;
}
