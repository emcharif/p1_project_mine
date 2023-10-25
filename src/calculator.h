#include <stdio.h>
#include <math.h>


void do_next_op(double operand, char operator, double* akkumulator);
double run_calculator(double *akkumulator);
double scan_number();
char scan_operator();

void help(double* akkumulator);

double addition (double* akkumulator,double operand);
double subtraktion (double* akkumulator,double operand);
double multiplikation (double* akkumulator,double operand);
double division(double* akkumulator,double operand);
double power(double* akkumulator,double operand);
void kvadratroden(double* akkumulator);
void reverse(double* akkumulator);
void divide_with_one(double* akkumulator);
void result(double* akkumulator);

