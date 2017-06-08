#ifndef BRYAN_AND_MATT_CPP
#define BRYAN_AND_MATT_CPP

#include "huffman.h"
#include "list.h"
//#include <cfloat>

typedef Pair<string, double> Element;
typedef BinaryNode<Element> BNode;
typedef BNode * BNodePtr;
typedef List<BNodePtr> BNodeList;
typedef ListIterator<BNodePtr> BNodeListIter;
typedef List<Element> ElemList;
typedef ListIterator<Element> ElemListIter;

double getValueFromBNodePtr(const BNodePtr in_ptr)
{
   return in_ptr->data.getSecond();
}

BNodeList buildTree(ElemList in_list)
{
   BNodeList list;

   // Populate the initial list
   for (ElemListIter it = in_list.begin();
      it != in_list.end(); ++it)
      list.push_back(new BNode(*it));

   // And now we loop until our list is left
   // with one node: the root of our Huffman Code tree
   while (list.size() > 1)
   {
      // First, we need to find the two minimum values
      // in the list as it stands
      BNodeListIter firstMin = list.end();
      BNodeListIter secondMin = list.end();
      
      for (BNodeListIter it = list.begin();
         it != list.end(); ++it)
      {
         if (firstMin == list.end() ||
            getValueFromBNodePtr(*it) < getValueFromBNodePtr(*firstMin))
         {
            secondMin = firstMin;
            firstMin = it;
         }
         else if (secondMin == list.end() ||
            getValueFromBNodePtr(*it) < getValueFromBNodePtr(*secondMin))
         {
            secondMin = it;
         }
      }

      // Now that we have those, we create a new node that will be their parent
      BNodePtr parent =
         new BNode(
            Element("", getValueFromBNodePtr(*firstMin) + getValueFromBNodePtr(*secondMin))
         );
      parent->addLeft(*firstMin);
      parent->addRight(*secondMin);

      // Then we replace the first minimum node in the list with this new parent
      list.insert(firstMin, parent);
      list.remove(firstMin);

      // And we replace the second node with the last item in the list
      BNodePtr last = *(--list.end());
      list.remove(--list.end());
      list.insert(secondMin, last);
      list.remove(secondMin);
   }

   // And that should be it
   return list;
}

/*******************************************
* HUFFMAN :: BUILDTREE
* Given a list, converts it into a BinaryTree for
* generating Huffman codes
*******************************************/
void HuffmanCode::buildTree()
{
   // 1. Start with a list of BinaryNodes - 1 for each of the characters/string
   //    a. Populate our list of BinaryNodes, using the list of pairs
   //bNodes = buildBNodeListFromPairsList(pairs);

   // 2. Find the two smallest (based on their frequency) from that list
   //ListIterator<BNodePtr> min1 = bNodes.end();
   //ListIterator<BNodePtr> min2 = bNodes.end();

   /*
   while (bNodes.size() > 1)
   {
      getMinimums(bNodes, min1, min2);

      BNode * newNode = new BNode();
      newNode->addLeft(*min1);
      newNode->addRight(*min2);

   }
   */
   // 3. Create a new node, and add those two smallest as the left and right nodes of the new node
   // 4. We'll remove the two nodes from the list, and put the new node into the list
   // 5. Rinse and repeat until we have just 1 node in the list

}

#endif