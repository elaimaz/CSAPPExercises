	.file	"bubble_sort_pointer.c"
# GNU C17 (Ubuntu 11.4.0-1ubuntu1~22.04) version 11.4.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.globl	array
	.data
	.align 32
	.type	array, @object
	.size	array, 80
array:
	.quad	7
	.quad	5
	.quad	7
	.quad	10
	.quad	9
	.quad	7
	.quad	3
	.quad	7
	.quad	8
	.quad	3
	.text
	.globl	bubble_s_pointer
	.type	bubble_s_pointer, @function
bubble_s_pointer:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	movq	%rdi, -40(%rbp)	# data, data
	movq	%rsi, -48(%rbp)	# count, count
# bubble_sort_pointer.c:5:     long* array_end = data + count - 1;
	movq	-48(%rbp), %rax	# count, count.0_1
	salq	$3, %rax	#, _2
# bubble_sort_pointer.c:5:     long* array_end = data + count - 1;
	leaq	-8(%rax), %rdx	#, _3
# bubble_sort_pointer.c:5:     long* array_end = data + count - 1;
	movq	-40(%rbp), %rax	# data, tmp96
	addq	%rdx, %rax	# _3, tmp95
	movq	%rax, -16(%rbp)	# tmp95, array_end
# bubble_sort_pointer.c:6:     for (last = count - 1; last > 0; last--) {
	movq	-48(%rbp), %rax	# count, tmp100
	subq	$1, %rax	#, tmp99
	movq	%rax, -24(%rbp)	# tmp99, last
# bubble_sort_pointer.c:6:     for (last = count - 1; last > 0; last--) {
	jmp	.L2	#
.L5:
# bubble_sort_pointer.c:8:             if (*(data + 1) < *(data)) {
	movq	-40(%rbp), %rax	# data, tmp101
	addq	$8, %rax	#, _4
# bubble_sort_pointer.c:8:             if (*(data + 1) < *(data)) {
	movq	(%rax), %rdx	# *_4, _5
# bubble_sort_pointer.c:8:             if (*(data + 1) < *(data)) {
	movq	-40(%rbp), %rax	# data, tmp102
	movq	(%rax), %rax	# *data_12, _6
# bubble_sort_pointer.c:8:             if (*(data + 1) < *(data)) {
	cmpq	%rax, %rdx	# _6, _5
	jge	.L4	#,
# bubble_sort_pointer.c:9:                 long t = *(data + 1);
	movq	-40(%rbp), %rax	# data, tmp103
	movq	8(%rax), %rax	# MEM[(long int *)data_12 + 8B], tmp104
	movq	%rax, -8(%rbp)	# tmp104, t
# bubble_sort_pointer.c:10:                 *(data + 1) = *(data);
	movq	-40(%rbp), %rax	# data, tmp105
	leaq	8(%rax), %rdx	#, _7
# bubble_sort_pointer.c:10:                 *(data + 1) = *(data);
	movq	-40(%rbp), %rax	# data, tmp106
	movq	(%rax), %rax	# *data_12, _8
# bubble_sort_pointer.c:10:                 *(data + 1) = *(data);
	movq	%rax, (%rdx)	# _8, *_7
# bubble_sort_pointer.c:11:                 *(data) = t;
	movq	-40(%rbp), %rax	# data, tmp107
	movq	-8(%rbp), %rdx	# t, tmp108
	movq	%rdx, (%rax)	# tmp108, *data_12
.L4:
# bubble_sort_pointer.c:13:             data++;
	addq	$8, -40(%rbp)	#, data
.L3:
# bubble_sort_pointer.c:7:         while(data < array_end) {
	movq	-40(%rbp), %rax	# data, tmp109
	cmpq	-16(%rbp), %rax	# array_end, tmp109
	jb	.L5	#,
# bubble_sort_pointer.c:15:         array_end--;
	subq	$8, -16(%rbp)	#, array_end
# bubble_sort_pointer.c:16:         data = data - last;
	movq	-24(%rbp), %rax	# last, last.1_9
	salq	$3, %rax	#, _10
	negq	%rax	# _11
# bubble_sort_pointer.c:16:         data = data - last;
	addq	%rax, -40(%rbp)	# _11, data
# bubble_sort_pointer.c:6:     for (last = count - 1; last > 0; last--) {
	subq	$1, -24(%rbp)	#, last
.L2:
# bubble_sort_pointer.c:6:     for (last = count - 1; last > 0; last--) {
	cmpq	$0, -24(%rbp)	#, last
	jg	.L3	#,
# bubble_sort_pointer.c:18: }
	nop	
	nop	
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	bubble_s_pointer, .-bubble_s_pointer
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
# bubble_sort_pointer.c:22:     bubble_s_pointer(array, 10);
	movl	$10, %esi	#,
	leaq	array(%rip), %rax	#, tmp84
	movq	%rax, %rdi	# tmp84,
	call	bubble_s_pointer	#
# bubble_sort_pointer.c:24:     return 0;
	movl	$0, %eax	#, _3
# bubble_sort_pointer.c:25: }
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
