// Yes Man Sky.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <string>
#include <fstream>

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
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
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
			OutputText(prologue);
		}
	}
	cout << "\n\n";
	getline(cin, name);
	string nametext = "\nSo, your name is " + name + ", huh? Okay, let's get to work, shall we?\n\n";
	OutputText(nametext);
	openprologue.close();
	return 0;
}
