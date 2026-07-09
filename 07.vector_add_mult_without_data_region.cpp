#include <iostream>
#include <openacc.h>

int main() {
    const int N = 1000000;
    float a[N], b[N], c[N], d[N];

    // Initialize arrays
    for (int i = 0; i < N; ++i) {
        a[i] = 1.0f;
        b[i] = 2.0f;
    }

    // First parallel region
    #pragma acc parallel loop
    for (int i = 0; i < N; ++i) {
        c[i] = a[i] + b[i];
    }

    // Second parallel region
    #pragma acc parallel loop
    for (int i = 0; i < N; ++i) {
        d[i] = a[i] * b[i];
    }

    std::cout << "[SUCCESS] Vector operations completed with OpenACC.\n";
    return 0;
}
