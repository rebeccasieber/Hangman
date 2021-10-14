/*
 Julie Schneider
 randword.h
 Header File
 */

#ifndef RANDWORD_H
#define RANDWORD_H
#define _SCL_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

void getWords(string fileName);

string getNextWord();


#endif
