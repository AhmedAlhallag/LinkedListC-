#include<iostream>
using namespace std;

template <class T> 
class Node
{
public:
  T data;
  Node* next;
  Node();
  Node(T val);
 
};

//------------------------------------------------------------------------ 
template <class T>
class LinkedList
{
private:  
  Node<T>* head, *tail;

public:
  int numElems;

  LinkedList();
  ~LinkedList();
  
  bool isEmpty();
  int length();
  T at(int i);  
  void insertAt(int i, T val);
  T removeAt(int i); 
  void destroy();
  void Append(T val);
  void print();
  void InsertBeforeTail(T val);
  void removeAtStart(); 
  void InsertAtStart(T val);
  void removeThirdElem();



  
};

