#include "Calculator.h"
double string_to_double(string s);
int Calculator::getPrecedence(char c,bool isCurrent){
	switch (c) {
	case '=':return 0;
	case'#':return 1;
	case'+':case'-':return (isCurrent) ? 3 : 4;
	case '*':case'/':case'%':return (isCurrent) ? 5 : 6;
	case '(':return (isCurrent) ? 8 : 2;
	case ')':return 2;
	case '^':return 7;
	case's':case'n':return (isCurrent) ? 7 : 2;
	default:return -1;
	}
}
void Calculator::GetTwoNum(double &Num1, double &Num2) {
	Num1 = Nstack.Pop();
	Num2 = Nstack.Pop();
}
void Calculator::GetOneNum(double &Num) {
	Num = Nstack.Pop();
}
void Calculator::Compute(char Opr) {
	double Num, Num1, Num2;
	if (Opr != '=') {
		if (Opr == '+') {GetTwoNum(Num1, Num2);Nstack.Push(Num1 + Num2);}
		else if(Opr == '-') {
			GetTwoNum(Num1, Num2); Nstack.Push(Num2 - Num1);
		}
		else if (Opr == '*') {
			GetTwoNum(Num1, Num2); Nstack.Push(Num2 * Num1);
		}
		else if (Opr == '/') {
			GetTwoNum(Num1, Num2); Nstack.Push(Num2 / Num1);
		}
		else if (Opr == '^') {
			GetTwoNum(Num1, Num2); Nstack.Push(pow(Num2,Num1));
		}
		else if (Opr == '%') {
			GetTwoNum(Num1, Num2); Nstack.Push(int(Num2) % int(Num1));
		}
		else if (Opr == 'n') {
			GetOneNum(Num); Nstack.Push(sin(Num));
		}
		else if (Opr == 's') {
			GetOneNum(Num); Nstack.Push(cos(Num));
		}
		else return;	
	}
}
double Calculator::Cal(string str){
	char top;
	for (unsigned int i = 0; i < str.size(); i++) {
		if (str[i]=='('&&str[i+1]=='-'&&(str[i+2] >= '0'&&str[i+2] <= '9')) {
			string temp;
			i++;
			while ((i++)&&((str[i]) >= '0'&&str[i] <= '9') || str[i] == '.') 
				temp += str[i];
			Nstack.Push((-1)*string_to_double(temp));
			temp.clear();
		}
		else if ((str[i]>='0'&&str[i]<='9')) {
			string temp;
			temp += str[i];
			while ((++i)&&((str[i]) >= '0'&&str[i] <= '9')||str[i]=='.')
				temp += str[i];
			Nstack.Push(string_to_double(temp));
			temp.clear();
			i--;
		}
		else if ((str[i])<'0'||str[i]>'9') {
			if (str[i] == 's' || str[i] == 'c') i+=2;
			if (Ostack.IsEmpty()) {
				Ostack.Push(str[i]);
			}
			else{
			top=Ostack.GetTop();
			if (getPrecedence(str[i],true) > getPrecedence(top,false) || str[i] == '(') {
				Ostack.Push(str[i]);
			}
			else {
				while (getPrecedence(str[i], true) <= getPrecedence(top, false)) {
					if (top == '#'&&str[i] == '=') {
						double answer;
						Ostack.Pop();
						answer=Nstack.GetTop();
						cout << answer << endl;
						Nstack.Pop();
						return 0;
					}
					else if (top == '('&&str[i] == ')'){
						++i;
				}
			else {
                  Compute(top);
			}
			Ostack.Pop();
			top=Ostack.GetTop();
			}
				Ostack.Push(str[i]);
	}
}
}
}
}
double string_to_double(string s) {
	int n = s.size();
	int i = -1, j = -1;
	double sum = 0.;
	double sum2 = 0.;
	while (i++ < n - 1) {
		if (s[i] == '-')
			continue;
		if (s[i] == '.')
		{
			j = i;
			continue;
		}
		if (s[i + 1] != '.'&&j == -1 && s[i + 1] != '\0')
		{
			sum = (sum + (s[i] - '0')) * 10;
			continue;
		}
		if (i == n - 1 && s[i + 1] != '.'&&j == -1) {
			sum += (s[i] - '0');
		}
		if (s[i + 1] == '.') {
			sum += (s[i] - '0');
			continue;
		}
		if (s[j + n - i] != '.'&&j != -1) {
			sum2 /= 10.;
			sum2 += (s[j + n - i] - '0') / 10.;
		}
	}
	return s[0] == '-' ? -(sum + sum2) : sum + sum2;
}