#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <chrono>
#include <thread>
#include <windows.h>
#define e endl;
using namespace std;

#pragma region �����

const string nul = "\033[0m";
const string black = "\033[30m";
const string red = "\033[31m";
const string yellow = "\033[33m";
const string green = "\033[32m";
const string blue = "\033[34m";
const string purple = "\033[35m";
const string cyan = "\033[36m";
const string white = "\033[37m";

#pragma endregion

static string name;
int money;

#pragma region ������

int music() {
	sf::SoundBuffer winBuf;
	if (!winBuf.loadFromFile("Mus1.OGG")) {
		return -1;
	}
	sf::Sound win;
	win.setBuffer(winBuf);

	sf::SoundBuffer failBuf;
	if (!failBuf.loadFromFile("Mus2.OGG")) {
		return -1;
	}
	sf::Sound fail;
	fail.setBuffer(failBuf);
	win.play();
}

int music1() {
	sf::SoundBuffer winBuf;
	if (!winBuf.loadFromFile("Mus1.OGG")) {
		return -1;
	}
	sf::Sound win;
	win.setBuffer(winBuf);

	sf::SoundBuffer failBuf;
	if (!failBuf.loadFromFile("Mus2.OGG")) {
		return -1;
	}
	sf::Sound fail;
	fail.setBuffer(failBuf);
	fail.play();
}

#pragma endregion

#pragma region �������

void c() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

#pragma endregion

#pragma region ���������

void map();

void menu();

void wakenow(int &money);

void bar(int &money,int &zakaz);

void casino(int &money);

void symbols(int dice1, int dice2);

void cubes();

void automat(int &money);

void sticks();

void calend();

void good();

void yt();

void knoword();

void pole(char mas[4][4]);

void view(char mas[4][4], bool swtch[4][4]);

void hod(char mas[4][4], bool swtch[4][4]);

void turn(int number, char mas[4][4], bool swtch[4][4]);

bool fls(bool swtch[4][4]);

void memory();

void carl();

#pragma endregion

#pragma region �������_�������

int main() {
	setlocale(LC_ALL, "ru_RU.utf8");
	setlocale(LC_ALL, "rus");
	srand(time(0));
	music();
	money = 300 + rand() % 500;
	cout << green << "\t\t\t����� ����������," << nul << yellow << " ������� �����!" << nul << "\n��� �� ���, ������, ���� ����� ������ ���������� ���� � ������ ����� � �� ���� ������ ���� ��������� ������ � ���������, ����������� ����������...\n\n";
	string chyfry[9] = { "1","2","3","4","5","6","7","8","9" };
	bool val = false;
	while (val != true) {
		cout << "���� ���: ";
		cin >> name;
		if (name.size() > 10) {
			cout << "��� ������� �������, ����� ����� �������\n";
			continue;
		}
		if (name.size() < 1) {
			cout << "��� ������� ��������, ����� ����� �������\n";
			continue;
		}
		if (name.size() < 10 && name.size() > 1) {
			for (int i = 0; i < name.size(); i++) {
				if (name == chyfry[i]) {
					cout << "� ��� ������� �����!\n";
					val = false;
				}
				else val = true;
			}
		}
	}
	cout << "����� ���, ��� �� �����, " << name << "!\n������, ��� �� ������, ����� ��� ������������� �����\n";
	cout << cyan << "\n����������� � ������������:" << nul << "\n\n������ ���� - ��� ��������� ��������� ����������� ��������� �� ����� �����, ������� �������� ������� ����������, ������� � ��������� ���������� �������, ������� ���������� ���������, �������, ��������� � ���������������, ������ ��� ����� ���� �� ��� �� � �����, ������ - ��� �� �� ����� ����� � ������ ����� �� ��� ������ ������������� � ���� ������������ ���������, ������� �� ������ ���� ����������� ���� �������� ����� �������������� ������, ��� �� ��� ��� �� ��� ���, ������� � ���������, ��� �� ������� ������ � ����, �� ������ ������, ������� ����...\n\n\n";
	int wake_up;
	while (true) {
		cout << "����� 1, ����� ����������\n";
		cin >> wake_up;
		if (wake_up!=1) {
			cout << "�������� �������! ����� ��� ���\n\n";
			continue;
		}
		else break;
	}
	if (wake_up == 1) {
		wakenow(money);
	}
}

#pragma endregion

#pragma region �������������� �������

void map() {
	cout << "\n\n����� ���������:\n\n\t\t\t\t\t |";
	for (int i = 0; i < 25; i++) {
		cout << "=";
	}
	cout << "|";
	cout << e;
	for (int i = 0; i < 5; i++) {
		cout << "\t\t\t\t\t |\t\t\t   | \n";
	}
	for (int i = 0; i < 1; i++) {
		cout << "\t\t\t\t\t |\t" << green << " ��� ������" << nul << "\t   |\n";
	}
	for (int i = 0; i < 5; i++) {
		cout << "\t\t\t\t\t |\t\t\t   |\n";
	}
	cout << "\t\t\t\t\t |";
	for (int i = 0; i < 25; i++) {
		cout << "=";
	}
	cout << "|\n\n";
	for (int i = 0; i < 5; i++) {
		cout << "\t\t\t\t\t\t        |\n";
	}
	cout << "\t\t";
	for (int i = 0; i < 37; i++) {
		cout << "=";
	}
	cout << blue << " ����� " << nul;
	for (int i = 0; i < 37; i++) {
		cout << "=";
	}
	cout << "\n";
	for (int i = 0; i < 5; i++) {
		cout << "\t\t|\t\t\t\t\t|\t\t\t\t\t|\n";
	}
	cout << "\t|";
	for (int i = 0; i < 15; i++) {
		cout << "=";
	}
	cout << "|\t\t\t|";
	for (int i = 0; i < 15; i++) {
		cout << "=";
	}
	cout << "|\t\t\t|";
	for (int i = 0; i < 15; i++) {
		cout << "=";
	}
	cout << "|\n";
	for (int i = 0; i < 4; i++) {
		cout << "\t|\t\t|\t\t\t|\t\t|\t\t\t|\t\t|\n";
	}
	for (int i = 0; i < 1; i++) {
		cout << "\t|\t" << yellow << "���" << nul << "\t| \t\t\t| " << red << "   �������" << nul << "\t| \t\t\t| " << cyan << "  ��� �����" << nul << "\t| \n";
	}
	for (int i = 0; i < 3; i++) {
		cout << "\t|\t\t|\t\t\t|\t\t|\t\t\t|\t\t|\n";
	}
	cout << "\t|";
	for (int i = 0; i < 15; i++) {
		cout << "_";
	}
	cout << "|\t\t\t|";
	for (int i = 0; i < 15; i++) {
		cout << "_";
	}
	cout << "|\t\t\t|";
	for (int i = 0; i < 15; i++) {
		cout << "_";
	}
	cout << "|\n";

}

