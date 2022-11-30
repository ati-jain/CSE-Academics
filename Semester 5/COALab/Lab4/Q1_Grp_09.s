# This program populates array A in a row major fashion using a Geometric Progression (GP) and prints its determinating by calculating using Laplace expansion
# Group-9
# Semester-5
# Assignment-4
# Question-1
# Group Members
# Atishay Jain - 20CS30008
# Abothula Suneetha - 20CS10004

.globl main
.data
# program output text constants
prompt:
    .asciiz "Enter four positive integers\n"
prompt_n:
    .asciiz "Enter n: "
prompt_a:
    .asciiz "Enter a: "
prompt_r:
    .asciiz "Enter r: "
prompt_m:
    .asciiz "Enter m: "

printA:
    .asciiz "\nMatrix A:\n"
detA:
    .asciiz "\nFinal determinant of the matrix A is: "
tab:
    .asciiz "\t"
newline:
    .asciiz "\n"
err1:
    .asciiz "Entered n is not positive. Please enter a positive value: "
err2:
    .asciiz "Entered a is not positive. Please enter a positive value: "
err3:
    .asciiz "Entered r is not positive. Please enter a positive value: "
err4:
    .asciiz "Entered m is not positive. Please enter a positive value: "

.text
   
# main program

# Variables
# $s0 = n
# $s1 = a
# $s2 = r
# $s3 = m
# $s4 = matrix A

main:
    subu    $sp, $sp, 32        # extending the stack
    sw      $ra, 20($sp)        # storing return address
    sw      $fp, 16($sp)        # save old frame pointer
    addi	$fp, $sp, 28        # setting the new frame pointer

    li      $v0, 4              # issue input prompt
    la      $a0, prompt         
    syscall  

    li      $v0, 4              # issue input prompt for n
    la      $a0, prompt_n         
    syscall                  
    
    li      $v0, 5
    syscall                     # syscall to take integer input n
    
    move    $s0, $v0            # $s0 = n
    blez    $s0, error1         # check if n is positive

    read_a:
        li      $v0, 4              # issue input prompt for a
        la      $a0, prompt_a         
        syscall 

        li      $v0, 5
        syscall                     # syscall to take integer input a
        
        move    $s1, $v0            # $s1 = a
        blez    $s1, error2         # check if a is positive

    read_r:
        li      $v0, 4              # issue input prompt for r
        la      $a0, prompt_r         
        syscall 

        li      $v0, 5
        syscall                     # syscall to take integer input r
        
        move    $s2, $v0            # $s2 = r 
        blez    $s2, error3         # check if r is positive

    read_m:
        li      $v0, 4              # issue input prompt for m
        la      $a0, prompt_m        
        syscall 

        li      $v0, 5
        syscall                     # syscall to take integer input m
        
        move    $s3, $v0            # $s3 = m 
        blez    $s3, error4         # check if m is positive

    continue:
        div	    $s2, $s3
        mfhi	$s2                 # r = r % m    
        mul     $t3, $s0, $s0       # $t3 = n * n [$t3 stores size of matrix]
        sll     $t0, $t3, 2         # $t0 = 4*size
        sub	    $sp, $sp, $t0       # sp = sp - (4*size), reserve space in stack
        move    $s4, $sp            # store A in $s4
        
        move    $a0, $t3            # setting first argument; $a0 = size of matrix
        move    $a1, $s4            # setting second argument; load A in $a1
        move    $a2, $s1            # setting third argument; load a in $a2
        move 	$a3, $s2            # setting fourth argument; load r in $a3
        sw      $s3, 0($fp)         # push m into the stack
        jal     populate_matrix     # call populate_matrix(size, A, a, r)
        lw      $s3, 0($fp)         # restore m

        li      $v0, 4              # issue prompt to print matrix A
        la      $a0, printA   
        syscall                     

        move    $a0, $s0            # setting first argument; load n in $a0
        move    $a1, $s4            # setting second argument; load A in $a1
        jal     print_matrix        # call print_matrix(A)

        move    $a0, $s0            # setting first argument; load n in $a0
        move    $a1, $s4            # setting second argument; load matrix in $a1
        jal     rec_det             # call rec_det(n, A)
        move    $t0, $v0            # store the answer in $t0 temporarily

        la      $a0, detA           # issue detA prompt
        li      $v0, 4
        syscall                     

        move    $a0, $t0            # print the determinant of A
        li      $v0, 1
        syscall                     

    mul     $t0, $s0, $s0       # $t0 = n*n
    sll     $t0, $t0, 2         # $t0 = 4*$t0
    add     $sp, $sp, $t0       # de-allocate the matrix A from stack

    lw      $ra,20($sp)         # Restore return address
    lw      $fp,16($sp)         # Restore frame pointer
    addi    $sp,$sp,32          # Pop stack frame

    li      $v0, 10             # terminate program
    syscall

    error1:
        li      $v0, 4              # issue not positive prompt
        la      $a0, err1
        syscall

        li      $v0, 5              # get n from user
        syscall
        move    $s0, $v0            # $s0 = n

        ble $s0, 0, error1	        # if the entered number is negative
        b read_a  

    error2:
        li      $v0, 4              # issue not positive prompt
        la      $a0, err2
        syscall

        li      $v0, 5              # get a from user
        syscall
        move    $s1, $v0            # $s1 = a

        ble $s1, 0, error2	        # if the entered number is negative
        b read_r 

    error3:
        li      $v0, 4              # issue not positive prompt
        la      $a0, err3
        syscall

        li      $v0, 5              # get r from user
        syscall
        move    $s2, $v0            # $s2 = r

        ble $s2, 0, error3	        # if the entered number is negative
        b read_m

    error4:
        li      $v0, 4              # issue not positive prompt
        la      $a0, err4
        syscall

        li      $v0, 5              # get m from user
        syscall
        move    $s3, $v0            # $s3 = m

        ble $s3, 0, error4	        # if the entered number is negative
        b continue


