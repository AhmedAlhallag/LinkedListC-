#include"LinkedList.h"
#include <iostream>
using namespace std; 
#include<assert.h>
#include <cmath>
//------------------------------------------------------------------------ 
template <class T>
Node<T> :: Node()
{
  next = NULL;	
}

//------------------------------------------------------------------------ 
template <class T>
Node<T> :: Node(T val)
{
  data = val;
  next = NULL;	
}

//------------------------------------------------------------------------ 
template <class T>
LinkedList<T>::LinkedList()
{
  head = new Node<T>;
  tail = head;
  numElems = 0;
}

//------------------------------------------------------------------------
template <class T>
LinkedList<T>::~LinkedList()
{
  destroy();  
}

//------------------------------------------------------------------------
template <class T>
bool LinkedList<T>:: isEmpty()
{
	return (numElems == 0);
}

//------------------------------------------------------------------------
template <class T>
void LinkedList<T>::Append(T val)
{
  Node<T>* Appended = new Node<T>(val);
    tail->next= Appended;
    tail = Appended;   //OR  tail = tail->next;

  ++numElems;
}

//------------------------------------------------------------------------
template <class T>
int LinkedList<T>::length()
{
  return numElems;
}

//------------------------------------------------------------------------
template <class T>
T LinkedList<T>::at(int i)
{
  //validate the input
  assert( (i < numElems) && (i >= 0 ) ); 
  
  //find the pointer to position i
  Node<T>* tmp= head;
    for(int k = 0 ; k <= i ; k++)
    tmp = tmp->next;
  
  return tmp->data;    
}

//------------------------------------------------------------------------
template <class T>
void LinkedList<T>::insertAt(int i, T val)
{
  //validate the input
  assert( (i < numElems) && (i >= 0 ) );
  
  //find the pointer to position i-1
  Node<T>* tmp = head;
   for(int k = 0 ; k < i ; k++)
   tmp= tmp->next;
  
  Node<T>* Inserted = new Node<T>(val);
    Inserted->next = tmp->next;
    tmp->next = Inserted;
   
  ++numElems;
}
  
//------------------ NEXT LECTURE -------------------------------------------
template <class T>
T LinkedList<T>::removeAt(int i)
{
  //validate the input
  assert( (i < numElems) && (i >= 0 ) );
  
  //find the pointer to position i-1
  Node<T>* tmp= head;
   for(int k = 0 ; k < i ; k++)
   tmp= tmp->next;
  
  Node<T>* toBeRemoved = tmp->next;
    tmp->next= toBeRemoved->next;
    T val = toBeRemoved->data;
    delete toBeRemoved;
    toBeRemoved = NULL;
  
  --numElems;
  return val;  
}

//------------------------------------------------------------------------
template <class T>
void LinkedList<T>::destroy()
{
  if(numElems == 0 ) return ;
 
  else{
		Node<T>* tmp= head->next;
		while(tmp != NULL)
	     {
		  delete head;
		  head = tmp;
		  tmp = tmp->next;  // here, tmp will be,  tmp = NULL
	     }
	  
   	    delete head;
	    tail= head = NULL;
        numElems = 0;
     } 
}

//------------------------------------------------------------------------ 
template <class T>
void LinkedList<T>::print()
{
 for(int i = 0; i < length(); ++i)
  
 cout << at(i) << '\t';  
 cout << endl;
}
// =============================== Q1.1
template <class T>
void LinkedList<T>::InsertBeforeTail(T val){
	
	if(head->next != NULL){
		
	
	
	Node<T>* Temp  =  head;
	for(int i =0   ; i<numElems-1 ; i++){
		Temp=Temp->next; 
	}
	
	Node<T>* Inserted =  new Node<T>(val);
	Inserted->next =  tail ;
	Temp->next =  Inserted ; 
	++numElems;
}

else{
	cout<<"This list is empty.Append/Insert Some Nodes First"<<endl ; 
	
	
}
	
	
	
}

//==============================Q1.2

