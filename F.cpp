#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


void enter(int **arr, int N);
double area(int **arr, int N);

int main(int argc, char** argv) {
    int N;
    cin >> N;
    int **arr = new int* [N + 1];
    for (int i = 0; i < N + 1; i++) {
        arr[i] = new int[2];
    }

    enter(arr, N);
    double S = area(arr, N);



    int **Triangal = new int* [4];
    for (int i = 0; i < 4; i++) {
        Triangal[i] = new int[2];
    }

    double sumOfTriangals = 0;
    for (int i = 0; i < N; i++) {
        arr[i][0] -= arr[0][0];
        arr[i][1] -= arr[0][1];
    }
    for (int i = 2; i < N; i++) {
        Triangal[0][0] = arr[0][0];
        Triangal[0][1] = arr[0][1];
        Triangal[1][0] = arr[i - 1][0];
        Triangal[1][1] = arr[i - 1][1];
        Triangal[2][0] = arr[i][0];
        Triangal[2][1] = arr[i][1];

        sumOfTriangals += area(Triangal, 3);
    }

    if (S == sumOfTriangals)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

void enter(int **arr, int N) {
    for (int j = 0; j < N; j++) {
        cin >> arr[j][0] >> arr[j][1];
    }
}

double area(int **arr, int N) {
    arr[N][0] = arr[0][0];
    arr[N][1] = arr[0][1];
    double area = 0;
    for (int i = 0; i < N; i++) {
        area += (arr[i][0] * arr[i + 1][1] - arr[i][1] * arr[i + 1][0]) / 2.0;
    }
    return abs(area);
}
