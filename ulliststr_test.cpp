/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"

using namespace std;


int main(int argc, char* argv[])
{ 
  ULListStr dat;

  dat.push_back("7");
  dat.push_front("8");
  dat.push_back("9");


 //GIVEN TESTS 
 //FUNCTIONS TESTED: push_front, push_back, size
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  // prints: 8 7 9
  cout << "String Size: " << dat.size() << endl;  // prints 3 since there are 3 strings stored

  dat.push_front("1");
  dat.push_front("2");
  dat.push_front("3");
  dat.push_front("4");
  dat.push_front("5");

  cout << "Updated String Size: " << dat.size() << endl; //prints 8 since there are 8 strings stored

  //prints: 5 4 3 2 1 8 7 9

  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << " " << dat.get(4) << " " << dat.get(5);
  cout << " " << dat.get(6) << " " << dat.get(7) << endl;

  // deletes 9 from the back of the list
  dat.pop_back();

  // deletes 5 from the front of the list
  dat.pop_front();

  // prints: 4 3 2 1 8 7
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << " " << dat.get(3) << " " << dat.get(4) << " " << dat.get(5) << endl;

  cout << "Access Front Item From List: " << dat.front() << endl; 

  cout << "Access Back Item From List: " << dat.back() << endl; 

  return 0;
}
