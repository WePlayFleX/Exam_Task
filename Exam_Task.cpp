#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "Human.h"//3 Объявите класс в отдельном заголовочном файле, а его реализацию в отдельном файле реализации. Свойства класса: возраст, масса

using namespace std;

//1 Создать класс с двумя свойствами
class PC
{
public:
	PC() {};
	PC(int, int) {};
	~PC() {};

private:
	int videomemory;
	int hdd;
};

//2 Создать класс с тремя свойствами, констурктором по умолчанию и с параметрами
class Person
{
public:
	Person()
	{
		age = 27;
		height = 175;
		sex = 1;			//0 - female, 1 - male, 2 - unknown
	};
	Person(int, char) {};
	~Person() {};

private:
	int age;
	int height;
	char sex;
};

//4 Создайте класс, чтобы в нём происходила утечка памяти
class Leak 
{
private:
	int* h = new int[9];

	int* j = new int;
public:
	Leak() 
	{
		h[10] = 777;
	}
	void out() 
	{
		cout << h << endl;
	}
	/*~Leak()		
	{
		delete h;
		delete j;
	}*/
};

//5 "Реализуйте класс для хранения информации о Лампочке: мощность (4-120 Вт), Световой поток (200-2000 Люмен), вид цоколя (Е14 либо Е27 либо E40). 
//Добавьте в класс конструктор копирования и оператор = "
class Lamp {
private:
	int power;
	int lightFlow;
	int k;
	char* plinth;

public:
	Lamp() 
	{
		power = rand() % 116 + 4;
		lightFlow = rand() % 1800 + 200;
		k = rand() % 3;

		if (k == 1)
		{
			plinth = new char[4]{ "E14" };
		}
		if (k == 2)
		{
			plinth = new char[4]{ "E27" };
		}
		if (k == 3)
		{
			plinth = new char[4]{ "E40" };
		}
	}
	Lamp(const Lamp& l) :
		power(l.power), lightFlow(l.lightFlow), plinth(l.plinth) 
	{
		cout << "Copy constructor" << endl;
	}

	void setPow(int power) 
	{
		if (power >= 0)
		{
			this->power = power;
		}
		else
		{
			this->power = -power;
		}
	}
	void setLightFlow(int LightFlow)
	{
		if (LightFlow >= 0)
		{
			this->lightFlow = LightFlow;
		}
		else
		{
			this->lightFlow = -LightFlow;
		}
	}
	void setTypePlinth(char* TypePlinth) 
	{
		if (TypePlinth != nullptr) 
		{
			this->plinth = new char[strlen(TypePlinth) + 1];
			strcpy_s(this->plinth, strlen(TypePlinth) + 1, TypePlinth);
		}
	}
	Lamp& operator=(const Lamp& p2)
	{
		this->setPow(p2.power);
		this->setLightFlow(p2.lightFlow);
		this->setTypePlinth(p2.plinth);
		return *this;
	}
};

//8 Реализовать класс Блюдо со свойствами: Название, стоимость, масса. Реализовать конструктор по умолчанию и с параметрами.
//9 Добавить в ранее реализованный класс оператор вывода, get/set'еры для свойств.
class Dish
{
private:
	char* name;
	double cost;
	double mass;
public:
	Dish() 
	{
		name = nullptr;
		cost = 0.0;
		mass = 0.0;
	}
	Dish(const char* Nname, double Ncost, double Nmass)
	{
		name = new char[128];
		cost = Ncost;
		mass = Nmass;
		strcpy_s(name, 128, Nname);
	}
	void setCost(double cost)
	{
		if (cost >= 0)
		{
			this->cost = cost;
		}
		else
		{
			this->cost = -cost;
		}
	}
	double getCost()const 
	{
		return this->cost;
	}
	void setName(char* name) 
	{
		if (name != nullptr) 
		{
			this->name = new char[strlen(name) + 1];
			strcpy_s(this->name, strlen(name) + 1, name);
		}
	}
	char* getName() const 
	{
		char* copyName = new char[strlen(this->name)];
		strcpy_s(copyName, strlen(this->name), this->name);
		return copyName;
	}
	void setMass(double mass)
	{
		if (mass >= 0)
		{
			this->mass = mass;
		}
		else
		{
			this->mass = -mass;
		}
	}
	double getMass()const 
	{
		return this->mass;
	}
	void outputFood()
	{
		if (name == nullptr) 
		{
			cerr << "Error" << endl;
		}
		else 
		{
			cout << "Name: " << name << endl;
			cout << "Cost = " << cost << endl;
			cout << "Mass = " << mass << endl;
		}
	}
};

//10 Реализовать класс Число с двумя числовыми свойствами внутри (double, int). Добавить оператор + в данный класс.
class Number
{
private:
	double first;
	int second;
public:
	Number()
	{
		first = 1.0;
		second = 9;
	}
	Number(double nf, int ns)
	{
		first = nf;
		second = ns;
	}
	Number(double i) : first(i) {}
	double sum() 
	{
		first = first + second;
		return first;
	}
};

//13 Сгенерировать массив случайной длины со случайными значениями. На основе сгенерированных значений создать вектор чисел (полная копия). 
class Random
{
private:
	int size;
	const static int buffer = 10000;
	int Array[buffer];
public:
	Random(const int size) : size(size)
	{
		if (this->size > buffer) this->size = buffer;
	}
	void filling() 
	{
		for (int i = 0; i < size; ++i) Array[i] = rand() % 9;
	}
	void print()const 
	{
		for (int i = 0; i < size; ++i) std::cout << Array[i] << ' ';
	}
};

//14 Создать класс с двумя методами, которые позволяют генерировать пароль заданной длины, а также подбирать пароль, сравнивая его с переданным в качестве параметра. Всё проделывать с помощью класса string
class Password 
{
private:
	string pass;
	string entpass;
public:
	Password() {}
	string getPassword(int length)
	{
		string password = "";
		for (int i = 0; i < length; i++)
		{
			password += char('0' + rand() % ('z' - '0'));
		}
		return password;
	}
	void getPassword()
	{
		int k;
		int length = 0;
		int count = 1;
		cout << "Enter len of password : " << endl; 
		cin >> length;

		string password;
		ofstream outFile("passwords.txt");
		password = getPassword(length);
		cout << "pass : " << password << endl;
		outFile << getPassword(length) << endl;

		string entpassword = "";
		cout << "enter your pass: " << endl;
		cin >> entpassword;
		cout << endl;

		int tempS = 0;
		for (int i = 0; i < length; i++)
		{
			if (password.length() != entpassword.length()) 
			{
				goto INC;
			}
			if (password[i] == entpassword[i])
			{
				tempS++;
			}
			else
			{
			INC:
				i = length;
				cout << "\tincorrect =( \n\n" << "rand pass: " << password << "\nyour pass: " << entpassword;
			}
		}
		if (tempS == length)
		{
			cout << "right! \n" << "rand pass: " << password << "\nyour pass: " << entpassword;
		}
		outFile.clear();
		outFile.close();
	}
};

int main()
{
	srand(time(nullptr));

	PC one;
	cout << endl;

	Person two;
	cout << endl;

	Human there;
	Human three ((rand() % 331), (rand() % 188 - 10));
	cout << there << endl;

	Leak four;
	four.out();
	cout << endl;

	Lamp five;
	cout << endl;

	Dish eight_nine;
	cout << endl;

	Number ten;
	cout << endl;

	int size;
	cin >> size;
	Random thirteen(size);
	thirteen.filling();
	thirteen.print();
	cout << endl;

	Password fourteen;
	fourteen.getPassword();
	cout << endl;

	system("pause");
	return 0;
}

