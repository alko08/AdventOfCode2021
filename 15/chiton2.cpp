#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <math.h>

using namespace std;

struct cordinate {
    short int r, c, v, pr, pc;
    bool marked, fresh;

    cordinate() {
        r = 0;
        c = 0;
        pr = 0;
        pc = 0;
        v = 0;
        marked = false;
        fresh = true;
    }
    cordinate(short int a, short int b, short int val) {
        r = a;
        c = b;
        pr = 0;
        pc = 0;
        v = val;
        marked = false;
        fresh = true;
    }

    void set(short int a, short int b) {
        pr = a;
        pc = b;
        fresh = false;
    }
};

const int SIZE = 500;
cordinate arr[SIZE][SIZE];

long long int findPath (cordinate c) {
    if (c.fresh)
        return 999999999;
    long long int path = 0;
    while (c.v != 0) {
        path += c.v;
        c = arr[c.pr][c.pc];
    }
    return path;
}

int main() {
    ifstream data;
    data.open("FiveByFive.txt");
    string text;
    long long int path = 0;
    vector<cordinate> Q;

    for(int i = 0; i < 500; i++) {
        getline(data, text);
        for(int j = 0; j < 500; j++) {
            short int temp = stoi(to_string(text[j])) - 48;
            arr[i][j] = cordinate(i, j, temp);
        }
    }
    arr[0][0].v = 0;
    arr[0][0].set(0, 0);

    Q.push_back(arr[0][0]);
    while (not (arr[SIZE-1][SIZE-1].marked or Q.empty())) {
        path = findPath(Q[0]);
        int spot = 0;
        for (int i = 1; i < Q.size(); i++) {
            long long int temp = findPath(Q[i]);
            if (temp < path) {
                path = temp;
                spot = i;
            }
        }
        arr[Q[spot].r][Q[spot].c].marked = true;
        cordinate temp2 = arr[Q[spot].r][Q[spot].c];
        Q[spot] = Q[Q.size()-1];
        Q.pop_back();

        int row = temp2.r, col = temp2.c;
        int t = findPath(temp2);
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                if (i != j and i+j!=0 and row+i >= 0 and row+i < SIZE and 
                col+j >= 0 and col + j < SIZE) {
                    temp2 = arr[row+i][col+j];
                    if (!temp2.marked and t + temp2.v < findPath(temp2)) {
                        arr[row+i][col+j].set(row, col);
                        Q.push_back(arr[row+i][col+j]);
                    }  
                }
            }
        }
        // cout << Q.size() << " ";
    }

    cout <<  endl << findPath(arr[SIZE-1][SIZE-1]) << endl;
    
    return 0;
}
