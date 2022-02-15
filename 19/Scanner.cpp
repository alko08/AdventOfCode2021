#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

struct beacon {
    short int x, y, z;

    beacon() {
        x = 0;
        y = 0;
        z = 0;
    }
    beacon(short int a, short int b, short int c) {
        x = a;
        y = b;
        z = c;
    }

    void set(short int a, short int b, short int c) {
        x = a;
        y = b;
        z = c;
    }
    void rotateX() {
        x = -x;
    }
    void rotateY() {
        y = -y;
    }
    void rotateZ() {
        z = -z;
    }
    string postion() {
        string temp = "";
        temp += x + y + z;
        return temp;
    }
};

struct scanner {
    vector<beacon> beacons;
    short int x, y, z;
    bool found;

    scanner() {
        x = 0;
        y = 0;
        z = 0;
        found = false;
    }
    scanner(short int a, short int b, short int c) {
        x = a;
        y = b;
        z = c;
        found = false;
    }
    void addBeacon(short int a, short int b, short int c) {
        beacons.push_back(beacon(a, b, c));
    }

    void set(short int a, short int b, short int c) {
        x = a;
        y = b;
        z = c;
        found = true;
    }
    void rotateX() {
        for (int i = 0; i < beacons.size(); i++) {
            beacons[i].rotateX();
        }
    }
    void rotateY() {
        for (int i = 0; i < beacons.size(); i++) {
            beacons[i].rotateY();
        }
    }
    void rotateZ() {
        for (int i = 0; i < beacons.size(); i++) {
            beacons[i].rotateZ();
        }
    }
};

scanner scanners[40];
bool done() {
    for (int i = 0; i < 40; i++) {
        if (!scanners[i].found)
            return false;
    }
    return true;
}

bool contains(int one, int two) {
    int count = 0;
    scanner temp1 = scanners[one], temp2 = scanners[two];
    for (int xLoop = 0; xLoop < 2; xLoop++) {
        temp2.rotateX();
        for (int yLoop = 0; yLoop < 2; yLoop++) {
            temp2.rotateY();
            for (int zLoop = 0; zLoop < 2; zLoop++) {
                temp2.rotateZ();
                count = 0;
                for (int i = 0; i < temp2.beacons.size(); i++) {
                    for (int j = 0; j < temp1.beacons.size(); j++) {
                        if (temp1.beacons[j].postion() == temp2.beacons[i].postion()) {
                            count++;
                            break;
                        }
                    }
                }
                if (count >= 12)
                    return true;
            }
        }
    }
    
    return count >= 12;
}

int main() {
    ifstream data;
    data.open("data.txt");
    string text1, text2, text3;
    int count;

    getline(data, text1);
    int s = 0;
    while (data.peek() != EOF) {
        if (data.peek() == 10) {
            s++;
            getline(data, text1);
            getline(data, text1);
        } else {
            getline(data, text1, ',');
            getline(data, text2, ',');
            getline(data, text3);
            cout << s << ": " << text1 << "," << text2 << "," << text3 << endl;
            scanners[s].addBeacon(stoi(text1), stoi(text2), stoi(text3));
        }
    }
    scanners[0].set(0, 0, 0);

    while (!done()) {
        // cry
        break;
    }

    return 0;
}
