#pragma once
#include "BufferPoolADT.h"
#include "LRUBufferBlock.h"
#include <string>
#include <fstream>
using namespace std;

// ADT for buffer pools using the message-passing style
class LRUBufferPool: public BufferPoolADT {
private:
	//The buffer pool consists of X number of buffer blocks
	fstream fin;
	Bufferblock* buffPool;
	int sizeOfPool;
	int sizeOfBlock;
	char* data;

public:
	//Constructor gets the filename of the file to be buffered,
	//opens the file, and instantiates poolSize buffer blocks by
	//reading the file and filling the blocks in order.  When the constructor
	//is done the buffer pool blocks should be full with the beginning
	//contents of the input file.
	LRUBufferPool() {}
	LRUBufferPool(string filename, int poolSize = 5, int blockSize = 4096) {
		
		fin.open(filename.c_str(), fstream::in | fstream::binary);
		if (fin)
		{
			sizeOfPool = poolSize;
			sizeOfBlock = blockSize;
			data = new char[blockSize];
			buffPool = new Bufferblock[poolSize];
			for (int i = 0; i < poolSize; i++)
			{

				fin.read(data, blockSize);

				buffPool[i].setBlock(data);
				buffPool[i].setID(i);
				
			}
		}
		else
		{
			cout << "File does not exist or file could not be opened." << endl;
		}
	}
	virtual ~LRUBufferPool() {
		fin.close();
	}

	// Copy "sz" bytes from position "pos" of the buffered
	//   storage to "space".
	void getBytes(char* space, int sz, int pos) {
		int spos = pos % (sizeOfBlock);
		bool found = false;
		int tempID = pos / sizeOfBlock;

		for (int i = 0; i < sizeOfPool; i++)
		{
			if (buffPool[i].getID() ==tempID)
			{
				found = true;
				buffPool[i].getData(spos, sz, space);
				Bufferblock temp = buffPool[i];
				for (int j = i; j > 0; j--)
				{
					buffPool[j] = buffPool[j - 1];
				}
				buffPool[0] = temp;				
			}
		}

		if (found==false) 
		{
			fin.seekg(sizeOfBlock * tempID);
			fin.read(data, sizeOfBlock);
			buffPool[sizeOfPool-1].setBlock(data);
			buffPool[sizeOfPool - 1].getData(spos, sz, space);
			buffPool[sizeOfPool-1].setID(tempID);

			Bufferblock temp = buffPool[sizeOfPool-1];
			for (int j = (sizeOfPool-1); j > 0; j--)
			{
				buffPool[j] = buffPool[j - 1];
			}
			buffPool[0] = temp;
		}
		
	}

	// Print the order of the buffer blocks using the block id
	//	 numbers.
	void printBufferBlockOrder(){
		cout << "My buffer block order from most recently used to LRU is: " << endl;
		for (int i = 0; i < sizeOfPool; i++) {
			if (i == (sizeOfPool - 1))
				cout << buffPool[i].getID();
			else
			{
				cout << buffPool[i].getID() << ", ";
			}		
			
		}
		cout << endl;
	}

	// Get the block id number of the least recently used 
	//	 buffer block.
	int getLRUBlockID() {
		return buffPool[sizeOfPool - 1].getID();
	}
};




