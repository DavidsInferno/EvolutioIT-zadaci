#include <iostream>
#include <time.h>

using namespace std;

int choiceAI();

int main(void) {
	int input = 0;
	int inputAI = 0;
	bool finished = false;
	int scoreUser = 0;
	int scorePC = 0;
	srand((unsigned)time(NULL));

	

	while (!finished) {
		cout << "Choose Rock(1), Scissors(2) or Paper(3)! If you are done press '-1'\Your input: ";
		cin >> input;

		//Input check
		if (!cin) {
			cout << "Please input a number." << endl;
			cin.clear();//clear bad input flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');//discards input
			continue;
		}
		if (input < 1 || input > 3) {
			if (input == -1)
				return 0;

			cout << "Enter one of the options!\n";
			continue;
		}
		//________________________


		inputAI = choiceAI();
		

		if ((input < inputAI && input + 2 != inputAI) || input - 2 == inputAI) {
			cout << "You win" << endl;
			scoreUser++;
		}
		else if (input == inputAI) {
			cout << "Draw" << endl;
		}
		else {
			cout << "You lose" << endl;
			scorePC++;
		}
		cout << "User: " << scoreUser << "		" << "Score PC: " << scorePC;
		cout << endl << endl;

	}
	return 0;
}


int choiceAI() {
	int temp = 0;
	temp = rand() % 3 + 1;

	if (temp == 1)
		cout << "Opponent chose rock";
	else if (temp == 2)
		cout << "Opponent chose scissors";
	else
		cout << "Opponent chose paper";

	cout << endl;
	return temp;
}
