# Name: Atishay Jain
# Roll No.: 20CS30008
# Assignment 1

	.file	"ass1_20CS30008.c"			# name of the source file
	.text
	.section	.rodata					# read-only data section
	.align 8							# align with 8 bytes memory
.LC0:									# label for a f-string, 1st printf
	.string	"Enter the string (all lowrer case): "
.LC1:									# label for a f-stirng, 1st scanf
	.string	"%s"
.LC2:									# label for f-string, 2nd printf
	.string	"Length of the string: %d\n"
	.align 8							# align with 8 bytes boundary
.LC3:									# label for another f-string, 3rd printf
	.string	"The string in descending order: %s\n"
	.text								# code starts from here
	.globl	main						# main is the global name
	.type	main, @function				# main is a function
main:									# main function starts
.LFB0:
	.cfi_startproc						# Call frame information
	endbr64
	pushq	%rbp						# save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp					# set new stack base pointer, rbp = rsp
	.cfi_def_cfa_register 6
	subq	$80, %rsp					# create space for local arrays and variables, rsp = stack pointer
	movq	%fs:40, %rax				# segment addressing
	movq	%rax, -8(%rbp)				# M[rbp-8] = rax
	xorl	%eax, %eax					# eax xor eax; eax <-- 0
	leaq	.LC0(%rip), %rdi			# Load address of f-string of 1st printf(.LC0); first argument for printf
	movl	$0, %eax					# eax <-- 0
	call	printf@PLT					# Calling printf function to print the f-string(.LC0)	
										# printf("Enter the string (all lowrer case): ");

	leaq	-64(%rbp), %rax				# load effective address; rax <-- M[rbp-64]; rax <-- str
	movq	%rax, %rsi					# rsi = rax; rsi <-- str; second argument for scanf
	leaq	.LC1(%rip), %rdi			# Load address of f-string of 1st scanf(.LC1); first argument for scanf
	movl	$0, %eax					# eax <-- 0
	call	__isoc99_scanf@PLT			# get the input
										# scanf("%s", str);

	leaq	-64(%rbp), %rax				# load effective address; rax <-- M[rbp-64]; rax <-- str
	movq	%rax, %rdi					# rdi = rax; rdi <-- str; setting the first argument of length function
	call	length						# push return address and goto length function
	movl	%eax, -68(%rbp)				# M[rbp-68] = eax; M[rbp-68] = len
	movl	-68(%rbp), %eax				# eax <-- M[rbp-68]; eax <-- len
	movl	%eax, %esi					# esi = eax; esi <-- len; second argument for printf
	leaq	.LC2(%rip), %rdi			# Load address of f-string of 2nd printf(.LC2); first argument for printf
	movl	$0, %eax					# eax <-- 0
	call	printf@PLT					# Calling printf function
										# printf("Length of the string: %d\n", len);

	leaq	-32(%rbp), %rdx				# load effective address; rdx <-- M[rbp-32]; rdx <-- dest
										# seting third argument for sort function

	movl	-68(%rbp), %ecx				# ecx <-- M[rbp-68]; ecx <-- len
	leaq	-64(%rbp), %rax				# load effective address; rax <-- M[rbp-64]; rax <-- str
	movl	%ecx, %esi					# esi = ecx; esi <-- len; setting the second argument of sort function
	movq	%rax, %rdi					# rdi = rax; rdi <-- str; setting the first argument of sort function
	call	sort						# push return address and goto sort function
	leaq	-32(%rbp), %rax				# rax <-- M[rbp-32]; rax <-- dest
	movq	%rax, %rsi					# rsi = rax;  rsi <-- M[rbp-32]; rsi <-- dest; second argument for printf
	leaq	.LC3(%rip), %rdi			# Load address of f-string of 3rd printf(.LC3); first argument for printf
	movl	$0, %eax					# eax <-- 0
	call	printf@PLT					# Calling printf function
										# printf("The string in descending order: %s\n", dest);

	movl	$0, %eax					# eax <-- 0
	movq	-8(%rbp), %rcx				# rcx <-- M[rbp-8]
	xorq	%fs:40, %rcx				# segment addressing
	je	.L3
	call	__stack_chk_fail@PLT
.L3:
	leave								# Set %rsp to %rbp, then pop top of stack into %rbp
	.cfi_def_cfa 7, 8
	ret									# return
	.cfi_endproc						# End of a function; call frame information directive
.LFE0:
	.size	main, .-main
	.globl	length						# length is a global name
	.type	length, @function			# length is a function
