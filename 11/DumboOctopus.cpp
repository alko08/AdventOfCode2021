#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int arr[10][10];
bool arr2[10][10];

void clearMarkers() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr2[i][j] = false;
        }
    }
}

int clearFlash() {
    int total = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if(arr[i][j] > 9) {
                arr[i][j] = 0;
                total += 1;
            }
                
        }
    }
    return total;
}

void recursiveFlash(int i, int j) {
    if (i < 0 or i > 9 or j < 0 or j > 9 or arr2[i][j]) {
        return;
    }
    arr[i][j] += 1;
    if(arr[i][j] > 9) {
        arr2[i][j] = true;
        recursiveFlash(i-1,j-1);
        recursiveFlash(i-1,j);
        recursiveFlash(i-1,j+1);
        recursiveFlash(i,j-1);
        recursiveFlash(i,j+1);
        recursiveFlash(i+1,j-1);
        recursiveFlash(i+1,j);
        recursiveFlash(i+1,j+1);
    }
}

int main() {
    ifstream data;
    data.open("data.txt");
    string text;
    int total = 0;

    for(int i = 0; i < 10; i++) {
        getline(data, text);
        for(int j = 0; j < 10; j++) {
            arr[i][j] = stoi(to_string(text[j])) - 48;
            // cout << arr[i][j] << " ";
        }
        // cout << endl;
    }

    bool sync = false;
    int counter = 0;
    while (!sync) {
        counter++;
        clearMarkers();
        for(int k = 0; k < 10; k++) {
            for(int j = 0; j < 10; j++) {
                arr[k][j] += 1;
                if(arr[k][j] > 9) {
                    recursiveFlash(k,j);
                }
            }
        }

        if(clearFlash() == 100){
            total = counter;
            sync = true;
        }
    }
    
    cout << total << endl;
    
    return 0;
}
