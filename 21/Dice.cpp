#include <iostream>

using namespace std;

int dice = 1, rolls = 0;
int roll() {
    int total = dice*3 + 3;
    dice += 3;
    rolls += 3;
    return total;
}

int main() {
    int player1 = 0, player2 = 0, pos1 = 9, pos2 = 10;
    while (player1 < 1000 and player2 < 1000) {
        pos1 = (pos1 + roll()) % 10;
        if (pos1 == 0)
            pos1 = 10;
        player1 += pos1;
        if (player1 < 1000) {
            pos2 = (pos2 + roll()) % 10;
            if (pos2 == 0)
                pos2 = 10;
            player2 += pos2;
        }
    }

    cout << "1: " << player1 << " 2: " << player2 << " R: " << rolls << endl;

    if (player1 >= 1000) {
        cout << player2 * rolls;
    } else {
        cout << player1 * rolls;
    }
    return 0;
}
