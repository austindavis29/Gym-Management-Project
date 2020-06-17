// Austin Davis
// Program to create a Gym Management System
//This is the header file
#include <iostream>
#include <fstream>
using namespace std;

class Person
{
	private:
		string firstName;
		string lastName;
	public:
		Person();
		Person(string,string);
		void setPerson(string,string);
		string getFirstName() const;
		string getLastName() const;
		void printPerson() const;
};

class Member: public Person
{
	private:
		int IDnumber;
	public:
		Member();
		Member(string,string,int);
		void setMember(string,string,int);
		int getIDNumber() const;
		void printMember() const;
};

class Worker: public Person
{
	private:
		string position;
	public:
		Worker();
		Worker(string,string,string);
		void setWorker(string,string,string);
		string getPosition() const;
		void printWorker() const;
};

void readInNames(string firstNames[], string lastNames[]);
void createMembers(string firstNames[], string lastNames[], Member list[]);
int Menu(int &choice);
void swap(Member* member1, Member* member2);
void searchForMember(Member list[]);
int partitionID(Member list[], int low, int high);
void sortByID(Member list[], int low, int high);
int partitionName(Member list[], int low, int high);
void sortByName(Member list[], int low, int high);


