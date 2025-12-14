#pragma once
#include <string>
#include "Player.h"
using namespace std;

class Player;

class Monster
{
public:
	Monster(string mobName);
	void attack(Player* player);
	void printMonsterStatus();

	string getName() { return name; }
	int getHP() { return HP; }
	int getPower() { return power; }
	int getDefence() { return defence; }
	int getSpeed() { return speed; }

	void setName(string mobName);
	void setHP(int mobHP);
	void setPower(int mobPower);
	void setDefence(int mobDefence);
	void setSpeed(int mobSpeed);

protected:
	string name;
	int level;
	int HP;
	int power;
	int defence;
	int speed;
};