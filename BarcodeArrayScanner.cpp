#include <iostream>
#include <fstream>
#include "UPC.h"

using namespace std;

int main() {

	//This program tests a search scenario for an array of various sizes. The amount of points will determine the amount of data. 
	int POINTS = 6;
	int SIZE = 1;

	//This is the search function. As each array needs to be of the right size, we create a new array each time.
	for(int i = 0; i<POINTS; i++) {
	SIZE *= 10;
	UPC* scanner = new UPC[SIZE];
	fstream read;
        read.open("upc_corpus.txt");
        string value;
        string words;
	UPC last;
	//Read a commma AND new line based text into our UPC objects and save the last one to perform a search
        for(int i = 0; i<SIZE; i++) {
                getline(read, value, ',');
                getline(read, words);
                UPC curr(value, words);
		last = curr;
                scanner[i] = curr;
        }

	UPC found;
	//Track time and search
	clock_t t = clock();
	for(int i = 0; i<SIZE; i++) {
		if(scanner[i] == last) {
			found = scanner[i];
			break;
		}
	}
	t = clock()-t;
	cout<<found<<endl;
	cout<<"Time to search: "<<t<<" milliseconds"<<endl;
	cout<<"Size of file: "<<SIZE<<endl;
	delete[] scanner;
	}

	return 0;
}
