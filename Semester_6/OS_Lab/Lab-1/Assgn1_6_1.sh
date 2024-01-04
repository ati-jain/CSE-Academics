#! /bin/bash
primes=()
for (( i=2; i<=1000; i++ ))
do
	if (( not_prime[i] == 0 ))
	then
        primes+=($i)
		for (( j=i*i; j<=1000; j=j+i ))
			do
				not_prime[$j]=1
			done
	fi
done
echo -n "" > output.txt

while read line
do
    for prime in ${primes[@]}
    do
        p2=$(( prime * prime ))
        if [ $p2 -gt $line ]
        then
            break
        fi
        if [ $(( $line % $prime )) == 0 ]
        then
            echo -n "$prime " >> output.txt
            line=$(( line / prime ))
        fi
        while [ $(( $line % $prime )) == 0 ]
        do
            line=$(( line / prime ))
        done
    done
    if (( line != 1 ))
    then
        echo -n "$line " >> output.txt
    fi
    echo "" >> output.txt
done < input.txt