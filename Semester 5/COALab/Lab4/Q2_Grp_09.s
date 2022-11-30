# This program reads an array of 10 integers then print them in sorted order
# Group-9
# Semester-5
# Assignment-4
# Question-2
# Group Members
# Atishay Jain - 20CS30008
# Abothula Suneetha - 20CS10004

.globl  main
.data

array:
    .space 40   # memory for 10 element integer array
arr_input:      # label for asking integers for array
    .asciiz "Please enter array elements:\n"
element:
    .asciiz "array["
colon:
    .asciiz "] : "
sorted_array:
    .asciiz "\nSorted array:\n"
space:
    .asciiz " "
newline:
    .asciiz "\n"

.text

# main program

# Variables
# $s0 = length of array = 10

main:
    subu    $sp, $sp, 8     # extending the stack
    addi    $fp, $sp, 4     # setting the new frame pointer

    li      $s0, 10     # $s0 <-- 10 = length of array
    li      $t0, 0      # $t0 <-- i = 0

    li      $v0, 4      # ask for the inputs
    la      $a0, arr_input
    syscall

    read_loop:              # loop for reading 10 integers

        li      $v0, 4
        la      $a0, element    # asking for array[i]
        syscall

        li      $v0, 1
        srl     $a0, $t0, 2
        syscall

        li      $v0, 4
        la      $a0, colon      # just printing proper message
        syscall

        li      $v0, 5      # read array element
        syscall

        sw      $v0, array($t0)     # store array element in array[i]

        addi    $t0, $t0, 4         # i++ effectively
        bne     $t0, 40, read_loop  # if (i != 10) iterate again; else end loop;

    la      $a0, array      # setting first argument; load array address in $a0
    li      $a1, 0          # setting second argument; load start index in $a1
    li      $a2, 9          # setting third argument; load end index in $a2
    jal     recursive_sort  # call recursive_sort(array, 0, 9)

    li      $v0, 4          # print sorted array message
    la      $a0, sorted_array
    syscall

    la      $a0, array      # setting first argument; load array address in $a0
    li      $a1, 10         # setting second argument; store array_length in $a1
    jal     print_array     # calling print_array(array, 10)

    addi    $sp, $sp, 8     # restore stack pointer

    li      $v0, 10         # terminate program
    syscall


# recursive sort function

# Variables
# $a0 = array
# $a1 = left
# $a2 = right
# $s0 = l
# $s1 = r
# $s2 = p

