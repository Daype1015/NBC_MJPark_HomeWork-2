#pragma once
#include "Player.h"

class Magician : public Player
{
public:
	Magician(string nickname) : Player(nickname) 
	{
		nickname = nickname;
		job_name = "Magician";
		level = 1;
		HP = 30;
		MP = 200;
		power = 10;
		defence = 5;
		accuracy = 50;
		speed = 8;
	}

	void attack();
	void attack(Monster* monster);
	void tekai();
	void buff();

};