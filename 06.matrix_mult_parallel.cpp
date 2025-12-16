#include <iostream>
#include <cstdlib>
#include <openacc.h>
#include <ctime>

void matrix_mult(int* h_a, int* h_b, int* h_result, int N)
{
        // Offload this region to GPU
        #pragma acc data copyin(h_a[0:N*N], h_b[0:N*N]) copyout(h_result[0:N*N])
        {
                // Parallelize the nested loops
                #pragma acc parallel loop collapse(2)
                for (int i = 0 ; i < N ; ++i )
                {
                        for (int j = 0 ; j < N ;++j)
                        {
                                int tmp = 0;
                                #pragma acc loop reduction(+:tmp)
                                for (int k = 0 ; k < N ; ++k)
                                {
                                        tmp += h_a[i * N + k] * h_b[k * N + j];
                                }
                                h_result[i * N + j] = tmp;
                        }
                }
        }
}

int main()
{
        int N =1280;
        int *a, *b, *c;

        // Allocate Memory
        a = new int[N*N];
        b = new int[N*N];
        c = new int[N*N];

        // Initialization of matrix A and B
        for (int i = 0 ; i < N*N ; i++ )
        {
                a[i] = 2;
                b[i] = 3;
        }

        // Measure execution time
        clock_t start = clock();
        matrix_mult(a, b, c, N);
        clock_t stop = clock();

        double timeTakenMs = ((double)(stop - start) / CLOCKS_PER_SEC) * 1000.0;
        std::cout << "Matrix Size : " << N << " x" << N << std::endl;
        std::cout << "Time Taken : " << timeTakenMs << " ms " << std::endl;
        std::cout << "Sample result c[12][0] = " << c[12 * N +0] << std::endl;

        delete[] a;
        delete[] b;
        delete[] c;

        return 0;

}

