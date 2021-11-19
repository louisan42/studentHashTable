#include<iostream>
#include <string>
#include"HashTable.h"


int main() {

	HashTable stdRecords;
	studentRecord student;
	bool exit{ false };
	int choice{ 0 };
	std::string name{};
	int v{ 0 }, num{ 0 };

	while (!exit)
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
			<< "5. Exit\n";
		std::cout << "Enter choice: ";
		std::cin >> choice;
		std::cout << std::endl;

		switch (choice)
		{
		case 1:
			std::cout << "How many Students(cannot be more than table size): ";
			std::cin >> num;
			if (num > stdRecords.getSize()) {
				std::cout << "Error! Number of students cannot be greater than Record table size!" << std::endl;
			}
			else {
				for (size_t i = 0; i < num; i++)
				{
					std::cout << "Enter stdent ID: ";
					std::cin >> student.studentID;
					std::cout << "Enter stdent name: ";
					std::getline(std::cin, student.name);
					stdRecords.insert(student);
				}
			}
			break;
		case 2:
			std::cout << "Enter age to delete: ";
			std::cin >> num;
			deleteAge(num);
			break;
		case 3:
			display();
			break;
		case 4:
			std::cout << "Enter age to search: ";
			std::cin >> num;
			search(num);
			break;
		case 5:
			exit = true;
			break;
		default:
			std::cout << "Invalid selection!" << std::endl;
			break;
		}


	}



	return 0;
}
