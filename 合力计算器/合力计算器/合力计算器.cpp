#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
#define MAX 15
void printWelcome() {
	cout << "��ӭʹ�ú�����������" << endl;
	cout << "�������ܹ���������ķ�������������Ĵ�С��Χ��" << endl << endl;
}
double jdz(double num) {
	return (num >= 0) ? num : num * -1;
}
int main() {
	double force[MAX];
	char input = 0;
FLAG:
	printWelcome();
	cout << "����������ĸ�����";
	int num;
	cin >> num;
	if (num > MAX) {
		cout << endl << "�����ĸ������࣡" << endl << endl;
		system("pause");
		return 0;
	}
	else {
		for (int i = 0; i < num; i++) {
			cout << "�������" << i + 1 << "�������Ĵ�С��";
			cin >> force[i];
		}
		double min = force[0], max = force[0];
		for (int i = 1; i < num; i++) {
			if (force[i] >= min && force[i] <= max) {
				min = 0;
			}
			else if (force[i] < min) {
				min = jdz(force[i] - min);
			}
			else {
				min = jdz(force[i] - max);
			}
			max += force[i];
		}
		cout << endl << "��������СֵΪ" << min << "N�����ֵΪ" << max << "N." << endl << endl;
	FLAG2:
		cout << "��1���¿�ʼ���㣬��2�˳�����" << endl;
		input = _getch();
		if (input == '1') {
			system("cls");
			goto FLAG;
		}
		else if (input == '2') {
			cout << "��ӭ�´�ʹ�ã�" << endl;
			return 0;
		}
		else {
			goto FLAG2;
		}
	}
	return 0;
}