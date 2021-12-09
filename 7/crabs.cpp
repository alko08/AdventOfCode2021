#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    ifstream data;
    data.open("data.txt");
    string text;
    int arr[1000];
    int num = 0;
    long long int total = 0;

    while (not data.eof()) {
        getline(data, text, ',' );
        int temp = stoi(text);
        arr[num] = temp;
        num++;
        total += temp;
    }
    cout << total << endl;
    long long int lowest = total*total;
    for(int i = 0; i < 1000; i++) {
        total = 0;
        for(int j = 0; j < 1000; j++) {
            int distance = abs(i-arr[j]);
            long long int count = 0;
            while(distance > 0) {
                distance--;
                count++;
                total += count;
            }   
        }
        if(total < lowest) {
            lowest = total;
        }
    }
    cout << lowest;

    return 0;
}
