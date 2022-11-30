# This program tells weather the entered number is prime or composite
# where n is entered by the user.

    .globl  main

    .data

# program output text constants
ask:
    .asciiz "Enter a positive integer greater than equals to 10: "
result1:
    .asciiz "Entered number is a PRIME number."
result2:
    .asciiz "Entered number is a COMPOSITE number."
newline:
    .asciiz "\n"

    .text

# main program
#
# program variables
#   n:   $s0
#   n/2: $s1
#   i: $s2
#   n/i: $s3

main:
	li  $v0, 4          #print message
    la  $a0, ask
    syscall

    li  $v0, 5          #scanning input
    syscall
    move $s0, $v0

    li  $v0, 4
    la	$a0, newline
    syscall

    blt $s0, 10, main   #sanity check
    li $v0, 2
    div $s0, $v0        #calculating n/2
    mflo $s1
    li $s2, 2           #setting i = 2
    b for               #for loop to check all factors from 2 to n/2

for:
    bgt $s2, $s1, prime #if the loop ends, then the number is prime
    div $s0, $s2
    mfhi $s3
    beq $s3, 0, comp    #if the remainder is zero, then the number is composite
    addi $s2, $s2, 1
    b for               #iterating the loop

prime:
    li  $v0, 4          #printing the result
    la  $a0, result1
    syscall

    li      $v0, 10     #terminate
    syscall

comp:
    li $v0, 4           #printing the result
    la $a0, result2
    syscall

    li      $v0, 10     #terminate
    syscall