#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int arr[100][100];
bool arr2[100][100];

void clearMarkers() {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            arr2[i][j] = false;
        }
    }
}

int recursiveBassin(int i, int j) {
    if(arr[i][j] == 9 or arr2[i][j])
        return 0;
    arr2[i][j] = true;
    int total = 1;
    if(i != 0)
        total += recursiveBassin(i-1,j);
    if(j != 0)
        total += recursiveBassin(i,j-1);
    if(i != 99)
        total += recursiveBassin(i+1,j);
    if(j != 99)
        total += recursiveBassin(i,j+1);
    return total;
}

int main() {
    ifstream data;
    data.open("data.txt");
    string text;
    vector<int> point1, point2;
    int bassins[3];
    int total = 0;

    for(int i = 0; i < 100; i++) {
        getline(data, text);
        for(int j = 0; j < 100; j++) {
            arr[i][j] = stoi(to_string(text[j])) - 48;
        }
    }
    
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            int num = arr[i][j];
            if(not((i != 0 and arr[i-1][j] <= num) or 
            (i != 99 and arr[i+1][j] <= num) or 
            (j != 0 and arr[i][j-1] <= num) or 
            (j != 99 and arr[i][j+1] <= num))) {
                total += num + 1;
                point1.push_back(i);
                point2.push_back(j);
            }
        }
    }

    bassins[0] = 0;
    bassins[1] = 0;
    bassins[2] = 0;
    int min = 0;
    for(int i = 0; i < point1.size(); i++) {
        clearMarkers();
        int temp = recursiveBassin(point1[i], point2[i]);
        // cout << temp << endl;
        if (temp > bassins[min]) {
            bassins[min] = temp;
            if(bassins[2] < bassins[min])
                min = 2;
            if(bassins[1] < bassins[min])
                min = 1;
            if(bassins[0] < bassins[min])
                min = 0;
        }
    }
    cout << total << endl;
    cout << bassins[0] << " " << bassins[1] << " " << bassins[2] << "| " << min << endl;
    cout << bassins[0] * bassins[1] * bassins[2];
    
    return 0;
}
