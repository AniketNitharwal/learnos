arr=(10 25 37 40)
echo "elements in array"
echo ${arr[@]}
echo "elements at 0 postion:"
echo ${arr[0]}
echo "adding element at 5 position"
arr[4]=123
echo ${arr[@]}
echo "lenght ${#arr[@]}"
echo "updating value of 0 position"
arr[0]=112
echo ${arr[@]}
echo "deleting value of 4 position"
unset arr[3]
echo ${arr[@]}
