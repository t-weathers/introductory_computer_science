/******************************************************
** Program: list.c
** Author: Thomas Weathers
** Date: 06/09/2018
** Description: this program takes multiple c functions and implements them for linked list manipulation
** Input: user inputted values to add to linked list
** Output: linked list and sorted in whichever direction
******************************************************/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
/********************************************************************
** Function: length()
** Description: finds the length of a linked list
** parameters: struct node * head
** pre-condition: the head of a linked list is given, there are values in the linked list
** post-condition: linked list is unchanged
********************************************************************/
int length(struct node *n){ //get the length of the list
  struct node *temp;
  int length;
  temp = (struct node *)malloc(sizeof(struct node));
  temp = n;
  length = 0;
  while(temp != NULL){
    temp = temp->next;
    length++;
  }
  return length - 1;
}

/********************************************************************
** Function: print()
** Description: this prints the linked list supplied
** parameters: node *head, int length to print
** pre-condition: linked list has more than one val, not NULL
** post-condition: linked list is unchanged
********************************************************************/
void print(struct node *n, int len){
  int i;
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp = n->next;
  i = 0;
  while(temp != NULL && i < len){
    printf("[%d] ",temp->val);
    temp = temp->next;
    i++;
  }
  printf("\n");
} //print a certain number of elements from the list starting with the first node

/********************************************************************
** Function: push()
** Description: creates a new node w given val and pushes to front of list
** parameters: node * head, int value of new node
** pre-condition: head is the head of a linked list, no value here
** post-condition: linked list now has new node w given val at front of it
********************************************************************/
struct node * push(struct node *n, int val){
  struct node *temp;
  struct node *newhead;
  temp = (struct node *)malloc(sizeof(struct node));

  if(n == NULL){
    newhead = (struct node *)malloc(sizeof(struct node));
    temp->val = val;
    temp->next = NULL;
    newhead->next = temp;
    free(n);
    return newhead;
  }
  temp->val = val;
  temp->next = n->next;
  n->next = temp;
  return n;
} //put at front

/********************************************************************
** Function: append()
** Description: creates a new node w given val and attatche to back of list
** parameters: node * head, int value of new node
** pre-condition: head is the head of a linked list, no value here
** post-condition: linked list now has new node w given val at end of it
********************************************************************/
struct node * append(struct node *n, int val){
  struct node *temp;
  struct node *newhead;
  struct node *newnode;
  temp = (struct node *)malloc(sizeof(struct node));
  newnode = (struct node *)malloc(sizeof(struct node));
  temp = n;
  newnode->val = val;
  newnode->next = NULL;
  if(n == NULL){
    newhead = (struct node *)malloc(sizeof(struct node));
    newhead->next = newnode;
    free(n);
    return newhead;
  }
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newnode;
  return n;
} //put at back

/********************************************************************
** Function: clear()
** Description: deletes a linked list, given the head
** parameters: node  * head
** pre-condition: linked list is not NULL
** post-condition: linked list is completely free'd of allocated memory
********************************************************************/
struct node * clear(struct node *n){

  struct node *temp1;
  struct node *temp2;
  temp1 = (struct node *)malloc(sizeof(struct node));
  temp2 = (struct node *)malloc(sizeof(struct node));
  temp1 = n;
  temp2 = n;
  while(temp1 != NULL){
    temp2 = temp1->next;
    temp1 = temp2;
  }
  n = NULL;
  return n;
} //delete entire list

/********************************************************************
** Function: remove_node()
** Description: removes the specific node from LL
** parameters: node * head, index to remove
** pre-condition: the head is a LL with values
** post-condition: node is removed from desired index and LL persists
********************************************************************/
struct node * remove_node(struct node *n, int index){
  int count;
  struct node *temp;
  struct node *temp2;
  count = 0;
  temp = (struct node *)malloc(sizeof(struct node));
  temp2 = (struct node *)malloc(sizeof(struct node));
  temp = n;
  temp2 = NULL;
  while(count < index){
    temp = temp->next;
    count++;
  }
  if(length(n) > index){
    if(length(n) - 1 == index){
      free(temp->next);
      temp->next = NULL;
      return n;
    }
    temp2 = temp;
    temp2= temp2->next->next;
    free(temp->next);
    temp->next = temp2;
    return n;
  }
  return n;
} //delete a particular node

/********************************************************************
** Function: sort_ascending()
** Description: takes the values of a LL and sorts them in ascencding order
** parameters: node * head
** pre-condition: list is unsorted, not NULL
** post-condition: list is sorted ascending order
********************************************************************/
struct node * sort_ascending(struct node *n){ //sort the nodes in ascending order
  struct node *sorted;
  int len;
  int i;
  int highest_index;
  int highest_val;
  struct node *temp;
  int count;
  temp = (struct node *)malloc(sizeof(struct node));
  temp = n;
  sorted = (struct node *)malloc(sizeof(struct node));
  len = length(n);
  for(i = 0; i < len; i++){
    temp = n;
    count = 0;
    highest_val = n->next->val;
    highest_index = 0;
    while(temp->next != NULL){
      temp = temp->next;
      if(temp->val > highest_val){
        highest_index = count;
        highest_val = temp->val;
      }
      count++;
    }
    n = remove_node(n,highest_index);
    sorted = push(sorted,highest_val);
  }
  n = clear(n);
  free(n);
  //free(temp);
  return sorted;
}

/********************************************************************
** Function: sort_descending()
** Description: takes the values of a LL and sorts them in desencding order
** parameters: node * head
** pre-condition: list is unsorted, not NULL
** post-condition: list is sorted descending order
********************************************************************/
struct node * sort_descending(struct node *n){
  struct node *sorted;
  int len;
  int i;
  int lowest_index;
  int lowest_val;
  struct node *temp;
  int count;
  temp = (struct node *)malloc(sizeof(struct node));
  temp = n;
  sorted = (struct node *)malloc(sizeof(struct node));
  len = length(n);
  printf("Here\n");
  for(i = 0; i < len; i++){
    temp = n;
    count = 0;
    printf("Here\n");
    lowest_val = n->next->val;
    printf("Here\n");
    lowest_index = 0;
    while(temp->next != NULL){
      printf("Here1\n");
      temp = temp->next;
      printf("Here\n");
      if(temp->val < lowest_val){
        lowest_index = count;
        lowest_val = temp->val;
      }
      count++;
    }
    n = remove_node(n,lowest_index);
    sorted = push(sorted,lowest_val);
  }
  n = clear(n);
  free(n);
  return sorted;
} //sort the nodes in descending order
//insert into a specific location in the list

/********************************************************************
** Function:insert_middle()
** Description: inserts new node in middle of list, at desired location
** parameters: node * head, value for new node, int index to add
** pre-condition: head is connected to a LL, LL is not null, index isnt out of range
** post-condition: LL with added node at correct spot
********************************************************************/
struct node * insert_middle(struct node *n, int val, int idx){
  struct node *temp;
  struct node *temp2;
  struct node *newnode;
  temp= (struct node *)malloc(sizeof(struct node));
  temp2 = (struct node *)malloc(sizeof(struct node));
  newnode = (struct node *)malloc(sizeof(struct node));
  temp = n;
  int count;
  count = 0;
  newnode->val = val;
  if(length(n) > idx){
    while(count < idx){
      temp = temp->next;
      count++;
    }
    if(length(n) == idx){
      newnode->next = NULL;
      temp->next = newnode;
      return n;
    }
    temp2 = temp;
    temp2 = temp2->next;
    temp->next = newnode;
    newnode->next = temp2;
  }
  else{
    n = append(n,val);
  }
  return n;
}
