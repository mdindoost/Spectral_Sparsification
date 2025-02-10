#include "run_gSparse.h"



// Include the master header for gSparse
#include <gSparse/gSparse.hpp>
// Include Eigen (either from submodule or system path):
// If you have Eigen submodule at external/eigen, use: #include "external/eigen/Eigen/Sparse"
// If Eigen is installed on your system, just: #include <Eigen/Sparse>

#include <Eigen/Sparse>

// Include the gSparse headers (adjust path as needed):
#include "gSparse/Interface/EffectiveResistance.hpp"

#include <vector>

int run_gSparse(
    int n,
    int m,
    const int* src,
    const int* dst,
    int* node_flags
)
{
    // 1. Build an Eigen SparseMatrix from src/dst
    //    NOTE: gSparse is generally for undirected or graph Laplacians,
    //    but we'll show how to create it from directed edges too.
    typedef Eigen::Triplet<double> T;
    std::vector<T> tripletList;
    tripletList.reserve(m);

    for (int i = 0; i < m; i++) {
        // Since graph is directed, only add (src[i], dst[i]) with weight 1.0
        tripletList.emplace_back(src[i], dst[i], 1.0);

        // If you want an undirected adjacency in practice:
        // tripletList.emplace_back(dst[i], src[i], 1.0);
    }

    Eigen::SparseMatrix<double> A(n, n);
    A.setFromTriplets(tripletList.begin(), tripletList.end());

    // 2. Use gSparse to compute the spectral sparsifier
    //    The function signature may vary, so adapt to whichever 
    //    gSparse function you need. For example:
    //
    //    auto A_sparsified = gSparse::SpectralSparsification::
    //        ComputeEffectiveResistanceSparsifier(
    //            A, [some fraction or target number of edges?], ...
    //        );
    //
    // Below is just a placeholder to compile. 
    // Check the gSparse usage for actual arguments.
    Eigen::SparseMatrix<double> A_sparsified;
    {
        // Example:
        // double epsilon = 0.5;  // A parameter controlling approximation
        // int targetEdges = ...;
        // A_sparsified = gSparse::SpectralSparsification::ComputeEffectiveResistanceSparsifier(A, epsilon);

        // For now, let's just copy A (no actual sparsification done):
        A_sparsified = A;
    }

    // 3. Based on the sparsified matrix, mark which nodes have at least one edge
    //    node_flags[i] = 1 if node i has at least one nonzero entry, else 0
    // 
    // A_sparsified.outerSize() is n; we can iterate column-by-column or row-by-row.
    for (int i = 0; i < n; i++) {
        node_flags[i] = 0;  // default
    }

    // Let's iterate by column (standard in Eigen's SparseMatrix):
    for (int col = 0; col < A_sparsified.outerSize(); col++) {
        for (Eigen::SparseMatrix<double>::InnerIterator it(A_sparsified, col); it; ++it) {
            int row = it.row();
            int thisCol = it.col();
            // it.value() is the weight (if nonzero, there's an edge)
            node_flags[row] = 1;
            node_flags[thisCol] = 1;
        }
    }

    return 0;  // or some success/error code
}

