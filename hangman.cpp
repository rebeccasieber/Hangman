/*
Rebecca Sieber
10/23/2020
CSC 160-470
This hangman game extracts words from a file "hangman.dat". It prints all of the words from the file, and then choses
a random word from the list to use for the game. From there the game requests letters to guess from the user, and tells the user 
whether or not the letter they guessed is in the word, and prints a hangman board visual to represent how many guesses they
have gotten wrong. When the user has 6 wrong guesses, they lose the game and they are given the option to play again with 
a new and unique word from the list. Once all the words on the list have been played, or the user decides to quit playing,
The program ends successfully. At this time, the game is not designed for the user to be able to win.
*/

#include <iostream> // istream & ostream

//programmer definied header files
#include "randword.h"
#include "myfuncts.h"

//Function prototypes
void drawHangman(int wrongGuesses, std::string word);
void printResultOfGuess(std::string resultMessage, char guessLetter);
void requestGuessLetter();
void displayGuessLetter(char letter);

int main()
{
	/* DECLARING VARIABLES */
	char guessLetter = '0';				//to be provided by user
	int wrongGuesses = 0;				//user gets up to 7 wrong guesses before game ends
	int playResponse = 0;				//holds user input for if they want to play again or not
	int failedResponse = 0;				//counts number of times user answers playResponse incorrectly
	std::string resultMessage = "";		//"FOUND" or "NOT FOUND" depending on whether guess letter is found or not found in wordToGuess
	std::string wordToGuess;			//provided by .dat file
	std::string replyYN = "";			//provided by user- answer to prompt to play

	/* Getting words to play with from .dat file and picking first word from list randomly and changing word
	to uppercase letters.*/

	getWords("hangman.dat");
	wordToGuess = getNextWord(); 
	changeToUpperCase(wordToGuess);

	/*Starting while loop to allow user to keep playing the game as long as there are unique words to chose
	from. When there are not unique words left to chose from the getNextWord function will return empty string */
	
	while (wordToGuess != "")
	{

		/* This loop asks player if they would like to play hangman. If they answer affirmatively then the game starts
		If they answer negatively, the game ends successfully. If they answer in a way that is not negative or positive
		then they are asked to reanswer 2 more times before the program terminates in error */

		for (int i = 0; i < 3; i++) // allows for the user to answer playResponse 3 times
		{
			std::cout << "\nDo you want to play a round of hangman? (Y/N) ";
			std::cin >> replyYN;

			playResponse = PromptYN(replyYN); //processing user respose to continued gameplay

			if (playResponse == PLAY)
			{
				std::cout << "Let's play!" << std::endl;
				std::cout << "\nWord to guess is: " << wordToGuess << std::endl; //this is for testing purposes only, comment out to play game for real
				break;				      
			}

			else if (playResponse == STOP)
			{
				std::cout << "Goodbye" << std::endl;
				return STOP;			    //exit program successfully
			}

			else
			{
				failedResponse += 1;
				std::cout << "Error in response." << endl;

				if (failedResponse == 3)	// If user answered playResponse incorrectly 3 times, terminating program
				{
					std::cout << "Terminating program." << endl;
					return ERROR; // exit code failure
				}

			}
		}

		failedResponse = 0; // resetting failed response counter

		//Starting while loop to allow for 6 wrong guesses before terminating game and user "loses"
		while (wrongGuesses < 6)
		{
			/*Accepting guess letter from user. Converting letter to uppercase, and printing users guess letter
			to the screen.*/

			requestGuessLetter();
			std:: cin >> guessLetter;
			guessLetter = toupper(guessLetter);
			displayGuessLetter(guessLetter);

			/*Determining if guessLetter is containted within guessWord and printing response to user.*/
			resultMessage = isLetterinWord(guessLetter, wordToGuess);

			/*If letter guessed was not found in the word, increasing wrong guess counter by 1*/
			if (resultMessage == "NOT FOUND")
			{
				wrongGuesses = wrongGuesses + 1;
			}

			/*Printing message to user as to whether guessLetter was found in guessWord or not*/
			printResultOfGuess(resultMessage, guessLetter);
		
			/*Printing hangman visual based on how many wrong guesses the user has accrued after each guess*/
			drawHangman(wrongGuesses, wordToGuess);
		}

		/*Getting new/unique word for next game, changing it to uppercase letters, and resetting wrong guess counter*/
		wordToGuess = getNextWord();	
		changeToUpperCase(wordToGuess); 
		wrongGuesses = 0;				
	}
	
	/* If there are no more unique words to play with from .dat file, ending game successfuly*/
	if (wordToGuess == "") 
	{		
		std::cout << "There are no more words to guess. Thank you for playing. Game over!" << std::endl;
  		return STOP;	//exit code success- game ending successfully
	}
	
}

/*This function draws the hangman visual based on how many wrong guesses the user has made*/
void drawHangman(int wrongGuesses, std::string word)
{
	/*Declaring constant strings that form hangman board visual. 
	There are 7 for each of the 7 stages of hangman. I promise they make a pretty picture.*/
	std::string const  HANGMAN_0 = " -------|\n |      |\n        |\n        |\n        |\n        |\n     ------\n\n";
	std::string const  HANGMAN_1 = " -------|\n |      |\n O      |\n        |\n        |\n        |\n     ------\n\n";
	std::string const  HANGMAN_2 = " -------|\n |      |\n O      |\n |      |\n        |\n        |\n     ------\n\n";
	std::string const  HANGMAN_3 = " -------|\n |      |\n O      |\n-|      |\n        |\n        |\n     ------\n\n";
	std::string const  HANGMAN_4 = " -------|\n |      |\n O      |\n-|-     |\n        |\n        |\n     ------\n\n";
	std::string const  HANGMAN_5 = " -------|\n |      |\n O      |\n-|-     |\n/       |\n        |\n     ------\n\n";
	std::string const  HANGMAN_6 = " -------|\n |      |\n O      |\n-|-     |\n/ \\     |\n        |\n     ------\n\n";

	if (wrongGuesses == 0)
		std::cout << HANGMAN_0;
	else if (wrongGuesses == 1)
		std::cout << HANGMAN_1;
	else if (wrongGuesses == 2)
		std::cout << HANGMAN_2;
	else if (wrongGuesses == 3)
		std::cout << HANGMAN_3;
	else if (wrongGuesses == 4)
		std::cout << HANGMAN_4;
	else if (wrongGuesses == 5)
		std::cout << HANGMAN_5;
	else if (wrongGuesses == 6)
		std::cout << HANGMAN_6 << "YOU LOSE. The word was " << word <<"."<< std::endl;
	else  //just incase something goes haywire	
		std::cout << "There has been a logic error in this program." << std::endl;
}

/* This function tells the user if their guess was contained inside of the guess word or not*/
void printResultOfGuess(std::string resultMessage, char guessLetter)
{
	std::cout << std::endl;
	std::cout << guessLetter << " is " << resultMessage << " in the word." << std::endl;
}

/*This function prompts the user to enter a guess. This function is probably unnecessary*/
void requestGuessLetter()
{
	std::cout << "\nEnter a letter to guess: ";
}

/*This function accepts a letter, converts it to uppercase, and prints uppercase version to user*/
void displayGuessLetter(char letter)
{
	letter = toupper(letter);						
	std::cout << "Your entered: " << letter << std::endl;
}

