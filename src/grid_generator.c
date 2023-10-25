#include "main.h"

int grid_generator(int len){
    for (int x = 0; x<len;++x){
        for(int y = 0; y<len;++y){
            printf("(%d,%d)\n",x,y);
        }
    }
}

