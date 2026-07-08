#include <iostream>
#include <openacc.h>

int main()
{
        const int N = 1000000; // Vector Size

        // Declaration of the vectors
        float a[N], b[N], c[N];

        // Initialize the input vectors
        for (int i=0 ; i < N ; ++i)
        {
                a[i] = 1.0f;
                b[i] = 2.0f;
        }

        // OpenACC Parallel Region
        // The "data" directive manages data transfer between CPU (Host) and GPU (Device)
        // Copy input arrays to GPU and output array back to CPU
        #pragma acc data copyin(a[0:N], b[0:N]) copyout(c[0:N])
        {
                // Execute loop on GPU
                #pragma acc parallel loop
                for (int i = 0 ; i < N ; ++i)
                {
                        c[i] = a[i] + b[i];
                }
        }
        std::cout << "First 10 Elements of Result:\n";

        for (int i = 0; i < 10; i++)
        {
                std::cout << "c[" << i << "] = " << c[i] << std::endl;
        }
        std::cout << "[SUCCESS] Vector Addition completed...\n";
        return 0;
}
