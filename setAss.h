#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>
#include <unordered_map>
#include <queue>

using namespace std;


// Define a struct to represent a cache block
struct cache_S {
    string tag;  // The tag bits for the cache block
    bool valid;  // Indicates if the cache block contains valid data
    int lastUsed; // Used for LRU replacement policy to store the time of last use
    // You can add additional fields here if needed
};

class SetAssociative{
private:
    int cacheSize;  // The size of the cache in bytes
    int blockSize;  // The size of each cache block in bytes
    int numBlocks;  // The number of cache blocks
    int numSets;    // The number of sets in the cache
    vector<vector<cache_S>> cache;  // The cache data structure
    unordered_map<string, int> tagToIndex; // A hash table for fast lookup of tags
    int numHits;
    int numMisses;
    int numWays; // Number of ways for the set associative cache
    queue<int> fifoQueue; // Queue to store the FIFO replacement policy

public:
    SetAssociative(int cacheSize, int blockSize, int numWays, bool isFifo) {
        // Initialize the cache size, block size, and number of blocks per set
        this->cacheSize = cacheSize;
        this->blockSize = blockSize;
        this -> numHits = 0;
        this-> numMisses = 0;
        this->numWays = numWays;

        // Calculate the number of cache blocks based on the cache size and block size
        this->numBlocks = cacheSize / blockSize;

        // Calculate the number of sets in the cache based on the number of ways
        this->numSets = numBlocks / numWays;

        // Initialize the cache with empty blocks
        for (int i = 0; i < numSets; i++) {
            vector<cache_S> set;
            for (int j = 0; j < numWays; j++) {
                cache_S block;
                block.valid = false;
                set.push_back(block);
            }
            cache.push_back(set);
        }
    }

    // Accesses the cache at the given memory address
    void accessCache(string address, bool isFifo) {
        // Convert the hexadecimal address to a binary string
        stringstream ss;
        ss << hex << address;
        bitset<64> bits(stoull(ss.str(), nullptr, 16));
        string binaryAddress = bits.to_string();

        // Calculate the cache index and tag bits for the given memory address
        int setIndex = bits.to_ulong() / blockSize % numSets;
        string tagBits = binaryAddress.substr(0, binaryAddress.length() - log2(blockSize) - log2(numSets));

        // Check if the cache set at the given index contains valid data
        bool cacheHit = false;
        for (int i = 0; i < cache[setIndex].size(); i++) {
            if (cache[setIndex][i].valid && cache[setIndex][i].tag == tagBits) {
                // Cache hit, no action needed
                cacheHit = true;
                numHits++;

                if (!isFifo) {
                    // Update the LRU information
                    cache[setIndex][i].lastUsed = numHits;
                }
                break;
            }
        }

        if (!cacheHit) {
            int blockToReplace = -1;
            for (int i = 0; i < cache[setIndex].size(); i++) {
            	if (!cache[setIndex][i].valid) {
                	// Found an empty block, use it
                	blockToReplace = i;
                	break;
            	}

            	if (!isFifo) {
                	// Find the LRU block
                	if (blockToReplace == -1 || cache[setIndex][i].lastUsed < cache[setIndex][blockToReplace].lastUsed) {
                    	blockToReplace = i;
                	}
            	} else if (isFifo) {
                	// Find the block that was inserted first
                	if (blockToReplace == -1 || cache[setIndex][i].lastUsed < cache[setIndex][blockToReplace].lastUsed) {
                    	blockToReplace = i;
                	}
            	}
        }

        // Update the cache with the new block
        cache_S block;
        block.tag = tagBits;
        block.valid = true;
        block.lastUsed = numHits;
        cache[setIndex][blockToReplace] = block;

        // Update the tag index hash table
        tagToIndex[tagBits] = setIndex * numSets + blockToReplace;

        numMisses++;
        }
    }

    float getHitRate() {
        return (float) numHits / (numHits + numMisses);
    }
};
