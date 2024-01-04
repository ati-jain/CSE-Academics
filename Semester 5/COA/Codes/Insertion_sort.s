
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

    b	sort_array		        # find_k_largest(array)

	li	$v0, 10					# terminating
	syscall


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

	li	$t0, 1              	# i = 1
	b for

	for:
		addi	$t1, $t0, -1	# j = i - 1
        sll     $t2, $t0, 2     # t2 = i * 4
        add     $t2, $t2, array
        lw      $t3, $t2        # t3 = key= arr[i]



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