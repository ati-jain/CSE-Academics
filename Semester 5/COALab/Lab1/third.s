# This program tells whether the entered number is a perfect number or not.
# where n is entered by the user.

    .globl  main

    .data

prompt:
    .asciiz "Enter a positive integer: "
result1:
    .asciiz "Entered number is a perfect number."
result2:
    .asciiz "Entered number is not a perfect number."
newline:
    .asciiz "\n"

    .text

# main program
#
# program variables
#   n:   $s0
#   sum_of_divisors: $s1
#   i: $s2

main:
    li $v0 , 4        # issue prompt
    la $a0 , prompt
    syscall

    li $v0 , 5        # get n from user
    syscall
    move $s0 , $v0

    li $v0 , 4        # new line
    la $a0 , newline
    syscall

    ble $s0, 0, main

    li $s1 , 0        # sum_of_divisors = 0
    li $s2 , 1        # i = 1
    b s

s:
    bge $s2, $s0, cond    # while $s2 < $s0
    rem $t0, $s0, $s2     # $t0 = $s0 % $s2
    bne $t0, $0, w
    addu $s1, $s1, $s2    # $s1 += $s2

w:
    addi $s2, $s2, 1      # $s2++
    j s;

cond:
    beq $s0, $s1, per
    bne $s0, $s1, notper

per:
    li $v0, 4             #printing the result
    la $a0, result1
    syscall

    li $v0, 10            #terminate
    syscall

notper:
    li  $v0, 4            #printing the result
    la  $a0, result2
    syscall

    li $v0, 10            #terminate
    syscall