#include "includes.h"
#include "gamefunctions.h"
#include <vector>
#include <fstream>
#include <ostream>
using namespace std;

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