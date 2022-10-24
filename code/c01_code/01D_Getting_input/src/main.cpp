// main.cpp
/*
import <iostream>;
#include "../thirdparty/format"

using namespace std;

int main(){
	int year;
	cout << format("Please type the year you were born in:\n");
	cin >> year;
	return 0;
}
*/
import <iostream>;
import <chrono>;

int main() {
	std::time_t t = std::time(nullptr);
	std::tm *const pTInfo = std::localtime(&t);
	int current_year = 1900 + pTInfo->tm_year;
	
	int birthday_year;
	std::cout << "Please type the year you were born in:\n";
	std::cin >> birthday_year;

	int years = current_year - birthday_year;

	std::cout << "You are " << years << " years old.\n";

	return 0;
}
