// Yes Man Sky.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <winuser.h>
#include <sstream>
#include <string>
#include <fstream>
#include <time.h> 
#pragma comment(lib, "winmm.lib")
using namespace std;

void WriteSentenceSlow(string hello) {

	int x = 0;

	while (hello[x] != '\0')
	{
		cout << hello[x];
		Sleep(1);										//50					// making console write letter by letter

		if (hello[x] == '.' || hello[x] == '?' || hello[x] == '!') {
			Sleep(3);										//300			// waiting at the end of the sentence
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

void AchievementComplete()
{
	int msgboxID = MessageBox(
		NULL,
		L"You found all the weird fish figures!!!",
		L"New achievement get!",
		MB_OK
	);

}


long long factorial(int n)
{
	if (n < 2)
		return 1;				//silnia z 1 to 1 lol

	return n * factorial(n - 1);		//rekurencja
}

void zeroFateVariable(string name, int money, int fishes, int fate) {
	fstream openfate0;
	string fate0[30];
	string tCAnswear;
	string answerB = "My name is Commander " + name + ", and here is my pass.";
	string answerC = "You buy this part, but you aren't necessarily happy about it. You have only " + to_string(money) + " credit$ in your wallet left.";
	string textA = "Commander " + name + ", it seems everything is working fine. We may now proceed our journey. I'm prepering engines, soon we will be back in space void.";
	bool haveABag;
	char a_Or_b;
	openfate0.open("Fate0.txt");

	if (openfate0.good())
	{
		int weird = (rand() % 2) - 0;
		cout << weird << endl;
		while (!openfate0.eof())
		{
			for (int i = 0; i <= 29; i++) {
				getline(openfate0, fate0[i]);
			}
			OutputText(fate0[0]);
			cout << "\n";
			OutputText(fate0[1]);
			cout << "\n\n";
			OutputText(name);
			cout << "\n";
			OutputText(fate0[2]);
			cout << "\n\n";
			OutputText(fate0[3]);
			cout << "\n\n";
			do {
				getline(cin, tCAnswear);

			} while (tCAnswear != "yes" && tCAnswear != "no" && tCAnswear != "Yes" && tCAnswear != "No" && tCAnswear != "Nope" && tCAnswear != "Yeah" && tCAnswear != "y" && tCAnswear != "n");
			cout << "\n";
			if (tCAnswear.find("y") != std::string::npos || tCAnswear.find("Y") != std::string::npos) {
				OutputText(fate0[4]);
				haveABag = true;
			}
			else if (tCAnswear.find("n") != std::string::npos || tCAnswear.find("N") != std::string::npos) {
				OutputText(fate0[5]);
				haveABag = false;
			}
			cout << "\n\n";
			OutputText(fate0[6]);
			cout << "\n";
			OutputText(fate0[7]+" (You have " + to_string(money) +" in your wallet)");
			cout << "\n";
			OutputText(fate0[8]);
			cout << "\n";
			OutputText(fate0[9]);
			cout << "\n";
			do {
				cin >> a_Or_b;

			} while (a_Or_b != 'a' && a_Or_b != 'b' && a_Or_b != 'A' && a_Or_b != 'B');
			cout << "\n\n";
			OutputText(name);
			cout << "\n";
			if (a_Or_b == 'a' || a_Or_b == 'A') {
				OutputText(fate0[10]);
				money = money - 10;
			}
			else{
				if (haveABag == false) 
				{
					OutputText(fate0[11]);
					money = money - 10;
				}
				else 
				{
					OutputText(answerB);
				}
			}
			cout << "\n\n";
			OutputText(fate0[12]);
			cout << "\n";
			OutputText(fate0[13]);
			cout << "\n\n";
			OutputText(fate0[14]);
			cout << "\n\n";
			OutputText(fate0[15]);
			cout << "\n";
			OutputText(fate0[16]);
			cout << "\n\n";
			OutputText(name);
			cout << "\n";
			OutputText(fate0[17]);
			cout << "\n\n";
			OutputText(fate0[18]);
			cout << "\n";
			OutputText(fate0[19] + " (You have " + to_string(money) + " in your wallet)");
			cout << "\n\n";
			do {
				getline(cin, tCAnswear);

			} while (tCAnswear != "yes" && tCAnswear != "no" && tCAnswear != "Yes" && tCAnswear != "No" && tCAnswear != "Nope" && tCAnswear != "Yeah" && tCAnswear != "y" && tCAnswear != "n");
			cout << "\n";
			if (tCAnswear.find("y") != std::string::npos || tCAnswear.find("Y") != std::string::npos) {
				OutputText(fate0[20]);
				cout << "\n\n";
				money = money - 40;
			}
			else if (tCAnswear.find("n") != std::string::npos || tCAnswear.find("N") != std::string::npos) {
				money = money - 40;
				OutputText(fate0[21]);
				cout << "\n\n";
				OutputText(fate0[22]);
				cout << "\n";
				OutputText(fate0[23]);
				cout << "\n\n";
				OutputText(answerC);
				cout << "\n\n";
			}
			OutputText(fate0[24]);
			cout << "\n\n";
			do {
				getline(cin, tCAnswear);

			} while (tCAnswear != "yes" && tCAnswear != "no" && tCAnswear != "Yes" && tCAnswear != "No" && tCAnswear != "Nope" && tCAnswear != "Yeah" && tCAnswear != "y" && tCAnswear != "n");
			cout << "\n";
			if (tCAnswear.find("y") != std::string::npos || tCAnswear.find("Y") != std::string::npos) {
				fishes++;
				OutputText(fate0[25]);
			}
			//else if (tCAnswear.find("n") != std::string::npos || tCAnswear.find("N") != std::string::npos) {
				//nothing welp, no achievement for you
			//}
			cout << "\n\n";
			OutputText(fate0[26]);
			cout << "\n\n";
			OutputText(fate0[0]);
			cout << "\n";
			OutputText(textA);
			cout << "\n\n";
			OutputText(fate0[27]);
			cout << "\n\n";
			OutputText(fate0[28]);
			cout << "\n";
			OutputText(fate0[29]);
			fate = weird;

		}
	}
}

void oneFateVariable(string name, int money, int fishes, int fate) {
	fstream openfate1;
	string fate1[30];
	string tCAnswear;
	string answerB = "My name is Commander " + name + ". Do you by any chance know a programmer who could repair hipernavigation system?.";
	char a_Or_b;

	int points = 0;
	int factorialRandom = (rand() % 10) - 0;
	int firstAnswear;
	int secondAnswear;
	int thirdAnswear;

	openfate1.open("Fate1.txt");

	if (openfate1.good())
	{
		while (!openfate1.eof())
		{
			for (int i = 0; i <= 29; i++) {
				getline(openfate1, fate1[i]);
			}
			OutputText(fate1[0]);
			cout << "\n";
			OutputText(fate1[1]);
			cout << "\n\n";
			OutputText(name);
			cout << "\n";
			OutputText(fate1[2]);
			cout << "\n\n";
			OutputText(fate1[3]);
			cout << "\n";
			OutputText(fate1[4]);
			cout << "\n\n";
			OutputText(name);
			cout << "\n";
			OutputText(fate1[5]);
			cout << "\n\n";
			OutputText(fate1[6]);
			cout << "\n\n";
			OutputText(fate1[7]);
			cout << "\n";
			OutputText(fate1[8]);
			cout << "\n\n";
			OutputText(name);
			cout << "\n";
			OutputText("Hello, my name is Commander "+name+" and "+fate1[9]);
			cout << "\n\n";
			OutputText(fate1[10]);
			cout << "\n";
			OutputText(fate1[11]);

			cout << "\n\n";
			do {
				getline(cin, tCAnswear);

			} while (tCAnswear != "yes" && tCAnswear != "no" && tCAnswear != "Yes" && tCAnswear != "No" && tCAnswear != "Nope" && tCAnswear != "Yeah" && tCAnswear != "y" && tCAnswear != "n");
			cout << "\n";
			if (tCAnswear.find("y") != std::string::npos || tCAnswear.find("Y") != std::string::npos) {
				OutputText(fate1[12]);
				
			}
			else if (tCAnswear.find("n") != std::string::npos || tCAnswear.find("N") != std::string::npos) {
				OutputText(fate1[13]);
				
			}
			cout << "\n\n";
			OutputText(fate1[14]);
			cout << "\n";
			OutputText(fate1[15]+ to_string(factorialRandom)+" ?");
			cin >> factorialRandom;

			fate = (rand() % 2) - 0;


		}
	}
}




int main()
{
	PlaySound(TEXT("spacemusic.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	AchievementComplete();
    system("color 02");
	srand(time(NULL));
	string name;
	string question = "Would like to proceed or give up and end this journey here? (yes/no)";
	string tCAnswear;
	string tCAnswear1;
	string tCA1 = "y";

	string prologue[10];
	int fateVariable = (rand() % 2) - 0;
	int fateVariable1 = (rand() % 2) - 0;
	int money = (rand() % 151) + 30;
	int countPlanets = 0;
	int countFishes = 0;
	fstream openprologue;
	fstream openSaveFile;


	cout << fateVariable << "  " << fateVariable1 <<"  "<< money << endl;
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
			cout << "\n";
			OutputText(prologue[6]);
			cout << "\n";
			if (tCAnswear.find("y") != std::string::npos || tCAnswear.find("Y") != std::string::npos) {
				OutputText(prologue[8]);
				cout << "\n\n\n~ End of Prolog ~\n\n";
			}else if(tCAnswear.find("n") != std::string::npos || tCAnswear.find("N") != std::string::npos){
				OutputText(prologue[9]);
				cout << "\n\n\n~ End of Prolog ~\n\n";
			}
			//OutputText(prologue[2]);
			//cout << "Nie dziala\n" << endl;
		}
	}
	openSaveFile.open("Save.txt");
	if (openSaveFile.good())
	{
			openSaveFile << name << endl;
			openSaveFile << money;
		
	}
	openSaveFile.close();

	do {

		switch (fateVariable)
		{
		case 0:
			zeroFateVariable(name, money, countFishes, fateVariable);
			break;

		case 1:
			oneFateVariable(name, money, countFishes, fateVariable);
			break;

		case 2:
			//twoFateVariable(name, money, countFishes, fateVariable);  //well, game has a potential to be much bigger but i decided to crop it a little bit because apparently writing dry story about aliens, and traveling in space is quite boring
			break;

		case 3:
			//threeFateVariable(name, money, countFishes, fateVariable);
			break;

		}
		cout << "\n\n";
		OutputText(question);
		cout << "\n\n";
		getline(cin, tCAnswear1);
		fateVariable = fateVariable1;
	} while (tCAnswear1 != "no" && tCAnswear1 != "No" && tCAnswear1 != "Nope" && tCAnswear1 != "n");

	openprologue.close();
	
	return 0;
}
