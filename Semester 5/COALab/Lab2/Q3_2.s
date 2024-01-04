# This program populates array A in a row major fashion using a Geometric Progression (GP)
# series with initial value a and common ratio r and prints A and its transpose matrix B
# Group-9
# Semeste-5
# Assignment-2
# Question-1
# Group Members
# Atishay Jain - 20CS30008
# Abothula Suneetha - 20CS10004

    .globl main
    .data

ask:
    .asciiz "Enter four positive integers m, n, a and r:\n"
tab:            
    .asciiz "\t"        # space for proper indentation
newline:                # Newline character
    .asciiz "\n"
matA:      
    .asciiz "Matrix A:\n"
matB:      
    .asciiz "Matrix B:\n"
err1:
    .asciiz "Your m is not positive. Please enter a positive value:\n"
err2:
    .asciiz "Your n is not positive. Please enter a positive value:\n"


#Variables:
#   m = $s0 + 12
#   n = $s0 + 8
#   a = $s0 + 4
#   r = $s0
#   A = $s1
#   B = $s2

    .text
main:
    # Initialising the stack pointer and the frame pointer
    jal initStack
            
    li $v0, 4                       # ask for inputs
    la $a0, ask
    syscall

    li $v0, 5                       # read m from user and push into stack
    syscall
    move $a0, $v0
    jal pushToStack

    li $v0, 5                       # read n from user and push into stack
    syscall
    move $a0, $v0
    jal pushToStack

    li $v0, 5                       # read a from user and push into stack
    syscall
    move $a0, $v0
    jal pushToStack

    li $v0, 5                       # read r from user and push into stack
    syscall
    move $a0, $v0
    jal pushToStack

    la $s0, 0($sp)                  # store address of stack pointer in $s0
    
    lw $t0, 12($s0)                 # $t0 = m
    lw $t1, 8($s0)                  # $t1 = n
 
    ble $t0, 0, error1              # check if m is positive

 cont1:
    ble $t1, 0, error2              # check if n is positive
    b cont

  cont:
    mul $a0, $t0, $t1               # $a0 = m*n
    jal mallocInStack               # calls mallocInStack to allocate memory from A
    move $s1, $v0                   # storing base address

    mul $a0, $t0, $t1               # $a0 = m*n
    jal mallocInStack               # calls mallocInStack to allocate memory from B
    move $s2, $v0                   # storing base address

   
   li      $t2, 0                   # i = 0
   li      $t3, 1                   # prod = 1
   lw $t4, 4($s0)                   # $t4 = a
   lw $t5, 0($s0)                   # $t5 = r

populate:
   mul    $t6, $t4, $t3             # $t6 = a*prod
   mul $t7, $t2, 4                  # $t7 = 4*i
   add   $t7, $s1, $t7              # $t7 = A+4*i = A[i]
   sw      $t6, 0($t7)              # A[i]= $t6
   addi    $t2, $t2, 1              # i++
   mul     $t3, $t3, $t5            # prod = prod*r
   mul     $t6, $t0, $t1            # $t6 = m*n
   blt     $t2, $t6, populate       # if i < m*n, loop

    la $a0, matA                    # for printing matrix A
    li $v0, 4
    syscall

    move $a0, $t0                   # calls printMatrix function which takes m, n and address of array A as parameters
    move $a1, $t1
    move $a2, $s1
    jal printMatrix

    move $a0, $t0                   # calls transposeMatrix function which takes m, n and addresses of array A and B as parameters
    move $a1, $t1
    move $a2, $s1
    move $a3, $s2
    jal transposeMatrix

    la $a0, matB                    # for printing matrix B
    li $v0, 4
    syscall

    move $a0, $t1                   # calls printMatrix function which takes m, n and address of array B as parameters
    move $a1, $t0
    move $a2, $s2
    jal printMatrix

    li $v0, 10                      # terminating
    syscall

error1:
    li      $v0, 4                  # issue not positive prompt
    la      $a0, err1
    syscall

    li      $v0, 5                  # get m from user
    syscall
    move    $t0, $v0                # $t0 <-- m

    ble $t0, 0, error1	            # if the entered number is negative
    b cont1

error2:
    li      $v0, 4                  # issue not positive prompt
    la      $a0, err2
    syscall

    li      $v0, 5                  # get n from user
    syscall
    move    $t1, $v0

    ble $t1, 0, error2	            # if the entered number is negative
    b cont

initStack:                          # initStack function
    addi    $sp, $sp, -4            # make space for storing frame pointer
    sw      $fp, 0($sp)             # store old frame pointer
    move    $fp, $sp                # update frame pointer to the new base of stack
    jr		$ra     

pushToStack:                        # pushToStack function
    addi    $sp, $sp, -4            # make space for storing the new element
    sw      $a0, 0($sp)             # save the new element to stack
    jr      $ra

mallocInStack:                      # mallocInStack function
    mul $a0, $a0, 4                 # $a0 = 4*m*n ( the size of the space that is to be allocated. )
    sub $sp, $sp, $a0               # push the stack pointer down for the space
    move $v0, $sp                   # Return the current stack pointer value.
    jr $ra 


printMatrix:                        # function to print the matrix
    li      $t2, 0                  # i = 0
    li      $t3, 0                  # j = 0

print:      
    mul     $t4, $t2, 4             # $t4= 4*i
    add     $t4, $a2, $t4           # $t4 = A+4*i = A[i]
    lw      $t4, 0($t4)             # load the value A[i] in $t4

    move    $t5, $a0                # store m in $t3

    li      $v0, 1                  # print $t4
    move    $a0, $t4        
    syscall     

    li      $v0, 4                  # print space
    la      $a0, tab
    syscall

    move    $a0, $t5                # restore m in $a0

    addi    $t2, $t2, 1             # i++
    addi    $t3, $t3, 1             # j++
    blt     $t3, $a1, print         # if j < n, loop

    move    $t4, $a0                # store m in $t2
    
    li      $v0, 4                  # print newline
    la      $a0, newline
    syscall
    
    li      $t3, 0                  # j = 0

    move    $a0, $t4                # restore m in $a0

    mul     $t4, $a0, $a1           # $t2 = m*n
    blt	$t2, $t4, print	            # if i < m*n, loop

    jr      $ra


transposeMatrix:                    # function to transpose the matrix
    li      $t2, 0                  # i = 0
    li      $t3, 0                  # j = 0
    li      $t4, 0                  # num = 0

transpose:
    mul     $t5, $t2, $a1           # $t5 = i*n
    add     $t5, $t5, $t3           # $t5 = i*n + j
    mul     $t5, $t5, 4             # $t5 = 4*(i*n+j)
    add     $t5, $t5, $a2           # $t5 = A + 4*(i*n+j) = A[i*n+j] = A[i][j] 
    lw      $t5, 0($t5)             # load the value A[i, j] in $t5
    mul     $t6, $t4, 4             # $t6 = 4*num
    add     $t6, $t6, $a3           # $t6 = B + 4*num
    sw      $t5, 0($t6)             # store value in B

    addi    $t2, $t2, 1             # i++
    addi    $t4, $t4, 1             # num++
    blt     $t2, $a0, transpose     # if i < m loop

    addi    $t3, $t3, 1             # j++
    li      $t2, 0                  # i = 0
    blt     $t3, $a1, transpose     # if j < n loop

    jr      $ra                     # return
