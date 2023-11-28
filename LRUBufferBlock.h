/*
 * File:   BufferBlock.hpp
 * Author: Professor Terri Sipantzi
 *
 * Created on August 25, 2012, 8:49 AM
 * Modified 05/13/2022 -- Prof Sipantzi -- Replaced #ifndef with #pragma once
 */


#include <iostream>
#include <string>
#include "BufferBlockADT.h"

using namespace std;

class Bufferblock:public BufferblockADT {
private:
    //Instance variables:
    int blockID;
    char* block;
    int size;
public:

    //sz is the size of the character array data
    //points to.
    Bufferblock() {
        size = BLOCKSIZE;
        block = new char[BLOCKSIZE];
    }
    Bufferblock(char* data, int sz = 4096) {
        
        size = sz;
        block = new char[sz];
        for (int i=0;i<sz;i++)
        {
            block[i] = data[i];
        }
    }
    virtual ~Bufferblock() {}

    //read the block from pos to pos + sz-1 (or to the end of the block)
    void getData(int pos, int sz, char* data) {
        
        for(int i = 0, j = pos; j < (pos + sz) && i < size; i++, j++)
        {
            data[i] = block[j];
        }
       
    }

    //setID
    void setID(int id) {
        blockID = id;
    }

    //getID
    int getID() const {
        return blockID;
    }

    //getBlocksize
    int getBlocksize() const
    {
        return size;
    }

    //return the block
    char* getBlock() const {
        return block;
    }

    //set the block
    void setBlock(char* blk) {
        for (int i = 0; i < size; i++) {
            block[i] = blk[i];
       }
    }
};




