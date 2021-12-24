#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;


bool paper[1311+1][895+1];

int countDots (int xRange, int yRange) {
    int count = 0;
    for (int i = 0; i <= xRange; i++) {
        for (int j = 0; j <= yRange; j++) {
            if (paper[i][j])
                count++;
        }
    }
    return count;
}

void foldPaper (bool isX, int num, int &xRange, int &yRange) {
    if (isX) {
        for (int j = 0; j <= yRange; j++) {
            for (int i = num+1; i <= xRange; i++) {
                int temp = num - (i-num);
                if (temp < 0)
                    break;
                if (paper[i][j])
                    paper[temp][j] = true;
            }
        }
        xRange = num - 1;
    } else {
        for (int j = 0; j <= xRange; j++) {
            for (int i = num+1; i <= yRange; i++) {
                int temp = num - (i-num);
                if (temp < 0)
                    break;
                if (paper[j][i])
                    paper[j][temp] = true;
            }
        }
        yRange = num - 1;
    }
   
}

int main() {
    ifstream data;
    data.open("data.txt");
    string text1, text2;
    int xRange = 1311, yRange = 895;
    
    for (int i = 0; i <= xRange; i++) {
        for (int j = 0; j <= yRange; j++) {
            paper[i][j] = false;
        }
    }

    for (int i = 0; i < 741; i++) {
        getline(data, text1, ',');
        getline(data, text2);
        int one = stoi(text1), two = stoi(text2);
        paper[one][two] = true;
    }

    getline(data, text1);
    for (int i = 0; i < 12; i++) {
        getline(data, text1, '=');
        getline(data, text2);
        int two = stoi(text2);
        foldPaper(text1.substr(11) == "x", two, xRange, yRange);
        cout <<"Fold " << i+1 << ": " << countDots(xRange, yRange) << endl;
    }

    for (int j = 0; j <= yRange; j++) {
        for (int i = 0; i <= xRange; i++) {
            if (paper[i][j]) {
                cout << "#";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    } 

    return 0;
}
