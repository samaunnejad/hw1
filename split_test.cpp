
#include <iostream>
#include "split.h"

using namespace std; 


//TEST CLASS
int main()
{
  
  Node* in = new Node(1,nullptr); 
  Node* evens = new Node(4,nullptr); 
  Node* odds = new Node(5,nullptr);

  append(in, 1);
  append(in, 2);
  append(in, 3);
  append(in, 4);
  append(in, 5);
  append(in, 6);

  cout << "\nCurrent List: " << endl;
  printList(in);

  split(in, odds, evens);

  cout <<  "Odds & Evens Split" << endl;
  cout << "Odds: ";
  printList(odds);
  cout << "Evens: ";
  printList(evens);


  return 0;
}