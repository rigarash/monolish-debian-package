#include "../test_utils.hpp"

template <typename T> void ans_subvec_op(monolish::vector<T> &vec) {

  for (int i = 0; i < vec.size(); i++) {
    vec[i] = vec[i] + 3;
    vec[i] = vec[i] * 2;
    vec[i] = vec[i] - 1;
    vec[i] = vec[i] / 2;
  }
}

template <typename T>
bool test_diag(const size_t M, const size_t N, double tol) {
  monolish::matrix::Dense<T> A(M, N, 10.0); // M*N matrix

  monolish::vector<T> vec(A.get_row(), 2.0);
  monolish::vector<T> ansvec(A.get_row(), 2.0);

  A.diag(ansvec);
  ans_subvec_op(ansvec);

  A.diag_add(3.0);
  A.diag_mul(2.0);
  A.diag_sub(1.0);
  A.diag_div(2.0);
  A.diag(vec);

  return ans_check<T>(__func__, A.type(), ansvec.data(), vec.data(), vec.size(),
                      tol);
}

int main(int argc, char **argv) {

  if (argc != 3) {
    std::cout << "$1: row, $2: col" << std::endl;
    return 1;
  }

  const size_t M = atoi(argv[1]);
  const size_t N = atoi(argv[2]);

  // monolish::util::set_log_level(3);
  // monolish::util::set_log_filename("./monolish_test_log.txt");

  std::cout << "M=" << M << ", N=" << N << std::endl;

  if (test_diag<double>(M, M, 1.0e-8) == false) {
    return 1;
  }
  if (test_diag<float>(M, M, 1.0e-8) == false) {
    return 1;
  }

  return 0;
}
