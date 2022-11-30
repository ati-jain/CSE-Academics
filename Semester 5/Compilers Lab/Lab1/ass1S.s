   1              		.file	"ass1.c"
   2              	# GNU C17 (Ubuntu 9.4.0-1ubuntu1~20.04.1) version 9.4.0 (x86_64-linux-gnu)
   3              	#	compiled by GNU C version 9.4.0, GMP version 6.2.0, MPFR version 4.0.2, MPC version 1.1.0, isl ve
   4              	
   5              	# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
   6              	# options passed:  -imultiarch x86_64-linux-gnu ass1.c -mtune=generic
   7              	# -march=x86-64 -g -fverbose-asm -fasynchronous-unwind-tables
   8              	# -fstack-protector-strong -Wformat -Wformat-security
   9              	# -fstack-clash-protection -fcf-protection
  10              	# options enabled:  -fPIC -fPIE -faggressive-loop-optimizations
  11              	# -fassume-phsa -fasynchronous-unwind-tables -fauto-inc-dec -fcommon
  12              	# -fdelete-null-pointer-checks -fdwarf2-cfi-asm -fearly-inlining
  13              	# -feliminate-unused-debug-types -ffp-int-builtin-inexact -ffunction-cse
  14              	# -fgcse-lm -fgnu-runtime -fgnu-unique -fident -finline-atomics
  15              	# -fipa-stack-alignment -fira-hoist-pressure -fira-share-save-slots
  16              	# -fira-share-spill-slots -fivopts -fkeep-static-consts
  17              	# -fleading-underscore -flifetime-dse -flto-odr-type-merging -fmath-errno
  18              	# -fmerge-debug-strings -fpeephole -fplt -fprefetch-loop-arrays
  19              	# -freg-struct-return -fsched-critical-path-heuristic
  20              	# -fsched-dep-count-heuristic -fsched-group-heuristic -fsched-interblock
  21              	# -fsched-last-insn-heuristic -fsched-rank-heuristic -fsched-spec
  22              	# -fsched-spec-insn-heuristic -fsched-stalled-insns-dep -fschedule-fusion
  23              	# -fsemantic-interposition -fshow-column -fshrink-wrap-separate
  24              	# -fsigned-zeros -fsplit-ivs-in-unroller -fssa-backprop
  25              	# -fstack-clash-protection -fstack-protector-strong -fstdarg-opt
  26              	# -fstrict-volatile-bitfields -fsync-libcalls -ftrapping-math -ftree-cselim
  27              	# -ftree-forwprop -ftree-loop-if-convert -ftree-loop-im -ftree-loop-ivcanon
  28              	# -ftree-loop-optimize -ftree-parallelize-loops= -ftree-phiprop
  29              	# -ftree-reassoc -ftree-scev-cprop -funit-at-a-time -funwind-tables
  30              	# -fverbose-asm -fzero-initialized-in-bss -m128bit-long-double -m64 -m80387
  31              	# -malign-stringops -mavx256-split-unaligned-load
  32              	# -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387 -mfxsr
  33              	# -mglibc -mieee-fp -mlong-double-80 -mmmx -mno-sse4 -mpush-args -mred-zone
  34              	# -msse -msse2 -mstv -mtls-direct-seg-refs -mvzeroupper
  35              	
  36              		.text
  37              	.Ltext0:
  38              		.section	.rodata
  39              		.align 8
  40              	.LC0:
  41 0000 456E7465 		.string	"Enter the string (all lowrer case): "
  41      72207468 
  41      65207374 
  41      72696E67 
  41      2028616C 
  42              	.LC1:
  43 0025 257300   		.string	"%s"
  44              	.LC2:
  45 0028 4C656E67 		.string	"Length of the string: %d\n"
  45      7468206F 
  45      66207468 
  45      65207374 
  45      72696E67 
  46 0042 00000000 		.align 8
  46      0000
  47              	.LC3:
  48 0048 54686520 		.string	"The string in descending order: %s\n"
  48      73747269 
  48      6E672069 
  48      6E206465 
  48      7363656E 
  49              		.text
  50              		.globl	main
  52              	main:
  53              	.LFB0:
  54              		.file 1 "ass1.c"
   1:ass1.c        **** #include <stdio.h>
   2:ass1.c        **** int length(char str[20]);
   3:ass1.c        **** void sort(char str[20], int len, char dest[20]);
   4:ass1.c        **** void reverse(char str[20], int len, char dest[20]);
   5:ass1.c        **** int main()
   6:ass1.c        **** {
  55              		.loc 1 6 1
  56              		.cfi_startproc
  57 0000 F30F1EFA 		endbr64	
  58 0004 55       		pushq	%rbp	#
  59              		.cfi_def_cfa_offset 16
  60              		.cfi_offset 6, -16
  61 0005 4889E5   		movq	%rsp, %rbp	#,
  62              		.cfi_def_cfa_register 6
  63 0008 4883EC50 		subq	$80, %rsp	#,
  64              	# ass1.c:6: {
  65              		.loc 1 6 1
  66 000c 64488B04 		movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp93
  66      25280000 
  66      00
  67 0015 488945F8 		movq	%rax, -8(%rbp)	# tmp93, D.2380
  68 0019 31C0     		xorl	%eax, %eax	# tmp93
  69              	# ass1.c:9:     printf("Enter the string (all lowrer case): ");
   7:ass1.c        ****     char str[20], dest[20];
   8:ass1.c        ****     int len;
   9:ass1.c        ****     printf("Enter the string (all lowrer case): ");
  70              		.loc 1 9 5
  71 001b 488D3D00 		leaq	.LC0(%rip), %rdi	#,
  71      000000
  72 0022 B8000000 		movl	$0, %eax	#,
  72      00
  73 0027 E8000000 		call	printf@PLT	#
  73      00
  74              	# ass1.c:10:     scanf("%s", str);
  10:ass1.c        ****     scanf("%s", str);
  75              		.loc 1 10 5
  76 002c 488D45C0 		leaq	-64(%rbp), %rax	#, tmp84
  77 0030 4889C6   		movq	%rax, %rsi	# tmp84,
  78 0033 488D3D00 		leaq	.LC1(%rip), %rdi	#,
  78      000000
  79 003a B8000000 		movl	$0, %eax	#,
  79      00
  80 003f E8000000 		call	__isoc99_scanf@PLT	#
  80      00
  81              	# ass1.c:11:     len = length(str); // calling length function
  11:ass1.c        ****     len = length(str); // calling length function
  82              		.loc 1 11 11
  83 0044 488D45C0 		leaq	-64(%rbp), %rax	#, tmp85
  84 0048 4889C7   		movq	%rax, %rdi	# tmp85,
  85 004b E8000000 		call	length	#
  85      00
  86 0050 8945BC   		movl	%eax, -68(%rbp)	# tmp86, len
  87              	# ass1.c:12:     printf("Length of the string: %d\n", len);
  12:ass1.c        ****     printf("Length of the string: %d\n", len);
  88              		.loc 1 12 5
  89 0053 8B45BC   		movl	-68(%rbp), %eax	# len, tmp87
  90 0056 89C6     		movl	%eax, %esi	# tmp87,
  91 0058 488D3D00 		leaq	.LC2(%rip), %rdi	#,
  91      000000
  92 005f B8000000 		movl	$0, %eax	#,
  92      00
  93 0064 E8000000 		call	printf@PLT	#
  93      00
  94              	# ass1.c:13:     sort(str, len, dest); // calling sorting function
  13:ass1.c        ****     sort(str, len, dest); // calling sorting function
  95              		.loc 1 13 5
  96 0069 488D55E0 		leaq	-32(%rbp), %rdx	#, tmp88
  97 006d 8B4DBC   		movl	-68(%rbp), %ecx	# len, tmp89
  98 0070 488D45C0 		leaq	-64(%rbp), %rax	#, tmp90
  99 0074 89CE     		movl	%ecx, %esi	# tmp89,
 100 0076 4889C7   		movq	%rax, %rdi	# tmp90,
 101 0079 E8000000 		call	sort	#
 101      00
 102              	# ass1.c:14:     printf("The string in descending order: %s\n", dest);
  14:ass1.c        ****     printf("The string in descending order: %s\n", dest);
 103              		.loc 1 14 5
 104 007e 488D45E0 		leaq	-32(%rbp), %rax	#, tmp91
 105 0082 4889C6   		movq	%rax, %rsi	# tmp91,
 106 0085 488D3D00 		leaq	.LC3(%rip), %rdi	#,
 106      000000
 107 008c B8000000 		movl	$0, %eax	#,
 107      00
 108 0091 E8000000 		call	printf@PLT	#
 108      00
 109              	# ass1.c:15:     return 0;
  15:ass1.c        ****     return 0;
 110              		.loc 1 15 12
 111 0096 B8000000 		movl	$0, %eax	#, _9
 111      00
 112              	# ass1.c:16: }
  16:ass1.c        **** }
 113              		.loc 1 16 1
 114 009b 488B4DF8 		movq	-8(%rbp), %rcx	# D.2380, tmp94
 115 009f 6448330C 		xorq	%fs:40, %rcx	# MEM[(<address-space-1> long unsigned int *)40B], tmp94
 115      25280000 
 115      00
 116 00a8 7405     		je	.L3	#,
 117 00aa E8000000 		call	__stack_chk_fail@PLT	#
 117      00
 118              	.L3:
 119 00af C9       		leave	
 120              		.cfi_def_cfa 7, 8
 121 00b0 C3       		ret	
 122              		.cfi_endproc
 123              	.LFE0:
 125              		.globl	length
 127              	length:
 128              	.LFB1:
  17:ass1.c        **** int length(char str[20])
  18:ass1.c        **** {
 129              		.loc 1 18 1
 130              		.cfi_startproc
 131 00b1 F30F1EFA 		endbr64	
 132 00b5 55       		pushq	%rbp	#
 133              		.cfi_def_cfa_offset 16
 134              		.cfi_offset 6, -16
 135 00b6 4889E5   		movq	%rsp, %rbp	#,
 136              		.cfi_def_cfa_register 6
 137 00b9 48897DE8 		movq	%rdi, -24(%rbp)	# str, str
 138              	# ass1.c:20:     for (i = 0; str[i] != '\0'; i++) // computing length of the string
  19:ass1.c        ****     int i;
  20:ass1.c        ****     for (i = 0; str[i] != '\0'; i++) // computing length of the string
 139              		.loc 1 20 12
 140 00bd C745FC00 		movl	$0, -4(%rbp)	#, i
 140      000000
 141              	# ass1.c:20:     for (i = 0; str[i] != '\0'; i++) // computing length of the string
 142              		.loc 1 20 5
 143 00c4 EB04     		jmp	.L5	#
 144              	.L6:
 145              	# ass1.c:20:     for (i = 0; str[i] != '\0'; i++) // computing length of the string
 146              		.loc 1 20 34 discriminator 3
 147 00c6 8345FC01 		addl	$1, -4(%rbp)	#, i
 148              	.L5:
 149              	# ass1.c:20:     for (i = 0; str[i] != '\0'; i++) // computing length of the string
 150              		.loc 1 20 20 discriminator 1
 151 00ca 8B45FC   		movl	-4(%rbp), %eax	# i, tmp87
 152 00cd 4863D0   		movslq	%eax, %rdx	# tmp87, _1
 153 00d0 488B45E8 		movq	-24(%rbp), %rax	# str, tmp88
 154 00d4 4801D0   		addq	%rdx, %rax	# _1, _2
 155 00d7 0FB600   		movzbl	(%rax), %eax	# *_2, _3
 156              	# ass1.c:20:     for (i = 0; str[i] != '\0'; i++) // computing length of the string
 157              		.loc 1 20 5 discriminator 1
 158 00da 84C0     		testb	%al, %al	# _3
 159 00dc 75E8     		jne	.L6	#,
 160              	# ass1.c:24:     return i;
  21:ass1.c        ****     {
  22:ass1.c        ****         ;
  23:ass1.c        ****     }
  24:ass1.c        ****     return i;
 161              		.loc 1 24 12
 162 00de 8B45FC   		movl	-4(%rbp), %eax	# i, _8
 163              	# ass1.c:25: }
  25:ass1.c        **** }
 164              		.loc 1 25 1
 165 00e1 5D       		popq	%rbp	#
 166              		.cfi_def_cfa 7, 8
 167 00e2 C3       		ret	
 168              		.cfi_endproc
 169              	.LFE1:
 171              		.globl	sort
 173              	sort:
 174              	.LFB2:
  26:ass1.c        **** void sort(char str[20], int len, char dest[20])
  27:ass1.c        **** {
 175              		.loc 1 27 1
 176              		.cfi_startproc
 177 00e3 F30F1EFA 		endbr64	
 178 00e7 55       		pushq	%rbp	#
 179              		.cfi_def_cfa_offset 16
 180              		.cfi_offset 6, -16
 181 00e8 4889E5   		movq	%rsp, %rbp	#,
 182              		.cfi_def_cfa_register 6
 183 00eb 4883EC30 		subq	$48, %rsp	#,
 184 00ef 48897DE8 		movq	%rdi, -24(%rbp)	# str, str
 185 00f3 8975E4   		movl	%esi, -28(%rbp)	# len, len
 186 00f6 488955D8 		movq	%rdx, -40(%rbp)	# dest, dest
 187              	# ass1.c:30:     for (i = 0; i < len; i++)
  28:ass1.c        ****     int i, j;
  29:ass1.c        ****     char temp;
  30:ass1.c        ****     for (i = 0; i < len; i++)
 188              		.loc 1 30 12
 189 00fa C745F800 		movl	$0, -8(%rbp)	#, i
 189      000000
 190              	# ass1.c:30:     for (i = 0; i < len; i++)
 191              		.loc 1 30 5
 192 0101 E9820000 		jmp	.L9	#
 192      00
 193              	.L13:
 194              	# ass1.c:32:         for (j = 0; j < len; j++)
  31:ass1.c        ****     {
  32:ass1.c        ****         for (j = 0; j < len; j++)
 195              		.loc 1 32 16
 196 0106 C745FC00 		movl	$0, -4(%rbp)	#, j
 196      000000
 197              	# ass1.c:32:         for (j = 0; j < len; j++)
 198              		.loc 1 32 9
 199 010d EB6D     		jmp	.L10	#
 200              	.L12:
 201              	# ass1.c:34:             if (str[i] < str[j]) // sorting in ascending order
  33:ass1.c        ****         {
  34:ass1.c        ****             if (str[i] < str[j]) // sorting in ascending order
 202              		.loc 1 34 20
 203 010f 8B45F8   		movl	-8(%rbp), %eax	# i, tmp97
 204 0112 4863D0   		movslq	%eax, %rdx	# tmp97, _1
 205 0115 488B45E8 		movq	-24(%rbp), %rax	# str, tmp98
 206 0119 4801D0   		addq	%rdx, %rax	# _1, _2
 207 011c 0FB610   		movzbl	(%rax), %edx	# *_2, _3
 208              	# ass1.c:34:             if (str[i] < str[j]) // sorting in ascending order
 209              		.loc 1 34 29
 210 011f 8B45FC   		movl	-4(%rbp), %eax	# j, tmp99
 211 0122 4863C8   		movslq	%eax, %rcx	# tmp99, _4
 212 0125 488B45E8 		movq	-24(%rbp), %rax	# str, tmp100
 213 0129 4801C8   		addq	%rcx, %rax	# _4, _5
 214 012c 0FB600   		movzbl	(%rax), %eax	# *_5, _6
 215              	# ass1.c:34:             if (str[i] < str[j]) // sorting in ascending order
 216              		.loc 1 34 16
 217 012f 38C2     		cmpb	%al, %dl	# _6, _3
 218 0131 7D45     		jge	.L11	#,
 219              	# ass1.c:36:                 temp = str[i];
  35:ass1.c        ****             {
  36:ass1.c        ****                 temp = str[i];
 220              		.loc 1 36 27
 221 0133 8B45F8   		movl	-8(%rbp), %eax	# i, tmp101
 222 0136 4863D0   		movslq	%eax, %rdx	# tmp101, _7
 223 0139 488B45E8 		movq	-24(%rbp), %rax	# str, tmp102
 224 013d 4801D0   		addq	%rdx, %rax	# _7, _8
 225              	# ass1.c:36:                 temp = str[i];
 226              		.loc 1 36 22
 227 0140 0FB600   		movzbl	(%rax), %eax	# *_8, tmp103
 228 0143 8845F7   		movb	%al, -9(%rbp)	# tmp103, temp
 229              	# ass1.c:37:                 str[i] = str[j];
  37:ass1.c        ****                 str[i] = str[j];
 230              		.loc 1 37 29
 231 0146 8B45FC   		movl	-4(%rbp), %eax	# j, tmp104
 232 0149 4863D0   		movslq	%eax, %rdx	# tmp104, _9
 233 014c 488B45E8 		movq	-24(%rbp), %rax	# str, tmp105
 234 0150 4801D0   		addq	%rdx, %rax	# _9, _10
 235              	# ass1.c:37:                 str[i] = str[j];
 236              		.loc 1 37 20
 237 0153 8B55F8   		movl	-8(%rbp), %edx	# i, tmp106
 238 0156 4863CA   		movslq	%edx, %rcx	# tmp106, _11
 239 0159 488B55E8 		movq	-24(%rbp), %rdx	# str, tmp107
 240 015d 4801CA   		addq	%rcx, %rdx	# _11, _12
 241              	# ass1.c:37:                 str[i] = str[j];
 242              		.loc 1 37 29
 243 0160 0FB600   		movzbl	(%rax), %eax	# *_10, _13
 244              	# ass1.c:37:                 str[i] = str[j];
 245              		.loc 1 37 24
 246 0163 8802     		movb	%al, (%rdx)	# _13, *_12
 247              	# ass1.c:38:                 str[j] = temp;
  38:ass1.c        ****                 str[j] = temp;
 248              		.loc 1 38 20
 249 0165 8B45FC   		movl	-4(%rbp), %eax	# j, tmp108
 250 0168 4863D0   		movslq	%eax, %rdx	# tmp108, _14
 251 016b 488B45E8 		movq	-24(%rbp), %rax	# str, tmp109
 252 016f 4801C2   		addq	%rax, %rdx	# tmp109, _15
 253              	# ass1.c:38:                 str[j] = temp;
 254              		.loc 1 38 24
 255 0172 0FB645F7 		movzbl	-9(%rbp), %eax	# temp, tmp110
 256 0176 8802     		movb	%al, (%rdx)	# tmp110, *_15
 257              	.L11:
 258              	# ass1.c:32:         for (j = 0; j < len; j++)
  32:ass1.c        ****         {
 259              		.loc 1 32 31 discriminator 2
 260 0178 8345FC01 		addl	$1, -4(%rbp)	#, j
 261              	.L10:
 262              	# ass1.c:32:         for (j = 0; j < len; j++)
  32:ass1.c        ****         {
 263              		.loc 1 32 9 discriminator 1
 264 017c 8B45FC   		movl	-4(%rbp), %eax	# j, tmp111
 265 017f 3B45E4   		cmpl	-28(%rbp), %eax	# len, tmp111
 266 0182 7C8B     		jl	.L12	#,
 267              	# ass1.c:30:     for (i = 0; i < len; i++)
  30:ass1.c        ****     {
 268              		.loc 1 30 27 discriminator 2
 269 0184 8345F801 		addl	$1, -8(%rbp)	#, i
 270              	.L9:
 271              	# ass1.c:30:     for (i = 0; i < len; i++)
  30:ass1.c        ****     {
 272              		.loc 1 30 5 discriminator 1
 273 0188 8B45F8   		movl	-8(%rbp), %eax	# i, tmp112
 274 018b 3B45E4   		cmpl	-28(%rbp), %eax	# len, tmp112
 275 018e 0F8C72FF 		jl	.L13	#,
 275      FFFF
 276              	# ass1.c:43:     reverse(str, len, dest);
  39:ass1.c        ****             }
  40:ass1.c        ****         }
  41:ass1.c        ****     }
  42:ass1.c        ****     // calling reverse to sort the array in descending order
  43:ass1.c        ****     reverse(str, len, dest);
 277              		.loc 1 43 5
 278 0194 488B55D8 		movq	-40(%rbp), %rdx	# dest, tmp113
 279 0198 8B4DE4   		movl	-28(%rbp), %ecx	# len, tmp114
 280 019b 488B45E8 		movq	-24(%rbp), %rax	# str, tmp115
 281 019f 89CE     		movl	%ecx, %esi	# tmp114,
 282 01a1 4889C7   		movq	%rax, %rdi	# tmp115,
 283 01a4 E8000000 		call	reverse	#
 283      00
 284              	# ass1.c:44: }
  44:ass1.c        **** }
 285              		.loc 1 44 1
 286 01a9 90       		nop	
 287 01aa C9       		leave	
 288              		.cfi_def_cfa 7, 8
 289 01ab C3       		ret	
 290              		.cfi_endproc
 291              	.LFE2:
 293              		.globl	reverse
 295              	reverse:
 296              	.LFB3:
  45:ass1.c        **** void reverse(char str[20], int len, char dest[50])
  46:ass1.c        **** {
 297              		.loc 1 46 1
 298              		.cfi_startproc
 299 01ac F30F1EFA 		endbr64	
 300 01b0 55       		pushq	%rbp	#
 301              		.cfi_def_cfa_offset 16
 302              		.cfi_offset 6, -16
 303 01b1 4889E5   		movq	%rsp, %rbp	#,
 304              		.cfi_def_cfa_register 6
 305 01b4 48897DE8 		movq	%rdi, -24(%rbp)	# str, str
 306 01b8 8975E4   		movl	%esi, -28(%rbp)	# len, len
 307 01bb 488955D8 		movq	%rdx, -40(%rbp)	# dest, dest
 308              	# ass1.c:49:     for (i = 0; i < len / 2; i++)
  47:ass1.c        ****     int i, j;
  48:ass1.c        ****     char temp;
  49:ass1.c        ****     for (i = 0; i < len / 2; i++)
 309              		.loc 1 49 12
 310 01bf C745F800 		movl	$0, -8(%rbp)	#, i
 310      000000
 311              	# ass1.c:49:     for (i = 0; i < len / 2; i++)
 312              		.loc 1 49 5
 313 01c6 EB72     		jmp	.L15	#
 314              	.L20:
 315              	# ass1.c:51:         for (j = len - i - 1; j >= len / 2; j--) // reversing the string
  50:ass1.c        ****     {
  51:ass1.c        ****         for (j = len - i - 1; j >= len / 2; j--) // reversing the string
 316              		.loc 1 51 22
 317 01c8 8B45E4   		movl	-28(%rbp), %eax	# len, tmp99
 318 01cb 2B45F8   		subl	-8(%rbp), %eax	# i, _1
 319              	# ass1.c:51:         for (j = len - i - 1; j >= len / 2; j--) // reversing the string
 320              		.loc 1 51 16
 321 01ce 83E801   		subl	$1, %eax	#, tmp100
 322 01d1 8945FC   		movl	%eax, -4(%rbp)	# tmp100, j
 323              	# ass1.c:51:         for (j = len - i - 1; j >= len / 2; j--) // reversing the string
 324              		.loc 1 51 9
 325 01d4 90       		nop	
 326              	# ass1.c:51:         for (j = len - i - 1; j >= len / 2; j--) // reversing the string
 327              		.loc 1 51 40
 328 01d5 8B45E4   		movl	-28(%rbp), %eax	# len, tmp112
 329 01d8 89C2     		movl	%eax, %edx	# tmp112, tmp113
 330 01da C1EA1F   		shrl	$31, %edx	#, tmp113
 331 01dd 01D0     		addl	%edx, %eax	# tmp113, tmp114
 332 01df D1F8     		sarl	%eax	# tmp115
 333              	# ass1.c:51:         for (j = len - i - 1; j >= len / 2; j--) // reversing the string
 334              		.loc 1 51 9
 335 01e1 3945FC   		cmpl	%eax, -4(%rbp)	# _11, j
 336 01e4 7C50     		jl	.L18	#,
 337              	# ass1.c:53:             if (i == j)
  52:ass1.c        ****         {
  53:ass1.c        ****             if (i == j)
 338              		.loc 1 53 16
 339 01e6 8B45F8   		movl	-8(%rbp), %eax	# i, tmp101
 340 01e9 3B45FC   		cmpl	-4(%rbp), %eax	# j, tmp101
 341 01ec 7447     		je	.L23	#,
 342              	# ass1.c:57:                 temp = str[i];
  54:ass1.c        ****                 break;
  55:ass1.c        ****             else
  56:ass1.c        ****             {
  57:ass1.c        ****                 temp = str[i];
 343              		.loc 1 57 27
 344 01ee 8B45F8   		movl	-8(%rbp), %eax	# i, tmp102
 345 01f1 4863D0   		movslq	%eax, %rdx	# tmp102, _2
 346 01f4 488B45E8 		movq	-24(%rbp), %rax	# str, tmp103
 347 01f8 4801D0   		addq	%rdx, %rax	# _2, _3
 348              	# ass1.c:57:                 temp = str[i];
 349              		.loc 1 57 22
 350 01fb 0FB600   		movzbl	(%rax), %eax	# *_3, tmp104
 351 01fe 8845F7   		movb	%al, -9(%rbp)	# tmp104, temp
 352              	# ass1.c:58:                 str[i] = str[j];
  58:ass1.c        ****                 str[i] = str[j];
 353              		.loc 1 58 29
 354 0201 8B45FC   		movl	-4(%rbp), %eax	# j, tmp105
 355 0204 4863D0   		movslq	%eax, %rdx	# tmp105, _4
 356 0207 488B45E8 		movq	-24(%rbp), %rax	# str, tmp106
 357 020b 4801D0   		addq	%rdx, %rax	# _4, _5
 358              	# ass1.c:58:                 str[i] = str[j];
 359              		.loc 1 58 20
 360 020e 8B55F8   		movl	-8(%rbp), %edx	# i, tmp107
 361 0211 4863CA   		movslq	%edx, %rcx	# tmp107, _6
 362 0214 488B55E8 		movq	-24(%rbp), %rdx	# str, tmp108
 363 0218 4801CA   		addq	%rcx, %rdx	# _6, _7
 364              	# ass1.c:58:                 str[i] = str[j];
 365              		.loc 1 58 29
 366 021b 0FB600   		movzbl	(%rax), %eax	# *_5, _8
 367              	# ass1.c:58:                 str[i] = str[j];
 368              		.loc 1 58 24
 369 021e 8802     		movb	%al, (%rdx)	# _8, *_7
 370              	# ass1.c:59:                 str[j] = temp;
  59:ass1.c        ****                 str[j] = temp;
 371              		.loc 1 59 20
 372 0220 8B45FC   		movl	-4(%rbp), %eax	# j, tmp109
 373 0223 4863D0   		movslq	%eax, %rdx	# tmp109, _9
 374 0226 488B45E8 		movq	-24(%rbp), %rax	# str, tmp110
 375 022a 4801C2   		addq	%rax, %rdx	# tmp110, _10
 376              	# ass1.c:59:                 str[j] = temp;
 377              		.loc 1 59 24
 378 022d 0FB645F7 		movzbl	-9(%rbp), %eax	# temp, tmp111
 379 0231 8802     		movb	%al, (%rdx)	# tmp111, *_10
 380              	# ass1.c:60:                 break;
  60:ass1.c        ****                 break;
 381              		.loc 1 60 17
 382 0233 EB01     		jmp	.L18	#
 383              	.L23:
 384              	# ass1.c:54:                 break;
  54:ass1.c        ****             else
 385              		.loc 1 54 17
 386 0235 90       		nop	
 387              	.L18:
 388              	# ass1.c:49:     for (i = 0; i < len / 2; i++)
  49:ass1.c        ****     {
 389              		.loc 1 49 31 discriminator 2
 390 0236 8345F801 		addl	$1, -8(%rbp)	#, i
 391              	.L15:
 392              	# ass1.c:49:     for (i = 0; i < len / 2; i++)
  49:ass1.c        ****     {
 393              		.loc 1 49 25 discriminator 1
 394 023a 8B45E4   		movl	-28(%rbp), %eax	# len, tmp116
 395 023d 89C2     		movl	%eax, %edx	# tmp116, tmp117
 396 023f C1EA1F   		shrl	$31, %edx	#, tmp117
 397 0242 01D0     		addl	%edx, %eax	# tmp117, tmp118
 398 0244 D1F8     		sarl	%eax	# tmp119
 399              	# ass1.c:49:     for (i = 0; i < len / 2; i++)
  49:ass1.c        ****     {
 400              		.loc 1 49 5 discriminator 1
 401 0246 3945F8   		cmpl	%eax, -8(%rbp)	# _12, i
 402 0249 0F8C79FF 		jl	.L20	#,
 402      FFFF
 403              	# ass1.c:64:     for (i = 0; i <= len; i++)
  61:ass1.c        ****             }
  62:ass1.c        ****         }
  63:ass1.c        ****     }
  64:ass1.c        ****     for (i = 0; i <= len; i++)
 404              		.loc 1 64 12
 405 024f C745F800 		movl	$0, -8(%rbp)	#, i
 405      000000
 406              	# ass1.c:64:     for (i = 0; i <= len; i++)
 407              		.loc 1 64 5
 408 0256 EB23     		jmp	.L21	#
 409              	.L22:
 410              	# ass1.c:65:         dest[i] = str[i];
  65:ass1.c        ****         dest[i] = str[i];
 411              		.loc 1 65 22 discriminator 3
 412 0258 8B45F8   		movl	-8(%rbp), %eax	# i, tmp120
 413 025b 4863D0   		movslq	%eax, %rdx	# tmp120, _13
 414 025e 488B45E8 		movq	-24(%rbp), %rax	# str, tmp121
 415 0262 4801D0   		addq	%rdx, %rax	# _13, _14
 416              	# ass1.c:65:         dest[i] = str[i];
 417              		.loc 1 65 13 discriminator 3
 418 0265 8B55F8   		movl	-8(%rbp), %edx	# i, tmp122
 419 0268 4863CA   		movslq	%edx, %rcx	# tmp122, _15
 420 026b 488B55D8 		movq	-40(%rbp), %rdx	# dest, tmp123
 421 026f 4801CA   		addq	%rcx, %rdx	# _15, _16
 422              	# ass1.c:65:         dest[i] = str[i];
 423              		.loc 1 65 22 discriminator 3
 424 0272 0FB600   		movzbl	(%rax), %eax	# *_14, _17
 425              	# ass1.c:65:         dest[i] = str[i];
 426              		.loc 1 65 17 discriminator 3
 427 0275 8802     		movb	%al, (%rdx)	# _17, *_16
 428              	# ass1.c:64:     for (i = 0; i <= len; i++)
  64:ass1.c        ****         dest[i] = str[i];
 429              		.loc 1 64 28 discriminator 3
 430 0277 8345F801 		addl	$1, -8(%rbp)	#, i
 431              	.L21:
 432              	# ass1.c:64:     for (i = 0; i <= len; i++)
  64:ass1.c        ****         dest[i] = str[i];
 433              		.loc 1 64 5 discriminator 1
 434 027b 8B45F8   		movl	-8(%rbp), %eax	# i, tmp124
 435 027e 3B45E4   		cmpl	-28(%rbp), %eax	# len, tmp124
 436 0281 7ED5     		jle	.L22	#,
 437              	# ass1.c:66: }
  66:ass1.c        **** }...
 438              		.loc 1 66 1
 439 0283 90       		nop	
 440 0284 90       		nop	
 441 0285 5D       		popq	%rbp	#
 442              		.cfi_def_cfa 7, 8
 443 0286 C3       		ret	
 444              		.cfi_endproc
 445              	.LFE3:
 447              	.Letext0:
 448              		.file 2 "/usr/lib/gcc/x86_64-linux-gnu/9/include/stddef.h"
 449              		.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
 450              		.file 4 "/usr/include/x86_64-linux-gnu/bits/types/struct_FILE.h"
 451              		.file 5 "/usr/include/x86_64-linux-gnu/bits/types/FILE.h"
 452              		.file 6 "/usr/include/stdio.h"
 453              		.file 7 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"
 1523              		.section	.note.gnu.property,"a"
 1524              		.align 8
 1525 0000 04000000 		.long	 1f - 0f
 1526 0004 10000000 		.long	 4f - 1f
 1527 0008 05000000 		.long	 5
 1528              	0:
 1529 000c 474E5500 		.string	 "GNU"
 1530              	1:
 1531              		.align 8
 1532 0010 020000C0 		.long	 0xc0000002
 1533 0014 04000000 		.long	 3f - 2f
 1534              	2:
 1535 0018 03000000 		.long	 0x3
 1536              	3:
 1537 001c 00000000 		.align 8
 1538              	4:
