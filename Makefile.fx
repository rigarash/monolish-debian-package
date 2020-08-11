TARGET=./lib/libmonolish_fx.so

MONOLISH_DIR?=$(HOME)/lib/monolish

CXX=FCC
#CXXFLAGS = -Nclang -O3 -Ofast -fopenmp -std=c++14 -fPIC -fvectorize -Nlibomp
CXXFLAGS = -Kfast,openmp,zfill,parallel,simd,reduction -std=c++14 -lm -fPIC -Kopenmp -Nlibomp
#CXXFLAGS	 += -Nsrc -Koptmsg=2
CXXFLAGS += $(CXXFLAGS_EXTRA)

LIBFLAGS = -shared 
#BLAS_LIB = -SSL2BLAMP
#BLAS_LIB = -Kopenmp -SSL2BLAMP

####################


####################

# need mumps 
# MUMPS_INC ?= -I ./external/obj/mumps/include/
# MUMPS_OBJ ?= \
# -L ./external/obj/mumps/lib/libpord.a \
# -L ./external/obj/mumps/lib/libdmumps.a \
# -L ./external/obj/mumps/lib/libmumps_common.a

####################

LIB_INC=$(BLAS_INC) $(MUMPS_INC)
LIB_OBJ=$(BLAS_LIB) $(MUMPS_OBJ)

####################

SRCS =$(notdir $(wildcard  ./src/*.cpp))

SRCS +=$(notdir $(wildcard ./src/equation/*.cpp))
SRCS +=$(notdir $(wildcard ./src/equation/*/*.cpp))

SRCS +=$(notdir $(wildcard ./src/blas/*.cpp))
SRCS +=$(notdir $(wildcard ./src/blas/*/*.cpp))

SRCS +=$(notdir $(wildcard ./src/utils/*.cpp))

#############################################################

vpath %.cpp ./src/

vpath %.cpp ./src/equation/
vpath %.cpp ./src/equation/lu/
vpath %.cpp ./src/equation/qr/
vpath %.cpp ./src/equation/cholesky/

vpath %.cpp ./src/blas/arithmetic/
vpath %.cpp ./src/blas/vector/
vpath %.cpp ./src/blas/matrix/

vpath %.cpp ./src/utils/

#############################################################

.PHONY = libs test clean

OBJDIR=./obj/fx/

OBJS=$(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p lib
	$(CXX) $(CXXFLAGS) $(LIBFLAGS) $(OBJS) $(LIB_INC) $(LIB_OBJ) -o $(TARGET) $(LIB_INC) $(LIB_OBJ) 

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(LIB_INC) $(LIB_OBJ) -I../include -c $< -o $@ 

libs:
	git submodule update -i
	make -C external

test:
	cd test; make; make run
	
install:
	-mkdir -p $(MONOLISH_DIR)
	-mkdir -p $(MONOLISH_DIR)/external
	-cp -r lib $(MONOLISH_DIR)
	-cp -r include $(MONOLISH_DIR)
	-cp -r external/obj $(MONOLISH_DIR)/external/
	-cp -r external/obj $(MONOLISH_DIR)/external/


clean:
	- rm $(OBJDIR)/*
	- rm lib/*
	- rm -r $(MONOLISH_DIR)
