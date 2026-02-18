echo "enter a character"
read ch
case $ch in
[A-Z])
echo "upper case"
;;
[a-z])
echo "lower case"
;;
*)
echo "invalid case"
;;
esac

