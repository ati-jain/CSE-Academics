

for file in `find $1 -name '*.py'`; do
    echo $file      # print file name
    flag=0          # flag to check if a line is inside multiline comment
    line_number=0   # line number of the file

    while IFS= read -r line; do
        line_number=$((line_number+1))
        if grep -q \".*'#'.*\" <<< $line; then          # ignore '#' that appears inside string
            continue
        elif grep -q '#' <<< $line; then                # print all single line comments 
            echo $line_number `grep -o '#'.* <<< $line`
            continue
        elif grep -q ['(''=']\"\"\" <<< "$line"; then   # ignore """ that appears inside string
            continue
        elif grep -q \"\"\"')' <<< "$line"; then        # ignore """ that appears inside string 
            continue
        elif grep -q \"\"\".*\"\"\" <<< "$line"; then   # dont change flag for double """ in a single line
            echo $line_number $line
            continue
        elif grep -q \"\"\" <<< "$line"; then           # change flag for single """ in a single line
            flag=$((1-$flag))
            if [[ $flag == 1 ]]; then                   # starting of multiline comment
                echo $line_number $line
            else                                        # ending of multiline comment
                echo $line
            fi
            continue
        fi

        if [[ $flag == 1 ]]; then                       # lines inside multiline comment
            echo $line
        fi
    done < $file
    
    printf "\n\n"
done
