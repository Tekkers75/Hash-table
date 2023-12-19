//@author �������� �.�.
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
    // ������� ��������� ���-�������
    HashTable<int> hashTable1(5, IntHashFunc);

    // ��������� �������� � ���-�������
    hashTable1.Insert(10);
    hashTable1.Insert(20);
    hashTable1.Insert(30);

    // ��������� ������� ����������� ���������
    assert(hashTable1.Find(10) == true);
    assert(hashTable1.Find(20) == true);
    assert(hashTable1.Find(30) == true);

    // ��������� ���������� �������������� ��������
    assert(hashTable1.Find(40) == false);

    // ��������� �������� ��������
    hashTable1.Insert(10);

    // ���������, ��� �������� ������� ��������
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

    // ��������� ���������� �������������� ��������
    assert(hashTable.Find("lemon") == false);

    // ��������� �������� ��������
    hashTable.Insert("apple");

    // ���������, ��� �������� ������� ��������
    assert(hashTable.Find("apple") == true);


    cout << "���� ������� � ������ �������" << endl;
}

void testHashTableDelete() {
    // ������� ��������� ���-�������
    HashTable<int> hashTable(5, SimpleHashFunction);

    // ��������� �������� � ���-�������
    hashTable.Insert(10);
    hashTable.Insert(20);
    hashTable.Insert(30);

    // ������� �������� �� ���-�������
    hashTable.Delete(10);
    hashTable.Delete(20);

    // ���������, ��� ��������� �������� ������ �� ������������
    assert(hashTable.Find(10) == false);
    assert(hashTable.Find(20) == false);
    assert(hashTable.Find(30) == true);


    HashTable<string> hashTable1(5, Djbhash);
    hashTable1.Insert("apple");
    hashTable1.Insert("banana");
    hashTable1.Insert("orange");
    hashTable1.Insert("grape");
    hashTable1.Insert("watermelon");

    // ������� �������� �� ���-�������
    hashTable1.Delete("banana");
    hashTable1.Delete("grape");

    // ���������, ��� ��������� �������� ������ �� ������������
    assert(hashTable1.Find("banana") == false);
    assert(hashTable1.Find("grape") == false);
    assert(hashTable1.Find("orange") == true);

    cout << "���� �������� �������" << endl;

}

void testHashTableClearList() {
    // ������� ��������� ���-�������
    HashTable<int> hashTable(5, SimpleHashFunction);

    // ��������� �������� � ���-�������
    hashTable.Insert(10);
    hashTable.Insert(20);
    hashTable.Insert(30);

    // ������� ��� ����� ���-�������
    hashTable.ClearList();

    // ���������, ��� ��� �������� ���� �������
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

    // ���������, ��� ��� �������� ���� �������
    assert(hashTable1.Find("apple") == false);
    assert(hashTable1.Find("grape") == false);
    assert(hashTable1.Find("watermelon") == false);


    cout << "���� ������� �������" << endl;
}

void testHashTableUpdate() {
    // ������� ��������� ���-�������
    HashTable<int> hashTable(5, SimpleHashFunction);

    // ��������� ������� � ���-�������
    hashTable.Insert(10);

    // ��������� �������� �����
    hashTable.Update(10, 20);

    // ���������, ��� ������ ���� ������ �� ������������, � ����� ���� ��������
    assert(hashTable.Find(10) == false);
    assert(hashTable.Find(20) == true);


    HashTable<string> hashTable1(5, Djbhash);
    hashTable1.Insert("apple");
    hashTable1.Insert("banana");
    hashTable1.Insert("orange");
    hashTable1.Insert("grape");
    hashTable1.Insert("watermelon");

    // ��������� �������� �����
    hashTable1.Update("apple", "������");

    // ���������, ��� ������ ���� ������ �� ������������, � ����� ���� ��������
    assert(hashTable1.Find("apple") == false);
    assert(hashTable1.Find("������") == true);


    cout << "���� ���������� �������" << endl;
}

