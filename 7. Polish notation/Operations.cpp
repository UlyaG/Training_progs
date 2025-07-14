#include <iostream>
#include <stack>
#include "Functions.h"
using namespace std;

int priority(char op) {
	switch (op) {
	case '(':
		return 1;
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	default:
		return 0;
	}
}


string fromSimpToPrefix(string smpl) {
	stack <char> operators;
	stack <string> operands;
	for (int i = 0; i < smpl.length(); i++) {
		if (((smpl[i] >= '0') && (smpl[i] <= '9')) || ((smpl[i] >= 'A') && (smpl[i] <= 'z'))) {
			operands.push(string(1, smpl[i]));
		}
		if (smpl[i] == '(') {
			operators.push(smpl[i]);
		}
		if (smpl[i] == ')') {
			while (!operators.empty() && operators.top() != '(') {
				string operand2 = operands.top();
				operands.pop();
				string operand1 = operands.top();
				operands.pop();
				string str = operators.top() + operand1 + operand2;
				operators.pop();
				operands.push(str);
			}
			operators.pop();
		}
		if (priority(smpl[i]) > 1) {
			while (!operators.empty() && operators.top() != '(' && (priority(operators.top()) > priority(smpl[i]))) {
				string operand2 = operands.top();
				operands.pop();
				string operand1 = operands.top();
				operands.pop();
				string str = operators.top() + operand1 + operand2;
				operators.pop();
				operands.push(str);
			}

			operators.push(smpl[i]);
		}
	}
	while (!operators.empty()) {

		string operand2 = operands.top();
		operands.pop();
		string operand1 = operands.top();
		operands.pop();
		string str = operators.top() + operand1 + operand2;
		operators.pop();
		operands.push(str);
	}

	return operands.top();
}

string fromSimpToReverse(string smpl) {
	stack <char> operators;
	string rvrs;
	for (int i=0;i<smpl.length();i++) {

		if (((smpl[i] >= '0') && (smpl[i] <= '9')) || ((smpl[i] >= 'A') && (smpl[i] <= 'z'))) {
			rvrs += smpl[i];
		}
		else if (smpl[i] == ')') {
			while (operators.top() != '(') {
				rvrs += operators.top();
				operators.pop();
			}
			operators.pop();
		}
		else if (smpl[i] == '(') {
			operators.push(smpl[i]);

		}
		else if ((priority(smpl[i])) != 0) {
			while (!(operators.empty())&&((priority(operators.top())) >= (priority(smpl[i])))) {
				rvrs += operators.top();
				operators.pop();
			}
			if ((operators.empty()) || ((priority(operators.top())) < (priority(smpl[i])))) {
				operators.push(smpl[i]);
			}
		}

	}
	while (!operators.empty()) {
		rvrs += operators.top();
		operators.pop();
	}
	
	return rvrs;
}

void isCorrect(string  smpl) {
	int countOpenBr = 0, countCloseBr = 0, countOper = 0, countNumb = 0;
	bool bracketMist = 0, operMist = 0, operCountMist = 0, numbMist = 0;
	for (int i=0;i<smpl.length()-1;i++) {
		if (smpl[i] == '(')
			countOpenBr++;
		if (smpl[i+1] == ')')
			countCloseBr++;
		if ((priority(smpl[i])>1) && (priority(smpl[i+1]) > 1)) 
			operMist = 1;
		if (priority(smpl[i]) > 1) 
			countOper++;
		if (((smpl[i] >= '0') && (smpl[i] <= '9')) || ((smpl[i] >= 'A') && (smpl[i] <= 'z'))) 
			countNumb++;
	}
}