#include "Slav.h"
#include <stdlib.h>
#include <fstream>

vector <string> Slav::names;

void Slav::init()
{
	ifstream file("names.dat");
	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(names));
	file.close();
}

int randomValue()
{
	return 20 + rand() % 75;	
}

Slav::Slav()
{
	static int amountOfNames = (init(), names.size());
	_name = names[rand() % amountOfNames];
	_hp = baseHp = randomValue();
//	_mana = baseMana = randomValue();
	_offence = { randomValue(), randomValue()};
	_defence = { randomValue(), randomValue()};
	exp = 0;
}

string Slav::description()
{
	return _name + "\n\tHP: " + to_string(_hp) + " BR: " + to_string(beastRatio()) + "\n\t" +
		"offence " + to_string(_offence.chance) + 
		":" + to_string(_offence.power) + 
		"\n\tdefence " + to_string(_defence.chance) + 
		":" + to_string(_defence.power);
}

bool Slav::damage(int value)
{
	_hp -= value;
	return _hp <= 0;
}

void Slav::heal()
{
	_hp = baseHp;
	exp++;
}

double Slav::beastRatio()
{
	double parametersRatio = 
		(_offence.chance * _defence.chance * _offence.power * _defence.power) / 100000000.;
	return _hp * parametersRatio;
}
