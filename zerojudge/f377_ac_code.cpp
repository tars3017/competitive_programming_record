#include <iostream>
#include <string>
using namespace std;
#define Priority(x) (x == '+' || x == '-' ? 1 : (x == '*' || x == '/' ? 2 : 0))

int main() {
	/* cin.sync_with_stdio(false), cin.tie(nullptr); */
	char operators[1000];
	string expression;
	int pointer = 0;
	while (getline(cin, expression)) {
		for (int i = 0; i != expression.size(); ++i) 
			if (expression[i] != ' ') {
				if (isalpha(expression[i]))
					cout << expression[i] << ' ';
				else if (expression[i] == '(')
					operators[pointer] = '(', ++pointer;
				else if (expression[i] == ')') {
					while (operators[pointer - 1] != '(')
						--pointer, cout << operators[pointer] << ' ';
					--pointer;
				}
				else {
					while (pointer && Priority(operators[pointer - 1]) >= Priority(expression[i]))
						--pointer, cout << operators[pointer] << ' ';
					operators[pointer] = expression[i]; ++pointer;
				}
			}
		while (pointer)
			--pointer, cout << operators[pointer] << ' ';
		cout << '\n';
	}
}
