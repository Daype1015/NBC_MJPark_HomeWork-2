#pragma once
#include <iostream>
#include <cstdlib>
#include <string> // 스트링 사용
#include "Monster.h"
using namespace std;

class Monster;

class Player { //플레이어 클래스 선언 
public:
	Player(string playerName); // 생성자

	virtual void attack() = 0; // 순수 가상함수 선언
	virtual void attack(Monster* monster) = 0;
	virtual void tekai() = 0;
	virtual void buff() = 0;
	void printPlayerStatus();

	//getter 함수
	string getJobName() { return job_name; }
	string getNickName() { return nickname; }
	int getLevel() { return level; }
	int getHP() { return HP; }
	int getMP() { return MP; }
	int getPower() { return power; }
	int getDefence() { return defence; }
	int getAccuracy() { return accuracy; }
	int getSpeed() { return speed; }

	//setter 함수
	void setNickName(string inputName);
	void setHP(int setHP);
	void setMP(int setMP);
	void setPower(int setPower);
	void setDefence(int setDefence);
	void setAccuracy(int setAccuracy);
	void setSpeed(int setSpeed);

protected:
	string job_name;
	string nickname;
	int level;
	int HP;
	int MP;
	int power;
	int defence;
	int accuracy;
	int speed;
};

