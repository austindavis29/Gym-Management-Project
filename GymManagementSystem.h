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


void readInNames(string firstNames[], string lastNames[]);
void createMembers(string firstNames[], string lastNames[], vector<Member> &list);
int Menu(int &choice);
void swap(Member* member1, Member* member2);
void searchForMember(vector<Member> list, int numOfMembers);
int partitionID(vector<Member> &list, int low, int high);
void sortByID(vector<Member> &list, int low, int high);
int partitionName(vector<Member> &list, int low, int high);
void sortByName(vector<Member> &list, int low, int high);
void addMember(vector<Member> &list, int &numOfMembers);
void removeMember(vector<Member> &list, int &numOfMembers);
