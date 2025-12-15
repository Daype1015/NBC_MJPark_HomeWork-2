#include <limits>
#include <random>
#include <ctime>

#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"

using namespace std;

string vsMonster() // 랜덤한 1~ 3 사이에 랜덤한 수를 생성 해서 해당 스트링 반환
{
	mt19937 generator(static_cast<unsigned int>(time(nullptr)));
	uniform_int_distribution<int> distribution(1, 3);
	int num_Monster = distribution(generator);

	switch (num_Monster)
	{
	case 1: return "Goblin";
		break;
	case 2: return "Dragon";
		break;
	case 3: return "Hydra";
		break;
	}
}

int checkint(int* a)
{
	while (1)
	{
		if (cin >> *a)
		{
			return *a;
		}
		else
		{
			cout << "올바른 숫자를 입력하세요." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

string checkStr()
{
	string input;
	while (1)
	{
		getline(cin, input); // getline 은 사용자가 enter를 입력할 때 까지 한줄 전체를 읽음 공백 예외처리 가능
		//cin >> input; // cin을 사용하면 공백이나 탭을 입력받는 기준자로 정하기 때문에 예외처리가 불가능
		bool has_Space = any_of(input.begin(), input.end(), [](unsigned char ch) {
			return isspace(ch);
			});
		bool allIsAlpha = all_of(input.begin(), input.end(), [](unsigned char ch) {
			return isalpha(static_cast<unsigned char>(ch));
			});
		if (allIsAlpha && !has_Space && !input.empty())
		{
			return input;
		}
		else
		{
			cout << "올바른 문자를 입력하세요." << endl;
			/*cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');*/
		}
	}
}

void battleMonster(Player* player, Monster* monster, int* run)
{
	int player_Behaivior = 0;
	int curdef= 0;
	int curPower = 0;
	bool hasBuff = false;
	while (1)
	{
		cout << "수행할 동작을 선택하세요." << endl;
		cout << "1) 공격! " << endl;
		cout << "2) 방어! " << endl;
		cout << "3) 강화! " << endl;
		cout << "4) 전투 상태 확인! " << endl;
		cout << "5) 도망! " << endl;
		switch (checkint(&player_Behaivior))
		{
		case 1: 
				if (hasBuff)
				{
					player->attack(monster);
					player->setPower(curPower);
					hasBuff = false;
				}
				else
				{
					player->attack(monster);
					monster->attack(player);
				}
			break;
		case 2: curdef = player->getDefence();
				player->tekai();
				monster->attack(player);
				player->setDefence(curdef);
			break;
		case 3: curPower = player->getPower();
				player->buff();
				monster->attack(player);
				hasBuff = true;
			break;
		case 4: player->printPlayerStatus();
				monster->printMonsterStatus();
			break;
		case 5: cout << "튀어~~~~잇!!" << endl;
				*run = 1;
				return;
		default:
			cout << "잘못된 입력입니다." << endl;
			break;
		}
	}
}

int main()
{
	string jobs[] = { "전사", "마법사", "도적", "궁수" };
	int job_choice = 0;
	int behaivior_Choice = 0;
	int runaway;
	string nickname;

	Player* player = nullptr;
	Monster* monster = nullptr;

	cout << "닉네임을 입력해주세요.";
	nickname = checkStr();

	cout << "<전직 시스템>" << endl;
	cout << nickname << " 님 환영합니다!" << endl;
	cout << "* 원하시는 작업을 선택해주세요." << endl;

	start_of_Input:
	for (int i = 0; i < 4; i++)
	{
		cout << (i + 1) << ". " << jobs[i] << endl;
	}

	cout << "선택 : ";
	job_choice = checkint(&job_choice);

	switch (job_choice)
	{
	case 1:
		player = new Warrior(nickname);
		break;
	case 2:
		player = new Magician(nickname);
		break;
	case 3:
		player = new Thief(nickname);
		break;
	case 4:
		player = new Archer(nickname);
		break;
	default:
		cout << "잘못된 입력입니다." << endl;
		goto start_of_Input;
	}

	start_of_game:
	player->printPlayerStatus();
	cout << "========================" << endl;
	cout << "동작을 선택하세요." << endl;
	cout << "1) 전투" << endl;
	cout << "2) 내 정보 조회" << endl;
	cout << "3) 종료" << endl;
	cout << "========================" << endl;
	behaivior_Choice = checkint(&behaivior_Choice);

	switch (behaivior_Choice)
	{
	case 1: monster = new Monster(vsMonster());
			monster->printMonsterStatus();
			battleMonster(player, monster, &runaway);
			if (runaway == 1)
			{
				goto start_of_game;
			}
		break;
	case 2: player->printPlayerStatus();
			goto start_of_game;
			break;
	case 3: return 0;
		break;
	}

	

	if (player != nullptr)
		delete player;
	if (monster != nullptr)
		delete monster;

	return 0;
}