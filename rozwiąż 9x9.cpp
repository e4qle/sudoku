#include <iostream>
#include <windows.h>
#include <cmath>
#include <string>
#include "h9x9.h"
#include "global.h"
using namespace std;

// mimo �e by�y deklarowane w headerze, trzeba jeszcze raz
int k[9][9];
bool lz[9][9];
bool kz[9][9];
bool bz[9][9];
bool mb[9][9][9];
void odpowiedz();
void los();
void pentla_los();
short int sk = 0, sl = 0, sn = 0;

void rozwiaz9main(){
	wypelnij(); // zbiera dane
    int reset[9][9];
    pentla();
    bool stop = false;
    cout << endl << "tyle da si� wyliczy� bez losowania liczb: ";
    odpowiedz();
    for (int a = 0; a < 9; a++) {
        for (int b = 0; b < 9; b++) {
            reset[b][a] = k[b][a];
        }
    }
    if (!(k[0][0] == 0 || k[0][1] == 0 || k[0][2] == 0 || k[0][3] == 0 || k[0][4] == 0 || k[0][5] == 0 || k[0][6] == 0 || k[0][7] == 0 || k[0][8] == 0 || k[1][0] == 0 || k[1][1] == 0 || k[1][2] == 0 || k[1][3] == 0 || k[1][4] == 0 || k[1][5] == 0 || k[1][6] == 0 || k[1][7] == 0 || k[1][8] == 0|| k[2][0] == 0 || k[2][1] == 0 || k[2][2] == 0 || k[2][3] == 0 || k[2][4] == 0 || k[2][5] == 0 || k[2][6] == 0 || k[2][7] == 0 || k[2][8] == 0|| k[3][0] == 0 || k[3][1] == 0 || k[3][2] == 0 || k[3][3] == 0 || k[3][4] == 0 || k[3][5] == 0 || k[3][6] == 0 || k[3][7] == 0 || k[3][8] == 0|| k[4][0] == 0 || k[4][1] == 0 || k[4][2] == 0 || k[4][3] == 0 || k[4][4] == 0 || k[4][5] == 0 || k[4][6] == 0 || k[4][7] == 0 || k[4][8] == 0|| k[5][0] == 0 || k[5][1] == 0 || k[5][2] == 0 || k[5][3] == 0 || k[5][4] == 0 || k[5][5] == 0 || k[5][6] == 0 || k[5][7] == 0 || k[5][8] == 0|| k[6][0] == 0 || k[6][1] == 0 || k[6][2] == 0 || k[6][3] == 0 || k[6][4] == 0 || k[6][5] == 0 || k[6][6] == 0 || k[6][7] == 0 || k[6][8] == 0|| k[7][0] == 0 || k[7][1] == 0 || k[7][2] == 0 || k[7][3] == 0 || k[7][4] == 0 || k[7][5] == 0 || k[7][6] == 0 || k[7][7] == 0 || k[7][8] == 0|| k[8][0] == 0 || k[8][1] == 0 || k[8][2] == 0 || k[8][3] == 0 || k[8][4] == 0 || k[8][5] == 0 || k[8][6] == 0 || k[8][7] == 0 || k[8][8] == 0)) {
        odpowiedz();
    }
    else {  
        cout << "te liczby wylosowali�my: ";
        pentla_los();
        if (!(k[0][0] == 0 || k[0][1] == 0 || k[0][2] == 0 || k[0][3] == 0 || k[0][4] == 0 || k[0][5] == 0 || k[0][6] == 0 || k[0][7] == 0 || k[0][8] == 0 || k[1][0] == 0 || k[1][1] == 0 || k[1][2] == 0 || k[1][3] == 0 || k[1][4] == 0 || k[1][5] == 0 || k[1][6] == 0 || k[1][7] == 0 || k[1][8] == 0 || k[2][0] == 0 || k[2][1] == 0 || k[2][2] == 0 || k[2][3] == 0 || k[2][4] == 0 || k[2][5] == 0 || k[2][6] == 0 || k[2][7] == 0 || k[2][8] == 0 || k[3][0] == 0 || k[3][1] == 0 || k[3][2] == 0 || k[3][3] == 0 || k[3][4] == 0 || k[3][5] == 0 || k[3][6] == 0 || k[3][7] == 0 || k[3][8] == 0 || k[4][0] == 0 || k[4][1] == 0 || k[4][2] == 0 || k[4][3] == 0 || k[4][4] == 0 || k[4][5] == 0 || k[4][6] == 0 || k[4][7] == 0 || k[4][8] == 0 || k[5][0] == 0 || k[5][1] == 0 || k[5][2] == 0 || k[5][3] == 0 || k[5][4] == 0 || k[5][5] == 0 || k[5][6] == 0 || k[5][7] == 0 || k[5][8] == 0 || k[6][0] == 0 || k[6][1] == 0 || k[6][2] == 0 || k[6][3] == 0 || k[6][4] == 0 || k[6][5] == 0 || k[6][6] == 0 || k[6][7] == 0 || k[6][8] == 0 || k[7][0] == 0 || k[7][1] == 0 || k[7][2] == 0 || k[7][3] == 0 || k[7][4] == 0 || k[7][5] == 0 || k[7][6] == 0 || k[7][7] == 0 || k[7][8] == 0 || k[8][0] == 0 || k[8][1] == 0 || k[8][2] == 0 || k[8][3] == 0 || k[8][4] == 0 || k[8][5] == 0 || k[8][6] == 0 || k[8][7] == 0 || k[8][8] == 0)) {
            odpowiedz();
        }
        else {
            for (int a = 0; a < 9; a++) {
                for (int b = 0; b < 9; b++) {
                    k[b][a] = reset[b][a];
                }
            }
            mb[sk][sl][sn - 1] = false;
            pentla_los();
        }
    } 
}
void pentla_los() {
    bool stop = false;
    for (short int l = 0; l < 9 && stop == false; l++) {
        los();
        pentla();
        if (!(k[0][0] == 0 || k[0][1] == 0 || k[0][2] == 0 || k[0][3] == 0 || k[0][4] == 0 || k[0][5] == 0 || k[0][6] == 0 || k[0][7] == 0 || k[0][8] == 0 || k[1][0] == 0 || k[1][1] == 0 || k[1][2] == 0 || k[1][3] == 0 || k[1][4] == 0 || k[1][5] == 0 || k[1][6] == 0 || k[1][7] == 0 || k[1][8] == 0 || k[2][0] == 0 || k[2][1] == 0 || k[2][2] == 0 || k[2][3] == 0 || k[2][4] == 0 || k[2][5] == 0 || k[2][6] == 0 || k[2][7] == 0 || k[2][8] == 0 || k[3][0] == 0 || k[3][1] == 0 || k[3][2] == 0 || k[3][3] == 0 || k[3][4] == 0 || k[3][5] == 0 || k[3][6] == 0 || k[3][7] == 0 || k[3][8] == 0 || k[4][0] == 0 || k[4][1] == 0 || k[4][2] == 0 || k[4][3] == 0 || k[4][4] == 0 || k[4][5] == 0 || k[4][6] == 0 || k[4][7] == 0 || k[4][8] == 0 || k[5][0] == 0 || k[5][1] == 0 || k[5][2] == 0 || k[5][3] == 0 || k[5][4] == 0 || k[5][5] == 0 || k[5][6] == 0 || k[5][7] == 0 || k[5][8] == 0 || k[6][0] == 0 || k[6][1] == 0 || k[6][2] == 0 || k[6][3] == 0 || k[6][4] == 0 || k[6][5] == 0 || k[6][6] == 0 || k[6][7] == 0 || k[6][8] == 0 || k[7][0] == 0 || k[7][1] == 0 || k[7][2] == 0 || k[7][3] == 0 || k[7][4] == 0 || k[7][5] == 0 || k[7][6] == 0 || k[7][7] == 0 || k[7][8] == 0 || k[8][0] == 0 || k[8][1] == 0 || k[8][2] == 0 || k[8][3] == 0 || k[8][4] == 0 || k[8][5] == 0 || k[8][6] == 0 || k[8][7] == 0 || k[8][8] == 0)) {
            stop = true;
        }
    }
}

