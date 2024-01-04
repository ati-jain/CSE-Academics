# check src and destn directory
[[ $# -lt 3 || ! -d $1 ]] && echo "Arguments invalid! Provide valid source directory, destination directory, and attribute names as arguments" && exit
mkdir -p $2

# get the attribute array
attr=("${@:3}")

# create a bash array for the jq command (to execute on shell)
columns=()
for col in ${attr[@]}; do
    [[ ${#columns[@]} -gt 0 ]] && columns+="+\",\"+"
    # [[ ${#columns[@]} -gt 0 ]] && columns+=","
    columns+="(."$col"|tostring)"
done

echo ${columns[@]}
mkdir -p new_dir/json_dumps

# iterate each file
for file in $1/*.jsonl;
do  
    # create output file and write column names
    out_csv="$2/$(basename "$file" .jsonl).csv"
    echo `$(IFS=,; echo "${attr[*]}" > $out_csv)`
    echo $file $out_csv
    # jq -r  $columns < $file >> $out_csv
    jq 'to_entries | map(.value |= "\"\(.)\"") | from_entries' $file | jq -r  $columns >> $out_csv
done
