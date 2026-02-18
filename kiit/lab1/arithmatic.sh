#!/bin/bash

echo "Addition of two numbers"

echo "Enter value for x"
read x

echo "Enter value for y"
read y

sum=$(expr $x + $y)
echo "Sum of $x and $y is $sum"

subtraction=$(expr $x - $y)
echo "Subtraction of $x and $y is $subtraction"

multiply=$(expr $x \* $y)
echo "Multiplication of $x and $y is $multiply"

divide=$(expr $x / $y)
echo "Division of $x and $y is $divide"
