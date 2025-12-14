#include "Archer.h"


void Archer::attack()
{
	cout << "Shoot Arrow" << endl;
}

void Archer::attack(Monster* monster)
{
	int damage = power - monster->getDefence();
	if (damage <= 0 || damage / 3 <= 0) 
	{ 
		damage = 1; 
		for (int i = 0; i < 3; i++)
			cout << "데미지 : " << damage << " 를 가했습니다." << endl;
	}
	else
	{
		for (int i = 0; i < 3; i++)
			cout << "데미지 : " << damage / 3 << " 를 가했습니다." << endl;
	}
	

	monster->setHP(monster->getHP() - damage);
	if (monster->getHP() > 0)
		cout << "몬스터의 남은 HP : " << monster->getHP() << " 입니다." << endl;
	else
	{
		cout << "몬스터를 처치했습니다. 플레이어가 승리했습니다!" << endl;
		exit(EXIT_FAILURE);
	}
}

void Archer::tekai()
{
	setDefence(20);
}

void Archer::buff()
{
	setPower(30);
}