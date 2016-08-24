#include "Question.h"

Question::Question(int num, string player)
{
	playerName = player;
	switch (num){
	case 1:
		name = "computer.txt";
		cout << "You have chosen a test about Computer Science!" << endl;
		break;
	case 2:
		name = "english.txt";
		cout << "You have chosen a test about English!" << endl;
		break;
	default:
		cout << "Choose a number from 1 to 2" << endl;
	}
	cout << "Write the answer correctly or the mark will not be counted!" << endl;
	cout << endl;
}

void Question::takeTest(){
	// shuffle and print out list of answer
	shuffle();

	int count = 1;
	string x;
	
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 6; j++){
			switch (j){
			case 0:
				cout << i + 1 << ".";
				break;
			case 1:
				cout << "a.";
				break;
			case 2:
				cout << "b.";
				break;
			case 3:
				cout << "c.";
				break;
			case 4:
				cout << "d.";
				break;
			}
			if (j != 5)
				cout << pakage[i][j] << endl;
			else {
				cout << "Answer: ";
				cin >> x;
				if (x == pakage[i][j]) mark++;
			}
		}
		cout << endl;
	}
}

// display result
void Question::display()
{
	system("CLS");
	cout << "\n Result:\n";
	cout << "\t" << playerName << " you got total " << mark << " marks,out of 10.\n";
}

// an private method to open the .txt file
// this method define the question pakage and make the array of question, answer , correct answer
void Question::define(){
	ifstream myfile(name);
	// get the question and answer
	while (!myfile.eof()){
		// transfer the text in .txt file into array of string 
		myfile.getline(s, 100);
		for (int i = 0; i < sizeof(s); i++){
			if (s[i] != NULL){
				line[lineCount] += s[i];
			}
			else break;
		}
		lineCount++;
	}
	// transfer the array of line text into 2 dimension array
	// I do 2D array to make it easier to shuffle
	int x = 0;
	while (x < lineCount){
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 6; j++){
				pakage[i][j] = line[x];
				x++;
			}
		}
	}
	myfile.close();
}

// shuffle the question and answer
void Question::shuffle(){
	define();
	
	srand((unsigned)time(NULL));
	int randNum;
	string tempLine[10][6];
	bool temp[10] = { false };
	int row = 0;

	// shuffling the question
	while (row < 10){
		randNum = rand() % 10;
		if (!temp[randNum]){
			for (int col = 0; col < 6; col++){
				tempLine[row][col] = pakage[randNum][col];
			}
			row++;
		}
	}
	
	// shullle the answer inside the question
	for (int row = 0; row < 10; row++){
		random_shuffle(&tempLine[row][1], &tempLine[row][4]);
	}

	// make a new question pakage
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 6; j++){
			pakage[i][j] = tempLine[i][j];
		}
	}
}