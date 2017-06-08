/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include "huffman.h"       // for HUFFMAN() prototype
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
   ifstream fin(filename);

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
void HuffmanCode :: display(ostream & out)
{
   return;
}

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman(std::string filename)
{
   HuffmanCode hc;
   hc.load(filename);
   return;
}
