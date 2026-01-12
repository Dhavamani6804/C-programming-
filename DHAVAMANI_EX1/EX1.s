	.file	"EX1.c"
	.text
	.section .rdata,"dr"
.LC0:
	.ascii "Enter an integer value: \0"
.LC1:
	.ascii "%d\0"
.LC2:
	.ascii "Enter a float value: \0"
.LC3:
	.ascii "%f\0"
.LC4:
	.ascii "\12--- Variable Details ---\0"
.LC5:
	.ascii "Integer value: %d\12\0"
.LC6:
	.ascii "Float value: %.2f\12\0"
	.align 8
.LC7:
	.ascii "Size of integer variable: %zu bytes\12\0"
	.align 8
.LC8:
	.ascii "Size of float variable: %zu bytes\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-4(%rbp), %rax
	leaq	.LC1(%rip), %rcx
	movq	%rax, %rdx
	call	scanf
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-8(%rbp), %rax
	leaq	.LC3(%rip), %rcx
	movq	%rax, %rdx
	call	scanf
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	puts
	movl	-4(%rbp), %eax
	leaq	.LC5(%rip), %rcx
	movl	%eax, %edx
	call	printf
	movss	-8(%rbp), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movapd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	movq	%xmm1, %rdx
	leaq	.LC6(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	printf
	leaq	.LC7(%rip), %rax
	movl	$4, %edx
	movq	%rax, %rcx
	call	printf
	leaq	.LC8(%rip), %rax
	movl	$4, %edx
	movq	%rax, %rcx
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev8, Built by MSYS2 project) 15.2.0"
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
