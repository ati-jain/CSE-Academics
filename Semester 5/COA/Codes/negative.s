
	.globl main
	
	.data
array:
	.space 40	#allocating space for 10 integer array
ask:
	.asciiz "Enter ten numbers: "
ask_k:
	.asciiz "Enter the value of k: "
sorted_array:
	.asciiz "\nSorted array: \n"
answer:
	.asciiz "Answer: "
space:
	.asciiz " "
newline:
	.asciiz "\n"
err:
	.asciiz "Enter k <= 10 and >= 1: "

	.text

#main program
#Variables
#	$t0 = i; for reading 10 integers

main:
    li  $t0, 0
    addi    $t0, $t0, 1234123424324
    li  $v0, 1
    move    $a0, $t0
    syscall
    li  $v0, 10
    syscall