	.file	"daxpy.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"Faltan recibir por parametro el tama\303\261o y un numero \n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC2:
	.string	"Tiempo (seg.): %11.9f\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$48, %rsp
	.cfi_def_cfa_offset 80
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	cmpl	$2, %edi
	jle	.L18
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movq	%rsi, %rbx
	xorl	%esi, %esi
	call	strtol@PLT
	movq	16(%rbx), %rdi
	xorl	%esi, %esi
	movl	%eax, N(%rip)
	call	strtod@PLT
	movl	N(%rip), %ebp
	movsd	%xmm0, a(%rip)
	movq	%rbp, %r12
	salq	$3, %rbp
	movq	%rbp, %rdi
	call	malloc@PLT
	movq	%rbp, %rdi
	movq	%rax, x(%rip)
	movq	%rax, %rbx
	call	malloc@PLT
	movq	%rax, y(%rip)
	testl	%r12d, %r12d
	je	.L3
	leal	-1(%r12), %esi
	movl	$1, %edx
	addq	$2, %rsi
	.p2align 4,,10
	.p2align 3
.L4:
	pxor	%xmm0, %xmm0
	leal	1(%rdx), %ecx
	cvtsi2sdl	%edx, %xmm0
	movsd	%xmm0, -8(%rbx,%rdx,8)
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%ecx, %xmm0
	movsd	%xmm0, -8(%rax,%rdx,8)
	addq	$1, %rdx
	cmpq	%rdx, %rsi
	jne	.L4
.L3:
	movq	%rsp, %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movl	N(%rip), %eax
	testl	%eax, %eax
	je	.L5
	movq	x(%rip), %rdi
	movq	y(%rip), %rdx
	leal	-1(%rax), %esi
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L6:
	movsd	(%rdi,%rax,8), %xmm0
	mulsd	a(%rip), %xmm0
	movq	%rax, %rcx
	addsd	(%rdx,%rax,8), %xmm0
	movsd	%xmm0, (%rdx,%rax,8)
	addq	$1, %rax
	cmpq	%rsi, %rcx
	jne	.L6
.L5:
	xorl	%edi, %edi
	leaq	16(%rsp), %rsi
	call	clock_gettime@PLT
	movq	24(%rsp), %rax
	pxor	%xmm0, %xmm0
	subq	8(%rsp), %rax
	cvtsi2sdq	%rax, %xmm0
	pxor	%xmm1, %xmm1
	movq	16(%rsp), %rax
	subq	(%rsp), %rax
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %edi
	movl	$1, %eax
	divsd	.LC1(%rip), %xmm0
	leaq	.LC2(%rip), %rsi
	addsd	%xmm1, %xmm0
	call	__printf_chk@PLT
	movq	40(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L19
	addq	$48, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
.L18:
	.cfi_restore_state
	movq	stderr(%rip), %rcx
	movl	$53, %edx
	movl	$1, %esi
	leaq	.LC0(%rip), %rdi
	call	fwrite@PLT
	orl	$-1, %edi
	call	exit@PLT
.L19:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.comm	y,8,8
	.comm	x,8,8
	.globl	a
	.bss
	.align 8
	.type	a, @object
	.size	a, 8
a:
	.zero	8
	.globl	N
	.align 4
	.type	N, @object
	.size	N, 4
N:
	.zero	4
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	0
	.long	1104006501
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
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
