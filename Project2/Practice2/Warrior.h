#pragma once
#include "Player.h"

class Warrior : public Player
{
public:
	Warrior(string nickname) : Player(nickname)
	{
		nickname = nickname;
		job_name = "Warrior";
		level = 1;
		HP = 200;
		MP = 50;
		power = 5;
		defence = 20;
		accuracy = 30;
		speed = 5;
	}

	void attack();
	void attack(Monster* monster);
	void tekai();
	void buff();
};