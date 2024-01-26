#include <iostream>
#include <cmath> 


// Task 1.
void Task1() {
	float b1 = 0;
	float b2 = 0;
	float height = 0;

	std::cout << "Задача 1" << std::endl;
	std::cout << "Введите основание b1:" << std::endl;
	std::cin >> b1;
	std::cout << "Введите основание b2:" << std::endl;
	std::cin >> b2;
	std::cout << "Введите высоту:" << std::endl;
	std::cin >> height;

	if (b1 > 0 && b2 > 0 && height > 0) {
		std::cout << "Площадь трапеции: " << (b1 + b2) / 2 * height << std::endl;
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 2
void Task2() {
	const float PI = 3.14;
	float radius = 0;

	std::cout << "Задача 2" << std::endl;
	std::cout << "Введите радиус окружности:" << std::endl;
	std::cin >> radius;

	if (radius > 0) {
		std::cout << "Длина окружности: " << 2 * PI * radius << std::endl;
		std::cout << "Площадь окружности: " << PI * pow(radius, 2) << std::endl;
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 3
void Task3() {
	float leg1 = 0;
	float leg2 = 0;

	std::cout << "Задача 3" << std::endl;
	std::cout << "Введите первый катет:" << std::endl;
	std::cin >> leg1;
	std::cout << "Введите второй катет:" << std::endl;
	std::cin >> leg2;

	if (leg1 > 0 && leg2 > 0) {
		std::cout << "Площадь прямоугольного треугольника: " << leg1 * leg2 / 2 << std::endl;
		std::cout << "Гипотенуза прямоугольного треугольника: " << sqrt(pow(leg1, 2) + pow(leg2, 2)) << std::endl;
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 4. Task 19. Сумма цифр числа
int sumDigits(int number) {
	int sum = 0;
	int tmp = 0;

	// Флаг на отрицательное число
	bool flag = false;
	if (number < 0)
		flag = true;

	while (number != 0) {
		tmp = abs(number % 10);
		sum += tmp;
		number /= 10;
	}

	//Если отрицательно - вычитаем удвоенную первую цифру
	if (flag == true)
		sum -= tmp * 2;

	return sum;
}
// Task 4
void Task4() {
	// P.S. Программа работает для числел любой длины и учитывает знак
	int number = 0;

	std::cout << "Задача 4" << std::endl;
	std::cout << "Введите число:" << std::endl;
	std::cin >> number;

	std::cout << "Сумма цифр: " << sumDigits(number) << std::endl;
}



// Task 5
void Task5() {
	float xRectangular = 0;
	float yRectangular = 0;
	const float PI = 3.14;

	std::cout << "Задача 5" << std::endl;
	std::cout << "Введите x:" << std::endl;
	std::cin >> xRectangular;
	std::cout << "Введите y:" << std::endl;
	std::cin >> yRectangular;

	if (xRectangular) {
		std::cout << "Декартовые координаты: " << "(" << xRectangular << ";" << yRectangular << ")" << std::endl;
		std::cout << "Полярные координаты: " << "(" << sqrt(pow(xRectangular, 2) + pow(yRectangular, 2)) << ";" << (atan(yRectangular / xRectangular) * 180 / PI) << ")" << std::endl;
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 6
void Task6() {
	float xPolar = 0;
	float yPolar = 0;
	const float PI = 3.14;

	std::cout << "Задача 6" << std::endl;
	std::cout << "Введите x:" << std::endl;
	std::cin >> xPolar;
	std::cout << "Введите y (в градусах):" << std::endl;
	std::cin >> yPolar;

	std::cout << "Полярные координаты: " << "(" << xPolar << ";" << yPolar << ")" << std::endl;
	std::cout << "Декартовых координаты: " << "(" << xPolar * cos(yPolar * PI / 180) << ";" << xPolar * sin(yPolar * PI / 180) << ")" << std::endl;
}



// Task 7
void Task7() {
	float a = 0;
	float b = 0;
	float c = 0;
	float d = 0;

	std::cout << "Задача 7" << std::endl;
	std::cout << "Уравение формата ax^2 + bx + c = 0" << std::endl;
	std::cout << "Введите коэффициент a:" << std::endl;
	std::cin >> a;
	std::cout << "Введите коэффициент b:" << std::endl;
	std::cin >> b;
	std::cout << "Введите коэффициент c:" << std::endl;
	std::cin >> c;

	d = pow(b, 2) - 4 * a * c;
	if (d > 0) {
		std::cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << " " << "x2 = " << (-b - sqrt(d)) / (2 * a) << std::endl;
	}
	else if (d == 0) {
		std::cout << "x1 = x2 = " << (-b + sqrt(d)) / (2 * a) << std::endl;
	}
	else {
		std::cout << "Нет действительных корней" << std::endl;
	}
}



// Task 8. Найти медианы треугольника, сторонами которого являются медианы исходного треугольника
float findMedian(float a, float b, float c)
{
	return (0.5 * (sqrt(2 * pow(c, 2) + 2 * pow(b, 2) - pow(a, 2))));
}
// Task 8
void Task8() {
	float a1 = 0;
	float b1 = 0;
	float c1 = 0;
	float a2 = 0;
	float b2 = 0;
	float c2 = 0;

	std::cout << "Задача 8" << std::endl;
	std::cout << "Введите a:" << std::endl;
	std::cin >> a1;
	std::cout << "Введите b:" << std::endl;
	std::cin >> b1;
	std::cout << "Введите c:" << std::endl;
	std::cin >> c1;

	if (((b1 + c1 - a1) > 0) && ((a1 + c1 - b1) > 0) && ((a1 + b1 - c1) > 0)) {
		std::cout << "Первоначальный треугольник со сторонами: " << a1 << " " << b1 << " " << c1 << std::endl;
		a2 = findMedian(a1, b1, c1);
		b2 = findMedian(b1, a1, c1);
		c2 = findMedian(c1, a1, b1);
		std::cout << "Медианы первоночального треугольника aka стороны искомого: " << a2 << " " << b2 << " " << c2 << std::endl;
		a1 = findMedian(a2, b2, c2);
		b1 = findMedian(b2, a2, c2);
		c1 = findMedian(c2, a2, b2);
		std::cout << "Медианы искомого треугольника: " << a1 << " " << b1 << " " << c1 << std::endl;
	}
	else {
		std::cout << "Треугольника не существует" << std::endl;
	}
}



// Task 9
void Task9() {
	int k = 0;
	int hours = 0;
	int minutes = 0;

	std::cout << "Задача 9" << std::endl;
	std::cout << "Введите сутки:" << std::endl;
	std::cin >> k;
	if (k > 0) {
		std::cout << "Прошло " << (k / 3600) << " часов и " << (k % 3600) / 60 << " минут" << std::endl;
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 10
void Task10() {
	float a = 0;
	float b = 0;
	float c = 0;

	std::cout << "Задача 10" << std::endl;
	std::cout << "Введите a:" << std::endl;
	std::cin >> a;
	std::cout << "Введите b:" << std::endl;
	std::cin >> b;
	std::cout << "Введите c:" << std::endl;
	std::cin >> c;

	if (((b + c - a) > 0) && ((a + c - b) > 0) && ((a + b - c) > 0)) {
		if ((a == b) || (b == c) || (a == c)) {
			std::cout << "Треугольник равнобедренный" << std::endl;
		}
		else {
			std::cout << "Треугольник неравнобедренный" << std::endl;
		}
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 11
void Task11() {
	float coasts = 0;
	const float DISCOUNT = 0.1;

	std::cout << "Задача 11" << std::endl;
	std::cout << "Введите первоначальную стоимость покупки:" << std::endl;
	std::cin >> coasts;

	if (coasts > 1000)
	{
		coasts -= coasts * DISCOUNT;
		std::cout << "Сумма со скидкой: " << coasts << std::endl;
	}
	else
	{
		std::cout << "Стоимость товара менее 1000 руб. Скидки нет" << std::endl;
	}
}



// Task 12
void Task12() {
	float height = 0;
	float weight = 0;
	float EPS = 1e-5;

	std::cout << "Задача 12" << std::endl;
	std::cout << "Введите рост:" << std::endl;
	std::cin >> height;
	std::cout << "Введите вес:" << std::endl;
	std::cin >> weight;

	if (weight > 0 && height > 100)
	{
		if (abs(height - 100 - weight) < EPS) {
			std::cout << "У вас идеальный вес" << std::endl;
		}
		else if (height - 100 > weight)
		{
			std::cout << "Набрать " << (height - 100) - weight << " кг" << std::endl;
		}
		else if (height - 100 < weight)
		{
			std::cout << "Сбросить " << weight - (height - 100) << " кг" << std::endl;
		}
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 13
void Task13() {
	srand(time(NULL));
	int randFirstNum = rand() % 9 + 1;
	int randSecondNum = rand() % 9 + 1;
	int inputResult = 0;

	std::cout << "Задача 13" << std::endl;
	std::cout << "Введите произведение двух чисел:" << std::endl;
	std::cin >> inputResult;

	if (randFirstNum * randSecondNum == inputResult)
	{
		std::cout << "Вы угадали число. Ответ: " << inputResult << std::endl;
	}
	else {
		std::cout << "Вы НЕ угадали число. Ответ: " << randFirstNum * randSecondNum << " произведение " << randFirstNum << " и " << randSecondNum << std::endl;
	}
}



// Task 14
void Task14() {
	float price = 0;
	float lengthСonversation = 0;
	int day = 0;

	std::cout << "Задача 14" << std::endl;
	std::cout << "Введите цену за минуту разговора:" << std::endl;
	std::cin >> price;
	std::cout << "Введите длину разговора:" << std::endl;
	std::cin >> lengthСonversation;
	std::cout << "Введите день недеди:" << std::endl;
	std::cin >> day;

	if (day > 0 && day < 8 && price > 0 && lengthСonversation > 0) {
		if (day == 6 || day == 7) {
			price = (price * lengthСonversation) - (price * lengthСonversation) * 0.2;
			std::cout << "Сумма: " << price << std::endl;
		}
		else {
			std::cout << "Сумма: " << price * lengthСonversation << std::endl;
		}
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 15
void Task15() {
	int month = 0;

	std::cout << "Задача 15" << std::endl;
	std::cout << "Введите месяц:" << std::endl;
	std::cin >> month;

	if (month > 0 && month < 13) {
		switch (month)
		{
		case 1:
			std::cout << "Январь. Зима" << std::endl;
			break;
		case 2:
			std::cout << "Февраль. Зима" << std::endl;
			break;
		case 3:
			std::cout << "Март. Весна" << std::endl;
			break;
		case 4:
			std::cout << "Апрель. Весна" << std::endl;
			break;
		case 5:
			std::cout << "Май. Весна" << std::endl;
			break;
		case 6:
			std::cout << "Июнь. Лето" << std::endl;
			break;
		case 7:
			std::cout << "Июль. Лето" << std::endl;
			break;
		case 8:
			std::cout << "Август. Лето" << std::endl;
			break;
		case 9:
			std::cout << "Сентабрь. Осень" << std::endl;
			break;
		case 10:
			std::cout << "Октябрь. Осень" << std::endl;
			break;
		case 11:
			std::cout << "Ноябрь. Осень" << std::endl;
			break;
		case 12:
			std::cout << "Декабрь. Зима" << std::endl;
			break;
		default:
			std::cout << "Ошибка в введеном значении" << std::endl;;
			break;
		}
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 16
void Task16() {
	int number = 0;

	std::cout << "Задача 16" << std::endl;
	std::cout << "Введите число:" << std::endl;
	std::cin >> number;

	if (number > 99999 && number < 1000000) {
		if (((number / 100000) + ((number % 100000) / 10000) + ((number % 10000) / 1000)) == ((number % 10) + ((number % 100) / 10) + ((number % 1000) / 100)))
		{
			std::cout << "Счатливое число" << std::endl;
		}
		else {
			std::cout << "Несчатливое число" << std::endl;
		}
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 17
void Task17() {
	int kopeck = 0;

	std::cout << "Задача 17" << std::endl;
	std::cout << "Введите копейки:" << std::endl;
	std::cin >> kopeck;

	// ноль, пять, шесть, семь, восемь, девять - копеек; одна - копейка; две, три, четыре  - копейки
	if (kopeck > 0 && kopeck < 100) {
		switch (kopeck % 10)
		{
		case 0:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
			std::cout << kopeck << " копеек" << std::endl;
			break;
		case 1:
			std::cout << kopeck << " копейка" << std::endl;
			break;
		case 2:
		case 3:
		case 4:
			std::cout << kopeck << " копейки" << std::endl;
			break;
		default:
			std::cout << "Ошибка в введеном значении" << std::endl;
			break;
		}
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 18
void Task18() {
	int number = 0;

	std::cout << "Задача 18" << std::endl;
	std::cout << "Введите число:" << std::endl;
	std::cin >> number;

	if (number > 999 && number < 10000) {
		if ((number / 1000) == (number % 10) && (((number / 100) % 10) == ((number % 100) / 10))) {
			std::cout << "Палиндром" << std::endl;
		}
		else {
			std::cout << "Не палиндром" << std::endl;
		}
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 19
void Task19() {
	int number = 0;
	int b = 0;
	int production = 1;


	std::cout << "Задача 19" << std::endl;
	std::cout << "Введите число:" << std::endl;
	std::cin >> number;
	std::cout << "Введите b:" << std::endl;
	std::cin >> b;

	if (number > 99 && number < 1000) {
		int tmp = number;
		while (tmp > 0) {
			production *= tmp % 10;
			tmp /= 10;
		}
		if (production > b) {
			std::cout << "Произведение его цифр больше b" << std::endl;
		}
		else {
			std::cout << "Произведение его цифр НЕ больше b" << std::endl;
		}
		// см. задание 4
		if (sumDigits(number) % 7 == 0) {
			std::cout << "Сумма цифр кратна 7" << std::endl;
		}
		else {
			std::cout << "Сумма цифр не кратна 7" << std::endl;
		}
	}
	else {
		std::cout << "Некорректно введенные данные" << std::endl;
	}
}



// Task 20
void Task20() {
	float a = 0;
	float b = 0;
	float c = 0;
	float d = 0;

	std::cout << "Задача 20" << std::endl;
	std::cout << "Введите a" << std::endl;
	std::cin >> a;
	std::cout << "Введите b" << std::endl;
	std::cin >> b;
	std::cout << "Введите c" << std::endl;
	std::cin >> c;
	std::cout << "Введите d" << std::endl;
	std::cin >> d;

	if (a > 0 && b > 0 && c > 0 && d > 0) {
		if ((a <= c && b <= d) || (a <= d && b <= c)) {
			std::cout << "Прямоугольник со сторонами a,b может поместиться в прямоугольник со сторонами c, d" << std::endl;
		}
		else {
			std::cout << "Прямоугольник со сторонами a,b НЕ может поместиться в прямоугольник со сторонами c, d" << std::endl;
		}
	}
	else {

		std::cout << "Неверный формат данных" << std::endl;
	}
}



// Task 21
void Task21() {
	// Каждый фундаментальный тип непосредственно соответствует аппаратным возможностям и имеет фиксированный размер, который определяет диапазон значений, которые могут в нем храниться.
	// Размер типа зависит от реализации (т.е. может меняться от машины к машине). См. в отчете номер 21.
	short shortNum = 0;
	int intNum = 0;
	long longNum = 0;
	long long longLongNum = 0;

	std::cout << "Задача 21" << std::endl;
	std::cout << "sizeof(shortNum) = " << sizeof(shortNum) << std::endl;
	std::cout << "sizeof(intNum) = " << sizeof(intNum) << std::endl;
	std::cout << "sizeof(longNum) = " << sizeof(longNum) << std::endl;
	std::cout << "sizeof(longLongNum) = " << sizeof(longLongNum) << std::endl;

	float floatNum = 0;
	double doubleNum = 0;
	long double longDoubleNum = 0;

	std::cout << "sizeof(floatNum) = " << sizeof(floatNum) << std::endl;
	std::cout << "sizeof(doubleNum) = " << sizeof(doubleNum) << std::endl;
	std::cout << "sizeof(longDoubleNum) = " << sizeof(longDoubleNum) << std::endl;

	char charNum = '0';
	wchar_t wchar_tNum = '0';

	std::cout << "sizeof(charNum) = " << sizeof(charNum) << std::endl;
	std::cout << "sizeof(wchar_t) = " << sizeof(wchar_t) << std::endl;
}



int main()
{
	setlocale(LC_ALL, "RU");

	/* Task 1 */
	// Вычислить площадь трапеции с основаниями b1 и b2 и высотой h 
	std::cout << "Result of 1 task" << std::endl;
	Task1();
	std::cout << std::endl;

	/* Task 2 */
	// Вычислить длину окружности и площадь круга радиуса г
	std::cout << "Result of 2 task" << std::endl;
	Task2();
	std::cout << std::endl;

	/* Task 3 */
	// Вычислить площадь прямоугольного треугольника и гипотенузу
	std::cout << "Result of 3 task" << std::endl;
	Task3();
	std::cout << std::endl;

	/* Task 4 */
	// Дано десятичное четырехзначное число. Найти сумму его цифр
	std::cout << "Result of 4 task" << std::endl;
	Task4();
	std::cout << std::endl;

	/* Task 5 */
	// Выполнить переход от декартовых координат к полярным
	std::cout << "Result of 5 task" << std::endl;
	Task5();
	std::cout << std::endl;

	/* Task 6 */
	// Выполнить переход от полярных координат к декартовым
	std::cout << "Result of 6 task" << std::endl;
	Task6();
	std::cout << std::endl;

	/* Task 7 */
	// Найти корни квадратного уравнения
	std::cout << "Result of 7 task" << std::endl;
	Task7();
	std::cout << std::endl;

	/* Task 8 */
	// Имеется треугольник со сторонами а, b, с. Найти медианы треугольника, сторонами которого являются медианы исходного треугольника
	std::cout << "Result of 8 task" << std::endl;
	Task8();
	std::cout << std::endl;

	/* Task 9 */
	// Идет k-я секунда суток. Определить, сколько целых часов и целых минут прошло с начала суток.
	std::cout << "Result of 9 task" << std::endl;
	Task9();
	std::cout << std::endl;

	/* Task 10 */
	// Определить, является ли треугольник со сторонами a, b, c равнобедренным	
	std::cout << "Result of 10 task" << std::endl;
	Task10();
	std::cout << std::endl;

	/* Task 11 */
	// Вычислить стоимость покупки с учётом скидки. Скидка в 10% предоставляется, если сумма покупки превышает 1000 рублей.
	std::cout << "Result of 11 task" << std::endl;
	Task11();
	std::cout << std::endl;

	/* Task 12 */
	// Дать рекомендации пользователю с известным ростом и весом похудеть или поправиться, если идеальный вес определяется формулой (рост - 100 = идеальный вес).
	std::cout << "Result of 12 task" << std::endl;
	Task12();
	std::cout << std::endl;

	/* Task 13 */
	// Программа генерирует два случайных числа в диапазоне от 1 до 9. Тестируемый вводит результат произведения этих чисел. Программа сообщает тестируемому ошибся он или нет.
	std::cout << "Result of 13 task" << std::endl;
	Task13();
	std::cout << std::endl;

	/* Task 14 */
	// Написать программу вычисления стоимости переговоров, если по субботам и воскресеньям предоставляется скидка 20%. Ввести продолжительность разговора и день недели(число от 1 до 7).
	std::cout << "Result of 14 task" << std::endl;
	Task14();
	std::cout << std::endl;

	/* Task 15 */
	// Ввести с клавиатуры номер месяца. Выдать сообщение о названии месяца и времени года.
	std::cout << "Result of 15 task" << std::endl;
	Task15();
	std::cout << std::endl;

	/* Task 16 */
	// Определить, является ли шестизначное число "счастливым"
	std::cout << "Result of 16 task" << std::endl;
	Task16();
	std::cout << std::endl;

	/* Task 17 */
	// Написать программу, которая при вводе числа в диапазоне от 1 до 99 добавляет к нему слово "копейка" в правильной форме.
	std::cout << "Result of 17 task" << std::endl;
	Task17();
	std::cout << std::endl;

	/* Task 18 */
	// Дано натуральное четырехзначное число. Выяснить, является ли оно палиндромом.
	std::cout << "Result of 18 task" << std::endl;
	Task18();
	std::cout << std::endl;

	/* Task 19 */
	// Дано трёхзначное число. Определить: 19.1 является ли произведение его цифр больше числа b 19.2 кратна ли 7 сумма его цифр.
	std::cout << "Result of 19 task" << std::endl;
	Task19();
	std::cout << std::endl;

	/* Task 20 */
	// Даны вещественные положительные числа a, b, c, d. Выяснить, можно ли прямоугольник со сторонами a, b поместить в прямоугольник со сторонами c, d так, чтобы стороны одного прямоугольника были параллельны сторонам другого.
	std::cout << "Result of 20 task" << std::endl;
	Task20();
	std::cout << std::endl;

	/* Task 21 */
	// Написать программу, в которой выводятся размеры основных типов данных. Сделать выводы.
	std::cout << "Result of 21 task" << std::endl;
	Task21();
	std::cout << std::endl;



	return 0;
}

