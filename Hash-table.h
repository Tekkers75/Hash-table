//@author �������� �.�.
#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;




// ����� ���-�������.
template <class T>
class HashTable
{
private:
    int numBuckets; // ����� ������

    vector <LinkedList<T>> buckets; // ���-������� - ������ ��������� �������
    // using 
    unsigned long (*hashFunction)(const T &key); // ��������� �� ���-�������

public:
    // ����������� ������ HashTable
    HashTable<T>(int nbuckets, unsigned long (*hashf)(const T& key))
        : numBuckets(nbuckets), hashFunction(hashf) {
        buckets.resize(numBuckets); // ������������� ������� �����
    }

    // ������� �������� � ���-�������
    void Insert(const T& key) {
        unsigned long hashValue = hashFunction(key);
        int bucketIndex = hashValue % numBuckets; // ���������� ������� ������
        buckets[bucketIndex].insert(key); // ������� �������� � ����
    }


    // ����� �������� � ���-�������
    bool Find(const T& key) {
        unsigned long hashValue = hashFunction(key);
        int bucketIndex = hashValue % numBuckets; // ���������� ������� ������
        return buckets[bucketIndex].search(key); // ����� �������� � �����
    }

    // �������� �������� �� ���-�������
    void Delete(const T& key) {
        unsigned long hashValue = hashFunction(key);
        int bucketIndex = hashValue % numBuckets; // ���������� ������� ������
        buckets[bucketIndex].remove(key); // �������� �������� �� �����
    }

    // ������� ���� ������ ���-�������
    void ClearList() {
        for (int i = 0; i < numBuckets; ++i) {
            buckets[i].clear();
        }
    }

    // ���������� �������� ����� � ���-�������
    void Update(const T& oldKey, const T& newKey) {
        unsigned long oldHashValue = hashFunction(oldKey);
        int oldBucketIndex = oldHashValue % numBuckets; // ���������� ������� ������� �����

        unsigned long newHashValue = hashFunction(newKey);
        int newBucketIndex = newHashValue % numBuckets; // ���������� ������� ������ �����

        if (oldBucketIndex == newBucketIndex) {
            buckets[oldBucketIndex].update(oldKey, newKey); // ���������� �������� ����� � ����� �����
        }
        else {
            buckets[oldBucketIndex].remove(oldKey); // �������� ������� ����� �� ������� �����
            buckets[newBucketIndex].insert(newKey); // ������� ������ ����� � ����� ����
        }
    }

    // ����� ���-�������
    void PrintTable() {
        for (int i = 0; i < numBuckets; ++i) {
            cout << "���� " << i << ": ";
            buckets[i].print();
            cout << endl;
        }
    }
};

//����������� �� ��������� �����
unsigned long SimpleHashFunction(const int &key) {
    return key % 10;
}

//����������� �� ������� ������
unsigned long HashFunction(const string& key) 
{
    /// todo �������� �� ��������� 
    return  key.length();
}

// ����������� djb2
unsigned long Djbhash(const string& str)
{
    unsigned long hash = 5381;

    for (char c : str)
        hash = ((hash << 5) + hash) + static_cast<unsigned char>(c);

    return hash;
}


unsigned long IntHashFunc(const int& key) {
    unsigned long hash = static_cast<unsigned long>(key);
    hash = (hash ^ (hash >> 16)) * 0x85ebca6b;
    hash = (hash ^ (hash >> 13)) * 0xc2b2ae35;
    hash = hash ^ (hash >> 16);
    return hash;
}

// ����������� FNV 
unsigned long FNVHashFunction(const string& key) {
    const unsigned long FNV_offset_basis = 14695981039346656037ULL;
    const unsigned long FNV_prime = 1099511628211ULL;

    unsigned long hash = FNV_offset_basis;

    for (char c : key) {
        hash ^= static_cast<unsigned long>(c);
        hash *= FNV_prime;
    }

    return hash;
}