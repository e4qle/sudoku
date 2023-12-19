#include <iostream>
#include <windows.h>
#include <cmath>
#include <locale.h> // potrzebne do tego setlocale
#include "h9x9.h" // wszystkie funkcje i zmienne od 9x9
#include "h3x3.h" // wszystkie funkcje i zmienne od 3x3
#include "global.h" // wszystkie funkcje od mainów
using namespace std;
int main() {
    setlocale(LC_CTYPE, "Polish"); // bez tego nie mo¿na printowaæ polskich liter
	cout << boolalpha;
	int mainwejscie;
	while (true) {
		cout << "3x3 czy 9x9?\nwpisz 1 albo 2: ";
		cin >> mainwejscie;
		if (mainwejscie == 1) {
			//main3x3(); // stary algorytm
            // 3x3 tylko istnieje ¿eby przetestowaæ pomys³y na mniejszej skali, w pewnym sensie ³atwiej to modyfikowaæ
            // ogólnie to nie patrz na to, tam prawie nic nie dzia³a
			v2();
		}
		else if (mainwejscie == 2) {
			main9();
		}
	}
}
