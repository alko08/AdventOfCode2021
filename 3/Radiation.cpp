#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    ifstream data;
    data.open("data.txt");
    string text;

    string high = "";
    string low = "";
    int arr[12];
    int arr2[12];

    for(int i = 0; i < 12; i++) {
        arr[i] = 0;
    }

    for (int i = 0 ; i < 1000 ; i++) {
        data >> text;
        if(text[0] == 48) {
            arr[0] -= 1;
        } else {
            arr[0] += 1;
        }
    }

    if(arr[0] >= 0) {
        high = high + "1";
        low = low + "0";
    } else {
        high = high + "0";
        low = low + "1";
    }

    for(int j = 1; j < 12; j++) {
        for(int i = 0; i < 12; i++) {
            arr[i] = 0;
            arr2[i] = 0;
        }
        data.seekg(0);

        for (int i = 0 ; i < 1000 ; i++) {
            data >> text;
            if(text.rfind(high, 0) == 0){
                // cout << high << "|" << text << endl;
                if(text[j] == 48) {
                    arr[j] -= 1;
                } else {
                    arr[j] += 1;
                }
            }
            if(text.rfind(low, 0) == 0){
                // cout << low << "|" << text << endl;
                if(text[j] == 48) {
                    arr2[j] -= 1;
                } else {
                    arr2[j] += 1;
                }
            }
        }

        if(arr[j] >= 0) {
            high = high + "1";
        } else {
            high = high + "0";
        }
        // cout << arr2[j] << endl;
        if(arr2[j] >= 0) {
            low = low + "0";
        } else {
            low = low + "1";
        }
    }

    cout << high << endl;
    cout << low << endl;

    // low = "001010100001";
    
    int highest = 0;
    int lowest = 0;
    for (int i = 0 ; i < 12 ; i++) {
        
        highest += (high[i]-48) * pow(2, 11-i);
        lowest += (low[i]-48) * pow(2, 11-i);
    }
    cout << highest << endl;
    cout << lowest << endl;
    cout << highest*lowest << endl;

    // int highest = 0;
    // int lowest = 0;
    // int num1 = 0;
    // int num2 = 0;
    // for (int i = 0 ; i < 12 ; i++) {
    //     if(arr[i] > 0){
    //         num1 = 1;
    //         num2 = 0;
    //     } else {
    //         num1 = 0;
    //         num2 = 1;
    //     }
    //     highest += num1 * pow(2, 11-i);
    //     lowest += num2 * pow(2, 11-i);
    // }
    // cout << highest << endl;
    // cout << lowest << endl;
    // cout << highest*lowest << endl;

    return 0;
}
