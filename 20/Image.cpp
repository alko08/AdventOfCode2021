#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
string key;

char convert(string temp) {
    int total = 0;
    for(int i = 0; i < 9; i++) {
        if (temp[i] == '#') {
            total += pow(2, 8-i);
        }
    }
    return key[total];
}

int main() {
    ifstream data;
    data.open("data.txt");
    string text;
    int count;
    char input[202][202];
    char input2[202][202];

    getline(data, key);
    getline(data, text);
    for (int i = 0; i < 202; i++) {
        for (int j = 0; j < 202; j++) {
            input[i][j] = '.';
        }
    }
    for (int i = 51; i < 151; i++) {
        getline(data, text);
        for (int j = 51; j < 151; j++) {
            input[i][j] = text[j-51];
        }
    }

    for (int k = 0; k < 25; k++) {
        // FIRST ENHANCE
        for (int i = 0; i < 202; i++) {
            for (int j = 0; j < 202; j++) {
                input2[i][j] = '#';
            }
        }
        for (int i = 1; i < 201; i++) {
            for (int j = 1; j < 201; j++) {
                string temp = "";
                temp += input[i-1][j-1];
                temp += input[i-1][j];
                temp += input[i-1][j+1];
                temp += input[i][j-1];
                temp += input[i][j];
                temp += input[i][j+1];
                temp += input[i+1][j-1];
                temp += input[i+1][j];
                temp += input[i+1][j+1];
                input2[i][j] = convert(temp);
            }
        }

        // SECOND ENHANCE
        for (int i = 0; i < 202; i++) {
            for (int j = 0; j < 202; j++) {
                input[i][j] = '.';
            }
        }
        for (int i = 1; i < 201; i++) {
            for (int j = 1; j < 201; j++) {
                string temp = "";
                temp += input2[i-1][j-1];
                temp += input2[i-1][j];
                temp += input2[i-1][j+1];
                temp += input2[i][j-1];
                temp += input2[i][j];
                temp += input2[i][j+1];
                temp += input2[i+1][j-1];
                temp += input2[i+1][j];
                temp += input2[i+1][j+1];
                input[i][j] = convert(temp);
            }
        }
    }

    for (int i = 0; i < 202; i++) {
        for (int j = 0; j < 202; j++) {
            if (input[i][j] == '#')
                count++;
        }
    } 
    cout << count;

    return 0;
}
