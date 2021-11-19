#include<iostream>
#include <string>
#include"HashTable.h"


int main() {

	HashTable stdRecords;
	studentRecord student;
	bool found{ false };
	bool quit{ false };
	int choice{ 0 };
	std::string name{};
	int v{ 0 }, num{ 0 };

	while (!quit && choice != 5)
	{
		
		
		std::cout << "-------------------------------------------------------------\n"
			<< "                  Hash Table operations test                \n"
			<< "----------------------------------------------------------------------\n";
		if (stdRecords.getSize() == 0) {
			std::cout << "Create Student record table" << std::endl;
			std::cout << "Enter class size: ";
			std::cin >> num;
			stdRecords.setSize(num);
		}
		std::cout << "1. Insert student Data\n"
			<< "2. Delete\n"
			<< "3. Display\n"
			<< "4. Search\n"
			<< "5. Exit\n\n";
		std::cout << "Enter choice: ";
		std::cin >> choice;
		std::cout <<"---------------------------------------------------------------" << std::endl;

		switch (choice)
		{
		case 1:
			std::cout << "How many Students(cannot be more than table size): ";
			std::cin >> num;
			if (num > stdRecords.getSize() ||num != (stdRecords.getSize() - stdRecords.getUsed())) {
				std::cout << "Error! Number of students cannot be greater than Record table size!" << std::endl;
			}
			else {
				for (size_t i = 0; i < num; i++)
				{
					std::cout << "Enter student ID: ";
					std::cin >> student.studentID;
					std::cout << "Enter student name: ";
					std::getline(std::cin>>std::ws, student.name);
					std::cout << "Enter student OOP 345 score: ";
					std::cin >> student.marks_oop345;

					stdRecords.insert(student);
					std::cout << std::endl;
				}
			}
			break;
		case 2:
			std::cout << "Enter student ID to delete: ";
			std::cin >> num;
			stdRecords.deleteRecord(num);
			break;
		case 3:
			stdRecords.display();
			break;
		case 4:
			std::cout << "Enter Student by Student ID to search: ";
			std::cin >> num;
			found = stdRecords.find(num,student);
			if (found) {
				std::cout << "Student ID: " << student.studentID << std::endl;
				std::cout << "Student Name: " << student.name << std::endl;
				std::cout << "OOP 345 score: " << student.marks_oop345 << std::endl;
			}
			break;
		case 5:
			quit = true;
			exit(1);
			break;
		default:
			std::cout << "Invalid selection!" << std::endl;
			break;
		}


	}



	return 0;
}