recursive_sort:
    subu    $sp, $sp, 40        # extending the stack
    sw      $ra, 4($sp)         # storing return adderss
    sw      $fp, 0($sp)         # storing pevious frame pointer
    addi    $fp, $sp, 36        # creating new frame pointer

    # pushing variables to stack
    sw      $s3, -28($fp)
    sw      $s0, -24($fp)
    sw      $s1, -20($fp)
    sw      $s2, -16($fp)
    sw      $a0, -8($fp)
    sw      $a1, -4($fp)
    sw      $a2, 0($fp)

    move    $s0, $a1    # $s0 <-- l = left
    move    $s1, $a2    # $s1 <-- r = right
    move    $s2, $a1    # $s2 <-- p = left
    move    $s3, $a0    # storing array locally

    while_outer:
        bge     $s0, $s1, sort_return     # if (l >= r) end loop; else iterate again

        sll     $t1, $s2, 2     # $t1 <-- 4*p
        add     $t1, $s3, $t1   # $t1 = base address of A + 4*p
        lw      $t1, 0($t1)     # $t1 <-- A[p]

        while_inner_l:
            sll     $t0, $s0, 2     # $t0 <-- 4*l
            add     $t0, $s3, $t0   # $t0 = base address of A + 4*l
            lw      $t0, 0($t0)     # $t0 <-- A[l]

            bgt     $t0, $t1, while_inner_r     # if (A[l] > A[p]) end this loop
            bge     $s0, $a2, while_inner_r     # else if (l >= right) end this loop; else iterate again
            addi    $s0, $s0, 1         # l++
            b       while_inner_l       # iterate again

        while_inner_r:
            sll     $t0, $s1, 2     # $t0 <-- 4*r
            add     $t0, $s3, $t0   # $t0 = base address of A + 4*r
            lw      $t0, 0($t0)     # $t0 <-- A[r]

            blt     $t0, $t1, if        # if (A[r] < A[p]) end this loop
            ble     $s1, $a1, if        # if (r <= left) end this loop
            addi    $s1, $s1, -1        # r--
            b       while_inner_r       # loop

        if:
            blt     $s0, $s1, swap_l_r      # if (l < r) swap A[l] and A[r]

            # swap A[p] and A[r]
            sll     $t0, $s2, 2     # $t0 <-- p*4
            add     $a0, $s3, $t0   # setting the first argument; $a0 = address of A[p]
            sll     $t0, $s1, 2     # $t0 <-- r*4
            add     $a1, $s3, $t0   # setting the second argument; $a1 = address of A[r]
            jal     swap            # call swap(A[p], A[r])

            # call recursive_sort(A, left, r-1)
            move    $a0, $s3        # setting first argument = array
            lw      $a1, -4($fp)    # setting second argument; load left into $a1
            addi    $a2, $s1, -1    # setting third argument; set $a2 to r-1
            jal     recursive_sort  # call recursvive_sort(A, left, r-1)

            # call recursive_sort(A, r+1, right)
            move    $a0, $s3        # setting first argument = array
            addi    $a1, $s1, 1     # setting second argument; set $a1 to r+1
            lw      $a2, 0($fp)     # setting third argument; load right into $a2
            jal     recursive_sort  # call recursvive_sort(A, r+1, right)

            b       sort_return

        swap_l_r:                   # swap A[l] and A[r]
            sll     $t0, $s0, 2     # $t0 <-- l*4
            add     $a0, $s3, $t0   # setting the second argument; $a1 = address of A[l]
            sll     $t0, $s1, 2     # $t0 <-- r*4
            add     $a1, $s3, $t0   # setting the first argument; $a0 = address of A[r]
            jal     swap            # call swap(A[l], A[r])

            lw      $a1, -4($fp)    # restore $a1
            lw      $a2, 0($fp)     # restore $a2

            b       while_outer     # loop once again

    sort_return:
        lw      $ra, 4($sp)    # restore $ra

        # restoring other variables
        lw          $s3, -28($fp)
        lw	    $s0, -24($fp)
        lw	    $s1, -20($fp)
        lw	    $s2, -16($fp)
        lw	    $a0, -8($fp)
        lw	    $a1, -4($fp)
        lw	    $a2, 0($fp)

        lw      $fp, 0($sp)     # restore frame pointer
        addi    $sp, $sp, 40    # erasing the stack

        jr      $ra             # return


#swap two integers function

# Variables
# array base address: $a0
# $a0 = first input
# $a1 = second input

swap:
    lw      $t2, 0($a0)     # $t2 = A[i]; load the value at A + 4*i
    lw      $t3, 0($a1)     # $t3 = A[j]; load the value at A + 4*j

    sw      $t2, 0($a1)     # store the value in $t2 to A + 4*j, A[j] now has old value of A[i]
    sw      $t3, 0($a0)     # store the value in $t3 to A + 4*i, A[i] now has old value of A[j]

    jr	    $ra		    # return


# print array function

# Variables:
# $a0 = array
# $a1 = 10

print_array:
    li      $t0, 0      # i = 0
    move    $s0, $a0    # storing array in $s0

    print_loop:
        bge     $t0, $a1, print_end  # if (i >= n) end loop

        sll     $t1, $t0, 2         # $t1 <-- i*4
        add     $t1, $s0, $t1       # $t1 = array base address + 4*i
        lw      $t1, 0($t1)         # $t1 <-- A[i]
        addi    $t0, $t0, 1         # i++
    
        li      $v0, 1      # print array[i]
        move    $a0, $t1    # load array[i] in $a0
        syscall

        li      $v0, 4          # print space character
        la      $a0, space      # load sapace character in $a0
        syscall

        b       print_loop  # interate loop

print_end:
    jr      $ra         # return
