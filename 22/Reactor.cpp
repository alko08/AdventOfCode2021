#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

// struct cube {
//     bool arr[2001];
//     cube() {
//         for (int i = 0; i <= 2000; i++) {
//            arr[i] = false;
//         }
//     }
// };

int main() {
    ifstream data;
    data.open("data.txt");
    string text;
    int count = 0;
    bool cubes[1000][1000][1000];

    for (int i = 0; i < 20; i++) {
        int x1, x2, y1, y2, z1, z2;
        getline(data, text, ' ');
        bool on = (text == "on");
        getline(data, text, '.');
        x1 = stoi(text.substr(2));
        getline(data, text, ',');
        x2 = stoi(text.substr(1));
        getline(data, text, '.');
        y1 = stoi(text.substr(2));
        getline(data, text, ',');
        y2 = stoi(text.substr(1));
        getline(data, text, '.');
        z1 = stoi(text.substr(2));
        getline(data, text);
        z2 = stoi(text.substr(1));
        for (int a = x1; a <= x2; a++) {
            for (int b = y1; b <= y2; b++) {
                for (int c = z1; c <= z2; c++) {
                    cubes[a+50][b+50][c+50] = on;
                }
            }
        }
    }

    
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            for (int k = 0; k < 101; k++) {
                if (cubes[i][j][k])
                    count++;
            }
        }
    }
    cout << count;

    return 0;
}
