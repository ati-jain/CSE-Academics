addi $3, 1          # BUBBLE SORT 
comp $30, $3 
xor $1, $1          # array
xor $11, $11
addi $11, 10        # arr[0]
sw $11, 0($1)
xor $11, $11
addi $11, 5        # arr[1]
sw $11, 1($1)
xor $11, $11
addi $11, 2         # arr[2]
sw $11, 2($1)
xor $11, $11
addi $11, 14        # arr[3]
sw $11, 3($1)
xor $11, $11
addi $11, -5        # arr[4]
sw $11, 4($1)
xor $11, $11
addi $11, 6         # arr[5]
sw $11, 5($1)
xor $11, $11
addi $11, 36        # arr[6]
sw $11, 6($1)
xor $11, $11
addi $11, 61       # arr[7]
sw $11, 7($1)
xor $11, $11
addi $11, 54        # arr[8]
sw $11, 8($1)
xor $11, $11
addi $11, 10         # arr[9]
sw $11, 9($1)
addi $2, 10         # i = n 
add $2, $30         #  LOOP1    # i=i-1
bz $2, 61
xor $3, $3          # j = 0
comp $4, $3         # LOOOP2
add $4, $2          # $4 = i - j
bz $4, 60           # bz $4, endloop2
xor $6, $6
add $6, $1
add $6, $3          # $6 = ar + j
lw $7, 0($6)        # $7 = ar[j]
addi $6, 1          # $6 = ar + j + 1
lw $8, 0($6)        # $8 = ar[j+1]
addi $3, 1          # j = j + 1
comp $9, $7
add $9, $8          # $9 = ar[j+1] - ar[j]
shrl $9, 15
shrl $9, 15
shrl $9, 1
comp $9, $9
bz $9, 56           # if ar[j] > ar[j+1] goto swap
b 38
sw $7, 0($6)        # ar[j+1]new = ar[j]old     #SWAP
add $6, $30         # $6 -= 1
sw $8, 0($6)        # ar[j]new = ar[j+1]old
b 38
b 35                # endloop2
xor $10, $10
lw $0, 0($10)
addi $10, 1
lw $1, 0($10)
addi $10, 1
lw $2, 0($10)
addi $10, 1
lw $3, 0($10)
addi $10, 1
lw $4, 0($10)
addi $10, 1
lw $5, 0($10)
addi $10, 1
lw $6, 0($10)
addi $10, 1
lw $7, 0($10)
addi $10, 1
lw $8, 0($10)
addi $10, 1
lw $9, 0($10)