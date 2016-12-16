// Car.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void printProgramFunction()
{
	cout << "1. Info" << endl;
	cout << "2. EngineOn" << endl;
	cout << "3. EngineOff" << endl;
	cout << "4. SetGear <gear>" << endl;
	cout << "5. SetSpeed <speed>" << endl;
	cout << "6. Exit" << endl;

}

int main()
{
	printProgramFunction();
	int commandNum = 0, value;
	string command, direction;
	CCar car;
	while (commandNum != progExit)
	{
		cout << "Input command: ";
		cin >> commandNum;
		if (!isdigit(commandNum))
		{
			cin.clear();//Восстановили поток
			cin.ignore(cin.rdbuf()->in_avail());//Почистили поток
		}

		if (commandNum == info)
		{
			direction = "neutral";
			command = "Off";
			if (car.IsEngineTurnedOn())
			{
				command = "On";
			}

			cout << "Speed: " << car.GetSpeed() << " Gear: " << car.GetGear() << " Direction: " << car.GetDir() << " IsEngineTurnedOn: " << command;
		}
		if (commandNum == turnedOn)
		{
			if (car.TurnOnEngine())
			{
				cout << "Car TurnedOn";
			}
			else
			{
				cout << "I can't turned on engine";
			}
		}
		if (commandNum == turnedOff)
		{
			if (car.TurnOffEngine())
			{		
				cout << "Car TurnedOff";
			}
			else
			{
				cout << "I can't turned off engine";
				
			}
		}
		if (commandNum == setGear)
		{
			cout << "Enter gear(1 - first, 2 - second, 3 - third, 4 - fouth, 5 - fifth, 6 - reverse, 0 - neutral: ";
			cin >> value;
			car.SetGear(value);
			if (car.GetGear() == value)
			{
				cout << "Success";
			}
			else
			{
				cout << "I can't change gear!";
			}
		}
		if (commandNum == setSpeed)
		{
			cout << "Enter speed: ";
			cin >> value;
			car.SetSpeed(value);
			if (car.GetSpeed() == value)
			{
				cout << "Success";
			}
			else
			{
				cout << "I can't change speed!";			
			}
		}
		cout << endl;
	}
	return 0;
}
