#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using std::cout; using std::string;

std::ifstream in("data.in");

struct tp { int Index, Score; };

struct TeamResult {
	int Total;
	tp TotalPlayer[4];
}Jets, Sharks;

struct Person {
	string Name;
	struct score {
		int Zone1, Zone2, Zone3;
	} Score;
} Players[8];

int main() {
	int answer1 = 0, answer2 = 0, answer2Index = 0, answer3 = 0, answer3Index = 0;
	for (int i = 0; i < 8; i++) {
		in >> Players[i].Name;
		Players[i].Name.erase(Players[i].Name.end() - 1);
		in >> Players[i].Score.Zone1; in.get();
		in >> Players[i].Score.Zone2; in.get();
		in >> Players[i].Score.Zone3; in.get();

		answer1 += Players[i].Score.Zone3;
		if (Players[i].Score.Zone1 + Players[i].Score.Zone2 + Players[i].Score.Zone3 > answer2) {
			answer2 = Players[i].Score.Zone1 + Players[i].Score.Zone2 + Players[i].Score.Zone3;
			answer2Index = i;
		}
		if (Players[i].Score.Zone1 + Players[i].Score.Zone2 * 2 + Players[i].Score.Zone3 * 3 > answer3) {
			answer3 = Players[i].Score.Zone1 + Players[i].Score.Zone2 * 2 + Players[i].Score.Zone3 * 3;
			answer3Index = i;
		}

		if (i / 4 == 0) {
			Jets.TotalPlayer[i].Score = Players[i].Score.Zone1 + Players[i].Score.Zone2 * 2 + Players[i].Score.Zone3 * 3;
			Jets.TotalPlayer[i].Index = i;
			Jets.Total += Jets.TotalPlayer[i].Score;
		}
		else {
			Sharks.TotalPlayer[i - 4].Score = Players[i].Score.Zone1 + Players[i].Score.Zone2 * 2 + Players[i].Score.Zone3 * 3;
			Sharks.TotalPlayer[i - 4].Index = i;
			Sharks.Total += Sharks.TotalPlayer[i - 4].Score;
		}
	}

	std::sort(Jets.TotalPlayer, Jets.TotalPlayer + 4, [](tp a, tp b) -> bool {return a.Score > b.Score; });
	std::sort(Sharks.TotalPlayer, Sharks.TotalPlayer + 4, [](tp a, tp b) -> bool {return a.Score > b.Score; });

	cout << answer1 << '\n';
	cout << Players[answer2Index].Name << '\n';
	cout << Players[answer3Index].Name << '\n';
	if (Jets.Total > Sharks.Total) {
		cout << Jets.Total << '\n';
		cout << Players[Sharks.TotalPlayer[1].Index].Name << '\n';
	}
	else {
		cout << Sharks.Total << '\n';
		cout << Players[Jets.TotalPlayer[1].Index].Name << '\n';
	}

	return 0;
}