FROM ghcr.io/ricosjp/allgebra/cuda10_1/clang11gcc7/mkl:20.12.2
LABEL maintainer "Toshiaki Hishinuma <hishinuma.toshiaki@gmail.com>"

COPY . /monolish

ENV MONOLISH_DIR /opt/ricos/monolish/0.3.2
ENV CC /usr/local/llvm-11.0.0/bin/clang 
ENV CXX /usr/local/llvm-11.0.0/bin/clang++ 

RUN apt-get update -y \
 && apt-get install -y python3-pip \
 && apt-get clean && \
 pip3 install monolish-log-viewer==0.1.0

# Build and install libmonolish_gpu.so
RUN cd /monolish && make clean && make install \
 && rm -rf build_cpu \
 && rm -rf build_gpu

RUN echo "${MONOLISH_DIR}/lib" > /etc/ld.so.conf.d/monolish.conf && ldconfig

ENV CPATH              ${MONOLISH_DIR}/include
ENV C_INCLUDE_PATH     ${MONOLISH_DIR}/include
ENV CPLUS_INCLUDE_PATH ${MONOLISH_DIR}/include
ENV LIBRARY_PATH       ${MONOLISH_DIR}/lib
