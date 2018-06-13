// TEMA: Aventura Politica 2.5
#include <iostream>
#include <string>
#include <vector>
#include "CEscenario.h"
using namespace std;
int main()
{
	// Creador del Mundo
	CEscenario NewWorld;
	while (true)
	{
		NewWorld.fn_world();
	}
	cin.ignore();
	cin.get();
	return 0;
}