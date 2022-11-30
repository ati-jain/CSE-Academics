# This program reads an array of 10 integers and an integer k; Then prints the kth largest interger from array
# Group-9
# Semester-5
# Assignment-2
# Question-2
# Group Members
# Atishay Jain - 20CS30008
# Abothula Suneetha - 20CS10004

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
	li      $v0, 4          	# ask for the inputs
	la      $a0, ask
	syscall

	li	$t0, 0
	b read_array				# read 10 integers

	read_array:					# input the array
		li	$v0, 5				# reading an integer
		syscall

		sw	$v0, array($t0)		# storing in the array

		addi	$t0, $t0, 4
		blt	$t0, 40, read_array	# running the for loop

		la 	$a0, array			# passing the array as argument
		jal	find_k_largest		# find_k_largest(array)

	li	$v0, 10					# terminating
	syscall

# find_k_largest function
#Variables:
#	$a0 <-- array
#	$t0 = k
#	$s0 <-- array
#	$s1 = array[10-k]

find_k_largest:
	subu	$sp, $sp, 8		# extending the stack
	sw	$ra, 0($sp)
	sw	$a0, 4($sp)

	li	$v0, 4
	la	$a0, newline		# printing new line
	syscall

	li	$v0, 4				# ask for k
	la	$a0, ask_k
	syscall

	li 	$v0, 5				# scan input
	syscall
	move    $s0, $v0		# $s0 = k

	bgt	$s0, 10, k_again	# if k is not in the bound
	blt $s0, 1, k_again

	b call_sort				# calling the sort label

	k_again:					# reading k again
		li	$v0, 4
		la	$a0, newline		# printing new line
		syscall

		li	$v0, 4
		la	$a0, err			# printing error message
		syscall

		li 	$v0, 5
		syscall
		move	$s0, $v0		# $s0 = k

		bgt	$s0, 10, k_again	# if k is still not in the bound
		blt $s0, 1, k_again

	call_sort:					# call the sort function
		lw	$a0, 4($sp)			# $a0 is the argument for sort
		jal	sort_array			# calling sort_array function; sort(array)

		li	$v0, 4
		la	$a0, answer			# printing answer
		syscall

		lw	$s1, 4($sp)			# s1 <-- array

		li	$t0, 10
		sub $s0, $t0, $s0		# k = 10 - k
		mul	$s0, $s0, 4
		add	$s1, $s1, $s0		# s1 <-- array[10-k]
		lw	$t0, ($s1)			# t0 = array[10-k]

		li	$v0, 1
		move	$a0, $t0		# printng the answer
		syscall

	lw	$ra, 0($sp)
	lw	$a0, 4($sp)
	addiu	$sp, $sp, 8			# deleting the stack
	jr	$ra						# returning

#sort_array funciton
#Variables:
#	$a0 <-- array
#	$t0 = i
#	$t1 = j
#	$t2 = n - i - 1
#	$t3 <-- array
#	$t5	= array[j]
#	$t6 = array[j+1]

sort_array:
	subu	$sp, $sp, 8			# creating stack
	sw	$ra, 0($sp)
	sw	$a0, 4($sp)
	move	$t3, $a0        # $t3 = array

	li	$t0, 0	# i = 0
	b for

	for:
		li	$t1, 0				# j = 0
		li	$t2, 36				# t2 = n - 1
		sub	$t2, $t2, $t0		# t2 = n - i - 1
		b forj

		forj:
			bge	$t1, $t2, endf2		# if j >= n- i - 1; end loop
			add $t4, $t3, $t1       # t4 = t3 + t1; t4 <-- arr[j]
			lw	$t5, ($t4)		    # t5 = array[j]
			move	$a0, $t4        # a0 = t4
			addi	$t1, $t1, 4		# j++
			add $t4, $t3, $t1       # t4 <-- arr[j + 1];
			lw	$t6, ($t4)		    # t6 = array[j + 1]
			move	$a1, $t4        # a1 = t4
			bgt $t5, $t6, do_swap
			b	forj

		endf2:
			addi $t0, $t0, 4		# i++
			blt	$t0, 40, for		# continue loop if i < n
			li	$v0, 4
			la	$a0, sorted_array
			syscall

			li	$t0, 0				# i = 0; for printing the sorted array

	print_loop:
		li	$v0, 1
		lw	$a0, ($t3)				# t3 <-- array[i]
		syscall

		li	$v0, 4
		la	$a0, space				# printing a space
		syscall

		addi	$t3, $t3, 4
		addi	$t0, $t0, 4			# i++
		blt	$t0, 40, print_loop

		li	$v0, 4
		la	$a0, newline			# print newline
		syscall

		lw	$ra, 0($sp)				# restoring the vlaues
		lw	$a0, 4($sp)
		addiu	$sp, $sp, 8			# deleting the stack
		jr	$ra						# return

	do_swap:
		jal	swap					# jump and link swap function
		b forj

# swap function
#Variables:
#	$a0 <-- array[j]
#	$a1 <-- array[j + 1]
#	$t7, $t8 = temporary variables

swap:
	subu	$sp, $sp, 4				# creating stack
	sw	$ra, 0($sp)

	#swapping the numbers

	lw	$t7, ($a0)
	lw	$t8, ($a1)
	sw	$t8, ($a0)
	sw	$t7, ($a1)
	
	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4				# deleting the stack
	jr	$ra							# return
