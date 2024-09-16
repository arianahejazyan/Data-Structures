/*#include "matrix.h"

template<typename T>
int forwardElimination(Matrix<T>& coefficients, Matrix<T>& constants)
{

    int m = coefficients.rows();
    int n = coefficients.cols();

    for (int i = 0; i < m - 1; i++)
    {
   
        for (int j = i + 1; j < m; j++)
        {
            T factor = coefficients(j,i) / coefficients(i,i);

            for (int k = j; k < n)
            {
                coefficients -= factor * coefficients(i,j);
            }

            constants -= factor * constants(1,j);
        }
    }
}

template<typename T>
void backwardSubstitution(Matrix<T>& coefficients, Matrix<T>& constants, Matrix<T>& solutions)
{

}

template<typename T>
void guassianElimination(Matrix<T>& coefficients, Matrix<T>& constants, Matrix<T>& solutions)
{

}*/