#include <iostream>
#include <conio.h>
#include <thread>
#include <windows.h>
#include <chrono>
//#include <cstdio>


class engine {
public:
	std::string m_horizontal = " ";
	std::string m_vertical = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	std::string m_horSpeed = " ";
	std::string m_verSpeed = "\n";
	char arr[2][2] = { {'_','_',},
					   {'_','_'}
	};
	void virtual s_moveLeft(int i);
	void virtual s_moveRight(std::string m_horSpeed);
	void virtual s_moveUp(int i);
	void virtual s_moveDown(std::string m_verSpeed);
	void virtual s_showObj(char arr[2][2], int x, int y);

	void move();
	void virtual frame(char arr[2][2], int x, int y);
	int virtual intro();
};

int engine::intro() {
	std::cout << "Вас прветствует консольный 'движок' - ConsoleEngine. \n\n";
	std::cout << "Управление объектами производится с помощью клавиш W,A,S,D.\n";
	std::cout << "В данной версии присутсвует 1 объект - космический корабль. \n";
	std::cout << "Функционал программы:\n\t1.Для запуска объекта(космическйи корабль) введите 1.\n\t2.Для выхода из программы намите 2.\n";
	int i{ 2 };
	std::cin >> i;
	return i;
};

void engine::s_moveLeft(int i) {
	m_horizontal.assign(m_horizontal, 0, i - 1);
}

void engine::s_moveRight(std::string x) {
	m_horizontal += x;

}
void engine::s_moveUp(int i) {
	m_vertical.assign(m_vertical, 0, i - 1);
}

void engine::s_moveDown(std::string x) {
	m_vertical += x;
}

void engine::s_showObj(char arr[2][2], int x, int y) {
	std::cout << m_vertical;
	for (int i = 0; i <= (x - 1); ++i) {
		std::cout << m_horizontal;
		for (int j = 0; j <= (y - 1); ++j) {
			std::cout << arr[i][j];
		}
		std::cout << "\n";
	}
}

void engine::move()
{
	int c{ 0 };
	while (true) {
		c = _getch();
		if (c == 97 || c == 65) {
			s_moveLeft(m_horizontal.length());
		}
		else if (c == 100 || c == 68) {
			s_moveRight(m_horSpeed);
		}
		else if (c == 87 || c == 119) {
			s_moveUp(m_vertical.length());
		}
		else if (c == 83 || c == 115) {
			s_moveDown(m_verSpeed);
		};

		c = 0;
	}
}


void engine::frame(char arr[2][2], int x, int y)
{
	while (true) {

		s_showObj(arr, x, y);
		std::this_thread::sleep_for(std::chrono::milliseconds(16)); // Создает видимость "кадра"
		system("cls");

	}

}


class spaceShip :public engine
{
public:
	char spaceship[9][9] = {
			{' ',' ',' ',' ','_',' ',' ',' ',' '},
			{' ',' ',' ','/',' ','\\',' ',' ',' '},
			{' ',' ','(',' ',' ',' ',')',' ',' '},
			{' ','/',' ',' ',' ',' ',' ','\\',' '},
			{'(',' ',' ',' ',' ',' ',' ',' ',')'},
			{'(',' ',' ',' ',' ',' ',' ',' ',')'},
			{' ','\\',' ',' ',' ',' ',' ','/',' '},
			{' ',' ','(',' ','_',' ',')',' ',' '},
			{' ',' ',' ','_',' ','_',' ',' ',' '}
	};
	std::string speedMultVert = "\n\n\n\n\n";
	std::string speedMultHoriz = "     ";
	int speedMult_Left_Up = 5;					//Из-за особенностей перемещения (влево,вверх)
	void s_moveLeft(int i);
	void s_moveRight(std::string m_horSpeed);
	void s_moveUp(int i);
	void s_moveDown(std::string m_verSpeed);
	void virtual s_showObj(char spaceship[9][9], int x, int y);
	void virtual frame();
	int virtual intro();
};

int spaceShip::intro() {
	std::cout << "Поздравляю вы создали свой собственный корабль!!!! \n\n";
	std::cout << "Удачного полета капитан(Внимание, корабль довольно быстрый).";
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	return 0;
};

void spaceShip::s_moveLeft(int i) {
	m_horizontal.assign(m_horizontal, 0, i - speedMult_Left_Up);
}

void spaceShip::s_moveRight(std::string x) {
	m_horizontal += x + speedMultHoriz;

}
void spaceShip::s_moveUp(int i) {
	m_vertical.assign(m_vertical + speedMultVert, 0, i - speedMult_Left_Up);
}

void spaceShip::s_moveDown(std::string x) {
	m_vertical += x + speedMultVert;
}

void spaceShip::s_showObj(char spaceship[9][9], int x, int y) {
	std::cout << m_vertical;		   //разная скорость у разных объектов
	for (int i = 0; i <= (x - 1); ++i) {
		std::cout << m_horizontal; //разная скорость у разных объектов
		for (int j = 0; j <= (y - 1); ++j) {
			std::cout << spaceship[i][j];
		}
		std::cout << "\n";
	}
}

void spaceShip::frame()
{
	while (true) {

		s_showObj(spaceship, 9, 9);
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
		system("cls");

	}

}

int main()
{
	system("chcp 1251>nul");

	engine intro;
	int menu = intro.intro();
	if (menu == 1) {
		spaceShip Cruiser;
		Cruiser.intro();
		std::thread a(&spaceShip::frame, std::ref(Cruiser)); //Для одновременного выввода поля с объектом
		Cruiser.move();										//и ввода вектора передвижения
		a.join();

	}
	else if (menu == 2) {
		return 0;
	}



	return 0;
}

