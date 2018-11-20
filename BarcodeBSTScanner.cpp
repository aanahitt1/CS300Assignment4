#include "binaryST.h"
#include "UPC.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	//This file will test how fast a search takes using a binary search tree of various sizes. It will test this using the last item inserted, AKA Worst Case Scenario, as the item will be a leaf.
	const int POINTS = 6;
	int SIZE = 1;

	//This loop will formulate each search anew. I create a new tree each time partly in order to mimic the array logic, and also to make the reading of material easier as per the for loop.
	for(int i = 0; i < POINTS; i++) {
	SIZE *= 10;
	BinarySearchTree<UPC>* scanner = new BinarySearchTree<UPC>;
	fstream read;
	read.open("upc_corpus.txt");
	string value;
	string words;
	UPC last;
	//Reads information into the tree. The time to add information to a tree is significantly longer than an array
	for(int i = 0; i<SIZE; i++) {
		getline(read, value, ',');
		getline(read, words);
		UPC curr(value, words);
		last = curr;
		scanner->insert(last);
	}

	//Searches for the last item saved and measures time.
	clock_t t; 
	t= clock();
	UPC found = scanner->search(last);
	t = clock() - t;
	cout<<found<<endl;
	cout<<"Time to search: "<<t<<" milliseconds"<<endl;
	cout<<"Size of file: "<<SIZE<<endl;
	delete scanner;
	}

	return 0;

}
