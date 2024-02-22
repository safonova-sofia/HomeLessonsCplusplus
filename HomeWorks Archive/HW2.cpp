#include <iostream>
#include <string>

// вспомогательные функции

int findSubString(std::string str, std::string subStr) {
    int positionStr = 0;
    while (positionStr < str.size() - (subStr.size() - 1)) {
        int tmp = 0;
        while (tmp <= (subStr.size() - 1) && str[positionStr + tmp] == subStr[tmp]) {
            tmp++;
        }
        if (tmp == subStr.size()) {
            return positionStr;
        }
        positionStr++;
    }
    return -1;
}

// Task 1
void numberOfLowercaseAndUppercase() {
    int countLowercase = 0;
    int countCapitals = 0;
    std::string str;
    
    std::cout << "Введите строку: " << std::endl;
    getline(std::cin, str);

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            countLowercase++;
        };

        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            countCapitals++;
        };

    };
    std::cout << "Строчные " << countLowercase << std::endl;
    std::cout << "Прописные " << countCapitals << std::endl; 
}

// Task 2
void numberOfWordsInLine() {
    bool flag = true; // внутри слова
    int count = 0;
    std::string str;

    std::cout << "Введите строку: " << std::endl;
    getline(std::cin, str);

    for (int i = 0; i < str.size(); i++) {
        if ((('a' <= str[i]) && ('z' >= str[i])) || (('A' <= str[i]) && ('Z' >= str[i])))
        {
            if (flag == true)
            {
                flag = false;
                count++;

            }
        }
        else if (str[i] = ' ') {
            flag = true;
        }
    };

    std::cout << "Кол-во слов: " << count << std::endl;
}

// Task 3
void composeWordsFromLetters() {
    std::string str;
    int i = 0;
    int j = 0;
    

    std::cout << "Введите строку: " << std::endl;
    getline(std::cin, str);
    int ls = str.size();

    for (i = 0; i < 5; i++)
    {
        int lw = rand() % (7 - 2 + 1) + 2;
        std::string w;
        while (j < lw)
        {
            int let = rand() % ls;
            if (str[let] != ' ')
            {
                w += str[let];
                ++j;
            }
        }
        j = 0;

        std::cout << w << std::endl;
    }
}

// Task 4
void removeRepeatedCharacters() {
    std::string str;
    std::cout << "Введите строку: " << std::endl;
    getline(std::cin, str);

    // удаляем пробелы
    str.erase(remove(str.begin(), str.end(), ' '), str.end());


    for (int i = 0; i < str.size(); i++) {
        while (true) {
            int j = str.find_last_of(str[i]);
            if (i < j) {
                str.erase(j, 1);
            }
            else {
                break;
            }
        }
    }
       
    std::cout << str << std::endl; 

}

// Task 5
void longestStringInArray() {
    int quantityOfLines = 0;
    int positionMaxLength = 0;

    std::string str;

    const int AMOUNT = 100;
    std::string lines[AMOUNT]{};

    // пользователь вводит число вводимых строк
    std::cout << "Введите кол-во вводимых строк:" << std::endl;
    std::cin >> quantityOfLines;

    getline(std::cin, str); // "дочитываем" конец строки из потока; возвращает пустую строку

    std::cout << "Введите строку: " << std::endl;
    for (int i = 0; i < quantityOfLines; i++)
    {
        getline(std::cin, lines[i]);
    }

    std::cout << std::endl;

    // удаляем пробелы
    std::cout << "№" << " " << "Строка" << " " << "Длина" << std::endl;
    for (int i = 0; i < quantityOfLines; i++)
    {
        lines[i].erase(remove(lines[i].begin(), lines[i].end(), ' '), lines[i].end());
        std::cout << i << " " << lines[i] << " " << lines[i].size() << std::endl;
    }

    // ищем максимальную длину
    for (int i = 1; i < quantityOfLines; i++)
    {
        if (lines[i].size() >= lines[positionMaxLength].size()) {
            positionMaxLength = i;
        };
    }

    std::cout << std::endl;

    std::cout << "№" << " " << "Строка" << " " << "Длина" << std::endl;
    for (int i = 0; i < quantityOfLines; i++)
    {
        if (lines[i].size() == lines[positionMaxLength].size()) {
            std::cout << i << " " << lines[i] << " " << lines[i].size() << std::endl;
        }

    }
}

// Task 6
void isPalindrome() {
    std::string str;
    std::cout << "Введите строку: " << std::endl;
    getline(std::cin, str);
    bool flag = true;

    // удаляем пробелы
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    // проверка на паллиндром
    for (int i = 0; i < str.size(); i++) {
        flag = true;
        {
            if (str[i] != str[str.size() - i - 1]) {
                flag = false;    
            }
        }
    }
    if (flag == false) {
        std::cout << "Not palindrome" << std::endl;
    }
    else {
        std::cout << "Palindrome" << std::endl;
    }

    
}

// Task 7
void replaceSubString() {
    int position = -1;

    std::string str;
    std::string subStr;
    std::string newStr;

    std::cout << "Введите строку:" << std::endl;
    getline(std::cin, str);
    std::cout << "Введите подстроку:" << std::endl;
    getline(std::cin, subStr);
    std::cout << "Введите новую строку:" << std::endl;
    getline(std::cin, newStr);

    // удаление пробелов в строках
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    subStr.erase(remove(subStr.begin(), subStr.end(), ' '), subStr.end());
    newStr.erase(remove(newStr.begin(), newStr.end(), ' '), newStr.end());

    // найдем индекс с которого начинается подстрока
    position = findSubString(str, subStr);

    str.erase(position, subStr.size());
    str.insert(position, newStr);

    std::cout << "Итого: " << str << std::endl;
}

// Task 8
void findLongestWord() {
    int length = 0;
    int maxLength = -1;
    int index = -1;
    std::string str;

    std::cout << "Введите строку: " << std::endl;
    getline(std::cin, str);

    for (int i = 0; i < str.size(); i++) {
        if ((('a' <= str[i]) && ('z' >= str[i])) || (('A' <= str[i]) && ('Z' >= str[i])))
        {
            length++;

            if (maxLength < length) {
                maxLength = length;
                index = i - length + 1;
            }
        }
        else if (str[i] = ' ') {
            length = 0;
        }
    }

    std::cout << "Самое длиноое слово: " << str.substr(index,maxLength) << std::endl;
    
}



int main()
{
    setlocale(LC_ALL, "RU");

    /*Task 1*/
    std::cout << "Result of 1 task:" << std::endl;
    numberOfLowercaseAndUppercase();
    std::cout << std::endl;

    
    /*Task 2*/
    std::cout << "Result of 2 task:" << std::endl;
    numberOfWordsInLine();
    std::cout << std::endl;
    
    /*Task 3*/
    std::cout << "Result of 3 task:" << std::endl;
    composeWordsFromLetters();
    std::cout << std::endl;
    
    /*Task 4*/
    std::cout << "Result of 4 task:" << std::endl;
    removeRepeatedCharacters();
    std::cout << std::endl;
    
    /*Task 5*/
    std::cout << "Result of 5 task:" << std::endl;
    longestStringInArray();
    std::cout << std::endl;
    
    /*Task 6*/
    std::cout << "Result of 6 task:" << std::endl;
    isPalindrome();
    std::cout << std::endl;
    
    /*Task 7*/
    std::cout << "Result of 7 task:" << std::endl;
    replaceSubString();
    std::cout << std::endl;
    
    /*Task 8*/
    std::cout << "Result of 8 task:" << std::endl;
    findLongestWord();
    std::cout << std::endl;
}


