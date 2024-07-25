#include <iostream>

using namespace std;

int main() {
    int row = 4;
    int col = 4;
    int arr[row][col];

    cout << "Enter values for the checkerboard:\n";
    for (int i = 0; i < row; i++) {
        for (int a = 0; a < col; a++) {
            cin >> arr[i][a];
        }
    }

    bool checkerboard = true;
    // Check rows
    for (int i = 0; i < row; i++) {
        for (int a = 0; a < col - 2; a++) {
            if (arr[i][a] == arr[i][a + 2] && arr[i][a] != arr[i][a + 1]) {
                checkerboard = true;
                //break;
            }else{
                	checkerboard = false;
                	break;
				}
        }
        if (!checkerboard) break;
    }

    // Check columns
    if (checkerboard) {
        for (int a = 0; a < col; a++) {
            for (int i = 0; i < row - 2; i++) {
                if (arr[i][a] == arr[i + 2][a] && arr[i][a] != arr[i + 1][a]) {
                    checkerboard = true;
                   // break;
                }else{
                	checkerboard = false;
                	break;
				}
            }
            if (!checkerboard) break;
        }
    }

    cout << "The entered 2D array is:\n";
    for (int i = 0; i < row; i++) {
        for (int a = 0; a < col; a++) {
            cout << arr[i][a] << " ";
        }
        cout << endl;
    }

    if (checkerboard) {
        cout << "Checkerboard -> TRUE\n";
    } else {
        cout << "Checkerboard -> FALSE\n";
    }

    return 0;
}




