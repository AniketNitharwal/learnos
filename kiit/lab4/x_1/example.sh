arr=(100 200 300 400)

echo "Array elements:"
for i in "${arr[@]}"
do
    echo "$i"
done

echo "Length of array: ${#arr[@]}"

