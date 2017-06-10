###############################################################
# Program:
#     Week 08, Binary Tree
#     Brother JonesL, CS235
# Author:
#     Bryan Lopez - 8 hours
#	  Matthew Burr - 8 hours
#	  Kimberly Stowe - 5 hours
#	  Shayla Nelson - 4 hours
# Summary:
#     Put binary nodes into a binary tree and print. 
#	  The hardest part was getting the binary tree to work
#	  with Huffman algorithm. 
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week08.o huffmanCode.o huffman.o
	g++ -o a.out week08.o huffmanCode.o huffman.o -g
	tar -cf week08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week08.o     : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
week08.o: bnode.h huffmanCode.h huffman.h week08.cpp
	g++ -c week08.cpp -g

huffman.o: bnode.h list.h pair.h huffman.h huffman.cpp
	g++ -c huffman.cpp -g

huffmanCode.o: bnode.h list.h pair.h huffman.h huffmanCode.h huffmanCode.cpp
	g++ -c huffmanCode.cpp -g
