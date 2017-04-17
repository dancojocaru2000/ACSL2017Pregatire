#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout; using std::string; using std::vector;

std::ifstream in("data.in");

vector<int> A, B, C, D;

int StringToInt(string number) {
	int no = 0;
	for (char c : number) {
		no = no * 10 + c - '0';
	}
	return no;
}
string IntToString(int number) {
	string rez, temp;

	for (; number > 0; number /= 10) temp += (number % 10 + '0');
	for (string::iterator i = temp.end() - 1; i != temp.begin(); i--) rez += *i;
	rez += temp[0];

	return rez;
}
 
int counter;

string temp;

string lookup(int toFind, char startFrom, bool odd = true, char switchAt = '\0') {
	if (switchAt == '\0') switchAt = startFrom;
	switch (startFrom) {
	case 'A':
		for (int house : A) {
			if (odd && house % 2 != 0 || !odd && house % 2 == 0) {
				toFind--;
				if (toFind == 0) return "A" + IntToString(house);
			}
		}
		if (switchAt == 'B') return lookup(toFind, 'B', !odd, switchAt);
		return lookup(toFind, 'B', odd, switchAt);
	case 'B':
		for (int house : B) {
			if (odd && house % 2 != 0 || !odd && house % 2 == 0) {
				toFind--;
				if (toFind == 0) return "B" + IntToString(house);
			}
		}
		if (switchAt == 'C') return lookup(toFind, 'C', !odd, switchAt);
		return lookup(toFind, 'C', odd, switchAt);
	case 'C':
		for (int house : C) {
			if (odd && house % 2 != 0 || !odd && house % 2 == 0) {
				toFind--;
				if (toFind == 0) return "C" + IntToString(house);
			}
		}
		if (switchAt == 'D') return lookup(toFind, 'D', !odd, switchAt);
		return lookup(toFind, 'D', odd, switchAt);
	case 'D':
		for (int house : D) {
			if (odd && house % 2 != 0 || !odd && house % 2 == 0) {
				toFind--;
				if (toFind == 0) return "D" + IntToString(house);
			}
		}
		if (switchAt == 'A') return lookup(toFind, 'A', !odd, switchAt);
		return lookup(toFind, 'A', odd, switchAt);
	}
}

int main() {
	in >> counter; in.get();
	for (int i = 0; i < counter; i++) {
		in >> temp;
		if (i < counter - 1) temp.erase(temp.end() - 1);
		switch (temp[0]) {
		case 'A':
			A.push_back(StringToInt(temp.substr(1)));
			break;
		case 'B':
			B.push_back(StringToInt(temp.substr(1)));
			break;
		case 'C':
			C.push_back(StringToInt(temp.substr(1)));
			break;
		case 'D':
			D.push_back(StringToInt(temp.substr(1)));
			break;
		}
	}

	for (int acsl = 0; acsl < 5; acsl++) {
		in >> counter; in.get();
		for (int i = 0; i < counter; i++) {
			in >> temp;
			temp.erase(temp.end() - 1);
			switch (temp[0]) {
			case 'A':
				A.push_back(StringToInt(temp.substr(1)));
				break;
			case 'B':
				B.push_back(StringToInt(temp.substr(1)));
				break;
			case 'C':
				C.push_back(StringToInt(temp.substr(1)));
				break;
			case 'D':
				D.push_back(StringToInt(temp.substr(1)));
				break;
			}
		}
		char startFrom;
		int house;
		in >> startFrom; in.get(); in >> house;

		cout << lookup(house, startFrom) << '\n';
	}

	return 0;
}