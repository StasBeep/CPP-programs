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
		cout << "�������� ����� �������:" << endl;
		cout << "1. ������� 1" << endl;
		cout << "2. ������� 2" << endl;
		cout << "3. ������� 3" << endl;
		cout << "4. ������� 4" << endl;
		cout << "5. ������� 5" << endl;
		cout << "6. �����" << endl << endl;

		cout << "�������: ";
		cin >> r;
		system("cls");

		switch (r)
		{
		case 1:
			cout << "������� �1" << endl << endl;

			cout << "������� ���������� ��������: ";
			cin >> n;

			cout << endl << "���������� �������� ����� ���� (for): "
				<< summNfor(n) << endl;

			cout << "���������� �������� ����� ���� (while): "
				<< summNwhile(n) << endl;

			cout << "���������� �������� ����� ���� (do...while): "
				<< summNdowhile(n) << endl << endl;
			system("pause");
			system("cls");
			break;

		case 2:
			cout << "������� �2" << endl << endl;

			cout << "������� ��������: ";
			cin >> eps;

			cout << endl << "���������� �������� ����� ���� � ���������: "
				<< eps << " (for) = " << summEpsfor(eps) << endl;

			cout << "���������� �������� ����� ���� � ���������: "
				<< eps << " (while) = " << summEpswhile(eps) << endl;

			cout << "���������� �������� ����� ���� � ���������: "
				<< eps << " (do...while) = " << summEpsdowhile(eps) << endl << endl;
			system("pause");
			system("cls");
			break;

		case 3:
			cout << "������� �3" << endl << endl;

			cout << "������� n: ";
			cin >> n;
			cout << "������� k: ";
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
			cout << "������� �4" << endl << endl;

			cout << "������� ��������: ";
			cin >> eps;

			cout << "����� ������� ����� ������������������, ��� �������� "
				<< "����������� ������� |ai| <= eps (for) " << findFirstElementFor(eps)
				<< endl;

			cout << "����� ������� ����� ������������������, ��� �������� "
				<< "����������� ������� |ai| <= eps (while) " << findFirstElementWhile(eps)
				<< endl;

			cout << "����� ������� ����� ������������������, ��� �������� "
				<< "����������� ������� |ai| <= eps (do...while) " << findFirstElementDowhile(eps)
				<< endl;
			system("pause");
			system("cls");
			break;

		case 5:
			cout << "������� �5" << endl << endl;

			cout << "������� ��������: ";
			cin >> eps;

			cout << "����� ������� �������������� ����� ������������������, ��� �������� "
				<< "����������� ������� |ai| <= eps (for) " << findFirstNegativeElementFor(eps)
				<< endl;

			cout << "����� ������� �������������� ����� ������������������, ��� �������� "
				<< "����������� ������� |ai| <= eps (while) " << findFirstNegativeElementWhile(eps)
				<< endl;

			cout << "����� ������� �������������� ����� ������������������, ��� �������� "
				<< "����������� ������� |ai| <= eps (do...while) " << findFirstNegativeElementDowhile(eps)
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