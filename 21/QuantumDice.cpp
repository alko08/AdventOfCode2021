#include <iostream>

using namespace std;

struct pos {
    long long int arr[21][21];
    pos() {
        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++) {
                arr[i][j] = 0;
            }
        }
    }
    bool isEmpty() {
        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 21; j++) {
                if (arr[i][j] > 0)
                    return false;
            }
        }
        return true;
    }
};

pos positions[10][10];
bool empty() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (!positions[i][j].isEmpty())
                return false;
        }
    }
    return true;
}

struct points {
    long long int player1, player2;

    points() {
        player1 = 0;
        player2 = 0;
    }
    points(long long int p1, long long int p2) {
        player1 = p1;
        player2 = p2;
    }
};

long long int rollhelper2(long long int amount, short int pos1,
short int pos2, short int p1, short int p2) {
    pos2 = pos2 % 10;
    if (pos2 == 0)
        pos2 = 10;
    p2 += pos2;
    if (p2 >= 21) {
        return amount;
    }
    positions[pos1-1][pos2-1].arr[p1][p2] += amount;
    return 0;
}

points rollhelper(long long int amount, short int pos1,
short int pos2, short int p1, short int p2) {
    long long int player1 = 0, player2 = 0;
    points temp;
    pos1 = pos1 % 10;
    if (pos1 == 0)
        pos1 = 10;
    p1 += pos1;
    if (p1 >= 21) {
        return points(amount, 0);
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                player2 += rollhelper2(amount, pos1, pos2+i+j+k, p1, p2);
            }
        }
    }
    
    return points(0, player2);
}

points roll(short int pos1, short int pos2, 
short int p1, short int p2) {
    long long int player1 = 0, player2 = 0, 
    amount = positions[pos1-1][pos2-1].arr[p1][p2];
    positions[pos1-1][pos2-1].arr[p1][p2] = 0;
    points temp;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
                temp = rollhelper(amount, pos1+i+j+k, pos2, p1, p2);
                player1 += temp.player1;
                player2 += temp.player2;
            }
        }
    }   
    return points(player1, player2);
}

int main() {
    long long int player1 = 0, player2 = 0;
    short int pos1 = 9, pos2 = 10;
    positions[pos1-1][pos2-1].arr[0][0] = 1;
    points temp;

    int count = 0;
    while(!empty()) {
        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 10; j++) {
                for (int p1 = 0; p1 <= 20; p1++) {
                    for (int p2 = 0; p2 <= 20; p2++) {
                        if (positions[i-1][j-1].arr[p1][p2] > 0) {
                            temp = roll(i, j, p1, p2);
                            player1 += temp.player1;
                            player2 += temp.player2;
                        }
                            
                    }
                }
            }
        }
    }

    cout << player1 << endl;
    cout << player2 << endl;
    return 0;
}
