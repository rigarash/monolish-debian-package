#include "../../test_utils.hpp"

template <typename T> void ans_vsign(monolish::vector<T> &ans) {
  for (size_t i = 0; i < ans.size(); i++) {
    ans[i] = -1 * ans[i];
  }
}

template <typename T> bool test_send_vsign(const size_t size, double tol) {

  monolish::vector<T> ans(size, 0.1, 10.0);

  monolish::vector<T> ans_tmp;
  ans_tmp = ans.copy();
  ans_vsign(ans_tmp);

  monolish::util::send(ans);
  monolish::vml::sign(ans, ans);
  ans.recv();

  return ans_check<T>(__func__, ans.data(), ans_tmp.data(), ans.size(), tol);
}

template <typename T> bool test_vsign(const size_t size, double tol) {

  monolish::vector<T> ans(size, 0.1, 10.0);

  monolish::vector<T> ans_tmp;
  ans_tmp = ans.copy();
  ans_vsign(ans_tmp);

  monolish::vml::sign(ans, ans);

  return ans_check<T>(__func__, ans.data(), ans_tmp.data(), ans.size(), tol);
}