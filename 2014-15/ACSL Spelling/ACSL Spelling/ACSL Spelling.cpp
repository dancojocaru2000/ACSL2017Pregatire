#include <iostream>
#include <fstream>
#include <string>
using std::cout; using std::string;

std::ifstream in("data.in");

bool isVowel(char character) {
	switch (character) {
	case 'a': return true;
	case 'e': return true;
	case 'i': return true;
	case 'o': return true;
	case 'u': return true;
	default: return false;
	}
}

string toPlural(string input) {
	if (*(input.end() - 2) == 'c' && *(input.end() - 1) == 'h') return input + "es";
	if (*(input.end() - 2) == 's' && *(input.end() - 1) == 'h') return input + "es";
	if (*(input.end() - 1) == 's') return input + "es";
	if (*(input.end() - 1) == 'x') return input + "es";
	if (*(input.end() - 1) == 'z') return input + "es";

	if (isVowel(*(input.end() - 2)) && *(input.end() - 1) == 'y') return input + "s";

	if (!isVowel(*(input.end() - 2)) && *(input.end() - 1) == 'y') {
		input.erase(input.end() - 1);
		return input + "ies";
	}

	if (*(input.end() - 1) == 'f') {
		input.erase(input.end() - 1);
		return input + "ves";
	}
	if (*(input.end() - 2) == 'f' && *(input.end() - 1) == 'e') {
		input.erase(input.end() - 2, input.end() - 1);
		return input + "ves";
	}

	if (isVowel(*(input.end() - 2)) && *(input.end() - 1) == 'o') return input + "s";

	if (!isVowel(*(input.end() - 2)) && *(input.end() - 1) == 'o') return input + "es";

	return input + "s";
}

string addSufix(string input, string suffix) {
	if (isVowel(suffix[0]) && *(input.end() - 1) == 'e') {
		input.erase(input.end() - 1);
		return input + suffix;
	}

	if (suffix[0] != 'i' && *(input.end() - 1) == 'y') {
		*(input.end() - 1) = 'i';
		return input + suffix;
	}

	if (!isVowel(*(input.end() - 3)) && isVowel(*(input.end() - 2)) && !isVowel(*(input.end() - 1)) && isVowel(suffix[0])) {
		return input + *(input.end() - 1) + suffix;
	}

	return input + suffix;
}

int main() {
	for (int i = 0; i < 5; i++) {
		string temp;
		in >> temp;
		cout << toPlural(temp) << '\n';
	}

	for (int i = 0; i < 5; i++) {
		string temp1, temp2;
		in >> temp1 >> temp2;
		temp1.erase(temp1.end() - 1);
		cout << addSufix(temp1, temp2) << '\n';
	}

	return 0;
}