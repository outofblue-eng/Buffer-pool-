/* 
 * File:   BufferBlock.hpp
 * Author: Professor Terri Sipantzi
 *
 * Created on August 25, 2012, 8:49 AM
 * Modified 05/13/2022 -- Prof Sipantzi -- Replaced #ifndef with #pragma once
 */

#pragma once

#include <iostream>
#include <string>

using namespace std;

class BufferblockADT {
private:
    //Instance variables:
	//	int blockID;
	//	char* block;
    
public:
    
	//sz is the size of the character array data
	//points to.
	BufferblockADT() {}
    BufferblockADT(char* data, int sz = 4096) {}
	virtual ~BufferblockADT() {}
    
    //read the block from pos to pos + sz-1 (or to the end of the block)
    virtual void getData(int pos, int sz, char* data) = 0;
    
    //setID
    virtual void setID(int id) = 0;
    
    //getID
    virtual int getID() const = 0;
    
    //getBlocksize
    virtual int getBlocksize() const = 0;
     
    //return the block
    virtual char* getBlock() const = 0;
    
    //set the block
    virtual void setBlock(char* blk) = 0;
	
	// do not make any changes to this file or you will not get
	// any credit for your work -- Prof Sipantzi (05/13/2022)
};




