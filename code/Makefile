CC = g++

MAKE_VIEWER_EXE= -o vu -time
MAKE_GENERATE_EXE= -o gen -time
MAKE_TEST_EXE= -o test -time

GL_FLAGS = -lglut -lGLEW -lGL -lGLU


VORALDO_FLAGS = ../resources/voraldo/v7.cc
CIMG_FLAGS    = -L/usr/X11R6/lib -lm -lpthread -lX11 -std=c++11 -Dcimg_use_png -lpng  -lz
LODEPNG_FLAGS = ../resources/lodepng.cpp -ansi -O3

UNNECCESARY_DEBUG = -Wall -Wextra -pedantic

all: vu gen

vu: vu.cc
	$(CC) vu.cc  $(MAKE_VIEWER_EXE) $(GL_FLAGS) $(LODEPNG_FLAGS) $(CIMG_FLAGS)

gen: gen.cc ../resources/voraldo/v7.cc
	$(CC) gen.cc  $(VORALDO_FLAGS) $(LODEPNG_FLAGS) $(MAKE_GENERATE_EXE) $(GL_FLAGS) $(CIMG_FLAGS)

test: test.cc
	$(CC) test.cc $(VORALDO_FLAGS) $(LODEPNG_FLAGS) $(MAKE_TEST_EXE) $(CIMG_FLAGS)
