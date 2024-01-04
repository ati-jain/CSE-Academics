#!/bin/bash

# check src and destn directory
[[ $# -lt 3 || ! -d $1 ]] && echo "Arguments invalid! Provide valid source directory, destination directory, and attribute names as arguments" && exit 1
mkdir -p $2

# get the attribute array
attr=("${@:3}")

# iterate each file
for file in $1/*.jsonl;
do
  # create output file and write column names
  out_csv="$2/$(basename "$file" .jsonl).csv"
  echo `$(IFS=,; echo "${attr[*]}" > $out_csv)`

  # iterate through each line (JSON file)
  while IFS= read -r json_line || [[ -n "$json_line" ]];
  do
    row=()
    # iterate through all required row values (attributes)
    for a in "${attr[@]}";
    do
      val=$(echo $json_line | jq -r ".$a")
      # append comma if row non empty
      [[ ${#row[@]} -gt 0 ]] && row+=","
      # handle strings with , or "
      [[ $val == *","* || $val == *"\""* ]] && val="\"$val\""
      row+=$val                           # append attribute value
    done
    echo ${row[@]} >> $out_csv            # write row to csv
  done < "$file"
done