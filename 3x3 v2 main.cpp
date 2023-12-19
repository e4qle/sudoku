#include <iostream>
#include <windows.h>
#include <cmath>
#include "h3x3.h"
#include "global.h"
using namespace std;
void v2() {
    int pyt;
    cout << "rozwi¹zaæ czy zaprojektowaæ ci?\nwpisz 1 albo 2: ";
    cin >> pyt;
    if (pyt == 1) {
        pytanie2();
        petla2();
        //debugv2();
    }
    else if (pyt == 2) {
        //zrobprzyklad2();
    }
}