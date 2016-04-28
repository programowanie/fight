#pragma once

#include <string>
#include <vector>

using namespace std;

struct parameter
{
	int chance, power;
};

class Slav
{
	static vector <string> names;

	string _name;
	int _hp, baseHp;
//	int _mana, baseMana;
	int exp;
	parameter _offence, _defence;

	static void init();

public:
	Slav();
//	~Slav();

	int hp() { return _hp; }
	string name() { return _name; }
	parameter offence() { return _offence; }
	parameter defence() { return _defence; }

	bool damage(int value);
	void heal();
	double beastRatio();

	string description();
};
