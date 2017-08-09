# C0mput0r_v1

## What's that?

It's a simple program written in C, which resolves polynomial equations (with a degree of 2 maximum).

It displays the reduce form of the equation, the polynomial degree, and the different steps of the solution.

Be careful, the syntax of the argument is very strict, and a bad caracter or a space misplaced can  generate a "Invalid Syntax" message.

## Example

```* $>./computor_v1 "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"```


```
Original form: 5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0
Reduced form: 4 * X^0 + 4 * X^1 - 9.3 * X^2 = 0

Polynomial degree: 2

Discriminant is strictly positive, the two solutions are:

x1 = (-b - sqrt(delta)) / (2 * a)
x2 = (-b + sqrt(delta)) / (2 * a)

x1 = -(4.000000) - sqrt(164.800000) / (2 * -9.300000)
x2 = -(4.000000) + sqrt(164.800000) / (2 * -9.300000)

x1 = 0.905239
x2 = -0.475131
```

## Installing

Simply compile with the Makefile using ```make```.

Run the program with ```./computor_v1 + "your_polynomial_equation"```.
