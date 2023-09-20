#Compiled with gcc -c -m32 -S -fverbose-asm main.c

	.file	"main.c"
# GNU C17 (Ubuntu 11.4.0-1ubuntu1~22.04) version 11.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -m32 -mtune=generic -march=i686 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection
	.text
	.globl	var_prod_ele
	.type	var_prod_ele, @function
var_prod_ele:
.LFB0:
	.cfi_startproc
	pushl	%ebp	#
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp	#,
	.cfi_def_cfa_register 5
	pushl	%edi	#
	pushl	%esi	#
	pushl	%ebx	#
	subl	$20, %esp	#,
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	call	__x86.get_pc_thunk.ax	#
	addl	$_GLOBAL_OFFSET_TABLE_, %eax	# tmp82,
# main.c:1: int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k) {
	movl	8(%ebp), %eax	# n, n.0_47
	leal	-1(%eax), %edx	#, _1
# main.c:1: int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k) {
	movl	%edx, -28(%ebp)	# _2, D.1550
# main.c:1: int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k) {
	movl	8(%ebp), %edx	# n, n.3_51
	leal	-1(%edx), %ecx	#, _8
# main.c:1: int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k) {
	movl	%ecx, -24(%ebp)	# _9, D.1554
# main.c:3:     int result = 0;
	movl	$0, -20(%ebp)	#, result
# main.c:5:     for (j = 0; j < n; j++)
	movl	$0, -32(%ebp)	#, j
# main.c:5:     for (j = 0; j < n; j++)
	jmp	.L2	#
.L3:
# main.c:6:         A[i][0] += A[i][j] * B[j][k];
	movl	%eax, %ebx	# n.0_47, n.8_15
	movl	20(%ebp), %ecx	# i, i.9_16
	imull	%ebx, %ecx	# n.8_15, _17
	leal	0(,%ecx,4), %ebx	#, _18
	movl	12(%ebp), %ecx	# A, tmp133
	addl	%ecx, %ebx	# tmp133, _19
# main.c:6:         A[i][0] += A[i][j] * B[j][k];
	movl	-32(%ebp), %ecx	# j, tmp134
	movl	(%ebx,%ecx,4), %ebx	# (*_19)[j_44], _20
# main.c:6:         A[i][0] += A[i][j] * B[j][k];
	movl	%edx, %esi	# n.3_51, n.10_21
	movl	-32(%ebp), %ecx	# j, j.11_22
	imull	%esi, %ecx	# n.10_21, _23
	leal	0(,%ecx,4), %esi	#, _24
	movl	16(%ebp), %ecx	# B, tmp135
	addl	%ecx, %esi	# tmp135, _25
# main.c:6:         A[i][0] += A[i][j] * B[j][k];
	movl	24(%ebp), %ecx	# k, tmp136
	movl	(%esi,%ecx,4), %ecx	# (*_25)[k_64(D)], _26
# main.c:6:         A[i][0] += A[i][j] * B[j][k];
	movl	%ebx, %esi	# _20, _20
	imull	%ecx, %esi	# _26, _20
# main.c:6:         A[i][0] += A[i][j] * B[j][k];
	movl	%eax, %ebx	# n.0_47, n.12_27
# main.c:6:         A[i][0] += A[i][j] * B[j][k];
	movl	20(%ebp), %ecx	# i, i.13_28
	imull	%ebx, %ecx	# n.12_27, _29
	leal	0(,%ecx,4), %ebx	#, _30
	movl	12(%ebp), %ecx	# A, tmp137
	addl	%ebx, %ecx	# _30, _31
	movl	(%ecx), %ebx	# (*_31)[0], _32
# main.c:6:         A[i][0] += A[i][j] * B[j][k];
	movl	%eax, %edi	# n.0_47, n.14_33
# main.c:6:         A[i][0] += A[i][j] * B[j][k];
	movl	20(%ebp), %ecx	# i, i.15_34
	imull	%edi, %ecx	# n.14_33, _35
	leal	0(,%ecx,4), %edi	#, _36
	movl	12(%ebp), %ecx	# A, tmp138
	addl	%edi, %ecx	# _36, _37
	addl	%esi, %ebx	# _65, _38
	movl	%ebx, (%ecx)	# _38, (*_37)[0]
# main.c:5:     for (j = 0; j < n; j++)
	addl	$1, -32(%ebp)	#, j
.L2:
# main.c:5:     for (j = 0; j < n; j++)
	movl	-32(%ebp), %ecx	# j, tmp139
	cmpl	8(%ebp), %ecx	# n, tmp139
	jl	.L3	#,
# main.c:9:     return A[i][0];
	movl	%eax, %edx	# n.0_47, n.16_39
	movl	20(%ebp), %eax	# i, i.17_40
	imull	%edx, %eax	# n.16_39, _41
	leal	0(,%eax,4), %edx	#, _42
	movl	12(%ebp), %eax	# A, tmp140
	addl	%edx, %eax	# _42, _43
# main.c:9:     return A[i][0];
	movl	(%eax), %eax	# (*_43)[0], _62
# main.c:10: }
	addl	$20, %esp	#,
	popl	%ebx	#
	.cfi_restore 3
	popl	%esi	#
	.cfi_restore 6
	popl	%edi	#
	.cfi_restore 7
	popl	%ebp	#
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	
	.cfi_endproc
.LFE0:
	.size	var_prod_ele, .-var_prod_ele
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp	#
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp	#,
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax	#
	addl	$_GLOBAL_OFFSET_TABLE_, %eax	# tmp82,
# main.c:13:     return 0;
	movl	$0, %eax	#, _1
# main.c:14: }
	popl	%ebp	#
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret	
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB2:
	.cfi_startproc
	movl	(%esp), %eax	#,
	ret
	.cfi_endproc
.LFE2:
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
