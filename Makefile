CXX      = g++
CXXFLAGS = -std=c++17 -O2

CXXFLAGS += -Iinclude         # so it finds run_gSparse.h
CXXFLAGS += -Iexternal/gSparse/include  # so it finds gSparse headers
# If you have an Eigen submodule or system Eigen, add the appropriate include path here:
CXXFLAGS += -Iexternal/eigen  
# or
# CXXFLAGS += -I/usr/include/eigen3  (if installed in system path)

SRCS = src/run_gSparse.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)

LIB  = libSpectralSparsification.a
APP  = spectral_sparsification_demo

all: $(LIB) $(APP)

$(LIB): src/run_gSparse.o
	@echo "Archiving $@ ..."
	ar rcs $@ $^

$(APP): $(OBJS)
	@echo "Linking $@ ..."
	$(CXX) -o $@ $^  # We also link run_gSparse.o; it's fine that it's also in the static lib

%.o: %.cpp
	@echo "Compiling $< ..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB) $(APP)

