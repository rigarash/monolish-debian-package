C=const

echo "#pragma once
#include \"../common/monolish_common.hpp\"
#include <stdio.h>
#include <vector>

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
"


## matvec Dense
echo "
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
 */ "
for prec in double float; do
  for arg1 in vector\<$prec\> view1D\<vector\<$prec\>,$prec\> view1D\<matrix::Dense\<$prec\>,$prec\>; do
    for arg2 in vector\<$prec\> view1D\<vector\<$prec\>,$prec\> view1D\<matrix::Dense\<$prec\>,$prec\>; do
      echo "void matvec(const matrix::Dense<$prec> &A, const $arg1 &x, $arg2 &y);"
    done
  done
done

echo ""

## matvec CRS
echo "
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
 */ "
for prec in double float; do
  for arg1 in vector\<$prec\> view1D\<vector\<$prec\>,$prec\> view1D\<matrix::Dense\<$prec\>,$prec\>; do
    for arg2 in vector\<$prec\> view1D\<vector\<$prec\>,$prec\> view1D\<matrix::Dense\<$prec\>,$prec\>; do
      echo "void matvec(const matrix::CRS<$prec> &A, const $arg1 &x, $arg2 &y);"
    done
  done
done

echo ""

## matvec LinearOperator
echo "
/**
 * @brief matrix (LinearOperator) and vector multiplication: y = Ax
 * @param A LinearOperator (size M x N)
 * @param x monolish vector (size N)
 * @param y monolish vector (size M)
 * @note
 * - # of computation: depends on matvec function
 * - Multi-threading: depends on matvec function
 * - GPU acceleration: depends on matvec function
 */ "
for prec in double float; do
  for arg1 in vector\<$prec\> view1D\<vector\<$prec\>,$prec\> view1D\<matrix::Dense\<$prec\>,$prec\>; do
    for arg2 in vector\<$prec\> view1D\<vector\<$prec\>,$prec\> view1D\<matrix::Dense\<$prec\>,$prec\>; do
      echo "void matvec(const matrix::LinearOperator<$prec> &A, const $arg1 &x, $arg2 &y);"
    done
  done
done

## rmatvec LinearOperator
echo "
/**
 * @brief matrix (LinearOperator) and vector multiplication: y = Ax
 * @param A LinearOperator (size M x N)
 * @param x monolish vector (size N)
 * @param y monolish vector (size M)
 * @note
 * - # of computation: depends on matvec function
 * - Multi-threading: depends on matvec function
 * - GPU acceleration: depends on matvec function
 */ "
for prec in double float; do
  for arg1 in vector\<$prec\> view1D\<vector\<$prec\>,$prec\> view1D\<matrix::Dense\<$prec\>,$prec\>; do
    for arg2 in vector\<$prec\> view1D\<vector\<$prec\>,$prec\> view1D\<matrix::Dense\<$prec\>,$prec\>; do
      echo "void rmatvec(const matrix::LinearOperator<$prec> &A, const $arg1 &x, $arg2 &y);"
    done
  done
done

echo "
} // namespace blas
} // namespace monolish"