template <class T>
void LinkedList<T>::removeAtStart(){
	
	if(head->next !=NULL ){
		
	
	Node<T>* Temp  =  head-> next ; 
	head->next =  Temp->next;
	delete Temp; 
	Temp = NULL; 
	--numElems;
	
}

else{
	cout<<"Please Append Some nodes"<<endl;
}
	
	
}

//==========================Q1.3
template <class T>
void LinkedList<T>::InsertAtStart(T val){
	
	Node<T>* Inserted =  new Node<T>(val);
	Inserted->next =  head->next;
	head->next =  Inserted ; 
	++numElems; 
	
	
	
	
	
	
	
}

//=======================Q1.4

template <class T>
void LinkedList<T>::removeThirdElem(){
	if(numElems >= 3){
	
	Node<T>* Temp = head; 
	for(int i = 0 ; i<2 ;i++){
		Temp= Temp->next; 
	}
	Node<T>* Temp2 = Temp->next; 
	Temp->next = Temp2->next; 
	delete Temp2 ; 
	Temp=NULL;
	--numElems;
	
	}
	else{
		cout<<"This list conatins elements less than 3 , Please Append More"<<endl;
	}
	
	
}













//
//
////==================================  Q2   =================================
//template<class T>
//void LinkedList<T>::enterThenSplitAndInsert(LinkedList &obj1){
//	int num  , tempNum  , size;
//	size=  0; 
//	
//	cout<<"Enter a number :" << endl ; 
//	
//	cin >> num; 
//	
//	tempNum = num ; 
//	
//	while(tempNum != 0 ){
//		
//		tempNum = tempNum/10 ; 
//		++size;
//		
//	}
//	
//		cout<<"The number you entered has " << size << " digits"<< endl ; 
//
//	
//	
//	int temp = 0 ; 
//	
//	for (int i = 0 ; i<size ; i++){
//		temp = num%10;
//		obj1.InsertAtStart(temp);
//		num = num / 10;  
//	}
//	
//obj1.print(); 
//cout<<'\n';
//
//}
////==================================  Q2   =================================
//template <class T>
//T LinkedList<T>::makeWhole(){
//	int tempSize = numElems;  
//	T value = 0 ;  
//	Node<T>* temp = head->next ; 
//	while(tempSize > 0 ) {
//	
//		value = value + ((temp->data) * pow(10,tempSize-1));
//		
//		
//		temp= temp->next; 
//		
//		tempSize--; 
//		
//		
//	}
//	
//	
//	return value  ; 
//}
////==================================  Q2   =================================
//
//template<class T>
//void LinkedList<T>::sumOfTwoNodes(LinkedList obj1 , LinkedList obj2 , LinkedList &obj3 ){
//	int tempResult, size ,Result;
//	size = 0 ; 
//    Result =  0 ; 
//	
//	Result = obj1.makeWhole();
//	Result+= obj2.makeWhole();	
//
//	
//	tempResult = Result ; //tempREsult will be used to knwo the new size of result of the summation 
//	
//	while(tempResult != 0 ){ // first loop to know the number of iteration needed for the second loop to append elements based on the size (or count)
//		
//		tempResult = tempResult/10 ; 
//		++size;
//		
//	}
//
//	int temp = 0 ; 
//	
//	for (int i = 0 ; i<size ; i++){
//		temp = Result%10;
//		obj3.InsertAtStart(temp);
//		Result = Result / 10;  
//	}
//	
//	cout<<"Result : " ;
//	obj3.print();
//	
//	
//}
//
////================================================ Q3 =======================================================
//template <class T>
//void LinkedList<T>::bubbleSort(LinkedList &obj){ // As implemented by Eng eman
//cout<<"Unsorted: " ; 
//obj.print();
//
//T temp;
//for(Node<T>* t1 = head->next    ;    t1 != NULL   ;    t1=t1->next  ){
//
//        for(Node<T>* t2 = t1->next  ;    t2 !=NULL   ;    t2=t2->next    ){
//        	
//        	   if(  t1->data  >  t2->data  ){
//        	   	   temp = t1->data;
//				   t1->data = t2->data;
//				   t2->data = temp; 
//			   }
//        	
//        	
//		}
//
//	
//}
//
//cout<<"Sorted: " ; 
//obj.print();
//cout<<'\n';
//
//	
//}
