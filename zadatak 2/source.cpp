#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool palindromeCheck(string);
string toLower(string);

int main(void) {
	string text;

	cout << "Enter text to check if it's a palindrome: ";
	getline(cin, text);

	if (palindromeCheck(text))
		cout << "This is a palindrome." << endl;
	else
		cout << "This is not a palindrome." << endl;

	return 0;
}

bool palindromeCheck(string str) {
	str.erase(remove(str.begin(), str.end(), ' '), str.end()); //removes all spaces from string
	str = toLower(str);
	string rev(str);

	reverse(rev.begin(), rev.end());

	for (int i = 0;i < str.length();i++)
		if (str[i] != rev[i])
			return false;

	return true;
}

string toLower(string str) {
	for (int i = 0;i < str.length();i++)
		str[i] = tolower(str[i]);

	return str;
}
