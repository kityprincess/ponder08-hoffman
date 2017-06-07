#ifndef BRYAN_AND_MATT_CPP
#define BRYAN_AND_MATT_CPP

#include "huffman.h"
#include "list.h"

/*
typedef BinaryNode<double> BNode;
typedef BNode* BNodePtr;
typedef List<BNodePtr> BNodeList;
typedef Pair<string, double> CodePair;
typedef List<CodePair> CodePairList;


BNodeList buildBNodeListFromPairsList(const CodePairList & in_list)
{
   BNodeList newList;
   return newList;
}

void getMinimums(const BNodeList & in_list, ListIterator<BNodePtr> & out_minFirst, ListIterator<BNodePtr> & out_minSecond)
{

}
*/

/*******************************************
* HUFFMAN :: BUILDTREE
* Driver program to exercise the huffman generation code
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