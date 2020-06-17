// Austin Davis
// Program to create a Gym Management System
//This is the function implementation file
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "GymManagementProject.h"
using namespace std;

Person::Person()
{
	firstName = "John";
	lastName = "Doe";
}

Person::Person(string fir, string las)
{
	firstName = fir;
	lastName = las;
}

void Person::setPerson(string fir, string las)
{
	firstName = fir;
	lastName = las;
}

string Person::getFirstName() const
{
	return firstName;
}

string Person::getLastName() const
{
	return lastName;
}


//Include function comments
void Person::printPerson() const
{
	cout << "Name: " << firstName << " " << lastName << endl;
}

Member::Member()
{
	IDnumber = 0;
}

Member::Member(string fir, string las, int IDn) : Person(fir,las)
{
	IDnumber = IDn;
}

void Member::setMember(string fir, string las, int IDn)
{
	Person::setPerson(fir,las);
	IDnumber = IDn;
}

int Member::getIDNumber() const
{
	return IDnumber;
}



void Member::printMember() const
{
	Person::printPerson();
	cout << "ID number: " << setw(5) << setfill('0') << IDnumber << endl;
 }
 
Worker::Worker()
{
	position = "associate";
}

Worker::Worker(string fir,string las,string pos) : Person(fir,las)
{
	position = pos;
}

void Worker::setWorker(string fir, string las, string pos)
{
	Person::setPerson(fir,las);
	position = pos;
}

string Worker::getPosition() const
{
	return position;
}

void Worker::printWorker() const
{
	Person::printPerson();
	cout << "Position: " << position << endl;
}

void readInNames(string firstNames[], string lastNames[]) 
{
	ifstream infile;
	infile.open("FirstNames.txt");
	for (int i=0;i<100; i++)
	{
		infile >> firstNames[i];
		infile >> ws;
	}
	
	infile.close();
	
	infile.open("LastNames.txt");
	
	for (int j=0;j<100; j++)
	{
		infile >> lastNames[j];
		infile >> ws;
	}
	
	infile.close();
	
}


void createMembers(string firstNames[], string lastNames[], Member list[])
{
	srand(time(0));
	string first = " ";
	string last = " ";
	int IDnum = 0;
	int num = 0;
	for (int i=0; i<100; i++)
	{
		num = rand() % 100;
		first = firstNames[num];
		num = rand() % 100;
		last = lastNames[num];
		IDnum = rand() % 99999;
		list[i].setMember(first,last,IDnum);
	}
	
	
}

int Menu(int &choice)
{
     cout << "Enter 1 to print list of members" << endl
     	  << "Enter 2 to search for a member" << endl
     	  << "Enter 3 to sort by Member ID" << endl
          << "Enter 4 to sort by members names alphabetically" << endl
          << "Enter 5 to Quit"                               << endl;
     cin >> choice;
     return choice;
}

void searchForMember(Member list[])
{
	int choice = 0;
	int count = 0;
	int ID = 0;
	string name;
	cout << "How would you like to search for this member's information?" << endl;
	cout << "Press 1 for Member ID or 2 for last name" << endl;
	cin >> choice;
	if (choice==1)
	{
		cout << "Enter a valid five digit ID" << endl;
		cin >> ID;
		for(int i=0; i<100; i++)
		{
			if(ID == list[i].getIDNumber())
			{
				list[i].printMember();
				count++;
			}
		}	
		if (count == 0)
			cout << "There was no match for the number entered" << endl;
		count = 0; //resets count for the next query
	}
	else if (choice==2)
	{
		cout << "Enter a valid last name" << endl;
		cin >> name;
		for(int i=0; i<100; i++)
		{
			if(name == list[i].getLastName())
			{	
				list[i].printMember();
				count++;
			}
		}	
		if (count == 0)
			cout << "There was no match for the name entered" << endl; 
		count = 0; //resets count for the next query
	}
	else
	{
		cout << "Error: Incorrect input" << endl;
	}
	
}

void swap(Member* member1, Member* member2)
{
	Member temp = *member1;
	*member1 = *member2;
	*member2 = temp;
}

int partitionID(Member list[], int low, int high)
{
	int pivot = list[high].getIDNumber();
	int i = (low - 1);
	
	for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (list[j].getIDNumber() < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&list[i], &list[j]);  
        }  
    }  
    swap(&list[i + 1], &list[high]);  
    return (i + 1);  
}  


//will be using quicksort
void sortByID(Member list[], int low, int high)
{
 	 if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partitionID(list, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        sortByID(list, low, pi - 1);  
        sortByID(list, pi + 1, high);  
    }  
}

int partitionName(Member list[], int low, int high)
{
	string pivot = list[high].getLastName();
	int i = (low - 1);
	
	for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (list[j].getLastName() == pivot)
        {
        	if (list[j].getFirstName() < list[high].getFirstName() ) //This ensures that if two people have the same name then the   
	        {  														 //first name is used to calculate alphabetical order.
	            i++; // increment index of smaller element  
	            swap(&list[i], &list[j]);  
	        }  
		}
        if (list[j].getLastName() < pivot)  
        {  
            i++; // increment index of smaller element  
            swap(&list[i], &list[j]);  
        }  
    }  
    swap(&list[i + 1], &list[high]);  
    return (i + 1);  
}

void sortByName(Member list[], int low, int high)
{
	if (low < high)  
    {  
        /* pi is partitioning index, arr[p] is now  
        at right place */
        int pi = partitionName(list, low, high);  
  
        // Separately sort elements before  
        // partition and after partition  
        sortByName(list, low, pi - 1);  
        sortByName(list, pi + 1, high);  
    }  
}






