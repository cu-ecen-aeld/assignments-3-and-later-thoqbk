if [ "$#" != "2" ]; then
   echo "Must pass in exactly 2 arguments for writefile and writestr"
   exit 1
fi

mkdir -p "$(dirname "$1")"
echo "$2" > "$1"
if [ $? -ne 0 ]; then
    echo "Error: Failed to create or write to $writefile"
    exit 1
fi

