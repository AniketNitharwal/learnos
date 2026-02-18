echo "enter file name:"
read fname
if [-f "$name"]
then 
echo "file exist."
echo"last column of each record :"
awk '{print $NF}' "&fname"
else
echo "file does not exist."
fi
