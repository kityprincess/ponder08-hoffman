#ifndef	BNODE_H
#define	BNODE_H

#include <iostream>
using namespace std;

/***********************************************************************       
 * BNODE CLASS                                                                  * Class to move throughout a tree
***********************************************************************/
template <class	T>
class BinaryNode
{
public:
   BinaryNode() : pLeft(NULL), pRight(NULL), pParent(NULL), numElements(1) {}
   BinaryNode(T t): t(t), pRight(NULL), pParent(NULL), pLeft(NULL), numElements(1) {}
   void addLeft(T & t);
   void addLeft(BinaryNode <T> * t);
   void addRight(T & t);
   void addReft(BinaryNode <T> * t);
   int size();
   
   
   private:
   BinaryNode <T> * pLeft;
   BinaryNode <T> * pRight;
   BinaryNode <T> * pParent;
   T t;
   int numElements;
};

/************************************************************
* Delete Binary Tree:
* Delete's all the elements in the tree
************************************************************/
void deleteBinaryTree();

/*****************************************                                      
 * BNODE :: INSERTION OPERATOR                                                              
 * Display the contents of the list forwards                                    
 ****************************************/
template <class T>
ostream & operator << (ostream & out, const BinaryNode <T> * element)
{   
   return out;
}

/*****************************************                                      
 * BNODE :: SIZE                                                              
 * Number of elements in tree
*****************************************/    
template <class T>
int BinaryNode <T> :: size()
{
   return numElements;
}

#endif // BNODE_H                      
