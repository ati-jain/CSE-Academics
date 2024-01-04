sed 's/.* //'<$1|sort|uniq -c|awk '{t=$1;$1=$NF;$NF=t;print}'|sort -k2nr -k1;echo;sed 's/ .*//'<$1|sort|uniq -d;sed 's/ .*//'<$1|sort|uniq -u|wc -l
