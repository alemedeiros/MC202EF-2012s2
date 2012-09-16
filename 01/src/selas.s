	.file	"selas.c"
	.text
.Ltext0:
	.globl	consomeLinha
	.type	consomeLinha, @function
consomeLinha:
.LFB0:
	.file 1 "selas.c"
	.loc 1 15 0
	.cfi_startproc
	pushq	%rbp
.LCFI0:
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
.LCFI1:
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	.loc 1 19 0
	nop
.L3:
	.loc 1 19 0 is_stmt 0 discriminator 1
	call	getchar
	movb	%al, -1(%rbp)
	cmpb	$10, -1(%rbp)
	je	.L5
	.loc 1 19 0 discriminator 2
	cmpb	$-1, -1(%rbp)
	jne	.L3
.L5:
	.loc 1 21 0 is_stmt 1
	nop
.L1:
	.loc 1 22 0
	leave
.LCFI2:
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	consomeLinha, .-consomeLinha
	.section	.rodata
.LC0:
	.string	"Dados inv\341lidos"
	.text
	.globl	entradaInvalida
	.type	entradaInvalida, @function
entradaInvalida:
.LFB1:
	.loc 1 25 0
	.cfi_startproc
	pushq	%rbp
.LCFI3:
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
.LCFI4:
	.cfi_def_cfa_register 6
	.loc 1 28 0
	movl	$.LC0, %edi
	call	puts
	.loc 1 29 0
	movl	$0, %edi
	call	exit
	.cfi_endproc
.LFE1:
	.size	entradaInvalida, .-entradaInvalida
	.section	.rodata
.LC1:
	.string	"%d"
	.align 8
.LC2:
	.string	"Os pontos de sela da matriz s\343o:\n"
.LC3:
	.string	"%4d%4d%4d\n"
.LC4:
	.string	"    nenhum"
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.loc 1 34 0
	.cfi_startproc
	pushq	%rbp
