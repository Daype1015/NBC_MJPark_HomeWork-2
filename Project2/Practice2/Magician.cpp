#include "Magician.h"

void Magician::attack()
{
	cout << "Fire Ball!!!" << endl;
}

void Magician::attack(Monster* monster)
{
	int damage = power - monster->getDefence();
	if (damage <= 0) { damage = 1; }

	cout << "데미지 : " << damage << " 를 가했습니다." << endl;

	monster->setHP(monster->getHP() - damage);
	if (monster->getHP() > 0)
		cout << "몬스터의 남은 HP : " << monster->getHP() << " 입니다." << endl;
	else
	{
		cout << "몬스터를 처치했습니다. 플레이어가 승리했습니다!" << endl;
		exit(EXIT_FAILURE);
	}
}

void Magician::tekai()
{
	setDefence(20);
}

void Magician::buff()
{
	setPower(40);
}