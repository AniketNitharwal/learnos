if [ $# -ne 3 ]; then
    echo "Usage: $0 file1 file2 outputfile"
    exit 1
fi

file1=$1
file2=$2
outfile=$3

paste -d "" "$file1" "$file2" > "$outfile"

echo "Files concatenated line by line into $outfile"

