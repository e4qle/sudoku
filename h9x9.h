// 9x9main.cpp
void resetwartosci(); // resetuje warto�ci, powtarzane co cykl

// rozwi�� 9x9.cpp
void rozwiaz9main(); // main tego pliku
void spr9(); // sprawdza czy dana liczba ju� jest w danej linii, kolumnie i bloku
void wykl9(); // wyklucza mo�liwo�ci na bazie wynik�w z spr9()
void wypelnij(); // pyta o dane
void pentla(); // robi w k�ko spr9 i wykl9 a� wszystko wykluczy

// zaprojektuj 9x9.cpp
void zaprojektuj9main(); // jeszcze nie zrobi�em

// MO�NA BY WPISA� WSZ�DZIE n ZAMIAST 9, POZWOLI� U�YTKOWNIKOWI SAM WYBRA� ROZMIAR KRATKI
// ALE TO P�KI CO ZA TRUDNE
// inty dla 9x9
// extern int w[9][9]; // wej�cie (tylko zaprojektuj)
extern int k[9][9]; // kratka operacyjna

// czy linia x zawiera liczb� y
// liczymy od 0
// linie od 0 do 8
// a np je�eli jest 1 w rz�dzie 1 to piszemy:
// lz[0][0] = true
// to to samo co
// r1m1 = true
// jest to lekko m�zgojebne ale tak to dzia�a
extern bool lz[9][9];

// czy kolumna x zawiera liczb� y
// ta sama teoria co powy�ej
// kz[0][0] = k1m1
extern bool kz[9][9];

// blok = taka kratka 3x3, w kratce 9x9 jest ich 9, w takim bloku liczby nie mog� si� powtarza�
// czy blok x zawiera liczb� y
// bloki:
// 0 1 2
// 3 4 5
// 6 7 8
extern bool bz[9][9];

// ARRAY 3D
// pierwsza liczba = szeroko��, czyli pozycja na linii (0 po lewo id�ce w prawo), czyli kt�ra kolumna
// druga liczba = wysoko��, czyli wysoko�� na kolumnie (0 na g�rze id�ce w d�), czyli kt�ra linia
// trzecia liczba = (cyferka w kratce - 1)
// mb[1][2][3] = true: 2 od lewej, 3 od g�rnej mo�e wynosi� 4
extern bool mb[9][9][9];

// debug.cpp
void debugwykluczone();
void debugmb();



