#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

vector<string> names;

struct node {
    vector<int> neighbors;
    string name;
    bool isBig;

    node() {
        name = "";
        isBig = false;
    }
    node(string n) {
        name = n;
        string temp = "";
        for (int i = 0; i < n.size(); i++) {
            temp += toupper(n[i]);
        }
        isBig = n == temp;
    }
    void addNeighbor(string n) {
        for (int i = 0 ; i < names.size(); i++) {
            if (n == names[i]) {
                neighbors.push_back(i);
                break;
            }       
        }
    }
};

vector<node> nodes;

int path(int p, vector<string> n, bool twice) {
    int count = 0;

    for (int i = 0; i < nodes[p].neighbors.size(); i++) {
        bool second = twice;
        bool contains = false;
        int num = nodes[p].neighbors[i];
        string temp = names[num];

        if(temp == "end") {
            count += 1;
        } else if (!nodes[num].isBig) {
            for (int j = 0; j < n.size(); j++) {
                if (n[j] == temp) {
                    if (!twice && temp != "start") {
                        second = true;
                    } else {
                        contains = true;
                    }
                    break;
                }
            }
            if (!contains) {
                n.push_back(temp);
                count += path(num, n, second);
                n.pop_back();
            }
        } else {
            count += path(num, n, twice);
        }
    }
    return count;
}

int main() {
    ifstream data;
    data.open("data.txt");
    string text1, text2;

    nodes.push_back(node("start"));
    names.push_back("start");
    nodes.push_back(node("end"));
    names.push_back("end");

    for (int i = 0; i < 26; i++) {
        getline(data, text1, '-');
        getline(data, text2);
        bool one = false, two = false;
        int spot1 = -1, spot2 = -1;
        for (int j = 0; j < names.size(); j++) {
            if (names[j] == text1) {
                one = true;
                spot1 = j;
            }      
            if (names[j] == text2) {
                two = true;
                spot2 = j;
            }        
        }
        if (!one) {
            spot1 = names.size();
            names.push_back(text1);
            nodes.push_back(node(text1));
        }
        if (!two) {
            spot2 = names.size();
            names.push_back(text2);
            nodes.push_back(node(text2));
        }

        nodes[spot1].addNeighbor(text2);
        nodes[spot2].addNeighbor(text1);
    }

    vector<string> n;
    n.push_back("start");
    cout << path(0, n, false) << endl;

    // cout << "--------------------\n";
    // for (int i = 0; i < nodes.size(); i++) {
    //     cout << names[i] << ": ";
    //     for (int j = 0; j < nodes[i].neighbors.size(); j++) {
    //         int temp = nodes[i].neighbors[j];
    //         cout << names[temp] << ",";
    //     }
    //     cout << endl;
    // }

    return 0;
}
