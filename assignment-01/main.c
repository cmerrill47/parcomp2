#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif
    float f1(float x, int intensity);
    float f2(float x, int intensity);
    float f3(float x, int intensity);
    float f4(float x, int intensity);
    
#ifdef __cplusplus
}
#endif

float getX(float a, float b, int n, int i){
  float x;
  x = a + (i + .5) * ((b - a)/ (float)n);
  return x;
}

double calc_numerical_integration(int functionid, int a, int b, int n, int intensity){
    float x;
    float (*f)(float,int);

    switch(functionid){
    case 1:
       f = &f1;
       break;
    case 2:
       f = &f2;
       break;
    case 3:
       f = &f3;
       break;
    case 4:
      f = &f4;
       break;
    }

    for (int i = 0; i < n; i++){
        x += f(getX(a,b,n,i), intensity);
    }

    x =  ((b-a)/ (float)n) * x;
    return x;


}
int main (int argc, char* argv[]) {
    
    if (argc < 6) {
        fprintf(stderr, "usage: %s <functionid> <a> <b> <n> <intensity>", argv[0]);
        return -1;
    }

    int functionid = atoi(argv[1]);
    float a = atof(argv[2]);
    float b = atof(argv[3]);
    int n = atoi(argv[4]);
    int intensity = atoi(argv[5]);


    clock_t t; // t represents clock ticks which is of type 'clock_t'
    t = clock(); // start clock
    double r = calc_numerical_integration(functionid, a, b, n, intensity);
    t = clock()-t; // end clock=
    float time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds; CLOCKS_PER_SEC is the number of clock ticks per second
    printf("%lf\n", r);
    fprintf(stderr, "%f\n", time_taken);
    
    return 0;
}

