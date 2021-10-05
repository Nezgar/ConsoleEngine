#include <iostream>
#include <conio.h>
#include <thread>
#include <windows.h>
#include <chrono>
//#include <cstdio>

/* ARKANOID
int unsigned sides = 0;
string size(sides, ' ');

void s_showSpaceship(char spaceship[][9], int x, int y) {
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	for (int i = 0; i <= (x - 1); ++i) {
		cout << size;
		for (int j = 0; j <= (y - 1); ++j) {
			cout << spaceship[i][j];
		}
		cout << "\n";
	}
}

void s_showSpaceshipLeft() {
	sides -= 1;
}

void s_showSpaceshipRight() {
	sides += 1;
}

int main()
{
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

	int x = 9;
	int y = 9;



	do {
		s_showSpaceship(spaceship, x, y);
		system("cls");

		if (!kbhit()) {
			system("pause>nul");
			char word = getch();
			switch (word) {
			case 'a': s_showSpaceshipLeft();
			case 'd': s_showSpaceshipRight();

			}
		}

	} while (true);


	system("cls");
}
*/ //ARKANOID







class engine {
public:
	std::string m_horizontal=" ";
	std::string m_vertical = "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	std::string m_horSpeed = " ";
	std::string m_verSpeed = "\n";
	char arr[2][2] = { {'_','_',},
					   {'_','_'}
	};
	void s_moveLeft( int i);
	void s_moveRight(std::string m_horSpeed);
	void s_moveUp(int i);
	void s_moveDown(std::string x = "\n");
	void virtual s_showObj(char arr[2][2], int x, int y);
	
	void move();
	void virtual frame(char arr[2][2], int x, int y);

};

void engine::s_moveLeft(int i) {
	m_horizontal.assign(m_horizontal,0,i-1);
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


void engine::frame(char arr[2][2],int x,int y)
{
	while (true) {
		
		s_showObj(arr, x, y);
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
		system("cls");
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
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
	void virtual s_showObj(char spaceship[9][9], int x, int y);
	void virtual frame();
};

void spaceShip::s_showObj(char spaceship[9][9], int x, int y) {
	std::cout << m_vertical;
	for (int i = 0; i <= (x - 1); ++i) {
		std::cout << m_horizontal;
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
		//std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

}

int main()
{
	system("chcp 1251>nul");
	//unsigned long long c = GetTickCount64();

	spaceShip Cruiser;
	std::thread a(&spaceShip::frame,std::ref(Cruiser));
	Cruiser.move();
	
	a.join();
	return 0;
}