# Populate matrix function

# Variables
# $a0 = size of matrix (n*n)
# $a1 = base address of A
# $a2 = a
# $a3 = r
# $t3 = a*(r^i)

populate_matrix:                 
    add     $t0, $zero, $zero   # i = 0
    lw      $t2, 0($fp)         # $t2 = m (modulo value)
    move    $t3, $a2            # $t3 = a

    loop:
        sll     $t1, $t0, 2         # $t1 = 4*i
        add     $t1, $a1, $t1       # $t1 = base address of A + 4*i
        div	    $t3, $t2
        mfhi	$t3			        # $t3 = a mod m
        sw	    $t3, 0($t1)         # M[A + 4*i] = (a)r^i, populate matrix element
        mul     $t3, $t3, $a3       # a = a * r

        addi    $t0, $t0, 1         # i++
        blt 	$t0, $a0, loop      # if (i < n*n), loop again
        
    jr      $ra			            # else return


# Print Matrix function

# Variables
# $a0 = n
# $a1 = base address of A
# $t3 = M[A + 4*i]

print_matrix:                    
    add     $t0, $zero, $zero   # i = 0
    add     $t1, $zero, $zero   # j = 0
    move    $t4, $a0            # temporarily store n in $t4

    printLoop:
        sll     $t2, $t0, 2         # $t2 = 4*i
        add	    $t2, $a1, $t2       # $t2 = (A + 4*i)
        lw	    $t3, 0($t2)         # $t3 = M[A + 4*i]

        li      $v0, 1              # print $t3
        move 	$a0, $t3
        syscall                     

        la      $a0, tab            
        li      $v0, 4
        syscall                     
    
        move    $a0, $t4            # restore n in $a0

        addi    $t0, $t0, 1         # i += 1, go to next element
        addi    $t1, $t1, 1         # j += 1
        blt     $t1, $a0, printLoop # if (j < n), printLoop
        
        move $t2, $a0

        li      $v0, 4              # print newline
        la      $a0, newline
        syscall        
        
        add     $t1, $zero, $zero   # reset j = 0
        move    $a0, $t4            # restore n in $a0
        mul     $t2, $a0, $a0       # $t2 = n*n
        blt     $t0, $t2, printLoop # if (i < n*n), loop again

    jr      $ra			            # else return


# Determinant calculating function

# Variables
# $a0 = n 
# $a1 = A 
# $s0 = M (base address of the smaller (n-1)*(n-1) matrix)
# $s1 = k (loop variable)
# $s2 = 4*(n-1)*(n-1) (size of the matrix M)

