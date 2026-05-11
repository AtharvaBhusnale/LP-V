#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0, min = arr[0], max = arr[0];

    #pragma omp parallel for reduction(+:sum) reduction(min:min) reduction(max:max)
    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (arr[i] < min)
            min = arr[i];

        if (arr[i] > max)
            max = arr[i];
    }

    cout << "\nSum = " << sum;
    cout << "\nMinimum = " << min;
    cout << "\nMaximum = " << max;
    cout << "\nAverage = " << (float)sum / n;

    return 0;
}