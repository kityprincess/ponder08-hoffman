/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include "huffmanCode.h"       // for HUFFMAN() prototype
#include "pair.h"

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

/*******************************************
 * GET PAIRS
 * read the paired data from a file and add
 * to a list
 *******************************************/
void HuffmanCode :: getPairs(string filename)
{
   // declare stream variable
   ifstream fin(filename.c_str());

   // check for read error
   if (fin.fail())
   {
      cout << "Unable to open file " << filename << endl;
      fin.close();
      return;
   }

   // read in data
   string line;
   while (getline(fin, line))
   {
      try
      {
         // load the line into a stringstream
         stringstream ss;
         ss.str(line);

         // declare variables
         string token;
         double frequency;

         // read in the data
         ss >> token >> frequency;

         // create a pair
         Pair<string, double> pair = Pair<string, double>(token, frequency);
         pairs.push_back(pair);
      }

      // catch any errors
      catch (string message)
      {
         cout << message << endl;
      }
   }
   fin.close();

   return;
}


/*******************************************
* BUILD TREE
* builds the actual binary tree containing
* the Huffman code
*******************************************/
Huffman HuffmanCode::buildTree(const List<Pair<std::string, double> > & in_list)
{
   // We start by creating an array of Huffman nodes, one for each item in the list
   int count = in_list.size();
   Huffman *nodes = new Huffman[count];

   // Here, we populate the array
   {
      int i = 0;
      for (ListIterator<Pair<std::string, double> > it = in_list.begin();
         it != in_list.end(); ++it)
      {
         nodes[i] = Huffman(*it);
         ++i;
      }
   }

   // Now we begin the merging process. This will gradually winnow the
   // Huffman nodes down just to one
   while (count > 1)
   {
      // First, we need to find the positions of the two Huffman nodes that
      // have the minimum values
      int idxMinLeft = -1;
      int idxMinRight = -1;

      for (int i = 0; i < count; i++)
      {
         if (idxMinLeft == -1 || nodes[i].getFrequency() < nodes[idxMinLeft].getFrequency())
         {
            idxMinRight = idxMinLeft;
            idxMinLeft = i;
         }
         else if (idxMinRight == -1 || nodes[i].getFrequency() < nodes[idxMinRight].getFrequency())
         {
            idxMinRight = i;
         }
      }

      // Now, we add the nodes together (merge them) and place the new
      // node in the prior left node's slot. Per the instructions, we
      // then move the last node in our array to occupy the old right-hand
      // node's slot
      if (idxMinRight < idxMinLeft)
      {
         int temp = idxMinRight;
         idxMinRight = idxMinLeft;
         idxMinLeft = temp;
      }
      nodes[idxMinLeft].add(&(nodes[idxMinRight]));
      nodes[idxMinRight] = nodes[count - 1];

      // and we decrement our count in order effectively to trim off the
      // old left node
      count--;
   }

   // In the end, we want to delete our array to avoid a memory leak
   Huffman result = nodes[0];
   delete[] nodes;
   return result;
}

/*******************************************
 * LOAD
 * load the data, translate into a list of pairs,
 * and merge pairs into tree
 *******************************************/
void HuffmanCode :: load(string filename)
{
   getPairs(filename);
   return;
}

/*******************************************
 * DISPLAY
 * display the huffman codes
 *******************************************/
void HuffmanCode :: display()
{
   // to avoid a memory leak in case we already
   // have a code, we clear it
   code.clear();
   code = buildTree(this->pairs);
   code.display(this->pairs, cout);
}

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(std::string filename)
{

   HuffmanCode hc;
   hc.load(filename);
   hc.display();

   return;
}
