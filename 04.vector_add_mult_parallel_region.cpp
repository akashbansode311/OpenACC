#include <iostream>
#include <openacc.h>

int main()
{
        const int N = 1000000; // Vector Size

        // Declaration of the vector arrays
        float a[N], b[N], c[N], d[N];

        // Initialize the input vectors
        for (int i = 0 ; i < N ; ++i)
        {
                a[i] = 1.0f;
                b[i] = 2.0f;
        }

        // OpenACC Parallel Region
        // The "data" directive manages data transfer between CPU (Host) and GPU (Device)
        #pragma acc data copyin(a[0:N], b[0:N]) copyout(c[0:N], d[0:N])
        {
                // First Parallel Region
                #pragma acc parallel loop
                for (int i = 0 ; i < N ; ++i)
                {
                        c[i] = a[i] + b[i];
                }

                // Second Parallel Region
                #pragma acc parallel loop
                for (int i = 0 ; i < N ; ++i)
                {
                        d[i] = a[i] * b[i];
                }
        }

        std::cout << "[SUCCESS] Vector Additon & Multiplication operations with explicit data management completed...\n";
        return 0;
}
