#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <math.h>

using namespace std;

const int SIZE = 100;

struct cordinate {
    short int r, c;

    cordinate() {
        r = 0;
        c = 0;
    }
    cordinate(short int a, short int b) {
        r = a;
        c = b;
    }

    void set(short int a, short int b) {
        r = a;
        c = b;
    }
};

struct point {
    cordinate cord;
    short int value;
    int total;
    bool marked;

    point() {
        value = 0;
        total = 0;
        marked = false;
    }
    point(short int a, short int b, short int v) {
        cord.r = a;
        cord.c = b;
        value = v;
        total = 99999999;
        marked = false;
    }
    
    int getR() {
        return cord.r;
    }
    int getC() {
        return cord.c;
    }
};

int main() {
    ifstream data;
    data.open("data.txt");
    string text;
    int path = 0;
    point arr[SIZE][SIZE];
    vector<cordinate> Q;

    for(int i = 0; i < 100; i++) {
        getline(data, text);
        for(int j = 0; j < 100; j++) {
            short int temp = stoi(to_string(text[j])) - 48;
            arr[i][j] = point(i, j, temp);
        }
    }
    ofstream out;
    out.open("FiveByFive.txt");
    for(int i = 0; i < 500; i++) {
        for(int j = 0; j < 500; j++) {
            int temp = arr[i % 100][j % 100].value + int(i / 100) + int(j / 100);
            if (temp > 9)
                temp -= 9;
            out << temp;
        }
        out << endl;
    }

    // cout << endl;
    // for(int i = 0; i < SIZE; i++) {
    //     for(int j = 0; j < SIZE; j++) {
    //         cout << arr[i][j].value << " ";
    //     }
    //     cout << endl;
    // }

    cordinate p;
    Q.push_back(p);
    arr[0][0].total = 0;
    while (not (arr[SIZE-1][SIZE-1].marked or Q.empty())) {
        path = arr[Q[0].r][Q[0].c].total;
        int spot = 0;
        for (int i = 1; i < Q.size(); i++) {
            int temp = arr[Q[i].r][Q[i].c].total;
            if (temp < path) {
                path = temp;
                spot = i;
            }
        }
        arr[Q[spot].r][Q[spot].c].marked = true;
        // cout << arr[0][0].marked << endl;
        point temp2 = arr[Q[spot].r][Q[spot].c];
        Q[spot] = Q[Q.size()-1];
        Q.pop_back();

        int row = temp2.getR(), col = temp2.getC();
        int t = temp2.total;
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i != j and i+j!=0 and row+i >= 0 and row+i < SIZE and 
                col+j >= 0 and col + j < SIZE) {
                    temp2 = arr[row+i][col+j];
                    if (!temp2.marked and t + temp2.value < temp2.total) {
                        arr[row+i][col+j].total = t + arr[row+i][col+j].value;
                        // cout << row+i << ", " << col+j  << ": " << arr[row+i][col+j].total
                        // << "| " << t << ", " << arr[row+i][col+j].value << endl;
                        p.set(row+i,col+j);
                        Q.push_back(p);
                    }  
                }
            }
        }
        // cout << Q.size() << ": " << row << ", " << col << endl;
    }
    // between 810 and 830
    cout << arr[SIZE-1][SIZE-1].total << endl;

    // for(int i = 0; i <= SIZE; i++) {
    //     for(int j = 0; j <= SIZE; j++) {
    //         cout << arr[i][j].total << "|";
    //     }
    //     cout << endl;
    // }
    
    return 0;
}
