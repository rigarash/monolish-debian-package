#include<iostream>
#include"../../test_utils.hpp"
#include"monolish_blas.hpp"

template <typename T>
void get_ans(monolish::matrix::Dense<T> &A, monolish::vector<T> &mx, monolish::vector<T> &my){

	if(A.get_col() != mx.size()){
		std::runtime_error("A.col != x.size");
	}
	if(A.get_col() != mx.size()){
		std::runtime_error("A.row != y.size");
	}

	T* x = mx.data();
	T* y = my.data();
    int M = A.get_row();
    int N = A.get_col();

	for(int i = 0; i < my.size(); i++)
		y[i] = 0;

	for(int i = 0; i < M; i++){
	    for(int j = 0; j < N; j++){
			y[i] += A.val[N * i + j] * x[j];
		}
	}
}

template <typename T>
bool test(const size_t M, const size_t N, double tol, int iter, int check_ans){

	monolish::matrix::Dense<T> A(M, N, 0.0, 1.0); // M*N matrix
	monolish::vector<T> x(A.get_col(), 0.0, 1.0);
	monolish::vector<T> y(A.get_row(), 0.0, 1.0);

	monolish::vector<T> ansy(A.get_row());
	ansy = y;

	if(check_ans == 1){
		get_ans(A, x, ansy);
		monolish::util::send(A, x, y);
		monolish::blas::matvec(A, x, y);
		y.recv();
		if(ans_check<T>(y.data(), ansy.data(), y.size(), tol) == false){
			return false;
		};
        A.device_free();
        x.device_free();
	}
	monolish::util::send(A, x, y);

	auto start = std::chrono::system_clock::now();

	for(int i = 0; i < iter; i++){
		monolish::blas::matvec(A, x, y);
	}

	auto end = std::chrono::system_clock::now();
	double sec = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()/1.0e+9;

 	A.device_free();
 	x.device_free();
 	y.device_free();

	std::cout << "average time: " << sec/iter << std::endl;

	return true;
}

int main(int argc, char** argv){

	if(argc!=5){
		std::cout << "error $1: row, $2: col, $3: iter, $3: error check (1/0)" << std::endl;
		return 1;
	}

	const size_t M = atoi(argv[1]);
    const size_t N = atoi(argv[2]);
	int iter = atoi(argv[3]);
	int check_ans = atoi(argv[4]);

	// monolish::util::set_log_level(3);
	// monolish::util::set_log_filename("./monolish_test_log.txt");

	if( test<double>(M, N, 1.0e-6, iter, check_ans) == false){ return 1; }
	if( test<float>(M, N, 1.0e-3, iter, check_ans) == false){ return 1; }

	return 0;
}