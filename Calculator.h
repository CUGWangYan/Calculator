#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "Node.h"
using namespace std;
class Calculator {
	Stack <double>Nstack;
	Stack <char>Ostack;
public:
	Calculator() {};
	double Cal(string str);
	void GetTwoNum(double &Num1, double &Num2);
	void Compute(char Opr);
	void GetOneNum(double &Num);
	int getPrecedence(char c,bool isCurrent);
};