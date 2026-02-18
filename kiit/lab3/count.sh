count=0

for file in *.sh
do
    if [ -f "$file" ]; then
        echo "Shell script found: $file"
        count=$((count + 1))
    fi
done

echo "Total number of .sh files: $count"
