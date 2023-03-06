include=-I../../include
libpath=-L../../lib
libs=-lNatNet -lGLU -lGL -lglut -lstdc++ -lm -lglfw -lGLEW -ldl -lpthread -lgomp #-lHL -lHLU -lHDU -lHD
CXXFLAGS=-fopenmp
all:main

main: 
	g++ main.cpp $(CXXFLAGS) $(include) $(libpath) $(libs) -o main

.PHONY: clean
clean:
	@rm -f ./main
