#include <iostream>
#include <vector>

// Вариант 2

struct Account {
	short id;
	char login[16];
	int password;
};

void toFullArray(int** array, int row, int column) {
	srand(time(NULL));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			array[i][j] = 1 + rand() % 70;
		}
	}
};

void toSnowArray(int** array, int row, int column) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
};

void sumAdditinalElements() {

	int rowArray = 0;
	int columnArray = 0;
	int summa = 0;

	std::cout << "Введите кол-во строк:" << std::endl;
	std::cin >> rowArray;
	std::cout << "Введите кол-во столбцов:" << std::endl;
	std::cin >> columnArray;

	int** array = new int* [rowArray];

	//Создание массива
	for (int i = 0; i < rowArray; i++) {
		array[i] = new int[columnArray];
	}

	//Заполнение
	toFullArray(array, rowArray, columnArray);

	std::cout << std::endl;

	//Вывод массива
	toSnowArray(array, rowArray, columnArray);

	// Сумма на побочных диагоналях при условии, что она квадратная
	if (rowArray == columnArray) {
		for (int i = 0; i < rowArray; i++) {
			summa += array[i][rowArray - 1 - i];
		}
	}

	std::cout << std::endl;
	std::cout << "Сумма на побочных диагоналях матрицы: " << summa << std::endl;

	// Возвращаем память
	for (int i = 0; i < rowArray; i++) {
		delete[] array[i];
	}
	delete[] array;
};

Account* createAccout(Account* Obj, const int length){
	// Смотрим размер массива со структурами
	// Если пустой - в создвем структуру
	if (length == 0) {
		Obj = new Account[length + 1];
	}
	// Если уже что-то есть - увеличиваем массив и переносим в "новый" массив
	else {
		Account* tmpObj = new Account[length + 1];
		for (int i = 0; i < length; i++) {
			tmpObj[i] = Obj[i];
		}

		delete[] Obj;

		Obj = tmpObj;
	}
	return Obj;
}

auto deleteAccout() {

}

auto editAccout() {

}

auto printAccout() {

}

void controlAccount() {
	bool flag = true; // продолжить ввод в цикле или остановить ввод
	
	int variation = 0; // выбор действия

	Account* array = 0;
	int length = 0; // кол-во акаунтов

	while (flag != false) {
		std::cout << "Выберите действие:" << std::endl;
		// 1 - создать, 2 - удалить, 3 - редактировать, 4 - выводить
		std::cin >> variation;
		switch (variation)
		{
		case 1:
			array = createAccout(array, length);
			break;
		case 2:
			deleteAccout();
			break;
		case 3:
			editAccout();
			break;
		case 4:
			printAccout();
			break;
		default:
			std::cout << "Ошибка ввода" << std::endl;
			break;
		} 
		exit;
	}

	delete[] array;

}



int main() {
	setlocale(LC_ALL, "RU");

	sumAdditinalElements();
	std::cout << std::endl;

	controlAccount();
	std::cout << std::endl;

	return 0;
}