void pentla() { // w k�ko robi
    for (short int pentla = 0; pentla < 10; pentla++) {
        spr9(); // sprawdza jakie linie/kolumny/bloki ju� zawieraj� dan� cyfr�
        wykl9(); // sprawdza gdzie ju� jest tylko 1 mo�liwo��
    } // jak to si� robi w k�ko, to mo�na coraz wi�cej wyklucza�    
}
void los() { // losowanie liczby jak nie ma jednego rozwi�zania, tu jeszcze jest sporo roboty
    bool robdalej = true;
    for (sl = 0; sl < 9 && robdalej == true; sl ++) {
        for (sk = 0; sk < 9 && robdalej == true; sk++) {
            if (k[sk][sl] == 0) {
                for (sn = 0; sn < 9 && robdalej == true; sn++) {
                    if (mb[sk][sl][sn] == true) {
                        k[sk][sl] = sn + 1;
                        robdalej = false;
                        cout << "k["<<sk<<"]["<<sl<<"] = " << k[sk][sl] << endl;
                    }
                }
            }
        }
    }
}
void odpowiedz() {
    cout << "\nrozwi�zanie:\n";
    short int x = 0, y = 0;
    for (y = 0; y < 9; y++, cout << endl) {
        for (x = 0; x < 9; x++) {
            cout << k[x][y] << " ";
        }
    }
}
void wypelnij() {
	int x = 0, y = 0, r = 0;
    cout << "sudoku 9x9\nzacznij od lewego g�rnego rogu, id� w prawo\npotem zejd� 1 w d� i znowu zacznij od lewej strony\ni tak dalej\n";
	cout << "wpisuj: ";
	string dlugaodp;
	cin >> dlugaodp;
	while (y < 9) {
	    while (x < 9) {				
		k[x][y] = dlugaodp[r] - 48;
		// pokazywa�o warto�ci zawsze dok�adnie wi�ksze o 48 od prawid�owych
		// chuj wie czemu
		// to twarde -48 i chuj
		x = x + 1;
		r = r + 1;
		}
		x = 0;
		y = y + 1;
	}
    x = 0, y = 0;
	cout << endl << "twoje wej�cie:\n";
	while (y < 9) {
		while (x < 9) {
			cout << k[x][y] << " ";
			x = x + 1;
		}
		cout << endl;
		x = 0;
		y = y + 1;
	}
}
void spr9() { // sprawdza wszystkie
	short int kol = 0, lin = 0, n = 0;
	// jakie liczby s� w jakich liniach
	cout << boolalpha;
    for (short int lin = 0; lin < 9; lin++) {
        for (short int kol = 0; kol < 9; kol++) {
            for (short int n = 0; n < 9; n++) {
				if (k[kol][lin] == n + 1) {
					lz[kol][n] = true;
				}
			}
		}
	}

    // jakie liczby s� w jakich kolumnach
    for (short int lin = 0; lin < 9; lin++) {
		for (short int kol = 0; kol < 9; kol++) {
			for (short int n = 0; n < 9; n++) {
				if (k[kol][lin] == n + 1) {
					kz[lin][n] = true;
				}
			}
		}
	}
	kol = 0, lin = 0, n = 0;

	int bkol = 0, blin = 0, n1 = 0, n2 = 0;
    // wiem �e mo�na for loopami ale jak dzia�a to nie ruszam
    // tyle si� tu nam�czy�em �e boje si� tu cokolwiek zmienia�
    // if it aint broke dont fix it

    // jakie liczby s� w jakich "blokach" (kratka 9x9 jest podzielona na 9 "blok�w" 3x3, w nich liczby te� nie mog� si� powtarza�)
	// blok 0
	while (n < 9) { // w k�ko a� sprawdzimy wszystkie liczby
		while (n1 < 3) { // w k�ko a� sprawdzimy wszystkie linie bloku
			while (n2 < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w linii bloku
				if (k[bkol + n1][blin + n2] == n + 1) {
					// je�eli kratka 3x3, gdzie lewy g�rny r�g to (bkol,blin) zawiera n, to bz[blok][n] = true 
					bz[0][n] = true;
				}
				n2 = n2 + 1;
			}
			n1 = n1 + 1;
			n2 = 0;
		}
		n = n + 1;
		n1 = 0;
	}
	n = 0;

	// blok 1
	bkol = 3, blin = 0, n1 = 0, n2 = 0;
	while (n < 9) { // w k�ko a� sprawdzimy wszystkie liczby
		while (n1 < 3) { // w k�ko a� sprawdzimy wszystkie linie bloku
			while (n2 < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w linii bloku
				if (k[bkol + n1][blin + n2] == n + 1) {
					bz[1][n] = true;
				}
				n2 = n2 + 1;
			}
			n1 = n1 + 1;
			n2 = 0;
		}
		n = n + 1;
		n1 = 0;
	}
	n = 0;

	// blok 2
	bkol = 6, blin = 0, n1 = 0, n2 = 0;
	while (n < 9) { // w k�ko a� sprawdzimy wszystkie liczby
		while (n1 < 3) { // w k�ko a� sprawdzimy wszystkie linie bloku
			while (n2 < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w linii bloku
				if (k[bkol + n1][blin + n2] == n + 1) {
					bz[2][n] = true;
				}
				n2 = n2 + 1;
			}
			n1 = n1 + 1;
			n2 = 0;
		}
		n = n + 1;
		n1 = 0;
	}
	n = 0;

	// blok 3
	bkol = 0, blin = 3, n1 = 0, n2 = 0;
	while (n < 9) { // w k�ko a� sprawdzimy wszystkie liczby
		while (n1 < 3) { // w k�ko a� sprawdzimy wszystkie linie bloku
			while (n2 < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w linii bloku
				if (k[bkol + n1][blin + n2] == n + 1) {
					bz[3][n] = true;
				}
				n2 = n2 + 1;
			}
			n1 = n1 + 1;
			n2 = 0;
		}
		n = n + 1;
		n1 = 0;
	}
	n = 0;

	// blok 4
	bkol = 3, blin = 3, n1 = 0, n2 = 0;
	while (n < 9) { // w k�ko a� sprawdzimy wszystkie liczby
		while (n1 < 3) { // w k�ko a� sprawdzimy wszystkie linie bloku
			while (n2 < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w linii bloku
				if (k[bkol + n1][blin + n2] == n + 1) {
					bz[4][n] = true;
				}
				n2 = n2 + 1;
			}
			n1 = n1 + 1;
			n2 = 0;
		}
		n = n + 1;
		n1 = 0;
	}
	n = 0;

	// blok 5
	bkol = 6, blin = 3, n1 = 0, n2 = 0;
	while (n < 9) { // w k�ko a� sprawdzimy wszystkie liczby
		while (n1 < 3) { // w k�ko a� sprawdzimy wszystkie linie bloku
			while (n2 < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w linii bloku
				if (k[bkol + n1][blin + n2] == n + 1) {
					bz[5][n] = true;
				}
				n2 = n2 + 1;
			}
			n1 = n1 + 1;
			n2 = 0;
		}
		n = n + 1;
		n1 = 0;
	}
	n = 0;

	// blok 6
	bkol = 0, blin = 6, n1 = 0, n2 = 0;
	while (n < 9) { // w k�ko a� sprawdzimy wszystkie liczby
		while (n1 < 3) { // w k�ko a� sprawdzimy wszystkie linie bloku
			while (n2 < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w linii bloku
				if (k[bkol + n1][blin + n2] == n + 1) {
					bz[6][n] = true;
				}
				n2 = n2 + 1;
			}
			n1 = n1 + 1;
			n2 = 0;
		}
		n = n + 1;
		n1 = 0;
	}
	n = 0;

	// blok 7
	bkol = 3, blin = 6, n1 = 0, n2 = 0;
	while (n < 9) { // w k�ko a� sprawdzimy wszystkie liczby
		while (n1 < 3) { // w k�ko a� sprawdzimy wszystkie linie bloku
			while (n2 < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w linii bloku
				if (k[bkol + n1][blin + n2] == n + 1) {
					bz[7][n] = true;
				}
				n2 = n2 + 1;
			}
			n1 = n1 + 1;
			n2 = 0;
		}
		n = n + 1;
		n1 = 0;
	}
	n = 0;

	// blok 8
	bkol = 6, blin = 6, n1 = 0, n2 = 0;
	while (n < 9) { // w k�ko a� sprawdzimy wszystkie liczby
		while (n1 < 3) { // w k�ko a� sprawdzimy wszystkie linie bloku
			while (n2 < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w linii bloku
				if (k[bkol + n1][blin + n2] == n + 1) {
					bz[8][n] = true;
				}
				n2 = n2 + 1;
			}
			n1 = n1 + 1;
			n2 = 0;
		}
		n = n + 1;
		n1 = 0;
	}
	n = 0;
}
void wykl9() {
	// te bloki to niestety trzeba twardo kodowa� ku mojej wiedzy
	int lin = 0, kol = 0, n = 0;
	// n to warto�� operacyjna, liczba wy�wietlona to n+1
    /* debugowo bez blok�w, czy przynajmniej tyle si� zgadza
    for (lin = 0; lin < 9; lin++) {
        for (kol = 0; kol < 9; kol++) {
            for (n = 0; n < 9; n++) {
                if (lz[kol][n] == true || kz[lin][n] == true) {
                    mb[lin][kol][n] = false; // czemu obr�ci�em lin i kol? nie wiem. ale dzia�a.
                }
            }
        }
    }
    */
	/* GDYBYM ZNALAZ� ZALE�NO�� MI�DZY B A LIN I KOL
	while (lin < 9) {
		while (kol < 9) {
			while (n < 9) {
				if (lz[kol][n] == false && kz[lin][n] == false && bz[b][n] == false) {
					mb[kol][lin][n] == true;
				}
				n = n + 1;
			}
			n = 0;
			kol = kol + 1;
		}
		kol = 0;
		lin = lin + 1;
	}
	*/
 
    // mo�na for loopami, ale chuj
	// blok 0	
	while (lin < 3) { // w k�ko a� sprawdzimy wszystkie linie
		while (kol < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w tej linii
			while (n < 9) { // a� sprawdzimy wszysktie liczby dla tej kratki
				if (lz[kol][n] == true || kz[lin][n] == true || bz[0][n] == true) { // jak liczba n jest w linii/kolumnie/bloku, to ta kratka ju� nie mo�e by� n
                    mb[kol][lin][n] = false;
                    //mb[lin][kol][n] = false;
                }
                /* debug
                cout << "lz[" << kol << "][" << n + 1 << "] : " << lz[kol][n] << endl;
                cout << "kz[" << lin << "][" << n + 1 << "] : " << lz[lin][n] << endl;
                cout << "bz[0][" << n + 1 << "] : " << bz[0][n] << endl;
                cout << "mb[" << kol << "][" << lin << "][" << n + 1 << "] : " << mb[kol][lin][n] << endl;
                cout << "==========" << endl;*/
				n = n + 1;
			}
			n = 0;
			kol = kol + 1;
		}
		kol = 0;
		lin = lin + 1;
	}

	// blok 1	
	lin = 0, kol = 3, n = 0;
	while (lin < 3) { // w k�ko a� sprawdzimy wszystkie linie
		while (2 < kol && kol < 6) { // w k�ko a� sprawdzimy wszystkie kolumny w tej linii
			while (n < 9) { // a� sprawdzimy wszysktie liczby dla tej kratki
				if (lz[kol][n] == true || kz[lin][n] == true || bz[1][n] == true) {
                    mb[kol][lin][n] = false;
                    //mb[lin][kol][n] = false;
                }
                /*cout << "lz[" << kol << "][" << n + 1 << "] : " << lz[kol][n] << endl;
                cout << "kz[" << lin << "][" << n + 1 << "] : " << lz[lin][n] << endl;
                cout << "bz[1][" << n + 1 << "] : " << bz[1][n] << endl;
                cout << "mb[" << kol << "][" << lin << "][" << n + 1 << "] : " << mb[kol][lin][n] << endl;
                cout << "==========" << endl;*/
				n = n + 1;
			}
			n = 0;
			kol = kol + 1;
		}
		kol = 3;
		lin = lin + 1;
	}

	// blok 2	
	lin = 0, kol = 6, n = 0;
	while (lin < 3) { // w k�ko a� sprawdzimy wszystkie linie
		while (5 < kol && kol < 9) { // w k�ko a� sprawdzimy wszystkie kolumny w tej linii
			while (n < 9) { // a� sprawdzimy wszysktie liczby dla tej kratki
				if (lz[kol][n] == true || kz[lin][n] == true || bz[2][n] == true) {
                    mb[kol][lin][n] = false;
                    //mb[lin][kol][n] = false;
                }
                /*cout << "lz[" << kol << "][" << n + 1 << "] : " << lz[kol][n] << endl;
                cout << "kz[" << lin << "][" << n + 1 << "] : " << lz[lin][n] << endl;
                cout << "bz[2][" << n + 1 << "] : " << bz[2][n] << endl;
                cout << "mb[" << kol << "][" << lin << "][" << n + 1 << "] : " << mb[kol][lin][n] << endl;
                cout << "==========" << endl;*/
				n = n + 1;
			}
			n = 0;
			kol = kol + 1;
		}
		kol = 6;
		lin = lin + 1;
	}

	// blok 3	
	lin = 3, kol = 0, n = 0;
	while (2 < lin && lin < 6) { // w k�ko a� sprawdzimy wszystkie linie
		while (kol < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w tej linii
			while (n < 9) { // a� sprawdzimy wszysktie liczby dla tej kratki
				if (lz[kol][n] == true || kz[lin][n] == true || bz[3][n] == true) {
                    mb[kol][lin][n] = false;
                    //mb[lin][kol][n] = false;
                }
                /*cout << "lz[" << kol << "][" << n + 1 << "] : " << lz[kol][n] << endl;
                cout << "kz[" << lin << "][" << n + 1 << "] : " << lz[lin][n] << endl;
                cout << "bz[3][" << n + 1 << "] : " << bz[3][n] << endl;
                cout << "mb[" << kol << "][" << lin << "][" << n + 1 << "] : " << mb[kol][lin][n] << endl;
                cout << "==========" << endl;*/
				n = n + 1;
			}
			n = 0;
			kol = kol + 1;
		}
		kol = 0;
		lin = lin + 1;
	}

	// blok 4	
	lin = 3, kol = 3, n = 0;
	while (2 < lin && lin < 6) { // w k�ko a� sprawdzimy wszystkie linie
		while (2 < kol && kol < 6) { // w k�ko a� sprawdzimy wszystkie kolumny w tej linii
			while (n < 9) { // a� sprawdzimy wszysktie liczby dla tej kratki
				if (lz[kol][n] == true || kz[lin][n] == true || bz[4][n] == true) {
                    mb[kol][lin][n] = false;
                    //mb[lin][kol][n] = false;
                }
               /* cout << "lz[" << kol << "][" << n + 1 << "] : " << lz[kol][n] << endl;
                cout << "kz[" << lin << "][" << n + 1 << "] : " << lz[lin][n] << endl;
                cout << "bz[4][" << n + 1 << "] : " << bz[4][n] << endl;
                cout << "mb[" << kol << "][" << lin << "][" << n + 1 << "] : " << mb[kol][lin][n] << endl;
                cout << "==========" << endl;*/
				n = n + 1;
			}
			n = 0;
			kol = kol + 1;
		}
		kol = 3;
		lin = lin + 1;
	}

	// blok 5	
	lin = 3, kol = 6, n = 0;
	while (2 < lin && lin < 6) { // w k�ko a� sprawdzimy wszystkie linie
		while (5 < kol && kol < 9) { // w k�ko a� sprawdzimy wszystkie kolumny w tej linii
			while (n < 9) { // a� sprawdzimy wszysktie liczby dla tej kratki
				if (lz[kol][n] == true || kz[lin][n] == true || bz[5][n] == true) {
                    mb[kol][lin][n] = false;
                    //mb[lin][kol][n] = false;
                }
              /*  cout << "lz[" << kol << "][" << n + 1 << "] : " << lz[kol][n] << endl;
                cout << "kz[" << lin << "][" << n + 1 << "] : " << lz[lin][n] << endl;
                cout << "bz[5][" << n + 1 << "] : " << bz[5][n] << endl;
                cout << "mb[" << kol << "][" << lin << "][" << n + 1 << "] : " << mb[kol][lin][n] << endl;
                cout << "==========" << endl;*/
				n = n + 1;
			}
			n = 0;
			kol = kol + 1;
		}
		kol = 6;
		lin = lin + 1;
	}

	// blok 6	
	lin = 6, kol = 0, n = 0;
	while (5 < lin && lin < 9) { // w k�ko a� sprawdzimy wszystkie linie
		while (kol < 3) { // w k�ko a� sprawdzimy wszystkie kolumny w tej linii
			while (n < 9) { // a� sprawdzimy wszysktie liczby dla tej kratki
				if (lz[kol][n] == true || kz[lin][n] == true || bz[6][n] == true) {
                    mb[kol][lin][n] = false;
                    //mb[lin][kol][n] = false;
                }
               /* cout << "lz[" << kol << "][" << n + 1 << "] : " << lz[kol][n] << endl;
                cout << "kz[" << lin << "][" << n + 1 << "] : " << lz[lin][n] << endl;
                cout << "bz[6][" << n + 1 << "] : " << bz[6][n] << endl;
                cout << "mb[" << kol << "][" << lin << "][" << n + 1 << "] : " << mb[kol][lin][n] << endl;
                cout << "==========" << endl;*/

				n = n + 1;
			}
			n = 0;
			kol = kol + 1;
		}
		kol = 0;
		lin = lin + 1;
	}

	// blok 7	
	lin = 6, kol = 3, n = 0;
	while (5 < lin && lin < 9) { // w k�ko a� sprawdzimy wszystkie linie
		while (2 < kol && kol < 6) { // w k�ko a� sprawdzimy wszystkie kolumny w tej linii
			while (n < 9) { // a� sprawdzimy wszysktie liczby dla tej kratki
				if (lz[kol][n] == true || kz[lin][n] == true || bz[7][n] == true) {
                    mb[kol][lin][n] = false;
                    //mb[lin][kol][n] = false;
                }
              /*  cout << "lz[" << kol << "][" << n + 1 << "] : " << lz[kol][n] << endl;
                cout << "kz[" << lin << "][" << n + 1 << "] : " << lz[lin][n] << endl;
                cout << "bz[7][" << n + 1 << "] : " << bz[7][n] << endl;
                cout << "mb[" << kol << "][" << lin << "][" << n + 1 << "] : " << mb[kol][lin][n] << endl;
                cout << "==========" << endl;*/
				n = n + 1;
			}
			n = 0;
			kol = kol + 1;
		}
		kol = 3;
		lin = lin + 1;
	}

	// blok 8	
	lin = 6, kol = 6, n = 0;
	while (5 < lin && lin < 9) { // w k�ko a� sprawdzimy wszystkie linie
		while (5 < kol && kol < 9) { // w k�ko a� sprawdzimy wszystkie kolumny w tej linii
			while (n < 9) { // a� sprawdzimy wszysktie liczby dla tej kratki
				if (lz[kol][n] == true || kz[lin][n] == true || bz[8][n] == true) {
                    mb[kol][lin][n] = false;
                    //mb[lin][kol][n] = false;
                }
             /*   cout << "lz[" << kol << "][" << n + 1 << "] : " << lz[kol][n] << endl;
                cout << "kz[" << lin << "][" << n + 1 << "] : " << lz[lin][n] << endl;
                cout << "bz[8][" << n + 1 << "] : " << bz[8][n] << endl;
                cout << "mb[" << kol << "][" << lin << "][" << n + 1 << "] : " << mb[kol][lin][n] << endl;
                cout << "==========" << endl;*/
				n = n + 1;
			}
			n = 0;
			kol = kol + 1;
		}
		kol = 6;
		lin = lin + 1;
	}
    // wykluczanie pojedy�czych liczb
    // je�eli m[kol][lin][0] == false && m[kol][lin][1] == false itd dla wszystkich opr�cz 2
    // to k[kol][lin] = 2
    // np. mb[0][0][n] musi by� false dla wszystkich n opr�cz jednej
    // kiedy� wymy�le jaki� algorytm, p�ki co zrobie tak chujowo
    short int z = 0;
    // z tym z to my�la�em �e co� si� da zrobi� for loopem, ale jednak nie

    for (short int y = 0; y < 9; y++) { // a� sprawdzimy wszystkie linie
        for (short int x = 0; x < 9; x++) { // a� sprawdzimy wszystkie kolumny w danej linii
            if (mb[x][y][z + 0] == true && mb[x][y][z + 1] == false && mb[x][y][z + 2] == false && mb[x][y][z + 3] == false && mb[x][y][z + 4] == false && mb[x][y][z + 5] == false && mb[x][y][z + 6] == false && mb[x][y][z + 7] == false && mb[x][y][z + 8] == false && k[x][y] == 0) {
                // je�eli k[kol][lin] to mo�e by� 1 i nic innego, to jest to 1.    
                // to na ko�cu to po to �eby tylko puste pola wype�nia�
                k[x][y] = 1;
            }
            if (mb[x][y][z + 0] == false && mb[x][y][z + 1] == true && mb[x][y][z + 2] == false && mb[x][y][z + 3] == false && mb[x][y][z + 4] == false && mb[x][y][z + 5] == false && mb[x][y][z + 6] == false && mb[x][y][z + 7] == false && mb[x][y][z + 8] == false && k[x][y] == 0) {
                k[x][y] = 2;
            }
            if (mb[x][y][z + 0] == false && mb[x][y][z + 1] == false && mb[x][y][z + 2] == true && mb[x][y][z + 3] == false && mb[x][y][z + 4] == false && mb[x][y][z + 5] == false && mb[x][y][z + 6] == false && mb[x][y][z + 7] == false && mb[x][y][z + 8] == false && k[x][y] == 0) {
                k[x][y] = 3;
            }
            if (mb[x][y][z + 0] == false && mb[x][y][z + 1] == false && mb[x][y][z + 2] == false && mb[x][y][z + 3] == true && mb[x][y][z + 4] == false && mb[x][y][z + 5] == false && mb[x][y][z + 6] == false && mb[x][y][z + 7] == false && mb[x][y][z + 8] == false && k[x][y] == 0) {
                k[x][y] = 4;
            }
            if (mb[x][y][z + 0] == false && mb[x][y][z + 1] == false && mb[x][y][z + 2] == false && mb[x][y][z + 3] == false && mb[x][y][z + 4] == true && mb[x][y][z + 5] == false && mb[x][y][z + 6] == false && mb[x][y][z + 7] == false && mb[x][y][z + 8] == false && k[x][y] == 0) {
                k[x][y] = 5;
            }
            if (mb[x][y][z + 0] == false && mb[x][y][z + 1] == false && mb[x][y][z + 2] == false && mb[x][y][z + 3] == false && mb[x][y][z + 4] == false && mb[x][y][z + 5] == true && mb[x][y][z + 6] == false && mb[x][y][z + 7] == false && mb[x][y][z + 8] == false && k[x][y] == 0) {
                k[x][y] = 6;
            }
            if (mb[x][y][z + 0] == false && mb[x][y][z + 1] == false && mb[x][y][z + 2] == false && mb[x][y][z + 3] == false && mb[x][y][z + 4] == false && mb[x][y][z + 5] == false && mb[x][y][z + 6] == true && mb[x][y][z + 7] == false && mb[x][y][z + 8] == false && k[x][y] == 0) {
                k[x][y] = 7;
            }
            if (mb[x][y][z + 0] == false && mb[x][y][z + 1] == false && mb[x][y][z + 2] == false && mb[x][y][z + 3] == false && mb[x][y][z + 4] == false && mb[x][y][z + 5] == false && mb[x][y][z + 6] == false && mb[x][y][z + 7] == true && mb[x][y][z + 8] == false && k[x][y] == 0) {
                k[x][y] = 8;
            }
            if (mb[x][y][z + 0] == false && mb[x][y][z + 1] == false && mb[x][y][z + 2] == false && mb[x][y][z + 3] == false && mb[x][y][z + 4] == false && mb[x][y][z + 5] == false && mb[x][y][z + 6] == false && mb[x][y][z + 7] == false && mb[x][y][z + 8] == true && k[x][y] == 0) {
                k[x][y] = 9;
            }
            //cout << x << "," << y << " = " << k[x][y] << endl;
        }
    }
}