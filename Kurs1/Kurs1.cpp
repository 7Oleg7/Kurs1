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

#pragma region Цвета

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

#pragma region Музыка

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

#pragma region Очистка

void c() {
	#ifdef _WIN32
		system("cls");
	#else
		system("clear");
	#endif
}

#pragma endregion

#pragma region Прототипы

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

#pragma region Главная_функция

int main() {
	setlocale(LC_ALL, "ru_RU.utf8");
	setlocale(LC_ALL, "rus");
	srand(time(0));
	music();
	money = 300 + rand() % 500;
	cout << green << "\t\t\tДОБРО ПОЖАЛОВАТЬ," << nul << yellow << " ДОРОГОЙ ИГРОК!" << nul << "\nЧто бы мне, автору, было более удобно ознакомить тебя с данной игрой и по ходу давать тебе различные советы и подсказки, представься пожалуйста...\n\n";
	string chyfry[9] = { "1","2","3","4","5","6","7","8","9" };
	bool val = false;
	while (val != true) {
		cout << "Ваше имя: ";
		cin >> name;
		if (name.size() > 10) {
			cout << "Имя слишком длинное, можно более простое\n";
			continue;
		}
		if (name.size() < 1) {
			cout << "Имя слишком короткое, введи более длинное\n";
			continue;
		}
		if (name.size() < 10 && name.size() > 1) {
			for (int i = 0; i < name.size(); i++) {
				if (name == chyfry[i]) {
					cout << "В имя введены цифры!\n";
					val = false;
				}
				else val = true;
			}
		}
	}
	cout << "Очень рад, что ты зашёл, " << name << "!\nКратко, или не совсем, скажу своё вступительное слово\n";
	cout << cyan << "\nПредистория и ознакомление:" << nul << "\n\nДанная игра - это небольшое жизненное путешествие персонажа по имени Джонн, который является простым подростком, живущем в небольшой английской деревне, кишащим различными секретами, тайнами, интригами и неожиданностями, однако сам Джонн тоже не так уж и прост, потому - что за всё время жизни в данном месте он уже вполне приспособился к этим каждодневным сюрпризам, поэтому он каждый день просыпается даже наоборот полон нетерпеливости узнать, что же его ждёт на сей раз, давайте и посмотрим, что же ожидает Джонна в этот, на первый взгляд, обычный день...\n\n\n";
	int wake_up;
	while (true) {
		cout << "Нажми 1, чтобы проснуться\n";
		cin >> wake_up;
		if (wake_up!=1) {
			cout << "Неверный вариант! Введи ещё раз\n\n";
			continue;
		}
		else break;
	}
	if (wake_up == 1) {
		wakenow(money);
	}
}

#pragma endregion

#pragma region Второстепенные функции

