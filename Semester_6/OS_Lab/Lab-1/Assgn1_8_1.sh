# Create main.csv if it doesn't exist
if [ ! -f "main.csv" ]; then
  echo "Date (dd-mm-yy),Category,Amount,Name" > main.csv
fi

count=0
for (( i=1; i<=$#; i++ )); do
  if grep -q ^[-]'.*' <<< ${!i}; then
    count=-1
  else
    count=$((count+1))
  fi

  if [ $count -eq 4 ]; then
    a=$i; b=$((i-1)); c=$((i-2)); d=$((i-3))
    echo "${!d},${!c},${!b},${!a}" >> main.csv
    echo "Inserted ${!d},${!c},${!b},${!a} in main.csv"
    break
  fi
done



while getopts ":c:n:s:h" opt; do
  case $opt in
    c)
      # Print amount spent in specified category
      awk -F "," -v category="$OPTARG" 'BEGIN {sum=0} $2 == category { sum += $3 } END { print "Money spent on " category ": " sum }' main.csv
      ;;
    n)
      # Print amount spent by specified person
      awk -F "," -v name="$OPTARG" 'BEGIN {sum=0} $4 == name { sum += $3 } END { print "Money spent by " name ": " sum }' main.csv
      ;;
    s)
      firstLine=`head -n 1 main.csv`
      firstLine="${firstLine}\n"
      sed -i '1d' main.csv
      # Sort csv by specified column
      opt=`echo "${OPTARG,,}"` # Convert to lowercase
      case $opt in
        'date')
          sed -i 's/,/-/1' main.csv
          sort -t "-" -k3n -k2n -k1n -o main.csv main.csv
          sed -i 's/-/,/3' main.csv
          ;;
        'category')
          sort -t "," -k2 -o main.csv main.csv
          ;;
        'amount')
          sort -t "," -k3n -o main.csv main.csv
          ;;
        'name')
          sort -t "," -k4 -o main.csv main.csv
          ;;
        *)
          echo "Invalid sorting option: $OPTARG"
          ;;
      esac
      sed -i "1s/^/$firstLine/" main.csv
      ;;
    h)
      # Print help prompt
      echo "Help Prompt:-"
      echo "Name: CSV File Manipulator"
      echo "Usage: ./Assgn1_8_1.sh [-c category] [-n name] [-s column] [-h] [date] [category] [amount] [name]"
      echo "Description: A shell script to track expenses."
      echo "By default, the script accepts 4 arguments representing a new record in a csv file named main.csv."
      echo "Additional flags allow for printing specific information such as amount spent in a category or by a person, and sorting the csv by a specified column."
      ;;
    \?)
      echo "Invalid option: -$OPTARG"
      ;;
  esac
done


