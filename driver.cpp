// Austin Davis
// Program to create a Gym Management System
//This is the header file
#include <iostream>
#include <fstream>
#include "GymManagementProject.h"
int main()
{
	
	string firstNames[100];
	string lastNames[100];
	Member list[100];
	int choice = 0;
 	readInNames(firstNames,lastNames);
 	createMembers(firstNames,lastNames, list);
 	cout << "Welcome to MyGymManager!" << endl << endl;
 	do
    	{
        	 Menu(choice);
        	switch (choice)
            {
                 case 1: //PRINT LIST OF MEMBERS
                         for (int j=0; j<100; j++)
						 {
						 	list[j].printMember();
						 }
                         break;
                 case 2: //SEARCH FOR A MEMBER
                         searchForMember(list);
                         break;
                 case 3: //SORT BY MEMBER ID
                         sortByID(list, 0, 99);
                         break;
                 case 4: //SORT BY MEMBER NAME
                         sortByName(list, 0, 99);
                         break;
                case 5: //QUIT THE PROGRAM
                         exit(0);
                         break;
                 default: //INVALID CHOICE
                          cout << "You have entered an invalid choice" << endl;
            }
        } while (choice != 5);  
	
	
	
	
}
