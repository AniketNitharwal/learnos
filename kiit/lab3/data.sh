echo "1. Home Directory"
echo "2. Bash Version"
echo "3. Host Name"
echo "4. Current Directory"
echo "5. Exit"

echo "Enter your choice:"
read ch

case $ch in
1)
   echo "Home Directory: $HOME"
   ;;
2)
   echo "Bash Version: $BASH_VERSION"
   ;;
3)
   echo "Host Name: $HOSTNAME"
   ;;
4)
   echo "Current Directory: $(pwd)"
   ;;
5)
   exit
   ;;
*)
   echo "Invalid choice"
   ;;
esac

