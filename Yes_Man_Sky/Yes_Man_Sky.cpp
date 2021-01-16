// Yes Man Sky.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <string>
#include <fstream>

using namespace std;

void writeSentenceSlow(string hello) {

	int x = 0;

	while (hello[x] != '\0')
	{
		cout << hello[x];
		Sleep(50);

		if (hello[x] == '.' || hello[x] == '?') {
			Sleep(300);
		}
		x++;
	};

}


int main()
{
    system("color 02");
	string name;
	string prologue;
	fstream openprologue;

	openprologue.open("Prologue.txt");
	if (openprologue.good() == true)
	{
		while (!openprologue.eof())
		{
			getline(openprologue, prologue);
			if (prologue.find("  ")) 
			{
				cout << endl;
			};
			writeSentenceSlow(prologue);
		}
	}
	cout << "\n\n";
	getline(cin, name);
	string nametext = "\nSo, your name is " + name + ", huh? Okay, let's get to work, shall we?\n\n";
	writeSentenceSlow(nametext);
	openprologue.close();
	return 0;
}
