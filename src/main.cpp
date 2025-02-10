#include <iostream>
#include "run_gSparse.h"

int main()
{
    // Define a small directed graph
    int n = 4;  // number of nodes
    int m = 4;  // number of edges

    // Edges: (0->1), (1->2), (2->3), (0->2)
    int src[] = {0, 1, 2, 0};
    int dst[] = {1, 2, 3, 2};

    // Array to hold node flags
    int* node_flags = new int[n];

    // Call our sparsification function
    int ret = run_gSparse(n, m, src, dst, node_flags);

    // Check for errors
    if (ret != 0) {
        std::cerr << "Error calling run_gSparse (error code: " << ret << ")" << std::endl;
        delete[] node_flags;
        return 1;
    }

    // Print out which nodes are marked as 1 (in the sparsified graph)
    for (int i = 0; i < n; i++) {
        std::cout << "Node " << i << " flag = " << node_flags[i] << std::endl;
    }

    // Clean up
    delete[] node_flags;
    return 0;
}

