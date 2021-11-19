#include<iostream>
#include<string>
#include<cassert>
#include"HashTable.h"

int idx = 0;
HashTable::HashTable()
{
	used = 0;
	size = 0;
	hashData = nullptr;
}

HashTable::HashTable(int size)
{
	used = 0;
	this->size = size;
	hashData = new studentRecord[size];
	for (size_t i = 0; i < size; i++)
	{
		hashData[i].studentID = -1;
	}
}

int HashTable::getUsed() const
{
	return used;
}

void HashTable::setSize(int s)
{
	size = s;
	hashData = new studentRecord[size];
}

int HashTable::getSize() const
{
	return size;
}

void HashTable::insert(const studentRecord& student)
{
	bool itemPresent;
	int index = 0;
	findIndex(student.studentID, itemPresent, index);
	if (!itemPresent) {
		assert(getUsed() < getSize());
		used++;
	}
	hashData[index] = student;
}

void HashTable::find(int key, bool& found, studentRecord& student)
{
	findIndex(key, found, idx);
	if (found)
	{
		student = hashData[idx];

	}
}

void HashTable::findIndex(int key, bool& found, int& i)
{
	int count{ 0 };
	i = hash(key);
	found = hashData[i].studentID == key;
	std::cout << "Found student ID " << found << std::endl;
}

int HashTable::hash(int key) const
{
	return key % getSize();
}

void HashTable::display()
{
	std::cout << "Displaying Student Records!" << std::endl;
	std::cout << "------------------------------------------------" << std::endl;
	for (size_t i = 0; i < getSize(); i++)
	{
		if (hashData[i].studentID != -1 && hashData[i].studentID != -1000) {
			std::cout << "Sudent ID: " << hashData[i].studentID << std::endl;
			std::cout << "Student Name: " << hashData[i].name << std::endl;
			std::cout << "OOP 345 marks: " << hashData[i].marks_oop345 << std::endl;
			std::cout << "------------------------------------------------" << std::endl;
		}

	}
}

bool HashTable::deleteRecord(int key)
{
	bool success{ false }, itemPresent;
	int index{ 0 };
	findIndex(key, itemPresent, index);
	if (itemPresent) {
		hashData[index].studentID = -1000;
		success = true;
	}
	return success;
}

HashTable::~HashTable()
{
	delete hashData;
	hashData = nullptr;
}
