#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    ifstream data;
    data.open("data.txt");
    string text;

    int **arr = new int*[1000]; 
    for (int i = 0 ; i < 1000 ; i++) {
        arr[i] = new int[1000]; 
        for (int j = 0; j < 1000; j++){
            arr[i][j] = 0;
        }
    }

    while (not data.eof()) {
        int x1, y1, x2, y2;

        getline(data, text, ',' );
        x1 = stoi(text);

        getline(data, text, ' ' );
        y1 = stoi(text);

        getline(data, text, ' ' );
        getline(data, text, ',' );
        x2 = stoi(text);

        getline(data, text);
        y2 = stoi(text);

        if (x1 == x2) {
            if (y1 > y2) {
                int temp = y1;
                y1 = y2;
                y2 = temp;
            }
            for(int i = y1; i <= y2; i++) {
                arr[x1][i] = arr[x1][i] + 1;
            }
        } else if (y1 == y2) {
            if (x1 > x2) {
                int temp = x1;
                x1 = x2;
                x2 = temp;
            }
            for(int i = x1; i <= x2; i++) {
                arr[i][y1] = arr[i][y1] + 1;
            }
        } else if ((x1 - x2 < 0 and y1 - y2 < 0) or (x1 - x2 > 0 and y1 - y2 > 0)) {
            if (x1 - x2 > 0) {
                int temp = x1;
                x1 = x2;
                x2 = temp;
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
            for(int  i = x1; i <= x2; i++) {
                arr[i][y1] = arr[i][y1] + 1;
                y1++;
            }
        } else {
            if (x1 - x2 > 0) {
                int temp = x1;
                x1 = x2;
                x2 = temp;
                temp = y1;
                y1 = y2;
                y2 = temp;
            }
            for(int  i = x1; i <= x2; i++) {
                arr[i][y1] = arr[i][y1] + 1;
                y1--;
            }
        }
    }

    int out = 0;
    for(int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (arr[i][j] > 1) {
                out++;
            }
        }
    }
    cout << out << endl;

    return 0;
}
