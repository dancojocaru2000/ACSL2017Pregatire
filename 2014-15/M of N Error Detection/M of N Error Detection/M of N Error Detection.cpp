#include <iostream>
#include <fstream>
#include <vector>
using std::vector; using std::cin;

std::ifstream in("data.in");

vector<bool> btWorker;
vector<int> input;
int bits, number;

bool bt(int position = 0) {

}

int main() {
	for (int acsl = 0; acsl < 10; acsl++) {
		input = vector<int>();
		for (; !('0' <= in.peek() && in.peek() <= '9'); in.get());
		for (input.push_back(in.get() - '0'); '0' <= in.peek() && in.peek() <= '9'; input.push_back(in.get() - '0'));
		in.get();
		in >> bits; in.get();
		in >> number;
		btWorker = vector<bool>(input.size(), false);

		bt();
	}

	return 0;
}