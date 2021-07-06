FROM ghcr.io/ricosjp/allgebra/cuda10_1/clang11gcc7/oss:21.05.0
LABEL maintainer "Ryo IGARASHI <rigarash@gmail.com>"

COPY . /monolish

ENV CC /usr/local/llvm-11.0.0/bin/clang 
ENV CXX /usr/local/llvm-11.0.0/bin/clang++ 

RUN sed -i -e 's%http://[^ ]\+%mirror://mirrors.ubuntu.com/mirrors.txt%g' /etc/apt/sources.list
RUN apt-get update && apt-get install -y \
    git-buildpackage \ 
    debhelper \
    patchelf \
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/*

# Build monolish with git-buildpackage
WORKDIR /monolish
RUN git clone -b ubuntu/focal/oss https://github.com/rigarash/monolish-debian-package.git \
 && cd monolish-debian-package \
 && gbp buildpackage
