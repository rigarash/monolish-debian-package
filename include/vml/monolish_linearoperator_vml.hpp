// this code is generated by gen_linearoperator_vml.sh
#pragma once

#include "../common/monolish_common.hpp"
#if defined USE_MPI
#include <mpi.h>
#endif

namespace monolish {
/**
 * @brief
 * Vector and Matrix element-wise math library
 */
namespace vml {

/**
 * @brief element by element addition LinearOperator matrix A and
 * LinearOperator matrix B.
 * @param A monolish LinearOperator Matrix (size M x N)
 * @param B monolish LinearOperator Matrix (size M x N)
 * @param C monolish LinearOperator Matrix (size M x N)
 * @note
 * - # of computation: 2 functions
 * - Multi-threading: false
 * - GPU acceleration: false
 */
void add(const matrix::LinearOperator<double> &A,
         const matrix::LinearOperator<double> &B,
         matrix::LinearOperator<double> &C);
void add(const matrix::LinearOperator<float> &A,
         const matrix::LinearOperator<float> &B,
         matrix::LinearOperator<float> &C);

/**
 * @brief element by element subtract LinearOperator matrix A and
 * LinearOperator matrix B.
 * @param A monolish LinearOperator Matrix (size M x N)
 * @param B monolish LinearOperator Matrix (size M x N)
 * @param C monolish LinearOperator Matrix (size M x N)
 * @note
 * - # of computation: 2 functions
 * - Multi-threading: false
 * - GPU acceleration: false
 */
void sub(const matrix::LinearOperator<double> &A,
         const matrix::LinearOperator<double> &B,
         matrix::LinearOperator<double> &C);
void sub(const matrix::LinearOperator<float> &A,
         const matrix::LinearOperator<float> &B,
         matrix::LinearOperator<float> &C);

/**
 * @brief element by element addition LinearOperator matrix A and
 * LinearOperator matrix B.
 * @param A monolish LinearOperator Matrix (size M x N)
 * @param alpha scalar value
 * @param C monolish LinearOperator Matrix (size M x N)
 * @note
 * - # of computation: 2 functions
 * - Multi-threading: false
 * - GPU acceleration: false
 */
void add(const matrix::LinearOperator<double> &A, const double &alpha,
         matrix::LinearOperator<double> &C);
void add(const matrix::LinearOperator<float> &A, const float &alpha,
         matrix::LinearOperator<float> &C);

/**
 * @brief element by element subtract LinearOperator matrix A and
 * LinearOperator matrix B.
 * @param A monolish LinearOperator Matrix (size M x N)
 * @param alpha scalar value
 * @param C monolish LinearOperator Matrix (size M x N)
 * @note
 * - # of computation: 2 functions
 * - Multi-threading: false
 * - GPU acceleration: false
 */
void sub(const matrix::LinearOperator<double> &A, const double &alpha,
         matrix::LinearOperator<double> &C);
void sub(const matrix::LinearOperator<float> &A, const float &alpha,
         matrix::LinearOperator<float> &C);

/**
 * @brief element by element multiplication LinearOperator matrix A and
 * LinearOperator matrix B.
 * @param A monolish LinearOperator Matrix (size M x N)
 * @param alpha scalar value
 * @param C monolish LinearOperator Matrix (size M x N)
 * @note
 * - # of computation: 2 functions
 * - Multi-threading: false
 * - GPU acceleration: false
 */
void mul(const matrix::LinearOperator<double> &A, const double &alpha,
         matrix::LinearOperator<double> &C);
void mul(const matrix::LinearOperator<float> &A, const float &alpha,
         matrix::LinearOperator<float> &C);

/**
 * @brief element by element division LinearOperator matrix A and
 * LinearOperator matrix B.
 * @param A monolish LinearOperator Matrix (size M x N)
 * @param alpha scalar value
 * @param C monolish LinearOperator Matrix (size M x N)
 * @note
 * - # of computation: 2 functions
 * - Multi-threading: false
 * - GPU acceleration: false
 */
void div(const matrix::LinearOperator<double> &A, const double &alpha,
         matrix::LinearOperator<double> &C);
void div(const matrix::LinearOperator<float> &A, const float &alpha,
         matrix::LinearOperator<float> &C);

} // namespace vml
} // namespace monolish
