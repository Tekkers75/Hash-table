//@author Саранчин К.А.
#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;




// Класс хэш-таблицы.
template <class T>
class HashTable
{
private:
    int numBuckets; // Число блоков

    vector <LinkedList<T>> buckets; // Хэш-таблица - вектор связанных списков
    // using 
    unsigned long (*hashFunction)(const T &key); // Указатель на хэш-функцию

public:
    // Конструктор класса HashTable
    HashTable<T>(int nbuckets, unsigned long (*hashf)(const T& key))
        : numBuckets(nbuckets), hashFunction(hashf) {
        buckets.resize(numBuckets); // Инициализация вектора блока
    }

    // Вставка элемента в хэш-таблицу
    void Insert(const T& key) {
        unsigned long hashValue = hashFunction(key);
        int bucketIndex = hashValue % numBuckets; // Вычисление индекса блоков
        buckets[bucketIndex].insert(key); // Вставка элемента в блок
    }


    // Поиск элемента в хэш-таблице
    bool Find(const T& key) {
        unsigned long hashValue = hashFunction(key);
        int bucketIndex = hashValue % numBuckets; // Вычисление индекса блоков
        return buckets[bucketIndex].search(key); // Поиск элемента в блоке
    }

    // Удаление элемента из хэш-таблицы
    void Delete(const T& key) {
        unsigned long hashValue = hashFunction(key);
        int bucketIndex = hashValue % numBuckets; // Вычисление индекса блоков
        buckets[bucketIndex].remove(key); // Удаление элемента из блока
    }

    // Очистка всех блоков хэш-таблицы
    void ClearList() {
        for (int i = 0; i < numBuckets; ++i) {
            buckets[i].clear();
        }
    }

    // Обновление значения ключа в хэш-таблице
    void Update(const T& oldKey, const T& newKey) {
        unsigned long oldHashValue = hashFunction(oldKey);
        int oldBucketIndex = oldHashValue % numBuckets; // Вычисление индекса старого блока

        unsigned long newHashValue = hashFunction(newKey);
        int newBucketIndex = newHashValue % numBuckets; // Вычисление индекса нового блока

        if (oldBucketIndex == newBucketIndex) {
            buckets[oldBucketIndex].update(oldKey, newKey); // Обновление значения ключа в одном блоке
        }
        else {
            buckets[oldBucketIndex].remove(oldKey); // Удаление старого ключа из старого блока
            buckets[newBucketIndex].insert(newKey); // Вставка нового ключа в новый блок
        }
    }

    // Вывод хэш-таблицы
    void PrintTable() {
        for (int i = 0; i < numBuckets; ++i) {
            cout << "Блок " << i << ": ";
            buckets[i].print();
            cout << endl;
        }
    }
};

//хэширование по последней цифре
unsigned long SimpleHashFunction(const int &key) {
    return key % 10;
}

//хэширование по размеру строки
unsigned long HashFunction(const string& key) 
{
    /// todo добавить по символьно 
    return  key.length();
}

// хэширование djb2
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

// хэширование FNV 
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