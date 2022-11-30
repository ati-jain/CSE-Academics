# This program reads an array of 10 integers and an integer k; Then prints the kth largest interger from array
# Group-9
# Semester-5
# Assignment-2
# Question-1
# Group Members
# Atishay Jain - 20CS30008
# Abothula Suneetha - 20CS10004

    .globl main

    .data
ask1:
    .asciiz "Enter first number: "
ask2:
    .asciiz "Enter second number: "
result:
    .asciiz "Product of the two numbers is: "
newline:
    .asciiz "\n"

    .text

# main program

#Variables:
#   $t0 = INT_MIN = -2^15
#   $t1 = INT_MAX = 2^15 - 1
#   $s0 = M
#   $s1 = Q
#   $s2 = 2^16 -1; 11...1

main:
    li  $t0, 1
    sll $t0, $t0, 15
    sub $t0, $zero, $t0         # $t0 = -2^15; INT_MIN

    li  $t1, 1
    sll $t1, $t1, 15
    sub $t1, $t1, 1             # $t1 = 2^15 - 1; INT_MAX

    li  $s2, 1
    sll $s2, $s2, 16
    sub $s2, $s2, 1             # $s2 = 2^16 - 1

    read_m:
        li  $v0, 4
        la  $a0, ask1               # printing message
        syscall

        li  $v0, 5
        syscall                     # reading first integer
        move    $s0, $v0            # $s0 <-- M

        li  $v0, 4
        la  $a0, newline            # printing newline
        syscall

        blt $s0, $t0, read_m        # if M < INT_MIN
        bgt $s0, $t1, read_m        # if M > INT_MAX
        and $s0, $s0, $s2           # taking least 16 bits only

    read_q:
        li  $v0, 4
        la  $a0, ask2               # asking second number
        syscall

        li  $v0, 5
        syscall                     # reading number
        move    $s1, $v0            # $s1 <-- Q

        li  $v0, 4
        la  $a0, newline            # printing newline
        syscall

        blt $s1, $t0, read_q        # if Q < INT_MIN
        bgt $s1, $t1, read_q        # if Q > INT_MAX
        and $s1, $s1, $s2           # taking least 16 bits only

    move    $a0, $s0            # passing first argument; a0 = M
    move    $a1, $s1            # passing second argument; a1 = Q
    jal   multiply_booth

    li  $s2, 1
    sll $s2, $s2, 15
    
    bne $s0, $s2, print
    sub $v0, $zero, $v0

    print:
        move    $s3, $v0            # storing the answer is $s3 from $v0
        li  $v0, 4
        la  $a0, result
        syscall

        li  $v0, 1
        move    $a0, $s3            # printing the answer
        syscall

    li  $v0, 10                 # terminating
    syscall

# multiply booth function

#Variables
#   $a0 = M
#   $a1 = Q
#   $t0 = A
#   $t1 = Q-1
#   $t2 = Q0
#   $t4 to decide the path; A = A - M; A = A + M; or nothing

multiply_booth:
    li  $t0, 0                  # $t0 <-- A = 0
    li  $t1, 0                  # $t1 <-- Q-1 = 0
    andi $t2, $a1, 1            # $t2 <-- Q0 = LSB of Q
    li  $t3, 16                 # t3 = count(16 bits)

    for:
        xor $t4, $t1, $t2       # $t4 = xor $t1, $t2

        beq $t4, 0, rs          # if they are same; do the right shift
        beq $t2, 1, sub_am      # if Q0 = 1; Q-1 = 0

        add $t0, $t0, $a0
        and $t0, $t0, $s2       # taking only the 16 bits
        b   rs

    sub_am:
        sub $t0, $t0, $a0
        and $t0, $t0, $s2       # taking only 16 bits

    rs:
        move    $t1, $t2        # $t1 = Q-1 = Q0
        srl $a1, $a1, 1         # right shift Q
        andi    $t4, $t0, 1     # t4 = LSB of A

        sll $t4, $t4, 15        # $t4 << 15
        or  $a1, $a1, $t4       # MSB of Q = LSB of A

        srl $t4, $t0, 15        # $t4 = MSB of A
        sll $t4, $t4, 15
        srl $t0, $t0, 1         # right shift A
        or  $t0, $t0, $t4       # MSB of A retained
        andi $t2, $a1, 1        # $t2 = Q0 = LSB of Q

    sub $t3, $t3, 1             # count--
    bgt $t3, $zero, for
    sll $t0, $t0, 16            # for concatenating A and Q
    or  $v0, $t0, $a1           # storing the return value in $v0

    jr  $ra                     # return answer