#include "calculator.h"

void do_next_op(double operand, char operator, double* akkumulator) {
    //all operators that need an operand
    switch(operator){
        case '+':
            *akkumulator = addition(akkumulator,operand);
            break;
        case '-':
            *akkumulator = subtraktion(akkumulator,operand);
            break;
        case '*':
            *akkumulator = multiplikation(akkumulator,operand);
            break;
        case '/':
            *akkumulator = division(akkumulator,operand);
            break;
        case '^':
            *akkumulator = power(akkumulator,operand);
            break;
        default:
            printf("You didn't used a valid operator, try again\n");
            //help();
            break;

    }
    //function to get new operator and operand
    run_calculator(akkumulator);

}
//Reverse, for at vende fortegnet af akkumulatoren
void result(double* akkumulator){
    printf("Result: %lf",*akkumulator);
    exit(0);
}

//Reverse, for at vende fortegnet af akkumulatoren
void divide_with_one(double* akkumulator){
    *akkumulator = 1 / *akkumulator;
    run_calculator(akkumulator);
}

//Reverse, for at vende fortegnet af akkumulatoren
void reverse(double* akkumulator){
    *akkumulator *= -1;
    run_calculator(akkumulator);
}

//kvadratroden
void kvadratroden(double* akkumulator){
    if(*akkumulator > 0){
    *akkumulator = sqrt(*akkumulator);
    }
    run_calculator(akkumulator);
}

//potensopløftning
double power(double* akkumulator,double operand){
    double result;
    result = pow(*akkumulator,operand);
    return result;
}

//Division
double division(double* akkumulator,double operand){
    double result;
    result = *akkumulator / operand;
    return result;
}

//multiplikation
double multiplikation(double* akkumulator,double operand){
    double result;
    result = *akkumulator * operand;
    return result;
}

//Plus
double addition (double* akkumulator,double operand){
    double result;
    result = *akkumulator + operand;
    return result;
}
//Sub
double subtraktion(double* akkumulator,double operand){
    double result;
    result = *akkumulator - operand;
    return result;
}


double run_calculator(double* akkumulator){
    //print current result
    printf("akkumulator: %lf\n\n",*akkumulator);
    //Scan for another operator
    char operator = scan_operator();
    //check if the operator needs a operand
    switch (operator) {
        case 'q':
            result(akkumulator);
            break;
        case '#':
            kvadratroden(akkumulator);
            break;
        case '%':
            reverse(akkumulator);
            break;
        case '!':
            divide_with_one(akkumulator);
            break;
        case 'h':
            help(akkumulator);
            break;
        default:
            break;
    }
    //The operand gets called.
    double operand = scan_number();
    //check what function to be used.
    do_next_op(operand,operator, akkumulator);
}


//Scan for the operator
char scan_operator(){
    char operator;
    printf("operator>");
    scanf("\n%c",&operator); //added \n for debug &operator was empty
    return operator;


}

// scan for the number
double scan_number(){
    double operand;
    printf("number>");
    scanf("%lf",&operand);
    return operand;
}



//User guide/Manual
void help(double* akkumulator){
    printf("\nHer er de gyldige binære operatorer i regnemaskinen:\n");
    printf("+ for addition af akkumulatoren med operanden\n");
    printf("- for subtraktion af akkumulatoren med operanden\n");
    printf("* for multiplikation af akkumulatoren med operanden\n");
    printf("/ for division af akkumulatoren med operanden\n");
    printf("^ for potensopløftning af akkumulatoren med operanden\n");
    printf("\nOg her er de gyldige unære operatorer:\n");
    printf("# for kvadratroden af akkumulatoren\n");
    printf("%% for at vende fortegnet af akkumulatoren\n");
    printf("! for at dividere 1 med akkumulatoren\n");
    printf("q for at afslutte regnemaskinen med slutresultatet\n");
    printf("\nh for at få hjælp\n\n");
    //continue the calculation with current result.
    run_calculator(akkumulator);
}