void menu() {
	cout << red << "\t\t\t\t\t����\n\n" << nul << cyan << "�������:" << nul << e;
	cout << "|";
	for (int i = 0; i < 97; i++) {
		cout << "=";
	}
	cout << "|\n";
	for (int i = 0; i < 1; i++) {
		cout << "|\t\t" << yellow << "���" << nul << "\t\t | \t\t" << blue << "����\t" << nul << " \t| \t  " << cyan << "������������ ���\t " << nul << " |\n";
	}
	for (int i = 0; i < 1; i++) {
		cout << "|\t\t\t\t |\t\t\t\t|\t\t\t\t  |\n";
	}
	cout << "|";
	for (int i = 0; i < 97; i++) {
		cout << "-";
	}
	cout << "|\n";
	for (int i = 0; i < 1; i++) {
		cout << "|\t\t" << green << "2$" << nul << "\t\t | \t\t" << green << "5$" << nul << "\t\t| \t\t" << green << "3$" << nul << "\t\t  | \n";
	}
	cout << "|";
	for (int i = 0; i < 97; i++) {
		cout << "=";
	}
	cout << "|\n\n\n" << red << "�������:" << nul << "\n|";
	for (int i = 0; i < 97; i++) {
		cout << "=";
	}
	cout << "|\n";
	for (int i = 0; i < 1; i++) {
		cout << "|    " << yellow << "������� ��������� � �������" << nul << "        |\t" << green << "������� �����" << nul << "  \t | \t" << red << "���������� ����" << nul << "\t\t  | \n";
	}
	for (int i = 0; i < 1; i++) {
		cout << "|\t\t\t\t\t|\t\t\t |\t\t\t\t  |\n";
	}
	cout << "|";
	for (int i = 0; i < 97; i++) {
		cout << "-";
	}
	cout << "|\n";
	for (int i = 0; i < 1; i++) {
		cout << "|\t\t" << green << "50$\t\t" << nul << " \t| \t" << green << "    30$\t" << nul << "\t | \t" << green << "\t55$ " << nul << "\t\t  |\n";
	}
	cout << "|";
	for (int i = 0; i < 97; i++) {
		cout << "=";
	}
	cout << "|\n";

}

