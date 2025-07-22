#include <stdio.h>

struct complex
{
    int real;
    int imag;
};

// addition by call by value
struct complex add(struct complex c1, struct complex c2)
{
    struct complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// multiplication by call by address
struct complex multiply(struct complex *c1, struct complex *c2)
{
    struct complex result;
    result.real = (c1->real * c2->real) - (c1->imag * c2->imag);
    result.imag = (c1->real * c2->imag) + (c1->imag * c2->real);
    return result;
}

int main()
{
    struct complex c1, c2, sum, product;

    // Input for first complex number
    printf("Enter first complex number (real and imaginary parts): ");
    scanf("%d %d", &c1.real, &c1.imag);

    // Input for second complex number
    printf("Enter second complex number (real and imaginary parts): ");
    scanf("%d %d", &c2.real, &c2.imag);

    // Calculate sum
    sum = add(c1, c2);
    printf("Sum: %d + %di\n", sum.real, sum.imag);

    // Calculate product
    product = multiply(&c1, &c2);
    printf("Product: %d + %di\n", product.real, product.imag);

    return 0;
}