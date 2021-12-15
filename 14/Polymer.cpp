#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

string arr[100];
char arr2[100];
long long int arr3[100];
long long int arr4[100];

void reset() {
    for (int i = 0; i < 100; i++) {
        arr3[i] = arr4[i];
        arr4[i] = 0;
    }
}

int findPair(string str) {
    for (int i = 0; i < 100; i++) {
        if (str == arr[i]) {
            return i;
        }
    }
    cout << str << " : WARNING!!!!\n";
    return -1;
}

int main() {
    ifstream data;
    data.open("data.txt");
    string first, text, poly;

    char values[10];
    values[0] = 'B';
    values[1] = 'C';
    values[2] = 'F';
    values[3] = 'H';
    values[4] = 'K';
    values[5] = 'N';
    values[6] = 'O';
    values[7] = 'P';
    values[8] = 'S';
    values[9] = 'V';

    long long int result[10];
    for (int i = 0; i < 10; i++) {
        result[i] = 0;
    }

    getline(data, first);
    getline(data, text);

    for (int i = 0; i < 100; i++) {
        getline(data, text, ' ');
        arr[i] = text;
        getline(data, text, ' ');
        getline(data, text);
        arr2[i] = text[0];
        arr3[i] = 0;
        arr4[i] = 0;
    }

    char last = ' ';
    for(int i = 0; i < first.size(); i++) {
        char temp = first[i];
        for (int j = 0; j < 10; j++) {
            if (temp == values[j]) {
                result[j]++;
            }
        }
        poly = last;
        poly += temp;
        arr3[findPair(poly)]++;
        last = temp;
    }

    for (int i = 0; i < 40; i++) {
        for (int j = 0; j < 100; j++) {
            long long int num = arr3[j];
            string one = arr[j], two = "";
            two += arr2[j];
            two += one[1];
            one = one[0];
            one += arr2[j];
            arr4[findPair(one)] += num;
            arr4[findPair(two)] += num;
            for (int k = 0; k < 10; k++) {
                if (arr2[j] == values[k]) {
                    result[k] += num;
                }
            }
        }
        reset();
    }

    /*
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr[i*10 + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr2[i*10 + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr3[i*10 + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << arr4[i*10 + j] << " ";
        }
        cout << endl;
    }

    cout << "-----" << endl;
    for (int i = 0; i < 10; i++) {
        cout << result[i] << " ";
    }
    cout << endl << "-----" << endl; 
    */

    long long int min = 999999999999999, max = 0;
    for (int i = 0; i < 10; i++) {
        long long int temp = result[i];
        if (temp > max)
            max = temp;
        if (temp < min)
            min = temp;
    }
    cout << max << " " << min << endl;
    cout << max - min << endl;
    
    return 0;
}
