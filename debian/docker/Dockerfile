FROM ghcr.io/ricosjp/allgebra/cuda10_1/clang11gcc7/oss:21.05.0
LABEL maintainer "Ryo IGARASHI <rigarash@gmail.com>"

COPY . /monolish

ENV CC /usr/local/llvm-11.0.0/bin/clang 
ENV CXX /usr/local/llvm-11.0.0/bin/clang++ 

RUN apt-get update && apt-get install -y \
    git-buildpackage \ 
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/*

# Build monolish with git-buildpackage
RUN cd /monolish \
 && gbp buildpackage -S
