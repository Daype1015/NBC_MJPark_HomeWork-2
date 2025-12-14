#pragma once
#include "Player.h"

class Thief : public Player
{
public:
	Thief(string nickname) : Player(nickname)
	{
		nickname = nickname;
		job_name = "Thief";
		level = 1;
		HP = 40;
		MP = 80;
		power = 20;
		defence = 0;
		accuracy = 90;
		speed = 20;
	}

	void attack();
	void attack(Monster* monster);
	void tekai();
	void buff();

};