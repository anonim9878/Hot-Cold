#include <iostream>
#include <random>
#include <string>

using namespace std;

bool cheatCode(std::string input, size_t number) {
	if (input.compare("give me monkey") == 0) {
		std::cout << "Number: " << number << std::endl;
		return true;
	}
	return false;
}

void main() {
	srand(time(0));
	const size_t MAX_RATE = 10000;
	const size_t HOT_DISTANCE = 10;
	const size_t VERY_HOT_DISTANCE = 3;
	size_t number = rand() % MAX_RATE;
	string input;
	int inputInt;
	cout << "Hello! Try to guess my number (from 0 to " << MAX_RATE << ")!\nFor exit enter 'q'\n";
	while (input != "q") {
		getline(cin, input);
		if (input == "q")
			continue;
		if (cheatCode(input, number))
			continue;
		try {
			inputInt = stoi(input);
		}
		catch (invalid_argument err) {
			cout << "Write only number without space\n";
			continue;
		}
		if (inputInt > MAX_RATE) {
			cout << "Input number from 0 to " << MAX_RATE << endl;
			continue;
		}
		if (inputInt != number) {
			if ((inputInt > number && number + VERY_HOT_DISTANCE > inputInt) || (inputInt < number && number - VERY_HOT_DISTANCE < inputInt))
				cout << "Very hot!\n";
			else if ((inputInt > number && number + HOT_DISTANCE > inputInt) || (inputInt < number && number - HOT_DISTANCE < inputInt))
				cout << "Hot!\n";
			else
				cout << "Cold\n";
		}
		else {
			cout << "You win!\nI change number, try guess it\n";
			number = rand() % MAX_RATE;
		}
	}
	cout << "Bye!";
	cin;
}