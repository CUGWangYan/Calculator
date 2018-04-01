#include "Calculator.h"
using namespace std;
int main() {
	Calculator Calcul;
	string str;
	cout << "Please input the equality that begins with '#' and end with '='" << endl;
	cout << "//Warning that you must input the '()' as well when you input a number below zero " << endl;
	while(cin >> str)
	Calcul.Cal(str);
	return 0;
}