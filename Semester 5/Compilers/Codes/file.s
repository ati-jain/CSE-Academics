.file "file.s"
.section .rodata
L1:
    .string "Atishay Jain"
L2:
    .string "Hello"
L3:

.text
.globl _start

_start:
    movl    $(SYS_write), %eax
    movq    $(STDOUT_FILENO), %rdi
    movq    $L1, rsi
    movq    $(L2-L1), %rdx
    syscall

    movl    $(SYS_exit), %eax
    movq    $0, %rdi
    syscall
    ret