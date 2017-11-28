#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void wordCheck(string eligible, string letterSet) {
	int len = eligible.size();
	string placeholder = eligible;
	size_t found;
	for (int j = 0; j < len; j++) {
		found = letterSet.find(placeholder[j]);
		if (found == string::npos) {
			return;
		}
		else {
			placeholder[j] = '*';
			letterSet[found] = '#';
		}
	}
	cout << eligible << endl;
	return;
}

int main() {
	cout << "Enter the 9 letters without spaces (key letter should be in the middle)" << endl;
	string nineLetters;
	cin >> nineLetters;
	char key = nineLetters[4];
	ifstream fullWordList("wordlist.txt");
	vector<string> filteredList;
	string word;
	size_t keyFound;
	while (fullWordList >> word) {
		keyFound = word.find(key);
		if (word.size() > 3 && word.size() < 10 && keyFound != string::npos) {
			filteredList.push_back(word);
		}
	}
	for (auto i: filteredList) {
		wordCheck(i, nineLetters);
	}
	system("pause");
	return 0;
}