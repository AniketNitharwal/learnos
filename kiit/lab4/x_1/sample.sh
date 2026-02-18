arr=(10 20 30 40 50)
echo ${arr [0]}
echo ${arr [2]}
echo ${arr[@]}
echo ${#arr[@]}
arr [5]=60
arr [1]=25
for i in "${arr[@]}"
do
echo $i
done
read -a arr
echo ${arr[@]}
unset arr [2]
