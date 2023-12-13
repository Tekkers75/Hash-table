//@author Саранчин К.А.

#include <iostream>
#include "Hash-table.h"

 // Пример хэш-функции для целых чисел
//unsigned long HashInt(int key) {
//    return static_cast<unsigned long>(key);
//}

//хэширование по последней цифре
unsigned long SimpleHashFunction(int key) {
    return key % 10; 
}

int main() {
    setlocale(LC_ALL, "rus");
    // Создаем хэш-таблицу с 5 блоками и хэш функцией
    HashTable<int> hashTable(8, SimpleHashFunction);

    // Вставляем элементы в хэш-таблицу
    hashTable.Insert(11);
    hashTable.Insert(22);
    hashTable.Insert(33);
    hashTable.Insert(44);
    hashTable.Insert(12);
    hashTable.Insert(25);
    hashTable.Insert(36);
    hashTable.Insert(47);
    hashTable.PrintTable();

    // Проверяем наличие элементов в хэш-таблице
    std::cout << "Элемент 20: " << (hashTable.Find(20) ? "Найден" : "Не найден") << std::endl;
    std::cout << "Элемент 50: " << (hashTable.Find(50) ? "Найден" : "Не найден") << std::endl;

    // Удаляем элемент из хэш-таблицы
    hashTable.Delete(30);
    hashTable.PrintTable();

    // Проверяем наличие удаленного элемента
    std::cout << "Элемент 30: " << (hashTable.Find(30) ? "Найден" : "Не найден") << std::endl;

    // Обновляем элемент в хэш-таблице
    hashTable.Update(20, 25);
    hashTable.PrintTable();

    // Проверяем наличие обновленного элемента
    std::cout << "Элемент 20: " << (hashTable.Find(20) ? "Найден" : "Не найден") << std::endl;
    std::cout << "Элемент 25: " << (hashTable.Find(25) ? "Найден" : "Не найден") << std::endl;

    // Очищаем хэш-таблицу
    hashTable.ClearList();

    hashTable.PrintTable();

    // Проверяем наличие элементов после очистки
    std::cout << "Элемент 10: " << (hashTable.Find(10) ? "Найден" : "Не найден") << std::endl;
    std::cout << "Элемент 40: " << (hashTable.Find(40) ? "Найден" : "Не найден") << std::endl;


    hashTable.PrintTable();
    return 0;
}