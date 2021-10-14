//myfuncts.cpp
//function implimentation file

#include "myfuncts.h"
#include <string>

//function definitions
int PromptYN(std::string reply)
{
	if (reply == "YES" ||
		reply == "yes" ||
		reply == "Yes" ||
		reply == "SURE" ||
		reply == "sure" ||
		reply == "Sure" ||
		reply == "OK" ||
		reply == "ok" ||
		reply == "Ok" ||
		reply == "Y" ||
		reply == "y")

		return PLAY; // 1 represents "play"

	else if (reply == "NO" ||
		reply == "no" ||
		reply == "No" ||
		reply == "QUIT" ||
		reply == "Quit" ||
		reply == "quit" ||
		reply == "STOP" ||
		reply == "Stop" ||
		reply == "stop" ||
		reply == "TERMINATE" ||
		reply == "Terminate" ||
		reply == "terminate" ||
		reply == "N" ||
		reply == "n" ||
		reply == "Q" ||
		reply == "q")

		return STOP; // 0 represents "stop

	else
		return ERROR; //representes "error"

}

std::string changeToUpperCase(std::string& word)
{
	for (int i = 0; i < word.size(); i++)
	{
		word.at(i) = toupper(word.at(i));
	}

	return word;
}

std::string isLetterinWord(char letter, std::string word )
{
	std::string result ="";
	int counter = 0;
	int lengthOfWord = word.size();

	while (counter < lengthOfWord)
	{
		if (letter == word.at(counter))
		{
			result = "FOUND";		//setting result to "found" as match was found
			break;							//terminating while loop as match has been found
		}

		else
		{
			result = "NOT FOUND";	//setting result to "not found", however this will be overwritten to "found" if match is found in a proceeding letter
			counter = counter + 1;			//increasing counter by 1
		}
	}
	return result;
}