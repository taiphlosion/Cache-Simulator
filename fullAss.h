#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>
#include <algorithm>

using namespace std;

// Define a struct to represent a cache block
struct Cache {
    string tag;  // The tag bits for the cache block
    bool valid;  // Indicates if the cache block contains valid data
    int accessTime;  // The time at which the block was last accessed
};

class FullyAssociative {
private:
    int cacheSize;  // The size of the cache in bytes
    int blockSize;  // The size of each cache block in bytes
    int numBlocks;  // The number of cache blocks
    vector<Cache> cache;  // The cache data structure
    int numHits;
    int numMisses;
    bool fifo;  // Flag to indicate if FIFO or LRU replacement policy should be used

public:
    FullyAssociative(int cacheSize, int blockSize, bool fifo) {
        // Initialize the cache size and block size
        this->cacheSize = cacheSize;
        this->blockSize = blockSize;
        this -> numHits = 0;
        this-> numMisses = 0;
        this->fifo = fifo;

        // Calculate the number of cache blocks based on the cache size and block size
        this->numBlocks = cacheSize / blockSize;

        // Initialize the cache with empty blocks
        for (int i = 0; i < numBlocks; i++) {
            Cache block;
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

        // Calculate the tag bits for the given memory address
        string tagBits = binaryAddress.substr(0, binaryAddress.length() - log2(blockSize));

        // Find the first cache block with invalid data
        int invalidIndex = -1;
        for (int i = 0; i < numBlocks; i++) {
            if (!cache[i].valid) {
                invalidIndex = i;
                break;
            }
        }

        for (int i = 0; i < numBlocks; i++) {
            if (cache[i].valid && cache[i].tag == tagBits) {
                // Cache hit
                numHits++;
                cache[i].accessTime = numMisses + numHits - 1;
                // cout << "Cache hit!" << endl;
                return;
            }
        }

        // If there is an invalid block, use it to store the data
        if (invalidIndex != -1) {
            cache[invalidIndex].tag = tagBits;
            cache[invalidIndex].valid = true;
            cache[invalidIndex].accessTime = numMisses + numHits;
            numMisses++;
            // cout << "Cache miss, inserted data into block " << invalidIndex << endl;
            return;
        }

        // If there is no invalid block, evict a block and replace it with the new data
        if (fifo) {
            // Find the block with the smallest access time (FIFO replacement policy)
            int minIndex = 0;
            for (int i = 1; i < numBlocks; i++) {
                if (cache[i].accessTime < cache[minIndex].accessTime) {
                    minIndex = i;
                }
            }
            cache[minIndex].tag = tagBits;
            cache[minIndex].accessTime = numMisses + numHits;
            numMisses++;
            // cout << "Cache miss, evicted block " << minIndex << " and inserted data" << endl;
        }
        else{
            int minIndex = 0;
            for (int i = 1; i < numBlocks; i++) {
                if (cache[i].accessTime < cache[minIndex].accessTime) {
                    minIndex = i;
                }
            }
            cache[minIndex].tag = tagBits;
            cache[minIndex].accessTime = numMisses + numHits;
            numMisses++;
            // cout << "Cache miss, evicted block " << minIndex << " and inserted data" << endl;
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
