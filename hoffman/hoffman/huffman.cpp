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
void Huffman::display(const List<Pair<std::string, double> > & in_list, std::ostream & out) const
{
   display(in_list, out, tree, "");
}

/*******************************************
* HUFFMAN:: DISPLAY
* Recursively displays the Huffman code
*******************************************/
void Huffman::display(const List<Pair<std::string, double> > & in_list, std::ostream & out, const BinaryNode<Pair<std::string, double> > * tree, string path) const
{
   List <Pair<string, string> > bitString;
   buildBitStrings(tree, bitString, "");
   for (ListIterator<Pair<string, double> > lit = in_list.begin(); lit != in_list.end(); ++lit)
   {
      for (ListIterator<Pair<string, string> > it = bitString.begin(); it != bitString.end(); ++it)
      {
         if ((*lit).first == (*it).second)
            out << (*it).second << " = " << (*it).first << endl;
      }
   }
}

/*******************************************
* HUFFMAN:: BUILDBITSTRINGS
* Builds the codes for the individual nodes
*******************************************/
void Huffman::buildBitStrings(const BinaryNode<Pair<std::string, double> > * tree, List <Pair<string, string> > & bitString, string path) const
{
   if (tree == NULL)
      return;

   if ("" != tree->data.first)
   {
      Pair<string, string> pair = Pair<string, string>(path, tree->data.first);
      bitString.push_back(pair);
   }

   buildBitStrings(tree->pLeft, bitString, path + "0");
   buildBitStrings(tree->pRight, bitString, path + "1");
}
