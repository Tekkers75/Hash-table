#pragma once
#include <iostream>
#include "LinkedList.h"
#include <vector>

using namespace std;
template <class T>
class HashTable
{
private:
	int numBuckets;

	vector <LinkedList<T>> buckets;
	unsigned long (*hashFunction)(T key);

public:
	HashTable<T>(int nbuckets, unsigned long (*hashf)(T key))
        : numBuckets(nbuckets), hashFunction(hashf) {
        buckets.resize(numBuckets);
    }

    void Insert(const T& key) {
        unsigned long hashValue = hashFunction(key);
        int bucketIndex = hashValue % numBuckets;
        buckets[bucketIndex].insert(key);
    }

    bool Find(const T& key) {
        unsigned long hashValue = hashFunction(key);
        int bucketIndex = hashValue % numBuckets;
        return buckets[bucketIndex].search(key);
    }

    void Delete(const T& key) {
        unsigned long hashValue = hashFunction(key);
        int bucketIndex = hashValue % numBuckets;
        buckets[bucketIndex].remove(key);
    }

    void ClearList() {
        for (int i = 0; i < numBuckets; ++i) {
            buckets[i].clear();
        }
    }

    void Update(const T& oldKey, const T& newKey) {
        unsigned long oldHashValue = hashFunction(oldKey);
        int oldBucketIndex = oldHashValue % numBuckets;

        unsigned long newHashValue = hashFunction(newKey);
        int newBucketIndex = newHashValue % numBuckets;

        if (oldBucketIndex == newBucketIndex) {
            buckets[oldBucketIndex].update(oldKey, newKey);
        }
        else {
            buckets[oldBucketIndex].remove(oldKey);
            buckets[newBucketIndex].insert(newKey);
        }
    }


    void PrintTable() {
        for (int i = 0; i < numBuckets; ++i) {
            std::cout << "Bucket " << i << ": ";
            buckets[i].print();
            std::cout << std::endl;
        }
    }


};
