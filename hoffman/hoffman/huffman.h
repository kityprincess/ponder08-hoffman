/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include "pair.h"
#include "bnode.h"
#include "list.h"
#include <string>
#include <iostream>

class HuffmanCode
{
public:
   HuffmanCode() { }
   void huffman(std::string filename);
   void load(std::string filename); // translate into a list of pairs, merge pairs into tree (private functions)
   void display(std::ostream & out); // iterate over the list of pairs in correct order using the bNodes
private:
   List<Pair<std::string, double>> pairs;
   List<BinaryNode> bNodes;
   void getPairs(); // read from file
   void buildTree(); // final bNodes tree
};

#endif // HUFFMAN_h
