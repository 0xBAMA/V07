CC = g++

MAKE_VIEWER_EXE= -o vu -time
MAKE_GENERATE_EXE= -o gen -time

GL_FLAGS = -lglut -lGLEW -lGL -lGLU


VORALDO_FLAGS = ../resources/voraldo/v.cc
CIMG_FLAGS    = -L/usr/X11R6/lib -lm -lpthread -lX11 -std=c++11 -Dcimg_use_png -lpng  -lz
LODEPNG_FLAGS = ../resources/lodepng.cpp -ansi -O3

UNNECCESARY_DEBUG = -Wall -Wextra -pedantic

all: vu gen

vu: view.cc
	$(CC)     view.cc  $(MAKE_VIEWER_EXE) $(GL_FLAGS) $(CIMG_FLAGS)

gen: generate.cc ../resources/voraldo/v.cc
	$(CC) generate.cc  $(VORALDO_FLAGS) $(LODEPNG_FLAGS) $(MAKE_GENERATE_EXE) $(GL_FLAGS) $(CIMG_FLAGS)
