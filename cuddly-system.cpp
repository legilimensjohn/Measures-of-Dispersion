#include <iostream>

#include <cmath>

using namespace std;

int main() {
        float n;
        int data;
        cout << "1) Sample 2)Population" << endl;
        cout << "Enter type of data set: ";
        cin >> data;

        cout << "Enter number of items in the data set: ";
        cin >> n;

        float arr[255];
        for (int i = 1; i <= n; i++) {
                cout << "Number " << i << ": ";
                cin >> arr[i - 1];
        }

        int sum = 0;
        for (int i = 0; i <= n; i++) {
                sum += arr[i];
        }

        float avg = sum / n;

        float arrMean[255];

        for (int i = 0; i < n; i++) {
                arrMean[i] = arr[i] - avg;
        }

        float sqrArr[255];

        for (int i = 0; i < n; i++) {
                sqrArr[i] = arrMean[i] * arrMean[i];
        }

        cout << "No.	X-Mean		(X-Mean)^2" << endl;
        for (int i = 0; i < n; i++) {
                cout << arr[i] << "\t" << arrMean[i] << "\t" << sqrArr[i] << endl;
        }

        int sumArr = 0;
        for (int i = 0; i < n; i++) {
                sumArr += sqrArr[i];
        }

        float s2, s;
        if (data == 1) {
                s2 = sumArr / (n - 1);
                s = sqrt(s2);
        } else if (data == 2) {
                s2 = sumArr / n;
                s = sqrt(s2);
        }

        cout << "Mean is " << avg << endl;
        cout << "Variance is " << s2 << endl;
        cout << "Standard Deviation is " << s << endl;
        cout << "Sum is " << sumArr;
}