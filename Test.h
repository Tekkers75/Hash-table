//@author Саранчин К.А.
#pragma once
#include <iostream>
//#include "Hash-table.h"
//#include "LinkedList.h"
#include <cassert>

void AddTable()
{
    HashTable<string> hashTable(5, Djbhash);
    hashTable.Insert("apple");
    hashTable.Insert("banana");
    hashTable.Insert("orange");
    hashTable.Insert("grape");
    hashTable.Insert("watermelon");

}

void testHashTableInsert() {
    // Создаем экземпляр хэш-таблицы
    HashTable<int> hashTable1(5, IntHashFunc);

    // Вставляем элементы в хэш-таблицу
    hashTable1.Insert(10);
    hashTable1.Insert(20);
    hashTable1.Insert(30);

    // Проверяем наличие вставленных элементов
    assert(hashTable1.Find(10) == true);
    assert(hashTable1.Find(20) == true);
    assert(hashTable1.Find(30) == true);

    // Проверяем отсутствие невставленного элемента
    assert(hashTable1.Find(40) == false);

    // Вставляем дубликат элемента
    hashTable1.Insert(10);

    // Проверяем, что дубликат успешно вставлен
    assert(hashTable1.Find(10) == true);

    HashTable<string> hashTable(5, Djbhash);
    hashTable.Insert("apple");
    hashTable.Insert("banana");
    hashTable.Insert("orange");
    hashTable.Insert("grape");
    hashTable.Insert("watermelon");

    assert(hashTable.Find("apple") == true);
    assert(hashTable.Find("orange") == true);
    assert(hashTable.Find("watermelon") == true);

    // Проверяем отсутствие невставленного элемента
    assert(hashTable.Find("lemon") == false);

    // Вставляем дубликат элемента
    hashTable.Insert("apple");

    // Проверяем, что дубликат успешно вставлен
    assert(hashTable.Find("apple") == true);


    cout << "Тест вставки и поиска пройден" << endl;
}

void testHashTableDelete() {
    // Создаем экземпляр хэш-таблицы
    HashTable<int> hashTable(5, SimpleHashFunction);

    // Вставляем элементы в хэш-таблицу
    hashTable.Insert(10);
    hashTable.Insert(20);
    hashTable.Insert(30);

    // Удаляем элементы из хэш-таблицы
    hashTable.Delete(10);
    hashTable.Delete(20);

    // Проверяем, что удаленные элементы больше не присутствуют
    assert(hashTable.Find(10) == false);
    assert(hashTable.Find(20) == false);
    assert(hashTable.Find(30) == true);


    HashTable<string> hashTable1(5, Djbhash);
    hashTable1.Insert("apple");
    hashTable1.Insert("banana");
    hashTable1.Insert("orange");
    hashTable1.Insert("grape");
    hashTable1.Insert("watermelon");

    // Удаляем элементы из хэш-таблицы
    hashTable1.Delete("banana");
    hashTable1.Delete("grape");

    // Проверяем, что удаленные элементы больше не присутствуют
    assert(hashTable1.Find("banana") == false);
    assert(hashTable1.Find("grape") == false);
    assert(hashTable1.Find("orange") == true);

    cout << "Тест удаления пройден" << endl;

}

void testHashTableClearList() {
    // Создаем экземпляр хэш-таблицы
    HashTable<int> hashTable(5, SimpleHashFunction);

    // Вставляем элементы в хэш-таблицу
    hashTable.Insert(10);
    hashTable.Insert(20);
    hashTable.Insert(30);

    // Очищаем все блоки хэш-таблицы
    hashTable.ClearList();

    // Проверяем, что все элементы были удалены
    assert(hashTable.Find(10) == false);
    assert(hashTable.Find(20) == false);
    assert(hashTable.Find(30) == false);

    HashTable<string> hashTable1(5, Djbhash);
    hashTable1.Insert("apple");
    hashTable1.Insert("banana");
    hashTable1.Insert("orange");
    hashTable1.Insert("grape");
    hashTable1.Insert("watermelon");

    hashTable1.ClearList();

    // Проверяем, что все элементы были удалены
    assert(hashTable1.Find("apple") == false);
    assert(hashTable1.Find("grape") == false);
    assert(hashTable1.Find("watermelon") == false);


    cout << "Тест очистки пройден" << endl;
}

void testHashTableUpdate() {
    // Создаем экземпляр хэш-таблицы
    HashTable<int> hashTable(5, SimpleHashFunction);

    // Вставляем элемент в хэш-таблицу
    hashTable.Insert(10);

    // Обновляем значение ключа
    hashTable.Update(10, 20);

    // Проверяем, что старый ключ больше не присутствует, а новый ключ добавлен
    assert(hashTable.Find(10) == false);
    assert(hashTable.Find(20) == true);


    HashTable<string> hashTable1(5, Djbhash);
    hashTable1.Insert("apple");
    hashTable1.Insert("banana");
    hashTable1.Insert("orange");
    hashTable1.Insert("grape");
    hashTable1.Insert("watermelon");

    // Обновляем значение ключа
    hashTable1.Update("apple", "яблоко");

    // Проверяем, что старый ключ больше не присутствует, а новый ключ добавлен
    assert(hashTable1.Find("apple") == false);
    assert(hashTable1.Find("яблоко") == true);


    cout << "Тест обновления пройден" << endl;
}

