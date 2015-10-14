//
//  main.c
//  Fourrier
//
//  Created by Lanusse Baptiste on 14/10/2015.
//  Copyright © 2015 Baptiste Lanusse. All rights reserved.
//

#ifndef main
#define main

#include <stdio.h>
#include <stdlib.h>
#include <fftw3.h>

#undef main

int main(int argc, char *argv[]){
    
    int N;
    fftw_complex *in, *out;
    fftw_plan my_plan;
    
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*N);
    my_plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    
    fftw_execute(my_plan);
    
    fftw_destroy_plan(my_plan);
    fftw_free(in);
    fftw_free(out);
    
    return EXIT_SUCCESS;
}

#endif