void bar(int &money, int &zakaz) {
	music1();
	int again;
	int vid_drink,coldrink=0,vid_food,colfood=0;
	int coltea = 0, colcof = 0, coljui = 0, colpot = 0, colpiz = 0, colbor = 0;
	bool ftea = false, fcof=false, fjui=false, fpot=false, fpiz=false, fbor=false;
	int tea = 2, cofee = 5, juice = 3;
	int potato = 50, pizza = 30, borsh = 55;
	int size = 0;
	int end=2, end1=2;
	int choice=0;
	string zakazaka[100];
	cout << green << "�����: " << nul << "����� - �� � � ���, ������ � ��� ����� ��� ��� - ��� ��� ��� ������ ����������, ����� ������ ��� - ������ ����������� <�\n";
	cout << "\n\n<������ ����� ����, �����>\n\n" << green << "�����:" << nul << " �� ��, ������ ����� ����� ���� �����-�� ��������, ��� �� ������ ����� ����������� ������ ��������� �������� � �������, ������ ����������� ����� �� ����� ����.\n\n";
	cout << "<������� ��������>\n\n";
	cout << yellow << "��������:" << nul << " ����� ����������! ��� ������������ � �������?\n\n";
	while (true) {
		cout << "<��������� � ����>\n\n";
		menu();
		cout << "\n��� ����� �� �������� (1-3, 0 - �������/�����): ";
		while (end!= 0) {
			while (true) {
				cin >> vid_drink;
				if (vid_drink < 0 || vid_drink>3) {
					cout << "������ �������� � ���� �� ����������!\n";
					continue;
				}
				else break;
			}
			if (vid_drink == 0 && coldrink==0) {
				zakazaka[0] = "������\n";
				end = 0;
			}
			if (vid_drink == 0) {
				end = 0;
			}
			if (vid_drink == 1 && (money - tea) > 0) {
				ftea = true;
				coldrink++;
				coltea++;
				zakazaka[1] = "���: ";
				zakazaka[2] = coltea;
				zakazaka[3] = " ����\n";
				zakaz = zakaz + tea;

			}
			if (vid_drink == 2 && (money - cofee) > 0) {
				fcof = true;
				coldrink++;
				colcof++;
				zakazaka[4] = "����: ";
				zakazaka[5] = colcof;
				zakazaka[6] = " ����\n";
				zakaz = zakaz + cofee;
			}
			if (vid_drink == 3 && (money - juice) > 0) {
				fjui = true;
				coldrink++;
				coljui++;
				zakazaka[7] = "������������ ���: ";
				zakazaka[8] = coljui;
				zakazaka[9] = " ����\n";
				zakaz = zakaz + juice;
			}
			if ((money-tea)<0 || (money-cofee)<0 || (money-juice<0)) cout << "� ��� �� ����� ��������� �������!\n";
			continue;
		}
		if (vid_drink == 0 && coldrink == 0) {
			cout << yellow << "\n\n��������:" << nul << " ����� ����, ��� �� ������� �� ��������� �����, ������ � ��� �� ���� ���������� ��������� �������, ����� ������� � ��� ����� �������� � �����!)\n\n��� ����� �� ������� (1-3, 0 - �������/�����): ";
		}
		if (vid_drink == 0 && coldrink!=0) {
			cout << yellow << "\n\n��������:" << nul << " �������� �����! ��� ������ ������� �� ����� ��������� �������?\n\n��� ����� �� ������� (1-3, 0 - �������/�����): ";
		}
		while (end1 != 1) {
			while (true) {
				cin >> vid_food;
				if (vid_food < 0 || vid_food>3) {
					cout << "������ �������� � ���� �� ����������!\n";
					continue;
				}
				else break;
			}
			if (vid_food == 0 && colfood==0) {
				zakazaka[10] = "������\n";
				end1 = 1;
			}
			if (vid_food == 0 && colfood!=0) {
				end1 = 1;
			}
			if (vid_food == 1 && (money - potato) > 0) {
				fpot = true;
				colfood++;
				colpot++;
				zakazaka[11] = "������� ��������� � �������: ";
				zakazaka[12] = colpot;
				zakazaka[13] = " ����\n";
				zakaz = zakaz + potato;

			}
			if (vid_food == 2 && (money - pizza) > 0) {
				fpiz = true;
				colfood++;
				colpiz++;
				zakazaka[14] = "�����: ";
				zakazaka[15] = colpiz;
				zakazaka[16] = " ����\n";
				zakaz = zakaz + pizza;
			}
			if (vid_food == 3 && (money - borsh) > 0) {
				fbor = true;
				colfood++;
				colbor++;
				zakazaka[17] = "����: ";
				zakazaka[18] = colbor;
				zakazaka[19] = " ����\n";
				zakaz = zakaz + borsh;
			}
			if ((money-potato)<0 || (money-pizza)<0 || (money-borsh)<0) cout << "� ��� �� ����� ��������� �������!\n";
			continue;
		}
		if ((vid_food == 0 && colfood!=0) || (vid_drink==0 && coldrink!=0)) {
			cout << yellow << "\n\n��������:" << nul << " ��������, �������� ����� 7-8 ����� �� ��� ����� ������ ����� ���� � �������� ����\n";
			cout << green << "\n�����:" << nul << " �������, ���� � ����������� �����!)\n";
			Sleep(2);
			cout << "\n\n<������ 5 �����>\n\n";
			Sleep(2);
			cout << yellow << "��������:" << nul << " ����������, ��� �����, ������� ��� �� ����� ���� ������� �����, ��� ������\n\n";
			cout << green << "�����:" << nul << " �������� �������! ��� ������ ����� ������� ����������\n\n";
		}
		if ((vid_food == 0 && colfood == 0) && (vid_drink==0 && coldrink==0)) {
			cout << yellow << "\n��������:" << nul << " �����-�� �� �������� �������...�� ������ �� ���� �� ����, ��� ���� �� �� ����� ������ ����?\n\n";
			cout << green << "\n�����:" << nul << " ������ ��������...XD\n";
			cout << yellow << "\n��������: " << nul << " ����, ������ ������ �� ����� ��� �����, ������� ��� ����������� ��� ���������� ������!\n\n1 - �� ���� �������� ���-������\n2 - �������� ������\n��� �����: ";
			while (true) {
				cin >> choice;
				if (choice < 1 || choice>2) {
					cout << "�������������� �������!\n";
					continue;
				}
				else break;
			}
		}
		if (choice == 1) {
			continue;
		}
		if (choice == 2) {
			c();
			break;
		}
		cout << yellow << "��������:" << nul << " ������� ��� ���-������?\n1 - ��������� ��� ���� �����\n2 - �������� ����\n��� �����: ";
		while (true) {
			cin >> again;
			if (again < 1 || again>2) {
				cout << "�������������� �������!\n";
				continue;
			}
			else break;
		}
		if (again == 1) {
			cout << green << "�����:" << nul << " ������� ��-���� ��� ���-������ ������\n\n";
			continue;
		}
		if (again == 2) {
			if ((vid_drink==0) && (coldrink!=0) && (ftea=true)){
				zakazaka[2] = coltea;
			}
			if ((vid_drink == 0) && (coldrink != 0) && (fcof = true)) {
				zakazaka[5] = colcof;
			}
			if ((vid_drink == 0) && (coldrink != 0) && (fjui = true)) {
				zakazaka[8] = coljui;
			}
			if ((vid_food == 0) && (colfood != 0) && (fpot = true)) {
				zakazaka[12] = colpot;
			}
			if ((vid_food == 0) && (colfood != 0) && (fpiz = true)) {
				zakazaka[15] = colpiz;
			}
			if ((vid_food == 0) && (colfood != 0) && (fbor = true)) {
				zakazaka[18] = colbor;
			}
			cout << green << "�����:" << nul << " ������� �� ���� ������ �����������, ��������� ���������� ����\n\n" << yellow << "��������:" << nul << " ������, ��� ������� ������� ��� ����\n\n";
			Sleep(1);
			c();
			cout << "\n<����� ����, ������� �� ����>";
			Sleep(1);
			cout << green << "\n\n�����:" << nul << " ������� �������!\n";
			cout << yellow << "\n��������:" << nul << " ��� �������! ��������� ��������)\n\n";
			cout << "����:\n";
			for (int i = 0; i < 30; i++) {
				cout << "=";
			}
			cout << "\n��������:\n" << cyan << "\n�������\n" << nul;
			for (int i = 0; i < 10; i++) {
				cout << zakazaka[i];
			}
			cout << red << "\n\n�������\n" << nul;
			for (int i = 10; i < 20; i++) {
				cout << zakazaka[i];
			}
			for (int i = 0; i < 30; i++) {
				cout << "=";
			}
			cout << "\n����� �����: " << green << zakaz << "$" << nul << e;
			for (int i = 0; i < 30; i++) {
				cout << "=";
			}
			cout << "\n";
		}
		Sleep(5);
		money = money - zakaz;
		cout << "\n" << green << "�����:" << nul << " �����-�� �� ���� ������� ����� ����� � �������, ����� ��� ������� ����� � �� �� ������ � ���, ������ � ������������ � ������������� ������ ����� ������������ ������!\n\n";
		cout << "<����� ��������>\n\n" << yellow << "��������:" << nul << " ����� ���, �������� � ��� ���!)\n\n";
		cout << green << "�����:" << nul << " �������! ����������� ��� ��� ������ �����!\n\n";
		break;
	}
	cout << "<������� ���>\n\n";
	return;
}

