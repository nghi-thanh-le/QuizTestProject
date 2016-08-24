#pragma once

#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>
using namespace std;

class Question
{
public:
	Question(int, string);
	void display();
	void takeTest();
	void init();

private: 
	string name, playerName, line[60], pakage[10][6];
	int lineCount = 0, mark = 0;
	char s[100];

	void define();
	void shuffle();
};

