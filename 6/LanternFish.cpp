#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int arr[] = {5,1,2,1,5,3,1,1,1,1,1,2,5,4,1,1,1,1,2,1,2,1,1,1,1,1,2,1,5,1,1,1,3,1,1,1,3,1,1,3,1,1,4,3,1,1,4,1,1,1,1,2,1,1,1,5,1,1,5,1,1,1,4,4,2,5,1,1,5,1,1,2,2,1,2,1,1,5,3,1,2,1,1,3,1,4,3,3,1,1,3,1,5,1,1,3,1,1,4,4,1,1,1,5,1,1,1,4,4,1,3,1,4,1,1,4,5,1,1,1,4,3,1,4,1,1,4,4,3,5,1,2,2,1,2,2,1,1,1,2,1,1,1,4,1,1,3,1,1,2,1,4,1,1,1,1,1,1,1,1,2,2,1,1,5,5,1,1,1,5,1,1,1,1,5,1,3,2,1,1,5,2,3,1,2,2,2,5,1,1,3,1,1,1,5,1,4,1,1,1,3,2,1,3,3,1,3,1,1,1,1,1,1,1,2,3,1,5,1,4,1,3,5,1,1,1,2,2,1,1,1,1,5,4,1,1,3,1,2,4,2,1,1,3,5,1,1,1,3,1,1,1,5,1,1,1,1,1,3,1,1,1,4,1,1,1,1,2,2,1,1,1,1,5,3,1,2,3,4,1,1,5,1,2,4,2,1,1,1,2,1,1,1,1,1,1,1,4,1,5};
    // vector<int> fish(arr, arr + sizeof(arr) / sizeof(int));

    // for (int i = 1; i <= 256; i++) {
    //     int temp = fish.size();
    //     for(int i = 0; i < temp; i++) {
    //         fish[i] = fish[i] - 1;
    //         if(fish[i] == -1) {
    //             fish[i] = 6;
    //             fish.push_back(8);
    //         }
    //     }
    // }

    vector<long long int> fish(9, 0);
    // cout << fish[0] + fish[1] + fish[2] + fish[3] + fish[4] + fish[5] + fish[6] + fish[7] + fish[8];
    for(int i = 0; i < 300; i++) {
        fish[arr[i]] = fish[arr[i]] + 1;
    }
    // cout << fish[0] + fish[1] + fish[2] + fish[3] + fish[4] + fish[5] + fish[6] + fish[7] + fish[8];

    for (int i = 1; i <= 256; i++) {
        long long int temp = fish[0];
        fish[0] = fish[1];
        fish[1] = fish[2];
        fish[2] = fish[3];
        fish[3] = fish[4];
        fish[4] = fish[5];
        fish[5] = fish[6];
        fish[6] = fish[7] + temp;
        fish[7] = fish[8];
        fish[8] = temp;
    }



    cout << fish[0] + fish[1] + fish[2] + fish[3] + fish[4] + fish[5] + fish[6] + fish[7] + fish[8];

    return 0;
}
