#include <iostream>
#include <stack>
using namespace std;

// Функция получает в качестве параметра указатель на целое число
// и увеличивает его значение на еденицу
void increment(int *n)
{
	*n = ++ * n;
}

// Функция работы со стеком
void incrementStackVariable()
{
	// создание на стеке целого числа
	stack <int> steck;
	int s;
	int* ps;

	cout << "Введите переменную стека: ";
	cin >> s;
	ps = &s;

	cout << "\ns = " << s << " aдрес s: " << ps << endl;

	// добавление значения в стек
	steck.push(s);
	int* psteck = &steck.top();

	cout << "s = " << steck.top() << " aдрес s: " << psteck << endl;

	increment(psteck); // функция из первого задания

	cout << "s = " << steck.top() << " aдрес s: " << psteck << endl;
}

// Функция работы с динамической памятью
void incrementHeapVariable()
{
	// выделение динамической памяти (целое число)
	int* p = (int*)malloc(sizeof(int));

	cout << "p = " << *p << " адрес: " << p << endl;

	cout << "Введите значение: ";
	cin >> *p;

	cout << "p = " << *p << " адрес: " << p << endl;

	increment(p); // функция из первого задания

	cout << "p = " << *p << " адрес: " << p << endl;

	// освобождение выделенной памяти
	free(p);

	cout << "p = " << *p << " адрес: " << p << endl;
}

// Функция вывода массива целых чисел на экран
void writeArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

// Функция ввода массива целых чисел с клавиатуры
void readArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Введите элемент массива: ";
		cin >> arr[i];
	}

	cout << endl;
}

// Функция сортировки массивов методом "Сортировка вставки"
void sort(int* arr, int length)
{
	int temp, // временная переменная для хранения значения элемента сортируемого массива
		item; // индекс предыдущего элемента

	// "Сортировка вставками" (начало со второго элемента массива)
	for (int counter = 1; counter < length; counter++)
	{
		temp = arr[counter]; // инициализируем временную переменную текущим значением элемента массива
		item = counter - 1; // запоминаем индекс предыдущего элемента массива

		// пока индекс не равен 0 и предыдущий элемент массива больше текущего
		while (item >= 0 && arr[item] > temp)
		{
			arr[item + 1] = arr[item];  // перестановка элементов массива
			arr[item] = temp;
			item--;
		}
	}
}

// Функция работы с массивом константой
void sortStackArray(int* arr, int n)
{
	// вывод исходного массива
	writeArray(arr, n);

	// сортировка массива
	sort(arr, n);

	cout << endl;

	// вывод сортированного массива
	writeArray(arr, n);
}

// Функция работы с массивом заполняемым пользователем
void sortArrayPerson()
{
	int size;
	cout << "Введите размер массива: ";
	cin >> size;

	// создание массива, состоящего из size элементов
	int* arrayPer = new int[size];

	// ввод массива
	readArray(arrayPer, size);

	// очистка консоли
	system("cls");

	// вывод исходного массива
	cout << "Исходный массив:" << endl;

	writeArray(arrayPer, size);

	cout << endl;

	// сортировка введённого массива
	sort(arrayPer, size);

	// вывод сортированного массива
	cout << "Сортированный массив: " << endl;
	
	writeArray(arrayPer, size);

	// освобождение памяти
	delete arrayPer;
}

// Изменение размера массива
void resizeArr(int* arr, int length)
{
	int* newArr = new int[length + 1];
	for (int i = 0; i < length; i++)
	{
		*(newArr + i) == *(arr + i);
	}
	delete newArr;

}