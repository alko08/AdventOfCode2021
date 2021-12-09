#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

using namespace std;

int main() {
    ifstream data;
    data.open("data.txt");
    string text, number;
    int horizontal = 0;
    int depth = 0;
    int aim = 0;

    for (int i = 0 ; i < 1000; i++) {
        data >> text;
        data >> number;
        int num = stoi(number);
        if (text == "forward") {
            horizontal += num;
            depth += aim * num;
        } else if (text == "down") {
            aim += num;
        } else { // if (text == "up")
            aim -= num;
        }
    }
    cout << horizontal * depth;

    return 0;
}
