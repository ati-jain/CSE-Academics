xor $0, $0
addi $0, 20 # $0 = key = -3, value to find
xor $5, $5
addi $5, 9 # $5 = n = 9
xor $7, $7 # $7 = 0, value indicator
addi $7, 1 # $7 = 1, when not found
xor $2, $2 # $2 = i = 0
lw $3, 0($2) # $3 = A[i]
comp $3, $3 # $3 = -A[i]
add $3, $0 # $3 = key - A[i]
bz $3, 17 # if key == A[i], goto found
addi $2, 1 # i = i + 1
comp $6, $5 # $6 = -n
add $6, $2 # $6 = -n + i
bz $6, 18 # if n == i, goto end
b 8 # goto loop
addi $7, 1 # found
addi $7, 0 # end