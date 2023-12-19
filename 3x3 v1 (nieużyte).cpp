// ogólnie to mi się bardzo nie podoba że użyłem tyle copypaste'a, to się na pewno da lepiej, ale nie mam pojęcia jak
#include <iostream>
#include <cmath>
#include "h3x3.h"
#include "global.h"
#include <windows.h> // unistd.h na linuxie czy w przeglądarce
using namespace std;
int s[3][3]; // macierz 3x3 zamiast 9 osobnych intów

/* te pierwsze to znaczą np.a1t1 = a1 to 1, więc jeżeli a1t1 = true, to a1 = 1
* jest to średni sposób na to, ponieważ załóżmy sudoku nxn
* tych booli jest n^3
* jeżeli byśmy zrobili sudoku 9x9, to ich byłoby 729
* chyba nie musze tłumaczyć czemu to źle
*/
bool a1t1, a1t2, a1t3, a2t1, a2t2, a2t3, a3t1, a3t2, a3t3, b1t1, b1t2, b1t3, b2t1, b2t2, b2t3, b3t1, b3t2, b3t3, c1t1, c1t2, c1t3, c2t1, c2t2, c2t3, c3t1, c3t2, c3t3;

/* te drugie to znaczą np. r1m1 = rząd 1 ma 1 = jest liczba 1 w rządzie 1 (k to kolumny)
* tych booli jest 2n^2 = tutaj 18
* w 9x9 byłoby ich 162
* trzeba coś innego wymyślić
*/
bool r1m1, r1m2, r1m3, r2m1, r2m2, r2m3, r3m1, r3m2, r3m3, k1m1, k1m2, k1m3, k2m1, k2m2, k2m3, k3m1, k3m2, k3m3;
void pytanie() {
	/* MACIERZ W C++
	* tworzenie macierzy (w tym przypadku intowej):
	* int macierz[szerokość][wysokość] = {{a1, a2, a3}, {b1, b2, b3}, {c1, c2, c3}}
	*				MÓJ PROGRAM
	*    k0 k1 k2	   k1 k2 k3
	* r0 a0 a1 a2	r1 a1 a2 a3
	* r1 b0 b1 b2	r2 b1 b2 b3
	* r2 c0 c1 c2	r3 c1 c2 c3
	* *w moim programie nazwałem a0 -> a1, a1 -> a2 itd. (1 przesunięty)
	* jak chcemy coś wpisać do niej to:
	* macierz[rząd][kolumna] = liczba;
	*/
	cout << "sudoku 3x3. wypelnij. jezeli niewiadome, wpisz 0.\n|a1 a2 a3|\n|b1 b2 b3|\n|c1 c2 c3|\n";
	cout << "a1 = ";
	cin >> s[0][0];
	cout << "a2 = ";
	cin >> s[0][1];
	cout << "a3 = ";
	cin >> s[0][2];
	cout << "b1 = ";
	cin >> s[1][0];
	cout << "b2 = ";
	cin >> s[1][1];
	cout << "b3 = ";
	cin >> s[1][2];
	cout << "c1 = ";
	cin >> s[2][0];
	cout << "c2 = ";
	cin >> s[2][1];
	cout << "c3 = ";
	cin >> s[2][2];
	cout << "\n==========\nwejscie:\n" << s[0][0] << " " << s[0][1] << " " << s[0][2] << endl;
	cout << s[1][0] << " " << s[1][1] << " " << s[1][2] << endl;
	cout << s[2][0] << " " << s[2][1] << " " << s[2][2] << endl;
}
void debugf() {
	// debug: mówi wszystkie boole z informacją o których liczbach są w każdym rzędzie i kolumnie
	cout << "\npoka debug? ";
	string debug;
	cin >> debug;
	if (debug == "ta") {
		cout << "r1m1, r1m2, itd.\n" << r1m1 << endl << r1m2 << endl << r1m3 << endl << r2m1 << endl << r2m2 << endl << r2m3 << endl << r3m1 << endl << r3m2 << endl << r3m3 << endl << k1m1 << endl << k1m2 << endl << k1m3 << endl << k2m1 << endl << k2m2 << endl << k2m3 << endl << k3m1 << endl << k3m2 << endl << k3m3 << endl;
	}
	if (debug == "ta") {
		cout << "\nspecjalny debug:\nr2m3: " << r2m3 << "\nk1m3: " << k1m3 << "\nb1t3: " << b1t3 << "\nr3m2: " << r3m2 << "\nk3m2: " << k3m2 << "\nc3t2: " << c3t2 << endl;
		cout << endl << "debug: a1t1, a2t2, itd\n" << a1t1 << endl << a1t2 << endl << a1t3 << endl << a2t1 << endl << a2t2 << endl << a2t3 << endl << a3t1 << endl << a3t2 << endl << a3t3 << endl << b1t1 << endl << b1t2 << endl << b1t3 << endl << b2t1 << endl << b2t2 << endl << b2t3 << endl << b3t1 << endl << b3t2 << endl << b3t3 << endl << c1t1 << endl << c1t2 << endl << c1t3 << endl << c2t1 << endl << c2t2 << endl << c2t3 << endl << c3t1 << endl << c3t2 << endl << c3t3 << "\n==========\n";
	}
}
void rzik() {
	// zakładamy że niczego nie ma w żadnym rzędzie, chyba że później to zmienimy tymi ifami
	r1m1 = r1m2 = r1m3 = r2m1 = r2m2 = r2m3 = r3m1 = r3m2 = r3m3 = k1m1 = k1m2 = k1m3 = k2m1 = k2m2 = k2m3 = k3m1 = k3m2 = k3m3 = false;
	// które liczby już są w rzędzie 1 (0)
	if (s[0][0] == 1 || s[0][1] == 1 || s[0][2] == 1) { // jeżeli a1 ALBO a2 ALBO a3 są równe 1, to jest jedynka w rzędzie 1
		r1m1 = true;
	}
	if (s[0][0] == 2 || s[0][1] == 2 || s[0][2] == 2) { // jeżeli a1 ALBO a2 ALBO a3 są równe 2, to jest dwójka w rzędzie 1
		r1m2 = true;
	}
	if (s[0][0] == 3 || s[0][1] == 3 || s[0][2] == 3) { // jeżeli a1 ALBO a2 ALBO a3 są równe 3, to jest trójka w rzędzie 1
		r1m3 = true;
	}

	// które liczby już są w rzędzie 2 (1)
	if (s[1][0] == 1 || s[1][1] == 1 || s[1][2] == 1) {
		r2m1 = true;
	}
	if (s[1][0] == 2 || s[1][1] == 2 || s[1][2] == 2) {
		r2m2 = true;
	}
	if (s[1][0] == 3 || s[1][1] == 3 || s[1][2] == 3) {
		r2m3 = true;
	}

	// które liczby już są w rzędzie 3 (2)
	if (s[2][0] == 1 || s[2][1] == 1 || s[2][2] == 1) {
		r3m1 = true;
	}
	if (s[2][0] == 2 || s[2][1] == 2 || s[2][2] == 2) {
		r3m2 = true;
	}
	if (s[2][0] == 3 || s[2][1] == 3 || s[2][2] == 3) {
		r3m3 = true;
	}

	// które liczby już są w kolumnie 1 (0)
	if (s[0][0] == 1 || s[1][0] == 1 || s[2][0] == 1) {
		k1m1 = true;
	}
	if (s[0][0] == 2 || s[1][0] == 2 || s[2][0] == 2) {
		k1m2 = true;
	}
	if (s[0][0] == 3 || s[1][0] == 3 || s[2][0] == 3) {
		k1m3 = true;
	}

	// które liczby już są w kolumnie 2 (1)
	if (s[0][1] == 1 || s[1][1] == 1 || s[2][1] == 1) {
		k2m1 = true;
	}
	if (s[0][1] == 2 || s[1][1] == 2 || s[2][1] == 2) {
		k2m2 = true;
	}
	if (s[0][1] == 3 || s[1][1] == 3 || s[2][1] == 3) {
		k2m3 = true;
	}

	// które liczby już są w kolumnie 3 (2)
	if (s[0][2] == 1 || s[1][2] == 1 || s[2][2] == 1) {
		k3m1 = true;
	}
	if (s[0][2] == 2 || s[1][2] == 2 || s[2][2] == 2) {
		k3m2 = true;
	}
	if (s[0][2] == 3 || s[1][2] == 3 || s[2][2] == 3) {
		k3m3 = true;
	}
}
void obliczanie() {
	a1t1 = a1t2 = a1t3 = a2t1 = a2t2 = a2t3 = a3t1 = a3t2 = a3t3 = b1t1 = b1t2 = b1t3 = b2t1 = b2t2 = b2t3 = b3t1 = b3t2 = b3t3 = c1t1 = c1t2 = c1t3 = c2t1 = c2t2 = c2t3 = c3t1 = c3t2 = c3t3 = true;
	// nie będę milion razy tego samego wyjaśniał, wszystko wyjaśnie raz, to wszystko jest ten sam kod, po prostu z innymi wartościami

	// czym jest a1
	if (r1m1 == true || k1m1 == true) { // jak jest 1 w rzędzie 1, albo w kolumnie 1, to a1 nie jest = 1
		a1t1 = false;
	}
	if (r1m2 == true || k1m2 == true) { // jak jest 2 w rzędzie 1, albo w kolumnie 1, to a1 nie jest = 2
		a1t2 = false;
	}
	if (r1m3 == true || k1m3 == true) { // jak jest 3 w rzędzie 1, albo w kolumnie 1, to a1 nie jest = 3
		a1t3 = false;
	}

	// jeżeli ustaliliśmy że nie ma jedynki w rzędzie 1 ani w kolumnie 1, to a1 na pewno jest równe 1
	if (a1t1 == true && a1t2 == false && a1t3 == false && s[0][0] == 0) { // jeżeli a1 jest dane, czyli nierówne 0, to nie można zmienić
		s[0][0] = 1;
	}

	// jeżeli ustaliliśmy że nie ma dwójki w rzędzie 1 ani w kolumnie 1, to a1 na pewno jest równe 2
	if (a1t2 == true && a1t1 == false && a1t3 == false && s[0][0] == 0) {
		s[0][0] = 2;
	}

	// jeżeli ustaliliśmy że nie ma trójki w rzędzie 1 ani w kolumnie 1, to a1 na pewno jest równe 3
	if (a1t3 == true && a1t2 == false && a1t1 == false && s[0][0] == 0) {
		s[0][0] = 3;
	}
	// problem jest w tym że jeżeli jest rząd/kolumna z 2 wolnymi miejscami, to z czego wiemy są 2 możliwe odpowiedzi dla tej kratki
	// po prostu puścimy to co nam wyszło z tego kodu jeszcze raz przez rzik() i obliczanie(), i wtedy na pewno danych starczy

	// czym jest a2
	if (r1m1 == true || k2m1 == true) {
		a2t1 = false;
	}
	if (r1m2 == true || k2m2 == true) {
		a2t2 = false;
	}
	if (r1m3 == true || k2m3 == true) {
		a2t3 = false;
	}
	if (a2t1 == true && a2t2 == false && a2t3 == false && s[0][1] == 0) {
		s[0][1] = 1;
	}
	if (a2t2 == true && a2t1 == false && a2t3 == false && s[0][1] == 0) {
		s[0][1] = 2;
	}
	if (a2t3 == true && a2t2 == false && a2t1 == false && s[0][1] == 0) {
		s[0][1] = 3;
	}

	// czym jest a3
	if (r1m1 == true || k3m1 == true) {
		a3t1 = false;
	}
	if (r1m2 == true || k3m2 == true) {
		a3t2 = false;
	}
	if (r1m3 == true || k3m3 == true) {
		a3t3 = false;
	}
	if (a3t1 == true && a3t2 == false && a3t3 == false && s[0][2] == 0) {
		s[0][2] = 1;
	}
	if (a3t2 == true && a3t1 == false && a3t3 == false && s[0][2] == 0) {
		s[0][2] = 2;
	}
	if (a3t3 == true && a3t2 == false && a3t1 == false && s[0][2] == 0) {
		s[0][2] = 3;
	}

	// czym jest b1
	if (r2m1 == true || k1m1 == true) {
		b1t1 = false;
	}
	if (r2m2 == true || k1m2 == true) {
		b1t2 = false;
	}
	if (r2m3 == true || k1m3 == true) {
		b1t3 = false;
	}
	if (b1t1 == true && b1t2 == false && b1t3 == false && s[1][0] == 0) {
		s[1][0] = 1;
	}
	if (b1t2 == true && b1t1 == false && b1t3 == false && s[1][0] == 0) {
		s[1][0] = 2;
	}
	if (b1t3 == true && b1t2 == false && b1t1 == false && s[1][0] == 0) {
		s[1][0] = 3;
	}

	// czym jest b2
	if (r2m1 == true || k2m1 == true) {
		b2t1 = false;
	}
	if (r2m2 == true || k2m2 == true) {
		b2t2 = false;
	}
	if (r2m3 == true || k2m3 == true) {
		b2t3 = false;
	}
	if (b2t1 == true && b2t2 == false && b2t3 == false && s[1][1] == 0) {
		s[1][1] = 1;
	}
	if (b2t2 == true && b2t1 == false && b2t3 == false && s[1][1] == 0) {
		s[1][1] = 2;
	}
	if (b2t3 == true && b2t2 == false && b2t1 == false && s[1][1] == 0) {
		s[1][1] = 3;
	}

	// czym jest b3
	if (r2m1 == true || k3m1 == true) {
		b3t1 = false;
	}
	if (r2m2 == true || k3m2 == true) {
		b3t2 = false;
	}
	if (r2m3 == true || k3m3 == true) {
		b3t3 = false;
	}
	if (b3t1 == true && b3t2 == false && b3t3 == false && s[1][2] == 0) {
		s[1][2] = 1;
	}
	if (b3t2 == true && b3t1 == false && b3t3 == false && s[1][2] == 0) {
		s[1][2] = 2;
	}
	if (b3t3 == true && b3t2 == false && b3t1 == false && s[1][2] == 0) {
		s[1][2] = 3;
	}

	// czym jest c1
	if (r3m1 == true || k1m1 == true) {
		c1t1 = false;
	}
	if (r3m2 == true || k1m2 == true) {
		c1t2 = false;
	}
	if (r3m3 == true || k1m3 == true) {
		c1t3 = false;
	}
	if (c1t1 == true && c1t2 == false && c1t3 == false && s[2][0] == 0) {
		s[2][0] = 1;
	}
	if (c1t2 == true && c1t1 == false && c1t3 == false && s[2][0] == 0) {
		s[2][0] = 2;
	}
	if (c1t3 == true && c1t2 == false && c1t1 == false && s[2][0] == 0) {
		s[2][0] = 3;
	}

	// czym jest c2
	if (r3m1 == true || k2m1 == true) {
		c2t1 = false;
	}
	if (r3m2 == true || k2m2 == true) {
		c2t2 = false;
	}
	if (r3m3 == true || k2m3 == true) {
		c2t3 = false;
	}
	if (c2t1 == true && c2t2 == false && c2t3 == false && s[2][1] == 0) {
		s[2][1] = 1;
	}
	if (c2t2 == true && c2t1 == false && c2t3 == false && s[2][1] == 0) {
		s[2][1] = 2;
	}
	if (c2t3 == true && c2t2 == false && c2t1 == false && s[2][1] == 0) {
		s[2][1] = 3;
	}

	// czym jest c3
	if (r3m1 == true || k3m1 == true) {
		c3t1 = false;
	}
	if (r3m2 == true || k3m2 == true) {
		c3t2 = false;
	}
	if (r3m3 == true || k3m3 == true) {
		c3t3 = false;
	}
	if (c3t1 == true && c3t2 == false && c3t3 == false && s[2][2] == 0) {
		s[2][2] = 1;
	}
	if (c3t2 == true && c3t1 == false && c3t3 == false && s[2][2] == 0) {
		s[2][2] = 2;
	}
	if (c3t3 == true && c3t2 == false && c3t1 == false && s[2][2] == 0) {
		s[2][2] = 3;
	}
}
void strzelanie() {	
	// jeżeli możemy wstawić 1 do a1, to tak zrobimy, jak nie, to idziemy dalej
	// taki bruteforce
	// trzeba inny sposób wymyślić, bo w 9x9 byłoby 81 takich, a nie 9
	if (s[0][0] == 0 && r1m1 == false && k1m1 == false) {
		s[0][0] = 1;
	}
	else if (s[0][0] == 0 && r1m2 == false && k1m2 == false) {
		s[0][0] = 2;
	}
	else if (s[0][0] == 0 && r1m3 == false && k1m3 == false) {
		s[0][0] = 3;
	}

	// a2?
	else if (s[0][1] == 0 && r1m1 == false && k2m1 == false) {
		s[0][1] = 1;
	}
	else if (s[0][1] == 0 && r1m2 == false && k2m2 == false) {
		s[0][1] = 2;
	}
	else if (s[0][1] == 0 && r1m3 == false && k2m3 == false) {
		s[0][1] = 3;
	}

	// a3?
	else if (s[0][2] == 0 && r1m1 == false && k3m1 == false) {
		s[0][2] = 1;
	}
	else if (s[0][2] == 0 && r1m2 == false && k3m2 == false) {
		s[0][2] = 2;
	}
	else if (s[0][2] == 0 && r1m3 == false && k3m3 == false) {
		s[0][2] = 3;
	}

	// b1?
	else if (s[1][0] == 0 && r2m1 == false && k1m1 == false) {
		s[1][0] = 1;
	}
	else if (s[1][0] == 0 && r2m2 == false && k1m2 == false) {
		s[1][0] = 2;
	}
	else if (s[1][0] == 0 && r2m3 == false && k1m3 == false) {
		s[1][0] = 3;
	}

	// b2?
	else if (s[1][1] == 0 && r2m1 == false && k2m1 == false) {
		s[1][1] = 1;
	}
	else if (s[1][1] == 0 && r2m2 == false && k2m2 == false) {
		s[1][1] = 2;
	}
	else if (s[1][1] == 0 && r2m3 == false && k2m3 == false) {
		s[1][1] = 3;
	}

	// b3?
	else if (s[1][2] == 0 && r2m1 == false && k3m1 == false) {
		s[1][2] = 1;
	}
	else if (s[1][2] == 0 && r2m2 == false && k3m2 == false) {
		s[1][2] = 2;
	}
	else if (s[1][2] == 0 && r2m3 == false && k3m3 == false) {
		s[1][2] = 3;
	}

	// c1?
	else if (s[2][0] == 0 && r3m1 == false && k1m1 == false) {
		s[2][0] = 1;
	}
	else if (s[2][0] == 0 && r3m2 == false && k1m2 == false) {
		s[2][0] = 2;
	}
	else if (s[2][0] == 0 && r3m3 == false && k1m3 == false) {
		s[2][0] = 3;
	}

	// c2?
	else if (s[2][1] == 0 && r3m1 == false && k2m1 == false) {
		s[2][1] = 1;
	}
	else if (s[2][1] == 0 && r3m2 == false && k2m2 == false) {
		s[2][1] = 2;
	}
	else if (s[1][1] == 0 && r3m3 == false && k2m3 == false) {
		s[2][1] = 3;
	}

	// c3?
	else if (s[2][2] == 0 && r3m1 == false && k3m1 == false) {
		s[2][2] = 1;
	}
	else if (s[2][2] == 0 && r3m2 == false && k3m2 == false) {
		s[2][2] = 2;
	}
	else if (s[2][2] == 0 && r3m3 == false && k3m3 == false) {
		s[2][2] = 3;
	}
	//to było do debugowania
	//cout << s[0][0] << " " << s[0][1] << " " << s[0][2] << endl << s[1][0] << " " << s[1][1] << " " << s[1][2] << endl << s[2][0] << " " << s[2][1] << " " << s[2][2] << endl;
}
void petla() {
	int licznik = 0;
	while ((s[0][0] == 0 || s[0][1] == 0 || s[0][2] == 0 || s[1][0] == 0 || s[1][1] == 0 || s[1][2] == 0 || s[2][0] == 0 || s[2][1] == 0 || s[2][2] == 0) && licznik < 20) {
		rzik(); // sprawdza czy dana liczba już jest w rzędzie lub kolumnie		
		obliczanie(); /* jeżeli jest, to możemy policzyć część odpowiedzi
		* problem jest w tym, że nie wszystko umie za pierwszym razem wyliczyć
		* otrzymujemy:
		* 2 1 3
		* 1 0 2
		* 3 0 1
		* program miał za dużo niewiadomych żeby policzyć b2 i c2
		* więc robimy wszystko jeszcze raz, z danymi dodadkowymi które właśnie wyliczyliśmy, i mamy wszystko
		* otrzymujemy:
		* 2 1 3
		* 1 3 2
		* 3 2 1
		* jeżeli jeszcze za mało, to powtarzamy aż nie będzie zer
		*/
		licznik = licznik + 1;		
	}
}
void zrobprzyklad() {
	s[0][0] = s[0][1] = s[0][2] = s[1][0] = s[1][1] = s[1][2] = s[2][0] = s[2][1] = s[2][2] = 0;
	srand(time(NULL));
	int rng[4][3];
	/* rząd 1: losowe liczby
	* rząd 2: ich lokalizacja x
	* rząd 3: ich lokalizacja y
	*/
	rng[0][0] = 1 /*rand() % 3 + 1*/; //wartosc 1
	rng[1][0] = rand() % 3; //y1
	rng[2][0] = rand() % 3; //x1

	rng[0][1] = 2 /*rand() % 3 + 1*/; //wartosc 2
	rng[1][1] = rand() % 3; //y2
	rng[2][1] = rand() % 3; //x2

	rng[0][2] = 3 /*rand() % 3 + 1 */; // wartosc 3
	//jeżeli x1=x2 ALBO y1=y2 to
	//x3 = x1 ALBO x3 = x2 ALBO y3 = y1 ALBO y3 = y2
	//bo jak tak nie jest to jest nierozwiązywalne
	int newrng;
	if (rng[2][0] == rng[2][1] || rng[1][0] == rng[1][1]) {
		newrng = rand() % 4 + 1;
		if (newrng == 1) {
			rng[2][2] = rng[2][0]; // x3 = x1
			rng[1][2] = rand() % 3 + 1; //y3
		}
		if (newrng == 2) {
			rng[2][2] = rng[2][1]; // x3 = x2
			rng[1][2] = rand() % 3 + 1;//y3
		}
		if (newrng == 3) {
			rng[1][2] = rng[1][0]; // y3 = y1
			rng[2][2] = rand() % 3 + 1;//x3
		}
		if (newrng == 4) {
			rng[1][2] = rng[1][1]; // y3 = y2
			rng[2][2] = rand() % 3 + 1;//x3
		}
	}
	else { // jeżeli nie są obok siebie, to losujemy normalnie
		rng[1][2] = rand() % 3; //y3
		rng[2][2] = rand() % 3; //x3
	}

	rng[0][3] = rand() % 3 + 1; /*rand() % 3 + 1*/; //wartosc 4
	//4 to wartość powtarzająca się, więc nie może być w tej samej linii co ta sama wartość
	while(rng[1][3] == rng[1][(rng[0][3]) - 1] || rng[2][3] == rng[2][(rng[0][3]) - 1]) {
		rng[1][3] = rand() % 3; //y4
		rng[2][3] = rand() % 3; //x4
	}
	cout << "\n=========\ntwoj przyklad:\n";
	int n = 0;
	while (n < 4) {
		s[rng[1][n]][rng[2][n]] = rng[0][n]; // ???????
		// W PRZEGLĄDARCE DZIAŁA
		n = n + 1;
	}
	cout << s[0][0] << " " << s[0][1] << " " << s[0][2] << endl << s[1][0] << " " << s[1][1] << " " << s[1][2] << endl << s[2][0] << " " << s[2][1] << " " << s[2][2] << endl;
	/* BEZ SENSU ODPOWIADAĆ, TO WYKOMENTOWAŁEM
	cout << "\nodpowiedz:\na1 a2 a3\nb1 b2 b3\nc1 c2 c3\n";
	int odp[3][3];
	cout << "a1 = ";
	cin >> odp[0][0];
	cout << "a2 = ";
	cin >> odp[0][1];
	cout << "a3 = ";
	cin >> odp[0][2];
	cout << "b1 = ";
	cin >> odp[1][0];
	cout << "b2 = ";
	cin >> odp[1][1];
	cout << "b3 = ";
	cin >> odp[1][2];
	cout << "c1 = ";
	cin >> odp[2][0];
	cout << "c2 = ";
	cin >> odp[2][1];
	cout << "c3 = ";
	cin >> odp[2][2];
	cout << "twoja odpowiedz to: \n" << odp[0][0] << " " << odp[0][1] << " " << odp[0][2] << endl << odp[1][0] << " " << odp[1][1] << " " << odp[1][2] << endl << odp[2][0] << " " << odp[2][1] << " " << odp[2][2] << endl << "sam widzisz czy dobrze";
	*/petla();
	if (s[0][0] == 0 || s[0][1] == 0 || s[0][2] == 0 || s[1][0] == 0 || s[1][1] == 0 || s[1][2] == 0 || s[2][0] == 0 || s[2][1] == 0 || s[2][2] == 0) {
		cout << "jest wiele rozwiazan, oto jedna z nich\n"; // jak jest wiele rozwiązań, to ci powie
	}
	else {
		cout << "==========\npoprawna odpowiedz:\n"; // pisze odpowiedzi
	}
	// będzie strzelać 1 liczbę, próbować rozwiązać, i tak w kółko aż będzie rozwiązanie, do 20 razy, po 20 razach już i tak nic to nie da, zły przykład
	int l = 0;
	if (s[0][0] == 0 || s[0][1] == 0 || s[0][2] == 0 || s[1][0] == 0 || s[1][1] == 0 || s[1][2] == 0 || s[2][0] == 0 || s[2][1] == 0 || s[2][2] == 0) {
		while ((s[0][0] == 0 || s[0][1] == 0 || s[0][2] == 0 || s[1][0] == 0 || s[1][1] == 0 || s[1][2] == 0 || s[2][0] == 0 || s[2][1] == 0 || s[2][2] == 0)&&l<20) {
			strzelanie();
			petla();
			l = l + 1;
		}
		cout << s[0][0] << " " << s[0][1] << " " << s[0][2] << endl << s[1][0] << " " << s[1][1] << " " << s[1][2] << endl << s[2][0] << " " << s[2][1] << " " << s[2][2] << "\n==========\n";
	}
	else {
		cout << s[0][0] << " " << s[0][1] << " " << s[0][2] << endl << s[1][0] << " " << s[1][1] << " " << s[1][2] << endl << s[2][0] << " " << s[2][1] << " " << s[2][2] << "\n==========\n";
	}
}
void main3x3()
{
	cout << "przyklad czy rozwiazac?\nwpisz 1 albo 2: ";
	string wybor;
	cin >> wybor;
	if (wybor == "2") { // rozwiązuje za ciebie
		pytanie(); // pyta o dane
		/* np.
		* 2 0 3
		* 1 0 0
		* 0 0 1
		*/
		petla(); // zobacz sobie co to jest, nie pytaj czemu to jest funkcja
		/* po jakimś czasie wyraźnie wiadomo czy jest wiele rozwiązań
		* jakimś czasie = 20 powtórzeń kodu
		* wtedy wstawimy gdzieś losową liczbę, i zobaczymy czy będzie się dało rozwiązać
		* jeżeli nie, to wstawiamy aż będzie się dało
		*/
		if (s[0][0] == 0 || s[0][1] == 0 || s[0][2] == 0 || s[1][0] == 0 || s[1][1] == 0 || s[1][2] == 0 || s[2][0] == 0 || s[2][1] == 0 || s[2][2] == 0) {
			cout << "\njest wiele rozwiazan\n"; // jak jest wiele rozwiązań, to ci powie
		}
		// będzie strzelać 1 liczbę, próbować rozwiązać, i tak w kółko aż będzie rozwiązanie
		while (s[0][0] == 0 || s[0][1] == 0 || s[0][2] == 0 || s[1][0] == 0 || s[1][1] == 0 || s[1][2] == 0 || s[2][0] == 0 || s[2][1] == 0 || s[2][2] == 0) {
			strzelanie();
			petla();
		}
		// debugf(); // printuje wszystkie te boole co tam na górze zadeklarowałem, jest to opcjonalne, ale potrzebowałem to do debugowania
		cout << "\n==========\nodpowiedz:\n"; // pisze odpowiedzi
		cout << s[0][0] << " " << s[0][1] << " " << s[0][2] << endl << s[1][0] << " " << s[1][1] << " " << s[1][2] << endl << s[2][0] << " " << s[2][1] << " " << s[2][2] << "\n==========\n";
	}
	else if (wybor == "1") {
		zrobprzyklad();
	}
}