/**********************************************************************
 * Program : Dot Product using OpenACC Reduction
 *
 * Operation:
 *      Dot Product = Σ (A[i] * B[i])
 *
 * Compile:
 *      nvc++ -acc -Minfo=accel filename.cpp -o filename
 *
 *********************************************************************/

#include <iostream>
#include <openacc.h>

#define N 1024

using namespace std;

int main()
{
    float A[N], B[N];
    float sum = 0.0f;

    // Initialize vectors
    for (int i = 0; i < N; i++)
    {
        A[i] = i + 1;
        B[i] = 2.0f;
    }

    // Copy input arrays from CPU to GPU
    #pragma acc data copyin(A, B)
    {
        // Parallel reduction
        #pragma acc parallel loop reduction(+:sum)
        for (int i = 0; i < N; i++)
        {
            sum += A[i] * B[i];
        }
    }

    cout << "Dot Product = " << sum << endl;

    return 0;
}
