echo "Enter maximum size X (in KB):"
read X

dir_no=1
current_size=0

mkdir "x_$dir_no"

for file in *
do
if [ -f "$file" ]; then
size=$(du -k "$file" | cut -f1)

if [ $((current_size + size)) -le $X ]; then
mv "$file" "x_$dir_no/"
current_size=$((current_size + size))
else
dir_no=$((dir_no + 1))
mkdir "x_$dir_no"
mv "$file" "x_$dir_no/"
current_size=$size
fi
fi
done

echo "Files stored successfully in directories x_1, x_2, x_3 ..."
