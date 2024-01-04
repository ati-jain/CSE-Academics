addi $3, 1          # BUBBLE SORT 
comp $30, $3        # $30 = -1
addi $1, 0     # array
addi $2, 10      # i = n 
add $2, $30     #  LOOP1   # i=i-1
bz $2, 31       # goto endloop2
xor $3, $3      # j = 0
comp $4, $3     # LOOOP2
add $4, $2      # $4 = i - j
bz $4, 30      # bz $4, endloop2
xor $6, $6
add $6, $1
add $6, $3      # $6 = ar + j
lw $7, 0($6)    # $7 = ar[j]
addi $6, 1      # $6 = ar + j + 1
lw $8, 0($6)    # $8 = ar[j+1]
addi $3, 1      # j = j + 1
comp $9, $7
add $9, $8      # $9 = ar[j+1] - ar[j]
shrl $9, 15
shrl $9, 15
shrl $9, 1
comp $9, $9
bz $9, 26     # if ar[j] > ar[j+1] goto swap
b 8
sw $7, 0($6)    # ar[j+1]new = ar[j]old  #SWAP
add $6, $30     # $6 -= 1
sw $8, 0($6)   # ar[j]new = ar[j+1]old
b 8
b 5            # endloop2
addi $1, 0      # endloop1