.LCFI5:
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
.LCFI6:
	.cfi_def_cfa_register 6
	subq	$1792, %rsp
	.loc 1 39 0
	leaq	-1780(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	%eax, -12(%rbp)
	.loc 1 40 0
	movl	-1780(%rbp), %eax
	testl	%eax, %eax
	jle	.L8
	.loc 1 40 0 is_stmt 0 discriminator 1
	movl	-1780(%rbp), %eax
	cmpl	$20, %eax
	jg	.L8
	cmpl	$1, -12(%rbp)
	je	.L9
.L8:
	.loc 1 41 0 is_stmt 1
	movl	$0, %eax
	call	entradaInvalida
	jmp	.L10
.L9:
	.loc 1 43 0
	movl	$0, %eax
	call	consomeLinha
.L10:
	.loc 1 45 0
	movl	$0, -4(%rbp)
	jmp	.L11
.L15:
	.loc 1 46 0
	movl	$0, -8(%rbp)
	jmp	.L12
.L14:
	.loc 1 47 0
	leaq	-1776(%rbp), %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rsi
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rsi, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	__isoc99_scanf
	movl	%eax, -12(%rbp)
	.loc 1 49 0
	cmpl	$1, -12(%rbp)
	je	.L13
	.loc 1 50 0
	movl	$0, %eax
	call	entradaInvalida
.L13:
	.loc 1 46 0
	addl	$1, -8(%rbp)
.L12:
	.loc 1 46 0 is_stmt 0 discriminator 1
	movl	-1780(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	jl	.L14
	.loc 1 52 0 is_stmt 1
	movl	$0, %eax
	call	consomeLinha
	.loc 1 45 0
	addl	$1, -4(%rbp)
.L11:
	.loc 1 45 0 is_stmt 0 discriminator 1
	movl	-1780(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L15
	.loc 1 56 0 is_stmt 1
	movl	$0, -4(%rbp)
	jmp	.L16
.L21:
	.loc 1 58 0
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$4, %rax
	addq	%rbp, %rax
	subq	$1776, %rax
	movl	(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -176(%rbp,%rax,4)
	.loc 1 59 0
	movl	-4(%rbp), %eax
	cltq
	movl	-1776(%rbp,%rax,4), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -96(%rbp,%rax,4)
	.loc 1 61 0
	movl	$0, -8(%rbp)
	jmp	.L17
.L20:
	.loc 1 62 0
	movl	-8(%rbp), %eax
	movslq	%eax, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	-1776(%rbp,%rax,4), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	-176(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jge	.L18
	.loc 1 63 0
	movl	-8(%rbp), %eax
	movslq	%eax, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	-1776(%rbp,%rax,4), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -176(%rbp,%rax,4)
.L18:
	.loc 1 64 0
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	-1776(%rbp,%rax,4), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	-96(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jle	.L19
	.loc 1 65 0
	movl	-4(%rbp), %eax
	movslq	%eax, %rcx
	movl	-8(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	-1776(%rbp,%rax,4), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	%edx, -96(%rbp,%rax,4)
.L19:
	.loc 1 61 0
	addl	$1, -8(%rbp)
.L17:
	.loc 1 61 0 is_stmt 0 discriminator 1
	movl	-1780(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	jl	.L20
	.loc 1 56 0 is_stmt 1
	addl	$1, -4(%rbp)
.L16:
	.loc 1 56 0 is_stmt 0 discriminator 1
	movl	-1780(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L21
	.loc 1 70 0 is_stmt 1
	movl	$.LC2, %edi
	call	puts
	.loc 1 71 0
	movl	$0, -12(%rbp)
	.loc 1 73 0
	movl	$0, -4(%rbp)
	jmp	.L22
.L26:
	.loc 1 74 0
	movl	$0, -8(%rbp)
	jmp	.L23
.L25:
	.loc 1 75 0
	movl	-8(%rbp), %eax
	movslq	%eax, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	-1776(%rbp,%rax,4), %edx
	movl	-4(%rbp), %eax
	cltq
	movl	-176(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jne	.L24
	.loc 1 75 0 is_stmt 0 discriminator 1
	movl	-8(%rbp), %eax
	movslq	%eax, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	-1776(%rbp,%rax,4), %edx
	movl	-8(%rbp), %eax
	cltq
	movl	-96(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jne	.L24
	.loc 1 76 0 is_stmt 1
	movl	-8(%rbp), %eax
	movslq	%eax, %rcx
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	%rdx, %rax
	salq	$2, %rax
	addq	%rdx, %rax
	salq	$2, %rax
	addq	%rcx, %rax
	movl	-1776(%rbp,%rax,4), %ecx
	movl	-8(%rbp), %edx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	.loc 1 77 0
	addl	$1, -12(%rbp)
.L24:
	.loc 1 74 0
	addl	$1, -8(%rbp)
.L23:
	.loc 1 74 0 is_stmt 0 discriminator 1
	movl	-1780(%rbp), %eax
	cmpl	%eax, -8(%rbp)
	jl	.L25
	.loc 1 73 0 is_stmt 1
	addl	$1, -4(%rbp)
.L22:
	.loc 1 73 0 is_stmt 0 discriminator 1
	movl	-1780(%rbp), %eax
	cmpl	%eax, -4(%rbp)
	jl	.L26
	.loc 1 82 0 is_stmt 1
	cmpl	$0, -12(%rbp)
	jne	.L27
	.loc 1 83 0
	movl	$.LC4, %edi
	call	puts
.L27:
	.loc 1 85 0
	movl	$0, %eax
	.loc 1 86 0
	leave
.LCFI7:
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
.Letext0:
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x16e
	.value	0x2
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF11
	.byte	0x1
	.long	.LASF12
	.long	.LASF13
	.quad	.Ltext0
	.quad	.Letext0
	.long	.Ldebug_line0
	.long	.Ldebug_macro0
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF2
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF3
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF4
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF5
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF8
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF9
	.uleb128 0x4
	.byte	0x1
	.long	.LASF14
	.byte	0x1
	.byte	0xe
	.quad	.LFB0
	.quad	.LFE0
	.long	.LLST0
	.byte	0x1
	.long	0xac
	.uleb128 0x5
	.string	"c"
	.byte	0x1
	.byte	0x11
	.long	0x70
	.byte	0x2
	.byte	0x91
	.sleb128 -17
	.byte	0
	.uleb128 0x6
	.byte	0x1
	.long	.LASF15
	.byte	0x1
	.byte	0x18
	.quad	.LFB1
	.quad	.LFE1
	.long	.LLST1
	.byte	0x1
	.uleb128 0x7
	.byte	0x1
	.long	.LASF16
	.byte	0x1
	.byte	0x21
	.long	0x5b
	.quad	.LFB2
	.quad	.LFE2
	.long	.LLST2
	.byte	0x1
	.long	0x14f
	.uleb128 0x5
	.string	"max"
	.byte	0x1
	.byte	0x24
	.long	0x14f
	.byte	0x3
	.byte	0x91
	.sleb128 -112
	.uleb128 0x5
	.string	"min"
	.byte	0x1
	.byte	0x24
	.long	0x14f
	.byte	0x3
	.byte	0x91
	.sleb128 -192
	.uleb128 0x5
	.string	"i"
	.byte	0x1
	.byte	0x24
	.long	0x5b
	.byte	0x2
	.byte	0x91
	.sleb128 -20
	.uleb128 0x5
	.string	"j"
	.byte	0x1
	.byte	0x24
	.long	0x5b
	.byte	0x2
	.byte	0x91
	.sleb128 -24
	.uleb128 0x8
	.long	.LASF10
	.byte	0x1
	.byte	0x24
	.long	0x15f
	.byte	0x3
	.byte	0x91
	.sleb128 -1792
	.uleb128 0x5
	.string	"n"
	.byte	0x1
	.byte	0x24
	.long	0x5b
	.byte	0x3
	.byte	0x91
	.sleb128 -1796
	.uleb128 0x5
	.string	"aux"
	.byte	0x1
	.byte	0x24
	.long	0x5b
	.byte	0x2
	.byte	0x91
	.sleb128 -28
	.byte	0
	.uleb128 0x9
	.long	0x5b
	.long	0x15f
	.uleb128 0xa
	.long	0x69
	.byte	0x13
	.byte	0
	.uleb128 0xb
	.long	0x5b
	.uleb128 0xa
	.long	0x69
	.byte	0x13
	.uleb128 0xa
	.long	0x69
	.byte	0x13
	.byte	0
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x10
	.uleb128 0x6
	.uleb128 0x2119
	.uleb128 0x6
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x2116
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x2116
	.uleb128 0xc
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0xc
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x1
	.uleb128 0x40
	.uleb128 0x6
	.uleb128 0x2116
	.uleb128 0xc
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0xa
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x21
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2f
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loc,"",@progbits
.Ldebug_loc0:
.LLST0:
	.quad	.LFB0-.Ltext0
	.quad	.LCFI0-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 8
	.quad	.LCFI0-.Ltext0
	.quad	.LCFI1-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 16
	.quad	.LCFI1-.Ltext0
	.quad	.LCFI2-.Ltext0
	.value	0x2
	.byte	0x76
	.sleb128 16
	.quad	.LCFI2-.Ltext0
	.quad	.LFE0-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 8
	.quad	0
	.quad	0
.LLST1:
	.quad	.LFB1-.Ltext0
	.quad	.LCFI3-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 8
	.quad	.LCFI3-.Ltext0
	.quad	.LCFI4-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 16
	.quad	.LCFI4-.Ltext0
	.quad	.LFE1-.Ltext0
	.value	0x2
	.byte	0x76
	.sleb128 16
	.quad	0
	.quad	0
.LLST2:
	.quad	.LFB2-.Ltext0
	.quad	.LCFI5-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 8
	.quad	.LCFI5-.Ltext0
	.quad	.LCFI6-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 16
	.quad	.LCFI6-.Ltext0
	.quad	.LCFI7-.Ltext0
	.value	0x2
	.byte	0x76
	.sleb128 16
	.quad	.LCFI7-.Ltext0
	.quad	.LFE2-.Ltext0
	.value	0x2
	.byte	0x77
	.sleb128 8
	.quad	0
	.quad	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_macro,"",@progbits
.Ldebug_macro0:
	.value	0x4
	.byte	0x2
	.long	.Ldebug_line0
	.byte	0x7
	.long	.Ldebug_macro1
	.byte	0x3
	.uleb128 0
	.uleb128 0x1
	.file 2 "/usr/include/stdio.h"
	.byte	0x3
	.uleb128 0x6
	.uleb128 0x2
	.byte	0x5
	.uleb128 0x1a
	.long	.LASF17
	.file 3 "/usr/include/features.h"
	.byte	0x3
	.uleb128 0x1b
	.uleb128 0x3
	.byte	0x7
	.long	.Ldebug_macro2
	.file 4 "/usr/include/stdc-predef.h"
	.byte	0x3
	.uleb128 0x159
	.uleb128 0x4
	.byte	0x7
	.long	.Ldebug_macro3
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro4
	.file 5 "/usr/include/sys/cdefs.h"
	.byte	0x3
	.uleb128 0x177
	.uleb128 0x5
	.byte	0x7
	.long	.Ldebug_macro5
	.file 6 "/usr/include/bits/wordsize.h"
	.byte	0x3
	.uleb128 0x17a
	.uleb128 0x6
	.byte	0x7
	.long	.Ldebug_macro6
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro7
	.byte	0x4
	.file 7 "/usr/include/gnu/stubs.h"
	.byte	0x3
	.uleb128 0x18f
	.uleb128 0x7
	.file 8 "/usr/include/gnu/stubs-64.h"
	.byte	0x3
	.uleb128 0xa
	.uleb128 0x8
	.byte	0x7
	.long	.Ldebug_macro8
	.byte	0x4
	.byte	0x4
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro9
	.file 9 "/usr/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stddef.h"
	.byte	0x3
	.uleb128 0x21
	.uleb128 0x9
	.byte	0x7
	.long	.Ldebug_macro10
	.byte	0x4
	.file 10 "/usr/include/bits/types.h"
	.byte	0x3
	.uleb128 0x23
	.uleb128 0xa
	.byte	0x5
	.uleb128 0x18
	.long	.LASF18
	.byte	0x3
	.uleb128 0x1b
	.uleb128 0x6
	.byte	0x7
	.long	.Ldebug_macro6
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro11
	.file 11 "/usr/include/bits/typesizes.h"
	.byte	0x3
	.uleb128 0x82
	.uleb128 0xb
	.byte	0x7
	.long	.Ldebug_macro12
	.byte	0x4
	.byte	0x6
	.uleb128 0xca
	.long	.LASF19
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro13
	.file 12 "/usr/include/libio.h"
	.byte	0x3
	.uleb128 0x4a
	.uleb128 0xc
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF20
	.file 13 "/usr/include/_G_config.h"
	.byte	0x3
	.uleb128 0x20
	.uleb128 0xd
	.byte	0x7
	.long	.Ldebug_macro14
	.byte	0x3
	.uleb128 0xf
	.uleb128 0x9
	.byte	0x7
	.long	.Ldebug_macro15
	.byte	0x4
	.byte	0x5
	.uleb128 0x10
	.long	.LASF21
	.file 14 "/usr/include/wchar.h"
	.byte	0x3
	.uleb128 0x14
	.uleb128 0xe
	.byte	0x7
	.long	.Ldebug_macro16
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro17
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro18
	.file 15 "/usr/lib/gcc/x86_64-unknown-linux-gnu/4.7.1/include/stdarg.h"
	.byte	0x3
	.uleb128 0x35
	.uleb128 0xf
	.byte	0x7
	.long	.Ldebug_macro19
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro20
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro21
	.file 16 "/usr/include/bits/stdio_lim.h"
	.byte	0x3
	.uleb128 0xa4
	.uleb128 0x10
	.byte	0x7
	.long	.Ldebug_macro22
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro23
	.file 17 "/usr/include/bits/sys_errlist.h"
	.byte	0x3
	.uleb128 0x355
	.uleb128 0x11
	.byte	0x4
	.byte	0x4
	.file 18 "/usr/include/stdlib.h"
	.byte	0x3
	.uleb128 0x7
	.uleb128 0x12
	.byte	0x7
	.long	.Ldebug_macro24
	.byte	0x3
	.uleb128 0x20
	.uleb128 0x9
	.byte	0x7
	.long	.Ldebug_macro25
	.byte	0x4
	.byte	0x7
	.long	.Ldebug_macro26
	.byte	0x4
	.byte	0x5
	.uleb128 0xa
	.long	.LASF22
	.byte	0x5
	.uleb128 0xb
	.long	.LASF23
	.byte	0x4
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.1.e525286973b3596cbfe7028b9982764d,comdat
.Ldebug_macro1:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1
	.long	.LASF24
	.byte	0x5
	.uleb128 0x1
	.long	.LASF25
	.byte	0x5
	.uleb128 0x1
	.long	.LASF26
	.byte	0x5
	.uleb128 0x1
	.long	.LASF27
	.byte	0x5
	.uleb128 0x1
	.long	.LASF28
	.byte	0x5
	.uleb128 0x1
	.long	.LASF29
	.byte	0x5
	.uleb128 0x1
	.long	.LASF30
	.byte	0x5
	.uleb128 0x1
	.long	.LASF31
	.byte	0x5
	.uleb128 0x1
	.long	.LASF32
	.byte	0x5
	.uleb128 0x1
	.long	.LASF33
	.byte	0x5
	.uleb128 0x1
	.long	.LASF34
	.byte	0x5
	.uleb128 0x1
	.long	.LASF35
	.byte	0x5
	.uleb128 0x1
	.long	.LASF36
	.byte	0x5
	.uleb128 0x1
	.long	.LASF37
	.byte	0x5
	.uleb128 0x1
	.long	.LASF38
	.byte	0x5
	.uleb128 0x1
	.long	.LASF39
	.byte	0x5
	.uleb128 0x1
	.long	.LASF40
	.byte	0x5
	.uleb128 0x1
	.long	.LASF41
	.byte	0x5
	.uleb128 0x1
	.long	.LASF42
	.byte	0x5
	.uleb128 0x1
	.long	.LASF43
	.byte	0x5
	.uleb128 0x1
	.long	.LASF44
	.byte	0x5
	.uleb128 0x1
	.long	.LASF45
	.byte	0x5
	.uleb128 0x1
	.long	.LASF46
	.byte	0x5
	.uleb128 0x1
	.long	.LASF47
	.byte	0x5
	.uleb128 0x1
	.long	.LASF48
	.byte	0x5
	.uleb128 0x1
	.long	.LASF49
	.byte	0x5
	.uleb128 0x1
	.long	.LASF50
	.byte	0x5
	.uleb128 0x1
	.long	.LASF51
	.byte	0x5
	.uleb128 0x1
	.long	.LASF52
	.byte	0x5
	.uleb128 0x1
	.long	.LASF53
	.byte	0x5
	.uleb128 0x1
	.long	.LASF54
	.byte	0x5
	.uleb128 0x1
	.long	.LASF55
	.byte	0x5
	.uleb128 0x1
	.long	.LASF56
	.byte	0x5
	.uleb128 0x1
	.long	.LASF57
	.byte	0x5
	.uleb128 0x1
	.long	.LASF58
	.byte	0x5
	.uleb128 0x1
	.long	.LASF59
	.byte	0x5
	.uleb128 0x1
	.long	.LASF60
	.byte	0x5
	.uleb128 0x1
	.long	.LASF61
	.byte	0x5
	.uleb128 0x1
	.long	.LASF62
	.byte	0x5
	.uleb128 0x1
	.long	.LASF63
	.byte	0x5
	.uleb128 0x1
	.long	.LASF64
	.byte	0x5
	.uleb128 0x1
	.long	.LASF65
	.byte	0x5
	.uleb128 0x1
	.long	.LASF66
	.byte	0x5
	.uleb128 0x1
	.long	.LASF67
	.byte	0x5
	.uleb128 0x1
	.long	.LASF68
	.byte	0x5
	.uleb128 0x1
	.long	.LASF69
	.byte	0x5
	.uleb128 0x1
	.long	.LASF70
	.byte	0x5
	.uleb128 0x1
	.long	.LASF71
	.byte	0x5
	.uleb128 0x1
	.long	.LASF72
	.byte	0x5
	.uleb128 0x1
	.long	.LASF73
	.byte	0x5
	.uleb128 0x1
	.long	.LASF74
	.byte	0x5
	.uleb128 0x1
	.long	.LASF75
	.byte	0x5
	.uleb128 0x1
	.long	.LASF76
	.byte	0x5
	.uleb128 0x1
	.long	.LASF77
	.byte	0x5
	.uleb128 0x1
	.long	.LASF78
	.byte	0x5
	.uleb128 0x1
	.long	.LASF79
	.byte	0x5
	.uleb128 0x1
	.long	.LASF80
	.byte	0x5
	.uleb128 0x1
	.long	.LASF81
	.byte	0x5
	.uleb128 0x1
	.long	.LASF82
	.byte	0x5
	.uleb128 0x1
	.long	.LASF83
	.byte	0x5
	.uleb128 0x1
	.long	.LASF84
	.byte	0x5
	.uleb128 0x1
	.long	.LASF85
	.byte	0x5
	.uleb128 0x1
	.long	.LASF86
	.byte	0x5
	.uleb128 0x1
	.long	.LASF87
	.byte	0x5
	.uleb128 0x1
	.long	.LASF88
	.byte	0x5
	.uleb128 0x1
	.long	.LASF89
	.byte	0x5
	.uleb128 0x1
	.long	.LASF90
	.byte	0x5
	.uleb128 0x1
	.long	.LASF91
	.byte	0x5
	.uleb128 0x1
	.long	.LASF92
	.byte	0x5
	.uleb128 0x1
	.long	.LASF93
	.byte	0x5
	.uleb128 0x1
	.long	.LASF94
	.byte	0x5
	.uleb128 0x1
	.long	.LASF95
	.byte	0x5
	.uleb128 0x1
	.long	.LASF96
	.byte	0x5
	.uleb128 0x1
	.long	.LASF97
	.byte	0x5
	.uleb128 0x1
	.long	.LASF98
	.byte	0x5
	.uleb128 0x1
	.long	.LASF99
	.byte	0x5
	.uleb128 0x1
	.long	.LASF100
	.byte	0x5
	.uleb128 0x1
	.long	.LASF101
	.byte	0x5
	.uleb128 0x1
	.long	.LASF102
	.byte	0x5
	.uleb128 0x1
	.long	.LASF103
	.byte	0x5
	.uleb128 0x1
	.long	.LASF104
	.byte	0x5
	.uleb128 0x1
	.long	.LASF105
	.byte	0x5
	.uleb128 0x1
	.long	.LASF106
	.byte	0x5
	.uleb128 0x1
	.long	.LASF107
	.byte	0x5
	.uleb128 0x1
	.long	.LASF108
	.byte	0x5
	.uleb128 0x1
	.long	.LASF109
	.byte	0x5
	.uleb128 0x1
	.long	.LASF110
	.byte	0x5
	.uleb128 0x1
	.long	.LASF111
	.byte	0x5
	.uleb128 0x1
	.long	.LASF112
	.byte	0x5
	.uleb128 0x1
	.long	.LASF113
	.byte	0x5
	.uleb128 0x1
	.long	.LASF114
	.byte	0x5
	.uleb128 0x1
	.long	.LASF115
	.byte	0x5
	.uleb128 0x1
	.long	.LASF116
	.byte	0x5
	.uleb128 0x1
	.long	.LASF117
	.byte	0x5
	.uleb128 0x1
	.long	.LASF118
	.byte	0x5
	.uleb128 0x1
	.long	.LASF119
	.byte	0x5
	.uleb128 0x1
	.long	.LASF120
	.byte	0x5
	.uleb128 0x1
	.long	.LASF121
	.byte	0x5
	.uleb128 0x1
	.long	.LASF122
	.byte	0x5
	.uleb128 0x1
	.long	.LASF123
	.byte	0x5
	.uleb128 0x1
	.long	.LASF124
	.byte	0x5
	.uleb128 0x1
	.long	.LASF125
	.byte	0x5
	.uleb128 0x1
	.long	.LASF126
	.byte	0x5
	.uleb128 0x1
	.long	.LASF127
	.byte	0x5
	.uleb128 0x1
	.long	.LASF128
	.byte	0x5
	.uleb128 0x1
	.long	.LASF129
	.byte	0x5
	.uleb128 0x1
	.long	.LASF130
	.byte	0x5
	.uleb128 0x1
	.long	.LASF131
	.byte	0x5
	.uleb128 0x1
	.long	.LASF132
	.byte	0x5
	.uleb128 0x1
	.long	.LASF133
	.byte	0x5
	.uleb128 0x1
	.long	.LASF134
	.byte	0x5
	.uleb128 0x1
	.long	.LASF135
	.byte	0x5
	.uleb128 0x1
	.long	.LASF136
	.byte	0x5
	.uleb128 0x1
	.long	.LASF137
	.byte	0x5
	.uleb128 0x1
	.long	.LASF138
	.byte	0x5
	.uleb128 0x1
	.long	.LASF139
	.byte	0x5
	.uleb128 0x1
	.long	.LASF140
	.byte	0x5
	.uleb128 0x1
	.long	.LASF141
	.byte	0x5
	.uleb128 0x1
	.long	.LASF142
	.byte	0x5
	.uleb128 0x1
	.long	.LASF143
	.byte	0x5
	.uleb128 0x1
	.long	.LASF144
	.byte	0x5
	.uleb128 0x1
	.long	.LASF145
	.byte	0x5
	.uleb128 0x1
	.long	.LASF146
	.byte	0x5
	.uleb128 0x1
	.long	.LASF147
	.byte	0x5
	.uleb128 0x1
	.long	.LASF148
	.byte	0x5
	.uleb128 0x1
	.long	.LASF149
	.byte	0x5
	.uleb128 0x1
	.long	.LASF150
	.byte	0x5
	.uleb128 0x1
	.long	.LASF151
	.byte	0x5
	.uleb128 0x1
	.long	.LASF152
	.byte	0x5
	.uleb128 0x1
	.long	.LASF153
	.byte	0x5
	.uleb128 0x1
	.long	.LASF154
	.byte	0x5
	.uleb128 0x1
	.long	.LASF155
	.byte	0x5
	.uleb128 0x1
	.long	.LASF156
	.byte	0x5
	.uleb128 0x1
	.long	.LASF157
	.byte	0x5
	.uleb128 0x1
	.long	.LASF158
	.byte	0x5
	.uleb128 0x1
	.long	.LASF159
	.byte	0x5
	.uleb128 0x1
	.long	.LASF160
	.byte	0x5
	.uleb128 0x1
	.long	.LASF161
	.byte	0x5
	.uleb128 0x1
	.long	.LASF162
	.byte	0x5
	.uleb128 0x1
	.long	.LASF163
	.byte	0x5
	.uleb128 0x1
	.long	.LASF164
	.byte	0x5
	.uleb128 0x1
	.long	.LASF165
	.byte	0x5
	.uleb128 0x1
	.long	.LASF166
	.byte	0x5
	.uleb128 0x1
	.long	.LASF167
	.byte	0x5
	.uleb128 0x1
	.long	.LASF168
	.byte	0x5
	.uleb128 0x1
	.long	.LASF169
	.byte	0x5
	.uleb128 0x1
	.long	.LASF170
	.byte	0x5
	.uleb128 0x1
	.long	.LASF171
	.byte	0x5
	.uleb128 0x1
	.long	.LASF172
	.byte	0x5
	.uleb128 0x1
	.long	.LASF173
	.byte	0x5
	.uleb128 0x1
	.long	.LASF174
	.byte	0x5
	.uleb128 0x1
	.long	.LASF175
	.byte	0x5
	.uleb128 0x1
	.long	.LASF176
	.byte	0x5
	.uleb128 0x1
	.long	.LASF177
	.byte	0x5
	.uleb128 0x1
	.long	.LASF178
	.byte	0x5
	.uleb128 0x1
	.long	.LASF179
	.byte	0x5
	.uleb128 0x1
	.long	.LASF180
	.byte	0x5
	.uleb128 0x1
	.long	.LASF181
	.byte	0x5
	.uleb128 0x1
	.long	.LASF182
	.byte	0x5
	.uleb128 0x1
	.long	.LASF183
	.byte	0x5
	.uleb128 0x1
	.long	.LASF184
	.byte	0x5
	.uleb128 0x1
	.long	.LASF185
	.byte	0x5
	.uleb128 0x1
	.long	.LASF186
	.byte	0x5
	.uleb128 0x1
	.long	.LASF187
	.byte	0x5
	.uleb128 0x1
	.long	.LASF188
	.byte	0x5
	.uleb128 0x1
	.long	.LASF189
	.byte	0x5
	.uleb128 0x1
	.long	.LASF190
	.byte	0x5
	.uleb128 0x1
	.long	.LASF191
	.byte	0x5
	.uleb128 0x1
	.long	.LASF192
	.byte	0x5
	.uleb128 0x1
	.long	.LASF193
	.byte	0x5
	.uleb128 0x1
	.long	.LASF194
	.byte	0x5
	.uleb128 0x1
	.long	.LASF195
	.byte	0x5
	.uleb128 0x1
	.long	.LASF196
	.byte	0x5
	.uleb128 0x1
	.long	.LASF197
	.byte	0x5
	.uleb128 0x1
	.long	.LASF198
	.byte	0x5
	.uleb128 0x1
	.long	.LASF199
	.byte	0x5
	.uleb128 0x1
	.long	.LASF200
	.byte	0x5
	.uleb128 0x1
	.long	.LASF201
	.byte	0x5
	.uleb128 0x1
	.long	.LASF202
	.byte	0x5
	.uleb128 0x1
	.long	.LASF203
	.byte	0x5
	.uleb128 0x1
	.long	.LASF204
	.byte	0x5
	.uleb128 0x1
	.long	.LASF205
	.byte	0x5
	.uleb128 0x1
	.long	.LASF206
	.byte	0x5
	.uleb128 0x1
	.long	.LASF207
	.byte	0x5
	.uleb128 0x1
	.long	.LASF208
	.byte	0x5
	.uleb128 0x1
	.long	.LASF209
	.byte	0x5
	.uleb128 0x1
	.long	.LASF210
	.byte	0x5
	.uleb128 0x1
	.long	.LASF211
	.byte	0x5
	.uleb128 0x1
	.long	.LASF212
	.byte	0x5
	.uleb128 0x1
	.long	.LASF213
	.byte	0x5
	.uleb128 0x1
	.long	.LASF214
	.byte	0x5
	.uleb128 0x1
	.long	.LASF215
	.byte	0x5
	.uleb128 0x1
	.long	.LASF216
	.byte	0x5
	.uleb128 0x1
	.long	.LASF217
	.byte	0x5
	.uleb128 0x1
	.long	.LASF218
	.byte	0x5
	.uleb128 0x1
	.long	.LASF219
	.byte	0x5
	.uleb128 0x1
	.long	.LASF220
	.byte	0x5
	.uleb128 0x1
	.long	.LASF221
	.byte	0x5
	.uleb128 0x1
	.long	.LASF222
	.byte	0x5
	.uleb128 0x1
	.long	.LASF223
	.byte	0x5
	.uleb128 0x1
	.long	.LASF224
	.byte	0x5
	.uleb128 0x1
	.long	.LASF225
	.byte	0x5
	.uleb128 0x1
	.long	.LASF226
	.byte	0x5
	.uleb128 0x1
	.long	.LASF227
	.byte	0x5
	.uleb128 0x1
	.long	.LASF228
	.byte	0x5
	.uleb128 0x1
	.long	.LASF229
	.byte	0x5
	.uleb128 0x1
	.long	.LASF230
	.byte	0x5
	.uleb128 0x1
	.long	.LASF231
	.byte	0x5
	.uleb128 0x1
	.long	.LASF232
	.byte	0x5
	.uleb128 0x1
	.long	.LASF233
	.byte	0x5
	.uleb128 0x1
	.long	.LASF234
	.byte	0x5
	.uleb128 0x1
	.long	.LASF235
	.byte	0x5
	.uleb128 0x1
	.long	.LASF236
	.byte	0x5
	.uleb128 0x1
	.long	.LASF237
	.byte	0x5
	.uleb128 0x1
	.long	.LASF238
	.byte	0x5
	.uleb128 0x1
	.long	.LASF239
	.byte	0x5
	.uleb128 0x1
	.long	.LASF240
	.byte	0x5
	.uleb128 0x1
	.long	.LASF241
	.byte	0x5
	.uleb128 0x1
	.long	.LASF242
	.byte	0x5
	.uleb128 0x1
	.long	.LASF243
	.byte	0x5
	.uleb128 0x1
	.long	.LASF244
	.byte	0x5
	.uleb128 0x1
	.long	.LASF245
	.byte	0x5
	.uleb128 0x1
	.long	.LASF246
	.byte	0x5
	.uleb128 0x1
	.long	.LASF247
	.byte	0x5
	.uleb128 0x1
	.long	.LASF248
	.byte	0x5
	.uleb128 0x1
	.long	.LASF249
	.byte	0x5
	.uleb128 0x1
	.long	.LASF250
	.byte	0x5
	.uleb128 0x1
	.long	.LASF251
	.byte	0x5
	.uleb128 0x1
	.long	.LASF252
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.features.h.19.4f5042aedf5915c2b54ecc753c881838,comdat
.Ldebug_macro2:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x13
	.long	.LASF253
	.byte	0x6
	.uleb128 0x62
	.long	.LASF254
	.byte	0x6
	.uleb128 0x63
	.long	.LASF255
	.byte	0x6
	.uleb128 0x64
	.long	.LASF256
	.byte	0x6
	.uleb128 0x65
	.long	.LASF257
	.byte	0x6
	.uleb128 0x66
	.long	.LASF258
	.byte	0x6
	.uleb128 0x67
	.long	.LASF259
	.byte	0x6
	.uleb128 0x68
	.long	.LASF260
	.byte	0x6
	.uleb128 0x69
	.long	.LASF261
	.byte	0x6
	.uleb128 0x6a
	.long	.LASF262
	.byte	0x6
	.uleb128 0x6b
	.long	.LASF263
	.byte	0x6
	.uleb128 0x6c
	.long	.LASF264
	.byte	0x6
	.uleb128 0x6d
	.long	.LASF265
	.byte	0x6
	.uleb128 0x6e
	.long	.LASF266
	.byte	0x6
	.uleb128 0x6f
	.long	.LASF267
	.byte	0x6
	.uleb128 0x70
	.long	.LASF268
	.byte	0x6
	.uleb128 0x71
	.long	.LASF269
	.byte	0x6
	.uleb128 0x72
	.long	.LASF270
	.byte	0x6
	.uleb128 0x73
	.long	.LASF271
	.byte	0x6
	.uleb128 0x74
	.long	.LASF272
	.byte	0x6
	.uleb128 0x75
	.long	.LASF273
	.byte	0x6
	.uleb128 0x76
	.long	.LASF274
	.byte	0x6
	.uleb128 0x77
	.long	.LASF275
	.byte	0x6
	.uleb128 0x78
	.long	.LASF276
	.byte	0x6
	.uleb128 0x79
	.long	.LASF277
	.byte	0x6
	.uleb128 0x7a
	.long	.LASF278
	.byte	0x6
	.uleb128 0x7b
	.long	.LASF279
	.byte	0x6
	.uleb128 0x7c
	.long	.LASF280
	.byte	0x5
	.uleb128 0x81
	.long	.LASF281
	.byte	0x5
	.uleb128 0x85
	.long	.LASF282
	.byte	0x5
	.uleb128 0x8f
	.long	.LASF283
	.byte	0x5
	.uleb128 0xc9
	.long	.LASF284
	.byte	0x5
	.uleb128 0xcf
	.long	.LASF285
	.byte	0x5
	.uleb128 0x154
	.long	.LASF286
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stdcpredef.h.19.785b9754a8399dbf7fe5c981ac822b48,comdat
.Ldebug_macro3:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x13
	.long	.LASF287
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF288
	.byte	0x5
	.uleb128 0x1f
	.long	.LASF289
	.byte	0x5
	.uleb128 0x23
	.long	.LASF290
	.byte	0x5
	.uleb128 0x26
	.long	.LASF291
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.features.h.353.8145bd23533174fc591c830b8b195800,comdat
.Ldebug_macro4:
	.value	0x4
	.byte	0
	.byte	0x6
	.uleb128 0x161
	.long	.LASF292
	.byte	0x5
	.uleb128 0x162
	.long	.LASF293
	.byte	0x5
	.uleb128 0x166
	.long	.LASF294
	.byte	0x5
	.uleb128 0x167
	.long	.LASF295
	.byte	0x5
	.uleb128 0x169
	.long	.LASF296
	.byte	0x5
	.uleb128 0x171
	.long	.LASF297
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.cdefs.h.20.7b689723b2c293dec180079438587747,comdat
.Ldebug_macro5:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x14
	.long	.LASF298
	.byte	0x2
	.uleb128 0x23
	.string	"__P"
	.byte	0x6
	.uleb128 0x24
	.long	.LASF299
	.byte	0x5
	.uleb128 0x2b
	.long	.LASF300
	.byte	0x5
	.uleb128 0x2c
	.long	.LASF301
	.byte	0x5
	.uleb128 0x38
	.long	.LASF302
	.byte	0x5
	.uleb128 0x39
	.long	.LASF303
	.byte	0x5
	.uleb128 0x3a
	.long	.LASF304
	.byte	0x5
	.uleb128 0x53
	.long	.LASF305
	.byte	0x5
	.uleb128 0x54
	.long	.LASF306
	.byte	0x5
	.uleb128 0x59
	.long	.LASF307
	.byte	0x5
	.uleb128 0x5a
	.long	.LASF308
	.byte	0x5
	.uleb128 0x5d
	.long	.LASF309
	.byte	0x5
	.uleb128 0x5e
	.long	.LASF310
	.byte	0x5
	.uleb128 0x66
	.long	.LASF311
	.byte	0x5
	.uleb128 0x67
	.long	.LASF312
	.byte	0x5
	.uleb128 0x7b
	.long	.LASF313
	.byte	0x5
	.uleb128 0x7c
	.long	.LASF314
	.byte	0x5
	.uleb128 0x7d
	.long	.LASF315
	.byte	0x5
	.uleb128 0x7e
	.long	.LASF316
	.byte	0x5
	.uleb128 0x7f
	.long	.LASF317
	.byte	0x5
	.uleb128 0x80
	.long	.LASF318
	.byte	0x5
	.uleb128 0x86
	.long	.LASF319
	.byte	0x5
	.uleb128 0x87
	.long	.LASF320
	.byte	0x5
	.uleb128 0x88
	.long	.LASF321
	.byte	0x5
	.uleb128 0x8d
	.long	.LASF322
	.byte	0x5
	.uleb128 0x8e
	.long	.LASF323
	.byte	0x5
	.uleb128 0x8f
	.long	.LASF324
	.byte	0x5
	.uleb128 0x92
	.long	.LASF325
	.byte	0x5
	.uleb128 0x94
	.long	.LASF326
	.byte	0x5
	.uleb128 0x95
	.long	.LASF327
	.byte	0x5
	.uleb128 0xa0
	.long	.LASF328
	.byte	0x5
	.uleb128 0xbb
	.long	.LASF329
	.byte	0x5
	.uleb128 0xc2
	.long	.LASF330
	.byte	0x5
	.uleb128 0xc4
	.long	.LASF331
	.byte	0x5
	.uleb128 0xc7
	.long	.LASF332
	.byte	0x5
	.uleb128 0xc8
	.long	.LASF333
	.byte	0x5
	.uleb128 0xdd
	.long	.LASF334
	.byte	0x5
	.uleb128 0xe6
	.long	.LASF335
	.byte	0x5
	.uleb128 0xed
	.long	.LASF336
	.byte	0x5
	.uleb128 0xf6
	.long	.LASF337
	.byte	0x5
	.uleb128 0xf7
	.long	.LASF338
	.byte	0x5
	.uleb128 0xff
	.long	.LASF339
	.byte	0x5
	.uleb128 0x10b
	.long	.LASF340
	.byte	0x5
	.uleb128 0x115
	.long	.LASF341
	.byte	0x5
	.uleb128 0x11e
	.long	.LASF342
	.byte	0x5
	.uleb128 0x126
	.long	.LASF343
	.byte	0x5
	.uleb128 0x12f
	.long	.LASF344
	.byte	0x5
	.uleb128 0x134
	.long	.LASF345
	.byte	0x5
	.uleb128 0x13c
	.long	.LASF346
	.byte	0x5
	.uleb128 0x145
	.long	.LASF347
	.byte	0x5
	.uleb128 0x146
	.long	.LASF348
	.byte	0x5
	.uleb128 0x151
	.long	.LASF349
	.byte	0x5
	.uleb128 0x152
	.long	.LASF350
	.byte	0x5
	.uleb128 0x166
	.long	.LASF351
	.byte	0x5
	.uleb128 0x175
	.long	.LASF352
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.wordsize.h.4.256e8fdbd37801980286acdbc40d0280,comdat
.Ldebug_macro6:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x4
	.long	.LASF353
	.byte	0x5
	.uleb128 0xa
	.long	.LASF354
	.byte	0x5
	.uleb128 0xc
	.long	.LASF355
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.cdefs.h.400.ba2ce59b32cb52d5813cd3ab7031ec87,comdat
.Ldebug_macro7:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x190
	.long	.LASF356
	.byte	0x5
	.uleb128 0x191
	.long	.LASF357
	.byte	0x5
	.uleb128 0x192
	.long	.LASF358
	.byte	0x5
	.uleb128 0x193
	.long	.LASF359
	.byte	0x5
	.uleb128 0x194
	.long	.LASF360
	.byte	0x5
	.uleb128 0x196
	.long	.LASF361
	.byte	0x5
	.uleb128 0x197
	.long	.LASF362
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stubs64.h.10.6fb4b470a4f113ab27ac07383b62200b,comdat
.Ldebug_macro8:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xa
	.long	.LASF363
	.byte	0x5
	.uleb128 0xb
	.long	.LASF364
	.byte	0x5
	.uleb128 0xc
	.long	.LASF365
	.byte	0x5
	.uleb128 0xd
	.long	.LASF366
	.byte	0x5
	.uleb128 0xe
	.long	.LASF367
	.byte	0x5
	.uleb128 0xf
	.long	.LASF368
	.byte	0x5
	.uleb128 0x10
	.long	.LASF369
	.byte	0x5
	.uleb128 0x11
	.long	.LASF370
	.byte	0x5
	.uleb128 0x12
	.long	.LASF371
	.byte	0x5
	.uleb128 0x13
	.long	.LASF372
	.byte	0x5
	.uleb128 0x14
	.long	.LASF373
	.byte	0x5
	.uleb128 0x15
	.long	.LASF374
	.byte	0x5
	.uleb128 0x16
	.long	.LASF375
	.byte	0x5
	.uleb128 0x17
	.long	.LASF376
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stdio.h.31.e39a94e203ad4e1d978c0fc68ce016ee,comdat
.Ldebug_macro9:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1f
	.long	.LASF377
	.byte	0x5
	.uleb128 0x20
	.long	.LASF378
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stddef.h.187.f0d8b8c72c4a3728cacef55a66e187f3,comdat
.Ldebug_macro10:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xbb
	.long	.LASF379
	.byte	0x5
	.uleb128 0xbc
	.long	.LASF380
	.byte	0x5
	.uleb128 0xbd
	.long	.LASF381
	.byte	0x5
	.uleb128 0xbe
	.long	.LASF382
	.byte	0x5
	.uleb128 0xbf
	.long	.LASF383
	.byte	0x5
	.uleb128 0xc0
	.long	.LASF384
	.byte	0x5
	.uleb128 0xc1
	.long	.LASF385
	.byte	0x5
	.uleb128 0xc2
	.long	.LASF386
	.byte	0x5
	.uleb128 0xc3
	.long	.LASF387
	.byte	0x5
	.uleb128 0xc4
	.long	.LASF388
	.byte	0x5
	.uleb128 0xc5
	.long	.LASF389
	.byte	0x5
	.uleb128 0xc6
	.long	.LASF390
	.byte	0x5
	.uleb128 0xc7
	.long	.LASF391
	.byte	0x5
	.uleb128 0xc8
	.long	.LASF392
	.byte	0x5
	.uleb128 0xc9
	.long	.LASF393
	.byte	0x5
	.uleb128 0xca
	.long	.LASF394
	.byte	0x5
	.uleb128 0xcf
	.long	.LASF395
	.byte	0x6
	.uleb128 0xeb
	.long	.LASF396
	.byte	0x6
	.uleb128 0x18e
	.long	.LASF397
	.byte	0x5
	.uleb128 0x193
	.long	.LASF398
	.byte	0x6
	.uleb128 0x199
	.long	.LASF399
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.types.h.98.2414c985b07b6bc05c8aeed70b12c683,comdat
.Ldebug_macro11:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x62
	.long	.LASF400
	.byte	0x5
	.uleb128 0x63
	.long	.LASF401
	.byte	0x5
	.uleb128 0x64
	.long	.LASF402
	.byte	0x5
	.uleb128 0x65
	.long	.LASF403
	.byte	0x5
	.uleb128 0x66
	.long	.LASF404
	.byte	0x5
	.uleb128 0x67
	.long	.LASF405
	.byte	0x5
	.uleb128 0x75
	.long	.LASF406
	.byte	0x5
	.uleb128 0x76
	.long	.LASF407
	.byte	0x5
	.uleb128 0x77
	.long	.LASF408
	.byte	0x5
	.uleb128 0x78
	.long	.LASF409
	.byte	0x5
	.uleb128 0x79
	.long	.LASF410
	.byte	0x5
	.uleb128 0x7a
	.long	.LASF411
	.byte	0x5
	.uleb128 0x7b
	.long	.LASF412
	.byte	0x5
	.uleb128 0x7c
	.long	.LASF413
	.byte	0x5
	.uleb128 0x7e
	.long	.LASF414
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.typesizes.h.24.8d3208ff8ed065b1a37190f7fa7cf78c,comdat
.Ldebug_macro12:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x18
	.long	.LASF415
	.byte	0x5
	.uleb128 0x22
	.long	.LASF416
	.byte	0x5
	.uleb128 0x23
	.long	.LASF417
	.byte	0x5
	.uleb128 0x26
	.long	.LASF418
	.byte	0x5
	.uleb128 0x27
	.long	.LASF419
	.byte	0x5
	.uleb128 0x28
	.long	.LASF420
	.byte	0x5
	.uleb128 0x29
	.long	.LASF421
	.byte	0x5
	.uleb128 0x2a
	.long	.LASF422
	.byte	0x5
	.uleb128 0x2b
	.long	.LASF423
	.byte	0x5
	.uleb128 0x2d
	.long	.LASF424
	.byte	0x5
	.uleb128 0x2e
	.long	.LASF425
	.byte	0x5
	.uleb128 0x33
	.long	.LASF426
	.byte	0x5
	.uleb128 0x34
	.long	.LASF427
	.byte	0x5
	.uleb128 0x35
	.long	.LASF428
	.byte	0x5
	.uleb128 0x36
	.long	.LASF429
	.byte	0x5
	.uleb128 0x37
	.long	.LASF430
	.byte	0x5
	.uleb128 0x38
	.long	.LASF431
	.byte	0x5
	.uleb128 0x39
	.long	.LASF432
	.byte	0x5
	.uleb128 0x3a
	.long	.LASF433
	.byte	0x5
	.uleb128 0x3b
	.long	.LASF434
	.byte	0x5
	.uleb128 0x3c
	.long	.LASF435
	.byte	0x5
	.uleb128 0x3d
	.long	.LASF436
	.byte	0x5
	.uleb128 0x3e
	.long	.LASF437
	.byte	0x5
	.uleb128 0x3f
	.long	.LASF438
	.byte	0x5
	.uleb128 0x40
	.long	.LASF439
	.byte	0x5
	.uleb128 0x41
	.long	.LASF440
	.byte	0x5
	.uleb128 0x42
	.long	.LASF441
	.byte	0x5
	.uleb128 0x43
	.long	.LASF442
	.byte	0x5
	.uleb128 0x44
	.long	.LASF443
	.byte	0x5
	.uleb128 0x45
	.long	.LASF444
	.byte	0x5
	.uleb128 0x46
	.long	.LASF445
	.byte	0x5
	.uleb128 0x47
	.long	.LASF446
	.byte	0x5
	.uleb128 0x48
	.long	.LASF447
	.byte	0x5
	.uleb128 0x49
	.long	.LASF448
	.byte	0x5
	.uleb128 0x4a
	.long	.LASF449
	.byte	0x5
	.uleb128 0x4d
	.long	.LASF450
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stdio.h.36.2dd12c1fd035242ad5cfd0152a01be5a,comdat
.Ldebug_macro13:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x24
	.long	.LASF451
	.byte	0x5
	.uleb128 0x25
	.long	.LASF452
	.byte	0x5
	.uleb128 0x38
	.long	.LASF453
	.byte	0x6
	.uleb128 0x3a
	.long	.LASF454
	.byte	0x5
	.uleb128 0x42
	.long	.LASF455
	.byte	0x6
	.uleb128 0x44
	.long	.LASF456
	.byte	0x5
	.uleb128 0x48
	.long	.LASF457
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4._G_config.h.5.b0f37d9e474454cf6e459063458db32f,comdat
.Ldebug_macro14:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x5
	.long	.LASF458
	.byte	0x5
	.uleb128 0xa
	.long	.LASF377
	.byte	0x5
	.uleb128 0xe
	.long	.LASF378
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stddef.h.235.83e02bdbc4fc462f3998524016bbc512,comdat
.Ldebug_macro15:
	.value	0x4
	.byte	0
	.byte	0x6
	.uleb128 0xeb
	.long	.LASF396
	.byte	0x6
	.uleb128 0x18e
	.long	.LASF397
	.byte	0x5
	.uleb128 0x193
	.long	.LASF398
	.byte	0x6
	.uleb128 0x199
	.long	.LASF399
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.wchar.h.80.628010d306c9ecbd260f9d4475ab1db1,comdat
.Ldebug_macro16:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x50
	.long	.LASF459
	.byte	0x6
	.uleb128 0x60
	.long	.LASF460
	.byte	0x6
	.uleb128 0x383
	.long	.LASF460
	.byte	0x6
	.uleb128 0x384
	.long	.LASF461
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4._G_config.h.21.e7d3148ce21cad5440fcfc0c3b32ab8e,comdat
.Ldebug_macro17:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x15
	.long	.LASF462
	.byte	0x5
	.uleb128 0x20
	.long	.LASF463
	.byte	0x5
	.uleb128 0x21
	.long	.LASF464
	.byte	0x5
	.uleb128 0x22
	.long	.LASF465
	.byte	0x5
	.uleb128 0x23
	.long	.LASF466
	.byte	0x5
	.uleb128 0x24
	.long	.LASF467
	.byte	0x5
	.uleb128 0x25
	.long	.LASF468
	.byte	0x5
	.uleb128 0x26
	.long	.LASF469
	.byte	0x5
	.uleb128 0x27
	.long	.LASF470
	.byte	0x5
	.uleb128 0x3a
	.long	.LASF471
	.byte	0x5
	.uleb128 0x3e
	.long	.LASF472
	.byte	0x5
	.uleb128 0x3f
	.long	.LASF473
	.byte	0x5
	.uleb128 0x40
	.long	.LASF474
	.byte	0x5
	.uleb128 0x41
	.long	.LASF475
	.byte	0x5
	.uleb128 0x43
	.long	.LASF476
	.byte	0x5
	.uleb128 0x44
	.long	.LASF477
	.byte	0x5
	.uleb128 0x45
	.long	.LASF478
	.byte	0x5
	.uleb128 0x46
	.long	.LASF479
	.byte	0x5
	.uleb128 0x47
	.long	.LASF480
	.byte	0x5
	.uleb128 0x48
	.long	.LASF481
	.byte	0x5
	.uleb128 0x4a
	.long	.LASF482
	.byte	0x5
	.uleb128 0x4c
	.long	.LASF483
	.byte	0x5
	.uleb128 0x4d
	.long	.LASF484
	.byte	0x5
	.uleb128 0x4e
	.long	.LASF485
	.byte	0x5
	.uleb128 0x4f
	.long	.LASF486
	.byte	0x5
	.uleb128 0x52
	.long	.LASF487
	.byte	0x5
	.uleb128 0x54
	.long	.LASF488
	.byte	0x5
	.uleb128 0x57
	.long	.LASF489
	.byte	0x5
	.uleb128 0x58
	.long	.LASF490
	.byte	0x5
	.uleb128 0x59
	.long	.LASF491
	.byte	0x5
	.uleb128 0x5a
	.long	.LASF492
	.byte	0x5
	.uleb128 0x5b
	.long	.LASF493
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.libio.h.34.dc0a735bec80ac9f069b078d6c6ea501,comdat
.Ldebug_macro18:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x22
	.long	.LASF494
	.byte	0x5
	.uleb128 0x23
	.long	.LASF495
	.byte	0x5
	.uleb128 0x24
	.long	.LASF496
	.byte	0x5
	.uleb128 0x25
	.long	.LASF497
	.byte	0x5
	.uleb128 0x26
	.long	.LASF498
	.byte	0x5
	.uleb128 0x27
	.long	.LASF499
	.byte	0x5
	.uleb128 0x28
	.long	.LASF500
	.byte	0x5
	.uleb128 0x29
	.long	.LASF501
	.byte	0x5
	.uleb128 0x2a
	.long	.LASF502
	.byte	0x5
	.uleb128 0x2b
	.long	.LASF503
	.byte	0x5
	.uleb128 0x2c
	.long	.LASF504
	.byte	0x5
	.uleb128 0x2d
	.long	.LASF505
	.byte	0x5
	.uleb128 0x2e
	.long	.LASF506
	.byte	0x5
	.uleb128 0x2f
	.long	.LASF507
	.byte	0x5
	.uleb128 0x30
	.long	.LASF508
	.byte	0x5
	.uleb128 0x34
	.long	.LASF509
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stdarg.h.34.3a23a216c0c293b3d2ea2e89281481e6,comdat
.Ldebug_macro19:
	.value	0x4
	.byte	0
	.byte	0x6
	.uleb128 0x22
	.long	.LASF510
	.byte	0x5
	.uleb128 0x27
	.long	.LASF511
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.libio.h.55.5cf8728efb44668b09c1e3fa6c73fa4d,comdat
.Ldebug_macro20:
	.value	0x4
	.byte	0
	.byte	0x6
	.uleb128 0x37
	.long	.LASF512
	.byte	0x5
	.uleb128 0x38
	.long	.LASF513
	.byte	0x5
	.uleb128 0x40
	.long	.LASF514
	.byte	0x5
	.uleb128 0x46
	.long	.LASF515
	.byte	0x5
	.uleb128 0x55
	.long	.LASF516
	.byte	0x5
	.uleb128 0x56
	.long	.LASF517
	.byte	0x5
	.uleb128 0x57
	.long	.LASF518
	.byte	0x5
	.uleb128 0x58
	.long	.LASF519
	.byte	0x5
	.uleb128 0x59
	.long	.LASF520
	.byte	0x5
	.uleb128 0x5a
	.long	.LASF521
	.byte	0x5
	.uleb128 0x5b
	.long	.LASF522
	.byte	0x5
	.uleb128 0x5c
	.long	.LASF523
	.byte	0x5
	.uleb128 0x64
	.long	.LASF524
	.byte	0x5
	.uleb128 0x65
	.long	.LASF525
	.byte	0x5
	.uleb128 0x66
	.long	.LASF526
	.byte	0x5
	.uleb128 0x67
	.long	.LASF527
	.byte	0x5
	.uleb128 0x68
	.long	.LASF528
	.byte	0x5
	.uleb128 0x69
	.long	.LASF529
	.byte	0x5
	.uleb128 0x6a
	.long	.LASF530
	.byte	0x5
	.uleb128 0x6b
	.long	.LASF531
	.byte	0x5
	.uleb128 0x6c
	.long	.LASF532
	.byte	0x5
	.uleb128 0x6d
	.long	.LASF533
	.byte	0x5
	.uleb128 0x6e
	.long	.LASF534
	.byte	0x5
	.uleb128 0x6f
	.long	.LASF535
	.byte	0x5
	.uleb128 0x70
	.long	.LASF536
	.byte	0x5
	.uleb128 0x71
	.long	.LASF537
	.byte	0x5
	.uleb128 0x72
	.long	.LASF538
	.byte	0x5
	.uleb128 0x73
	.long	.LASF539
	.byte	0x5
	.uleb128 0x74
	.long	.LASF540
	.byte	0x5
	.uleb128 0x75
	.long	.LASF541
	.byte	0x5
	.uleb128 0x76
	.long	.LASF542
	.byte	0x5
	.uleb128 0x78
	.long	.LASF543
	.byte	0x5
	.uleb128 0x79
	.long	.LASF544
	.byte	0x5
	.uleb128 0x7d
	.long	.LASF545
	.byte	0x5
	.uleb128 0x85
	.long	.LASF546
	.byte	0x5
	.uleb128 0x86
	.long	.LASF547
	.byte	0x5
	.uleb128 0x87
	.long	.LASF548
	.byte	0x5
	.uleb128 0x88
	.long	.LASF549
	.byte	0x5
	.uleb128 0x89
	.long	.LASF550
	.byte	0x5
	.uleb128 0x8a
	.long	.LASF551
	.byte	0x5
	.uleb128 0x8b
	.long	.LASF552
	.byte	0x5
	.uleb128 0x8c
	.long	.LASF553
	.byte	0x5
	.uleb128 0x8d
	.long	.LASF554
	.byte	0x5
	.uleb128 0x8e
	.long	.LASF555
	.byte	0x5
	.uleb128 0x8f
	.long	.LASF556
	.byte	0x5
	.uleb128 0x90
	.long	.LASF557
	.byte	0x5
	.uleb128 0x91
	.long	.LASF558
	.byte	0x5
	.uleb128 0x92
	.long	.LASF559
	.byte	0x5
	.uleb128 0x93
	.long	.LASF560
	.byte	0x5
	.uleb128 0x94
	.long	.LASF561
	.byte	0x5
	.uleb128 0x95
	.long	.LASF562
	.byte	0x5
	.uleb128 0xff
	.long	.LASF563
	.byte	0x5
	.uleb128 0x11c
	.long	.LASF564
	.byte	0x5
	.uleb128 0x14c
	.long	.LASF565
	.byte	0x5
	.uleb128 0x14d
	.long	.LASF566
	.byte	0x5
	.uleb128 0x14e
	.long	.LASF567
	.byte	0x5
	.uleb128 0x198
	.long	.LASF568
	.byte	0x5
	.uleb128 0x19d
	.long	.LASF569
	.byte	0x5
	.uleb128 0x1a0
	.long	.LASF570
	.byte	0x5
	.uleb128 0x1a4
	.long	.LASF571
	.byte	0x5
	.uleb128 0x1b7
	.long	.LASF572
	.byte	0x5
	.uleb128 0x1b8
	.long	.LASF573
	.byte	0x5
	.uleb128 0x1c2
	.long	.LASF574
	.byte	0x5
	.uleb128 0x1d0
	.long	.LASF575
	.byte	0x5
	.uleb128 0x1d1
	.long	.LASF576
	.byte	0x5
	.uleb128 0x1d2
	.long	.LASF577
	.byte	0x5
	.uleb128 0x1d3
	.long	.LASF578
	.byte	0x5
	.uleb128 0x1d4
	.long	.LASF579
	.byte	0x5
	.uleb128 0x1d5
	.long	.LASF580
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stdio.h.120.80cbf0ec1718a5b27e6428218e29c72d,comdat
.Ldebug_macro21:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x78
	.long	.LASF581
	.byte	0x5
	.uleb128 0x79
	.long	.LASF582
	.byte	0x5
	.uleb128 0x7a
	.long	.LASF583
	.byte	0x5
	.uleb128 0x7f
	.long	.LASF584
	.byte	0x5
	.uleb128 0x8c
	.long	.LASF585
	.byte	0x5
	.uleb128 0x8d
	.long	.LASF586
	.byte	0x5
	.uleb128 0x8e
	.long	.LASF587
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stdio_lim.h.23.5601568edf6da86ede461f368e1c5446,comdat
.Ldebug_macro22:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x17
	.long	.LASF588
	.byte	0x5
	.uleb128 0x18
	.long	.LASF589
	.byte	0x5
	.uleb128 0x19
	.long	.LASF590
	.byte	0x6
	.uleb128 0x24
	.long	.LASF591
	.byte	0x5
	.uleb128 0x25
	.long	.LASF592
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stdio.h.172.df21df34a7396d7da2e08f9b617d582f,comdat
.Ldebug_macro23:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0xac
	.long	.LASF593
	.byte	0x5
	.uleb128 0xad
	.long	.LASF594
	.byte	0x5
	.uleb128 0xae
	.long	.LASF595
	.byte	0x5
	.uleb128 0x21f
	.long	.LASF596
	.byte	0x5
	.uleb128 0x249
	.long	.LASF597
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stdlib.h.27.59e2586c75bdbcb991b248ad7257b993,comdat
.Ldebug_macro24:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x1b
	.long	.LASF377
	.byte	0x5
	.uleb128 0x1d
	.long	.LASF598
	.byte	0x5
	.uleb128 0x1e
	.long	.LASF378
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stddef.h.235.225aa0e0a9ad52cb36dc783defd9a043,comdat
.Ldebug_macro25:
	.value	0x4
	.byte	0
	.byte	0x6
	.uleb128 0xeb
	.long	.LASF396
	.byte	0x5
	.uleb128 0x108
	.long	.LASF599
	.byte	0x5
	.uleb128 0x109
	.long	.LASF600
	.byte	0x5
	.uleb128 0x10a
	.long	.LASF601
	.byte	0x5
	.uleb128 0x10b
	.long	.LASF602
	.byte	0x5
	.uleb128 0x10c
	.long	.LASF603
	.byte	0x5
	.uleb128 0x10d
	.long	.LASF604
	.byte	0x5
	.uleb128 0x10e
	.long	.LASF605
	.byte	0x5
	.uleb128 0x10f
	.long	.LASF606
	.byte	0x5
	.uleb128 0x110
	.long	.LASF607
	.byte	0x5
	.uleb128 0x111
	.long	.LASF608
	.byte	0x5
	.uleb128 0x112
	.long	.LASF609
	.byte	0x5
	.uleb128 0x113
	.long	.LASF610
	.byte	0x5
	.uleb128 0x114
	.long	.LASF611
	.byte	0x5
	.uleb128 0x115
	.long	.LASF612
	.byte	0x5
	.uleb128 0x116
	.long	.LASF613
	.byte	0x6
	.uleb128 0x123
	.long	.LASF614
	.byte	0x6
	.uleb128 0x158
	.long	.LASF615
	.byte	0x6
	.uleb128 0x18e
	.long	.LASF397
	.byte	0x5
	.uleb128 0x193
	.long	.LASF398
	.byte	0x6
	.uleb128 0x199
	.long	.LASF399
	.byte	0
	.section	.debug_macro,"G",@progbits,wm4.stdlib.h.37.1be3071a0bfc975b56afe19d7f5e6361,comdat
.Ldebug_macro26:
	.value	0x4
	.byte	0
	.byte	0x5
	.uleb128 0x25
	.long	.LASF616
	.byte	0x5
	.uleb128 0x6e
	.long	.LASF617
	.byte	0x5
	.uleb128 0x7a
	.long	.LASF618
	.byte	0x5
	.uleb128 0x80
	.long	.LASF619
	.byte	0x5
	.uleb128 0x85
	.long	.LASF620
	.byte	0x5
	.uleb128 0x86
	.long	.LASF621
	.byte	0x5
	.uleb128 0x8a
	.long	.LASF622
	.byte	0x5
	.uleb128 0x1d3
	.long	.LASF623
	.byte	0x5
	.uleb128 0x2e7
	.long	.LASF624
	.byte	0x6
	.uleb128 0x3c4
	.long	.LASF625
	.byte	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF352:
	.string	"__glibc_unlikely(cond) __builtin_expect((cond), 0)"
.LASF550:
	.string	"_IO_DEC 020"
.LASF386:
	.string	"_SIZE_T_ "
.LASF257:
	.string	"__USE_ISOCXX11"
.LASF501:
	.string	"_IO_pid_t _G_pid_t"
.LASF389:
	.string	"_SIZE_T_DEFINED "
.LASF466:
	.string	"_G_pid_t __pid_t"
.LASF96:
	.string	"__LONG_LONG_MAX__ 9223372036854775807LL"
.LASF201:
	.string	"__DEC64_SUBNORMAL_MIN__ 0.000000000000001E-383DD"
.LASF166:
	.string	"__DBL_DECIMAL_DIG__ 17"
.LASF611:
	.string	"__INT_WCHAR_T_H "
.LASF154:
	.string	"__FLT_MIN__ 1.17549435082228750797e-38F"
.LASF149:
	.string	"__FLT_MIN_10_EXP__ (-37)"
.LASF417:
	.string	"__SYSCALL_ULONG_TYPE __ULONGWORD_TYPE"
.LASF445:
	.string	"__CLOCKID_T_TYPE __S32_TYPE"
.LASF297:
	.string	"__GLIBC_HAVE_LONG_LONG 1"
.LASF227:
	.string	"__GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1"
.LASF135:
	.string	"__INT_FAST32_MAX__ 9223372036854775807L"
.LASF200:
	.string	"__DEC64_EPSILON__ 1E-15DD"
.LASF134:
	.string	"__INT_FAST16_MAX__ 9223372036854775807L"
.LASF117:
	.string	"__INT_LEAST8_MAX__ 127"
.LASF481:
	.string	"_G_HAVE_IO_GETLINE_INFO 1"
.LASF328:
	.string	"__flexarr []"
.LASF109:
	.string	"__INT8_MAX__ 127"
.LASF609:
	.string	"_WCHAR_T_H "
.LASF126:
	.string	"__UINT8_C(c) c"
.LASF523:
	.string	"_IOS_BIN 128"
.LASF52:
	.string	"__ORDER_PDP_ENDIAN__ 3412"
.LASF346:
	.string	"__attribute_artificial__ __attribute__ ((__artificial__))"
.LASF539:
	.string	"_IO_IS_APPENDING 0x1000"
.LASF619:
	.string	"RAND_MAX 2147483647"
.LASF334:
	.string	"__attribute_malloc__ __attribute__ ((__malloc__))"
.LASF13:
	.string	"/media/Files/Codes/Monitoria 2012s2/01/src"
.LASF531:
	.string	"_IO_EOF_SEEN 0x10"
.LASF586:
	.string	"SEEK_CUR 1"
.LASF596:
	.string	"getc(_fp) _IO_getc (_fp)"
.LASF162:
	.string	"__DBL_MIN_EXP__ (-1021)"
.LASF220:
	.string	"__GCC_ATOMIC_CHAR16_T_LOCK_FREE 2"
.LASF530:
	.string	"_IO_NO_WRITES 8"
.LASF400:
	.string	"__S16_TYPE short int"
.LASF451:
	.string	"__need_FILE "
.LASF233:
	.string	"__SIZEOF_WINT_T__ 4"
.LASF283:
	.string	"__GNUC_PREREQ(maj,min) ((__GNUC__ << 16) + __GNUC_MINOR__ >= ((maj) << 16) + (min))"
.LASF381:
	.string	"_SIZE_T "
.LASF477:
	.string	"_G_HAVE_MMAP 1"
.LASF182:
	.string	"__LDBL_MIN__ 3.36210314311209350626e-4932L"
.LASF515:
	.string	"EOF (-1)"
.LASF487:
	.string	"_G_HAVE_ST_BLKSIZE defined (_STATBUF_ST_BLKSIZE)"
.LASF184:
	.string	"__LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L"
.LASF429:
	.string	"__RLIM_T_TYPE __SYSCALL_ULONG_TYPE"
.LASF28:
	.string	"__GNUC_MINOR__ 7"
.LASF542:
	.string	"_IO_USER_LOCK 0x8000"
.LASF3:
	.string	"unsigned int"
.LASF296:
	.string	"__GLIBC_PREREQ(maj,min) ((__GLIBC__ << 16) + __GLIBC_MINOR__ >= ((maj) << 16) + (min))"
.LASF378:
	.string	"__need_NULL "
.LASF407:
	.string	"__UQUAD_TYPE unsigned long int"
.LASF265:
	.string	"__USE_XOPEN2K"
.LASF62:
	.string	"__CHAR16_TYPE__ short unsigned int"
.LASF461:
	.string	"__need_wint_t"
.LASF47:
	.string	"__SIZEOF_SIZE_T__ 8"
.LASF27:
	.string	"__GNUC__ 4"
.LASF51:
	.string	"__ORDER_BIG_ENDIAN__ 4321"
.LASF536:
	.string	"_IO_LINE_BUF 0x200"
.LASF374:
	.string	"__stub_sigreturn "
.LASF385:
	.string	"__SIZE_T "
.LASF132:
	.string	"__UINT64_C(c) c ## UL"
.LASF292:
	.string	"__GNU_LIBRARY__"
.LASF160:
	.string	"__DBL_MANT_DIG__ 53"
.LASF159:
	.string	"__FLT_HAS_QUIET_NAN__ 1"
.LASF34:
	.string	"__ATOMIC_RELEASE 3"
.LASF581:
	.string	"_IOFBF 0"
.LASF431:
	.string	"__BLKCNT_T_TYPE __SYSCALL_SLONG_TYPE"
.LASF66:
	.string	"__INT16_TYPE__ short int"
.LASF193:
	.string	"__DEC32_EPSILON__ 1E-6DF"
.LASF391:
	.string	"_SIZE_T_DECLARED "
.LASF94:
	.string	"__INT_MAX__ 2147483647"
.LASF175:
	.string	"__LDBL_DIG__ 18"
.LASF313:
	.string	"__BEGIN_NAMESPACE_STD "
.LASF32:
	.string	"__ATOMIC_SEQ_CST 5"
.LASF285:
	.string	"__USE_ISOC95 1"
.LASF315:
	.string	"__USING_NAMESPACE_STD(name) "
.LASF43:
	.string	"__SIZEOF_SHORT__ 2"
.LASF30:
	.string	"__VERSION__ \"4.7.1 20120721 (prerelease)\""
.LASF72:
	.string	"__UINT64_TYPE__ long unsigned int"
.LASF566:
	.string	"_IO_stdout ((_IO_FILE*)(&_IO_2_1_stdout_))"
.LASF73:
	.string	"__INT_LEAST8_TYPE__ signed char"
.LASF614:
	.string	"_BSD_WCHAR_T_"
.LASF79:
	.string	"__UINT_LEAST32_TYPE__ unsigned int"
.LASF526:
	.string	"_IO_MAGIC_MASK 0xFFFF0000"
.LASF226:
	.string	"__GCC_ATOMIC_LLONG_LOCK_FREE 2"
.LASF402:
	.string	"__S32_TYPE int"
.LASF87:
	.string	"__UINT_FAST32_TYPE__ long unsigned int"
.LASF291:
	.string	"__STDC_NO_THREADS__ 1"
.LASF53:
	.string	"__BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__"
.LASF125:
	.string	"__UINT_LEAST8_MAX__ 255"
.LASF171:
	.string	"__DBL_HAS_DENORM__ 1"
.LASF92:
	.string	"__SCHAR_MAX__ 127"
.LASF76:
	.string	"__INT_LEAST64_TYPE__ long int"
.LASF98:
	.string	"__WCHAR_MIN__ (-__WCHAR_MAX__ - 1)"
.LASF86:
	.string	"__UINT_FAST16_TYPE__ long unsigned int"
.LASF447:
	.string	"__BLKSIZE_T_TYPE __SYSCALL_SLONG_TYPE"
.LASF493:
	.string	"_G_VTABLE_LABEL_PREFIX_ID __vt_"
.LASF153:
	.string	"__FLT_MAX__ 3.40282346638528859812e+38F"
.LASF80:
	.string	"__UINT_LEAST64_TYPE__ long unsigned int"
.LASF106:
	.string	"__UINTMAX_C(c) c ## UL"
.LASF81:
	.string	"__INT_FAST8_TYPE__ signed char"
.LASF170:
	.string	"__DBL_DENORM_MIN__ ((double)4.94065645841246544177e-324L)"
.LASF130:
	.string	"__UINT32_C(c) c ## U"
.LASF483:
	.string	"_G_OPEN64 __open64"
.LASF616:
	.string	"_STDLIB_H 1"
.LASF264:
	.string	"__USE_UNIX98"
.LASF286:
	.string	"__USE_FORTIFY_LEVEL 0"
.LASF562:
	.string	"_IO_BOOLALPHA 0200000"
.LASF252:
	.string	"__DECIMAL_BID_FORMAT__ 1"
.LASF231:
	.string	"__SIZEOF_INT128__ 16"
.LASF304:
	.string	"__NTH(fct) __attribute__ ((__nothrow__ __LEAF)) fct"
.LASF518:
	.string	"_IOS_ATEND 4"
.LASF502:
	.string	"_IO_uid_t _G_uid_t"
.LASF118:
	.string	"__INT8_C(c) c"
.LASF384:
	.string	"_T_SIZE "
.LASF584:
	.string	"BUFSIZ _IO_BUFSIZ"
.LASF75:
	.string	"__INT_LEAST32_TYPE__ int"
.LASF302:
	.string	"__THROW __attribute__ ((__nothrow__ __LEAF))"
.LASF164:
	.string	"__DBL_MAX_EXP__ 1024"
.LASF383:
	.string	"_T_SIZE_ "
.LASF573:
	.string	"_IO_ferror_unlocked(__fp) (((__fp)->_flags & _IO_ERR_SEEN) != 0)"
.LASF390:
	.string	"_BSD_SIZE_T_DEFINED_ "
.LASF347:
	.string	"__extern_inline extern __inline __attribute__ ((__gnu_inline__))"
.LASF393:
	.string	"_GCC_SIZE_T "
.LASF15:
	.string	"entradaInvalida"
.LASF250:
	.string	"__unix__ 1"
.LASF343:
	.string	"__attribute_warn_unused_result__ __attribute__ ((__warn_unused_result__))"
.LASF454:
	.string	"__need_FILE"
.LASF141:
	.string	"__INTPTR_MAX__ 9223372036854775807L"
.LASF387:
	.string	"_BSD_SIZE_T_ "
.LASF373:
	.string	"__stub_setlogin "
.LASF147:
	.string	"__FLT_DIG__ 6"
.LASF215:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1"
.LASF19:
	.string	"__STD_TYPE"
.LASF599:
	.string	"__wchar_t__ "
.LASF17:
	.string	"_STDIO_H 1"
.LASF500:
	.string	"_IO_off64_t _G_off64_t"
.LASF168:
	.string	"__DBL_MIN__ ((double)2.22507385850720138309e-308L)"
.LASF191:
	.string	"__DEC32_MIN__ 1E-95DF"
.LASF488:
	.string	"_G_BUFSIZ 8192"
.LASF303:
	.string	"__THROWNL __attribute__ ((__nothrow__))"
.LASF183:
	.string	"__LDBL_EPSILON__ 1.08420217248550443401e-19L"
.LASF604:
	.string	"__WCHAR_T "
.LASF337:
	.string	"__attribute_used__ __attribute__ ((__used__))"
.LASF203:
	.string	"__DEC128_MIN_EXP__ (-6142)"
.LASF281:
	.string	"__KERNEL_STRICT_NAMES "
.LASF489:
	.string	"_G_NAMES_HAVE_UNDERSCORE 0"
.LASF617:
	.string	"__ldiv_t_defined 1"
.LASF207:
	.string	"__DEC128_EPSILON__ 1E-33DL"
.LASF261:
	.string	"__USE_POSIX199506"
.LASF254:
	.string	"__USE_ISOC11"
.LASF331:
	.string	"__REDIRECT_NTHNL(name,proto,alias) name proto __asm__ (__ASMNAME (#alias)) __THROWNL"
.LASF145:
	.string	"__FLT_RADIX__ 2"
.LASF503:
	.string	"_IO_iconv_t _G_iconv_t"
.LASF306:
	.string	"__PMT(args) args"
.LASF420:
	.string	"__GID_T_TYPE __U32_TYPE"
.LASF46:
	.string	"__SIZEOF_LONG_DOUBLE__ 16"
.LASF173:
	.string	"__DBL_HAS_QUIET_NAN__ 1"
.LASF18:
	.string	"_BITS_TYPES_H 1"
.LASF472:
	.string	"_G_HAVE_ATEXIT 1"
.LASF428:
	.string	"__PID_T_TYPE __S32_TYPE"
.LASF116:
	.string	"__UINT64_MAX__ 18446744073709551615UL"
.LASF498:
	.string	"_IO_ssize_t _G_ssize_t"
.LASF436:
	.string	"__FSFILCNT64_T_TYPE __UQUAD_TYPE"
.LASF178:
	.string	"__LDBL_MAX_EXP__ 16384"
.LASF123:
	.string	"__INT_LEAST64_MAX__ 9223372036854775807L"
.LASF369:
	.string	"__stub_gtty "
.LASF527:
	.string	"_IO_USER_BUF 1"
.LASF440:
	.string	"__USECONDS_T_TYPE __U32_TYPE"
.LASF89:
	.string	"__INTPTR_TYPE__ long int"
.LASF199:
	.string	"__DEC64_MAX__ 9.999999999999999E384DD"
.LASF156:
	.string	"__FLT_DENORM_MIN__ 1.40129846432481707092e-45F"
.LASF224:
	.string	"__GCC_ATOMIC_INT_LOCK_FREE 2"
.LASF615:
	.string	"__need_wchar_t"
.LASF241:
	.string	"__MMX__ 1"
.LASF133:
	.string	"__INT_FAST8_MAX__ 127"
.LASF553:
	.string	"_IO_SHOWBASE 0200"
.LASF376:
	.string	"__stub_stty "
.LASF181:
	.string	"__LDBL_MAX__ 1.18973149535723176502e+4932L"
.LASF548:
	.string	"_IO_RIGHT 04"
.LASF401:
	.string	"__U16_TYPE unsigned short int"
.LASF50:
	.string	"__ORDER_LITTLE_ENDIAN__ 1234"
.LASF600:
	.string	"__WCHAR_T__ "
.LASF105:
	.string	"__UINTMAX_MAX__ 18446744073709551615UL"
.LASF234:
	.string	"__SIZEOF_PTRDIFF_T__ 8"
.LASF202:
	.string	"__DEC128_MANT_DIG__ 34"
.LASF282:
	.string	"__USE_ANSI 1"
.LASF67:
	.string	"__INT32_TYPE__ int"
.LASF333:
	.string	"__ASMNAME2(prefix,cname) __STRING (prefix) cname"
.LASF403:
	.string	"__U32_TYPE unsigned int"
.LASF362:
	.string	"__REDIRECT_NTH_LDBL(name,proto,alias) __REDIRECT_NTH (name, proto, alias)"
.LASF256:
	.string	"__USE_ISOC95"
.LASF612:
	.string	"_GCC_WCHAR_T "
.LASF190:
	.string	"__DEC32_MAX_EXP__ 97"
.LASF583:
	.string	"_IONBF 2"
.LASF255:
	.string	"__USE_ISOC99"
.LASF482:
	.string	"_G_IO_IO_FILE_VERSION 0x20001"
.LASF537:
	.string	"_IO_TIED_PUT_GET 0x400"
.LASF289:
	.string	"__STDC_IEC_559_COMPLEX__ 1"
.LASF473:
	.string	"_G_HAVE_SYS_WAIT 1"
.LASF167:
	.string	"__DBL_MAX__ ((double)1.79769313486231570815e+308L)"
.LASF287:
	.string	"_STDC_PREDEF_H 1"
.LASF371:
	.string	"__stub_putmsg "
.LASF119:
	.string	"__INT_LEAST16_MAX__ 32767"
.LASF388:
	.string	"_SIZE_T_DEFINED_ "
.LASF311:
	.string	"__BEGIN_DECLS "
.LASF397:
	.string	"NULL"
.LASF520:
	.string	"_IOS_TRUNC 16"
.LASF91:
	.string	"__GXX_ABI_VERSION 1002"
.LASF441:
	.string	"__SUSECONDS_T_TYPE __SYSCALL_SLONG_TYPE"
.LASF587:
	.string	"SEEK_END 2"
.LASF504:
	.string	"_IO_HAVE_SYS_WAIT _G_HAVE_SYS_WAIT"
.LASF535:
	.string	"_IO_IN_BACKUP 0x100"
.LASF554:
	.string	"_IO_SHOWPOINT 0400"
.LASF575:
	.string	"_IO_peekc(_fp) _IO_peekc_unlocked (_fp)"
.LASF236:
	.string	"__amd64__ 1"
.LASF279:
	.string	"__FAVOR_BSD"
.LASF533:
	.string	"_IO_DELETE_DONT_CLOSE 0x40"
.LASF353:
	.string	"__WORDSIZE 64"
.LASF517:
	.string	"_IOS_OUTPUT 2"
.LASF70:
	.string	"__UINT16_TYPE__ short unsigned int"
.LASF564:
	.string	"__HAVE_COLUMN "
.LASF525:
	.string	"_OLD_STDIO_MAGIC 0xFABC0000"
.LASF521:
	.string	"_IOS_NOCREATE 32"
.LASF219:
	.string	"__GCC_ATOMIC_CHAR_LOCK_FREE 2"
.LASF508:
	.string	"_IO_wint_t _G_wint_t"
.LASF555:
	.string	"_IO_UPPERCASE 01000"
.LASF411:
	.string	"__ULONG32_TYPE unsigned int"
.LASF78:
	.string	"__UINT_LEAST16_TYPE__ short unsigned int"
.LASF151:
	.string	"__FLT_MAX_10_EXP__ 38"
.LASF546:
	.string	"_IO_SKIPWS 01"
.LASF398:
	.string	"NULL ((void *)0)"
.LASF111:
	.string	"__INT32_MAX__ 2147483647"
.LASF342:
	.string	"__nonnull(params) __attribute__ ((__nonnull__ params))"
.LASF572:
	.string	"_IO_feof_unlocked(__fp) (((__fp)->_flags & _IO_EOF_SEEN) != 0)"
.LASF212:
	.string	"__NO_INLINE__ 1"
.LASF567:
	.string	"_IO_stderr ((_IO_FILE*)(&_IO_2_1_stderr_))"
.LASF365:
	.string	"__stub_fattach "
.LASF146:
	.string	"__FLT_MANT_DIG__ 24"
.LASF497:
	.string	"_IO_size_t _G_size_t"
.LASF310:
	.string	"__long_double_t long double"
.LASF216:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1"
.LASF605:
	.string	"_WCHAR_T_ "
.LASF330:
	.string	"__REDIRECT_NTH(name,proto,alias) name proto __asm__ (__ASMNAME (#alias)) __THROW"
.LASF56:
	.string	"__SIZE_TYPE__ long unsigned int"
.LASF448:
	.string	"__FSID_T_TYPE struct { int __val[2]; }"
.LASF144:
	.string	"__DEC_EVAL_METHOD__ 2"
.LASF309:
	.string	"__ptr_t void *"
.LASF592:
	.string	"FOPEN_MAX 16"
.LASF163:
	.string	"__DBL_MIN_10_EXP__ (-307)"
.LASF8:
	.string	"char"
.LASF460:
	.string	"__need_mbstate_t"
.LASF129:
	.string	"__UINT_LEAST32_MAX__ 4294967295U"
.LASF177:
	.string	"__LDBL_MIN_10_EXP__ (-4931)"
.LASF624:
	.string	"__COMPAR_FN_T "
.LASF505:
	.string	"_IO_HAVE_ST_BLKSIZE _G_HAVE_ST_BLKSIZE"
.LASF314:
	.string	"__END_NAMESPACE_STD "
.LASF143:
	.string	"__FLT_EVAL_METHOD__ 0"
.LASF433:
	.string	"__FSBLKCNT_T_TYPE __SYSCALL_ULONG_TYPE"
.LASF607:
	.string	"_WCHAR_T_DEFINED_ "
.LASF238:
	.string	"__x86_64__ 1"
.LASF104:
	.string	"__INTMAX_C(c) c ## L"
.LASF139:
	.string	"__UINT_FAST32_MAX__ 18446744073709551615UL"
.LASF463:
	.string	"_G_ssize_t __ssize_t"
.LASF434:
	.string	"__FSBLKCNT64_T_TYPE __UQUAD_TYPE"
.LASF559:
	.string	"_IO_UNITBUF 020000"
.LASF247:
	.string	"__linux 1"
.LASF510:
	.string	"__need___va_list"
.LASF577:
	.string	"_IO_funlockfile(_fp) "
.LASF444:
	.string	"__KEY_T_TYPE __S32_TYPE"
.LASF324:
	.string	"__fortify_function __extern_always_inline __attribute_artificial__"
.LASF349:
	.string	"__va_arg_pack() __builtin_va_arg_pack ()"
.LASF115:
	.string	"__UINT32_MAX__ 4294967295U"
.LASF471:
	.string	"_G_HAVE_BOOL 1"
.LASF345:
	.string	"__always_inline __inline __attribute__ ((__always_inline__))"
.LASF524:
	.string	"_IO_MAGIC 0xFBAD0000"
.LASF610:
	.string	"___int_wchar_t_h "
.LASF344:
	.string	"__wur "
.LASF84:
	.string	"__INT_FAST64_TYPE__ long int"
.LASF593:
	.string	"stdin stdin"
.LASF316:
	.string	"__BEGIN_NAMESPACE_C99 "
.LASF415:
	.string	"_BITS_TYPESIZES_H 1"
.LASF192:
	.string	"__DEC32_MAX__ 9.999999E96DF"
.LASF579:
	.string	"_IO_cleanup_region_start(_fct,_fp) "
.LASF260:
	.string	"__USE_POSIX199309"
.LASF74:
	.string	"__INT_LEAST16_TYPE__ short int"
.LASF348:
	.string	"__extern_always_inline extern __always_inline __attribute__ ((__gnu_inline__))"
.LASF246:
	.string	"__gnu_linux__ 1"
.LASF485:
	.string	"_G_MMAP64 __mmap64"
.LASF423:
	.string	"__MODE_T_TYPE __U32_TYPE"
.LASF161:
	.string	"__DBL_DIG__ 15"
.LASF298:
	.string	"_SYS_CDEFS_H 1"
.LASF39:
	.string	"__LP64__ 1"
.LASF225:
	.string	"__GCC_ATOMIC_LONG_LOCK_FREE 2"
.LASF127:
	.string	"__UINT_LEAST16_MAX__ 65535"
.LASF336:
	.string	"__attribute_const__ __attribute__ ((__const__))"
.LASF359:
	.string	"__LDBL_REDIR_NTH(name,proto) name proto __THROW"
.LASF38:
	.string	"_LP64 1"
.LASF253:
	.string	"_FEATURES_H 1"
.LASF459:
	.string	"____mbstate_t_defined 1"
.LASF425:
	.string	"__FSWORD_T_TYPE __SYSCALL_SLONG_TYPE"
.LASF404:
	.string	"__SLONGWORD_TYPE long int"
.LASF110:
	.string	"__INT16_MAX__ 32767"
.LASF9:
	.string	"long long int"
.LASF48:
	.string	"__CHAR_BIT__ 8"
.LASF138:
	.string	"__UINT_FAST16_MAX__ 18446744073709551615UL"
.LASF470:
	.string	"_G_stat64 stat64"
.LASF218:
	.string	"__GCC_ATOMIC_BOOL_LOCK_FREE 2"
.LASF450:
	.string	"__FD_SETSIZE 1024"
.LASF37:
	.string	"__FINITE_MATH_ONLY__ 0"
.LASF318:
	.string	"__USING_NAMESPACE_C99(name) "
.LASF580:
	.string	"_IO_cleanup_region_end(_Doit) "
.LASF358:
	.string	"__LDBL_REDIR1_NTH(name,proto,alias) name proto __THROW"
.LASF563:
	.string	"_IO_file_flags _flags"
.LASF350:
	.string	"__va_arg_pack_len() __builtin_va_arg_pack_len ()"
.LASF464:
	.string	"_G_off_t __off_t"
.LASF516:
	.string	"_IOS_INPUT 1"
.LASF93:
	.string	"__SHRT_MAX__ 32767"
.LASF597:
	.string	"putc(_ch,_fp) _IO_putc (_ch, _fp)"
.LASF414:
	.string	"__STD_TYPE typedef"
.LASF299:
	.string	"__PMT"
.LASF598:
	.string	"__need_wchar_t "
.LASF251:
	.string	"__ELF__ 1"
.LASF307:
	.string	"__CONCAT(x,y) x ## y"
.LASF90:
	.string	"__UINTPTR_TYPE__ long unsigned int"
.LASF120:
	.string	"__INT16_C(c) c"
.LASF229:
	.string	"__GCC_HAVE_DWARF2_CFI_ASM 1"
.LASF625:
	.string	"__need_malloc_and_calloc"
.LASF44:
	.string	"__SIZEOF_FLOAT__ 4"
.LASF194:
	.string	"__DEC32_SUBNORMAL_MIN__ 0.000001E-95DF"
.LASF158:
	.string	"__FLT_HAS_INFINITY__ 1"
.LASF131:
	.string	"__UINT_LEAST64_MAX__ 18446744073709551615UL"
.LASF23:
	.string	"TAMLINHA 100"
.LASF293:
	.string	"__GNU_LIBRARY__ 6"
.LASF24:
	.string	"__STDC__ 1"
.LASF243:
	.string	"__SSE2__ 1"
.LASF295:
	.string	"__GLIBC_MINOR__ 16"
.LASF410:
	.string	"__SLONG32_TYPE int"
.LASF137:
	.string	"__UINT_FAST8_MAX__ 255"
.LASF41:
	.string	"__SIZEOF_LONG__ 8"
.LASF36:
	.string	"__ATOMIC_CONSUME 1"
.LASF380:
	.string	"__SIZE_T__ "
.LASF59:
	.string	"__WINT_TYPE__ unsigned int"
.LASF338:
	.string	"__attribute_noinline__ __attribute__ ((__noinline__))"
.LASF83:
	.string	"__INT_FAST32_TYPE__ long int"
.LASF457:
	.string	"_STDIO_USES_IOSTREAM "
.LASF45:
	.string	"__SIZEOF_DOUBLE__ 8"
.LASF557:
	.string	"_IO_SCIENTIFIC 04000"
.LASF29:
	.string	"__GNUC_PATCHLEVEL__ 1"
.LASF432:
	.string	"__BLKCNT64_T_TYPE __SQUAD_TYPE"
.LASF278:
	.string	"__USE_FORTIFY_LEVEL"
.LASF100:
	.string	"__WINT_MIN__ 0U"
.LASF479:
	.string	"_G_HAVE_LONG_DOUBLE_IO 1"
.LASF174:
	.string	"__LDBL_MANT_DIG__ 64"
.LASF589:
	.string	"TMP_MAX 238328"
.LASF10:
	.string	"info"
.LASF594:
	.string	"stdout stdout"
.LASF237:
	.string	"__x86_64 1"
.LASF366:
	.string	"__stub_fchflags "
.LASF323:
	.string	"__bos0(ptr) __builtin_object_size (ptr, 0)"
.LASF455:
	.string	"____FILE_defined 1"
.LASF618:
	.string	"__lldiv_t_defined 1"
.LASF465:
	.string	"_G_off64_t __off64_t"
.LASF186:
	.string	"__LDBL_HAS_INFINITY__ 1"
.LASF492:
	.string	"_G_VTABLE_LABEL_PREFIX \"__vt_\""
.LASF514:
	.string	"_IO_UNIFIED_JUMPTABLES 1"
.LASF14:
	.string	"consomeLinha"
.LASF232:
	.string	"__SIZEOF_WCHAR_T__ 4"
.LASF339:
	.string	"__attribute_deprecated__ __attribute__ ((__deprecated__))"
.LASF622:
	.string	"MB_CUR_MAX (__ctype_get_mb_cur_max ())"
.LASF54:
	.string	"__FLOAT_WORD_ORDER__ __ORDER_LITTLE_ENDIAN__"
.LASF340:
	.string	"__attribute_format_arg__(x) __attribute__ ((__format_arg__ (x)))"
.LASF188:
	.string	"__DEC32_MANT_DIG__ 7"
.LASF271:
	.string	"__USE_FILE_OFFSET64"
.LASF196:
	.string	"__DEC64_MIN_EXP__ (-382)"
.LASF108:
	.string	"__SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)"
.LASF549:
	.string	"_IO_INTERNAL 010"
.LASF392:
	.string	"___int_size_t_h "
.LASF33:
	.string	"__ATOMIC_ACQUIRE 2"
.LASF128:
	.string	"__UINT16_C(c) c"
.LASF443:
	.string	"__SWBLK_T_TYPE __SYSCALL_SLONG_TYPE"
.LASF370:
	.string	"__stub_lchmod "
.LASF377:
	.string	"__need_size_t "
.LASF322:
	.string	"__bos(ptr) __builtin_object_size (ptr, __USE_FORTIFY_LEVEL > 1)"
.LASF275:
	.string	"__USE_ATFILE"
.LASF499:
	.string	"_IO_off_t _G_off_t"
.LASF244:
	.string	"__SSE_MATH__ 1"
.LASF424:
	.string	"__NLINK_T_TYPE __SYSCALL_ULONG_TYPE"
.LASF61:
	.string	"__UINTMAX_TYPE__ long unsigned int"
.LASF214:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1"
.LASF396:
	.string	"__need_size_t"
.LASF320:
	.string	"__unbounded "
.LASF300:
	.string	"__LEAF , __leaf__"
.LASF204:
	.string	"__DEC128_MAX_EXP__ 6145"
.LASF547:
	.string	"_IO_LEFT 02"
.LASF602:
	.string	"_T_WCHAR_ "
.LASF140:
	.string	"__UINT_FAST64_MAX__ 18446744073709551615UL"
.LASF113:
	.string	"__UINT8_MAX__ 255"
.LASF222:
	.string	"__GCC_ATOMIC_WCHAR_T_LOCK_FREE 2"
.LASF574:
	.string	"_IO_PENDING_OUTPUT_COUNT(_fp) ((_fp)->_IO_write_ptr - (_fp)->_IO_write_base)"
.LASF20:
	.string	"_IO_STDIO_H "
.LASF21:
	.string	"__need_mbstate_t "
.LASF99:
	.string	"__WINT_MAX__ 4294967295U"
.LASF136:
	.string	"__INT_FAST64_MAX__ 9223372036854775807L"
.LASF102:
	.string	"__SIZE_MAX__ 18446744073709551615UL"
.LASF152:
	.string	"__FLT_DECIMAL_DIG__ 9"
.LASF325:
	.string	"__warndecl(name,msg) extern void name (void) __attribute__((__warning__ (msg)))"
.LASF582:
	.string	"_IOLBF 1"
.LASF308:
	.string	"__STRING(x) #x"
.LASF453:
	.string	"__FILE_defined 1"
.LASF176:
	.string	"__LDBL_MIN_EXP__ (-16381)"
.LASF556:
	.string	"_IO_SHOWPOS 02000"
.LASF511:
	.string	"__GNUC_VA_LIST "
.LASF409:
	.string	"__UWORD_TYPE unsigned long int"
.LASF40:
	.string	"__SIZEOF_INT__ 4"
.LASF578:
	.string	"_IO_ftrylockfile(_fp) "
.LASF491:
	.string	"_G_USING_THUNKS 1"
.LASF408:
	.string	"__SWORD_TYPE long int"
.LASF5:
	.string	"short int"
.LASF613:
	.string	"_WCHAR_T_DECLARED "
.LASF368:
	.string	"__stub_getmsg "
.LASF197:
	.string	"__DEC64_MAX_EXP__ 385"
.LASF484:
	.string	"_G_LSEEK64 __lseek64"
.LASF290:
	.string	"__STDC_ISO_10646__ 201103L"
.LASF6:
	.string	"long int"
.LASF112:
	.string	"__INT64_MAX__ 9223372036854775807L"
.LASF426:
	.string	"__OFF_T_TYPE __SYSCALL_SLONG_TYPE"
.LASF259:
	.string	"__USE_POSIX2"
.LASF63:
	.string	"__CHAR32_TYPE__ unsigned int"
.LASF399:
	.string	"__need_NULL"
.LASF565:
	.string	"_IO_stdin ((_IO_FILE*)(&_IO_2_1_stdin_))"
.LASF205:
	.string	"__DEC128_MIN__ 1E-6143DL"
.LASF540:
	.string	"_IO_IS_FILEBUF 0x2000"
.LASF569:
	.string	"_IO_getc_unlocked(_fp) (_IO_BE ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end, 0) ? __uflow (_fp) : *(unsigned char *) (_fp)->_IO_read_ptr++)"
.LASF421:
	.string	"__INO_T_TYPE __SYSCALL_ULONG_TYPE"
.LASF467:
	.string	"_G_uid_t __uid_t"
.LASF85:
	.string	"__UINT_FAST8_TYPE__ unsigned char"
.LASF122:
	.string	"__INT32_C(c) c"
.LASF187:
	.string	"__LDBL_HAS_QUIET_NAN__ 1"
.LASF284:
	.string	"__USE_ISOC99 1"
.LASF58:
	.string	"__WCHAR_TYPE__ int"
.LASF95:
	.string	"__LONG_MAX__ 9223372036854775807L"
.LASF11:
	.string	"GNU C 4.7.1 20120721 (prerelease)"
.LASF273:
	.string	"__USE_SVID"
.LASF534:
	.string	"_IO_LINKED 0x80"
.LASF372:
	.string	"__stub_revoke "
.LASF356:
	.string	"__LDBL_REDIR1(name,proto,alias) name proto"
.LASF277:
	.string	"__USE_REENTRANT"
.LASF532:
	.string	"_IO_ERR_SEEN 0x20"
.LASF71:
	.string	"__UINT32_TYPE__ unsigned int"
.LASF375:
	.string	"__stub_sstk "
.LASF267:
	.string	"__USE_XOPEN2K8"
.LASF103:
	.string	"__INTMAX_MAX__ 9223372036854775807L"
.LASF590:
	.string	"FILENAME_MAX 4096"
.LASF262:
	.string	"__USE_XOPEN"
.LASF22:
	.string	"NMAX 20"
.LASF452:
	.string	"__need___FILE "
.LASF480:
	.string	"_G_HAVE_IO_FILE_OPEN 1"
.LASF552:
	.string	"_IO_HEX 0100"
.LASF121:
	.string	"__INT_LEAST32_MAX__ 2147483647"
.LASF42:
	.string	"__SIZEOF_LONG_LONG__ 8"
.LASF69:
	.string	"__UINT8_TYPE__ unsigned char"
.LASF395:
	.string	"__size_t "
.LASF245:
	.string	"__SSE2_MATH__ 1"
.LASF449:
	.string	"__SSIZE_T_TYPE __SWORD_TYPE"
.LASF412:
	.string	"__S64_TYPE long int"
.LASF335:
	.string	"__attribute_pure__ __attribute__ ((__pure__))"
.LASF588:
	.string	"L_tmpnam 20"
.LASF274:
	.string	"__USE_MISC"
.LASF621:
	.string	"EXIT_SUCCESS 0"
.LASF490:
	.string	"_G_VTABLE_LABEL_HAS_LENGTH 1"
.LASF319:
	.string	"__bounded "
.LASF541:
	.string	"_IO_BAD_SEEN 0x4000"
.LASF468:
	.string	"_G_wchar_t wchar_t"
.LASF317:
	.string	"__END_NAMESPACE_C99 "
.LASF55:
	.string	"__SIZEOF_POINTER__ 8"
.LASF507:
	.string	"_IO_va_list _G_va_list"
.LASF442:
	.string	"__DADDR_T_TYPE __S32_TYPE"
.LASF422:
	.string	"__INO64_T_TYPE __UQUAD_TYPE"
.LASF509:
	.string	"__need___va_list "
.LASF608:
	.string	"_WCHAR_T_DEFINED "
.LASF97:
	.string	"__WCHAR_MAX__ 2147483647"
.LASF326:
	.string	"__warnattr(msg) __attribute__((__warning__ (msg)))"
.LASF107:
	.string	"__SIG_ATOMIC_MAX__ 2147483647"
.LASF458:
	.string	"_G_config_h 1"
.LASF228:
	.string	"__GCC_ATOMIC_POINTER_LOCK_FREE 2"
.LASF321:
	.string	"__ptrvalue "
.LASF437:
	.string	"__ID_T_TYPE __U32_TYPE"
.LASF591:
	.string	"FOPEN_MAX"
.LASF16:
	.string	"main"
.LASF427:
	.string	"__OFF64_T_TYPE __SQUAD_TYPE"
.LASF439:
	.string	"__TIME_T_TYPE __SYSCALL_SLONG_TYPE"
.LASF7:
	.string	"sizetype"
.LASF12:
	.string	"selas.c"
.LASF210:
	.string	"__USER_LABEL_PREFIX__ "
.LASF0:
	.string	"long unsigned int"
.LASF462:
	.string	"_G_size_t size_t"
.LASF435:
	.string	"__FSFILCNT_T_TYPE __SYSCALL_ULONG_TYPE"
.LASF221:
	.string	"__GCC_ATOMIC_CHAR32_T_LOCK_FREE 2"
.LASF25:
	.string	"__STDC_VERSION__ 199901L"
.LASF364:
	.string	"__stub_chflags "
.LASF249:
	.string	"__unix 1"
.LASF114:
	.string	"__UINT16_MAX__ 65535"
.LASF528:
	.string	"_IO_UNBUFFERED 2"
.LASF469:
	.string	"_G_wint_t wint_t"
.LASF438:
	.string	"__CLOCK_T_TYPE __SYSCALL_SLONG_TYPE"
.LASF31:
	.string	"__ATOMIC_RELAXED 0"
.LASF26:
	.string	"__STDC_HOSTED__ 1"
.LASF603:
	.string	"_T_WCHAR "
.LASF361:
	.string	"__REDIRECT_LDBL(name,proto,alias) __REDIRECT (name, proto, alias)"
.LASF570:
	.string	"_IO_peekc_unlocked(_fp) (_IO_BE ((_fp)->_IO_read_ptr >= (_fp)->_IO_read_end, 0) && __underflow (_fp) == EOF ? EOF : *(unsigned char *) (_fp)->_IO_read_ptr)"
.LASF305:
	.string	"__P(args) args"
.LASF495:
	.string	"_IO_fpos_t _G_fpos_t"
.LASF406:
	.string	"__SQUAD_TYPE long int"
.LASF266:
	.string	"__USE_XOPEN2KXSI"
.LASF101:
	.string	"__PTRDIFF_MAX__ 9223372036854775807L"
.LASF560:
	.string	"_IO_STDIO 040000"
.LASF478:
	.string	"_G_HAVE_MREMAP 1"
.LASF294:
	.string	"__GLIBC__ 2"
.LASF150:
	.string	"__FLT_MAX_EXP__ 128"
.LASF351:
	.string	"__restrict_arr __restrict"
.LASF35:
	.string	"__ATOMIC_ACQ_REL 4"
.LASF142:
	.string	"__UINTPTR_MAX__ 18446744073709551615UL"
.LASF341:
	.string	"__attribute_format_strfmon__(a,b) __attribute__ ((__format__ (__strfmon__, a, b)))"
.LASF1:
	.string	"unsigned char"
.LASF189:
	.string	"__DEC32_MIN_EXP__ (-94)"
.LASF558:
	.string	"_IO_FIXED 010000"
.LASF68:
	.string	"__INT64_TYPE__ long int"
.LASF413:
	.string	"__U64_TYPE unsigned long int"
.LASF601:
	.string	"_WCHAR_T "
.LASF545:
	.string	"_IO_FLAGS2_USER_WBUF 8"
.LASF474:
	.string	"_G_NEED_STDARG_H 1"
.LASF276:
	.string	"__USE_GNU"
.LASF363:
	.string	"__stub_bdflush "
.LASF301:
	.string	"__LEAF_ATTR __attribute__ ((__leaf__))"
.LASF65:
	.string	"__INT8_TYPE__ signed char"
.LASF77:
	.string	"__UINT_LEAST8_TYPE__ unsigned char"
.LASF620:
	.string	"EXIT_FAILURE 1"
.LASF544:
	.string	"_IO_FLAGS2_NOTCANCEL 2"
.LASF416:
	.string	"__SYSCALL_SLONG_TYPE __SLONGWORD_TYPE"
.LASF606:
	.string	"_BSD_WCHAR_T_ "
.LASF329:
	.string	"__REDIRECT(name,proto,alias) name proto __asm__ (__ASMNAME (#alias))"
.LASF571:
	.string	"_IO_putc_unlocked(_ch,_fp) (_IO_BE ((_fp)->_IO_write_ptr >= (_fp)->_IO_write_end, 0) ? __overflow (_fp, (unsigned char) (_ch)) : (unsigned char) (*(_fp)->_IO_write_ptr++ = (_ch)))"
.LASF155:
	.string	"__FLT_EPSILON__ 1.19209289550781250000e-7F"
.LASF561:
	.string	"_IO_DONT_CLOSE 0100000"
.LASF240:
	.string	"__k8__ 1"
.LASF419:
	.string	"__UID_T_TYPE __U32_TYPE"
.LASF405:
	.string	"__ULONGWORD_TYPE unsigned long int"
.LASF223:
	.string	"__GCC_ATOMIC_SHORT_LOCK_FREE 2"
.LASF585:
	.string	"SEEK_SET 0"
.LASF263:
	.string	"__USE_XOPEN_EXTENDED"
.LASF270:
	.string	"__USE_LARGEFILE64"
.LASF496:
	.string	"_IO_fpos64_t _G_fpos64_t"
.LASF595:
	.string	"stderr stderr"
.LASF172:
	.string	"__DBL_HAS_INFINITY__ 1"
.LASF124:
	.string	"__INT64_C(c) c ## L"
.LASF312:
	.string	"__END_DECLS "
.LASF486:
	.string	"_G_FSTAT64(fd,buf) __fxstat64 (_STAT_VER, fd, buf)"
.LASF268:
	.string	"__USE_XOPEN2K8XSI"
.LASF57:
	.string	"__PTRDIFF_TYPE__ long int"
.LASF576:
	.string	"_IO_flockfile(_fp) "
.LASF82:
	.string	"__INT_FAST16_TYPE__ long int"
.LASF288:
	.string	"__STDC_IEC_559__ 1"
.LASF208:
	.string	"__DEC128_SUBNORMAL_MIN__ 0.000000000000000000000000000000001E-6143DL"
.LASF456:
	.string	"__need___FILE"
.LASF269:
	.string	"__USE_LARGEFILE"
.LASF4:
	.string	"signed char"
.LASF272:
	.string	"__USE_BSD"
.LASF506:
	.string	"_IO_BUFSIZ _G_BUFSIZ"
.LASF165:
	.string	"__DBL_MAX_10_EXP__ 308"
.LASF357:
	.string	"__LDBL_REDIR(name,proto) name proto"
.LASF2:
	.string	"short unsigned int"
.LASF623:
	.string	"__malloc_and_calloc_defined "
.LASF211:
	.string	"__GNUC_STDC_INLINE__ 1"
.LASF242:
	.string	"__SSE__ 1"
.LASF529:
	.string	"_IO_NO_READS 4"
.LASF49:
	.string	"__BIGGEST_ALIGNMENT__ 16"
.LASF394:
	.string	"_SIZET_ "
.LASF367:
	.string	"__stub_fdetach "
.LASF382:
	.string	"_SYS_SIZE_T_H "
.LASF169:
	.string	"__DBL_EPSILON__ ((double)2.22044604925031308085e-16L)"
.LASF60:
	.string	"__INTMAX_TYPE__ long int"
.LASF148:
	.string	"__FLT_MIN_EXP__ (-125)"
.LASF206:
	.string	"__DEC128_MAX__ 9.999999999999999999999999999999999E6144DL"
.LASF209:
	.string	"__REGISTER_PREFIX__ "
.LASF327:
	.string	"__errordecl(name,msg) extern void name (void) __attribute__((__error__ (msg)))"
.LASF418:
	.string	"__DEV_T_TYPE __UQUAD_TYPE"
.LASF213:
	.string	"__STRICT_ANSI__ 1"
.LASF568:
	.string	"_IO_BE(expr,res) __builtin_expect ((expr), res)"
.LASF332:
	.string	"__ASMNAME(cname) __ASMNAME2 (__USER_LABEL_PREFIX__, cname)"
.LASF235:
	.string	"__amd64 1"
.LASF512:
	.string	"_IO_va_list"
.LASF248:
	.string	"__linux__ 1"
.LASF354:
	.string	"__WORDSIZE_TIME64_COMPAT32 1"
.LASF522:
	.string	"_IOS_NOREPLACE 64"
.LASF551:
	.string	"_IO_OCT 040"
.LASF475:
	.string	"_G_va_list __gnuc_va_list"
.LASF239:
	.string	"__k8 1"
.LASF476:
	.string	"_G_HAVE_PRINTF_FP 1"
.LASF88:
	.string	"__UINT_FAST64_TYPE__ long unsigned int"
.LASF446:
	.string	"__TIMER_T_TYPE void *"
.LASF280:
	.string	"__KERNEL_STRICT_NAMES"
.LASF179:
	.string	"__LDBL_MAX_10_EXP__ 4932"
.LASF198:
	.string	"__DEC64_MIN__ 1E-383DD"
.LASF513:
	.string	"_IO_va_list __gnuc_va_list"
.LASF519:
	.string	"_IOS_APPEND 8"
.LASF230:
	.string	"__PRAGMA_REDEFINE_EXTNAME 1"
.LASF64:
	.string	"__SIG_ATOMIC_TYPE__ int"
.LASF543:
	.string	"_IO_FLAGS2_MMAP 1"
.LASF258:
	.string	"__USE_POSIX"
.LASF217:
	.string	"__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1"
.LASF538:
	.string	"_IO_CURRENTLY_PUTTING 0x800"
.LASF355:
	.string	"__SYSCALL_WORDSIZE 64"
.LASF185:
	.string	"__LDBL_HAS_DENORM__ 1"
.LASF430:
	.string	"__RLIM64_T_TYPE __UQUAD_TYPE"
.LASF494:
	.string	"_IO_pos_t _G_fpos_t"
.LASF379:
	.string	"__size_t__ "
.LASF195:
	.string	"__DEC64_MANT_DIG__ 16"
.LASF157:
	.string	"__FLT_HAS_DENORM__ 1"
.LASF360:
	.string	"__LDBL_REDIR_DECL(name) "
.LASF180:
	.string	"__DECIMAL_DIG__ 21"
	.ident	"GCC: (GNU) 4.7.1 20120721 (prerelease)"
	.section	.note.GNU-stack,"",@progbits
