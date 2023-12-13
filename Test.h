//@author Саранчин К.А.
#pragma once
#include <iostream>
//#include "Hash-table.h"
//#include "LinkedList.h"
#include <cassert>


void testHashTableInsert() {
    // Создаем экземпляр хэш-таблицы
    HashTable<int> hashTable1(5, SimpleHashFunction);

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

    cout << "Тест обновления пройден" << endl;
}

