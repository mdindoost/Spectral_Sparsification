#include "run_gSparse.h"
#include <gSparse/gSparse.hpp>
#include <Eigen/Core>
#include <iostream>
#include <memory>

int run_gSparse(int n, int m, const int* src, const int* dst, int* node_flags) {
    try {
        gSparse::EdgeMatrix edges(m, 2);
        for (int i = 0; i < m; i++) {
            edges(i, 0) = src[i];
            edges(i, 1) = dst[i];
        }

        auto graph = std::make_shared<gSparse::UndirectedGraph>(edges);
        gSparse::SpectralSparsifier::ERSampling sparsifier(graph);
        
        sparsifier.SetERPolicy(gSparse::SpectralSparsifier::EXACT_ER);  // Changed from APPROXIMATE_ER
        // sparsifier.SetERPolicy(gSparse::SpectralSparsifier::APPROXIMATE_ER);
        sparsifier.SetC(4.0);
        sparsifier.SetEpsilon(0.5);
        
        sparsifier.Compute();
        auto sparseGraph = sparsifier.GetSparsifiedGraph();
        auto sparseEdges = sparseGraph->GetEdgeList();
        
        std::cout << "\nSparsified edges (" << sparseEdges.rows() << " total):" << std::endl;
        for (int i = 0; i < sparseEdges.rows(); i++) {
            std::cout << sparseEdges(i, 0) << " -> " << sparseEdges(i, 1) << std::endl;
        }

        std::fill(node_flags, node_flags + n, 0);
        for (int i = 0; i < sparseEdges.rows(); i++) {
            node_flags[static_cast<int>(sparseEdges(i, 0))] = 1;
            node_flags[static_cast<int>(sparseEdges(i, 1))] = 1;
        }

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return -1;
    }
}