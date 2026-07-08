#include <iostream>

int main()
{
        const int N = 1000000; // Vector Size

        // Declaration of the vector arrays
        float a[N], b[N], c[N];

        // Initialize the input vectors
        for (int i=0 ; i < N ; ++i)
        {
                a[i] = 1.0f;
                b[i] = 2.0f;
        }

        // Perform Vector Addtion Operation
        for (int i = 0 ; i < N ; ++i)
        {
                c[i] = a[i] + b[i];
        }

        std::cout << "[SUCCESS] Vector Addition completed...\n";
        return 0;
}
