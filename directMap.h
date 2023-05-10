#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>

using namespace std;

// Define a struct to represent a cache block
struct cacheBlock {
    string tag;  // The tag bits for the cache block
    bool valid;  // Indicates if the cache block contains valid data
    // You can add additional fields here if needed
};

class DirectMapped {
private:
    int cacheSize;  // The size of the cache in bytes
    int blockSize;  // The size of each cache block in bytes
    int numBlocks;  // The number of cache blocks
    vector<cacheBlock> cache;  // The cache data structure
    int numHits;
    int numMisses;

public:
    DirectMapped(int cacheSize, int blockSize) {
        // Initialize the cache size and block size
        this->cacheSize = cacheSize;
        this->blockSize = blockSize;
        this -> numHits = 0;
        this-> numMisses = 0;

        // Calculate the number of cache blocks based on the cache size and block size
        this->numBlocks = cacheSize / blockSize;

        // Initialize the cache with empty blocks
        for (int i = 0; i < numBlocks; i++) {
            cacheBlock block;
            block.valid = false;
            cache.push_back(block);
        }
    }

    // Accesses the cache at the given memory address
    void accessCache(string address) {
        // Convert the hexadecimal address to a binary string
        stringstream ss;
        ss << hex << address;
        
        bitset<64> bits(stoull(ss.str(), nullptr, 16));
        
        string binaryAddress = bits.to_string();



        // Calculate the cache index and tag bits for the given memory address
        int cacheIndex = bits.to_ulong() / blockSize % numBlocks;
        string tagBits = binaryAddress.substr(0, binaryAddress.length() - log2(blockSize) - log2(numBlocks));

        // Check if the cache block at the given index contains valid data
        if (cache[cacheIndex].valid) {
            // Check if the tag bits for the cache block match the tag bits for the memory address
            if (cache[cacheIndex].tag == tagBits) {
                // Cache hit, no action needed
                // cout << "Cache hit" << endl;
                numHits++;
                return;
            } else {
                // Cache miss, update the cache block with the new tag bits
                cache[cacheIndex].tag = tagBits;
                // cout << "Cache miss, updated cache block" << endl;
                numMisses++;
                return;
            }
        } else {
            // Cache miss, update the cache block with the new tag bits and set the valid bit
            cache[cacheIndex].tag = tagBits;
            cache[cacheIndex].valid = true;
            numMisses++;
            // cout << "Cache miss, updated cache block and set valid bit" << endl;
            return;
        }
    }

    int getNumHits() {
        return numHits;
    }
// Returns the number of cache misses
    int getNumMisses() {
        return numMisses;
    }

    float getHitRate() {
        return (float) numHits / (numHits + numMisses);
    }
};
