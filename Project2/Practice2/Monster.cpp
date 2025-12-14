#include <cstdlib>
#include "Monster.h"

Monster::Monster(string mobName)
{
	name = mobName;
	level = 3;
	HP = 10;
	power = 30;
	defence = 10;
	speed = 10;
}

void Monster::printMonsterStatus() {
	cout << "------------------------------------" << endl;
	cout << "* 현재 능력치" << endl;
	cout << "닉네임: " << name << endl;
	cout << "Lv. " << level << endl;
	cout << "HP: " << HP << endl;
	cout << "공격력: " << power << endl;
	cout << "방어력: " << defence << endl;
	cout << "속도: " << speed << endl;
	cout << "------------------------------------" << endl;
}

void Monster::attack(Player* player)
{
	int damage = power - player->getDefence();
	if (damage <= 0) { damage = 1; }
	cout << "플레이어에게 " << damage << " 만큼 피해를 입혔습니다." << endl;
	player->setHP(player->getHP() - damage);
	if (player->getHP() > 0)
		cout << "플레이어의 남은 HP : " << player->getHP() << "입니다." << endl;
	else
	{
		cout << "플레이어가 사망했습니다." << endl;
		exit(EXIT_FAILURE);
	}
	
}

void Monster::setName(string mobName)
{
	name = mobName;
}

void Monster::setHP(int mobHP)
{
	HP = mobHP;
}

void Monster::setPower(int mobPower)
{
	power = mobPower;
}

void Monster::setDefence(int mobDefence)
{
	defence = mobDefence;
}

void Monster::setSpeed(int mobSpeed)
{
	speed = mobSpeed;
}