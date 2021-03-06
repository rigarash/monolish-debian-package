// this code is generated by gen_matvec_blas.sh
#pragma once
#include "../common/monolish_common.hpp"

#if defined USE_MPI
#include <mpi.h>
#endif

namespace monolish {
/**
 * @brief
 * Basic Linear Algebra Subprograms for Dense Matrix, Sparse Matrix, Vector and
 * Scalar
 */
namespace blas {

/**
 * @brief Dense matrix and vector multiplication: y = Ax
 * @param A Dense matrix (size M x N)
 * @param x monolish vector (size M)
 * @param y monolish vector (size M)
 * @note
 * - # of computation: MN
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void matvec(const matrix::Dense<double> &A, const vector<double> &x,
            vector<double> &y);
void matvec(const matrix::Dense<double> &A, const vector<double> &x,
            view1D<vector<double>, double> &y);
void matvec(const matrix::Dense<double> &A, const vector<double> &x,
            view1D<matrix::Dense<double>, double> &y);
void matvec(const matrix::Dense<double> &A,
            const view1D<vector<double>, double> &x, vector<double> &y);
void matvec(const matrix::Dense<double> &A,
            const view1D<vector<double>, double> &x,
            view1D<vector<double>, double> &y);
void matvec(const matrix::Dense<double> &A,
            const view1D<vector<double>, double> &x,
            view1D<matrix::Dense<double>, double> &y);
void matvec(const matrix::Dense<double> &A,
            const view1D<matrix::Dense<double>, double> &x, vector<double> &y);
void matvec(const matrix::Dense<double> &A,
            const view1D<matrix::Dense<double>, double> &x,
            view1D<vector<double>, double> &y);
void matvec(const matrix::Dense<double> &A,
            const view1D<matrix::Dense<double>, double> &x,
            view1D<matrix::Dense<double>, double> &y);
void matvec(const matrix::Dense<float> &A, const vector<float> &x,
            vector<float> &y);
void matvec(const matrix::Dense<float> &A, const vector<float> &x,
            view1D<vector<float>, float> &y);
void matvec(const matrix::Dense<float> &A, const vector<float> &x,
            view1D<matrix::Dense<float>, float> &y);
void matvec(const matrix::Dense<float> &A,
            const view1D<vector<float>, float> &x, vector<float> &y);
void matvec(const matrix::Dense<float> &A,
            const view1D<vector<float>, float> &x,
            view1D<vector<float>, float> &y);
void matvec(const matrix::Dense<float> &A,
            const view1D<vector<float>, float> &x,
            view1D<matrix::Dense<float>, float> &y);
void matvec(const matrix::Dense<float> &A,
            const view1D<matrix::Dense<float>, float> &x, vector<float> &y);
void matvec(const matrix::Dense<float> &A,
            const view1D<matrix::Dense<float>, float> &x,
            view1D<vector<float>, float> &y);
void matvec(const matrix::Dense<float> &A,
            const view1D<matrix::Dense<float>, float> &x,
            view1D<matrix::Dense<float>, float> &y);

/**
 * @brief sparse matrix (CRS) and vector multiplication: y = Ax
 * @param A CRS matrix (size M x N)
 * @param x monolish vector (size M)
 * @param y monolish vector (size M)
 * @note
 * - # of computation: 2nnz
 * - Multi-threading: true
 * - GPU acceleration: true
 *    - # of data transfer: 0
 */
void matvec(const matrix::CRS<double> &A, const vector<double> &x,
            vector<double> &y);
void matvec(const matrix::CRS<double> &A, const vector<double> &x,
            view1D<vector<double>, double> &y);
void matvec(const matrix::CRS<double> &A, const vector<double> &x,
            view1D<matrix::Dense<double>, double> &y);
void matvec(const matrix::CRS<double> &A,
            const view1D<vector<double>, double> &x, vector<double> &y);
void matvec(const matrix::CRS<double> &A,
            const view1D<vector<double>, double> &x,
            view1D<vector<double>, double> &y);
void matvec(const matrix::CRS<double> &A,
            const view1D<vector<double>, double> &x,
            view1D<matrix::Dense<double>, double> &y);
void matvec(const matrix::CRS<double> &A,
            const view1D<matrix::Dense<double>, double> &x, vector<double> &y);
void matvec(const matrix::CRS<double> &A,
            const view1D<matrix::Dense<double>, double> &x,
            view1D<vector<double>, double> &y);
void matvec(const matrix::CRS<double> &A,
            const view1D<matrix::Dense<double>, double> &x,
            view1D<matrix::Dense<double>, double> &y);
void matvec(const matrix::CRS<float> &A, const vector<float> &x,
            vector<float> &y);
void matvec(const matrix::CRS<float> &A, const vector<float> &x,
            view1D<vector<float>, float> &y);
void matvec(const matrix::CRS<float> &A, const vector<float> &x,
            view1D<matrix::Dense<float>, float> &y);
void matvec(const matrix::CRS<float> &A, const view1D<vector<float>, float> &x,
            vector<float> &y);
void matvec(const matrix::CRS<float> &A, const view1D<vector<float>, float> &x,
            view1D<vector<float>, float> &y);
void matvec(const matrix::CRS<float> &A, const view1D<vector<float>, float> &x,
            view1D<matrix::Dense<float>, float> &y);
void matvec(const matrix::CRS<float> &A,
            const view1D<matrix::Dense<float>, float> &x, vector<float> &y);
void matvec(const matrix::CRS<float> &A,
            const view1D<matrix::Dense<float>, float> &x,
            view1D<vector<float>, float> &y);
void matvec(const matrix::CRS<float> &A,
            const view1D<matrix::Dense<float>, float> &x,
            view1D<matrix::Dense<float>, float> &y);

/**
 * @brief matrix (LinearOperator) and vector multiplication: y = Ax
 * @param A LinearOperator (size M x N)
 * @param x monolish vector (size N)
 * @param y monolish vector (size M)
 * @note
 * - # of computation: depends on matvec function
 * - Multi-threading: depends on matvec function
 * - GPU acceleration: depends on matvec function
 */
void matvec(const matrix::LinearOperator<double> &A, const vector<double> &x,
            vector<double> &y);
void matvec(const matrix::LinearOperator<double> &A, const vector<double> &x,
            view1D<vector<double>, double> &y);
void matvec(const matrix::LinearOperator<double> &A, const vector<double> &x,
            view1D<matrix::Dense<double>, double> &y);
void matvec(const matrix::LinearOperator<double> &A,
            const view1D<vector<double>, double> &x, vector<double> &y);
void matvec(const matrix::LinearOperator<double> &A,
            const view1D<vector<double>, double> &x,
            view1D<vector<double>, double> &y);
void matvec(const matrix::LinearOperator<double> &A,
            const view1D<vector<double>, double> &x,
            view1D<matrix::Dense<double>, double> &y);
void matvec(const matrix::LinearOperator<double> &A,
            const view1D<matrix::Dense<double>, double> &x, vector<double> &y);
void matvec(const matrix::LinearOperator<double> &A,
            const view1D<matrix::Dense<double>, double> &x,
            view1D<vector<double>, double> &y);
void matvec(const matrix::LinearOperator<double> &A,
            const view1D<matrix::Dense<double>, double> &x,
            view1D<matrix::Dense<double>, double> &y);
void matvec(const matrix::LinearOperator<float> &A, const vector<float> &x,
            vector<float> &y);
void matvec(const matrix::LinearOperator<float> &A, const vector<float> &x,
            view1D<vector<float>, float> &y);
void matvec(const matrix::LinearOperator<float> &A, const vector<float> &x,
            view1D<matrix::Dense<float>, float> &y);
void matvec(const matrix::LinearOperator<float> &A,
            const view1D<vector<float>, float> &x, vector<float> &y);
void matvec(const matrix::LinearOperator<float> &A,
            const view1D<vector<float>, float> &x,
            view1D<vector<float>, float> &y);
void matvec(const matrix::LinearOperator<float> &A,
            const view1D<vector<float>, float> &x,
            view1D<matrix::Dense<float>, float> &y);
void matvec(const matrix::LinearOperator<float> &A,
            const view1D<matrix::Dense<float>, float> &x, vector<float> &y);
void matvec(const matrix::LinearOperator<float> &A,
            const view1D<matrix::Dense<float>, float> &x,
            view1D<vector<float>, float> &y);
void matvec(const matrix::LinearOperator<float> &A,
            const view1D<matrix::Dense<float>, float> &x,
            view1D<matrix::Dense<float>, float> &y);

/**
 * @brief matrix (LinearOperator) and vector multiplication: y = Ax
 * @param A LinearOperator (size M x N)
 * @param x monolish vector (size N)
 * @param y monolish vector (size M)
 * @note
 * - # of computation: depends on matvec function
 * - Multi-threading: depends on matvec function
 * - GPU acceleration: depends on matvec function
 */
void rmatvec(const matrix::LinearOperator<double> &A, const vector<double> &x,
             vector<double> &y);
void rmatvec(const matrix::LinearOperator<double> &A, const vector<double> &x,
             view1D<vector<double>, double> &y);
void rmatvec(const matrix::LinearOperator<double> &A, const vector<double> &x,
             view1D<matrix::Dense<double>, double> &y);
void rmatvec(const matrix::LinearOperator<double> &A,
             const view1D<vector<double>, double> &x, vector<double> &y);
void rmatvec(const matrix::LinearOperator<double> &A,
             const view1D<vector<double>, double> &x,
             view1D<vector<double>, double> &y);
void rmatvec(const matrix::LinearOperator<double> &A,
             const view1D<vector<double>, double> &x,
             view1D<matrix::Dense<double>, double> &y);
void rmatvec(const matrix::LinearOperator<double> &A,
             const view1D<matrix::Dense<double>, double> &x, vector<double> &y);
void rmatvec(const matrix::LinearOperator<double> &A,
             const view1D<matrix::Dense<double>, double> &x,
             view1D<vector<double>, double> &y);
void rmatvec(const matrix::LinearOperator<double> &A,
             const view1D<matrix::Dense<double>, double> &x,
             view1D<matrix::Dense<double>, double> &y);
void rmatvec(const matrix::LinearOperator<float> &A, const vector<float> &x,
             vector<float> &y);
void rmatvec(const matrix::LinearOperator<float> &A, const vector<float> &x,
             view1D<vector<float>, float> &y);
void rmatvec(const matrix::LinearOperator<float> &A, const vector<float> &x,
             view1D<matrix::Dense<float>, float> &y);
void rmatvec(const matrix::LinearOperator<float> &A,
             const view1D<vector<float>, float> &x, vector<float> &y);
void rmatvec(const matrix::LinearOperator<float> &A,
             const view1D<vector<float>, float> &x,
             view1D<vector<float>, float> &y);
void rmatvec(const matrix::LinearOperator<float> &A,
             const view1D<vector<float>, float> &x,
             view1D<matrix::Dense<float>, float> &y);
void rmatvec(const matrix::LinearOperator<float> &A,
             const view1D<matrix::Dense<float>, float> &x, vector<float> &y);
void rmatvec(const matrix::LinearOperator<float> &A,
             const view1D<matrix::Dense<float>, float> &x,
             view1D<vector<float>, float> &y);
void rmatvec(const matrix::LinearOperator<float> &A,
             const view1D<matrix::Dense<float>, float> &x,
             view1D<matrix::Dense<float>, float> &y);

} // namespace blas
} // namespace monolish
