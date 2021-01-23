// Yes Man Sky.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <string>
#include <fstream>
#include <time.h> 

using namespace std;

void WriteSentenceSlow(string hello) {

	int x = 0;

	while (hello[x] != '\0')
	{
		cout << hello[x];
		Sleep(50);															// making console write letter by letter

		if (hello[x] == '.' || hello[x] == '?' || hello[x] == '!') {
			Sleep(300);													// waiting at the end of the sentence
		}
		x++;
	};

}

int GetBufferWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;			// this function reads the buffer of the console size and returns it
	int bufferWidth, result;

	result = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bufferInfo);

	if (result)
	{
		bufferWidth = bufferInfo.dwSize.X;
	}

	return bufferWidth;
}


void OutputText(std::string s)
{
	int bufferWidth = GetBufferWidth();

	for (unsigned int i = 1; i <= s.length(); i++)
	{
		char c = s[i - 1];

		int spaceCount = 0;

		// Add whitespace if newline detected.
		if (c == '\n')
		{
			int charNumOnLine = ((i) % bufferWidth);
			spaceCount = bufferWidth - charNumOnLine;
			s.insert((i - 1), (spaceCount), ' ');			//insert space before newline break
			i += (spaceCount);							//jump forward in string to character at beginning of next line
			continue;
		}

		if ((i % bufferWidth) == 0)
		{
			if (c != ' ')
			{
				for (int j = (i - 1); j > -1; j--)
				{
					if (s[j] == ' ')
					{
						s.insert(j, spaceCount, ' ');
						break;
					}
					else spaceCount++;
				}
			}
		}
	}

	WriteSentenceSlow(s);
}
void zeroFateVariable() {
	fstream openfate0;
	string fate0[5];

	openfate0.open("Fate0.txt");

	if (openfate0.good())
	{
		while (!openfate0.eof())
		{
			for (int i = 0; i <= 4; i++) {
				getline(openfate0, fate0[i]);
			}
			OutputText(fate0[0]);

			cout << "\n\n";
			OutputText(fate0[1]);
		}
	}
}

int main()
{
    system("color 02");
	srand(time(NULL));
	string name;
	string tCAnswear;
	string tCA1 = "y";

	string prologue[10];
	int fateVariable = (rand() % 6) - 0;
	int money = (rand() % 151) - 0;
	fstream openprologue;
	fstream openSaveFile;


	//cout << fateVariable <<"  "<< money << endl;
	openprologue.open("Prologue.txt");

	if (openprologue.good())
	{
		while (!openprologue.eof())
		{
			for (int i = 0; i <= 9; i++) {
				getline(openprologue, prologue[i]);
			}
			OutputText(prologue[0]);
			cout << "\n";
			OutputText(prologue[1]);
			cout << "\n\n";

			getline(cin, name);
			cout << "\n";
			OutputText(prologue[0]);
			string nametext = "\nSo, your name is " + name + ", huh? Okay, let's get to work, shall we?";
			WriteSentenceSlow(nametext);
			cout << "\n\n";

			for (int i = 2; i <= 7; i++) {
				OutputText(prologue[i]);
				if (i % 2 == 0) {
					cout << "\n";
				}else  cout << "\n\n";
			}
			
			do {
				getline(cin, tCAnswear);

			} while (tCAnswear != "yes" && tCAnswear != "no" && tCAnswear != "Yes" && tCAnswear != "No" && tCAnswear != "Nope" && tCAnswear != "Yeah" && tCAnswear != "y" && tCAnswear != "n");
			OutputText(prologue[6]);
			cout << "\n";
			if (tCAnswear.find("y") != std::string::npos || tCAnswear.find("Y") != std::string::npos) {
				OutputText(prologue[8]);
				cout << "\n\n";
			}else if(tCAnswear.find("n") != std::string::npos || tCAnswear.find("N") != std::string::npos){
				OutputText(prologue[9]);
				cout << "\n\n";
			}
		}
	}
	switch (fateVariable)
	{
	case 0:
		//jakis kod
		break;

	case 1:
		//jakis kod
		break;

	case 2:
		//jakis kod
		break;

	case 3:
		//jakis kod
		break;

	case 4:
		//jakis kod
		break;

	case 5:
		//jakis kod
		break;
	
	default:
		//jakis kod
		break;
	}

	openprologue.close();
	
	return 0;
}
