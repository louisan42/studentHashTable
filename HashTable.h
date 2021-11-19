#ifndef HASHTABLE_H
#define HASHtABLE_H

//constexpr size_t MAX = 40;

struct studentRecord {
	int studentID;
	std::string name;
	float marks_oop345;
};

class HashTable {
private:
	studentRecord *hashData;
	int used;
	int size;

public:
	HashTable();
	HashTable(int size);
	int getUsed()const;
	void setSize(int s);
	int getSize() const;
	void insert(const studentRecord& student);
	void find(int key, bool& found, studentRecord& student);
	void findIndex(int key, bool& found, int& i);
	int hash(int key)const;
	void display();
	bool deleteRecord(int key);
	~HashTable();
};





#endif // !HASHTABLE_H
