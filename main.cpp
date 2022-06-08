// Author: Abdullah Yaser Alnadhari
// follow me on github: https://github.com/buudi 
#include <iostream>

int* multiply_AX(int A[3][3], int X[3], int Y[3])
{
    // Performing Matrix Multiplication Y=AX
    // Formula: Y[i] = (A[i][0]*X[0]) + (A[i][1]*X[1]) + (A[i][2]*X[2])
    // where i is the iteration in the loop, which reflects: rowNumber+1

    for (int i=0; i<3; i++)
    {
        Y[i] = (A[i][0]*X[0]) + (A[i][1]*X[1]) + (A[i][2]*X[2]);
    }

    return Y;
}

int main()
{
    // defining Matrix A
    int A[3][3] ={
        {3, -1, 0},
        {-2, 6, -2},
        {0, -1, 3}
    };

    // defining Matrix X
    int X[3] = {0, 1, 0};

    // New Matrix Y that will be the result of
    // matrix Multiplication Y=AX, 
    // initially it holds (0 0 0) transposed
    int Y[3]={0, 0, 0};

    multiply_AX(A, X, Y);

    // Printing the new Matrix Y:
    std::cout << "Y = (" << Y[0] << ", " << Y[1] << ", " << Y[2]<< ") Transpose" << std::endl;

    // defining the error as delta:
    float delta = 0.0005;

    // defining a 3x1 matrix which will hold the
    // dominant eigenvector once the iteration ends
    float eigenvector[3] = {0, 0, 0};


}

