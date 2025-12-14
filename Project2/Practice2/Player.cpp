#include "Player.h"

Player::Player(string playerName)
{
	nickname = playerName;
}

void Player::printPlayerStatus() {
	cout << "------------------------------------" << endl;
	cout << "* 현재 능력치" << endl;
	cout << "닉네임: " << nickname << endl;
	cout << "직업: " << job_name << endl;
	cout << "Lv. " << level << endl;
	cout << "HP: " << HP << endl;
	cout << "MP: " << MP << endl;
	cout << "공격력: " << power << endl;
	cout << "방어력: " << defence << endl;
	cout << "정확도: " << accuracy << endl;
	cout << "속도: " << speed << endl;
	cout << "------------------------------------" << endl;
}

void Player::setNickName(string inputName)
{
	nickname = inputName;
}

void Player::setHP(int setHP)
{
	HP = setHP;
}

void Player::setMP(int setMP)
{
	MP = setMP;
}

void Player::setPower(int setPower)
{
	power = setPower;
}

void Player::setDefence(int setDefence)
{
	defence = setDefence;
}

void Player::setAccuracy(int setAccuracy)
{
	accuracy = setAccuracy;
}

void Player::setSpeed(int setSpeed)
{
	speed = setSpeed;
}


