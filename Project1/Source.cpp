#include "includes.h"
#include "gamefunctions.h"

int main()
{
	createItems();
	srand((unsigned int)time(nullptr));
	mainMenu();
	Sleep(10);
	characterCreation();
	cls();
	adventureMenu();
	return 0;
}