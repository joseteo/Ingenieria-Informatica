	.file	"daxpy.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Faltan recibir por parametro el tama\303\261o y un numero \n"
.LC2:
	.string	"Tiempo (seg.): %11.9f\n"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB24:
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
	jg	.L2
	movq	stderr(%rip), %rsi
	leaq	.LC0(%rip), %rdi
	call	fputs@PLT
	orl	$-1, %edi
	call	exit@PLT
.L2:
	movq	8(%rsi), %rdi
	movq	%rsi, %rbp
	call	atoi@PLT
	movq	16(%rbp), %rdi
	movl	%eax, %r12d
	movl	%r12d, N(%rip)
	movq	%r12, %rbx
	salq	$3, %r12
	call	atof@PLT
	movq	%r12, %rdi
	movsd	%xmm0, a(%rip)
	call	malloc@PLT
	movq	%r12, %rdi
	movq	%rax, x(%rip)
	movq	%rax, %rbp
	call	malloc@PLT
	xorl	%edx, %edx
	movq	%rax, y(%rip)
.L3:
	cmpl	%edx, %ebx
	jbe	.L10
	leal	1(%rdx), %ecx
	cvtsi2sdl	%ecx, %xmm0
	leal	2(%rdx), %ecx
	movsd	%xmm0, 0(%rbp,%rdx,8)
	cvtsi2sdl	%ecx, %xmm0
	movsd	%xmm0, (%rax,%rdx,8)
	incq	%rdx
	jmp	.L3
.L10:
	leaq	8(%rsp), %rsi
	xorl	%edi, %edi
	call	clock_gettime@PLT
	movl	N(%rip), %ecx
	movq	x(%rip), %rsi
	xorl	%eax, %eax
	movq	y(%rip), %rdx
.L5:
	cmpl	%eax, %ecx
	jbe	.L11
	movsd	(%rsi,%rax,8), %xmm0
	mulsd	a(%rip), %xmm0
	addsd	(%rdx,%rax,8), %xmm0
	movsd	%xmm0, (%rdx,%rax,8)
	incq	%rax
	jmp	.L5
.L11:
	xorl	%edi, %edi
	leaq	24(%rsp), %rsi
	call	clock_gettime@PLT
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	leaq	.LC2(%rip), %rsi
	cvtsi2sdq	%rax, %xmm0
	movq	24(%rsp), %rax
	subq	8(%rsp), %rax
	divsd	.LC1(%rip), %xmm0
	cvtsi2sdq	%rax, %xmm1
	movl	$1, %edi
	movb	$1, %al
	addsd	%xmm1, %xmm0
	call	__printf_chk@PLT
	movq	40(%rsp), %rax
	xorq	%fs:40, %rax
	je	.L7
	call	__stack_chk_fail@PLT
.L7:
	addq	$48, %rsp
	.cfi_def_cfa_offset 32
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
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
