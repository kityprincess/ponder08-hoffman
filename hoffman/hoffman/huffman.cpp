#include "huffman.h"

/*******************************************
* HUFFMAN:: ADD
* Adds a Huffman node onto this one, this
* results in creating a new parent node
*******************************************/
void Huffman::add(Huffman * rhs)
{
   // Create the new parent with no value and a frequency that is the sum
   // of the two nodes' frequencies
   BinaryNode<Pair<string, double> > * parent = new BinaryNode<Pair<string, double> >();
   parent->data = Pair<string, double>("", getFrequency() + rhs->getFrequency());
   
   // If the right-hand node has a lower frequency than the left,
   // we need to push it over to become the left child of the new parent
   if (rhs->getFrequency() < getFrequency())
   {
      parent->pLeft = rhs->tree;
      parent->pRight = this->tree;
   }
   else // otherwise, we leave the nodes in their original order
   {
      parent->pLeft = this->tree;
      parent->pRight = rhs->tree;
   }

   // And now our tree will point to this new parent
   this->tree = parent;
}

/*******************************************
* HUFFMAN:: DISPLAY
* Displays the Huffman code to the console
*******************************************/
void Huffman::display(std::ostream & out) const
{
   display(out, tree, "");
}

/*******************************************
* HUFFMAN:: DISPLAY
* Recursively displays the Huffman code, building
* the codes for the individual nodes as it goes along
*******************************************/
void Huffman::display(std::ostream & out, const BinaryNode<Pair<std::string, double>> * tree, string path) const
{
   if (tree == NULL)
      return;

   if ("" != tree->data.first)
      out << path << "\t" << tree->data.first << endl;

   display(out, tree->pLeft, path + "0");
   display(out, tree->pRight, path + "1");
}
