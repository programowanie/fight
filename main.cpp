#include "Slav.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

#define HIT_FORCE 10
#define HIT_INTERVAL 1000000

int main(int argc, char const *argv[])
{
	srand(argc == 2 
		? atoi(argv[1]) 
		: time(NULL));
	
	Slav slavs[2];

	for (int i = 0; i < 2; ++i)
		printf("%s\n", slavs[i].description().c_str());

	srand(time(NULL));
	while(1)
	{
		usleep(HIT_INTERVAL);
		// Kto uderza?
		double attack[2];
		for (int i = 0; i < 2; ++i)
			attack[i] = (rand() % 100) < slavs[i].offence().chance
				? (slavs[i].offence().power) / 100. * HIT_FORCE
				: 0;

		int whoHits = (int)(attack[1] > attack[0]);

		// Jak mocno?
		int damage = attack[whoHits] - attack[1 - whoHits];

		// Obrona
		damage *= (rand() % 100) < slavs[1-whoHits].defence().chance
			? 1 - (slavs[1-whoHits].defence().power / 100.)
			: 1;

		// Uderz
		bool isLethal = slavs[1 - whoHits].damage(damage);

		printf(" [%2i, %2i] uderza %s z siłą %i\n", 
			slavs[0].hp(), slavs[1].hp(), 
			slavs[whoHits].name().c_str(),
			damage);

		if (isLethal)
		{
			printf("%s wygrywa\n", slavs[whoHits].name().c_str());
			break;
		}
	}

}