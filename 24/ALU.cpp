#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

ifstream data;
string text1, text2, text3;
char vars[4];
long int vals[4], arr[14];

int find(char name) {
    for (int i = 0; i < 4; i++) {
        if (name == vars[i])
            return i;
    }
    return -1;
}

void checkNumber(int input) {
    int one, two;
    getline(data, text1);
    vals[0] = input;
    for (int i = 0; i < 17; i++) {
        getline(data, text1, ' ');
        getline(data, text2, ' ');
        getline(data, text3);

        one = find(text2[0]);
        if (isdigit(text3[0])) {
            two = stoi(text3);
        } else {
            two = vals[find(text3[0])];
        }
        
        if (text1 == "add") {
            vals[one] = vals[one] + two;
        } else if (text1 == "mul") {
            vals[one] = vals[one] * two;
        } else if (text1 == "div") {
            vals[one] = vals[one] / two;
        } else if (text1 == "mod") {
            vals[one] = vals[one] % two;
        } else if (text1 == "eql") {
            vals[one] = vals[one] == two;
        }
    }
}

void reset() {
    for(int i = 0; i < 4; i++) {
        vals[i] = 0;
    }
    vars[0] = 'w';
    vars[1] = 'x';
    vars[2] = 'y';
    vars[3] = 'z';
    data.clear();
    data.seekg(0);
}

bool notZero(long long int num) {
    for (int j = 13; j >= 0; j--) {
        int temp = num % 10;
        if (temp == 0)
            return false;
        arr[j] = temp;
        num = num / 10;
    }
    return true;
}


int main() {
    data.open("data.txt");
    reset();
    // 99997714000000
    long long int max = 0, i = 99999999999999;
    while (max == 0) {
        if (notZero(i)) {
            reset();
            
            for (int j = 0; j < 14; j++) {
                checkNumber(arr[j]);
            }
            if (vals[3] == 0) {
                max = i;
            }
        }
        i--;
        if (i % 1000000 == 0)
            cout << i / 1000000 << " ";
    }

    cout << endl;
    cout << max << endl;
    cout << vals[0] << ", " << vals[1] << ", " << vals[2] << ", " << vals[3] << endl;

    return 0;
}
