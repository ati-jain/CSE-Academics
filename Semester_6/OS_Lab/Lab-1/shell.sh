# awk '{if('/$2/') $(echo $0 | sed 's/[a-zA-Z][^a-z^A-Z]*.\?/\u\0/g'); else print $0}' $1
# awk '{if('/$2/') print $(echo $0 | sed 's/[a-zA-Z][^a-z^A-Z]*.\?/\u\0/g')}' $1
while read -r line
do
    if [[ $line =~ (^| )"$2"( |$) ]]
    then
        echo "$line" | tr '[:upper:]' '[:lower:]' | sed 's/[a-zA-Z][^a-z^A-Z]*.\?/\u\0/g'
        # l=$(echo "$linex" | tr '[:upper:]' '[:lower:]')
        # echo `sed 's/[[:lower:]][^[:alpha:]]*\([[:alpha:]]\|$\)/\u&/g' <<< $l`
    # elif [[ "$line" =~ ^"$2 " ]]
    # then
    #     echo $line | sed 's/[a-zA-Z][^a-z^A-Z]*.\?/\u\0/g'
    # elif [[ $line == " $2"$ ]]
    # then
    #     echo $line | sed 's/[a-zA-Z][^a-z^A-Z]*.\?/\u\0/g'
    # else
    #     echo $line
    fi
done<$1