void symbols(int dice1, int dice2) {
	if (dice1) {
		if (dice1 == 1) cout << "\n-----------------\n|               |\n|               |\n|       *       |\n|               |\n|               |\n-----------------\n";
		if (dice1 == 2) cout << "\n-----------------\n|               |\n|       *       |\n|               |\n|       *       |\n|               |\n-----------------\n";
		if (dice1 == 3) cout << "\n-----------------\n|               |\n|   *           |\n|      *        |\n|         *     |\n|               |\n-----------------\n";
		if (dice1 == 4) cout << "\n-----------------\n|               |\n|    *     *    |\n|               |\n|    *     *    |\n|               |\n-----------------\n";
		if (dice1 == 5) cout << "\n-----------------\n|               |\n|    *    *     |\n|       *       |\n|    *    *     |\n|               |\n-----------------\n";
		if (dice1 == 6) cout << "\n-----------------\n|               |\n|   *     *     |\n|   *     *     |\n|   *     *     |\n|               |\n-----------------\n";
	}
	if (dice2) {
		if (dice2 == 1) cout << "\n-----------------\n|               |\n|               |\n|       *       |\n|               |\n|               |\n-----------------\n";
		if (dice2 == 2) cout << "\n-----------------\n|               |\n|       *       |\n|               |\n|       *       |\n|               |\n-----------------\n";
		if (dice2 == 3) cout << "\n-----------------\n|               |\n|   *           |\n|      *        |\n|         *     |\n|               |\n-----------------\n";
		if (dice2 == 4) cout << "\n-----------------\n|               |\n|    *     *    |\n|               |\n|    *     *    |\n|               |\n-----------------\n";
		if (dice2 == 5) cout << "\n-----------------\n|               |\n|    *    *     |\n|       *       |\n|    *    *     |\n|               |\n-----------------\n";
		if (dice2 == 6) cout << "\n-----------------\n|               |\n|   *     *     |\n|   *     *     |\n|   *     *     |\n|               |\n-----------------\n";
	}
}

void cubes(int &money) {
	int attempts = 0, attempts1=0;
	cout << "\t\t\t����-���� " << purple << "�" << cyan << "�" << purple << "�" << cyan << "�" << purple << "�" << cyan << "�" << nul << "\n\n";
	cout << yellow << "������� ����:" << nul << " ���� �������, �� ����� " << red << "�����" << nul << ", � ������� ����� �������� � ������, �� �������� ����� ����������, ���� ���� �������� � ����, � ���� ����� ���������� ������� ������ � ����� ����� ������ �����, ��� � ����������. ���������� ������ 3 �������� ������������� ������� � " << green << "70$" << nul << ", �������������� ����������� ����� ������� 3-�� ��������� ������ ������ �����. �����!\n\n";
	cout << green << "�����:" << nul << " ����������� �����, �� ���, ��������, �������?\n";
	cout << "\n" << red << "�����:" << nul << " ���������� �����! ����� �� ��������. �� ��������, ���������, ��������� �� �� ���� �� ���� ���...\n\n";
	while (true) {
		int toss = rand() % 2;
		if (toss == 0) cout << "�� ������ �������� " << green << "�����" << nul << "!\n";
		if (toss == 1) cout << "�� ������ �������� " << red << "�����" << nul << "!\n";
		int score = 0, pcscore = 0, brosok=0, points = 0;
		while (points != 10 && brosok == 1 || brosok != 1) {
			cout << "������� 1, ����� ����������: ";
			cin >> brosok;
			if (brosok != 1) {
				cout << "�������� ����!\n";
				continue;
			}
			else {
				int random = 1 + rand() % 6;
				int random1 = 1 + rand() % 6;
				if (toss == 0) {
					cout << "��� ���: ";
					int dice1, dice2;
					dice1 = random;
					dice2 = random1;
					cout << "\n�� �������: " << dice1 << " � " << dice2 << endl;
					symbols(dice1, dice2);
					score += dice1 + dice2;
					points++;
					toss = 1;
					continue;
				}
				if (toss == 1) {
					cout << "��� ������\n";
					int dice1, dice2;
					dice1 = dice2 = random;
					cout << "����� ������: " << dice1 << " � " << dice2 << endl;
					symbols(dice1, dice2);
					pcscore += dice1 + dice2;
					points++;
					toss = 0;
					continue;
				}
			}
		}
		cout << "����� ����!\n��� ����: " << score << "\n���� ������: " << pcscore << endl;
		if (score > pcscore) {
			cout << green << "�� ��������!\n" << nul;
			attempts1++;
		}
		else if (pcscore > score) {
			cout << red << "����� �������!\n" << nul;
			attempts++;
		}
		else cout << "�����!\n";
		cout << "������� ����� ����� �� ������: \n��: " << score / 10.0 << "\n�����: " << pcscore / 10.0 << endl;
		if (attempts == 3) {
			cout << "\n\n�� ��������� 3 ����! ������ " << red << "70$" << nul << "\n\n";
			money = money - 70;
			attempts = 0;
		}
		if (attempts1 == 3) {
			cout << "\n\n�� �������� 3 ����! ������� " << green << "70$" << nul << "\n\n";
			money = money + 70;
			attempts1 = 0;
		}
		int again=0;
		cout << "\n\n������� ��� ��� ��������� � �������?\n\n1 - ��\n2 - ��������� � ������ ����-���\n\n��� �����: ";
		while (true) {
			cin >> again;
			if (again < 1 || again>2) {
				cout << "�������������� �������!\n";
				continue;
			}
			else break;
		}
		if (again == 1) {
			toss = 0,score=0,pcscore=0,points=0;
			continue;
		}
		if (again == 2) {
			break;
			casino(money);
		}
	}
}

