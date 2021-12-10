#include <iostream>
#include <vector>
#include <fstream>
#include <stack>
#include <math.h>

using namespace std;

stack<char> code;

void clear() {
    while(code.size() > 0) {
        code.pop();
    }
}

void swap(vector<long long int> &data, int left, int right)
{
    long long int temp = data[left];
    data[left] = data[right];
    data[right] = temp;
}

int partition(vector<long long int> &data, int left, int right)
{
    long long int less = 0; 
    long long int greater = 0;
    for (int i = left + 1; i <= right; i++) {
        if (data[i] < data[left]) {
            less++;
            if(greater > 0) {
                swap(data, left + less, i);    
            }
        } else {
            greater++;
        }
    }
    
    swap(data, left, left + less);
    return left + less;
}

void quicksortHelper(vector<long long int> &data, int left, int right) {
    if (right - left > 1) {
        long long int pivot = partition(data, left, right);
        quicksortHelper(data, left, pivot - 1);
        quicksortHelper(data, pivot + 1, right);
    } else if (right - left == 1) {
        if (data[right] < data[left]) {
            swap(data, left, right);
        }
    }
}

void quicksort(vector<long long int> &data)
{
    quicksortHelper(data, 0, data.size() - 1);
     
}


int main() {
    ifstream data;
    data.open("data.txt");
    string text;
    
    char opener[4];
    char closer[4];
    vector<char> corrupted;
    int points[4];
    vector<long long int> autoCorrect;

    opener[0] = '(';
    opener[1] = '[';
    opener[2] = '{';
    opener[3] = '<';
    closer[0] = ')';
    closer[1] = ']';
    closer[2] = '}';
    closer[3] = '>';
    points[0] = 3;
    points[1] = 57;
    points[2] = 1197;
    points[3] = 25137;

    
    for(int i = 0; i < 94; i++) {
        clear();
        bool corrupt = false;
        getline(data, text);
        for(int j = 0; j < text.size(); j++) {
            if(text[j] == opener[0] or text[j] == opener[1] or 
            text[j] == opener[2] or text[j] == opener[3]) {
                code.push(text[j]);
            } else {
                char temp = code.top();
                int num = 0;
                if(temp == opener[0]) {
                    num = 0;
                } else if(temp == opener[1]) {
                    num = 1;
                } else if(temp == opener[2]) {
                    num = 2;
                } else { //if(temp == opener[3])
                    num = 3;
                }

                if(text[j] == closer[num]) {
                    code.pop();
                } else {
                    corrupted.push_back(text[j]);
                    corrupt = true;
                    break;
                }
            }
        }
        if (!corrupt) {
            long long int total = 0;
            while (code.size() > 0) {
                char temp = code.top();
                code.pop();
                int num = 0;
                if(temp == opener[0]) {
                    num = 1;
                } else if(temp == opener[1]) {
                    num = 2;
                } else if(temp == opener[2]) {
                    num = 3;
                } else { //if(temp == opener[3])
                    num = 4;
                }
                total = total * 5 + num;
                // cout << total << endl;
            }
            autoCorrect.push_back(total);
        }
    }
    
    int total = 0;
    for(int i = 0; i < corrupted.size(); i++) {
        for(int j = 0; j < 4; j++) {
            if(closer[j] == corrupted[i]) {
                total += points[j];
            }
        }
    }

    quicksort(autoCorrect);
    cout << "Corrupted Points: " << total << endl;
    cout << "Autocomplete Points: " << autoCorrect[autoCorrect.size()/2] << endl;

    // for(int i = 0; i < autoCorrect.size(); i++) {
    //     cout << i << ": " << autoCorrect[i] << endl;
    // }
    
    return 0;
}
