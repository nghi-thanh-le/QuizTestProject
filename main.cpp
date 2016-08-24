#include "Question.h"

int chosenNumber;

int main(){
	cout << "****************************" << endl;
	cout << "*                          *" << endl;
	cout << "*       The Quiz Game      *" << endl;
	cout << "*                          *" << endl;
	cout << "*            by            *" << endl;
	cout << "*                          *" << endl;
	cout << "*       Nghi Le Thanh      *" << endl;
	cout << "*                          *" << endl;
	cout << "****************************" << endl;
	cout << endl;

	string player;
	cout << "Enter your name: ";
	cin >> player;

	cout << "Choose 1 or 2 to select question pakage : ";
	int num;
	cin >> num;
	cout << endl;

	Question q(num, player);
	q.takeTest();
	q.display();
	system("pause");
	return 0;
}