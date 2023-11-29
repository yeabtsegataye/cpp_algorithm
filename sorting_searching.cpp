#include <iostream>
using namespace std;

//////////

void bubbleSort(int a[], int n, bool decrement) {
    bool interchange = true;
    int i = 0;
    while (i < n - 1 && interchange) {
        interchange = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (decrement ? a[j] < a[j + 1] : a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                interchange = true;
            }
        }
        i++;
    }
}

void selectionSort(int a[], int n, bool decrement) {
    for (int i = 0; i < n; i++) {
        int last = n - i - 1;
        int pos = i; // Initialize pos to i, not 0
        for (int j = i + 1; j < n; j++) { // Fixed the loop conditions
            if (decrement) {
                if (a[j] > a[pos]) { // Decrement sorting
                    pos = j;
                }
            } else {
                if (a[j] < a[pos]) { // Increment sorting
                    pos = j;
                }
            }
        }
        swap(a[pos], a[last]);
    }
}
////////////////

///////////
void insertionSort(int a[], int n, bool decrement) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (!decrement ? a[j] < a[j - 1] : a[j] > a[j - 1]) {
                swap(a[j], a[j - 1]);
            }
        }
    }
}
//////////////

int linearSearch(int a[], int n, int key) {
    bool found = false;
    int i = 0;
    while (i < n && !found) {
        if (key == a[i])
            found = true;
        else
            i++;
    }
    if (found)
        cout << "Element is Found at index : " << i << endl;
    else
        cout << "Element not Found" << endl;
}

int binarySearch(int a[], int n, int key) {
    int left = 0;
    int right = n - 1;

    // First, sort the array using bubbleSort or selectionSort
    // For example, you can use bubbleSort with increment sorting
    bubbleSort(a, n, false);

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == key) {
            cout << "Element found at index: " << mid << endl;
            return mid;
        } else if (a[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << "Element not found" << endl;
    return -1; // Element not found
}

int main() {
    const int maxElements = 100;
    int n;
    int arr[maxElements];

    while (true) { // Main program loop
        cout << "Enter the number of elements in the array: ";
        cin >> n;

        if (n > maxElements) {
            cout << "Error: Exceeds maximum array size." << endl;
            return 1;
        }

        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Menu:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Linear Search\n";
        cout << "5. Binary Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3) {
            int x;
            cout << "1. Decrement\n";
            cout << "2. Increment\n";
            cout << "3. Go back\n";
            cout << "Enter your choice: ";
            cin >> x;

            if (x == 1) {
                // Decrement operation
                if (choice == 1) {
                    bubbleSort(arr, n, true);
                } else if (choice == 2) {
                    selectionSort(arr, n, true);
                } else if (choice == 3) {
                    insertionSort(arr, n, true);
                }
            } else if (x == 2) {
                // Increment operation
                if (choice == 1) {
                    bubbleSort(arr, n, false);
                } else if (choice == 2) {
                    selectionSort(arr, n, false);
                } else if (choice == 3) {
                    insertionSort(arr, n, false);
                }
            } else if (x == 3) {
                continue; // Go back to the menu
            } else {
                cout << "Invalid choice for increment/decrement." << endl;
            }
        }
        if (choice == 4) {
            int key;
            cout << "Insert the key: ";
            cin >> key;
            linearSearch(arr, n, key);
        }
        if (choice == 5) {
            int key;
            cout << "Insert the key: ";
            cin >> key;
            binarySearch(arr, n, key);
        }
        if (choice == 6) {
            cout << "Exiting..." << endl;
            break; // Exit the program
        }

        cout << "Array after the chosen operation: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}