for file in 'ls'
do
if [ ! -s $file ]
then
echo $file
fi
done
