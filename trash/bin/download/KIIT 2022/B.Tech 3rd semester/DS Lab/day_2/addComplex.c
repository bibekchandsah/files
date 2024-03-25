// Wap in C to display the addition of 2 complex numbers.

#include <stdio.h>
struct complex
{
    double real;
    double imag;
};
struct complex add_complex(struct complex a, struct complex b)
{
    struct complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}
int main()
{
    struct complex a, b, c;
    printf("Enter the real and imaginary parts of the first complex number: ");
    scanf("%lf %lf", &a.real, &a.imag);
    printf("Enter the real and imaginary parts of the second complex number: ");
    scanf("%lf %lf", &b.real, &b.imag);
    c = add_complex(a, b);
    printf("The sum of the two complex numbers is: %.2f + %.2fi\n", c.real, c.imag);
    return 0;
}