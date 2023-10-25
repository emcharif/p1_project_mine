#include "calculator.h"

int main(void) {
    double akkumulator = 0.0;

    printf("Type 'h' in the operator for help");
    run_calculator(&akkumulator);

    return 0;
}
