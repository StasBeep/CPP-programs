#include <iostream>
#include "Header.h";
using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");

	int n, k, r;
	double eps;
	bool sl = true;

	while (sl)
	{
		cout << "Выберите номер задания:" << endl;
		cout << "1. Задание 1" << endl;
		cout << "2. Задание 2" << endl;
		cout << "3. Задание 3" << endl;
		cout << "4. Задание 4" << endl;
		cout << "5. Задание 5" << endl;
		cout << "6. Выход" << endl << endl;

		cout << "Задание: ";
		cin >> r;
		system("cls");

		switch (r)
		{
		case 1:
			cout << "Задание №1" << endl << endl;

			cout << "Введите количество итераций: ";
			cin >> n;

			cout << endl << "Вычисление значения суммы ряда (for): "
				<< summNfor(n) << endl;

			cout << "Вычисление значения суммы ряда (while): "
				<< summNwhile(n) << endl;

			cout << "Вычисление значения суммы ряда (do...while): "
				<< summNdowhile(n) << endl << endl;
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "Задание №2" << endl << endl;

			cout << "Введите точность: ";
			cin >> eps;

			cout << endl << "Вычисление значения суммы ряда с точностью: "
				<< eps << " (for) = " << summEpsfor(eps) << endl;

			cout << "Вычисление значения суммы ряда с точностью: "
				<< eps << " (while) = " << summEpswhile(eps) << endl;

			cout << "Вычисление значения суммы ряда с точностью: "
				<< eps << " (do...while) = " << summEpsdowhile(eps) << endl << endl;
			system("pause");
			system("cls");
			break;

		case 3:
			cout << "Задание №3" << endl << endl;

			cout << "Введите n: ";
			cin >> n;
			cout << "Введите k: ";
			cin >> k;

			printFor(n, k);
			cout << endl;
			printWhile(n, k);
			cout << endl;
			printDowhile(n, k);
			cout << endl << endl;
			system("pause");
			system("cls");
			break;

		case 4:
			cout << "Задание №4" << endl << endl;

			cout << "Введите точность: ";
			cin >> eps;

			cout << "Номер первого члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (for) " << findFirstElementFor(eps)
				<< endl;

			cout << "Номер первого члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (while) " << findFirstElementWhile(eps)
				<< endl;

			cout << "Номер первого члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (do...while) " << findFirstElementDowhile(eps)
				<< endl;
			system("pause");
			system("cls");
			break;

		case 5:
			cout << "Задание №5" << endl << endl;

			cout << "Введите точность: ";
			cin >> eps;

			cout << "Номер первого отрицательного члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (for) " << findFirstNegativeElementFor(eps)
				<< endl;

			cout << "Номер первого отрицательного члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (while) " << findFirstNegativeElementWhile(eps)
				<< endl;

			cout << "Номер первого отрицательного члена последовательности, для которого "
				<< "выполняется условие |ai| <= eps (do...while) " << findFirstNegativeElementDowhile(eps)
				<< endl;
			system("pause");
			system("cls");
			break;
		case 6:
			sl = false;
			break;
		}
	}
}