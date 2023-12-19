// 9x9main.cpp
void resetwartosci(); // resetuje wartoœci, powtarzane co cykl

// rozwi¹¿ 9x9.cpp
void rozwiaz9main(); // main tego pliku
void spr9(); // sprawdza czy dana liczba ju¿ jest w danej linii, kolumnie i bloku
void wykl9(); // wyklucza mo¿liwoœci na bazie wyników z spr9()
void wypelnij(); // pyta o dane
void pentla(); // robi w kó³ko spr9 i wykl9 a¿ wszystko wykluczy

// zaprojektuj 9x9.cpp
void zaprojektuj9main(); // jeszcze nie zrobi³em

// MO¯NA BY WPISAÆ WSZÊDZIE n ZAMIAST 9, POZWOLIÆ U¯YTKOWNIKOWI SAM WYBRAÆ ROZMIAR KRATKI
// ALE TO PÓKI CO ZA TRUDNE
// inty dla 9x9
// extern int w[9][9]; // wejœcie (tylko zaprojektuj)
extern int k[9][9]; // kratka operacyjna

// czy linia x zawiera liczbê y
// liczymy od 0
// linie od 0 do 8
// a np je¿eli jest 1 w rzêdzie 1 to piszemy:
// lz[0][0] = true
// to to samo co
// r1m1 = true
// jest to lekko mózgojebne ale tak to dzia³a
extern bool lz[9][9];

// czy kolumna x zawiera liczbê y
// ta sama teoria co powy¿ej
// kz[0][0] = k1m1
extern bool kz[9][9];

// blok = taka kratka 3x3, w kratce 9x9 jest ich 9, w takim bloku liczby nie mog¹ siê powtarzaæ
// czy blok x zawiera liczbê y
// bloki:
// 0 1 2
// 3 4 5
// 6 7 8
extern bool bz[9][9];

// ARRAY 3D
// pierwsza liczba = szerokoœæ, czyli pozycja na linii (0 po lewo id¹ce w prawo), czyli która kolumna
// druga liczba = wysokoœæ, czyli wysokoœæ na kolumnie (0 na górze id¹ce w dó³), czyli która linia
// trzecia liczba = (cyferka w kratce - 1)
// mb[1][2][3] = true: 2 od lewej, 3 od górnej mo¿e wynosiæ 4
extern bool mb[9][9][9];

// debug.cpp
void debugwykluczone();
void debugmb();



