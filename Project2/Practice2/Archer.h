#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer(string nickname) : Player(nickname) 
	{
		nickname = nickname;
		job_name = "Archer";
		level = 1;
		HP = 50;
		MP = 100;
		power = 15;
		defence = 5;
		accuracy = 70;
		speed = 12;
	}

	void attack();
	void attack(Monster* monster);
	void tekai();
	void buff();
	
};