length:									# length function starts
.LFB1:
	.cfi_startproc						# Start of a function; Call frame information directive
	endbr64
	pushq	%rbp						# save old base pointer; callee saved
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp					# set new stack base pointer, rbp = rsp
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)				# M[rbp-24] = rdi, i.e value of 1st argument of the function(str)
	movl	$0, -4(%rbp)				# M[rbp-4] = 0; i = 0
	jmp	.L5								# jump to .L5
.L6:
	addl	$1, -4(%rbp)				# M[rbp-4] += 1; i++
.L5:
	movl	-4(%rbp), %eax				# eax <-- M[rbp-4]; eax <-- i
	movslq	%eax, %rdx					# move long to quad; rdx = eax; rdx <-- i
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	addq	%rdx, %rax					# rax = rax + rdx; rax <-- str[i]
	movzbl	(%rax), %eax				# move byte to long; eax <-- M[rax]; eax <-- str[i]
	testb	%al, %al					# performs AND operation on least significant byte of %eax (with itself)
										# change the ZF flag to 1, if al&al = 1
	jne	.L6								# if str[i] != '\0', goto .L6
	movl	-4(%rbp), %eax				# else eax <-- M[rbp-4]; eax <-- i; setting retunn value
	popq	%rbp						# pop base pointer off the stack
	.cfi_def_cfa 7, 8
	ret									# pops return address from stack and transfers control, return i
	.cfi_endproc						# End of a function; call frame information directive
.LFE1:
	.size	length, .-length
	.globl	sort						# sort is a global name
	.type	sort, @function				# sort is a function
sort:									# Starting of sort function
.LFB2:
	.cfi_startproc						# call frame information
	endbr64
	pushq	%rbp						# save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp					# set new stack base pointer, rbp = rsp
	.cfi_def_cfa_register 6
	subq	$48, %rsp					# create space for local arrays and variables, rsp = stack pointer
	movq	%rdi, -24(%rbp)				# M[rbp-24] = rdi, i.e value of 1st argument of the function(str)
	movl	%esi, -28(%rbp)				# M[rbp-28] = esi, value of the 2nd argument of the function(len)
	movq	%rdx, -40(%rbp)				# M[rbp-40] = rdx, value of the 3rd argument of the function(dest)
	movl	$0, -8(%rbp)				# M[rbp-8] = 0; i = 0
	jmp	.L9								# jump to .L9; calling the outer for loop
.L13:
	movl	$0, -4(%rbp)				# M[rbp-4] = 0; j = 0
	jmp	.L10							# jump to .L10; calling the inner for loop
.L12:
	movl	-8(%rbp), %eax				# eax <-- M[rbp-8]; eax <-- i
	movslq	%eax, %rdx					# move and sign-extend the value from a 32-bit %eax to a 64-bit %rdx; rdx <-- i
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	addq	%rdx, %rax					# rax = rax + rdx; rax <-- str + i = sr[i]
	movzbl	(%rax), %edx				# dereferencing rax and moving byte(8 bits) to long(32 bits) in edx; edx <-- str[i]
	movl	-4(%rbp), %eax				# eax <-- M[rbp-4]; eax <-- j
	movslq	%eax, %rcx					# move and sign-extend the value from a 32-bit %eax to a 64-bit %rdx; rcx <-- j
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	addq	%rcx, %rax					# rax = rax + rcx; rax <-- str + j = str[j]
	movzbl	(%rax), %eax				# moving byte(1 byte) to long(8 bytes); eax <-- M[rax]; eax <-- str[j]
	cmpb	%al, %dl					# compare least significant bytes of eax and edx al and dl; compare str[j] and str[i]
	jge	.L11							# if str[j] >= str[i] goto .L11
	movl	-8(%rbp), %eax				# eax <-- M[rbp-8]; eax <-- i
	movslq	%eax, %rdx					# rdx = eax; move long to quad; rdx <-- i
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	addq	%rdx, %rax					# rax = rax + rdx; rax <-- str[i]
	movzbl	(%rax), %eax				# move LSB(least significant byte) of rax to eax
	movb	%al, -9(%rbp)				# M[rbp-9] = LSB(least significant byte) of rax; temp = str[i]
	movl	-4(%rbp), %eax				# eax <-- M[rbp-4]; eax <-- j
	movslq	%eax, %rdx					# move long to quad; rdx = eax; rdx <-- j
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	addq	%rdx, %rax					# rax = rax + rdx; rax <-- str[j]
	movl	-8(%rbp), %edx				# edx <-- M[rbp-8]; edx <-- i
	movslq	%edx, %rcx					# move long(4 bytes) to quad(8 bytes); rcx = edx
	movq	-24(%rbp), %rdx				# rdx <-- M[rbp-24]; rdx <-- str
	addq	%rcx, %rdx					# rdx = rdx + rcx; rdx <-- str[i]
	movzbl	(%rax), %eax				# move byte(str[j]) to long; eax <-- M[rax]; eax <-- str[j]
	movb	%al, (%rdx)					# M[rdx] = al; str[i] = str[j]
	movl	-4(%rbp), %eax				# eax <-- M[rbp-4]; eax <-- j
	movslq	%eax, %rdx					# move long to quad; rdx = eax; rdx <-- j
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	addq	%rax, %rdx					# rdx = rdx + rax; rdx <-- str[j]
	movzbl	-9(%rbp), %eax				# move byte to long; eax <-- M[rbp-9]; eax <-- temp
	movb	%al, (%rdx)					# M[rdx] = al; str[j] = temp
