#include <iostream>
#include <unordered_set>
#include <map>
#include <string>
#include <vector>
#include <deque>

void countDiffNum() {
    std::unordered_set<int> numbers;
    int quantity = 0;
    std::cin >> quantity;

    for (int i = 0; i < quantity; ++i) {
        int num;
        std::cin >> num;
        numbers.insert(num);
    }

    std::cout << numbers.size();
}

void doClassList() {
    std::map<int, std::vector<std::string>> classList;
    int classNum = 0;
    std::string surname;

    while (std::cin >> classNum >> surname) {
        classList[classNum].push_back(surname);
    }

    for (int classNum = 9; classNum <= 11; ++classNum) {
        for (int k = 0; k < classList[classNum].size(); k++) {
            std::cout << classNum << " " << classList[classNum][k] << std::endl;
        }

    }  
}

void playCardWar() {
    int firstPlayer = 0;
    int secondPlayer = 0;
    const int kNumOfCards = 5;
    long long step = 0;
    const long long kMaxStep = pow(10, 6);
    std::deque<int> firstDeque;
    std::deque<int> secondDeque;

    for (int i = 0; i < kNumOfCards; i++) {
        std::cin >> firstPlayer;
        firstDeque.push_back(firstPlayer);
    }

    for (int i = 0; i < kNumOfCards; i++) {
        std::cin >> secondPlayer;
        secondDeque.push_back(secondPlayer);
    }

    for (unsigned i{}; i < kNumOfCards; i++) {
        if (firstDeque.empty() || secondDeque.empty()) {
            break;
        }
        else if ((firstDeque.at(i) == 0 && secondDeque.at(i) == 9) ||
            (secondDeque.at(i) == 0 && firstDeque.at(i) == 9)) {
            if (firstDeque.at(i) == 0) {
                firstDeque.push_back(firstDeque.front());
                firstDeque.push_back(secondDeque.front());
            }
            else {
                secondDeque.push_back(firstDeque.front());
                secondDeque.push_back(secondDeque.front());
            }
            firstDeque.pop_front();
            secondDeque.pop_front();
            step++;
            i--;
        }
        else if (firstDeque.at(i) > secondDeque.at(i)) {
            firstDeque.push_back(firstDeque.front());
            firstDeque.push_back(secondDeque.front());
            firstDeque.pop_front();
            secondDeque.pop_front();
            step++;
            i--;
        }
        else {
            secondDeque.push_back(firstDeque.front());
            secondDeque.push_back(secondDeque.front());
            firstDeque.pop_front();
            secondDeque.pop_front();
            step++;
            i--;
        }

        if (step > kMaxStep) {
            std::cout << "botva" << std::endl;
            exit(1);
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");

    // Задача №1418. Разные
    countDiffNum();

    // Задача №49. Списки по классам
    doClassList();

    // Задача №50.Игра в пьяницу
    playCardWar();

    return 0;
}
