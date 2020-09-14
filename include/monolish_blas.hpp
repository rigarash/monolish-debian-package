#pragma once
#include "common/monolish_common.hpp"
#include <omp.h>
#include <stdio.h>
#include <vector>

#if defined USE_MPI
#include <mpi.h>
#endif

namespace monolish {
namespace blas {

////////////vector////////////////////

//////////////////////////////////////////////////////
//  T asum
//////////////////////////////////////////////////////
/**
 * @brief double precision vector asum (absolute sum)
 * @param[in] x double precision monolish vector
 * @return The result of the asum
 */
double asum(const vector<double> &x);
float asum(const vector<float> &x);

//////////////////////////////////////////////////////
//  void asum
//////////////////////////////////////////////////////
/**
 * @brief double precision vector asum (absolute sum)
 * @param[in] x double precision monolish vector
 * @param[in] ans result value
 */
void asum(const vector<double> &x, double &ans);
void asum(const vector<float> &x, float &ans);

//////////////////////////////////////////////////////
//  T sum
//////////////////////////////////////////////////////
/**
 * @brief double precision vector sum
 * @param[in] x double precision monolish vector
 * @return The result of the sum
 */
double sum(const vector<double> &x);
float sum(const vector<float> &x);

//////////////////////////////////////////////////////
//  void sum
//////////////////////////////////////////////////////
/**
 * @brief double precision vector sum
 * @param[in] x double precision monolish vector
 * @param[in] ans result value
 */
void sum(const vector<double> &x, double &ans);
void sum(const vector<float> &x, float &ans);

//////////////////////////////////////////////////////
//  axpy
//////////////////////////////////////////////////////
/**
 * @brief double precision axpy: y = ax + y
 * @param[in] alpha double precision scalar value
 * @param[in] x double precision monolish vector
 * @param[in] y double precision monolish vector
 */
void axpy(const double alpha, const vector<double> &x, vector<double> &y);
void axpy(const float alpha, const vector<float> &x, vector<float> &y);

//////////////////////////////////////////////////////
//  axpyz
//////////////////////////////////////////////////////
/**
 * @brief double precision axpyz: z = ax + y
 * @param[in] alpha double precision scalar value
 * @param[in] x double precision monolish vector
 * @param[in] y double precision monolish vector
 * @param[in] z double precision monolish vector
 */
void axpyz(const double alpha, const vector<double> &x, const vector<double> &y,
           vector<double> &z);
void axpyz(const float alpha, const vector<float> &x, const vector<float> &y,
           vector<float> &z);

//////////////////////////////////////////////////////
//  T dot
//////////////////////////////////////////////////////
/**
 * @brief double precision inner product (dot)
 * @param[in] x double precision monolish vector
 * @param[in] y double precision monolish vector
 * @return The result of the inner product product of x and y
 */
double dot(const vector<double> &x, const vector<double> &y);

/**
 * @brief float precision inner product (dot)
 * @param[in] x float precision monolish vector
 * @param[in] y float precision monolish vector
 * @return The result of the inner product product of x and y
 */
float dot(const vector<float> &x, const vector<float> &y);

//////////////////////////////////////////////////////
//  void dot
//////////////////////////////////////////////////////
/**
 * @brief double precision inner product (dot)
 * @param[in] x double precision monolish vector
 * @param[in] y double precision monolish vector
 * @param[in] ans result value
 */
void dot(const vector<double> &x, const vector<double> &y, double &ans);

/**
 * @brief float precision inner product (dot)
 * @param[in] x float precision monolish vector
 * @param[in] y float precision monolish vector
 * @param[in] ans result value
 */
void dot(const vector<float> &x, const vector<float> &y, float &ans);

//////////////////////////////////////////////////////
//  T nrm2
//////////////////////////////////////////////////////
/**
 * @brief double precision nrm2: ||x||_2
 * @param[in] x double precision monolish vector
 * @return The result of the nrm2
 */
double nrm2(const vector<double> &x);
float nrm2(const vector<float> &x);

//////////////////////////////////////////////////////
//  void nrm2
//////////////////////////////////////////////////////
/**
 * @brief double precision nrm2: ||x||_2
 * @param[in] x double precision monolish vector
 * @param[in] ans result value
 */
void nrm2(const vector<double> &x, double &ans);
void nrm2(const vector<float> &x, float &ans);

//////////////////////////////////////////////////////
//  scal
//////////////////////////////////////////////////////
/**
 * @brief double precision scal: x = alpha * x
 * @param[in] alpha double precision scalar value
 * @param[in] x double precision monolish vector
 */
void scal(const double alpha, vector<double> &x);
void scal(const float alpha, vector<float> &x);

//////////////////////////////////////////////////////
//  xpay
//////////////////////////////////////////////////////
/**
 * @brief double precision xpay: y = x + ay
 * @param[in] alpha double precision scalar value
 * @param[in] x double precision monolish vector
 * @param[in] y double precision monolish vector
 * @param[in] z double precision monolish vector
 */
void xpay(const double alpha, const vector<double> &x, vector<double> &y);
void xpay(const float alpha, const vector<float> &x, vector<float> &y);

//////////////////////////////////////////////////////
//  matrix scale
//////////////////////////////////////////////////////
/**
 * @brief double precision scal: A = alpha * A
 * @param[in] alpha double precision scalar value
 * @param[in] A double precision CRS matrix
 */
void mscal(const double alpha, matrix::Dense<double> &A);
void mscal(const float alpha, matrix::Dense<float> &A);

/**
 * @brief double precision scal: A = alpha * A
 * @param[in] alpha double precision scalar value
 * @param[in] A double precision CRS matrix
 */
void mscal(const double alpha, matrix::CRS<double> &A);
void mscal(const float alpha, matrix::CRS<float> &A);

//////////////////////////////////////////////////////
//  matvec
//////////////////////////////////////////////////////
/**
 * @brief double precision Dense matrix and vector multiplication: y = Ax
 * @param[in] A double precision Dense matrix
 * @param[in] x double precision monolish vector
 * @param[in] y double precision monolish vector
 */
void matvec(const matrix::Dense<double> &A, const vector<double> &x,
            vector<double> &y);
void matvec(const matrix::Dense<float> &A, const vector<float> &x,
            vector<float> &y);

/**
 * @brief double precision sparse matrix (CRS) and vector multiplication: y = Ax
 * @param[in] A double precision CRS matrix
 * @param[in] x double precision monolish vector
 * @param[in] y double precision monolish vector
 */
void matvec(const matrix::CRS<double> &A, const vector<double> &x,
            vector<double> &y);
void matvec(const matrix::CRS<float> &A, const vector<float> &x,
            vector<float> &y);

//////////////////////////////////////////////////////
//  matadd
//////////////////////////////////////////////////////
/**
 * @brief double precision Dense matrix addition: C = AB (A and B must be same
 * structure)
 * @param[in] A double precision CRS matrix
 * @param[in] B double precision CRS matrix
 * @param[in] C double precision CRS matrix
 */
void matadd(const matrix::CRS<double> &A, const matrix::CRS<double> &B,
            matrix::CRS<double> &C);
void matadd(const matrix::CRS<float> &A, const matrix::CRS<float> &B,
            matrix::CRS<float> &C);

/**
 * @brief double precision Dense matrix addition: C = AB
 * @param[in] A double precision Dense matrix
 * @param[in] B double precision Dense matrix
 * @param[in] C double precision Dense matrix
 */
void matadd(const matrix::Dense<double> &A, const matrix::Dense<double> &B,
            matrix::Dense<double> &C);
void matadd(const matrix::Dense<float> &A, const matrix::Dense<float> &B,
            matrix::Dense<float> &C);

//////////////////////////////////////////////////////
//  matmul
//////////////////////////////////////////////////////
/**
 * @brief double precision Dense matrix multiplication: C = AB
 * @param[in] A double precision CRS matrix
 * @param[in] B double precision Dense matrix
 * @param[in] C double precision Dense matrix
 */
void matmul(const matrix::CRS<double> &A, const matrix::Dense<double> &B,
            matrix::Dense<double> &C);
void matmul(const matrix::CRS<float> &A, const matrix::Dense<float> &B,
            matrix::Dense<float> &C);

/**
 * @brief double precision Dense matrix multiplication: C = AB
 * @param[in] A double precision Dense matrix
 * @param[in] B double precision Dense matrix
 * @param[in] C double precision Dense matrix
 */
void matmul(const matrix::Dense<double> &A, const matrix::Dense<double> &B,
            matrix::Dense<double> &C);
void matmul(const matrix::Dense<float> &A, const matrix::Dense<float> &B,
            matrix::Dense<float> &C);

} // namespace blas
} // namespace monolish
