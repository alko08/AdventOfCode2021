#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    ifstream data;
    data.open("data.txt");
    string text;
    string arr[10];
    string arr2[4];
    string actual[10];
    
    int total = 0;

    while (not data.eof()) {
        for (int i = 0; i < 10; i++) {
            data >> text;
            arr[i] = text;
            actual[i] = "";
        }
        data >> text;
        for(int i = 0; i < 4; i++) {
            data >> text;
            arr2[i] = text;
        }

        for(int i = 0; i < 10; i++) {
            if(arr[i].size() == 2)
                actual[1] = arr[i];
            else if(arr[i].size() == 3)
                actual[7] = arr[i];
            else if(arr[i].size() == 4)
                actual[4] = arr[i];
            else if(arr[i].size() == 7)
                actual[8] = arr[i];
        }
        for(int i = 0; i < 10; i++) {
            if(arr[i].size() == 5) {
                if(arr[i].find(actual[1][0]) != -1 and arr[i].find(actual[1][1]) != -1) {
                    actual[3] = arr[i];
                }
            }
        }

        for(int i = 0; i < 10; i++) {
            if(arr[i].size() == 6) {
                int j = 0;
                bool nine = true;
                while (j < 4 and nine) {
                    if(arr[i].find(actual[4][j]) == -1)
                        nine = false;
                    j++;
                }
                if (nine)
                    actual[9] = arr[i];
                else {
                    bool six = false;
                    bool zero = false;
                    j = 0;
                    while (j < 5 and !six and !zero) {
                        if(arr[i].find(actual[1][0]) == -1 or arr[i].find(actual[1][1]) == -1)
                            six = true;
                        else
                            zero = true;  
                        j++;
                    }
                    if (six)
                        actual[6] = arr[i];
                    else
                        actual[0] = arr[i];
                }
            }
        }
        for(int i = 0; i < 10; i++) {
            if(arr[i].size() == 5) {
                int j = 0;
                bool two = false;
                while (j < 5 and !two) {
                    if(actual[6].find(arr[i][j]) == -1)
                        two = true;
                    j++;
                }
                if (!two)
                    actual[5] = arr[i];
                else if (actual[3] != arr[i])
                    actual[2] = arr[i];
            }
        }
        string temp = "";
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 10; j++){
                if(arr2[i].size() == actual[j].size()) {
                    bool contain = true;
                    for (int k = 0; k < actual[j].size(); k++){
                        if(arr2[i].find(actual[j][k]) == -1)
                            contain = false;
                    }
                    if (contain)
                        temp += to_string(j);
                    }    
            }
        }
        // cout << total << endl;
        total += stoi(temp);
    }
    cout << total;

    return 0;
}
