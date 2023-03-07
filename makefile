# include=-I../../include
# libpath=-L../../lib
libs=-lGLU -lGL -lglut -lstdc++ -lm -lglfw -lGLEW -ldl -lpthread -lgomp #-lNatNet -lHL -lHLU -lHDU -lHD
CXXFLAGS=-fopenmp
all:main

main: 
	g++ main.cpp $(CXXFLAGS) $(include) $(libpath) $(libs) -o main

.PHONY: clean
clean:
	@rm -f ./main
