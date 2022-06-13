// Author: Abdullah Yaser Alnadhari
// follow me on github: https://github.com/buudi 
// check latest updates for this program: https://github.com/buudi/Dominant-EigenValue 
#include <iostream>
#include <cstdlib>

float* multiply_AX(int A[3][3], float X[3], float Y[3])
{
    // Performing Matrix Multiplication Y=AX
    // Formula: Y[i] = (A[i][0]*X[0]) + (A[i][1]*X[1]) + (A[i][2]*X[2])
    // where i is the iteration in the loop, which reflects the row number

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
        {5, -2, 1},
        {-2, 2, 0},
        {2, -2, 3}
    };

    // defining Matrix X
    float X[3] = {1, 0, 1};

    // New Matrix Y that will be the result of
    // matrix Multiplication Y=AX, 
    // initially it holds (0 0 0) transposed
    float Y[3]={0, 0, 0};

    multiply_AX(A, X, Y);

    // Printing the new Matrix Y:
    // std::cout << "Y = (" << Y[0] << ", " << Y[1] << ", " << Y[2]<< ") Transpose" << std::endl;

    // defining a 3x1 matrix which will hold the
    // dominant eigenvector once the iteration ends
    float V[3] = {0, 0, 0};

    // first let the initial EigenVector equal X
    for (int i=0; i < 3; i++)
    {
        V[i] = X[i];
    }

    // defining the error value as delta:
    float delta = 0.0005;

    // 2nd we initilize a holder for current error, the A*V vector and 
    // for the eigen value m:
    float AV[3] = {0, 0, 0};
    float m = 0;
    float tempM[9];
    float error;

    // 3rd, we specify the condition to end the loop
    int foundYet;

    // now we iterate to find the eigenvector: 
    for  (int i =0; i < foundYet + 1; i++)
    {
        multiply_AX(A, V, AV);
        for (int i=0; i<3; i++)
        {
            if (AV[i] > m)
                m = AV[i];
        }
        tempM[i] = m;
        // std::cout << "m " <<i << ":" << m << std::endl;
        for (int i=0; i < 3; i++)
        {
            V[i] = AV[i] / m;
        } 
        if(i != 0)
        {
            error = m - tempM[i-1];
           // std::cout << "Error " << i << ":" <<  error << std::endl;
        } 
        if (i!=0 && (m - tempM[i-1] ) < delta)
            foundYet = i; 
    }
    
    std::cout << "eigenvalue: " << m << std::endl;
    std::cout << "Eigenvector: "  << std::endl;
    std::cout << V[0] << std::endl; 
    std::cout << V[1] << std::endl; 
    std::cout << V[2] << std::endl; 

    system("pause");
    return 0;
}