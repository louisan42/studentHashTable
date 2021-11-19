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
	for (size_t i = 0; i < size; i++)
	{
		hashData[i].studentID = -1;
	}
}

int HashTable::getSize() const
{
	return size;
}

void HashTable::insert(const studentRecord& student)
{
	int index = 0;
	bool itemPresent = findIndex(student.studentID, index);
	
	if (!itemPresent) {
		assert(getUsed() < getSize());
		used++;
	}
	hashData[index] = student;
	
}

bool HashTable::find(int key, studentRecord& student)
{
	bool found{ false };
	
	if (findIndex(key, idx))
	{
		student = hashData[idx];
		std::cout << "Student Found!" << std::endl;
		found = true;

	}
	else {
		std::cout << "Student not found!" << std::endl;
	}
	return found;
}

bool HashTable::findIndex(int key, int& i)
{
	bool found{ false };
	int count{ 0 };
	i = hash(key);
	
	return hashData[i].studentID == key;
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

void HashTable::deleteRecord(int key)
{
	int index{ 0 };
	;
	if (findIndex(key, index)) {
		 hashData[index].studentID = -1000;
		 hashData[index].name.clear();
		 hashData[index].marks_oop345 = 0.0f;
		std::cout << "Student deleted successfully!" << std::endl;
	}
	else {
		std::cout << "Student not in records table" << std::endl;
	}
}

HashTable::~HashTable()
{
	delete hashData;
	hashData = nullptr;
}
