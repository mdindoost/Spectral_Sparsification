#include <iostream>
#include "run_gSparse.h"
#include <vector>

int main() {
    int n = 20;  // 5-node clique
    std::vector<int> src, dst;
    
    // Generate complete graph edges
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            src.push_back(i);
            dst.push_back(j);
        }
    }
    
    int m = src.size();
    std::cout << "Original edges (" << m << " total):" << std::endl;
    for(int i = 0; i < m; i++) {
        std::cout << src[i] << " -> " << dst[i] << std::endl;
    }

    int* node_flags = new int[n];
    int ret = run_gSparse(n, m, src.data(), dst.data(), node_flags);

    if (ret != 0) {
        std::cerr << "Error in run_gSparse" << std::endl;
        delete[] node_flags;
        return 1;
    }

    std::cout << "\nNodes in sparsified graph:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Node " << i << ": " << (node_flags[i] ? "included" : "excluded") << std::endl;
    }

    delete[] node_flags;
    return 0;
}