
// A simple C program for traversal of a linked list 
#include <stdio.h> 
#include <stdlib.h> 
  
struct Node { 
    char data; 
    struct Node* next; 
}; 
  
// This function prints contents of linked list starting from 
// the given node 
void printList(struct Node* n) 
{ 
    while (n != NULL) { 
        printf(" %c ", n->data); 
        n = n->next; 
    } 
    printf("\n");
} 
  
void main() 
{ 
    // printf("Enter what letter of the alphabet you want to print up to: ");
    // int element;
    // scanf("%d\n", &element);
    struct Node* head = NULL; 
    struct Node* second = NULL; 
    struct Node* third = NULL; 
  
    // allocate 3 nodes in the heap 
    head = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node)); 
  
    head->data = 'a'; // assign data in first node 
    head->next = second; // Link first node with second 
  
    second->data = 'b'; // assign data to second node 
    second->next = third; 
  
    third->data = 'c'; // assign data to third node 
    third->next = NULL; 
    // for(int i = 0; i < element; i++){
    //     if(i == element-1){
    //         head->next=NULL;
    //     }
    //     else{
    //         head->data = (char)(i+32);
    //         head->next = second;

    //     }
    // }
  
    printList(head); 
   
}