void automat(int &money) {
	int go;
	int attempts = 0;
	char symbs[5] = {'!','@','$','#','&'};
	int symb;
	char mas[3][3];
	cout << "\n\n��� ������: " << green << money << "$" << nul << "\n\n";
	cout << green << "�����:" << nul << " �� ��� ��, ���������, �������� � ���� ��� ������-������ ������� ��� ���...\n\n";
	cout << "\t\t\t����-���� " << red << "�" << green << "�" << yellow << "�" << cyan << "�" << purple << "�" << blue << "�" << red << "�" << nul << "\n\n";
	cout << cyan << "�������: " << nul << "����� �������� ������ " << yellow << "���������" << nul << " (1) ����� ������������� �������� �������� �������� ��������� �����, ���� 3 ����������� ������� ��������� ���� � ������, ����� ������������ �������, ������� " << green << "40$" << nul << ", � ����� - ���, �� ���� ������ � " << red << "40$" << nul << ".�����!\n\n";
	while (true) {
		cout << "������� 1, ����� ������: ";
		while (true) {
			cin >> go;
			if (go != 1) {
				cout << "������� ����!\n";
				continue;
			}
			else break;
		}
		if (go == 1) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					symb = 0;
					symb = rand() % 4;
					mas[i][j] = symbs[symb];
				}
			}
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					cout << mas[i][j] << " ";
				}
				cout << e;
			}
			cout << e;
			if ((mas[1][0] == mas[1][1]) && (mas[1][0] == mas[1][2]) && (mas[1][1] == mas[1][2])) {
				cout << green << "������!" << nul << "\n\n";
				cout << "������� � " << green << "40$" << nul << "\n\n";
				money = money + 40;
			}
			if ((mas[1][0] != mas[1][1]) || (mas[1][0] != mas[1][2]) || (mas[1][1] != mas[1][2])) {
				cout << red << "�������!" << nul << "\n\n";
				attempts++;
			}
		}
		if (attempts == 3) {
			cout << "�� ��������� 3 ����! ������ " << red << "40$" << nul << "\n\n";
			money = money - 40;
			attempts = 0;
		}
		int again;
		cout << "������� ����������� ��� ���?\n1 - ����������� ��� ���\n2 - ��������� � ������ ����-���\n��� �����: ";
		while (true) {
			cin >> again;
			if (again < 1 || again>2) {
				cout << "�������������� �������!\n";
				continue;
			}
			else break;
		}
		if (again == 1) {
			continue;
		}
		if (again == 2) {
			casino(money);
		}
	}
}
	
void casino(int &money) {
	music();
	int choice;
	while (true) {
		cout << "\n\n��� ������: " << green << money << "$" << nul << "\n\n���� �����������?\n\n1 - �� ���� � ���������\n2 - �� ����� � ���������� �����\n3 - �������� �������\n\n���� �������� : ";
		while (true) {
			cin >> choice;
			if (choice < 1 || choice>3) {
				cout << "�������������� �������!\n";
				continue;
			}
			else break;
		}
		if (choice == 1) {
			automat(money);
		}
		if (choice == 2) {
			cubes(money);
		}
		if (choice == 3) {
			cout << "\n\n<������� �������>\n\n";
			break;
		}
	}
	return;
}

void stks() {
	int sticks, num = 0;
	string symb = "| ";
	int restart = 1;
	c();
	cout << "\t\t\t���� " << green << "�������" << nul << cyan << "\n\n�������:" << nul << " ��� ���������� ��������� ���� ������. ����� ���� ��������� N ��� - �� �������.�� � ���� ������ �� ������� ����� 1, 2 ��� 3 �������.������� ��������� ������� - ���������.��������� ��.\n\n������� ���������� ������� : ";
	while (restart == 1 && restart != 2) {
		if (restart == 2) {
			restart = 2;
			break;
		}
		while (true) {
			cin >> sticks;
			if (sticks < 2 || sticks>25) {
				cout << "������������ ���-�� �������!\n";
				continue;
			}
			else break;
		}
		int game = sticks;
		int player, bot;
			int num = 0;
			for (int i = 0; i < sticks; i++) {
				cout << symb;
			}
			cout << endl;
			for (int j = 0; j < sticks; j++) {
				num++;
				cout << num << " ";
			}
			while (game != 1 || game != 0) {
				cout << "\n�������: " << game << "\n\n������� ������� �������: ";
				cin >> player;
				if (player > 3 || player < 1) {
					cout << "����� �������!" << endl;
					num = 0;
					for (int i = 0; i < game; i++) {
						cout << symb;
					}
					cout << endl;
					for (int j = 0; j < game; j++) {
						num++;
						cout << num << " ";
					}
				}
				else {
					game -= player;
					num = 0;
					for (int i = 0; i < game; i++) {
						cout << symb;
					}
					cout << endl;
					for (int j = 0; j < game; j++) {
						num++;
						cout << num << " ";
					}
					if (game == 1) {
						cout << green << "\n����� �������!" << nul << endl;
						cout << "������� ��� ���?\n\n1 - ��\n2 - ��������� � ������ ���\n\n��� �����: ";
						while (true) {
							cin >> restart;
							if (restart < 1 || restart>2) {
								cout << "�������������� �������!\n";
								continue;
							}
							else break;
						}
						if (restart == 1) {
							break;
						}
						if (restart == 2) {
							restart = 2;
						}
						break;
					}
					cout << "\n��� �����" << endl;
					Sleep(1);
					if (game > 3) {
						bot = 1 + rand() % 3;
					}
					else if (game == 3) {
						bot = 2;
					}
					else if (game == 2) {
						bot = 1;
					}
					cout << "���� ����: " << bot << " �������" << endl;
					game -= bot;
					num = 0;
					for (int i = 0; i < game; i++) {
						cout << symb;
					}
					cout << endl;
					for (int j = 0; j < game; j++) {
						num++;
						cout << num << " ";
					}
					if (game == 1) {
						cout << cyan << "\n������� ����" << nul << endl;
						cout << green << "\n������� �����!" << nul << endl;
						cout << "������� ��� ���?\n\n1 - ��\n2 - ��������� � ������ ���\n\n��� �����: ";
						while (true) {
							cin >> restart;
							if (restart < 1 || restart>2) {
								cout << "�������������� �������!\n";
								continue;
							}
							else break;
						}
						if (restart == 1) {
							break;
						}
						if (restart == 2) {
							c();
							restart = 2;
						}
						break;
					}
				}
				if (game <= 0) {
					cout << "������!" << endl;
					break;
				}
			}
		}
	carl();
}

