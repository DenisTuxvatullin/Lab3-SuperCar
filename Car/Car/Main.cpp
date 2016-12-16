// Car.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Car.h"
#include <stdlib.h>
#include <iostream>
#include <string>
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
	string command;
	
	CCar car;
	while (commandNum != 6)
	{
		cout << "Input command: ";
		cin >> commandNum;

		if (commandNum == 1)
		{
			command = "Off";
			if (car.IsEngineTurnedOn())
			{
				command = "On";
			}
			cout << "Speed: " << car.GetSpeed() << " Gear: " << car.GetGear() << " Direction: " << car.GetDir() << " IsEngineTurnedOn: " << command;
		}

		if (commandNum == 2)
		{
			if (car.TurnOnEngine())
			{
				cout << "Car TurnedOn";
			}
			else
			{
				cout << "Car already turnedOn";
			}
		}

		if (commandNum == 3)
		{
			if (car.TurnOffEngine())
			{		
				cout << "Car TurnedOff";
			}
			else
			{
				cout << "Error(Gear -> neutral, Speed -> 0, engine -> TurnedOn)";
				
			}
		}
		if (commandNum == 4)
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
				cout << "Engine(1-6) -> TurnedOn, Speed should be in the correct range";
			}
		}
		if (commandNum == 5)
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
				cout << "Speed should be in the correct range";			
			}
		}
		cout << endl;

	}
	return 0;
}
