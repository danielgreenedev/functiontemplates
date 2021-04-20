// C++ Software Development
// CIS 1202.201
// 
// Daniel J. Greene
// December 5, 2019
// 
// Function Templates
// final assignment
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>

template <class fill>
void Fill_Vector(std::vector<fill> * vect_p, std::string dataType) {
	fill input;

	bool again = true;

	while (again) {
		std::cout << std::endl << "Enter a " << dataType << " value: ";
		std::cin >> input;

		while (input < 0) { std::cout << std::endl << "Please enter a number 0 or greater: "; std::cin >> input; }

		(*(vect_p)).push_back(input);

		std::cout << std::endl << "Enter 1 to enter another number, or 0 to end: ";
		std::cin >> again;
	}
}

template <class process>
void Process_Vector(std::vector<process>& vct, std::vector<process>& vctCount, int &numModes) {

	typename std::vector <process>::iterator iter;

	process modeStore;

	int counter = 0;
	for (iter = vct.begin() + 1; iter < vct.end(); iter++) {
		process mode = *iter;
		int count = std::count(vct.begin(), vct.end(), mode);

		if (count > counter) {
			modeStore = mode;
			counter = count;
		}
	}

	vctCount.push_back(modeStore);
	numModes = counter;
}

int main() {

	std::vector<double> dblVct;
	std::vector<double> dblModeVct;
	std::vector<int> intVct;
	std::vector<int> intModeVct;

	std::string dataT;

	int numberModes = 0;

	bool repeat = true;

	while (repeat) {

	std::cout << "Please decide on your data type and enter 'int' or 'double' (no quotes) at the prompt: " << std::endl;
	std::cin >> dataT;

	if (dataT == "double") {
		Fill_Vector(&dblVct, dataT); 
		Process_Vector(dblVct, dblModeVct, numberModes);
		std::cout << std::endl << "For " << dataT << " the mode is: " << dblModeVct[0] << " occuring " << numberModes << " times.";
	}
	else if (dataT == "int") { 
		Fill_Vector(&intVct, dataT); 
		Process_Vector(intVct, intModeVct, numberModes); 
		std::cout << std::endl << "For " << dataT << " the mode is: " << intModeVct[0] << " occuring " << numberModes << " times.";
	}
	


	std::cout << std::endl << "Enter 1 to enter another data set, or 0 to end: ";
	std::cin >> repeat;

	dblVct.clear();
	dblModeVct.clear();
	intVct.clear();
	intModeVct.clear();

	}

	std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}