void calend(string let) {
	auto startPlayer = chrono::steady_clock::now();
	int letrs = 0;
	cout << "�� ������������ ��������� ����� ���������� �������� (�� ����������, � ������� �����!)\n";
	string cword = " Calendar";
	string secret[8] = { "*","*","*","*","*","*","*","*" };
	for (int i = 0; i <= 7; i++) {
		cout << secret[i];
	}
	while (true) {
		int tek;
		let = " ";
		if (letrs == 8) {
			auto endPlayer = chrono::steady_clock::now();
			chrono::duration<double> elapsedPlayer = endPlayer - startPlayer;
			double timePlayer = elapsedPlayer.count();
			cout << "\n\n����������! �� ������� �����: ";
			for (int i = 0; i <= 7; i++) {
				cout << secret[i];
			}
			cout << "\n\n������ ��� � ���: " << timePlayer << " ���.\n";
			break;
		}
		cout << "\n���������� ����� (����.!): ";
		for (int i = 0; i <= 1; i++) {
			cin >> let;
			if (cword.find(let)) {
				i += 1;
			}
			else {
				cout << "����� ����� ����������� � �����!\n���������� ����� (����.!): ";
				i--;
				continue;
			}
		}
		if (let == "C") {
			if (secret[0] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[0] != let) {
				secret[0] = let;
				letrs++;
			}
			for (int i = 0; i <= 7; i++) {
				cout << secret[i];
			}
		}
		if (let == "a") {
			if (secret[6] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[1] == let && secret[6] != let) {
				letrs++;
				secret[6] = let;
			}
			if (secret[1] != let) {
				secret[1] = let;
				letrs++;
			}
			for (int i = 0; i <= 7; i++) {
				cout << secret[i];
			}
		}
		if (let == "l") {
			if (secret[2] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[2] != let) {
				secret[2] = let;
				letrs++;
			}
			for (int i = 0; i <= 7; i++) {
				cout << secret[i];
			}
		}
		if (let == "e") {
			if (secret[3] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[3] != let) {
				secret[3] = let;
				letrs++;
			}
			for (int i = 0; i <= 7; i++) {
				cout << secret[i];
			}
		}
		if (let == "n") {
			if (secret[4] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[4] != let) {
				secret[4] = let;
				letrs++;
			}
			for (int i = 0; i <= 7; i++) {
				cout << secret[i];
			}
		}
		if (let == "d") {
			if (secret[5] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[5] != let) {
				secret[5] = let;
				letrs++;
			}
			for (int i = 0; i <= 7; i++) {
				cout << secret[i];
			}
		}
		if (let == "r") {
			if (secret[7] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[7] != let) {
				secret[7] = let;
				letrs++;
			}
			for (int i = 0; i <= 7; i++) {
				cout << secret[i];
			}
		}
	}
}

void good(string let) {
	auto startPlayer = chrono::steady_clock::now();
	int letrs = 0;
	cout << "����� ���, � �� 12 ����, � ������ ������ �� 4 ����, � ������� �� 7 ��������� (�� ����������, � ������� �����!)\n";
	string cword = " Year";
	string secret[4] = { "*","*","*","*" };
	for (int i = 0; i <= 3; i++) {
		cout << secret[i];
	}
	while (true) {
		int tek;
		let = " ";
		if (letrs == 4) {
			auto endPlayer = chrono::steady_clock::now();
			chrono::duration<double> elapsedPlayer = endPlayer - startPlayer;
			double timePlayer = elapsedPlayer.count();
			cout << "\n\n����������! �� ������� �����: ";
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
			cout << "\n\n������ ��� � ���: " << timePlayer << " ���.\n";
			break;
		}
		cout << "\n���������� ����� (����.!): ";
		for (int i = 0; i <= 1; i++) {
			cin >> let;
			if (cword.find(let)) {
				i += 1;
			}
			else {
				cout << "����� ����� ����������� � �����!\n���������� ����� (����.!): ";
				i--;
				continue;
			}
		}
		if (let == "Y") {
			if (secret[0] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[0] != let) {
				secret[0] = let;
				letrs++;
			}
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
		}
		if (let == "e") {
			if (secret[1] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[1] != let) {
				secret[1] = let;
				letrs++;
			}
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
		}
		if (let == "a") {
			if (secret[2] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[2] != let) {
				secret[2] = let;
				letrs++;
			}
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
		}
		if (let == "r") {
			if (secret[3] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[3] != let) {
				secret[3] = let;
				letrs++;
			}
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
		}
	}
}

void yt(string let) {
	auto startPlayer = chrono::steady_clock::now();
	int letrs = 0;
	cout << "�� ���� �������� ����� ������� �� �����, �� �����, � �� ��� ������ ����� (�� ����������, � ������� �����!)\n";
	string cword = " Iron";
	string secret[4] = { "*","*","*","*" };
	for (int i = 0; i <= 3; i++) {
		cout << secret[i];
	}
	while (true) {
		int tek;
		let = " ";
		if (letrs == 4) {
			auto endPlayer = chrono::steady_clock::now();
			chrono::duration<double> elapsedPlayer = endPlayer - startPlayer;
			double timePlayer = elapsedPlayer.count();
			cout << "\n\n����������! �� ������� �����: ";
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
			cout << "\n\n������ ��� � ���: " << timePlayer << " ���.\n";
			break;
		}
		cout << "\n���������� ����� (����.!): ";
		for (int i = 0; i <= 1; i++) {
			cin >> let;
			if (cword.find(let)) {
				i += 1;
			}
			else {
				cout << "����� ����� ����������� � �����!\n���������� ����� (����.!): ";
				i--;
				continue;
			}
		}
		if (let == "I") {
			if (secret[0] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[0] != let) {
				secret[0] = let;
				letrs++;
			}
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
		}
		if (let == "r") {
			if (secret[1] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[1] != let) {
				secret[1] = let;
				letrs++;
			}
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
		}
		if (let == "o") {
			if (secret[2] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[2] != let) {
				secret[2] = let;
				letrs++;
			}
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
		}
		if (let == "n") {
			if (secret[3] == let) {
				cout << "������ ����� ��� ���������!\n";
				tek = letrs;
			}
			if (secret[3] != let) {
				secret[3] = let;
				letrs++;
			}
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
		}
	}
}

