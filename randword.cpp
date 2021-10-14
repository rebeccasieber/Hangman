/*
 Julie Schneider
 randword.cpp
 Function Definition File
 */

#include "randword.h"

 // global variables - you should never write using these though.
 // we haven't gone over arrays and that is the only reason they
 // are declared globally not locally.
string* Words;
int Used = 0;

string getNextWord()
{
	int randomNum = 0;
	string word;


	if (Used > 0)
	{
		randomNum = rand() % Used;

		word = Words[randomNum];

		Words[randomNum] = Words[Used - 1];
		Used--;
		return(word);
	}
	else
		return("");
}

void getWords(string fileName)
{
	int i = 0;
	int max = 2;
	string* temp, tmp;
	ifstream input;

	if (Used != 0)
	{
		cout << "\nError - getWords() cannot be called more than once for any program run!\n";
		return;
	}
	time_t seed = time(NULL);
	srand((unsigned int)seed);

	Words = new string[max];

	input.open(fileName.c_str());

	if (!input)
	{
		cout << "Error opening file \n";
		return;
	}

	cout << endl;

	input >> tmp;
	while (!input.fail())
	{
		cout << tmp << endl;
		if (i >= max)
		{
			temp = new string[max + 2];
			copy(Words, Words + max, temp);
			max += 2;
			delete[] Words;
			Words = temp;
		}
		Used++;
		Words[i] = tmp;
		i++;
		input >> tmp;
	}

	input.close();

}