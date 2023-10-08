#include <iostream>
#include <stdlib.h>

using namespace std;
const int SIZE = 4;



template <typename t>
class Node {
public:
    t data;
    Node<t>* next;

    Node(t value) : data(value), next(nullptr) {}
};

template <typename t>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    // Function to add a new element to the front of the list
    void pushFront(T value) {
        Node<t>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to print the elements in the list
    void print() {
        Node<t>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructor to free memory
    ~LinkedList() {
        Node<t>* current = head;
        while (current != nullptr) {
            Node<t>* next = current->next;
            delete current;
            current = next;
        }
    }
};

template <typename t>
t* merge(t*, t*);
int main()

{

  int s1[SIZE]  ={5,6,7,8};
  int s2[SIZE] = { 2,3,4,9};

  int * s3 = merge(s1, s2);
  
  
  for(int i = 0 ; i < 8; i++)
  {
    cout << s3[i] << " " ;
  }
  cout << endl;
};

template <typename t> 
 t* merge(t s1[], t s2[])
{
  cout << &s1 << " -2" << endl;
  t* temp = new t[8];
  int i1 = 0;
  int i2 = 0;

  for(int i = 0; i < 8; i++)
  {
    if(s1[i1] < s2[i2]){
      temp[i] = s1[i1];
      i1 ++;
    }
    else
    {
      temp[i] = s2[i2];
      i2++;
    }
  }
  

  return temp;

}

template <typename t>
Node<t>* merge(Node s1, Node s2)
{
  // h
  Node<t> * head;
  Node<t> * tail;
  Node<t> * s1front= &s1;
  Node<t> * s2front= &s2;


  if (s1.data < s2.data){
    head= &s1;
    tail = &s1;
    s1front =  s1.next;
  }
  else
  {
    head = &s2
    tail = &s2
    s2front = s2.next;
  }

  while(s1front!= nullptr || s2front != nullptr)
  {
    if(s1front->data < s2front->data){
      tail->next = s1front;

      tail = s1front;

      s1front = s1front->next;
    }
    else if(s1front->data >= s2front->data){
      tail->next = s2front;

      tail = s2front;

      s2front = s2front->next;
    }
  }  
  if(s1front  == nullptr){

    tail->next = s2front;
  } 
  else
  {
    tail->next = s1front;
  }
  tail = nullptr;
  s2front = nullptr;
  s1front = nullptr;
  return front;
}
  






