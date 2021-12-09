#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int arr[100][5][5];

bool win(int i){
    for(int j = 0; j < 5; j++) {
        bool last = arr[i][j][0] == -1;
        if (last) {
            for(int k = 1; k < 5; k++) {
                if (arr[i][j][k] != -1){
                    last = false;
                    break;
                } 
            }
            if (last) {
                return true;
            }
        }
    }

    for(int j = 0; j < 5; j++) {
        bool last = arr[i][0][j] == -1;
        if (last) {
            for(int k = 1; k < 5; k++) {
                if (arr[i][k][j] != -1){
                    last = false;
                    break;
                } 
            }
            if (last) {
                return true;
            }
        }
        
    }

    bool last = arr[i][0][0] == -1;
    if (last) {
        for(int j = 1; j < 5; j++) {
            if (arr[i][j][j] != -1){
                last = false;
                break;
            }
        }
        if (last) {
            return true;
        }
    }

    last = (arr[i][5][0] == -1);
    if (last) {
        for(int j = 1; j < 5; j++) {
            if (arr[i][5-j][j] != -1){
                last = false;
                break;
            } 
        }
        if (last) {
            return true;
        }
    }

    return false;
}

int main() {
    ifstream data;
    data.open("data.txt");
    ifstream boards;
    boards.open("boards.txt");
    string text;

    for (int i = 0 ; i < 100 ; i++) {
        for(int j = 0; j < 5; j++) {
            for(int k = 0; k < 5; k++) {
                boards >> text;
                // cout << text << endl;
                int temp = stoi(text);
                arr[i][j][k] = temp;
            }
        }
    }

    int bingo = -1;
    int num = 0;
    int bingoTotal = 0;
    bool quitAll = false;
    while (not data.eof() and !quitAll) {
        getline(data, text, ',' );
        num = stoi(text);
        for (int i = 0 ; i < 100 ; i++) {
            bool quit = false;
            if (arr[i][0][0] != -2) {
                // cout << i << endl;
                for( int j = 0; j < 5; j++) {
                    for(int k = 0; k < 5; k++) {
                        if (num == arr[i][j][k]){
                            arr[i][j][k] = -1;
                            if (win(i)) {
                                bingoTotal++;
                                if (bingoTotal == 100) {
                                    bingo = i;
                                    quitAll = quit = true;
                                    cout << "Bingo: " << bingoTotal << " | " << i << endl;
                                }else {
                                    cout << "Bingo: " << bingoTotal << " | " << i << endl;
                                    quit = true;
                                    arr[i][0][0] = -2;
                                }
                                break;
                            }
                        }  
                    }
                    if(quit) {
                        break;
                    }
                }
            }
            if(quitAll) {
                break;
            }
        }
    }

    int total = 0;
    for(int j = 0; j < 5; j++) {
        for(int k = 0; k < 5; k++) {
            cout << arr[bingo][j][k] << " ";
            if (arr[bingo][j][k] != -1){
                total += arr[bingo][j][k];
            }  
        }
        cout << endl;
    }
    cout << num << endl;
    cout << total * num << endl;

    return 0;
}
