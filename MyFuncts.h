/*
 Rebecca Sieber
 myfuncts.h
Declaration File
 */

#ifndef MYFUNCTS_H
#define MYFUNCTS_H

#define PLAY 1
#define STOP 0
#define ERROR -1

#include <string>

//function prototypes
int PromptYN(std::string reply);
std::string changeToUpperCase(std::string& word);
std::string isLetterinWord(char letter, std::string word);

#endif


