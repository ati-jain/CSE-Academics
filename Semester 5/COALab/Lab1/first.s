# This program computes and displays the GCD of two positive integers,
# where a and b are entered by the user.

    .globl  main

    .data

# program output text constants
ask1:
    .asciiz "Enter the first positive integer: "
ask2:
    .asciiz "Enter the second positive integer: "
result:
    .asciiz "GCD of the two integers is: "
newline:
    .asciiz "\n"
err:
    .asciiz "Please enter a positive number"

    .text

# main program
#
# program variables
#   a:   $s0
#   b:   $s1

main:
	b read1					# read the first integer

read1:
    li      $v0, 4          # print message
    la      $a0, ask1
    syscall

    li      $v0, 5          # reading a from user
    syscall
    move    $s0, $v0
    
    li		$v0, 4
    la		$a0, newline
    syscall

    blt $s0, 0, n1			# if the entered number is negative
    b read2					# else read another no.

read2:
    li      $v0, 4          # print message
    la      $a0, ask2
    syscall

    li      $v0, 5          # reading b from user
    syscall
    move    $s1, $v0
    
    li		$v0, 4
    la		$a0, newline
    syscall
    
    blt $s1, 0, n2			# if the entered number is negative
    b gcd                   # else go to the GCD function

n1:
	li      $v0, 4          # issue prompt
    la      $a0, err
    syscall

    li      $v0, 5          # get a from user
    syscall
    move    $s0, $v0

    li		$v0, 4
    la		$a0, newline
    syscall

    blt $s0, 0, n1	        # if the entered number is negative
    b read2                 # else read another number

n2:
	li      $v0, 4          # issue prompt
    la      $a0, err
    syscall

    li      $v0, 5          # get b from user
    syscall
    move    $s1, $v0

    li		$v0, 4
    la		$a0, newline
    syscall

    blt $s1, 0, n2          # if the entered number is negative
    b gcd                   # else go to the GCD function
    
gcd:
	beq $s0, 0, retb        # if a == 0
    b while

while:                      # while loop
    beq     $s1, 0, reta
    bgt     $s0, $s1, a_m_b
    b b_m_a

b_m_a:
    sub     $s1, $s1, $s0
    b while

a_m_b:
    sub     $s0, $s0, $s1
    b while

reta:                       # printing a and ending program
    li      $v0, 4
    la      $a0, result
    syscall

    li      $v0, 1
    move    $a0, $s0
    syscall

    li      $v0, 10         # terminating
    syscall

retb:                       # printing b and ending program
    li      $v0, 4
    la      $a0, result
    syscall

    li      $v0, 1
    move    $a0, $s1
    syscall

    li      $v0, 10         # terminating
    syscall