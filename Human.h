#pragma once
class Human
{
public:
	Human() {};
	Human(int, int) {};
	~Human() {};

	void setAge(int);
	int getAge() const;

	void setHeight(int);
	int getHeight() const;

	friend ostream& operator << (ostream&, const Human&);

private:
	int age;
	int height;
};

Human::Human(int age, int height)
{
	setAge(age);
	setHeight(height);
}

void Human::setAge(int age)
{
	if (age >= 0)
	{
		this->age = age;
	}
	else
	{
		this->age = -age;
	}
}

int Human::getAge() const
{
	return this->age;
}

void Human::setHeight(int height)
{
	this->height = height;
}

int Human::getHeight() const
{
	return this->height;
}

ostream& operator << (ostream& out, const Human& h)
{
	out << "Age - " << h.age << endl;
	out << "Height - " << h.height << endl;
	return out;
}