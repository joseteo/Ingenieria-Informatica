	.file	"daxpy.c"
	.text
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC1:
	.string	"Faltan recibir por parametro el tama\303\261o y un numero \n"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC6:
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
	jle	.L32
	movq	8(%rsi), %rdi
	movl	$10, %edx
	movq	%rsi, %rbx
	xorl	%esi, %esi
	call	strtol@PLT
	movq	16(%rbx), %rdi
	xorl	%esi, %esi
	movl	%eax, N(%rip)
	call	strtod@PLT
	movl	N(%rip), %r12d
	movsd	%xmm0, a(%rip)
	movq	%r12, %rbp
	salq	$3, %r12
	movq	%r12, %rdi
	call	malloc@PLT
	movq	%r12, %rdi
	movq	%rax, x(%rip)
	movq	%rax, %rbx
	call	malloc@PLT
	movq	%rax, y(%rip)
	testl	%ebp, %ebp
	je	.L3
	leal	-1(%rbp), %edx
	cmpl	$2, %edx
	jbe	.L14
	movl	%ebp, %ecx
	movdqa	.LC0(%rip), %xmm2
	movdqa	.LC2(%rip), %xmm6
	xorl	%edx, %edx
	shrl	$2, %ecx
	movdqa	.LC3(%rip), %xmm5
	movdqa	.LC4(%rip), %xmm4
	salq	$5, %rcx
	.p2align 4,,10
	.p2align 3
.L5:
	movdqa	%xmm2, %xmm0
	paddd	%xmm6, %xmm2
	movdqa	%xmm0, %xmm1
	paddd	%xmm4, %xmm0
	paddd	%xmm5, %xmm1
	cvtdq2pd	%xmm1, %xmm3
	pshufd	$238, %xmm1, %xmm1
	movups	%xmm3, (%rbx,%rdx)
	cvtdq2pd	%xmm1, %xmm1
	movups	%xmm1, 16(%rbx,%rdx)
	cvtdq2pd	%xmm0, %xmm1
	pshufd	$238, %xmm0, %xmm0
	movups	%xmm1, (%rax,%rdx)
	cvtdq2pd	%xmm0, %xmm0
	movups	%xmm0, 16(%rax,%rdx)
	addq	$32, %rdx
	cmpq	%rcx, %rdx
	jne	.L5
	movl	%ebp, %edx
	andl	$-4, %edx
	testb	$3, %bpl
	je	.L3
.L4:
	leal	1(%rdx), %ecx
	pxor	%xmm0, %xmm0
	leal	2(%rdx), %esi
	movslq	%edx, %rdi
	cvtsi2sdl	%ecx, %xmm0
	movsd	%xmm0, (%rbx,%rdi,8)
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%esi, %xmm0
	movsd	%xmm0, (%rax,%rdi,8)
	cmpl	%ecx, %ebp
	jbe	.L3
	movslq	%ecx, %rcx
	leal	3(%rdx), %edi
	movsd	%xmm0, (%rbx,%rcx,8)
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%edi, %xmm0
	movsd	%xmm0, (%rax,%rcx,8)
	cmpl	%esi, %ebp
	jbe	.L3
	movslq	%esi, %rsi
	addl	$4, %edx
	movsd	%xmm0, (%rbx,%rsi,8)
	pxor	%xmm0, %xmm0
	cvtsi2sdl	%edx, %xmm0
	movsd	%xmm0, (%rax,%rsi,8)
.L3:
	xorl	%edi, %edi
	movq	%rsp, %rsi
	call	clock_gettime@PLT
	movl	N(%rip), %edi
	testl	%edi, %edi
	je	.L7
	movq	x(%rip), %rcx
	movq	y(%rip), %rdx
	leal	-1(%rdi), %eax
	leaq	15(%rcx), %rsi
	subq	%rdx, %rsi
	cmpq	$30, %rsi
	seta	%r8b
	cmpl	$1, %eax
	seta	%sil
	testb	%sil, %r8b
	je	.L8
	movl	%edi, %esi
	leaq	(%rdx,%rsi,8), %r8
	leaq	a(%rip), %rsi
	cmpq	%rsi, %r8
	setbe	%r8b
	addq	$8, %rsi
	cmpq	%rsi, %rdx
	setnb	%sil
	orb	%sil, %r8b
	je	.L8
	movsd	a(%rip), %xmm1
	movl	%edi, %esi
	xorl	%eax, %eax
	shrl	%esi
	unpcklpd	%xmm1, %xmm1
	salq	$4, %rsi
	.p2align 4,,10
	.p2align 3
.L9:
	movupd	(%rcx,%rax), %xmm0
	movupd	(%rdx,%rax), %xmm7
	mulpd	%xmm1, %xmm0
	addpd	%xmm7, %xmm0
	movups	%xmm0, (%rdx,%rax)
	addq	$16, %rax
	cmpq	%rax, %rsi
	jne	.L9
	movl	%edi, %eax
	andl	$-2, %eax
	andl	$1, %edi
	je	.L7
	cltq
	movsd	(%rcx,%rax,8), %xmm0
	leaq	(%rdx,%rax,8), %rdx
	mulsd	a(%rip), %xmm0
	addsd	(%rdx), %xmm0
	movsd	%xmm0, (%rdx)
.L7:
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
	divsd	.LC5(%rip), %xmm0
	leaq	.LC6(%rip), %rsi
	addsd	%xmm1, %xmm0
	call	__printf_chk@PLT
	movq	40(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L33
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
.L8:
	.cfi_restore_state
	movl	%eax, %esi
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L11:
	movsd	(%rcx,%rax,8), %xmm0
	mulsd	a(%rip), %xmm0
	movq	%rax, %rdi
	addsd	(%rdx,%rax,8), %xmm0
	movsd	%xmm0, (%rdx,%rax,8)
	addq	$1, %rax
	cmpq	%rsi, %rdi
	jne	.L11
	jmp	.L7
.L14:
	xorl	%edx, %edx
	jmp	.L4
.L33:
	call	__stack_chk_fail@PLT
.L32:
	movq	stderr(%rip), %rcx
	movl	$53, %edx
	movl	$1, %esi
	leaq	.LC1(%rip), %rdi
	call	fwrite@PLT
	orl	$-1, %edi
	call	exit@PLT
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.comm	y,8,8
	.comm	x,8,8
	.globl	a
	.bss
	.align 16
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
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.long	0
	.long	1
	.long	2
	.long	3
	.align 16
.LC2:
	.long	4
	.long	4
	.long	4
	.long	4
	.align 16
.LC3:
	.long	1
	.long	1
	.long	1
	.long	1
	.align 16
.LC4:
	.long	2
	.long	2
	.long	2
	.long	2
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC5:
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
