#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int main() {

	std::string line;
	std::getline(std::cin, line);

	std::istringstream iss(line);
	std::stack<int> operands;
	char operation;

	while (iss >> operation) {
		if (isdigit(operation)) {
			operands.push(operation - '0');
		}
		else {
			int num2 = operands.top();
			operands.pop();
			int num1 = operands.top();
			operands.pop();

			switch (operation) {
			case '+':
				operands.push(num1 + num2);
				break;
			case '-':
				operands.push(num1 - num2);
				break;
			case '*':
				operands.push(num1 * num2);
				break;
			}
		}
	}

	std::cout << operands.top();


	return 0;
}