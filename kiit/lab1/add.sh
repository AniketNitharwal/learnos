echo "addition of two numbers"
echo "enter value for x"
read x
echo "enter value for y"
read y
sum ='expr $x+$y |bc'
echo "sum of $x and $y is $sum"
