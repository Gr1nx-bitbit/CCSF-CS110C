#include <iostream>
using namespace std;

int oddSum(int array[], int size) {
    if (size != 1) {
        if (array[size-1] % 2 != 0) {
            return (array[size-1] + oddSum(array, size - 1));
        } else {
            return oddSum(array, size - 1);
        }

    } else {
        if (array[size-1] % 2 != 0) {
            return array[size-1];
        } else {
            return 0;
        }
    }
}

int main(void) {
    int cool[9] = {2, 3, 7, 8, 5, 9, 10, 1, 0};
    cout << oddSum(cool, 9) << endl;
    return 0;
}