void map() {
	cout << "\n\nКарта местности:\n\n\t\t\t\t\t |";
	for (int i = 0; i < 25; i++) {
		cout << "=";
	}
	cout << "|";
	cout << e;
	for (int i = 0; i < 5; i++) {
		cout << "\t\t\t\t\t |\t\t\t   | \n";
	}
	for (int i = 0; i < 1; i++) {
		cout << "\t\t\t\t\t |\t" << green << " ДОМ ДЖОННА" << nul << "\t   |\n";
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
	cout << blue << " ДЖОНН " << nul;
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
		cout << "\t|\t" << yellow << "БАР" << nul << "\t| \t\t\t| " << red << "   ИГРОВАЯ" << nul << "\t| \t\t\t| " << cyan << "  ДОМ КАРЛА" << nul << "\t| \n";
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
	cout << red << "\t\t\t\t\tМЕНЮ\n\n" << nul << cyan << "НАПИТКИ:" << nul << e;
	cout << "|";
	for (int i = 0; i < 97; i++) {
		cout << "=";
	}
	cout << "|\n";
	for (int i = 0; i < 1; i++) {
		cout << "|\t\t" << yellow << "ЧАЙ" << nul << "\t\t | \t\t" << blue << "КОФЕ\t" << nul << " \t| \t  " << cyan << "АПЕЛЬСИНОВЫЙ СОК\t " << nul << " |\n";
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
	cout << "|\n\n\n" << red << "ЗАКУСКИ:" << nul << "\n|";
	for (int i = 0; i < 97; i++) {
		cout << "=";
	}
	cout << "|\n";
	for (int i = 0; i < 1; i++) {
		cout << "|    " << yellow << "ЖАРЕНЫЙ КАРТОФЕЛЬ С ГРИБАМИ" << nul << "        |\t" << green << "СРЕДНЯЯ ПИЦЦА" << nul << "  \t | \t" << red << "УКРАИНСКИЙ БОРЩ" << nul << "\t\t  | \n";
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
	cout << green << "Джонн: " << nul << "схожу - ка я в бар, обычно в это время там как - раз все мои друзья собираются, может закажу что - нибудь вкусненькое <З\n";
	cout << "\n\n<Открыл дверь бара, зашёл>\n\n" << green << "Джонн:" << nul << " да уж, видимо вчера здесь было какое-то застолье, раз на полках стало значительно меньше различных напитков и закусок, однако определённый выбор всё равно есть.\n\n";
	cout << "<Подошёл официант>\n\n";
	cout << yellow << "Официант:" << nul << " добро пожаловать! Уже определились с заказом?\n\n";
	while (true) {
		cout << "<Посмотрел в меню>\n\n";
		menu();
		cout << "\nВаш выбор из напитков (1-3, 0 - пропуск/далее): ";
		while (end!= 0) {
			while (true) {
				cin >> vid_drink;
				if (vid_drink < 0 || vid_drink>3) {
					cout << "Такого варианта в меню не существует!\n";
					continue;
				}
				else break;
			}
			if (vid_drink == 0 && coldrink==0) {
				zakazaka[0] = "ОТМЕНА\n";
				end = 0;
			}
			if (vid_drink == 0) {
				end = 0;
			}
			if (vid_drink == 1 && (money - tea) > 0) {
				ftea = true;
				coldrink++;
				coltea++;
				zakazaka[1] = "Чай: ";
				zakazaka[2] = coltea;
				zakazaka[3] = " штук\n";
				zakaz = zakaz + tea;

			}
			if (vid_drink == 2 && (money - cofee) > 0) {
				fcof = true;
				coldrink++;
				colcof++;
				zakazaka[4] = "Кофе: ";
				zakazaka[5] = colcof;
				zakazaka[6] = " штук\n";
				zakaz = zakaz + cofee;
			}
			if (vid_drink == 3 && (money - juice) > 0) {
				fjui = true;
				coldrink++;
				coljui++;
				zakazaka[7] = "Апельсиновый сок: ";
				zakazaka[8] = coljui;
				zakazaka[9] = " штук\n";
				zakaz = zakaz + juice;
			}
			if ((money-tea)<0 || (money-cofee)<0 || (money-juice<0)) cout << "У вас на счету нехватает средств!\n";
			continue;
		}
		if (vid_drink == 0 && coldrink == 0) {
			cout << yellow << "\n\nОфициант:" << nul << " очень жаль, что вы сегодня не испытуете жажду, однако у нас же есть прекрасные фирменные закуски, после которых у вас точно появится и жажда!)\n\nВаш выбор из закусок (1-3, 0 - пропуск/далее): ";
		}
		if (vid_drink == 0 && coldrink!=0) {
			cout << yellow << "\n\nОфициант:" << nul << " отличный выбор! Что нибудь желаете из наших фирменных закусок?\n\nВаш выбор из закусок (1-3, 0 - пропуск/далее): ";
		}
		while (end1 != 1) {
			while (true) {
				cin >> vid_food;
				if (vid_food < 0 || vid_food>3) {
					cout << "Такого варианта в меню не существует!\n";
					continue;
				}
				else break;
			}
			if (vid_food == 0 && colfood==0) {
				zakazaka[10] = "ОТМЕНА\n";
				end1 = 1;
			}
			if (vid_food == 0 && colfood!=0) {
				end1 = 1;
			}
			if (vid_food == 1 && (money - potato) > 0) {
				fpot = true;
				colfood++;
				colpot++;
				zakazaka[11] = "Жареный картофель с грибами: ";
				zakazaka[12] = colpot;
				zakazaka[13] = " штук\n";
				zakaz = zakaz + potato;

			}
			if (vid_food == 2 && (money - pizza) > 0) {
				fpiz = true;
				colfood++;
				colpiz++;
				zakazaka[14] = "Пицца: ";
				zakazaka[15] = colpiz;
				zakazaka[16] = " штук\n";
				zakaz = zakaz + pizza;
			}
			if (vid_food == 3 && (money - borsh) > 0) {
				fbor = true;
				colfood++;
				colbor++;
				zakazaka[17] = "Борщ: ";
				zakazaka[18] = colbor;
				zakazaka[19] = " штук\n";
				zakaz = zakaz + borsh;
			}
			if ((money-potato)<0 || (money-pizza)<0 || (money-borsh)<0) cout << "У вас на счету нехватает средств!\n";
			continue;
		}
		if ((vid_food == 0 && colfood!=0) || (vid_drink==0 && coldrink!=0)) {
			cout << yellow << "\n\nОфициант:" << nul << " ожидайте, примерно через 7-8 минут всё уже будет стоять перед вами и радовать глаз\n";
			cout << green << "\nДжонн:" << nul << " отлично, буду с нетерпением ждать!)\n";
			Sleep(2);
			cout << "\n\n<Прошло 5 минут>\n\n";
			Sleep(2);
			cout << yellow << "Официант:" << nul << " пожалуйста, ваш заказ, сегодня вам на удачу даже быстрее вышло, чем обычно\n\n";
			cout << green << "Джонн:" << nul << " огромное спасибо! Сам удивлён столь быстрой готовности\n\n";
		}
		if ((vid_food == 0 && colfood == 0) && (vid_drink==0 && coldrink==0)) {
			cout << yellow << "\nОфициант:" << nul << " какой-то вы странный сегодня...Не хотите не есть не пить, для чего же вы тогда пришли сюда?\n\n";
			cout << green << "\nДжонн:" << nul << " просто посидеть...XD\n";
			cout << yellow << "\nОфициант: " << nul << " ясно, вообще сейчас не время для шуток, поэтому или заказывайте или УБИРАЙТЕСЬ ОТСЮДА!\n\n1 - Всё таки заказать что-нибудь\n2 - Убраться отсюда\nВаш выбор: ";
			while (true) {
				cin >> choice;
				if (choice < 1 || choice>2) {
					cout << "Несуществующий вариант!\n";
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
		cout << yellow << "Официант:" << nul << " желаете ещё что-нибудь?\n1 - совершить ещё один заказ\n2 - принести счёт\nВаш выбор: ";
		while (true) {
			cin >> again;
			if (again < 1 || again>2) {
				cout << "Несуществующий вариант!\n";
				continue;
			}
			else break;
		}
		if (again == 1) {
			cout << green << "Джонн:" << nul << " пожалуй всё-таки ещё что-нибудь закажу\n\n";
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
			cout << green << "Джонн:" << nul << " пожалуй на этом заказе остановлюсь, принисите пожалуйста счёт\n\n" << yellow << "Официант:" << nul << " хорошо, сию секунду принесу вам счёт\n\n";
			Sleep(1);
			c();
			cout << "\n<Принёс счёт, положил на стол>";
			Sleep(1);
			cout << green << "\n\nДжонн:" << nul << " спасибо большое!\n";
			cout << yellow << "\nОфициант:" << nul << " вам спасибо! Приятного аппетита)\n\n";
			cout << "Счёт:\n";
			for (int i = 0; i < 30; i++) {
				cout << "=";
			}
			cout << "\nЗаказано:\n" << cyan << "\nНАПИТКИ\n" << nul;
			for (int i = 0; i < 10; i++) {
				cout << zakazaka[i];
			}
			cout << red << "\n\nЗАКУСКИ\n" << nul;
			for (int i = 10; i < 20; i++) {
				cout << zakazaka[i];
			}
			for (int i = 0; i < 30; i++) {
				cout << "=";
			}
			cout << "\nОбщая сумма: " << green << zakaz << "$" << nul << e;
			for (int i = 0; i < 30; i++) {
				cout << "=";
			}
			cout << "\n";
		}
		Sleep(5);
		money = money - zakaz;
		cout << "\n" << green << "Джонн:" << nul << " какие-же всё таки вкусные здесь блюда и напитки, тепер мой желудок полон и он не думает о еде, теперь с уверенностью и восполненными силами можно отправляться дальше!\n\n";
		cout << "<Вслед слышится>\n\n" << yellow << "Официант:" << nul << " удачи вам, заходите к нам ещё!)\n\n";
		cout << green << "Джонн:" << nul << " спасибо! Обязательно ещё как нибудь зайду!\n\n";
		break;
	}
	cout << "<Покинул бар>\n\n";
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
	cout << "\t\t\tМИНИ-ИГРА " << purple << "К" << cyan << "У" << purple << "Б" << cyan << "И" << purple << "К" << cyan << "И" << nul << "\n\n";
	cout << yellow << "Правила игры:" << nul << " есть человек, по имени " << red << "Фрэнк" << nul << ", с которым можно поиграть в кубики, он является твоим оппонентом, твоя цель выиграть у него, у кого после нескольких бросков кубика в сумме будет больше очков, тот и победитель. Победителю каждые 3 выигрыша присваивается награда в " << green << "70$" << nul << ", соответственно проигравший после каждого 3-го проигрыша теряет данную сумму. Удачи!\n\n";
	cout << green << "Джонн:" << nul << " приветствую Фрэнк, ну что, приятель, сыграем?\n";
	cout << "\n" << red << "Фрэнк:" << nul << " здравствуй Джонн! Давно не виделись. Не откажусь, посмотрим, обыграешь ли ты меня на этот раз...\n\n";
	while (true) {
		int toss = rand() % 2;
		if (toss == 0) cout << "По жребию начинает " << green << "Джонн" << nul << "!\n";
		if (toss == 1) cout << "По жребию начинает " << red << "Фрэнк" << nul << "!\n";
		int score = 0, pcscore = 0, brosok=0, points = 0;
		while (points != 10 && brosok == 1 || brosok != 1) {
			cout << "Нажмите 1, чтобы продолжить: ";
			cin >> brosok;
			if (brosok != 1) {
				cout << "Неверный ввод!\n";
				continue;
			}
			else {
				int random = 1 + rand() % 6;
				int random1 = 1 + rand() % 6;
				if (toss == 0) {
					cout << "Ваш ход: ";
					int dice1, dice2;
					dice1 = random;
					dice2 = random1;
					cout << "\nВы бросили: " << dice1 << " и " << dice2 << endl;
					symbols(dice1, dice2);
					score += dice1 + dice2;
					points++;
					toss = 1;
					continue;
				}
				if (toss == 1) {
					cout << "Ход Фрэнка\n";
					int dice1, dice2;
					dice1 = dice2 = random;
					cout << "Фрэнк бросил: " << dice1 << " и " << dice2 << endl;
					symbols(dice1, dice2);
					pcscore += dice1 + dice2;
					points++;
					toss = 0;
					continue;
				}
			}
		}
		cout << "Конец игры!\nВаш счёт: " << score << "\nСчёт Фрэнка: " << pcscore << endl;
		if (score > pcscore) {
			cout << green << "ВЫ ВЫИГРАЛИ!\n" << nul;
			attempts1++;
		}
		else if (pcscore > score) {
			cout << red << "Фрэнк выиграл!\n" << nul;
			attempts++;
		}
		else cout << "Ничья!\n";
		cout << "Средняя сумма очков за бросок: \nВы: " << score / 10.0 << "\nФрэнк: " << pcscore / 10.0 << endl;
		if (attempts == 3) {
			cout << "\n\nВы проиграли 3 раза! Потеря " << red << "70$" << nul << "\n\n";
			money = money - 70;
			attempts = 0;
		}
		if (attempts1 == 3) {
			cout << "\n\nВы выиграли 3 раза! Награда " << green << "70$" << nul << "\n\n";
			money = money + 70;
			attempts1 = 0;
		}
		int again=0;
		cout << "\n\nЖелаете ещё раз сразиться с Фрэнком?\n\n1 - Да\n2 - Вернуться к выбору мини-игр\n\nВаш выбор: ";
		while (true) {
			cin >> again;
			if (again < 1 || again>2) {
				cout << "Несуществующий вариант!\n";
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
	cout << "\n\nВаш баланс: " << green << money << "$" << nul << "\n\n";
	cout << green << "Джонн:" << nul << " ну что же, посмотрим, порадует и меня эта шайтан-машина сегодня или нет...\n\n";
	cout << "\t\t\tМИНИ-ИГРА " << red << "А" << green << "В" << yellow << "Т" << cyan << "О" << purple << "М" << blue << "А" << red << "Т" << nul << "\n\n";
	cout << cyan << "Правила: " << nul << "игрок нажимает кнопку " << yellow << "ПОВЕРНУТЬ" << nul << " (1) после определенного поворота барабана вылетают различные цифры, если 3 центральных символа совпадают друг с другом, тогда пользователь победил, награда " << green << "40$" << nul << ", а иначе - нет, то есть потеря в " << red << "40$" << nul << ".Удачи!\n\n";
	while (true) {
		cout << "Нажмите 1, чтобы играть: ";
		while (true) {
			cin >> go;
			if (go != 1) {
				cout << "НАЖМИТЕ ОДИН!\n";
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
				cout << green << "ПОБЕДА!" << nul << "\n\n";
				cout << "Награда в " << green << "40$" << nul << "\n\n";
				money = money + 40;
			}
			if ((mas[1][0] != mas[1][1]) || (mas[1][0] != mas[1][2]) || (mas[1][1] != mas[1][2])) {
				cout << red << "НЕУДАЧА!" << nul << "\n\n";
				attempts++;
			}
		}
		if (attempts == 3) {
			cout << "Вы проиграли 3 раза! Потеря " << red << "40$" << nul << "\n\n";
			money = money - 40;
			attempts = 0;
		}
		int again;
		cout << "Желаете попробовать ещё раз?\n1 - Попробовать ещё раз\n2 - Вернуться к выбору мини-игр\nВаш выбор: ";
		while (true) {
			cin >> again;
			if (again < 1 || again>2) {
				cout << "Несуществующий вариант!\n";
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
		cout << "\n\nВаш баланс: " << green << money << "$" << nul << "\n\nКуда направиться?\n\n1 - На лево к автоматам\n2 - На право к настольным играм\n3 - Покинуть игровую\n\nВаше действие : ";
		while (true) {
			cin >> choice;
			if (choice < 1 || choice>3) {
				cout << "Несуществующий вариант!\n";
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
			cout << "\n\n<Покинул игровую>\n\n";
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
	cout << "\t\t\tИГРА " << green << "ПАЛОЧКИ" << nul << cyan << "\n\nПравила:" << nul << " Вам необходимо посчитать ходы наперёд. Перед вами находится N кол - во палочек.Вы и Карл будете по очереди брать 1, 2 или 3 палочки.Взявший последнюю палочку - ПРОИГРАЕТ.Начинаете вы.\n\nВведите количество палочек : ";
	while (restart == 1 && restart != 2) {
		if (restart == 2) {
			restart = 2;
			break;
		}
		while (true) {
			cin >> sticks;
			if (sticks < 2 || sticks>25) {
				cout << "Недопустимое кол-во палочек!\n";
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
				cout << "\nПалочек: " << game << "\n\nСколько палочек возьмёте: ";
				cin >> player;
				if (player > 3 || player < 1) {
					cout << "Читай условие!" << endl;
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
						cout << green << "\nДЖОНН ВЫИГРАЛ!" << nul << endl;
						cout << "Желаете ещё раз?\n\n1 - Да\n2 - Вернуться к выбору игр\n\nВаш выбор: ";
						while (true) {
							cin >> restart;
							if (restart < 1 || restart>2) {
								cout << "Несуществующий вариант!\n";
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
					cout << "\nХод Карла" << endl;
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
					cout << "Карл взял: " << bot << " палочек" << endl;
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
						cout << cyan << "\nВЫИГРАЛ КАРЛ" << nul << endl;
						cout << green << "\nВЫИГРАЛ ДЖОНН!" << nul << endl;
						cout << "Желаете ещё раз?\n\n1 - Да\n2 - Вернуться к выбору игр\n\nВаш выбор: ";
						while (true) {
							cin >> restart;
							if (restart < 1 || restart>2) {
								cout << "Несуществующий вариант!\n";
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
					cout << "Ошибка!" << endl;
					break;
				}
			}
		}
	carl();
}

void calend(string let) {
	auto startPlayer = chrono::steady_clock::now();
	int letrs = 0;
	cout << "На раскрашенных страницах много праздников хранится (НА АНГЛИЙСКОМ, С БОЛЬШОЙ БУКВЫ!)\n";
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
			cout << "\n\nПоздравляю! Вы угадали слово: ";
			for (int i = 0; i <= 7; i++) {
				cout << secret[i];
			}
			cout << "\n\nЗаняло это у вас: " << timePlayer << " сек.\n";
			break;
		}
		cout << "\nУгадывайте букву (АНГЛ.!): ";
		for (int i = 0; i <= 1; i++) {
			cin >> let;
			if (cword.find(let)) {
				i += 1;
			}
			else {
				cout << "Такая буква отсутствует в слове!\nУгадывайте букву (АНГЛ.!): ";
				i--;
				continue;
			}
		}
		if (let == "C") {
			if (secret[0] == let) {
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
	cout << "Стоит дуб, в нём 12 гнёзд, в каждом гнезде по 4 яйца, в которых по 7 цыпленков (НА АНГЛИЙСКОМ, С БОЛЬШОЙ БУКВЫ!)\n";
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
			cout << "\n\nПоздравляю! Вы угадали слово: ";
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
			cout << "\n\nЗаняло это у вас: " << timePlayer << " сек.\n";
			break;
		}
		cout << "\nУгадывайте букву (АНГЛ.!): ";
		for (int i = 0; i <= 1; i++) {
			cin >> let;
			if (cword.find(let)) {
				i += 1;
			}
			else {
				cout << "Такая буква отсутствует в слове!\nУгадывайте букву (АНГЛ.!): ";
				i--;
				continue;
			}
		}
		if (let == "Y") {
			if (secret[0] == let) {
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
	cout << "По реке Простыне плывёт пароход то назад, то вперёд, а за ним только гладь (НА АНГЛИЙСКОМ, С БОЛЬШОЙ БУКВЫ!)\n";
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
			cout << "\n\nПоздравляю! Вы угадали слово: ";
			for (int i = 0; i <= 3; i++) {
				cout << secret[i];
			}
			cout << "\n\nЗаняло это у вас: " << timePlayer << " сек.\n";
			break;
		}
		cout << "\nУгадывайте букву (АНГЛ.!): ";
		for (int i = 0; i <= 1; i++) {
			cin >> let;
			if (cword.find(let)) {
				i += 1;
			}
			else {
				cout << "Такая буква отсутствует в слове!\nУгадывайте букву (АНГЛ.!): ";
				i--;
				continue;
			}
		}
		if (let == "I") {
			if (secret[0] == let) {
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
				cout << "Данная буква уже разгадана!\n";
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
	cout << "ИГРА " << yellow << "УГАДАЙ СЛОВО" << nul << "\n\n";
	while (true) {
		cout << "Готовы начать?\n1 - Да\n2 - Нет\nВаш выбор: ";
		while (true) {
			cin >> start;
			if (start < 1 || start>2) {
				cout << "Несуществующий вариант!\n";
				continue;
			}
			else break;
		}
		if (start == 1) {
			int num = 0;
			cout << "Выберете номер загадки:\n1 - Первая\n2 - Вторая\n3 - Третья\n4 - Случайно\nВаш выбор: ";
			while (true) {
				cin >> num;
				if (num < 1 || num>4) {
					cout << "Несуществующий вариант!\n";
					continue;
				}
				else break;
			}
			cout << blue << "\t\t\tРАЗГАДАЙ ЗАГАДКУ\n\t\t\t" << nul;
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
			cout << "А стоило бы(\n";
		}
		int again = 0;
		cout << "Желаете ещё раз?\n1 - Да\n2 - Нет\nВаш выбор: ";
		while (true) {
			cin >> again;
			if (again < 1 || again>2) {
				cout << "Несуществующий вариант!\n";
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
	cout << "Скрытие:\n";
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
	cout << "Введите координаты первого символа (строка, столбец): " << e;
		cin >> el1 >> el2;
		cout << "Введите координаты второго символа (строка, столбец): " << e;
		cin >> el3 >> el4;
	if (mas[el1 - 1][el2 - 1] == mas[el3 - 1][el4 - 1]) {
		cout << "Символ отгадан!\n";
		swtch[el1 - 1][el2 - 1] = true;
		swtch[el3 - 1][el4 - 1] = true;
	}
	else {
		cout << "Символы позаданным координатам не совпали!\n";
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
	cout << green << "\t\tПАМЯТЬ" << cyan << "\nСуть игры" << yellow << ": найти пару одинаковых символов, за как можно короткое время\nИмеется 3 подсказки, использовать которые можно нажатием на <u>" << nul;
	while (true) {
		help = 3;
		number = 1;
		cout << "\nВы готовы начать ? (1 - Да, 2 - Нет)\nВаш выбор : ";
		while (true) {
			cin >> start;
			if (start < 1 || start>2) {
				cout << "Несуществующий вариант!\n";
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
			cout << "1)Подсказка (Осталось " << help << ")\n2)Сделать ход\nВаш выбор : ";
			cin >> choice;
			if (choice == 1) {
				if (help > 0) {
					cout << "Введите строку и столбец нужного символа: " << e;
					cin >> str1 >> stlb1;
					cout << "Этот символ стоит на заданной вами клетке:   " << mas[str1 - 1][stlb1 - 1] << endl;
					help--;
				}
				else {
					cout << "Подсказки закончились!\n";
				}
			}
			else {
				if (choice == 2) {
					turn(number, mas, swtch);
				}
				else {
					cout << "Ошибка!\n";
				}
			}
		}
		cout << "Вы прошли игру за " << number << " ходов\n";
		int again;
		cout << "Желаете ещё раз?\n\n1 - да\n2 - нет\n\nВаш выбор: ";
		while (true) {
			cin >> again;
			if (again < 1 || again>2) {
				cout << "Несуществующий вариант!\n";
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
	cout << cyan << "Карл:" << nul << " сыграем во что-нибудь?\n\n";
	cout << green << "Джонн:" << nul << " отличная идея, только во что? Я знаю, у тебя на этт случай достаточный набор варинатов!\n";
	cout << cyan << "Карл:" << nul << " да, есть несколько интересных вариантов, например <Палочки>, <Угадай слово> или же <Память>, какая - тебе больше нравится ? \n\n";
	cout << "Ваш выбор, нумерация аналогична перечислению Карла (1-3, 4 - не во что): ";
	while (true) {
		cin >> game;
		if (game < 1 || game>4) {
			cout << "Несуществующий вариант!\n";
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
		cout << green << "Джонн:" << nul << " что-то я передумал, я к тебе чуть позже зайду, у меня срочные дела. Пока!\n\n";
		cout << cyan << "Карл:" << nul << " ну как знаешь, до встречи(\n\n";
		cout << "<Strange ending...>\n\n";
	}
}

#pragma endregion

#pragma region Главная_второстепенная_функция

void wakenow(int &money) {
	music();
	int locals = 0;
	cout << green << "Джонн:" << nul << " какое замечательное утро, самое время узнать, что - же меня сегоня ждёт...";
	cout << white << "\n\n<Посмотрел на часы, которые только пробили 8 утра>\n\n" << nul << "Ой... сейчас же ещё все лишь 8 часов утра, родители ещё спят, ладно пойду прогуляюсь по округе...";
	Sleep(5);
	cout << white << "\nСпустя 5 минут, Джонн был уже в лёгкой летней одежде во дворе своего небольшого дома..." << nul;
	cout << "Да уж, мой дом находится довольно далеко от основных зданий посёлка, но благо у меня есть с собой личных " << green << money << "$" << nul << "\nКуда же мне сегодня направиться, может быть в наш знаменитый бар...\n";
	Sleep(3);
	cout << "а может в игровую, где всегда происходит что - то интересное, хотя я там уже вчера был...\n";
	Sleep(3);
	cout << "но можно ведь и к Карлу, его я знаю с самого детства, с человеком с таким богатым набором идей точно не заскучаешь...";
	Sleep(5);
	while (true) {
		if (locals == 3) {
			c();
			break;
		}
		map();
		int pohod;
		cout << "\n\nВаш баланс: " << green << money << "$" << nul;
		cout << "\n\nКуда направляться (НАПРАВЛЕНИЯ АНАЛОГИЧНЫ НАПРАВЛЕНИЯМ НА КАРТЕ, НИКАКИХ ЗЕРКАЛЬНЫХ ПРЕДСТАВЛЕНИЙ!)\n1 - Влево\n2 - Вниз\n3 - Вправо\nВаш выбор: ";
		while (true) {
			cin >> pohod;
			if (pohod < 1 || pohod>3) {
				cout << "Данного направления не существует!\n";
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
			cout << "\n\n<Открыл дверь игровой, зашёл>\n\n";
			cout << green << "Джонн:" << nul << " ух ты! Давненько я здесь не был, появилось много чего нового, самое время испытать свою удачу!)\n\n";
			casino(money);
			locals++;
			continue;
		}
		if (pohod == 3) {
			c();
			cout << "\n\n<Постучал в дверь, открыл Карл>\n\n";
			cout << cyan << "Карл:" << nul << " О! Привет, как твои дела, очень рад что ты зашёл!\n\n";
			cout << green << "Джонн:" << nul << " Здравствуй дружище! Дела мои отлично, тоже очень рад тебя видеть, вот решил к тебе зайти, всё таки давненько уже не виделись...\n\n";
			carl();
			locals++;
			continue;
		}
	}
	while (true) {
		music();
		map();
		int pohod;
		cout << "\n\nВаш баланс: " << green << money << "$" << nul;
		cout << "\n\nКуда направляться (НАПРАВЛЕНИЯ АНАЛОГИЧНЫ НАПРАВЛЕНИЯМ НА КАРТЕ, НИКАКИХ ЗЕРКАЛЬНЫХ ПРЕДСТАВЛЕНИЙ!)\n1 - Влево\n2 - Вниз\n3 - Вправо\n" << green << "4 - Вернуться домой\n\n" << nul << "Ваш выбор : ";
		while (true) {
			cin >> pohod;
			if (pohod < 1 || pohod>4) {
				cout << "Данного направления не существует!\n";
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
			cout << "\n\n<Открыл дверь игровой, зашёл>\n\n";
			cout << green << "Джонн:" << nul << " ух ты! Давненько я здесь не был, появилось много чего нового, самое время испытать свою удачу!)\n\n";
			casino(money);
			continue;
		}
		if (pohod == 3) {
			c();
			cout << "\n\n<Постучал в дверь, открыл Карл>\n\n";
			cout << cyan << "Карл:" << nul << " О! Привет, как твои дела, очень рад что ты зашёл!\n\n";
			cout << green << "Джонн:" << nul << " Здравствуй дружище! Дела мои отлично, тоже очень рад тебя видеть, вот решил к тебе зайти, всё таки давненько уже не виделись...\n\n";
			carl();
			continue;
		}
		if (pohod == 4) {
			c();
			cout << green << "Джонн:" << nul << " эх ладно, думаю с меня на сегодня хватит походов, при чём уже и вечереет, пора возвращаться домой.";
			Sleep(1);
			cout << green << "Джонн:" << nul << " спасибо тебе большое за игру, " << name << "! До новых встреч, удачи тебе!\n\n";
			Sleep(1);
			cout << yellow << "Официант:" << nul << " спасибо за игру " << name << "! И за денюшки отдельное;)\n\n";
			Sleep(1);
			cout << cyan << "Карл:" << nul << " спасибо за игру " << name << "! Джонну отдельно также!\n\n";
			Sleep(1);
			cout << red << "Фрэнк:" << nul << " спасибо за игру " << name << "! А в кубики я тебя всё равно хотя-бы раз, но обырал, признайся...)";
			Sleep(2);
			cout << "<ОТ АВТОРА>\n\n" << "От себя лично также скажу, спасибо тебе, " << name << " за игру!\n\n";
			Sleep(1);
			cout << "<Двери дома Джонна захлопнулись, над городом настала ночь>\n\n" << green << "\t\t\t\t\tКОНЕЦ\n" << nul;
			break;
		}
	}
}

#pragma endregion