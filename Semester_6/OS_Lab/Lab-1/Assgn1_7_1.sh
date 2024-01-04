mkdir -p $2;for ch in {A..Z};do
grep -ih ^$ch $1/*.txt|sort>$2/$ch.txt;done