void knoword() {
	int start;
	string let;
	c();
	cout << "���� " << yellow << "������ �����" << nul << "\n\n";
	while (true) {
		cout << "������ ������?\n1 - ��\n2 - ���\n��� �����: ";
		while (true) {
			cin >> start;
			if (start < 1 || start>2) {
				cout << "�������������� �������!\n";
				continue;
			}
			else break;
		}
		if (start == 1) {
			int num = 0;
			cout << "�������� ����� �������:\n1 - ������\n2 - ������\n3 - ������\n4 - ��������\n��� �����: ";
			while (true) {
				cin >> num;
				if (num < 1 || num>4) {
					cout << "�������������� �������!\n";
					continue;
				}
				else break;
			}
			cout << blue << "\t\t\t�������� �������\n\t\t\t" << nul;
			string symb = "^";
			for (int i = 0; i < 16; i++) {
				cout << symb;
			}
			cout << "\n\n";
			if (num == 4) {
				num = 1 + rand() % 3;
			}
			if (num == 1) {
				string let = " ";
				calend(let);
			}
			if (num == 2) {
				string let = " ";
				good(let);
			}
			if (num == 3) {
				string let = " ";
				yt(let);
			}
		}
		if (start == 2) {
			cout << "� ������ ��(\n";
		}
		int again = 0;
		cout << "������� ��� ���?\n1 - ��\n2 - ���\n��� �����: ";
		while (true) {
			cin >> again;
			if (again < 1 || again>2) {
				cout << "�������������� �������!\n";
				continue;
			}
			else break;
		}
		if (again == 1) {
			c();
			continue;
		}
		if (again == 2) {
			carl();
		}
	}
	return;
}

void pole(char mas[4][4]) {
	char symb[] = "##**@@++$$&&%%==";
	random_shuffle(symb, symb + 16);
	int h = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			mas[i][j] = symb[h];
			/*cout << mas[i][j] << " ";*/
			h++;
		}
		cout << e;
	}
	cout << e;
}

void view(char mas[4][4], bool swtch[4][4]) {
	cout << "�������:\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (swtch[i][j] == true) {
				cout << red << "X " << nul;
			}
			else {
				cout << mas[i][j] << " ";
			}
		}
		cout << e;
	}
	cout << e;
}

void hod(char mas[4][4], bool swtch[4][4]) {
	int el1, el2, el3, el4;
	cout << "������� ���������� ������� ������� (������, �������): " << e;
		cin >> el1 >> el2;
		cout << "������� ���������� ������� ������� (������, �������): " << e;
		cin >> el3 >> el4;
	if (mas[el1 - 1][el2 - 1] == mas[el3 - 1][el4 - 1]) {
		cout << "������ �������!\n";
		swtch[el1 - 1][el2 - 1] = true;
		swtch[el3 - 1][el4 - 1] = true;
	}
	else {
		cout << "������� ���������� ����������� �� �������!\n";
	}
}

void turn(int number, char mas[4][4], bool swtch[4][4]) {
	view(mas, swtch);
	hod(mas, swtch);
	number++;
}

bool fls(bool swtch[4][4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (swtch[i][j] == false) {
				return true;
			}
		}
	}
	return false;
}

void memory() {
	int start;
	bool swtch[4][4] = { false };
	int number = 1;
	int help = 3;
	int str1, stlb1;
	char mas[4][4];
	c();
	cout << green << "\t\t������" << cyan << "\n���� ����" << yellow << ": ����� ���� ���������� ��������, �� ��� ����� �������� �����\n������� 3 ���������, ������������ ������� ����� �������� �� <u>" << nul;
	while (true) {
		help = 3;
		number = 1;
		cout << "\n�� ������ ������ ? (1 - ��, 2 - ���)\n��� ����� : ";
		while (true) {
			cin >> start;
			if (start < 1 || start>2) {
				cout << "�������������� �������!\n";
				continue;
			}
			else break;
		}
		if (start == 2) {
			c();
			carl();
		}
		else {
			pole(mas);
			view(mas, swtch);
		}
		while (fls) {
			int choice;
			cout << "1)��������� (�������� " << help << ")\n2)������� ���\n��� ����� : ";
			cin >> choice;
			if (choice == 1) {
				if (help > 0) {
					cout << "������� ������ � ������� ������� �������: " << e;
					cin >> str1 >> stlb1;
					cout << "���� ������ ����� �� �������� ���� ������:   " << mas[str1 - 1][stlb1 - 1] << endl;
					help--;
				}
				else {
					cout << "��������� �����������!\n";
				}
			}
			else {
				if (choice == 2) {
					turn(number, mas, swtch);
				}
				else {
					cout << "������!\n";
				}
			}
		}
		cout << "�� ������ ���� �� " << number << " �����\n";
		int again;
		cout << "������� ��� ���?\n\n1 - ��\n2 - ���\n\n��� �����: ";
		while (true) {
			cin >> again;
			if (again < 1 || again>2) {
				cout << "�������������� �������!\n";
				continue;
			}
			else break;
		}
		if (again == 1) {
			continue;
		}
		else {
			c();
			carl();
		}
	}
}

