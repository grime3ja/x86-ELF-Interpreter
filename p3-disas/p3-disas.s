	.file	"p3-disas.c"
	.text
	.globl	regs
	.section	.rodata
.LC0:
	.string	"%rax"
.LC1:
	.string	"%rcx"
.LC2:
	.string	"%rdx"
.LC3:
	.string	"%rbx"
.LC4:
	.string	"%rsp"
.LC5:
	.string	"%rbp"
.LC6:
	.string	"%rsi"
.LC7:
	.string	"%rdi"
.LC8:
	.string	"%r8"
.LC9:
	.string	"%r9"
.LC10:
	.string	"%r10"
.LC11:
	.string	"%r11"
.LC12:
	.string	"%r12"
.LC13:
	.string	"%r13"
.LC14:
	.string	"%r14"
	.section	.data.rel.local,"aw"
	.align 32
	.type	regs, @object
	.size	regs, 120
regs:
	.quad	.LC0
	.quad	.LC1
	.quad	.LC2
	.quad	.LC3
	.quad	.LC4
	.quad	.LC5
	.quad	.LC6
	.quad	.LC7
	.quad	.LC8
	.quad	.LC9
	.quad	.LC10
	.quad	.LC11
	.quad	.LC12
	.quad	.LC13
	.quad	.LC14
	.text
	.globl	fetch
	.type	fetch, @function
