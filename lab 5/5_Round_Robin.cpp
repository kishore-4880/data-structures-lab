// C++ program to implement a round robin scheduling algorithm using a circularly linked list
#include <iostream>
#include "5_Circularly_Linked_List.h"
using namespace std;
#define fixed_time 5
int main()
{
    int choice, stop = 0;
    int time, val;
    list round_robin;
    while (!stop)
    {
        cout << "\n\nMENU :\n 1. Insert Process\n 2. Execute\n 3. Exit\n";
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter duration of process (minutes) : ";
            cin >> time;
            round_robin.insertEnd(time);
            break;

        case 2:
            val = round_robin.deleteBeg();
            if (val == -1)
            {
                cout << "No processes in queue." << endl;
            }
            else if (val > fixed_time)
            {
                cout << "Process Executed. " << val - fixed_time << " minutes remaining." << endl;
                round_robin.insertEnd(val - fixed_time);
            }
            else
            {
                cout << "Process Completed." << endl;
            }
            break;

        case 3:
            stop = 1;
            cout << "Exitting program." << endl;
            break;

        default:
            cout << "Invalid choice. Enter again." << endl;
            break;
        }
    }
}