void carl() {
	music1();
	int game;
	c();
	cout << cyan << "����:" << nul << " ������� �� ���-������?\n\n";
	cout << green << "�����:" << nul << " �������� ����, ������ �� ���? � ����, � ���� �� ��� ������ ����������� ����� ���������!\n";
	cout << cyan << "����:" << nul << " ��, ���� ��������� ���������� ���������, �������� <�������>, <������ �����> ��� �� <������>, ����� - ���� ������ �������� ? \n\n";
	cout << "��� �����, ��������� ���������� ������������ ����� (1-3, 4 - �� �� ���): ";
	while (true) {
		cin >> game;
		if (game < 1 || game>4) {
			cout << "�������������� �������!\n";
			continue;
		}
		else break;
	}
	if (game == 1) {
		c();
		stks();
	}
	if (game == 2) {
		c();
		knoword();
	}
	if (game == 3) {
		c();
		memory();
	}
	if (game == 4) {
		c();
		cout << green << "�����:" << nul << " ���-�� � ���������, � � ���� ���� ����� �����, � ���� ������� ����. ����!\n\n";
		cout << cyan << "����:" << nul << " �� ��� ������, �� �������(\n\n";
		cout << "<Strange ending...>\n\n";
	}
}

#pragma endregion

#pragma region �������_��������������_�������

void wakenow(int &money) {
	music();
	int locals = 0;
	cout << green << "�����:" << nul << " ����� ������������� ����, ����� ����� ������, ��� - �� ���� ������ ���...";
	cout << white << "\n\n<��������� �� ����, ������� ������ ������� 8 ����>\n\n" << nul << "��... ������ �� ��� ��� ���� 8 ����� ����, �������� ��� ����, ����� ����� ���������� �� ������...";
	Sleep(5);
	cout << white << "\n������ 5 �����, ����� ��� ��� � ����� ������ ������ �� ����� ������ ���������� ����..." << nul;
	cout << "�� ��, ��� ��� ��������� �������� ������ �� �������� ������ ������, �� ����� � ���� ���� � ����� ������ " << green << money << "$" << nul << "\n���� �� ��� ������� �����������, ����� ���� � ��� ���������� ���...\n";
	Sleep(3);
	cout << "� ����� � �������, ��� ������ ���������� ��� - �� ����������, ���� � ��� ��� ����� ���...\n";
	Sleep(3);
	cout << "�� ����� ���� � � �����, ��� � ���� � ������ �������, � ��������� � ����� ������� ������� ���� ����� �� ����������...";
	Sleep(5);
	while (true) {
		if (locals == 3) {
			c();
			break;
		}
		map();
		int pohod;
		cout << "\n\n��� ������: " << green << money << "$" << nul;
		cout << "\n\n���� ������������ (����������� ���������� ������������ �� �����, ������� ���������� �������������!)\n1 - �����\n2 - ����\n3 - ������\n��� �����: ";
		while (true) {
			cin >> pohod;
			if (pohod < 1 || pohod>3) {
				cout << "������� ����������� �� ����������!\n";
				continue;
			}
			else break;
		}
		if (pohod == 1) {
			c();
			int zakaz = 0;
			bar(money,zakaz);
			locals++;
			continue;
		}
		if (pohod == 2) {
			c();
			cout << "\n\n<������ ����� �������, �����>\n\n";
			cout << green << "�����:" << nul << " �� ��! ��������� � ����� �� ���, ��������� ����� ���� ������, ����� ����� �������� ���� �����!)\n\n";
			casino(money);
			locals++;
			continue;
		}
		if (pohod == 3) {
			c();
			cout << "\n\n<�������� � �����, ������ ����>\n\n";
			cout << cyan << "����:" << nul << " �! ������, ��� ���� ����, ����� ��� ��� �� �����!\n\n";
			cout << green << "�����:" << nul << " ���������� �������! ���� ��� �������, ���� ����� ��� ���� ������, ��� ����� � ���� �����, �� ���� ��������� ��� �� ��������...\n\n";
			carl();
			locals++;
			continue;
		}
	}
	while (true) {
		music();
		map();
		int pohod;
		cout << "\n\n��� ������: " << green << money << "$" << nul;
		cout << "\n\n���� ������������ (����������� ���������� ������������ �� �����, ������� ���������� �������������!)\n1 - �����\n2 - ����\n3 - ������\n" << green << "4 - ��������� �����\n\n" << nul << "��� ����� : ";
		while (true) {
			cin >> pohod;
			if (pohod < 1 || pohod>4) {
				cout << "������� ����������� �� ����������!\n";
				continue;
			}
			else break;
		}
		if (pohod == 1) {
			c();
			int zakaz = 0;
			bar(money, zakaz);
			continue;
		}
		if (pohod == 2) {
			c();
			cout << "\n\n<������ ����� �������, �����>\n\n";
			cout << green << "�����:" << nul << " �� ��! ��������� � ����� �� ���, ��������� ����� ���� ������, ����� ����� �������� ���� �����!)\n\n";
			casino(money);
			continue;
		}
		if (pohod == 3) {
			c();
			cout << "\n\n<�������� � �����, ������ ����>\n\n";
			cout << cyan << "����:" << nul << " �! ������, ��� ���� ����, ����� ��� ��� �� �����!\n\n";
			cout << green << "�����:" << nul << " ���������� �������! ���� ��� �������, ���� ����� ��� ���� ������, ��� ����� � ���� �����, �� ���� ��������� ��� �� ��������...\n\n";
			carl();
			continue;
		}
		if (pohod == 4) {
			c();
			cout << green << "�����:" << nul << " �� �����, ����� � ���� �� ������� ������ �������, ��� ��� ��� � ��������, ���� ������������ �����.";
			Sleep(1);
			cout << green << "�����:" << nul << " ������� ���� ������� �� ����, " << name << "! �� ����� ������, ����� ����!\n\n";
			Sleep(1);
			cout << yellow << "��������:" << nul << " ������� �� ���� " << name << "! � �� ������� ���������;)\n\n";
			Sleep(1);
			cout << cyan << "����:" << nul << " ������� �� ���� " << name << "! ������ �������� �����!\n\n";
			Sleep(1);
			cout << red << "�����:" << nul << " ������� �� ���� " << name << "! � � ������ � ���� �� ����� ����-�� ���, �� ������, ���������...)";
			Sleep(2);
			cout << "<�� ������>\n\n" << "�� ���� ����� ����� �����, ������� ����, " << name << " �� ����!\n\n";
			Sleep(1);
			cout << "<����� ���� ������ ������������, ��� ������� ������� ����>\n\n" << green << "\t\t\t\t\t�����\n" << nul;
			break;
		}
	}
}

#pragma endregion