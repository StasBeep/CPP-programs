#include <iostream>
#include <stack>
using namespace std;

// ������� �������� � �������� ��������� ��������� �� ����� �����
// � ����������� ��� �������� �� �������
void increment(int *n)
{
	*n = ++ * n;
}

// ������� ������ �� ������
void incrementStackVariable()
{
	// �������� �� ����� ������ �����
	stack <int> steck;
	int s;
	int* ps;

	cout << "������� ���������� �����: ";
	cin >> s;
	ps = &s;

	cout << "\ns = " << s << " a���� s: " << ps << endl;

	// ���������� �������� � ����
	steck.push(s);
	int* psteck = &steck.top();

	cout << "s = " << steck.top() << " a���� s: " << psteck << endl;

	increment(psteck); // ������� �� ������� �������

	cout << "s = " << steck.top() << " a���� s: " << psteck << endl;
}

// ������� ������ � ������������ �������
void incrementHeapVariable()
{
	// ��������� ������������ ������ (����� �����)
	int* p = (int*)malloc(sizeof(int));

	cout << "p = " << *p << " �����: " << p << endl;

	cout << "������� ��������: ";
	cin >> *p;

	cout << "p = " << *p << " �����: " << p << endl;

	increment(p); // ������� �� ������� �������

	cout << "p = " << *p << " �����: " << p << endl;

	// ������������ ���������� ������
	free(p);

	cout << "p = " << *p << " �����: " << p << endl;
}

// ������� ������ ������� ����� ����� �� �����
void writeArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

// ������� ����� ������� ����� ����� � ����������
void readArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "������� ������� �������: ";
		cin >> arr[i];
	}

	cout << endl;
}

// ������� ���������� �������� ������� "���������� �������"
void sort(int* arr, int length)
{
	int temp, // ��������� ���������� ��� �������� �������� �������� ������������ �������
		item; // ������ ����������� ��������

	// "���������� ���������" (������ �� ������� �������� �������)
	for (int counter = 1; counter < length; counter++)
	{
		temp = arr[counter]; // �������������� ��������� ���������� ������� ��������� �������� �������
		item = counter - 1; // ���������� ������ ����������� �������� �������

		// ���� ������ �� ����� 0 � ���������� ������� ������� ������ ��������
		while (item >= 0 && arr[item] > temp)
		{
			arr[item + 1] = arr[item];  // ������������ ��������� �������
			arr[item] = temp;
			item--;
		}
	}
}

// ������� ������ � �������� ����������
void sortStackArray(int* arr, int n)
{
	// ����� ��������� �������
	writeArray(arr, n);

	// ���������� �������
	sort(arr, n);

	cout << endl;

	// ����� �������������� �������
	writeArray(arr, n);
}

// ������� ������ � �������� ����������� �������������
void sortArrayPerson()
{
	int size;
	cout << "������� ������ �������: ";
	cin >> size;

	// �������� �������, ���������� �� size ���������
	int* arrayPer = new int[size];

	// ���� �������
	readArray(arrayPer, size);

	// ������� �������
	system("cls");

	// ����� ��������� �������
	cout << "�������� ������:" << endl;

	writeArray(arrayPer, size);

	cout << endl;

	// ���������� ��������� �������
	sort(arrayPer, size);

	// ����� �������������� �������
	cout << "������������� ������: " << endl;
	
	writeArray(arrayPer, size);

	// ������������ ������
	delete arrayPer;
}

// ��������� ������� �������
void resizeArr(int* arr, int length)
{
	int* newArr = new int[length + 1];
	for (int i = 0; i < length; i++)
	{
		*(newArr + i) == *(arr + i);
	}
	delete newArr;

}