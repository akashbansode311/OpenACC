/**********************************************************************
 * Program : Vector Addition & Multiplication Serial Program
 *
 * Operations:
 *      Vector Addition:
 *          C[i] = A[i] + B[i]
 *
 *      Vector Multiplication:
 *          D[i] = A[i] * B[i]
 *
 * Assignment:
 * 1. Convert this serial code into an OpenACC parallel program.
 * 2. Add the required OpenACC directives.
 * 3. Execute it on the GPU.
 *
 *********************************************************************/
#include <iostream>
#include <vector>

int main()
{
        const int N = 1000000; // Vector Size

        float a[N], b[N], c[N], d[N];

        // Initialize the input vectors
        for (int i = 0 ; i < N ; ++i)
        {
                a[i] = 1.0f;
                b[i] = 2.0f;
        }

        // Vector Addition
        for (int i = 0 ; i < N ; ++i)
        {
                c[i] = a[i] + b[i];
        }

        // Vector Multiplication
        for (int i = 0 ; i < N ; ++i)
        {
                d[i] = a[i] * b[i];
        }

        std::cout << "[SUCCESS] Vector Addition & Multiplication operations (serial) completed...\n";

        // Verification of the results
        std::cout << "Check: \nc[0] = " << c[0] << " (expected 3), \nd[0] = " << d[0] << " (expected 2)\n";

        return 0;
}