.L11:									# updatation in inner for loop
	addl	$1, -4(%rbp)				# M[rbp-4] += 1; j++
.L10:									# inner loop; for (j = 0; j < len; j++)
	movl	-4(%rbp), %eax				# eax <-- M[rbp-4]; eax <-- j
	cmpl	-28(%rbp), %eax				# compare M[rbp-28] and eax; compare len and j
	jl	.L12							# if j < len; jump to .L12
	addl	$1, -8(%rbp)				# else M[rbp-8] += 1; i++
.L9:									# outer loop; for (i = 0; i < len; i++)
	movl	-8(%rbp), %eax				# eax <-- M[rbp-8]; eax <-- i
	cmpl	-28(%rbp), %eax				# compare M[rbp-28] and eax; compare len and i
	jl	.L13							# if i < len, jump to .L13
	movq	-40(%rbp), %rdx				# rdx <-- M[rbp-40]; rdx <-- dest; setting 3rd argument
	movl	-28(%rbp), %ecx				# ecx <-- M[rbp-28]; ecx <-- len
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	movl	%ecx, %esi					# esi = ecx; esi <-- len; setting second argument
	movq	%rax, %rdi					# rdi = rax; rdi <-- str; setting first argument
	call	reverse						# calling reverse function with the arguments set above
	nop									# Do nothing
	leave								# Sets rsp to rbp, and then pops the old rbp from the stack
	.cfi_def_cfa 7, 8
	ret									# pops return address from stack and transfers control, back to the return address
	.cfi_endproc						# unwinds the entry opened by .cfi_startproc
.LFE2:
	.size	sort, .-sort
	.globl	reverse						# reverse is in global scope
	.type	reverse, @function			# reverse is a function
reverse:								# reverse function starts here
.LFB3:
	.cfi_startproc						# Start of a function; Call frame information directive
	endbr64
	pushq	%rbp						# save old base pointer
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp					
	.cfi_def_cfa_register 6
	movq	%rdi, -24(%rbp)				# M[rbp-24] = rdi, i.e value of 1st argument of the function(str)
	movl	%esi, -28(%rbp)				# M[rbp-28] = esi, value of the 2nd argument of the function(len)
	movq	%rdx, -40(%rbp)				# M[rbp-40] = rdx, value of the 3rd argument of the function(dest)
	movl	$0, -8(%rbp)				# M[rbp-8] = 0; i = 0
	jmp	.L15							# goto .L15
