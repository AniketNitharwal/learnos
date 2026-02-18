echo "Enter an integer:"
read num

rev=0
temp=$num

while [ $temp -ne 0 ]
do
rem=$((temp % 10))
rev=$((rev * 10 + rem))
temp=$((temp / 10))
done

echo "Reversed number: $rev"

