// TU MA�O CO DZIA�A, JESZCZE NA TO NIE PATRZ
#include <iostream>
#include <windows.h>
#include <cmath>
#include "h3x3.h"
#include "global.h"
using namespace std;
int u[3][3];
bool liz[3][3];
bool koz[3][3];
// m[kol][lin][n]
// koordynat kol,lin mo�e wynosi� n
bool m[3][3][3];

void pytanie2() {
	cout << "0,0 = lewy g�rny r�g\nlewa liczba ro�nie id�c w prawo\nprawa liczba ro�nie id�c w d�\n";
	cout << "jak puste to wpisz 0\n";
	int l = 0, k = 0, n = 0;
	string duze;
	cout << "wpisz wszystkie 9 liczb obok siebie\nzaczyn�jac w lewym g�rnym id�c w prawo, potem spowrotem na lewo i 1 w d�\nwpisuj: ";
	cin >> duze;	
	while (l < 3) {
		while (k < 3) {
			u[k][l] = duze[n] - 48; // CZEMU MUSI BY� -48??????
			n++;
			k++;
		}
		k = 0;
		l++;
	}	
	l = 0, k = 0, n = 0;
	cout << "\ntwoje wej�cie:\n";
	while (l < 3) {
		while (k < 3) {
			cout << u[k][l] << " ";
			n++;
			k++;
		}
		cout << endl;
		k = 0;
		l++;
	}
}
void petla2() {
	short int licznik = 0;
	while ((u[0][0] == 0 || u[0][1] == 0 || u[0][2] == 0 || u[1][0] == 0 || u[1][1] == 0 || u[1][2] == 0 || u[2][0] == 0 || u[2][1] == 0 || u[2][2] == 0) && licznik < 20) {
		rzik2();
		obliczanie2();       
		licznik++;
	}
}
void rzik2() {
	cout << boolalpha;
	short int lin = 0, kol = 0;
	for (short int lin = 0; lin < 3; lin++) {
		for (short int kol = 0; kol < 3; kol++) {
			for (short int n = 0; n < 3; n++) {
				if (u[kol][lin] == n + 1) {
					liz[kol][n] = true;
				}
				
			}
		}
	}
	for (short int kol = 0; kol < 3; kol++) {
		for (short int lin = 0; lin < 3; lin++) {
			for (short int n = 0; n < 3; n++) {
				if (u[kol][lin] == n + 1) {
					koz[lin][n] = true;				
				}
			}
		}
	}	
}
void obliczanie2() {
    for (short int lin = 0; lin < 3; lin++) {
        for (short int kol = 0; kol < 3; kol++) {
            for (short int n = 0; n < 3; n++) {
                m[kol][lin][n] = true;
            }
        }
    }
	// te warunki
    // wykluczanie mo�liwo�ci
	// if liz[kol][n] == true || koz[lin][n] == true
	// to u[kol][lin] != n
	// to m[kol][lin][n] = false
    for (short int lin = 0; lin < 3; lin++) {
        for (short int kol = 0; kol < 3; kol++) {
            for (short int n = 0; n < 3; n++) {
                if (liz[kol][n] == true || koz[lin][n] == true) {
                    m[kol][lin][n] = false;
                }
            }
        }
    }

    // wykluczanie pojedy�czych liczb
    // je�eli m[kol][lin][0] == false && m[kol][lin][1] == false
    // to u[kol][lin] = 2
    // np. m[0][0][n] musi by� false dla wszystkich n opr�cz jednej

}
void debugv2() {
	cout << "linia 0 zawiera 1 ? " << liz[0][0] << endl;
	cout << "linia 0 zawiera 2 ? " << liz[0][1] << endl;
	cout << "linia 0 zawiera 3 ? " << liz[0][2] << endl;
	cout << "linia 1 zawiera 1 ? " << liz[1][0] << endl;
	cout << "linia 1 zawiera 2 ? " << liz[1][1] << endl;
	cout << "linia 1 zawiera 3 ? " << liz[1][2] << endl;
	cout << "linia 2 zawiera 1 ? " << liz[2][0] << endl;
	cout << "linia 2 zawiera 2 ? " << liz[2][1] << endl;
	cout << "linia 2 zawiera 3 ? " << liz[2][2] << endl;

	cout << "kolumna 0 zawiera 1 ? " << koz[0][0] << endl;
	cout << "kolumna 0 zawiera 2 ? " << koz[0][1] << endl;
	cout << "kolumna 0 zawiera 3 ? " << koz[0][2] << endl;
	cout << "kolumna 1 zawiera 1 ? " << koz[1][0] << endl;
	cout << "kolumna 1 zawiera 2 ? " << koz[1][1] << endl;
	cout << "kolumna 1 zawiera 3 ? " << koz[1][2] << endl;
	cout << "kolumna 2 zawiera 1 ? " << koz[2][0] << endl;
	cout << "kolumna 2 zawiera 2 ? " << koz[2][1] << endl;
	cout << "kolumna 2 zawiera 3 ? " << koz[2][2] << endl;

    cout << boolalpha;
    for (short int lin = 0; lin < 3; lin++) {
        for (short int kol = 0; kol < 3; kol++) {
            for (short int n = 0; n < 3; n++) {
                cout << kol << "," << lin << " mo�e by� " << n + 1 << " ? " << m[kol][lin][n] << endl;
            }
        }
    }
}