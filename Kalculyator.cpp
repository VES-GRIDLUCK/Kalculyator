// Kalculyator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
double expression();
double term();
double power();
double factor();
double number();

void interface()
{
	cout << "\t\t=================================================================\n";
	cout << "\t\t|                          #############                        |\n";
	cout << "\t\t| ( - + * \/ * + - )         КАЛЬКУЛЯТОР       ( - + * \/ * + - ) |\n";
	cout << "\t\t|                          $$$$$$$$$$$$$                        |\n";
	cout << "\t\t=================================================================\n";
}
//Сложение и вычитание
double expression()
{
	double result;
	char operation;

	result = term();

	while (true)
	{

		operation = cin.get();

		switch (operation)
		{
		case '+':
			result += term();
			break;
		case '-':
			result -= term();
			break;
		default:
			cin.putback(operation);
			return result;

		}
	}
}
//Умножение и деление проверка на 0
double term()
{
	double result;
	char operation;
	double temp;

	result = power();

	while (true)
	{
		operation = cin.get();

		switch (operation)
		{
		case '*':
			result *= power();
			break;
		case '/':
			temp = power();

			if (temp == 0.0)
			{
				cout << "Деление на 0!" << endl;
			}

			result /= temp;
			break;
		default:
			cin.putback(operation);
			return result;
		}
	}
}
//Степени
double power()
{
	double result;
	char operation;
	vector < double > args;

	args.push_back(factor());

	while (true)
	{
		operation = cin.get();

		while (operation == ' ')
			operation = cin.get();

		if (operation == '^')
			args.push_back(factor());
		else
		{
			cin.putback(operation);
			break;
		}
	}

	for (int i = args.size() - 1; i > 0; i--)
		args[i - 1] = pow(args[i - 1], args[i]);

	return args[0];
}
//Скобки
double factor()
{
	double result;
	char bracket;
	int sign = 1;

	bracket = cin.get();

	while (bracket == ' ')
		bracket = cin.get();

	switch (bracket)
	{
	case '-':
		sign = -1;
	case '+':
		bracket = cin.get();
		break;
	}

	while (bracket == ' ')
		bracket = cin.get();

	if (bracket == '(')
	{
		result = expression();
		bracket = cin.get();

		if (bracket != ')')
		{
			cout << "Нехватает скобки!" << std::endl;
		}
	}
	else
	{
		cin.putback(bracket);
		result = number();
	}

	return sign * result;
}
//Знаки после запятой
double number()
{
	double result = 0.0;
	char digit;
	double k = 10.0;
	int sign = 1;

	digit = cin.get();

	switch (digit)
	{
	case '-':
		sign = -1;
		break;
	default:
		if (digit != '+')
			cin.putback(digit);

		break;
	}

	while (true)
	{
		digit = cin.get();

		while (digit == ' ')
			digit = cin.get();

		if (digit >= '0' && digit <= '9')
			result = result * 10.0 + (digit - '0');
		else
		{
			cin.putback(digit);
			break;
		}
	}

	digit = cin.get();

	if (digit == '.')
	{
		while (true)
		{
			digit = cin.get();

			while (digit == ' ')
				digit = cin.get();

			if (digit >= '0' && digit <= '9')
			{
				result += (digit - '0') / k;
				k *= 10.0;
			}
			else
			{
				cin.putback(digit);
				break;
			}
		}
	}
	else
		cin.putback(digit);

	return sign * result;
}

int main()
{
	setlocale(LC_ALL, "ru");
	system("Color E0");
	interface();
	while (true) {
		switch (true) {
		case 1:
			double n;
			cout << "Введите ваш пример " << endl;
			n = expression();

			cout << "Ответ : " << n << endl;

			cin.get();
			cin.get();
			break;
		}
	}
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
