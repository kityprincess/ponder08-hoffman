#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "bnode.h"
#include "pair.h"
#include "list.h"
#include <string>
#include <iostream>

/*****************************************************
   CLASS: HUFFMAN
   A helper class that organizes some of the work needed
   to build a binary tree to store a Huffman code. This
   sort of follows a Builder design pattern
******************************************************/
class Huffman
{
public:
   Huffman()
   {
      tree = NULL;
   }

   Huffman(Pair<std::string, double> item)
   {
      tree = new BinaryNode<Pair <std::string, double > >(item);
   }

   // Gets the frequency of this Huffman node
   double getFrequency() const
   {
      return tree->data.getSecond();
   }

   // Gets the value of this Huffman node
   string getValue() const
   {
      return tree->data.getFirst();
   }

   // Adds a Huffman node to this one, which will create a new
   // tree with two child subtrees
   void add(Huffman * rhs);

   // Displays the Huffman tree to an ostream
   void display(const List<Pair<std::string, double> > & in_list, std::ostream & out) const;

   // Destroys the binary tree inside the Huffman
   // class to avoid memory leaks
   void clear()
   {
      deleteBinaryTree(tree);
   }

private:
   // The tree holding all the binary nodes making up the Huffman Code tree
   BinaryNode< Pair < std::string, double > > * tree;

   // Used to display the nodes of the tree with their individual codes prepended
   void display(const List<Pair<std::string, double> > & in_list, std::ostream & out, const BinaryNode<Pair<std::string, double> > * tree, string path) const;

   void buildBitStrings(const BinaryNode<Pair<std::string, double> > * tree, List <Pair<string, string> > & bitString, string path) const;

   List <Pair<string, string> > bitString;
};
#endif
