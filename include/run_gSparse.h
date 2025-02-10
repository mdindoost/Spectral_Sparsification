#ifndef RUN_GSPARSE_H
#define RUN_GSPARSE_H

/**
 * @brief Sparsify the given directed, unweighted graph using gSparse.
 * 
 * @param n            Number of nodes in the graph.
 * @param m            Number of edges in the graph.
 * @param src          Array of source vertices for edges.
 * @param dst          Array of destination vertices for edges.
 * @param node_flags   Pointer to an integer array of size n. 
 *                     The function should set node_flags[i] = 1 if node i
 *                     remains in the sparsified graph (has at least one edge)
 *                     and 0 otherwise.
 * 
 * @return int         Returns 0 on success (or any error code you define).
 */
int run_gSparse(
    int n,
    int m,
    const int* src,
    const int* dst,
    int* node_flags
);

#endif // RUN_GSPARSE_H

