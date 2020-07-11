// Austin Davis
// Program to create a Gym Management System
//This is the header file
#include <iostream>
#include <fstream>
#include <vector>
#include "GymManagementSystem.h"
using namespace std;
int main()
{
	int numOfMembers = 100;
	int choice = 0;
	string firstNames[numOfMembers];
	string lastNames[numOfMembers];
	vector<Member> list(numOfMembers);
 	readInNames(firstNames,lastNames);
 	createMembers(firstNames,lastNames, list);
 	cout << "Welcome to MyGymManager!" << endl << endl;
 	do
    	{
        	 Menu(choice);
        	switch (choice)
            {
                 case 1: //PRINT LIST OF MEMBERS
                         for (int j=0; j<numOfMembers; j++)
						 {
						 	list[j].printMember();
						 }
                         break;
                 case 2: //SEARCH FOR A MEMBER
                         searchForMember(list,numOfMembers);
                         break;
                 case 3: //SORT BY MEMBER ID
                         sortByID(list, 0, numOfMembers-1);
                         break;
                 case 4: //SORT BY MEMBER NAME
                         sortByName(list, 0, numOfMembers-1);
                         break;
                case 5: //ADD A NEW MEMBER
                         addMember(list, numOfMembers);
                         break;
                case 6: //REMOVE A MEMBER
                         removeMember(list, numOfMembers);
                         break;
                case 7: //QUIT THE PROGRAM
                         exit(0);
                         break;
                 default: //INVALID CHOICE
                          cout << "You have entered an invalid choice" << endl;
            }
        } while (choice != 7);  
	
}




