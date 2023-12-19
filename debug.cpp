#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
#include "h9x9.h"
#include "global.h"
using namespace std;
void debugwykluczone() {
	cout << boolalpha;
    // wiem ¿e to siê da for loopami, ale wtedy tego nie wiedzia³em, teraz ju¿ niech tak bêdzie
	cout << "linia 0 zawiera 1 ? " << lz[0][0] << endl;
	cout << "linia 0 zawiera 2 ? " << lz[0][1] << endl;
	cout << "linia 0 zawiera 3 ? " << lz[0][2] << endl;
	cout << "linia 0 zawiera 4 ? " << lz[0][3] << endl;
	cout << "linia 0 zawiera 5 ? " << lz[0][4] << endl;
	cout << "linia 0 zawiera 6 ? " << lz[0][5] << endl;
	cout << "linia 0 zawiera 7 ? " << lz[0][6] << endl;
	cout << "linia 0 zawiera 8 ? " << lz[0][7] << endl;
	cout << "linia 0 zawiera 9 ? " << lz[0][8] << endl;

	cout << "linia 1 zawiera 1 ? " << lz[1][0] << endl;
	cout << "linia 1 zawiera 2 ? " << lz[1][1] << endl;
	cout << "linia 1 zawiera 3 ? " << lz[1][2] << endl;
	cout << "linia 1 zawiera 4 ? " << lz[1][3] << endl;
	cout << "linia 1 zawiera 5 ? " << lz[1][4] << endl;
	cout << "linia 1 zawiera 6 ? " << lz[1][5] << endl;
	cout << "linia 1 zawiera 7 ? " << lz[1][6] << endl;
	cout << "linia 1 zawiera 8 ? " << lz[1][7] << endl;
	cout << "linia 1 zawiera 9 ? " << lz[1][8] << endl;

	cout << "linia 2 zawiera 1 ? " << lz[2][0] << endl;
	cout << "linia 2 zawiera 2 ? " << lz[2][1] << endl;
	cout << "linia 2 zawiera 3 ? " << lz[2][2] << endl;
	cout << "linia 2 zawiera 4 ? " << lz[2][3] << endl;
	cout << "linia 2 zawiera 5 ? " << lz[2][4] << endl;
	cout << "linia 2 zawiera 6 ? " << lz[2][5] << endl;
	cout << "linia 2 zawiera 7 ? " << lz[2][6] << endl;
	cout << "linia 2 zawiera 8 ? " << lz[2][7] << endl;
	cout << "linia 2 zawiera 9 ? " << lz[2][8] << endl;

	cout << "linia 3 zawiera 1 ? " << lz[3][0] << endl;
	cout << "linia 3 zawiera 2 ? " << lz[3][1] << endl;
	cout << "linia 3 zawiera 3 ? " << lz[3][2] << endl;
	cout << "linia 3 zawiera 4 ? " << lz[3][3] << endl;
	cout << "linia 3 zawiera 5 ? " << lz[3][4] << endl;
	cout << "linia 3 zawiera 6 ? " << lz[3][5] << endl;
	cout << "linia 3 zawiera 7 ? " << lz[3][6] << endl;
	cout << "linia 3 zawiera 8 ? " << lz[3][7] << endl;
	cout << "linia 3 zawiera 9 ? " << lz[3][8] << endl;

	cout << "linia 4 zawiera 1 ? " << lz[4][0] << endl;
	cout << "linia 4 zawiera 2 ? " << lz[4][1] << endl;
	cout << "linia 4 zawiera 3 ? " << lz[4][2] << endl;
	cout << "linia 4 zawiera 4 ? " << lz[4][3] << endl;
	cout << "linia 4 zawiera 5 ? " << lz[4][4] << endl;
	cout << "linia 4 zawiera 6 ? " << lz[4][5] << endl;
	cout << "linia 4 zawiera 7 ? " << lz[4][6] << endl;
	cout << "linia 4 zawiera 8 ? " << lz[4][7] << endl;
	cout << "linia 4 zawiera 9 ? " << lz[4][8] << endl;

	cout << "linia 5 zawiera 1 ? " << lz[5][0] << endl;
	cout << "linia 5 zawiera 2 ? " << lz[5][1] << endl;
	cout << "linia 5 zawiera 3 ? " << lz[5][2] << endl;
	cout << "linia 5 zawiera 4 ? " << lz[5][3] << endl;
	cout << "linia 5 zawiera 5 ? " << lz[5][4] << endl;
	cout << "linia 5 zawiera 6 ? " << lz[5][5] << endl;
	cout << "linia 5 zawiera 7 ? " << lz[5][6] << endl;
	cout << "linia 5 zawiera 8 ? " << lz[5][7] << endl;
	cout << "linia 5 zawiera 9 ? " << lz[5][8] << endl;

	cout << "linia 6 zawiera 1 ? " << lz[6][0] << endl;
	cout << "linia 6 zawiera 2 ? " << lz[6][1] << endl;
	cout << "linia 6 zawiera 3 ? " << lz[6][2] << endl;
	cout << "linia 6 zawiera 4 ? " << lz[6][3] << endl;
	cout << "linia 6 zawiera 5 ? " << lz[6][4] << endl;
	cout << "linia 6 zawiera 6 ? " << lz[6][5] << endl;
	cout << "linia 6 zawiera 7 ? " << lz[6][6] << endl;
	cout << "linia 6 zawiera 8 ? " << lz[6][7] << endl;
	cout << "linia 6 zawiera 9 ? " << lz[6][8] << endl;

	cout << "linia 7 zawiera 1 ? " << lz[7][0] << endl;
	cout << "linia 7 zawiera 2 ? " << lz[7][1] << endl;
	cout << "linia 7 zawiera 3 ? " << lz[7][2] << endl;
	cout << "linia 7 zawiera 4 ? " << lz[7][3] << endl;
	cout << "linia 7 zawiera 5 ? " << lz[7][4] << endl;
	cout << "linia 7 zawiera 6 ? " << lz[7][5] << endl;
	cout << "linia 7 zawiera 7 ? " << lz[7][6] << endl;
	cout << "linia 7 zawiera 8 ? " << lz[7][7] << endl;
	cout << "linia 7 zawiera 9 ? " << lz[7][8] << endl;

	cout << "linia 8 zawiera 1 ? " << lz[8][0] << endl;
	cout << "linia 8 zawiera 2 ? " << lz[8][1] << endl;
	cout << "linia 8 zawiera 3 ? " << lz[8][2] << endl;
	cout << "linia 8 zawiera 4 ? " << lz[8][3] << endl;
	cout << "linia 8 zawiera 5 ? " << lz[8][4] << endl;
	cout << "linia 8 zawiera 6 ? " << lz[8][5] << endl;
	cout << "linia 8 zawiera 7 ? " << lz[8][6] << endl;
	cout << "linia 8 zawiera 8 ? " << lz[8][7] << endl;
	cout << "linia 8 zawiera 9 ? " << lz[8][8] << endl;

	cout << "kolumna 0 zawiera 1 ? " << kz[0][0] << endl;
	cout << "kolumna 0 zawiera 2 ? " << kz[0][1] << endl;
	cout << "kolumna 0 zawiera 3 ? " << kz[0][2] << endl;
	cout << "kolumna 0 zawiera 4 ? " << kz[0][3] << endl;
	cout << "kolumna 0 zawiera 5 ? " << kz[0][4] << endl;
	cout << "kolumna 0 zawiera 6 ? " << kz[0][5] << endl;
	cout << "kolumna 0 zawiera 7 ? " << kz[0][6] << endl;
	cout << "kolumna 0 zawiera 8 ? " << kz[0][7] << endl;
	cout << "kolumna 0 zawiera 9 ? " << kz[0][8] << endl;

	cout << "kolumna 1 zawiera 1 ? " << kz[1][0] << endl;
	cout << "kolumna 1 zawiera 2 ? " << kz[1][1] << endl;
	cout << "kolumna 1 zawiera 3 ? " << kz[1][2] << endl;
	cout << "kolumna 1 zawiera 4 ? " << kz[1][3] << endl;
	cout << "kolumna 1 zawiera 5 ? " << kz[1][4] << endl;
	cout << "kolumna 1 zawiera 6 ? " << kz[1][5] << endl;
	cout << "kolumna 1 zawiera 7 ? " << kz[1][6] << endl;
	cout << "kolumna 1 zawiera 8 ? " << kz[1][7] << endl;
	cout << "kolumna 1 zawiera 9 ? " << kz[1][8] << endl;

	cout << "kolumna 2 zawiera 1 ? " << kz[2][0] << endl;
	cout << "kolumna 2 zawiera 2 ? " << kz[2][1] << endl;
	cout << "kolumna 2 zawiera 3 ? " << kz[2][2] << endl;
	cout << "kolumna 2 zawiera 4 ? " << kz[2][3] << endl;
	cout << "kolumna 2 zawiera 5 ? " << kz[2][4] << endl;
	cout << "kolumna 2 zawiera 6 ? " << kz[2][5] << endl;
	cout << "kolumna 2 zawiera 7 ? " << kz[2][6] << endl;
	cout << "kolumna 2 zawiera 8 ? " << kz[2][7] << endl;
	cout << "kolumna 2 zawiera 9 ? " << kz[2][8] << endl;

	cout << "kolumna 3 zawiera 1 ? " << kz[3][0] << endl;
	cout << "kolumna 3 zawiera 2 ? " << kz[3][1] << endl;
	cout << "kolumna 3 zawiera 3 ? " << kz[3][2] << endl;
	cout << "kolumna 3 zawiera 4 ? " << kz[3][3] << endl;
	cout << "kolumna 3 zawiera 5 ? " << kz[3][4] << endl;
	cout << "kolumna 3 zawiera 6 ? " << kz[3][5] << endl;
	cout << "kolumna 3 zawiera 7 ? " << kz[3][6] << endl;
	cout << "kolumna 3 zawiera 8 ? " << kz[3][7] << endl;
	cout << "kolumna 3 zawiera 9 ? " << kz[3][8] << endl;

	cout << "kolumna 4 zawiera 1 ? " << kz[4][0] << endl;
	cout << "kolumna 4 zawiera 2 ? " << kz[4][1] << endl;
	cout << "kolumna 4 zawiera 3 ? " << kz[4][2] << endl;
	cout << "kolumna 4 zawiera 4 ? " << kz[4][3] << endl;
	cout << "kolumna 4 zawiera 5 ? " << kz[4][4] << endl;
	cout << "kolumna 4 zawiera 6 ? " << kz[4][5] << endl;
	cout << "kolumna 4 zawiera 7 ? " << kz[4][6] << endl;
	cout << "kolumna 4 zawiera 8 ? " << kz[4][7] << endl;
	cout << "kolumna 4 zawiera 9 ? " << kz[4][8] << endl;

	cout << "kolumna 5 zawiera 1 ? " << kz[5][0] << endl;
	cout << "kolumna 5 zawiera 2 ? " << kz[5][1] << endl;
	cout << "kolumna 5 zawiera 3 ? " << kz[5][2] << endl;
	cout << "kolumna 5 zawiera 4 ? " << kz[5][3] << endl;
	cout << "kolumna 5 zawiera 5 ? " << kz[5][4] << endl;
	cout << "kolumna 5 zawiera 6 ? " << kz[5][5] << endl;
	cout << "kolumna 5 zawiera 7 ? " << kz[5][6] << endl;
	cout << "kolumna 5 zawiera 8 ? " << kz[5][7] << endl;
	cout << "kolumna 5 zawiera 9 ? " << kz[5][8] << endl;

	cout << "kolumna 6 zawiera 1 ? " << kz[6][0] << endl;
	cout << "kolumna 6 zawiera 2 ? " << kz[6][1] << endl;
	cout << "kolumna 6 zawiera 3 ? " << kz[6][2] << endl;
	cout << "kolumna 6 zawiera 4 ? " << kz[6][3] << endl;
	cout << "kolumna 6 zawiera 5 ? " << kz[6][4] << endl;
	cout << "kolumna 6 zawiera 6 ? " << kz[6][5] << endl;
	cout << "kolumna 6 zawiera 7 ? " << kz[6][6] << endl;
	cout << "kolumna 6 zawiera 8 ? " << kz[6][7] << endl;
	cout << "kolumna 6 zawiera 9 ? " << kz[6][8] << endl;

	cout << "kolumna 7 zawiera 1 ? " << kz[7][0] << endl;
	cout << "kolumna 7 zawiera 2 ? " << kz[7][1] << endl;
	cout << "kolumna 7 zawiera 3 ? " << kz[7][2] << endl;
	cout << "kolumna 7 zawiera 4 ? " << kz[7][3] << endl;
	cout << "kolumna 7 zawiera 5 ? " << kz[7][4] << endl;
	cout << "kolumna 7 zawiera 6 ? " << kz[7][5] << endl;
	cout << "kolumna 7 zawiera 7 ? " << kz[7][6] << endl;
	cout << "kolumna 7 zawiera 8 ? " << kz[7][7] << endl;
	cout << "kolumna 7 zawiera 9 ? " << kz[7][8] << endl;

	cout << "kolumna 8 zawiera 1 ? " << kz[8][0] << endl;
	cout << "kolumna 8 zawiera 2 ? " << kz[8][1] << endl;
	cout << "kolumna 8 zawiera 3 ? " << kz[8][2] << endl;
	cout << "kolumna 8 zawiera 4 ? " << kz[8][3] << endl;
	cout << "kolumna 8 zawiera 5 ? " << kz[8][4] << endl;
	cout << "kolumna 8 zawiera 6 ? " << kz[8][5] << endl;
	cout << "kolumna 8 zawiera 7 ? " << kz[8][6] << endl;
	cout << "kolumna 8 zawiera 8 ? " << kz[8][7] << endl;
	cout << "kolumna 8 zawiera 9 ? " << kz[8][8] << endl;

	cout << "blok 0 zawiera 1 ? " << bz[0][0] << endl;
	cout << "blok 0 zawiera 2 ? " << bz[0][1] << endl;
	cout << "blok 0 zawiera 3 ? " << bz[0][2] << endl;
	cout << "blok 0 zawiera 4 ? " << bz[0][3] << endl;
	cout << "blok 0 zawiera 5 ? " << bz[0][4] << endl;
	cout << "blok 0 zawiera 6 ? " << bz[0][5] << endl;
	cout << "blok 0 zawiera 7 ? " << bz[0][6] << endl;
	cout << "blok 0 zawiera 8 ? " << bz[0][7] << endl;
	cout << "blok 0 zawiera 9 ? " << bz[0][8] << endl;

	cout << "blok 1 zawiera 1 ? " << bz[1][0] << endl;
	cout << "blok 1 zawiera 2 ? " << bz[1][1] << endl;
	cout << "blok 1 zawiera 3 ? " << bz[1][2] << endl;
	cout << "blok 1 zawiera 4 ? " << bz[1][3] << endl;
	cout << "blok 1 zawiera 5 ? " << bz[1][4] << endl;
	cout << "blok 1 zawiera 6 ? " << bz[1][5] << endl;
	cout << "blok 1 zawiera 7 ? " << bz[1][6] << endl;
	cout << "blok 1 zawiera 8 ? " << bz[1][7] << endl;
	cout << "blok 1 zawiera 9 ? " << bz[1][8] << endl;

	cout << "blok 2 zawiera 1 ? " << bz[2][0] << endl;
	cout << "blok 2 zawiera 2 ? " << bz[2][1] << endl;
	cout << "blok 2 zawiera 3 ? " << bz[2][2] << endl;
	cout << "blok 2 zawiera 4 ? " << bz[2][3] << endl;
	cout << "blok 2 zawiera 5 ? " << bz[2][4] << endl;
	cout << "blok 2 zawiera 6 ? " << bz[2][5] << endl;
	cout << "blok 2 zawiera 7 ? " << bz[2][6] << endl;
	cout << "blok 2 zawiera 8 ? " << bz[2][7] << endl;
	cout << "blok 2 zawiera 9 ? " << bz[2][8] << endl;

	cout << "blok 3 zawiera 1 ? " << bz[3][0] << endl;
	cout << "blok 3 zawiera 2 ? " << bz[3][1] << endl;
	cout << "blok 3 zawiera 3 ? " << bz[3][2] << endl;
	cout << "blok 3 zawiera 4 ? " << bz[3][3] << endl;
	cout << "blok 3 zawiera 5 ? " << bz[3][4] << endl;
	cout << "blok 3 zawiera 6 ? " << bz[3][5] << endl;
	cout << "blok 3 zawiera 7 ? " << bz[3][6] << endl;
	cout << "blok 3 zawiera 8 ? " << bz[3][7] << endl;
	cout << "blok 3 zawiera 9 ? " << bz[3][8] << endl;

	cout << "blok 4 zawiera 1 ? " << bz[4][0] << endl;
	cout << "blok 4 zawiera 2 ? " << bz[4][1] << endl;
	cout << "blok 4 zawiera 3 ? " << bz[4][2] << endl;
	cout << "blok 4 zawiera 4 ? " << bz[4][3] << endl;
	cout << "blok 4 zawiera 5 ? " << bz[4][4] << endl;
	cout << "blok 4 zawiera 6 ? " << bz[4][5] << endl;
	cout << "blok 4 zawiera 7 ? " << bz[4][6] << endl;
	cout << "blok 4 zawiera 8 ? " << bz[4][7] << endl;
	cout << "blok 4 zawiera 9 ? " << bz[4][8] << endl;

	cout << "blok 5 zawiera 1 ? " << bz[5][0] << endl;
	cout << "blok 5 zawiera 2 ? " << bz[5][1] << endl;
	cout << "blok 5 zawiera 3 ? " << bz[5][2] << endl;
	cout << "blok 5 zawiera 4 ? " << bz[5][3] << endl;
	cout << "blok 5 zawiera 5 ? " << bz[5][4] << endl;
	cout << "blok 5 zawiera 6 ? " << bz[5][5] << endl;
	cout << "blok 5 zawiera 7 ? " << bz[5][6] << endl;
	cout << "blok 5 zawiera 8 ? " << bz[5][7] << endl;
	cout << "blok 5 zawiera 9 ? " << bz[5][8] << endl;

	cout << "blok 6 zawiera 1 ? " << bz[6][0] << endl;
	cout << "blok 6 zawiera 2 ? " << bz[6][1] << endl;
	cout << "blok 6 zawiera 3 ? " << bz[6][2] << endl;
	cout << "blok 6 zawiera 4 ? " << bz[6][3] << endl;
	cout << "blok 6 zawiera 5 ? " << bz[6][4] << endl;
	cout << "blok 6 zawiera 6 ? " << bz[6][5] << endl;
	cout << "blok 6 zawiera 7 ? " << bz[6][6] << endl;
	cout << "blok 6 zawiera 8 ? " << bz[6][7] << endl;
	cout << "blok 6 zawiera 9 ? " << bz[6][8] << endl;

	cout << "blok 7 zawiera 1 ? " << bz[7][0] << endl;
	cout << "blok 7 zawiera 2 ? " << bz[7][1] << endl;
	cout << "blok 7 zawiera 3 ? " << bz[7][2] << endl;
	cout << "blok 7 zawiera 4 ? " << bz[7][3] << endl;
	cout << "blok 7 zawiera 5 ? " << bz[7][4] << endl;
	cout << "blok 7 zawiera 6 ? " << bz[7][5] << endl;
	cout << "blok 7 zawiera 7 ? " << bz[7][6] << endl;
	cout << "blok 7 zawiera 8 ? " << bz[7][7] << endl;
	cout << "blok 7 zawiera 9 ? " << bz[7][8] << endl;

	cout << "blok 8 zawiera 1 ? " << bz[8][0] << endl;
	cout << "blok 8 zawiera 2 ? " << bz[8][1] << endl;
	cout << "blok 8 zawiera 3 ? " << bz[8][2] << endl;
	cout << "blok 8 zawiera 4 ? " << bz[8][3] << endl;
	cout << "blok 8 zawiera 5 ? " << bz[8][4] << endl;
	cout << "blok 8 zawiera 6 ? " << bz[8][5] << endl;
	cout << "blok 8 zawiera 7 ? " << bz[8][6] << endl;
	cout << "blok 8 zawiera 8 ? " << bz[8][7] << endl;
	cout << "blok 8 zawiera 9 ? " << bz[8][8] << endl;

}
void debugmb() {
	// mb[kol][lin][n], sprawdziæ wszystkie mo¿liwoœci
	cout << boolalpha;
	for (short int lin = 0; lin < 9; lin++) {
		for (short int kol = 0; kol < 9; kol++) {
			for (short int n = 0; n < 9; n++) {
                cout << kol << "," << lin << " mo¿e byæ " << n + 1 << "? " << mb[kol][lin][n] << endl;
			}
            cout << "==========\n";
		}
	}
}