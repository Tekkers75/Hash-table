//@author �������� �.�.
#pragma once
#include <iostream>
//#include "Hash-table.h"
//#include "LinkedList.h"
#include <cassert>


void testHashTableInsert() {
    // ������� ��������� ���-�������
    HashTable<int> hashTable1(5, SimpleHashFunction);

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

    cout << "���� ���������� �������" << endl;
}

