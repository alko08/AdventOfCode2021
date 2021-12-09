#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    ifstream data;
    data.open("data.txt");
    string text;
    int last = 100000;
    int larger = 0;
    int A = 0;
    int Acount = 0;
    int B = 0;
    int Bcount = -1;
    int C = 0;
    int Ccount = -2;

    for (int i = 0 ; i < 2000; i++) {
        data >> text;
        int temp = stoi(text);
        if (Acount >= 0) {
            A += temp;
            Acount++;
        }
        if (Acount == 3) {
            if (A > last)
                larger++;
            last = A;
            Acount = 0;
            A = 0;
        }
        
        if (Bcount >= 0) {
            B += temp;
            Bcount++;
        } else{
            Bcount++;
        }
        if (Bcount == 3) {
            if (B > last)
                larger++;
            last = B;
            Bcount = 0;
            B = 0;
        }

        if (Ccount >= 0) {
            C += temp;
            Ccount++;
        } else{
            Ccount++;
        }
        if (Ccount == 3) {
            if (C > last)
                larger++;
            last = C;
            Ccount = 0;
            C = 0;
        }
    }
    cout << larger;

    return 0;
}
