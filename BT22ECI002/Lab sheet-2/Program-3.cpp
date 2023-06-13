#include <iostream>

using namespace std;

int main()
{
    int m;
    cout << "Enter the square matrix order: ";
    cin >> m;

    int** matrix = new int*[m];
    for (int i = 0; i < m; i++)
    {
        matrix[i] = new int[m];
    }

    cout << "Input the matrix:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "The matrix is:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    bool saddlePointFound = false;
    for (int i = 0; i < m; i++)
    {
        int min = matrix[i][0];
        int minColumnIndex = 0;
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                minColumnIndex = j;
            }
        }

        bool isSaddlePoint = true;
        for (int k = 0; k < m; k++)
        {
            if (matrix[k][minColumnIndex] > min)
            {
                isSaddlePoint = false;
                break;
            }
        }

        if (isSaddlePoint)
        {
            saddlePointFound = true;
            cout << "Saddle point (" << i << ", " << minColumnIndex << ") gives min : " << min << endl;
        }
    }

    if (!saddlePointFound)
    {
        cout << "No saddle point found." << endl;
    }

    for (int i = 0; i < m; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