rec_det:                  
    slti    $t0, $a0, 2         
    beq	    $t0, $zero, recursive       # if (n >= 2), call recusive function
    # else return
    lw      $v0, 0($a1)                 # ans = A[0][0]
    jr      $ra                         # return

    recursive:
        subu    $sp, $sp, 40        # extending the stack
        sw      $ra, 4($sp)         # storing return adderss
        sw      $fp, 0($sp)         # storing pevious frame pointer
        addi    $fp, $sp, 36        # creating new frame pointer
        
        # storing variables in the stack
        sw      $s3, -12($fp)
        sw      $s2, -8($fp)
        sw      $s1, -4($fp)
        sw      $s0, 0($fp)

        addi    $t0, $a0, -1        # $t0 = n-1
        mul     $s2, $t0, $t0       # $s2 = (n-1)*(n-1)
        sll     $s2, $s2, 2         # $s2 = 4*(n-1)*(n-1) [size of the allocated space for M]
        sub     $sp, $sp, $s2       # allocating space for the submatrix M of dimensions (n-1)*(n-1)

        move    $s0, $sp            # $s0 = base address of M
        add     $s3, $zero, $zero   # $s3 = 0
        add     $s1, $zero, $zero   # k = 0
    
    L1:
        bge     $s1, $a0, restore_det       # if (k >= n) exit loop and restore stack

        add     $t0, $zero, 1       # i = 1, iterates over rows of A
        add     $t2, $zero, $a0     # $t2 = i*n
        add     $t5, $zero, $zero   # $t5 = 0

    L2:
        bge     $t0, $a0, L7
        add     $t1, $zero, $zero   # j = 0, iterates over columns of A

    L3:
        bge     $t1, $a0, L4        # if (j >= n), go to next row
        beq     $t1, $s1, L5        # if (j == k), ignore this column, go to next column
        add     $t3, $t2, $t1       # $t3 = i*n + j
        sll     $t4, $t3, 2         # $t4 = 4*(i*n + j)
        add     $t4, $a1, $t4       # $t4 = A + 4*(i*n + j)
        lw	$t3, 0($t4)             # $t3 = A[i][j]

        sll     $t4, $t5, 2         # $t4 = x*4
        add     $t4, $s0, $t4       # $t4 = A + x*4
        sw      $t3, 0($t4)         # $t4 = A[x]
        j       L6

    L5:
        addi    $t1, $t1, 1         # j = j + 1
        j       L3                  # jump to L3

    L6:
        addi    $t1, $t1, 1         # j = j + 1
        addi    $t5, $t5, 1         # x = x + 1
        j       L3                  # jump to L3

    L4:
        addi    $t0, $t0, 1         # i = i + 1
        mul     $t2, $t0, $a0       # $t2 = i * n
        j       L2                  # jump to L2

    L7:
        sw      $a0, -16($fp)       # store $a0 on stack
        addi    $t0, $a0, -1        # $t0 = n-1
        sw       $a1, -20($fp)      # store $a1 on stack

        move    $a0, $t0            # 1st argument: n-1
        move    $a1, $s0            # 2nd argument: M [(n-1)*(n-1) matrix]
        jal     rec_det             # recursive call for rec_det
        move    $t0, $v0            # $t0 = return value = Minor_0_k

        lw      $a1, -20($fp)       # restore $a1
        lw      $a0, -16($fp)       # restore $a0

        sll     $t7, $s1, 2
        add     $t7, $a1, $t7
        lw      $t7, 0($t7)         # $t7 = A[0][k]
        mul     $t7 ,$t0, $t7       # $t7 = A[0][k]*Minor_0_k

        andi    $t8, $s1, 1
        bne     $t8, $zero, subtract     # if k is odd, subtract from ans, else add

        add     $s3, $s3, $t7       # ans = ans + A[0][k] * Minor_0_k

        addi    $s1, $s1, 1         # k++
        j       L1                  # jump to L1

    subtract:
        sub     $s3, $s3, $t7       # ans = ans - A[0][k] * Minor_0_k

        addi    $s1, $s1, 1         # k++
        j       L1                  # jump to L1

    restore_det:
        move    $t1, $s3            # save answer (return value) to $t1
        add     $sp, $sp, $s2       # de-allocate the matrix M [(n-1)*(n-1) matrix] from stack
        
        lw      $ra, 4($sp)         # restore $ra
        lw      $s3, -12($fp)       # restore $s3
        lw      $s2, -8($fp)        # restore $s2
        lw      $s1, -4($fp)        # restore $s1
        lw      $s0, 0($fp)         # restore $s0   
        lw      $fp, 0($sp)         # restore frame pointer
        addi    $sp, $sp, 40        # erasing the stack
        move    $v0, $t1            # store return value in $v0

    jr      $ra             # return