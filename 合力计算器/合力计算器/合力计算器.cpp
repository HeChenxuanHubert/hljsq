#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
#define MAX 15
void printWelcome() {
	cout << "欢迎使用合力计算器！" << endl;
	cout << "本程序能够根据输入的分力计算出合力的大小范围。" << endl << endl;
}
double jdz(double num) {
	return (num >= 0) ? num : num * -1;
}
int main() {
	double force[MAX];
	char input = 0;
FLAG:
	printWelcome();
	cout << "请输入分力的个数：";
	int num;
	cin >> num;
	if (num > MAX) {
		cout << endl << "分力的个数过多！" << endl << endl;
		system("pause");
		return 0;
	}
	else {
		for (int i = 0; i < num; i++) {
			cout << "请输入第" << i + 1 << "个分力的大小：";
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
		cout << endl << "合力的最小值为" << min << "N，最大值为" << max << "N." << endl << endl;
	FLAG2:
		cout << "按1重新开始计算，按2退出程序。" << endl;
		input = _getch();
		if (input == '1') {
			system("cls");
			goto FLAG;
		}
		else if (input == '2') {
			cout << "欢迎下次使用！" << endl;
			return 0;
		}
		else {
			goto FLAG2;
		}
	}
	return 0;
}