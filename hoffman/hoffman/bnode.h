#ifndef	BNODE_H
#define	BNODE_H

#include <iostream>
using namespace std;

/***********************************************************************
 * BNODE CLASS                                                                  * Class to move throughout a tree
***********************************************************************/
template <class T>
class BinaryNode
{
public:
   BinaryNode() : pLeft(NULL), pRight(NULL), pParent(NULL), numElements(1) {}
   BinaryNode(T in_data): data(in_data), pRight(NULL), pParent(NULL), pLeft(NULL), numElements(1) {}
   void addLeft(const T & t);
   void addLeft(BinaryNode <T> * pAdd);
   void addRight(const T & t);
   void addRight(BinaryNode <T> * pAdd);
   int size();


   public:
   BinaryNode <T> * pLeft;
   BinaryNode <T> * pRight;
   BinaryNode <T> * pParent;
   T data;
   int numElements;
};

/************************************************************
* Delete Binary Tree:
* Deletes all the elements in the tree
************************************************************/
template <class T>
void deleteBinaryTree(BinaryNode<T> * in_tree)
{
   if (in_tree == NULL)
      return;
   deleteBinaryTree(in_tree->pLeft);
   deleteBinaryTree(in_tree->pRight);
   delete in_tree;
}

/*****************************************
 * BNODE :: INSERTION OPERATOR
 * Display the contents of the list forwards
 ****************************************/
template <class T>
ostream & operator << (ostream & out, const BinaryNode <T> * element)
{
   if (element == NULL)
      return out;
   if (element->pLeft)
      out << element->pLeft;
   out << element->data;
   out << " ";
   if (element->pRight)
      out << element->pRight;
   return out;
}

template<class T>
inline void BinaryNode<T>::addLeft(const T & in_data)
{
   BinaryNode<T> * leftNode = new BinaryNode<T>(in_data);
   leftNode->pParent = this;
   pLeft = leftNode;
}

template<class T>
inline void BinaryNode<T>::addLeft(BinaryNode<T>* in_tree)
{
   pLeft = in_tree;
   if (pLeft)
      pLeft->pParent = this;
}

template<class T>
inline void BinaryNode<T>::addRight(const T & in_data)
{
   BinaryNode<T> * rightNode = new BinaryNode<T>(in_data);
   rightNode->pParent = this;
   pRight = rightNode;
}

template<class T>
inline void BinaryNode<T>::addRight(BinaryNode<T>* in_tree)
{
   pRight = in_tree;
   if (pRight)
      pRight->pParent = this;
}

/*****************************************
 * BNODE :: SIZE
 * Number of elements in tree
*****************************************/
template <class T>
int BinaryNode <T> :: size()
{
   int size = 1;

   if (pLeft)
      size += pLeft->size();

   if (pRight)
      size += pRight->size();

   return size;
}

#endif // BNODE_H
