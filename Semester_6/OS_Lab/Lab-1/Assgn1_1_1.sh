echo -n "LCM(";ans=1;while read line;do
if [ $line ];then
arr=`echo $line|rev`;echo -n $arr ,;tmp=$((arr*ans));while [ $arr != 0 ];do
t=$arr;arr=$((ans%arr));ans=$t;done;ans=$((tmp/ans));fi;done<"$1";echo -e "\b\b)=$ans"
