/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#ifndef HUFFMANCODE_H
#define HUFFMANCODE_H

#include "pair.h"
#include "bnode.h"
#include "list.h"
#include <string>
#include <iostream>
#include "huffman.h"

void huffman(std::string filename);

class HuffmanCode
{
public:
   HuffmanCode() { }
   ~HuffmanCode()
   {
      // we need to clear the code to avoid memory leaks
      code.clear();
   }

   void load(std::string filename); // translate into a list of pairs, merge pairs into tree (private functions)
   void display(); // iterate over the list of pairs in correct order using the bNodes
private:
   List<Pair<std::string, double> > pairs;
   Huffman code;
   void getPairs(std::string filename); // read from file
   Huffman buildTree(const List<Pair<std::string, double> > & in_list); // final bNodes tree
};

#endif // HUFFMAN_h
