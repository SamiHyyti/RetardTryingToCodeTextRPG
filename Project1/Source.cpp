#include "includes.h"
using namespace std;
player Player;
enemy Enemy;
weapon Weapon("Katana", "World's best sword ever made t. nippon pro", 200, 10.0f); // 10.0f value does nothing for some reason
float percentage = 0.f;
void combatMenu();
void mainMenu()
{
	string menutext = "text monster killing RPG v0.05 early acces alpha\n\n1. New game\n2. Quit game\n\n";
	int choise;
retry:
	cout << menutext;
	cout << "Selection: ";
	while (!(cin >> choise))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout << menutext;
		cout << "\nERROR invalid selection\nSelection: ";
		Sleep(1000);
		system("cls");
		cout << menutext << "Selection: ";
	}
	switch (choise)
	{
	case 1:
		system("cls");
		return;
	case 2:
		exit(1);
	default:
		system("cls");
		cout << menutext;
		cout << "\nERROR invalid selection\nSelection: ";
		Sleep(1000);
		system("cls");
		goto retry;
	}
}

void generateEnemy()
{
	int x = rand() % 100 + 1;
	if (x < 51)
	{
		Enemy.stats(10.f + 10.f * percentage, 1, 10.f, percentage, "Goblin");
	}
	else if (x < 81)
	{
		Enemy.stats(20.f + 20.f * percentage, 4, 15.f, percentage, "Orc");
	}
	else
	{
		Enemy.stats(50.f + 50.f * percentage, 10, 20.f, percentage, "Troll");
	}
}

void battle()
{
	bool menu = true;
	int selection;
retry:
	Enemy.readStats();
	cout << "\n\n1. Attack Enemy\n2. Flee the battle\nSelection: ";
	while (!(cin >> selection))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout << "\n\n1. Attack Enemy\n2. Flee the battle\nSelection: ";
		cout << "\nERROR invalid selection\nSelection: ";
		Sleep(1000);
		system("cls");
		cout << "\n\n1. Attack Enemy\n2. Flee the battle\nSelection: ";
	}
	switch (selection)
	{
	case 1:
		combatMenu();
		if (Enemy.alive() >!0.0f)
		{
			Player.takeDamage(Enemy.attack());
			if (Player.alive() >!0.0f)
				goto retry;
			else
			{
				system("cls");
				cout << "YOU DIED\nGAME OVER!\n";
				system("pause");
				exit(3);
			}
		}
		else if (Enemy.alive() >!0.0f)
			goto retry;
		else
			percentage += 0.01f;
		break;
	case 2:
		if (percentage != 0.00f)
		{
			percentage -= 0.01f;
			system("cls");
			break;
		}
		system("cls");
		break;
	default:
		system("cls");
		cout << "\n\n1. Attack Enemy\n2. Flee the battle\nSelection: ";
		cout << "\nERROR invalid selection\nSelection: ";
		Sleep(1000);
		system("cls");
		cout << "\n\n1. Attack Enemy\n2. Flee the battle\nSelection: ";
	}
}

void characterCreation()
{
	cout << "Enter the name of your character: ";
	Player.giveName();
	system("cls");
	Player.chooseClass();
	system("cls");
}

void shop()
{



}

void adventureMenu()
{
	bool menu = true;
	string selectiontext = "1. battle random enemy\n2. current stats and equipment\n3. shop(TEST WEAPON VALUES)\n4. quit\n\nselection: ";
	int selection;
retry:
	cout << selectiontext;
	while (!(cin >> selection))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout << "1. battle random enemy\n2. current stats and equipment\n3. shop(TEST WEAPON VALUES)\n4. quit\n";
		cout << "\nERROR invalid selection\nSelection: ";
		Sleep(1000);
		system("cls");
		cout << selectiontext;
	}

	switch (selection)
	{
	case 1:
		generateEnemy();
		battle();
		goto retry;
	case 2:
		Player.readStats();
		goto retry;
	case 3:
		Weapon.readItem(Weapon.x);
		system("cls");
		goto retry;
	case 4:
		exit(2);
	default:
		system("cls");
		cout << "1. battle random enemy\n2. current stats and equipment\n3. shop(TEST WEAPON VALUES)\n4. quit\n\nselection: ERROR invalid selection";
		Sleep(1000);
		system("cls");
		goto retry;
	}

}

void combatMenu()
{
	bool menu = true;
	int selection;
	float x;
	system("cls");
retry:
	cout << "1. Strong Attack\n2. Normal Attack\n3. Quick Attack\n\nselection: ";
	while (!(cin >> selection))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout << "1. Strong Attack\n2. Normal Attack\n3. Quick Attack\n";
		cout << "\nERROR invalid selection\nSelection: ";
		Sleep(1000);
		system("cls");
		cout << "1. Strong Attack\n2. Normal Attack\n3. Quick Attack\n\nselection: ";
	}
	switch (selection)
	{
	case 1:
		x = Player.attack(selection);
		Enemy.takeDamage(x);
		break;
	case 2:
		x = Player.attack(selection);
		Enemy.takeDamage(x);
		break;
	case 3:
		x = Player.attack(selection);
		Enemy.takeDamage(x);
		break;
	default:
		system("cls");
		cout << "1. Strong Attack\n2. Normal Attack\n3. Quick Attack\n\nselection: ";
		Sleep(1000);
		system("cls");
		goto retry;
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	mainMenu();
	characterCreation();
	Player.readStats();
	system("cls");
	adventureMenu();
	return 0;
}