/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std; 

/* Add a prototype for a helper function here if you need */


void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  if(in == NULL){

    return;
  }
//Checks if value in node is an even & then passes it into evens Node list
  else if(in->value % 2 == 0){
    evens->next = in; 
    evens = evens->next;
    evens->next = NULL;  
  }
//Checks if value in node is an odd & then passes it into odds Node list
  else {
    odds->next = in; 
    odds = odds->next; 
    odds->next = NULL; 
  }

//recursive function that calls itself to split Linked List
   split(in->next, odds, evens); 
}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE

void append(Node* in, int value) 
{
  if(in == NULL){
      return;
  }

  Node* newNode = new Node(value, in);
  in = newNode;

  cout << in->value << " ";

}

void printList(Node* in) 
{
  if(in == NULL){
    return;
  }
  cout << in->value << endl;
  printList(in->next); 

}
