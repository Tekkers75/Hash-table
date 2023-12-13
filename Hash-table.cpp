// Hash-table.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Hash-table.h"

 // Пример хэш-функции для целых чисел
unsigned long HashInt(int key) {
    return static_cast<unsigned long>(key);
}

int main() {
    // Создаем хэш-таблицу с 5 корзинами для целых чисел
    HashTable<int> hashTable(5, HashInt);

    // Вставляем элементы в хэш-таблицу
    hashTable.Insert(10);
    hashTable.Insert(20);
    hashTable.Insert(30);
    hashTable.Insert(40);
    hashTable.Insert(10);
    hashTable.Insert(20);
    hashTable.Insert(30);
    hashTable.Insert(40);
    hashTable.Insert(10);
    hashTable.Insert(20);
    hashTable.Insert(30);
    hashTable.Insert(40);
    hashTable.Insert(10);
    hashTable.Insert(20);
    hashTable.Insert(30);
    hashTable.Insert(40);



    hashTable.PrintTable();

    // Проверяем наличие элементов в хэш-таблице
    std::cout << "Element 20: " << (hashTable.Find(20) ? "Found" : "Not found") << std::endl;
    std::cout << "Element 50: " << (hashTable.Find(50) ? "Found" : "Not found") << std::endl;

    // Удаляем элемент из хэш-таблицы
    hashTable.Delete(30);
    hashTable.PrintTable();

    // Проверяем наличие удаленного элемента
    std::cout << "Element 30: " << (hashTable.Find(30) ? "Found" : "Not found") << std::endl;

    // Обновляем элемент в хэш-таблице
    hashTable.Update(20, 25);
    hashTable.PrintTable();

    // Проверяем наличие обновленного элемента
    std::cout << "Element 20: " << (hashTable.Find(20) ? "Found" : "Not found") << std::endl;
    std::cout << "Element 25: " << (hashTable.Find(25) ? "Found" : "Not found") << std::endl;

    // Очищаем хэш-таблицу
    hashTable.ClearList();

    hashTable.PrintTable();

    // Проверяем наличие элементов после очистки
    std::cout << "Element 10: " << (hashTable.Find(10) ? "Found" : "Not found") << std::endl;
    std::cout << "Element 40: " << (hashTable.Find(40) ? "Found" : "Not found") << std::endl;


    hashTable.PrintTable();
    return 0;
}