#include "../../../include/common/monolish_dense.hpp"
#include "../../../include/common/monolish_logger.hpp"
#include "../../../include/common/monolish_matrix.hpp"
#include "../../../include/common/monolish_vector.hpp"
#include "../../../include/monolish_blas.hpp"
#include "../../internal/monolish_internal.hpp"

#include <fstream>
#include <iomanip>
#include <limits>
#include <sstream>

namespace monolish {
namespace matrix {

template <typename T> void LinearOperator<T>::convert(COO<T> &coo) {
  Logger &logger = Logger::get_instance();
  logger.util_in(monolish_func);

  // todo coo err check (only square)

  rowN = coo.get_row();
  colN = coo.get_col();

  gpu_status = coo.get_device_mem_stat();

  set_matvec([&](const monolish::vector<T> &VEC) {
    CRS<T> crs(coo);
    monolish::vector<T> vec(crs.get_row(), 0);
    monolish::blas::matvec(crs, VEC, vec);
    return vec;
  });
  rmatvec_init_flag = false;

  logger.util_out();
}

template void LinearOperator<double>::convert(COO<double> &coo);
template void LinearOperator<float>::convert(COO<float> &coo);

template <typename T> void LinearOperator<T>::convert(CRS<T> &crs) {
  Logger &logger = Logger::get_instance();
  logger.util_in(monolish_func);

  // todo crs err check (only square)

  rowN = crs.get_row();
  colN = crs.get_col();

  gpu_status = crs.get_device_mem_stat();

  set_matvec([&](const monolish::vector<T> &VEC) {
    monolish::vector<T> vec(crs.get_row(), 0);
    if (gpu_status) {
      monolish::util::send(vec);
    }
    monolish::blas::matvec(crs, VEC, vec);
    return vec;
  });
  rmatvec_init_flag = false;

  logger.util_out();
}

template void LinearOperator<double>::convert(CRS<double> &crs);
template void LinearOperator<float>::convert(CRS<float> &crs);

template <typename T>
void LinearOperator<T>::convert_to_Dense(Dense<T> &dense) const {
  if (!matvec_init_flag) {
    Dense<T> A(rowN, colN);
    dense = A;
    return;
  }

  std::vector<T> values(rowN * colN);
  for (size_t i = 0; i < colN; ++i) {
    std::vector<T> vec_tmp(colN, 0);
    vec_tmp[i] = 1;
    vector<T> vec(vec_tmp);
    vector<T> ans(rowN);
    if (gpu_status) {
      util::send(ans, vec);
    }
    ans = matvec(vec);
    if (gpu_status) {
      util::recv(ans);
    }
    for (size_t j = 0; j < rowN; ++j) {
      values[j * colN + i] = ans[j];
    }
  }

  dense = Dense<T>(rowN, colN, values);
}

template void LinearOperator<double>::convert_to_Dense(Dense<double> &) const;
template void LinearOperator<float>::convert_to_Dense(Dense<float> &) const;

} // namespace matrix
} // namespace monolish
