#include "../resources/voraldo/v7.h"


Voraldo *main_block;


int main(){

  main_block = new Voraldo();
  main_block->init_block(vec(512,256,256));


	return 0;
}
