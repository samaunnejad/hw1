#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <string>
#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/*
function to access front item to return const reference to front element 
*/
std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}

/*
function to access back item to return const reference to back element
*/
std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}


/* 
 * Adds a new value to the back of the list
 */
void ULListStr::push_back(const std::string& val)
{

  if(tail_ == nullptr){

   Item* newItem = new Item();
    tail_ = newItem;
    head_ = newItem;
    tail_->val[tail_->first] = val;

    tail_->last++; 

  }

  else if(tail_->last == ARRSIZE){

    Item* newItem = new Item();

    tail_->next = newItem;
    newItem->prev = tail_;

    tail_ = newItem;

    tail_->val[tail_->first] = val; 

    tail_->last++;

  }
  else{

    tail_->val[tail_->last] = val; 

    tail_->last++; 

  }

  size_++;

}




/*
* Adds a new value to the front of the list.
*/
void ULListStr::push_front(const std::string& val)
{
  
  if(head_ == nullptr){

   Item* newItem = new Item();
    tail_ = newItem;
    head_ = newItem;

    head_->last = ARRSIZE; 

    head_->first = ARRSIZE -1; 

    head_->val[head_->first] = val;

  }

  else if(head_->first == 0){

    Item* newItem = new Item();


    head_->prev = newItem;
    newItem->next = head_;

    head_ = newItem;

    head_->first = ARRSIZE;
    head_->last = ARRSIZE; 

    head_->val[head_->first-1] = val; 
    head_->first--;
    
  }
  else{
    
    head_->val[head_->first-1] = val; 

    head_->first--; 

  }

  size_++;
}


std::string*  ULListStr::getValAtLoc(size_t loc) const
 {
  Item *currItem = head_;
  if(!currItem) return NULL;
  int currIndex = currItem->first;
   for(int i = 0;i<(int)loc;i++){
     if(!currItem) return NULL;
     currIndex++;
     if(currIndex == currItem->last){
       currItem = currItem->next;
       currIndex = 0;
     }
   }

   
   std::string* toReturn = new std::string(currItem->val[currIndex]);
   return toReturn;
 }

/**
* Removes a value from the front of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_front()
{

  if(head_==nullptr){
    return;
  }
  else if(head_->first == head_->last-1){
    head_ = head_->next;
    delete head_->prev;
    head_->prev = nullptr;
  }
  else{
    head_->first++;
  } 

  size_--;

}

/*
* Removes a value from the back of the list
*   - MUST RUN in O(1)
*/
void ULListStr::pop_back()
{
  if(tail_==nullptr){
    return;
  }
  else if(tail_->first == tail_->last-1){
    tail_ = tail_->prev;
    delete tail_->next;
    tail_->next = nullptr;

  }
  else{
      tail_->last--; 
  } 

  size_--;

}
  

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


