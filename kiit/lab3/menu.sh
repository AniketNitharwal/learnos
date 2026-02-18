echo "1. Current Directory"
echo "2. List Directory"
echo "3. create Directory"
echo "4. Copy File"
echo "5. Exit"

echo "Enter your choice:"
read ch

case $ch in
1)
echo "Current Directory: $(pwd)"
;;
2)
echo "List Directory: $(ls)"
;;
3)
echo "Create Directory: $(mkdir --help)"
;;
4)
echo "copy Directory: $(cp --help)"
;;
5)
   exit
   ;;
*)
   echo "Invalid choice"
   ;;
esac