fetch:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%rdi, -56(%rbp)
	movq	%rsi, -64(%rbp)
	movq	%rdx, -72(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	cmpq	$0, -64(%rbp)
	jne	.L2
	movl	$13, -48(%rbp)
	movq	-56(%rbp), %rcx
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, 16(%rcx)
	movq	%rdx, 24(%rcx)
	jmp	.L42
.L2:
	cmpq	$0, -72(%rbp)
	jne	.L4
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	movq	-56(%rbp), %rcx
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, 16(%rcx)
	movq	%rdx, 24(%rcx)
	jmp	.L42
.L4:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	shrb	$4, %al
	movzbl	%al, %eax
	movl	%eax, -48(%rbp)
	movl	$0, -44(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	movq	%rax, -24(%rbp)
	movl	-48(%rbp), %eax
	cmpl	$12, %eax
	ja	.L5
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L7(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L7(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L7:
	.long	.L19-.L7
	.long	.L18-.L7
	.long	.L17-.L7
	.long	.L16-.L7
	.long	.L15-.L7
	.long	.L14-.L7
	.long	.L13-.L7
	.long	.L12-.L7
	.long	.L11-.L7
	.long	.L10-.L7
	.long	.L9-.L7
	.long	.L8-.L7
	.long	.L6-.L7
	.text
.L19:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	testl	%eax, %eax
	je	.L20
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L20:
	movq	-24(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -24(%rbp)
	jmp	.L21
.L18:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	testl	%eax, %eax
	je	.L22
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L22:
	movq	-24(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -24(%rbp)
	jmp	.L21
.L17:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	movl	%eax, -44(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	shrb	$4, %al
	movzbl	%al, %eax
	movl	%eax, -40(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	movl	%eax, -36(%rbp)
	movq	-24(%rbp), %rax
	addq	$2, %rax
	movq	%rax, -24(%rbp)
	movl	-44(%rbp), %eax
	cmpl	$6, %eax
	jg	.L23
	movl	-40(%rbp), %eax
	cmpl	$14, %eax
	ja	.L23
	movl	-36(%rbp), %eax
	cmpl	$14, %eax
	jbe	.L44
.L23:
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L16:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	shrb	$4, %al
	movzbl	%al, %eax
	movl	%eax, -40(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	movl	%eax, -36(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	2(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	addq	$10, %rax
	movq	%rax, -24(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	testl	%eax, %eax
	jne	.L25
	movl	-40(%rbp), %eax
	cmpl	$15, %eax
	jne	.L25
	movl	-36(%rbp), %eax
	cmpl	$14, %eax
	jbe	.L45
.L25:
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L15:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	shrb	$4, %al
	movzbl	%al, %eax
	movl	%eax, -40(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	movl	%eax, -36(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	2(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	addq	$10, %rax
	movq	%rax, -24(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	testl	%eax, %eax
	jne	.L27
	movl	-40(%rbp), %eax
	cmpl	$14, %eax
	jbe	.L46
.L27:
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L14:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	shrb	$4, %al
	movzbl	%al, %eax
	movl	%eax, -40(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	movl	%eax, -36(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	2(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	addq	$10, %rax
	movq	%rax, -24(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	testl	%eax, %eax
	jne	.L29
	movl	-40(%rbp), %eax
	cmpl	$14, %eax
	jbe	.L47
.L29:
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L13:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	movl	%eax, -44(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	shrb	$4, %al
	movzbl	%al, %eax
	movl	%eax, -40(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	movl	%eax, -36(%rbp)
	movq	-24(%rbp), %rax
	addq	$2, %rax
	movq	%rax, -24(%rbp)
	movl	-44(%rbp), %eax
	cmpl	$3, %eax
	jg	.L31
	movl	-40(%rbp), %eax
	cmpl	$14, %eax
	ja	.L31
	movl	-36(%rbp), %eax
	cmpl	$14, %eax
	jbe	.L48
.L31:
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L12:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	movl	%eax, -44(%rbp)
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	addq	$9, %rax
	movq	%rax, -24(%rbp)
	movl	-44(%rbp), %eax
	cmpl	$6, %eax
	jle	.L49
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L11:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	testl	%eax, %eax
	je	.L34
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L34:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rax
	addq	$9, %rax
	movq	%rax, -24(%rbp)
	jmp	.L21
.L10:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	testl	%eax, %eax
	je	.L35
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L35:
	movq	-24(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -24(%rbp)
	jmp	.L21
.L9:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	testl	%eax, %eax
	jne	.L36
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	shrb	$4, %al
	cmpb	$14, %al
	ja	.L36
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	cmpl	$15, %eax
	je	.L37
.L36:
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L37:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	shrb	$4, %al
	movzbl	%al, %eax
	movl	%eax, -40(%rbp)
	movl	$15, -36(%rbp)
	movq	-24(%rbp), %rax
	addq	$2, %rax
	movq	%rax, -24(%rbp)
	jmp	.L21
.L8:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	testl	%eax, %eax
	jne	.L38
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	shrb	$4, %al
	cmpb	$14, %al
	ja	.L38
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	cmpl	$15, %eax
	je	.L39
.L38:
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L39:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	shrb	$4, %al
	movzbl	%al, %eax
	movl	%eax, -40(%rbp)
	movl	$15, -36(%rbp)
	movq	-24(%rbp), %rax
	addq	$2, %rax
	movq	%rax, -24(%rbp)
	jmp	.L21
.L6:
	movq	-64(%rbp), %rax
	movq	128(%rax), %rdx
	movq	-72(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	andl	$15, %eax
	movl	%eax, -44(%rbp)
	movq	-24(%rbp), %rax
	addq	$1, %rax
	movq	%rax, -24(%rbp)
	movl	-44(%rbp), %eax
	cmpl	$5, %eax
	jle	.L50
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L5:
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$4, 136(%rax)
	jmp	.L21
.L44:
	nop
	jmp	.L21
.L45:
	nop
	jmp	.L21
.L46:
	nop
	jmp	.L21
.L47:
	nop
	jmp	.L21
.L48:
	nop
	jmp	.L21
.L49:
	nop
	jmp	.L21
.L50:
	nop
.L21:
	movq	-24(%rbp), %rax
	cmpq	$4096, %rax
	jbe	.L41
	movl	$13, -48(%rbp)
	movq	-64(%rbp), %rax
	movl	$3, 136(%rax)
.L41:
	movq	-56(%rbp), %rcx
	movq	-48(%rbp), %rax
	movq	-40(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-32(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rax, 16(%rcx)
	movq	%rdx, 24(%rcx)
.L42:
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L43
	call	__stack_chk_fail@PLT
.L43:
	movq	-56(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	fetch, .-fetch
	.section	.rodata
.LC15:
	.string	"0x%lx"
.LC16:
	.string	"0x%lx(%s)"
.LC17:
	.string	"%s"
.LC18:
	.string	", "
	.text
	.globl	disassemble
	.type	disassemble, @function
disassemble:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movq	%rax, %rdi
	call	disassemble_icode
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jg	.L52
	movl	$10, %edi
	call	putchar@PLT
	jmp	.L51
.L52:
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %edi
	call	disassemble_register
	movq	%rax, -16(%rbp)
	movq	-40(%rbp), %rax
	movl	12(%rax), %eax
	movl	%eax, %edi
	call	disassemble_register
	movq	%rax, -8(%rbp)
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	$15, %eax
	je	.L54
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$5, %eax
	jne	.L55
	movq	-40(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	$15, %eax
	jne	.L56
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L54
.L56:
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, %rsi
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L54
.L55:
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L54:
	cmpl	$1, -20(%rbp)
	jle	.L57
	leaq	.LC18(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$5, %eax
	jne	.L58
	movq	-16(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L57
.L58:
	movq	-40(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$4, %eax
	jne	.L59
	movq	-40(%rbp), %rax
	movl	12(%rax), %eax
	cmpl	$15, %eax
	jne	.L60
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L57
.L60:
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, %rsi
	leaq	.LC16(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L57
.L59:
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC17(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L57:
	movl	$10, %edi
	call	putchar@PLT
.L51:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	disassemble, .-disassemble
	.section	.rodata
.LC19:
	.string	" "
	.align 8
.LC20:
	.string	"  0x%03x: %30s| .pos 0x%03x code\n"
.LC21:
	.string	"  0x%03x:%31s| _start:\n"
.LC22:
	.string	"Invalid opcode: 0x%2x\n"
.LC23:
	.string	"  0x%03lx: "
.LC24:
	.string	"%x%x "
.LC25:
	.string	"%02x "
.LC26:
	.string	"%3s"
.LC27:
	.string	"%24s"
.LC28:
	.string	"%27s"
.LC29:
	.string	"%30s"
.LC30:
	.string	"|   "
	.text
	.globl	disassemble_code
	.type	disassemble_code, @function
disassemble_code:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$272, %rsp
	movq	%rdi, -216(%rbp)
	movq	%rsi, -224(%rbp)
	movq	%rdx, -232(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-224(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %eax
	movq	%rax, -32(%rbp)
	movq	-224(%rbp), %rax
	movl	8(%rax), %edx
	movq	-224(%rbp), %rax
	movl	8(%rax), %eax
	movl	%edx, %ecx
	leaq	.LC19(%rip), %rdx
	movl	%eax, %esi
	leaq	.LC20(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L62
.L76:
	movq	-32(%rbp), %rdx
	movq	-232(%rbp), %rax
	movzwl	2(%rax), %eax
	movzwl	%ax, %eax
	cmpq	%rax, %rdx
	jne	.L63
	movq	-232(%rbp), %rax
	movzwl	2(%rax), %eax
	movzwl	%ax, %eax
	leaq	.LC19(%rip), %rdx
	movl	%eax, %esi
	leaq	.LC21(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L63:
	leaq	-272(%rbp), %rax
	movq	-216(%rbp), %rdx
	leaq	-160(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	fetch
	movq	-272(%rbp), %rax
	movq	-264(%rbp), %rdx
	movq	%rax, -192(%rbp)
	movq	%rdx, -184(%rbp)
	movq	-256(%rbp), %rax
	movq	-248(%rbp), %rdx
	movq	%rax, -176(%rbp)
	movq	%rdx, -168(%rbp)
	movl	-192(%rbp), %eax
	cmpl	$13, %eax
	jne	.L64
	movq	-32(%rbp), %rdx
	movq	-216(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC22(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L65
.L64:
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC23(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-188(%rbp), %edx
	movl	-192(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC24(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-168(%rbp), %rax
	movq	-32(%rbp), %rdx
	subq	%rdx, %rax
	cmpq	$10, %rax
	je	.L66
	cmpq	$10, %rax
	ja	.L67
	cmpq	$9, %rax
	je	.L68
	cmpq	$9, %rax
	ja	.L67
	cmpq	$1, %rax
	je	.L69
	cmpq	$2, %rax
	je	.L70
	jmp	.L67
.L66:
	movl	-180(%rbp), %edx
	movl	-184(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC24(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	addl	$2, %eax
	movl	%eax, -200(%rbp)
	jmp	.L71
.L72:
	movl	-200(%rbp), %eax
	movslq	%eax, %rdx
	movq	-216(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC25(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -200(%rbp)
.L71:
	movl	-200(%rbp), %eax
	movslq	%eax, %rdx
	movq	-32(%rbp), %rax
	addq	$10, %rax
	cmpq	%rax, %rdx
	jb	.L72
	jmp	.L73
.L68:
	movq	-32(%rbp), %rax
	addl	$1, %eax
	movl	%eax, -196(%rbp)
	jmp	.L74
.L75:
	movl	-196(%rbp), %eax
	movslq	%eax, %rdx
	movq	-216(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC25(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -196(%rbp)
.L74:
	movl	-196(%rbp), %eax
	movslq	%eax, %rdx
	movq	-32(%rbp), %rax
	addq	$9, %rax
	cmpq	%rax, %rdx
	jb	.L75
	leaq	.LC19(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC26(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L73
.L70:
	movl	-180(%rbp), %edx
	movl	-184(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC24(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC19(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC27(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L73
.L69:
	leaq	.LC19(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC28(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L73
.L67:
	leaq	.LC19(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC29(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L73:
	leaq	.LC30(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-192(%rbp), %rax
	movq	%rax, %rdi
	call	disassemble
	movq	-168(%rbp), %rax
	movq	%rax, -32(%rbp)
.L62:
	movq	-32(%rbp), %rdx
	movq	-224(%rbp), %rax
	movl	8(%rax), %ecx
	movq	-224(%rbp), %rax
	movl	4(%rax), %eax
	addl	%ecx, %eax
	movl	%eax, %eax
	cmpq	%rax, %rdx
	jb	.L76
.L65:
	movl	$10, %edi
	call	putchar@PLT
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L77
	call	__stack_chk_fail@PLT
.L77:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	disassemble_code, .-disassemble_code
	.section	.rodata
.LC31:
	.string	"halt"
.LC32:
	.string	"nop"
.LC33:
	.string	"rrmovq "
.LC34:
	.string	"cmovle "
.LC35:
	.string	"cmovl "
.LC36:
	.string	"cmove "
.LC37:
	.string	"cmovne "
.LC38:
	.string	"cmovge "
.LC39:
	.string	"cmovg "
.LC40:
	.string	"badcmov "
.LC41:
	.string	"irmovq 0x%lx"
.LC42:
	.string	"rmmovq "
.LC43:
	.string	"mrmovq "
.LC44:
	.string	"addq "
.LC45:
	.string	"subq "
.LC46:
	.string	"andq "
.LC47:
	.string	"xorq "
.LC48:
	.string	"badopq "
.LC49:
	.string	"jmp "
.LC50:
	.string	"jle "
.LC51:
	.string	"jl "
.LC52:
	.string	"je "
.LC53:
	.string	"jne "
.LC54:
	.string	"jge "
.LC55:
	.string	"jg "
.LC56:
	.string	"badjump"
.LC57:
	.string	"call 0x%lx"
.LC58:
	.string	"ret"
.LC59:
	.string	"pushq "
.LC60:
	.string	"popq "
.LC61:
	.string	"iotrap %d"
	.text
	.globl	disassemble_icode
	.type	disassemble_icode, @function
disassemble_icode:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	movq	-24(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$13, %eax
	ja	.L79
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L81(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L81(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L81:
	.long	.L94-.L81
	.long	.L93-.L81
	.long	.L92-.L81
	.long	.L91-.L81
	.long	.L90-.L81
	.long	.L89-.L81
	.long	.L88-.L81
	.long	.L87-.L81
	.long	.L86-.L81
	.long	.L85-.L81
	.long	.L84-.L81
	.long	.L83-.L81
	.long	.L82-.L81
	.long	.L123-.L81
	.text
.L94:
	leaq	.LC31(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L79
.L93:
	leaq	.LC32(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L79
.L92:
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	$7, %eax
	ja	.L95
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L97(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L97(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L97:
	.long	.L104-.L97
	.long	.L103-.L97
	.long	.L102-.L97
	.long	.L101-.L97
	.long	.L100-.L97
	.long	.L99-.L97
	.long	.L98-.L97
	.long	.L96-.L97
	.text
.L104:
	leaq	.LC33(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L95
.L103:
	leaq	.LC34(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L95
.L102:
	leaq	.LC35(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L95
.L101:
	leaq	.LC36(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L95
.L100:
	leaq	.LC37(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L95
.L99:
	leaq	.LC38(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L95
.L98:
	leaq	.LC39(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L95
.L96:
	leaq	.LC40(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L95:
	movl	$2, -4(%rbp)
	jmp	.L79
.L91:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC41(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$2, -4(%rbp)
	jmp	.L79
.L90:
	leaq	.LC42(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$2, -4(%rbp)
	jmp	.L79
.L89:
	leaq	.LC43(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$2, -4(%rbp)
	jmp	.L79
.L88:
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	$4, %eax
	ja	.L105
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L107(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L107(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L107:
	.long	.L111-.L107
	.long	.L110-.L107
	.long	.L109-.L107
	.long	.L108-.L107
	.long	.L106-.L107
	.text
.L111:
	leaq	.LC44(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L105
.L110:
	leaq	.LC45(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L105
.L109:
	leaq	.LC46(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L105
.L108:
	leaq	.LC47(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L105
.L106:
	leaq	.LC48(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L105:
	movl	$2, -4(%rbp)
	jmp	.L79
.L87:
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	cmpl	$7, %eax
	ja	.L112
	movl	%eax, %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L114(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L114(%rip), %rdx
	addq	%rdx, %rax
	notrack jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L114:
	.long	.L121-.L114
	.long	.L120-.L114
	.long	.L119-.L114
	.long	.L118-.L114
	.long	.L117-.L114
	.long	.L116-.L114
	.long	.L115-.L114
	.long	.L113-.L114
	.text
.L121:
	leaq	.LC49(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L112
.L120:
	leaq	.LC50(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L112
.L119:
	leaq	.LC51(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L112
.L118:
	leaq	.LC52(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L112
.L117:
	leaq	.LC53(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L112
.L116:
	leaq	.LC54(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L112
.L115:
	leaq	.LC55(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L112
.L113:
	leaq	.LC56(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
.L112:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC15(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L79
.L86:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rsi
	leaq	.LC57(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L79
.L85:
	leaq	.LC58(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L79
.L84:
	leaq	.LC59(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, -4(%rbp)
	jmp	.L79
.L83:
	leaq	.LC60(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, -4(%rbp)
	jmp	.L79
.L82:
	movq	-24(%rbp), %rax
	movl	4(%rax), %eax
	movl	%eax, %esi
	leaq	.LC61(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L79
.L123:
	nop
.L79:
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	disassemble_icode, .-disassemble_icode
	.globl	disassemble_register
	.type	disassemble_register, @function
disassemble_register:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -4(%rbp)
	cmpl	$14, -4(%rbp)
	jbe	.L125
	movl	$0, %eax
	jmp	.L126
.L125:
	movl	-4(%rbp), %eax
	leaq	0(,%rax,8), %rdx
	leaq	regs(%rip), %rax
	movq	(%rdx,%rax), %rax
.L126:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	disassemble_register, .-disassemble_register
	.section	.rodata
	.align 8
.LC62:
	.string	"  0x%03x: %30s| .pos 0x%03x data\n"
.LC63:
	.string	"%6s|   "
.LC64:
	.string	".quad 0x%lx"
	.text
	.globl	disassemble_data
	.type	disassemble_data, @function
disassemble_data:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$192, %rsp
	movq	%rdi, -184(%rbp)
	movq	%rsi, -192(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-192(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %eax
	movq	%rax, -32(%rbp)
	movq	-192(%rbp), %rax
	movl	8(%rax), %edx
	movq	-192(%rbp), %rax
	movl	8(%rax), %eax
	movl	%edx, %ecx
	leaq	.LC19(%rip), %rdx
	movl	%eax, %esi
	leaq	.LC62(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L128
.L131:
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC23(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	movl	%eax, -172(%rbp)
	jmp	.L129
.L130:
	movl	-172(%rbp), %eax
	movslq	%eax, %rdx
	movq	-184(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC25(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -172(%rbp)
.L129:
	movl	-172(%rbp), %eax
	movslq	%eax, %rdx
	movq	-32(%rbp), %rax
	addq	$8, %rax
	cmpq	%rax, %rdx
	jb	.L130
	leaq	.LC19(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC63(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rdx
	movq	-184(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movq	%rax, -168(%rbp)
	movq	-168(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC64(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	%rax, -32(%rbp)
	movl	$10, %edi
	call	putchar@PLT
.L128:
	movq	-32(%rbp), %rdx
	movq	-192(%rbp), %rax
	movl	8(%rax), %ecx
	movq	-192(%rbp), %rax
	movl	4(%rax), %eax
	addl	%ecx, %eax
	movl	%eax, %eax
	cmpq	%rax, %rdx
	jb	.L131
	movl	$10, %edi
	call	putchar@PLT
	nop
	movq	-8(%rbp), %rax
	subq	%fs:40, %rax
	je	.L132
	call	__stack_chk_fail@PLT
.L132:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	disassemble_data, .-disassemble_data
	.section	.rodata
	.align 8
.LC65:
	.string	"  0x%03x: %30s| .pos 0x%03x rodata\n"
.LC66:
	.string	"\""
	.text
	.globl	disassemble_rodata
	.type	disassemble_rodata, @function
disassemble_rodata:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$200, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -200(%rbp)
	movq	%rsi, -208(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-208(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %eax
	movq	%rax, -48(%rbp)
	movl	$0, -184(%rbp)
	movq	-48(%rbp), %rax
	movl	%eax, -180(%rbp)
	movq	-208(%rbp), %rax
	movl	8(%rax), %edx
	movq	-208(%rbp), %rax
	movl	8(%rax), %eax
	movl	%edx, %ecx
	leaq	.LC19(%rip), %rdx
	movl	%eax, %esi
	leaq	.LC65(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L134
.L137:
	movl	$0, -184(%rbp)
	jmp	.L135
.L136:
	addl	$1, -184(%rbp)
.L135:
	movl	-180(%rbp), %eax
	leal	1(%rax), %edx
	movl	%edx, -180(%rbp)
	movslq	%eax, %rdx
	movq	-200(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L136
	movl	-180(%rbp), %edx
	movl	-184(%rbp), %esi
	movq	-200(%rbp), %rdi
	subq	$144, %rsp
	movq	%rsp, %rax
	movq	-176(%rbp), %rcx
	movq	-168(%rbp), %rbx
	movq	%rcx, (%rax)
	movq	%rbx, 8(%rax)
	movq	-160(%rbp), %rcx
	movq	-152(%rbp), %rbx
	movq	%rcx, 16(%rax)
	movq	%rbx, 24(%rax)
	movq	-144(%rbp), %rcx
	movq	-136(%rbp), %rbx
	movq	%rcx, 32(%rax)
	movq	%rbx, 40(%rax)
	movq	-128(%rbp), %rcx
	movq	-120(%rbp), %rbx
	movq	%rcx, 48(%rax)
	movq	%rbx, 56(%rax)
	movq	-112(%rbp), %rcx
	movq	-104(%rbp), %rbx
	movq	%rcx, 64(%rax)
	movq	%rbx, 72(%rax)
	movq	-96(%rbp), %rcx
	movq	-88(%rbp), %rbx
	movq	%rcx, 80(%rax)
	movq	%rbx, 88(%rax)
	movq	-80(%rbp), %rcx
	movq	-72(%rbp), %rbx
	movq	%rcx, 96(%rax)
	movq	%rbx, 104(%rax)
	movq	-64(%rbp), %rcx
	movq	-56(%rbp), %rbx
	movq	%rcx, 112(%rax)
	movq	%rbx, 120(%rax)
	movq	-48(%rbp), %rcx
	movq	-40(%rbp), %rbx
	movq	%rcx, 128(%rax)
	movq	%rbx, 136(%rax)
	call	print_rodata
	addq	$144, %rsp
	leaq	.LC66(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	-180(%rbp), %edx
	movl	-184(%rbp), %esi
	movq	-200(%rbp), %rdi
	subq	$144, %rsp
	movq	%rsp, %rax
	movq	-176(%rbp), %rcx
	movq	-168(%rbp), %rbx
	movq	%rcx, (%rax)
	movq	%rbx, 8(%rax)
	movq	-160(%rbp), %rcx
	movq	-152(%rbp), %rbx
	movq	%rcx, 16(%rax)
	movq	%rbx, 24(%rax)
	movq	-144(%rbp), %rcx
	movq	-136(%rbp), %rbx
	movq	%rcx, 32(%rax)
	movq	%rbx, 40(%rax)
	movq	-128(%rbp), %rcx
	movq	-120(%rbp), %rbx
	movq	%rcx, 48(%rax)
	movq	%rbx, 56(%rax)
	movq	-112(%rbp), %rcx
	movq	-104(%rbp), %rbx
	movq	%rcx, 64(%rax)
	movq	%rbx, 72(%rax)
	movq	-96(%rbp), %rcx
	movq	-88(%rbp), %rbx
	movq	%rcx, 80(%rax)
	movq	%rbx, 88(%rax)
	movq	-80(%rbp), %rcx
	movq	-72(%rbp), %rbx
	movq	%rcx, 96(%rax)
	movq	%rbx, 104(%rax)
	movq	-64(%rbp), %rcx
	movq	-56(%rbp), %rbx
	movq	%rcx, 112(%rax)
	movq	%rbx, 120(%rax)
	movq	-48(%rbp), %rcx
	movq	-40(%rbp), %rbx
	movq	%rcx, 128(%rax)
	movq	%rbx, 136(%rax)
	call	print_remaining_lines
	addq	$144, %rsp
	movl	-180(%rbp), %eax
	cltq
	movq	%rax, -48(%rbp)
.L134:
	movq	-48(%rbp), %rdx
	movq	-208(%rbp), %rax
	movl	8(%rax), %ecx
	movq	-208(%rbp), %rax
	movl	4(%rax), %eax
	addl	%ecx, %eax
	movl	%eax, %eax
	cmpq	%rax, %rdx
	jb	.L137
	movl	$10, %edi
	call	putchar@PLT
	nop
	movq	-24(%rbp), %rax
	subq	%fs:40, %rax
	je	.L138
	call	__stack_chk_fail@PLT
.L138:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	disassemble_rodata, .-disassemble_rodata
	.section	.rodata
.LC67:
	.string	"   "
.LC68:
	.string	"|   .string \""
	.text
	.globl	print_rodata
	.type	print_rodata, @function
print_rodata:
.LFB13:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movq	144(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC23(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	144(%rbp), %rax
	movl	%eax, -12(%rbp)
	jmp	.L140
.L142:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC25(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -12(%rbp)
.L140:
	movl	-12(%rbp), %eax
	movslq	%eax, %rdx
	movq	144(%rbp), %rax
	addq	$10, %rax
	cmpq	%rax, %rdx
	jnb	.L141
	movl	-12(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L142
.L141:
	movl	-28(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	jmp	.L143
.L144:
	leaq	.LC67(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -8(%rbp)
.L143:
	cmpl	$9, -8(%rbp)
	jle	.L144
	leaq	.LC68(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	144(%rbp), %rax
	movl	%eax, -4(%rbp)
	jmp	.L145
.L146:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %edi
	call	putchar@PLT
	addl	$1, -4(%rbp)
.L145:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	144(%rbp), %rcx
	movl	-28(%rbp), %eax
	cltq
	addq	%rcx, %rax
	cmpq	%rax, %rdx
	jb	.L146
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	print_rodata, .-print_rodata
	.section	.rodata
.LC69:
	.string	"| "
.LC70:
	.string	"  0x%03x: "
	.text
	.globl	print_remaining_lines
	.type	print_remaining_lines, @function
print_remaining_lines:
.LFB14:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	cmpl	$9, -28(%rbp)
	jle	.L148
	movq	144(%rbp), %rax
	addq	$10, %rax
	movq	%rax, %rsi
	leaq	.LC23(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -28(%rbp)
.L148:
	movq	144(%rbp), %rax
	addl	$10, %eax
	movl	%eax, -8(%rbp)
	movq	144(%rbp), %rax
	addl	$10, %eax
	movl	%eax, -4(%rbp)
	jmp	.L149
.L154:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC25(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -28(%rbp)
	cmpl	$10, -28(%rbp)
	jne	.L150
	leaq	.LC69(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	addl	$10, -8(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC70(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -28(%rbp)
.L150:
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L151
	jmp	.L152
.L153:
	leaq	.LC67(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -28(%rbp)
.L152:
	cmpl	$9, -28(%rbp)
	jle	.L153
	leaq	.LC69(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L151:
	addl	$1, -4(%rbp)
.L149:
	movl	-4(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jl	.L154
	nop
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	print_remaining_lines, .-print_remaining_lines
	.ident	"GCC: (Ubuntu 13.2.0-23ubuntu4) 13.2.0"
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
