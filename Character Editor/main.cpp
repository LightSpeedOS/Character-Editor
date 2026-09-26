#include "Includes.h"
#include "Logic.h"
#include "Struct.h"

using namespace std;


auto main() -> int
{

	Player player = {};

	player.name = "Jamaal";
	player.health = 100;
	player.damage = 20;
	player.level = 10;

	int mainOption;

	while (true)
	{
		listPlayer(player);

		cout << "[1] Edit Name" << endl;
		cout << "[2] Edit Health" << endl;
		cout << "[3] Edit Damage" << endl;
		cout << "[4] Edit Level" << endl;

		space();
		cout << "> ";
		cin >> mainOption;

		if (input())
		{
			continue;
		}

		switch (mainOption)
		{
		case Name:
			editName(&player);
			break;

		case Health:
			editHealth(&player);
			break;

		case Damage:
			editDamage(&player);
			break;

		case Level:
			editLevel(&player);
			break;

		default:
			invalid();
			break;
		}
	}
}