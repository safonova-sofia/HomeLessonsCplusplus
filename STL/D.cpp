#include <iostream>
#include <stack>
#include <string>

int main() {
    std::string sequence;
    std::cin >> sequence;

    std::stack<char> brackets;
    bool isRight = true;

    for (char c : sequence) {
        switch (c) {
        case '(':
            brackets.push(c);
            break;
        case '[':
            brackets.push(c);
            break;
        case '{':
            brackets.push(c);
            break;
        case ')':
            if (brackets.empty() || brackets.top() != '(') {
                isRight = false;
                break;
            }
            brackets.pop();
            break;
        case ']':
            if (brackets.empty() || brackets.top() != '[') {
                isRight = false;
                break;
            }
            brackets.pop();
            break;
        case '}':
            if (brackets.empty() || brackets.top() != '{') {
                isRight = false;
                break;
            }
            brackets.pop();
            break;
        default:
            isRight = false;
            break;
        }
        if (!isRight) break;
    }

    if (isRight && brackets.empty()) {
        std::cout << "yes" << std::endl;
    }
    else {
        std::cout << "no" << std::endl;
    }

    return 0;
}
