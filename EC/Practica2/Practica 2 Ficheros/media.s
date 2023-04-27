.section .data
lista:		#.int 0x10000000, 0x10000000, 0x10000000, 0x10000000
		#.int 0x10000000, 0x10000000, 0x10000000, 0x10000000
		#.int 0x10000000, 0x10000000, 0x10000000, 0x10000000
		#.int 0x10000000, 0x10000000, 0x10000000, 0x10000000

		#.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff
		#.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff
		#.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff
		#.int 0x0fffffff, 0x0fffffff, 0x0fffffff, 0x0fffffff

		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
		.int 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff

		#.int 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1

longlista:	.int   (.-lista)/4
resultado:	.quad   0
  formato: 	.asciz	"suma = %lu = 0x%lx hex\n"

# opción: 1) no usar printf, 2)3) usar printf/fmt/exit, 4) usar tb main
# 1) as  suma.s -o suma.o
#    ld  suma.o -o suma					1232 B
# 2) as  suma.s -o suma.o				6520 B
#    ld  suma.o -o suma -lc -dynamic-linker /lib64/ld-linux-x86-64.so.2
# 3) gcc suma.s -o suma -no-pie –nostartfiles		6544 B
# 4) gcc suma.s -o suma	-no-pie				8664 B

.section .text

main: .global  main
	
	mov     $lista, %rbx
	mov  longlista, %ecx
	call suma		# == suma(&lista, longlista);
	mov  %eax, resultado
	mov  %edx, resultado+4

	mov   $formato, %rdi
	mov   resultado,%rsi
	mov   resultado,%rdx
	mov          $0,%eax	# varargin sin xmm
	call  printf		# == printf(formato, res, res);

	mov        $60, %rax
	mov  $0, %edi
	syscall			# == _exit(resultado)
	ret

suma:
	mov  $0, %eax
	mov  $0, %edx
	mov  $0, %rsi
bucle:
	add  (%rbx,%rsi,4), %eax
	adc  $0, %edx

	inc   %rsi
	cmp   %rsi,%rcx
	jne    bucle

	ret



#imprim_C:			# requiere libC

acabar_L:
	

#acabar_C:			# requiere libC
#	mov  resultado, %edi
#	call _exit		# ==  exit(resultado)
#	ret