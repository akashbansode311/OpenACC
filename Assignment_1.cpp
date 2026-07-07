/**********************************************************************
 * Program : Single Precision AX Plus Y (SAXPY Serial Program)
 *
 * Operation:
 *      Y = a * X + Y
 *
 * Assignment:
 * 1. Convert this serial code into an OpenACC parallel program.
 * 2. Add the required OpenACC directives.
 * 3. Execute it on the GPU.
 *********************************************************************/

#include <iostream>

#define N 1024

int main()
{
    // Input vectors
    float X[N], Y[N];

    // Scalar multiplier
    float a = 2.5f;

    // Initialize the vectors
    for (int i = 0; i < N; i++)
    {
        X[i] = i + 1;
        Y[i] = i;
    }

    // Serial SAXPY Computation
    for (int i = 0; i < N; i++)
    {
        Y[i] = a * X[i] + Y[i];
    }

    // Display the output by printing first 10 results
    std::cout << "First 10 elements after SAXPY:\n";

    for (int i = 0; i < 10; i++)
    {
        std::cout << "Y[" << i << "] = " << Y[i] << std::endl;
    }

    return 0;
}
