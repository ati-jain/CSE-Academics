awk '{if(length($0)<5||length($0)>20||/[^a-zA-Z0-9]/||/^[^0-9]+$/||/^[^a-zA-Z]/)print"No";else print$0}' $1>validation_results.txt;while read fruit;do
sed -i "s/^.*$fruit.*$/N0/i" validation_results.txt;done<fruits.txt;sed -ri 's/^.{5,}$/Yes/' validation_results.txt