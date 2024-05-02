/**
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
**/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float n;
    int data;
    
    cout << "1) Sample 2) Population" << endl;
    cout << "Enter type of data set: ";
    cin >> data;

    cout << "Enter number of items in the data set: ";
    cin >> n;

    // Using a dynamic array instead of a fixed-size array
    float* arr = new float[n];

    for (int i = 0; i < n; i++) {
        cout << "Number " << i+1 << ": "; // Corrected index for user readability
        cin >> arr[i];
    }

    float sum = 0;

    // Iterate from 0 to n-1 for array indices
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    float avg = sum / n;

    float* arrMean = new float[n];
    float* sqrArr = new float[n];

    // Calculating (X - Mean) and (X - Mean)^2
    for (int i = 0; i < n; i++) {
        arrMean[i] = arr[i] - avg;
        sqrArr[i] = arrMean[i] * arrMean[i];
    }

    cout << "No.     X-Mean       (X-Mean)^2" << endl;

    // Outputting data set values, (X - Mean), and (X - Mean)^2
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t" << arrMean[i] << "\t" << sqrArr[i] << endl;
    }

    float sumArr = 0;

    // Calculating the sum of (X - Mean)^2
    for (int i = 0; i < n; i++) {
        sumArr += sqrArr[i];
    }

    float s2, s;

    // Choosing appropriate formula for variance based on data type
    if (data == 1) {
        s2 = sumArr / (n - 1);
    } else if (data == 2) {
        s2 = sumArr / n;
    }

    s = sqrt(s2);

    cout << "Mean is " << avg << endl;
    cout << "Variance is " << s2 << endl;
    cout << "Standard Deviation is " << s << endl;
    cout << "Sum is " << sumArr << endl;

    // Freeing dynamically allocated memory
    delete[] arr;
    delete[] arrMean;
    delete[] sqrArr;

    return 0;
}
