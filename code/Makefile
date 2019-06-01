CC = g++

MAKE_VIEWER_EXE= -o vu -time
MAKE_GENERATE_EXE= -o gen -time

GL_FLAGS = -lglut -lGLEW -lGL -lGLU

CIMG_FLAGS = -O2 -L/usr/X11R6/lib -lm -lpthread -lX11 -std=c++11 -Dcimg_use_png -lpng  -lz

all: vu gen

vu: view.cc
	$(CC)     view.cc  $(MAKE_VIEWER_EXE)   $(GL_FLAGS) $(CIMG_FLAGS)

gen: generate.cc ../resources/voraldo/v.cc
	$(CC) generate.cc ../resources/voraldo/v.cc $(MAKE_GENERATE_EXE) $(GL_FLAGS) $(CIMG_FLAGS)
