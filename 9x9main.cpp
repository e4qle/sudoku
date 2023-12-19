#include <iostream>
#include <windows.h>
#include <cmath>
#include "h9x9.h"
#include "global.h"
using namespace std;
void resetwartosci();
void main9() {
	resetwartosci();
	cout << "rozwi¹zaæ czy zrobiæ ci do rozwi¹zania?\nodpowiedz 1 albo 2: ";
	int wmain9;
	cin >> wmain9;
	if (wmain9 == 1) {
		rozwiaz9main();
	}
	else if (wmain9 == 2) {
		zaprojektuj9main();
	}
}
void resetwartosci() { // wszystkie wartoœci resetuje na koniec cyklu ¿eby siê nie jeba³o
	// wszystkie k = 0
	// wszystkie w = 0
	// wszystkie lz = false
	// wszystkie kz = false
	// wszystkie bz = false
	int x = 0;
	int y = 0;
	int z = 0;
	while (y < 9) {
		while (x < 9) {
			//w[x][y] = 0;
			k[x][y] = 0;
			lz[x][y] = false;
			kz[x][y] = false;
			bz[x][y] = 0;
			x = x + 1;
		}
		x = 0;	
		y = y + 1;
	}
	x = 0, y = 0;

	// wszystkie mb = true
	while (z < 9) {
		while (y < 9) {
			while (x < 9) {
				mb[x][y][z] = true;
				x = x + 1;
			}
			x = 0;
			y = y + 1;
		}
		y = 0;
		z = z + 1;
	}
}