.L20:
	movl	-28(%rbp), %eax				# eax <-- M[rbp-28]; eax <-- len
	subl	-8(%rbp), %eax				# eax <-- len - i
	subl	$1, %eax					# eax <-- len - i - 1
	movl	%eax, -4(%rbp)				# M[rbp-4] = eax
	nop									# Do nothing
	movl	-28(%rbp), %eax				# eax <-- M[rbp-24]
	movl	%eax, %edx					# edx = eax
	shrl	$31, %edx					# logical shift edx to right by 31 bits
										#  stores value of MSB (for sign) in edx
	addl	%edx, %eax					# eax = eax + edx
	sarl	%eax						# eax <-- len/2, arithmetic right shift by eax by 1 bit
	cmpl	%eax, -4(%rbp)				# compare eax and M[rbp-4]; compare len/2 and j
	jl	.L18							# if j < len/2; goto .L18
	movl	-8(%rbp), %eax				# eax <-- M[rbp-8]; eax <-- i
	cmpl	-4(%rbp), %eax				# compare M[rbp-4] and eax; compare j and i
	je	.L23							# if i == j; jump to .L23
	movl	-8(%rbp), %eax				# eax <-- M[rbp-8]; eax <-- i
	movslq	%eax, %rdx					# move long to quad; rdx = eax; rdx <-- i
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	addq	%rdx, %rax					# rax = rax + rdx; rax <-- str[i]
	movzbl	(%rax), %eax				# move byte to long; eax = M[rax]
	movb	%al, -9(%rbp)				# M[rbp-9] <-- al (last 8 bits of eax); temp = str[i]
	movl	-4(%rbp), %eax				# eax <-- M[rbp-4]; eax <-- j
	movslq	%eax, %rdx					# rdx = eax; rdx <-- j
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	addq	%rdx, %rax					# rax = rax + rdx; rax <-- str[j]
	movl	-8(%rbp), %edx				# edx <-- M[rbp-8]; edx <-- i
	movslq	%edx, %rcx					# rcx = edx; rcx <-- i
	movq	-24(%rbp), %rdx				# rdx <-- M[rbp-24]; rdx <-- str
	addq	%rcx, %rdx					# rdx = rdx + rcx; rdx <-- str[i]
	movzbl	(%rax), %eax				# eax <-- M[rax]
	movb	%al, (%rdx)					# M[rdx] = al(last bit of rax); str[i] = str[j]
	movl	-4(%rbp), %eax				# eax <-- M[rbp-4]; eax <-- j
	movslq	%eax, %rdx					# rdx = eax; rdx <-- j
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	addq	%rax, %rdx					# rdx = rdx + rax; rdx <-- str[j]
	movzbl	-9(%rbp), %eax				# eax <-- M[rbp-9]; eax <-- temp
	movb	%al, (%rdx)					# str[j] = temp
	jmp	.L18							# jump to .L18
.L23:
	nop									# Do nothing
.L18:									# for loop updatation
	addl	$1, -8(%rbp)				# M[rbp-8] = M[rbp-8] + 1; i++
.L15:
	movl	-28(%rbp), %eax				# eax <-- M[rbp-28]; eax <-- len
	movl	%eax, %edx					# edx = eax; edx <-- len
	shrl	$31, %edx					# logical shift edx to right by 31 bits
										# stores value of MSB (for sign) in edx
	addl	%edx, %eax					# eax = eax + edx
	sarl	%eax						# eax <-- len/2, arithmetic right shift by eax by 1 bit
	cmpl	%eax, -8(%rbp)				# compare eax and M[rbp-8]; compare len/2 and i
	jl	.L20							# if i < len/2; jump to .L20
	movl	$0, -8(%rbp)				# M[rbp-8] = 0; i = 0
	jmp	.L21							# goto .L21
.L22:
	movl	-8(%rbp), %eax				# eax <-- M[rbp-8]; eax <-- i
	movslq	%eax, %rdx					# move long to quad; rdx = eax; rdx <-- i
	movq	-24(%rbp), %rax				# rax <-- M[rbp-24]; rax <-- str
	addq	%rdx, %rax					# rax = rax + rdx; rax <-- str[i]
	movl	-8(%rbp), %edx				# edx = M[rbp-8]; edx <-- i
	movslq	%edx, %rcx					# move long to quad; rcx = edx; rcx <-- i
	movq	-40(%rbp), %rdx				# rdx <-- M[rbp-40]; rdx <-- dest
	addq	%rcx, %rdx					# rdx = rdx + rcx; rdx <-- dest[i]
	movzbl	(%rax), %eax				# move byte to long; eax <-- M[rax]; eax <-- str
	movb	%al, (%rdx)					# copy al to last 8-bits of rdx
	addl	$1, -8(%rbp)				# M[rbp-8] = M[rbp-8] + 1; i++
.L21:									# for (i = 0; i <= len; i++)
	movl	-8(%rbp), %eax				# eax <-- M[rbp-8]; eax <-- i
	cmpl	-28(%rbp), %eax				# compare eax and M{rbp-28]; compare len and i
	jle	.L22							# if i <= len; goto .L22
	nop									# Do nothing
	nop									# Do nothing
	popq	%rbp						# pop base pointer off the stack
	.cfi_def_cfa 7, 8
	ret									# pops return address from stack and transfers control, return
	.cfi_endproc						# End of a function; call frame information directive
.LFE3:
	.size	reverse, .-reverse
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
