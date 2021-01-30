	.file	"eff.cpp"
	.text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1577:
	.cfi_startproc
	movl	%esi, %eax
	ret
	.cfi_endproc
.LFE1577:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.text._ZNSt6vectorI5QuerySaIS0_EED2Ev,"axG",@progbits,_ZNSt6vectorI5QuerySaIS0_EED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorI5QuerySaIS0_EED2Ev
	.type	_ZNSt6vectorI5QuerySaIS0_EED2Ev, @function
_ZNSt6vectorI5QuerySaIS0_EED2Ev:
.LFB10068:
	.cfi_startproc
	movq	(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L5
	jmp	_ZdlPv@PLT
	.p2align 4
.L5:
	rep ret
	.cfi_endproc
.LFE10068:
	.size	_ZNSt6vectorI5QuerySaIS0_EED2Ev, .-_ZNSt6vectorI5QuerySaIS0_EED2Ev
	.weak	_ZNSt6vectorI5QuerySaIS0_EED1Ev
	.set	_ZNSt6vectorI5QuerySaIS0_EED1Ev,_ZNSt6vectorI5QuerySaIS0_EED2Ev
	.text
	.p2align 4,,15
	.type	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElS2_NS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_T0_SD_T1_T2_.isra.35, @function
_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElS2_NS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_T0_SD_T1_T2_.isra.35:
.LFB10117:
	.cfi_startproc
	leaq	-1(%rdx), %rax
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rax, %r10
	shrq	$63, %r10
	addq	%rax, %r10
	sarq	%r10
	cmpq	%r10, %rsi
	jge	.L7
	movq	%rsi, %r8
	jmp	.L8
	.p2align 4
.L19:
	vmovdqu	(%r9), %xmm0
	cmpq	%r11, %r10
	vmovups	%xmm0, (%r8)
	vmovdqu	16(%r9), %xmm0
	vmovups	%xmm0, 16(%r8)
	jle	.L16
	movq	%r11, %rcx
.L11:
	movq	%rcx, %r8
.L8:
	leaq	1(%r8), %rax
	salq	$5, %r8
	addq	%rdi, %r8
	leaq	(%rax,%rax), %rcx
	salq	$6, %rax
	addq	%rdi, %rax
	leaq	-1(%rcx), %r11
	movq	24(%rax), %rbx
	movq	%r11, %r9
	salq	$5, %r9
	addq	%rdi, %r9
	cmpq	%rbx, 24(%r9)
	jg	.L19
	vmovdqu	(%rax), %xmm0
	cmpq	%rcx, %r10
	vmovups	%xmm0, (%r8)
	vmovdqu	16(%rax), %xmm0
	vmovups	%xmm0, 16(%r8)
	jg	.L11
.L10:
	testb	$1, %dl
	jne	.L12
	subq	$2, %rdx
	movq	%rdx, %r8
	shrq	$63, %r8
	addq	%r8, %rdx
	sarq	%rdx
	cmpq	%rcx, %rdx
	je	.L20
.L12:
	leaq	-1(%rcx), %rdx
	movq	24(%rsp), %rbp
	movq	32(%rsp), %rbx
	movq	40(%rsp), %r11
	movq	48(%rsp), %r10
	movq	%rdx, %r9
	shrq	$63, %r9
	addq	%rdx, %r9
	sarq	%r9
	cmpq	%rsi, %rcx
	jle	.L13
	movq	%r9, %r8
	salq	$5, %r8
	addq	%rdi, %r8
	cmpq	24(%r8), %r10
	jg	.L14
	jmp	.L13
	.p2align 4
.L15:
	movq	%rdx, %r8
	movq	%r9, %rcx
	movq	%rdx, %r9
	salq	$5, %r8
	addq	%rdi, %r8
	cmpq	24(%r8), %r10
	jle	.L13
.L14:
	vmovdqu	(%r8), %xmm0
	leaq	-1(%r9), %rax
	salq	$5, %rcx
	addq	%rdi, %rcx
	movq	%rax, %rdx
	vmovups	%xmm0, (%rcx)
	shrq	$63, %rdx
	addq	%rax, %rdx
	movq	%r9, %rax
	salq	$5, %rax
	sarq	%rdx
	vmovdqu	16(%r8), %xmm0
	addq	%rdi, %rax
	cmpq	%r9, %rsi
	vmovups	%xmm0, 16(%rcx)
	jl	.L15
.L13:
	movq	%rbp, (%rax)
	movq	%rbx, 8(%rax)
	movq	%r11, 16(%rax)
	movq	%r10, 24(%rax)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L20:
	.cfi_restore_state
	leaq	1(%rcx,%rcx), %rcx
	movq	%rcx, %rdx
	salq	$5, %rdx
	addq	%rdi, %rdx
	vmovdqu	(%rdx), %xmm0
	vmovups	%xmm0, (%rax)
	vmovdqu	16(%rdx), %xmm0
	vmovups	%xmm0, 16(%rax)
	movq	%rdx, %rax
	jmp	.L12
	.p2align 4
.L16:
	movq	%r9, %rax
	movq	%r11, %rcx
	jmp	.L10
	.p2align 4
.L7:
	movq	%rsi, %rax
	movq	%rsi, %rcx
	salq	$5, %rax
	addq	%rdi, %rax
	jmp	.L10
	.cfi_endproc
.LFE10117:
	.size	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElS2_NS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_T0_SD_T1_T2_.isra.35, .-_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElS2_NS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_T0_SD_T1_T2_.isra.35
	.p2align 4,,15
	.type	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEENS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_.isra.85, @function
_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEENS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_.isra.85:
.LFB10167:
	.cfi_startproc
	cmpq	%rsi, %rdi
	je	.L33
	leaq	32(%rdi), %r8
	cmpq	%r8, %rsi
	je	.L33
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rsi, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbp
	movq	%r8, %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	jmp	.L28
	.p2align 4
.L37:
	cmpq	%rbx, %rbp
	je	.L24
	movq	%r8, %rdi
	subq	%rbp, %rdx
	movq	%rbp, %rsi
	movq	%rcx, 8(%rsp)
	movq	%r8, (%rsp)
	call	memmove@PLT
	movq	8(%rsp), %rcx
	movq	(%rsp), %r8
.L24:
	addq	$32, %rbx
	movq	%rcx, 0(%rbp)
	movq	%r15, 8(%rbp)
	cmpq	%r13, %rbx
	movq	%r14, 16(%rbp)
	movq	%r12, 24(%rbp)
	je	.L36
.L28:
	movq	24(%rbx), %r12
	cmpq	24(%rbp), %r12
	movq	%rbx, %rdx
	movq	(%rbx), %rcx
	movq	8(%rbx), %r15
	movq	16(%rbx), %r14
	jl	.L37
	cmpq	-8(%rbx), %r12
	jge	.L26
	leaq	-32(%rbx), %rax
	.p2align 4
.L27:
	vmovdqu	(%rax), %xmm0
	movq	%rax, %rdx
	subq	$32, %rax
	vmovups	%xmm0, 64(%rax)
	vmovdqu	48(%rax), %xmm0
	vmovups	%xmm0, 80(%rax)
	cmpq	24(%rax), %r12
	jl	.L27
.L26:
	addq	$32, %rbx
	movq	%rcx, (%rdx)
	movq	%r15, 8(%rdx)
	cmpq	%r13, %rbx
	movq	%r14, 16(%rdx)
	movq	%r12, 24(%rdx)
	jne	.L28
.L36:
	addq	$24, %rsp
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L33:
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	.cfi_restore 13
	.cfi_restore 14
	.cfi_restore 15
	rep ret
	.cfi_endproc
.LFE10167:
	.size	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEENS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_.isra.85, .-_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEENS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_.isra.85
	.p2align 4,,15
	.type	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElNS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_T1_, @function
_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElNS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_T1_:
.LFB9479:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rdx, %r14
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	movq	%rsi, %rdx
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	%rdi, %rdx
	subq	$40, %rsp
	.cfi_def_cfa_offset 96
	cmpq	$512, %rdx
	movzbl	96(%rsp), %ebp
	jle	.L65
	testq	%r14, %r14
	movq	%rdi, %r13
	movq	%rsi, %r15
	je	.L40
	leaq	32(%rdi), %r12
	movq	%rsi, %rbx
.L42:
	subq	%r13, %rbx
	movq	56(%r13), %rdi
	subq	$1, %r14
	sarq	$5, %rbx
	movq	-8(%rsi), %r8
	movq	0(%r13), %r11
	movq	%rbx, %rdx
	movq	8(%r13), %r10
	movq	16(%r13), %r9
	shrq	$63, %rdx
	movq	24(%r13), %rax
	addq	%rbx, %rdx
	sarq	%rdx
	salq	$5, %rdx
	addq	%r13, %rdx
	movq	24(%rdx), %rcx
	cmpq	%rcx, %rdi
	jge	.L47
	cmpq	%r8, %rcx
	jl	.L52
	cmpq	%r8, %rdi
	jl	.L67
.L68:
	vmovdqu	32(%r13), %xmm0
	movq	%r11, 32(%r13)
	movq	%r10, 40(%r13)
	vmovups	%xmm0, 0(%r13)
	vmovdqu	48(%r13), %xmm0
	movq	%r9, 48(%r13)
	movq	%rax, 56(%r13)
	vmovups	%xmm0, 16(%r13)
	movq	-8(%rsi), %rax
.L49:
	movq	%r12, %rbx
	movq	%rsi, %rdx
	movq	24(%r13), %rcx
	.p2align 4
.L53:
	movq	24(%rbx), %rdi
	movq	%rbx, %r15
	cmpq	%rcx, %rdi
	jl	.L54
	cmpq	%rcx, %rax
	leaq	-32(%rdx), %r8
	jle	.L60
	leaq	-64(%rdx), %rax
	.p2align 4
.L56:
	movq	%rax, %rdx
	subq	$32, %rax
	cmpq	%rcx, 56(%rax)
	jg	.L56
	cmpq	%rdx, %rbx
	jnb	.L69
.L57:
	vmovdqu	(%rdx), %xmm0
	movq	8(%rbx), %rcx
	movq	(%rbx), %r8
	vmovups	%xmm0, (%rbx)
	movq	16(%rbx), %rax
	vmovdqu	16(%rdx), %xmm0
	vmovups	%xmm0, 16(%rbx)
	movq	%rax, 16(%rdx)
	movq	%r8, (%rdx)
	movq	%rcx, 8(%rdx)
	movq	%rdi, 24(%rdx)
	movq	-8(%rdx), %rax
	movq	24(%r13), %rcx
.L54:
	addq	$32, %rbx
	jmp	.L53
	.p2align 4
.L47:
	cmpq	%r8, %rdi
	jl	.L68
	cmpq	%r8, %rcx
	jge	.L52
.L67:
	vmovdqu	-32(%rsi), %xmm0
	vmovups	%xmm0, 0(%r13)
	vmovdqu	-16(%rsi), %xmm0
	vmovups	%xmm0, 16(%r13)
	movq	%r11, -32(%rsi)
	movq	%r10, -24(%rsi)
	movq	%r9, -16(%rsi)
	movq	%rax, -8(%rsi)
	jmp	.L49
	.p2align 4
.L60:
	movq	%r8, %rdx
	cmpq	%rdx, %rbx
	jb	.L57
	.p2align 4
.L69:
	subq	$8, %rsp
	.cfi_def_cfa_offset 104
	movq	%r14, %rdx
	movq	%rbx, %rdi
	pushq	%rbp
	.cfi_def_cfa_offset 112
	call	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElNS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_T1_
	movq	%rbx, %rdx
	subq	%r13, %rdx
	cmpq	$512, %rdx
	popq	%rax
	.cfi_def_cfa_offset 104
	popq	%rcx
	.cfi_def_cfa_offset 96
	jle	.L65
	testq	%r14, %r14
	movq	%rbx, %rsi
	jne	.L42
.L40:
	sarq	$5, %rdx
	leaq	-2(%rdx), %r12
	movq	%rdx, %rbp
	sarq	%r12
	movq	%r12, %rbx
	salq	$5, %rbx
	addq	%r13, %rbx
	jmp	.L44
	.p2align 4
.L70:
	subq	$1, %r12
.L44:
	movq	8(%rbx), %rdx
	movq	16(%rbx), %rsi
	subq	$32, %rbx
	movq	56(%rbx), %rdi
	movq	32(%rbx), %rax
	movq	%rdx, 8(%rsp)
	movq	%rsi, 16(%rsp)
	movq	%rdi, 24(%rsp)
	movq	%rax, (%rsp)
	pushq	%rdi
	.cfi_def_cfa_offset 104
	pushq	%rsi
	.cfi_def_cfa_offset 112
	movq	%r13, %rdi
	pushq	%rdx
	.cfi_def_cfa_offset 120
	pushq	%rax
	.cfi_def_cfa_offset 128
	movq	%rbp, %rdx
	movq	%r12, %rsi
	call	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElS2_NS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_T0_SD_T1_T2_.isra.35
	addq	$32, %rsp
	.cfi_def_cfa_offset 96
	testq	%r12, %r12
	jne	.L70
	subq	$32, %r15
	.p2align 4
.L45:
	vmovdqu	0(%r13), %xmm0
	movq	%r15, %rbx
	subq	$32, %r15
	movq	40(%r15), %rdx
	movq	32(%r15), %rax
	subq	%r13, %rbx
	vmovups	%xmm0, 32(%r15)
	movq	48(%r15), %rsi
	movq	56(%r15), %rdi
	movq	%rbx, %rcx
	sarq	$5, %rcx
	vmovdqu	16(%r13), %xmm0
	movq	%rdx, 8(%rsp)
	movq	%rsi, 16(%rsp)
	vmovups	%xmm0, 48(%r15)
	movq	%rdi, 24(%rsp)
	movq	%rax, (%rsp)
	pushq	%rdi
	.cfi_def_cfa_offset 104
	pushq	%rsi
	.cfi_def_cfa_offset 112
	movq	%r13, %rdi
	pushq	%rdx
	.cfi_def_cfa_offset 120
	pushq	%rax
	.cfi_def_cfa_offset 128
	xorl	%esi, %esi
	movq	%rcx, %rdx
	call	_ZSt13__adjust_heapIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElS2_NS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_T0_SD_T1_T2_.isra.35
	addq	$32, %rsp
	.cfi_def_cfa_offset 96
	cmpq	$32, %rbx
	jg	.L45
.L65:
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L52:
	.cfi_restore_state
	vmovdqu	(%rdx), %xmm0
	vmovups	%xmm0, 0(%r13)
	vmovdqu	16(%rdx), %xmm0
	vmovups	%xmm0, 16(%r13)
	movq	%r11, (%rdx)
	movq	%r10, 8(%rdx)
	movq	%r9, 16(%rdx)
	movq	%rax, 24(%rdx)
	movq	-8(%rsi), %rax
	jmp	.L49
	.cfi_endproc
.LFE9479:
	.size	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElNS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_T1_, .-_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElNS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_T1_
	.section	.text._ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC2Ev,"axG",@progbits,_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC2Ev
	.type	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC2Ev, @function
_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC2Ev:
.LFB8358:
	.cfi_startproc
	leaq	48(%rdi), %rax
	movq	$1, 8(%rdi)
	movq	$0, 16(%rdi)
	movq	$0, 24(%rdi)
	movl	$0x3f800000, 32(%rdi)
	movq	%rax, (%rdi)
	movq	$0, 40(%rdi)
	movq	$0, 48(%rdi)
	ret
	.cfi_endproc
.LFE8358:
	.size	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC2Ev, .-_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC2Ev
	.weak	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC1Ev
	.set	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC1Ev,_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC2Ev
	.text
	.p2align 4,,15
	.globl	_Z3addxx
	.type	_Z3addxx, @function
_Z3addxx:
.LFB8360:
	.cfi_startproc
	leal	(%rdi,%rsi), %eax
	ret
	.cfi_endproc
.LFE8360:
	.size	_Z3addxx, .-_Z3addxx
	.p2align 4,,15
	.globl	_Z3mulxx
	.type	_Z3mulxx, @function
_Z3mulxx:
.LFB8361:
	.cfi_startproc
	movl	%edi, %eax
	imull	%esi, %eax
	ret
	.cfi_endproc
.LFE8361:
	.size	_Z3mulxx, .-_Z3mulxx
	.p2align 4,,15
	.globl	_Z3dfsxxxx
	.type	_Z3dfsxxxx, @function
_Z3dfsxxxx:
.LFB8362:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	leaq	w(%rip), %rax
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	till(%rip), %r14
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	par(%rip), %r11
	leaq	vis(%rip), %r12
	leaq	level(%rip), %r10
	subq	$120, %rsp
	.cfi_def_cfa_offset 176
	movq	(%rax,%rdi,8), %r8
	movq	%rsi, (%r11,%rdi,8)
	movq	$1, (%r12,%rdi,8)
	movq	%rdx, (%r10,%rdi,8)
	imull	%r8d, %r8d
	addl	%r8d, %ecx
	cmpq	%rdx, mx_level(%rip)
	leaq	tree(%rip), %r8
	movq	%rcx, (%r14,%rdi,8)
	movq	%rdx, %rcx
	cmovge	mx_level(%rip), %rcx
	movq	%rcx, mx_level(%rip)
	leaq	(%rdi,%rdi,2), %rcx
	leaq	(%r8,%rcx,8), %rcx
	movq	(%rcx), %rbx
	movq	8(%rcx), %rcx
	cmpq	%rcx, %rbx
	je	.L85
	movq	%rdi, 24(%rsp)
	leaq	1(%rdx), %rsi
	leaq	3(%rdx), %rdi
	movq	%rdx, 32(%rsp)
	movq	%rcx, %r9
	movq	%rsi, 16(%rsp)
	movq	%rdi, 40(%rsp)
.L81:
	movq	(%rbx), %rbp
	cmpq	$0, (%r12,%rbp,8)
	je	.L88
.L76:
	addq	$8, %rbx
	cmpq	%r9, %rbx
	jne	.L81
.L85:
	addq	$120, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L88:
	.cfi_restore_state
	movq	24(%rsp), %rsi
	movq	(%rax,%rbp,8), %rdx
	movq	$1, (%r12,%rbp,8)
	imull	%edx, %edx
	addl	(%r14,%rsi,8), %edx
	movq	%rsi, (%r11,%rbp,8)
	movq	16(%rsp), %rsi
	cmpq	%rsi, mx_level(%rip)
	movq	%rdx, (%r14,%rbp,8)
	movq	%rsi, %rdx
	cmovge	mx_level(%rip), %rdx
	movq	%rsi, (%r10,%rbp,8)
	movq	%rdx, mx_level(%rip)
	leaq	0(%rbp,%rbp,2), %rdx
	leaq	(%r8,%rdx,8), %rdx
	movq	(%rdx), %rcx
	movq	8(%rdx), %rdx
	cmpq	%rdx, %rcx
	je	.L76
	movq	%rcx, %r15
	movq	%rbp, 64(%rsp)
	movq	32(%rsp), %rdi
	movq	(%r15), %rbp
	movq	%rdx, 8(%rsp)
	leaq	2(%rdi), %rsi
	cmpq	$0, (%r12,%rbp,8)
	movq	%rsi, 56(%rsp)
	je	.L89
.L77:
	addq	$8, %r15
	cmpq	%r15, 8(%rsp)
	je	.L76
	movq	(%r15), %rbp
	cmpq	$0, (%r12,%rbp,8)
	jne	.L77
.L89:
	movq	64(%rsp), %rsi
	movq	(%rax,%rbp,8), %rdx
	movq	56(%rsp), %rdi
	movq	$1, (%r12,%rbp,8)
	imull	%edx, %edx
	addl	(%r14,%rsi,8), %edx
	cmpq	%rdi, mx_level(%rip)
	movq	%rsi, (%r11,%rbp,8)
	movq	%rdi, (%r10,%rbp,8)
	movq	%rdx, (%r14,%rbp,8)
	movq	%rdi, %rdx
	cmovge	mx_level(%rip), %rdx
	movq	%rdx, mx_level(%rip)
	leaq	0(%rbp,%rbp,2), %rdx
	leaq	(%r8,%rdx,8), %rdx
	movq	(%rdx), %r13
	movq	8(%rdx), %rdx
	cmpq	%rdx, %r13
	je	.L77
	movq	%rdx, 48(%rsp)
.L79:
	movq	0(%r13), %rdi
	cmpq	$0, (%r12,%rdi,8)
	je	.L90
.L78:
	addq	$8, %r13
	cmpq	48(%rsp), %r13
	jne	.L79
	jmp	.L77
	.p2align 4
.L90:
	movq	(%r14,%rbp,8), %rcx
	movq	40(%rsp), %rdx
	movq	%rbp, %rsi
	movq	%r9, 104(%rsp)
	movq	%rax, 96(%rsp)
	movq	%r10, 88(%rsp)
	movq	%r8, 80(%rsp)
	movq	%r11, 72(%rsp)
	call	_Z3dfsxxxx
	movq	104(%rsp), %r9
	movq	96(%rsp), %rax
	movq	88(%rsp), %r10
	movq	80(%rsp), %r8
	movq	72(%rsp), %r11
	jmp	.L78
	.cfi_endproc
.LFE8362:
	.size	_Z3dfsxxxx, .-_Z3dfsxxxx
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	" "
	.text
	.p2align 4,,15
	.globl	_Z5printPxx
	.type	_Z5printPxx, @function
_Z5printPxx:
.LFB8364:
	.cfi_startproc
	testq	%rsi, %rsi
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	jle	.L92
	leaq	8(%rdi), %rbx
	leaq	_ZSt4cout(%rip), %rbp
	leaq	(%rbx,%rsi,8), %r12
	.p2align 4
.L93:
	movq	(%rbx), %rsi
	movq	%rbp, %rdi
	addq	$8, %rbx
	call	_ZNSo9_M_insertIxEERSoT_@PLT
	leaq	.LC1(%rip), %rsi
	movl	$1, %edx
	movq	%rax, %rdi
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT
	cmpq	%r12, %rbx
	jne	.L93
.L92:
	movq	_ZSt4cout(%rip), %rax
	leaq	_ZSt4cout(%rip), %rdx
	movq	-24(%rax), %rax
	movq	240(%rdx,%rax), %rbx
	testq	%rbx, %rbx
	je	.L100
	cmpb	$0, 56(%rbx)
	je	.L95
	movsbl	67(%rbx), %esi
.L96:
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo3putEc@PLT
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	movq	%rax, %rdi
	jmp	_ZNSo5flushEv@PLT
	.p2align 4
.L95:
	.cfi_restore_state
	movq	%rbx, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	(%rbx), %rax
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%rdx, %rax
	je	.L96
	movq	%rbx, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L96
.L100:
	call	_ZSt16__throw_bad_castv@PLT
	.cfi_endproc
.LFE8364:
	.size	_Z5printPxx, .-_Z5printPxx
	.section	.rodata.str1.1
.LC2:
	.string	"%lld%lld"
	.text
	.p2align 4,,15
	.globl	_Z7processv
	.type	_Z7processv, @function
_Z7processv:
.LFB8366:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$8, %rsp
	.cfi_def_cfa_offset 64
	movq	q(%rip), %rax
	movq	query(%rip), %rbp
	testq	%rax, %rax
	jle	.L102
	leaq	query(%rip), %r14
	leaq	par(%rip), %r15
	leaq	.LC2(%rip), %r13
	xorl	%r12d, %r12d
	.p2align 4
.L103:
	movq	%r12, %rbx
	xorl	%eax, %eax
	movq	%r13, %rdi
	salq	$5, %rbx
	leaq	0(%rbp,%rbx), %rsi
	leaq	8(%rsi), %rdx
	call	scanf@PLT
	movq	(%r14), %rbp
	leaq	0(%rbp,%rbx), %rax
	movq	(%rax), %rdx
	movq	%r12, 16(%rax)
	addq	$1, %r12
	movq	(%r15,%rdx,8), %rdx
	movq	%rdx, 24(%rax)
	movq	q(%rip), %rax
	cmpq	%r12, %rax
	jg	.L103
.L102:
	salq	$5, %rax
	leaq	0(%rbp,%rax), %r13
	movq	%rax, %rbx
	cmpq	%rbp, %r13
	je	.L114
	sarq	$5, %rax
	subq	$8, %rsp
	.cfi_def_cfa_offset 72
	movl	$63, %edx
	bsrq	%rax, %rax
	pushq	$0
	.cfi_def_cfa_offset 80
	movq	%r13, %rsi
	xorq	$63, %rax
	movq	%rbp, %rdi
	cltq
	subq	%rax, %rdx
	addq	%rdx, %rdx
	call	_ZSt16__introsort_loopIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEElNS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_T1_
	cmpq	$512, %rbx
	popq	%rax
	.cfi_def_cfa_offset 72
	popq	%rdx
	.cfi_def_cfa_offset 64
	jle	.L106
	leaq	512(%rbp), %r12
	movq	%rbp, %rdi
	movq	%r12, %rsi
	call	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEENS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_.isra.85
	cmpq	%r12, %r13
	je	.L114
	movq	%r12, %rsi
	movq	%r13, %r10
	.p2align 4
.L110:
	movq	24(%rsi), %rcx
	cmpq	%rcx, -8(%rsi)
	movq	%rsi, %rdx
	movq	(%rsi), %r9
	movq	8(%rsi), %r8
	movq	16(%rsi), %rdi
	jle	.L108
	leaq	-32(%rsi), %rax
	.p2align 4
.L109:
	vmovdqu	(%rax), %xmm0
	movq	%rax, %rdx
	subq	$32, %rax
	vmovups	%xmm0, 64(%rax)
	vmovdqu	48(%rax), %xmm0
	vmovups	%xmm0, 80(%rax)
	cmpq	24(%rax), %rcx
	jl	.L109
.L108:
	addq	$32, %rsi
	movq	%r9, (%rdx)
	movq	%r8, 8(%rdx)
	cmpq	%rsi, %r10
	movq	%rdi, 16(%rdx)
	movq	%rcx, 24(%rdx)
	jne	.L110
.L114:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L106:
	.cfi_restore_state
	addq	$8, %rsp
	.cfi_def_cfa_offset 56
	movq	%r13, %rsi
	movq	%rbp, %rdi
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	jmp	_ZSt16__insertion_sortIN9__gnu_cxx17__normal_iteratorIP5QuerySt6vectorIS2_SaIS2_EEEENS0_5__ops15_Iter_comp_iterIZ7processvEUlS2_S2_E_EEEvT_SC_T0_.isra.85
	.cfi_endproc
.LFE8366:
	.size	_Z7processv, .-_Z7processv
	.p2align 4,,15
	.globl	_Z7get_ansxx
	.type	_Z7get_ansxx, @function
_Z7get_ansxx:
.LFB8370:
	.cfi_startproc
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	leaq	par(%rip), %rax
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	movq	(%rax,%rdi,8), %rbx
	cmpq	$-1, %rbx
	jne	.L117
	movq	8+w(%rip), %rax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	imull	%eax, %eax
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L117:
	.cfi_restore_state
	movq	%rdi, %rbp
	movq	(%rax,%rbx,8), %rdi
	movq	%rsi, %r12
	cmpq	$-1, %rdi
	jne	.L119
	movq	8+w(%rip), %rax
	leaq	w(%rip), %rcx
	imull	%eax, %eax
.L120:
	movq	(%rcx,%r12,8), %rdx
	imull	(%rcx,%rbp,8), %edx
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	addl	%edx, %eax
	ret
	.p2align 4
.L119:
	.cfi_restore_state
	movq	(%rax,%rsi,8), %r13
	movq	(%rax,%r13,8), %rsi
	call	_Z7get_ansxx
	leaq	w(%rip), %rcx
	movq	(%rcx,%r13,8), %rdx
	imull	(%rcx,%rbx,8), %edx
	addl	%edx, %eax
	jmp	.L120
	.cfi_endproc
.LFE8370:
	.size	_Z7get_ansxx, .-_Z7get_ansxx
	.p2align 4,,15
	.globl	_Z6answerv
	.type	_Z6answerv, @function
_Z6answerv:
.LFB8371:
	.cfi_startproc
	movq	q(%rip), %rax
	testq	%rax, %rax
	jle	.L156
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	salq	$5, %rax
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	w(%rip), %rcx
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	par(%rip), %rbp
	leaq	ans(%rip), %rbx
	subq	$104, %rsp
	.cfi_def_cfa_offset 160
	movq	8+w(%rip), %rdx
	movq	query(%rip), %r8
	movl	%edx, %r15d
	leaq	(%rax,%r8), %r14
	imull	%edx, %r15d
	jmp	.L132
	.p2align 4
.L125:
	addq	$32, %r8
	movq	%rax, (%rbx,%r11,8)
	cmpq	%r8, %r14
	je	.L159
.L132:
	movq	(%r8), %r10
	movq	16(%r8), %r11
	movq	%r15, %rax
	movq	0(%rbp,%r10,8), %r9
	cmpq	$-1, %r9
	je	.L125
	movq	0(%rbp,%r9,8), %r12
	movq	8(%r8), %r13
	movq	%r15, %rdx
	cmpq	$-1, %r12
	jne	.L160
.L126:
	movq	(%rcx,%r13,8), %rax
	addq	$32, %r8
	imull	(%rcx,%r10,8), %eax
	addl	%edx, %eax
	cmpq	%r8, %r14
	movq	%rax, (%rbx,%r11,8)
	jne	.L132
.L159:
	xorl	%r12d, %r12d
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %r14
	jmp	.L136
	.p2align 4
.L163:
	movsbl	67(%rbp), %esi
.L135:
	movq	%r13, %rdi
	addq	$1, %r12
	call	_ZNSo3putEc@PLT
	movq	%rax, %rdi
	call	_ZNSo5flushEv@PLT
	cmpq	%r12, q(%rip)
	jle	.L161
.L136:
	movq	(%rbx,%r12,8), %rsi
	leaq	_ZSt4cout(%rip), %rdi
	call	_ZNSo9_M_insertIxEERSoT_@PLT
	movq	%rax, %r13
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%r13,%rax), %rbp
	testq	%rbp, %rbp
	je	.L162
	cmpb	$0, 56(%rbp)
	jne	.L163
	movq	%rbp, %rdi
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT
	movq	0(%rbp), %rax
	movl	$10, %esi
	movq	48(%rax), %rax
	cmpq	%r14, %rax
	je	.L135
	movq	%rbp, %rdi
	call	*%rax
	movsbl	%al, %esi
	jmp	.L135
	.p2align 4
.L161:
	addq	$104, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L160:
	.cfi_restore_state
	movq	0(%rbp,%r12,8), %rax
	movq	0(%rbp,%r13,8), %rdx
	movq	%r15, %rsi
	cmpq	$-1, %rax
	movq	%rax, 8(%rsp)
	jne	.L164
.L127:
	movq	(%rcx,%rdx,8), %rax
	imull	(%rcx,%r9,8), %eax
	leal	(%rax,%rsi), %edx
	jmp	.L126
	.p2align 4
.L156:
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	.cfi_restore 13
	.cfi_restore 14
	.cfi_restore 15
	rep ret
	.p2align 4
.L164:
	.cfi_def_cfa_offset 160
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
	movq	0(%rbp,%rdx,8), %rax
	movq	%rax, 16(%rsp)
	movq	8(%rsp), %rax
	movq	0(%rbp,%rax,8), %rax
	cmpq	$-1, %rax
	movq	%rax, 24(%rsp)
	jne	.L165
.L128:
	movq	16(%rsp), %rax
	movq	(%rcx,%rax,8), %rax
	imull	(%rcx,%r12,8), %eax
	addl	%eax, %esi
	jmp	.L127
.L165:
	movq	16(%rsp), %rax
	movq	0(%rbp,%rax,8), %rax
	movq	%rax, 32(%rsp)
	movq	24(%rsp), %rax
	movq	0(%rbp,%rax,8), %rax
	cmpq	$-1, %rax
	movq	%rax, 40(%rsp)
	jne	.L166
.L129:
	movq	32(%rsp), %rax
	movq	8(%rsp), %rdi
	movq	(%rcx,%rax,8), %rax
	imull	(%rcx,%rdi,8), %eax
	addl	%eax, %esi
	jmp	.L128
.L166:
	movq	32(%rsp), %rax
	movq	0(%rbp,%rax,8), %rax
	movq	%rax, 48(%rsp)
	movq	40(%rsp), %rax
	movq	0(%rbp,%rax,8), %rax
	cmpq	$-1, %rax
	movq	%rax, 64(%rsp)
	jne	.L167
.L130:
	movq	48(%rsp), %rax
	movq	24(%rsp), %rdi
	movq	(%rcx,%rax,8), %rax
	imull	(%rcx,%rdi,8), %eax
	addl	%eax, %esi
	jmp	.L129
.L162:
	call	_ZSt16__throw_bad_castv@PLT
.L167:
	movq	48(%rsp), %rax
	movq	0(%rbp,%rax,8), %rax
	movq	%rax, 56(%rsp)
	movq	64(%rsp), %rax
	movq	0(%rbp,%rax,8), %rdi
	cmpq	$-1, %rdi
	je	.L131
	movq	56(%rsp), %rax
	movq	%rdx, 80(%rsp)
	movq	%rcx, 88(%rsp)
	movq	0(%rbp,%rax,8), %rdx
	movq	0(%rbp,%rdx,8), %rsi
	movq	%rdx, 72(%rsp)
	call	_Z7get_ansxx
	movq	72(%rsp), %rdx
	movq	88(%rsp), %rcx
	movq	(%rcx,%rdx,8), %rsi
	movq	64(%rsp), %rdx
	imull	(%rcx,%rdx,8), %esi
	movq	80(%rsp), %rdx
	addl	%eax, %esi
.L131:
	movq	56(%rsp), %rax
	movq	40(%rsp), %rdi
	movq	(%rcx,%rax,8), %rax
	imull	(%rcx,%rdi,8), %eax
	addl	%eax, %esi
	jmp	.L130
	.cfi_endproc
.LFE8371:
	.size	_Z6answerv, .-_Z6answerv
	.section	.text._ZNSt6vectorIxSaIxEEC2Ev,"axG",@progbits,_ZNSt6vectorIxSaIxEEC5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIxSaIxEEC2Ev
	.type	_ZNSt6vectorIxSaIxEEC2Ev, @function
_ZNSt6vectorIxSaIxEEC2Ev:
.LFB8877:
	.cfi_startproc
	movq	$0, (%rdi)
	movq	$0, 8(%rdi)
	movq	$0, 16(%rdi)
	ret
	.cfi_endproc
.LFE8877:
	.size	_ZNSt6vectorIxSaIxEEC2Ev, .-_ZNSt6vectorIxSaIxEEC2Ev
	.weak	_ZNSt6vectorIxSaIxEEC1Ev
	.set	_ZNSt6vectorIxSaIxEEC1Ev,_ZNSt6vectorIxSaIxEEC2Ev
	.section	.text._ZNSt6vectorIxSaIxEED2Ev,"axG",@progbits,_ZNSt6vectorIxSaIxEED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIxSaIxEED2Ev
	.type	_ZNSt6vectorIxSaIxEED2Ev, @function
_ZNSt6vectorIxSaIxEED2Ev:
.LFB8880:
	.cfi_startproc
	movq	(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L171
	jmp	_ZdlPv@PLT
	.p2align 4
.L171:
	rep ret
	.cfi_endproc
.LFE8880:
	.size	_ZNSt6vectorIxSaIxEED2Ev, .-_ZNSt6vectorIxSaIxEED2Ev
	.weak	_ZNSt6vectorIxSaIxEED1Ev
	.set	_ZNSt6vectorIxSaIxEED1Ev,_ZNSt6vectorIxSaIxEED2Ev
	.text
	.p2align 4,,15
	.type	__tcf_0, @function
__tcf_0:
.LFB10049:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	leaq	7200000+tree(%rip), %rbx
	leaq	-7200024(%rbx), %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	.p2align 4,,10
	.p2align 3
.L173:
	movq	%rbx, %rdi
	subq	$24, %rbx
	call	_ZNSt6vectorIxSaIxEED1Ev
	cmpq	%rbp, %rbx
	jne	.L173
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE10049:
	.size	__tcf_0, .-__tcf_0
	.section	.text._ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED2Ev,"axG",@progbits,_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED2Ev
	.type	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED2Ev, @function
_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED2Ev:
.LFB8889:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbp
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	16(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L178
	.p2align 4
.L179:
	movq	(%rdi), %rbx
	call	_ZdlPv@PLT
	testq	%rbx, %rbx
	movq	%rbx, %rdi
	jne	.L179
.L178:
	movq	8(%rbp), %rax
	movq	0(%rbp), %rdi
	xorl	%esi, %esi
	addq	$48, %rbp
	leaq	0(,%rax,8), %rdx
	call	memset@PLT
	movq	-48(%rbp), %rdi
	movq	$0, -24(%rbp)
	movq	$0, -32(%rbp)
	cmpq	%rbp, %rdi
	je	.L185
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	jmp	_ZdlPv@PLT
	.p2align 4
.L185:
	.cfi_restore_state
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE8889:
	.size	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED2Ev, .-_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED2Ev
	.weak	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev
	.set	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev,_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED2Ev
	.section	.text._ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED2Ev,"axG",@progbits,_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED5Ev,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED2Ev
	.type	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED2Ev, @function
_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED2Ev:
.LFB10051:
	.cfi_startproc
	jmp	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEED1Ev
	.cfi_endproc
.LFE10051:
	.size	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED2Ev, .-_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED2Ev
	.weak	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED1Ev
	.set	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED1Ev,_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED2Ev
	.section	.text._ZNSt6vectorI5QuerySaIS0_EEC2EmRKS1_,"axG",@progbits,_ZNSt6vectorI5QuerySaIS0_EEC5EmRKS1_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorI5QuerySaIS0_EEC2EmRKS1_
	.type	_ZNSt6vectorI5QuerySaIS0_EEC2EmRKS1_, @function
_ZNSt6vectorI5QuerySaIS0_EEC2EmRKS1_:
.LFB8898:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r12
	pushq	%r10
	pushq	%rbx
	.cfi_offset 12, -24
	.cfi_offset 10, -32
	.cfi_offset 3, -40
	movq	%rdi, %r12
	subq	$8, %rsp
	testq	%rsi, %rsi
	movq	$0, (%rdi)
	movq	$0, 8(%rdi)
	movq	$0, 16(%rdi)
	je	.L189
	movabsq	$576460752303423487, %rax
	cmpq	%rax, %rsi
	ja	.L197
	movq	%rsi, %rbx
	salq	$5, %rbx
	movq	%rbx, %rdi
	call	_Znwm@PLT
	vpxor	%xmm0, %xmm0, %xmm0
	leaq	(%rax,%rbx), %rsi
	movq	%rax, (%r12)
	movq	%rsi, 16(%r12)
	.p2align 4
.L191:
	vmovups	%xmm0, (%rax)
	vextracti128	$0x1, %ymm0, 16(%rax)
	addq	$32, %rax
	cmpq	%rsi, %rax
	jne	.L191
	vzeroupper
.L192:
	movq	%rsi, 8(%r12)
	addq	$8, %rsp
	popq	%rbx
	popq	%r10
	popq	%r12
	popq	%rbp
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret
	.p2align 4
.L189:
	.cfi_restore_state
	xorl	%esi, %esi
	jmp	.L192
.L197:
	call	_ZSt17__throw_bad_allocv@PLT
	.cfi_endproc
.LFE8898:
	.size	_ZNSt6vectorI5QuerySaIS0_EEC2EmRKS1_, .-_ZNSt6vectorI5QuerySaIS0_EEC2EmRKS1_
	.weak	_ZNSt6vectorI5QuerySaIS0_EEC1EmRKS1_
	.set	_ZNSt6vectorI5QuerySaIS0_EEC1EmRKS1_,_ZNSt6vectorI5QuerySaIS0_EEC2EmRKS1_
	.section	.text._ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_,"axG",@progbits,_ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_
	.type	_ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_, @function
_ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_:
.LFB9233:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	movq	%rsi, %r14
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rsi, %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbp
	subq	$24, %rsp
	.cfi_def_cfa_offset 80
	movq	8(%rdi), %rcx
	movq	(%rdi), %rbx
	movq	%rcx, %rax
	subq	%rbx, %r14
	subq	%rbx, %rax
	sarq	$3, %rax
	testq	%rax, %rax
	je	.L206
	leaq	(%rax,%rax), %rsi
	movq	$-8, %r15
	cmpq	%rsi, %rax
	jbe	.L217
.L200:
	movq	%r15, %rdi
	movq	%rdx, (%rsp)
	call	_Znwm@PLT
	movq	0(%rbp), %rbx
	movq	8(%rbp), %rcx
	movq	%r12, %r8
	movq	(%rsp), %rdx
	movq	%rax, %r13
	addq	%rax, %r15
	subq	%rbx, %r8
.L201:
	addq	%r13, %r14
	je	.L202
	movq	(%rdx), %rax
	movq	%rax, (%r14)
.L202:
	cmpq	%rbx, %r12
	je	.L203
	movq	%r8, %rdx
	movq	%rbx, %rsi
	movq	%r13, %rdi
	movq	%rcx, 8(%rsp)
	movq	%r8, (%rsp)
	call	memmove@PLT
	movq	8(%rsp), %rcx
	movq	(%rsp), %r8
.L203:
	movq	%rcx, %r14
	leaq	8(%r13,%r8), %r8
	subq	%r12, %r14
	cmpq	%r12, %rcx
	je	.L204
	movq	%r8, %rdi
	movq	%r14, %rdx
	movq	%r12, %rsi
	call	memcpy@PLT
	movq	%rax, %r8
.L204:
	addq	%r8, %r14
	testq	%rbx, %rbx
	je	.L205
	movq	%rbx, %rdi
	call	_ZdlPv@PLT
.L205:
	movq	%r13, 0(%rbp)
	movq	%r14, 8(%rbp)
	movq	%r15, 16(%rbp)
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L206:
	.cfi_restore_state
	movl	$1, %esi
.L199:
	leaq	0(,%rsi,8), %r15
	jmp	.L200
	.p2align 4
.L217:
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rsi
	ja	.L200
	testq	%rsi, %rsi
	jne	.L199
	movq	%r14, %r8
	xorl	%r15d, %r15d
	xorl	%r13d, %r13d
	jmp	.L201
	.cfi_endproc
.LFE9233:
	.size	_ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_, .-_ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_
	.section	.rodata.str1.1
.LC3:
	.string	"%lld"
	.text
	.p2align 4,,15
	.globl	_Z4initv
	.type	_Z4initv, @function
_Z4initv:
.LFB8365:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	leaq	q(%rip), %rdx
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	n(%rip), %rsi
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	leaq	.LC2(%rip), %rdi
	subq	$120, %rsp
	.cfi_def_cfa_offset 176
	movq	%fs:40, %rax
	movq	%rax, 104(%rsp)
	xorl	%eax, %eax
	call	scanf@PLT
	cmpq	$0, n(%rip)
	jle	.L219
	leaq	8+w(%rip), %rbp
	leaq	vis(%rip), %r15
	leaq	.LC3(%rip), %r12
	movl	$1, %ebx
	.p2align 4
.L223:
	movq	%rbp, %rsi
	xorl	%eax, %eax
	movq	%r12, %rdi
	call	scanf@PLT
	movq	n(%rip), %rax
	movq	$0, (%r15,%rbx,8)
	addq	$1, %rbx
	addq	$8, %rbp
	cmpq	%rbx, %rax
	jge	.L223
	cmpq	$1, %rax
	jle	.L219
	xorl	%ebx, %ebx
	leaq	96(%rsp), %r12
	leaq	88(%rsp), %rbp
	leaq	tree(%rip), %r14
	leaq	.LC2(%rip), %r13
	jmp	.L221
	.p2align 4
.L255:
	testq	%rsi, %rsi
	movq	96(%rsp), %rax
	je	.L225
	movq	%rax, (%rsi)
	movq	96(%rsp), %rax
.L225:
	leaq	(%rdx,%rdx,2), %rdx
	addq	$8, %rsi
	movq	%rsi, 8(%r14,%rdx,8)
.L226:
	leaq	(%rax,%rax,2), %rdx
	leaq	(%r14,%rdx,8), %rdi
	movq	8(%rdi), %rsi
	cmpq	16(%rdi), %rsi
	je	.L227
	testq	%rsi, %rsi
	je	.L228
	movq	88(%rsp), %rdx
	movq	%rdx, (%rsi)
.L228:
	leaq	(%rax,%rax,2), %rax
	addq	$8, %rsi
	movq	%rsi, 8(%r14,%rax,8)
.L229:
	movq	n(%rip), %rax
	addq	$1, %rbx
	subq	$1, %rax
	cmpq	%rbx, %rax
	jle	.L219
.L221:
	movq	%r12, %rdx
	movq	%rbp, %rsi
	movq	%r13, %rdi
	xorl	%eax, %eax
	call	scanf@PLT
	movq	88(%rsp), %rdx
	leaq	(%rdx,%rdx,2), %rax
	leaq	(%r14,%rax,8), %rdi
	movq	8(%rdi), %rsi
	cmpq	16(%rdi), %rsi
	jne	.L255
	movq	%r12, %rdx
	call	_ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_
	movq	96(%rsp), %rax
	jmp	.L226
	.p2align 4
.L219:
	movq	8+w(%rip), %rax
	movq	24+tree(%rip), %rdx
	movq	$-1, 8+par(%rip)
	movq	$1, 8+vis(%rip)
	movq	$0, 8+level(%rip)
	imull	%eax, %eax
	cmpq	$0, mx_level(%rip)
	movq	%rax, 8+till(%rip)
	movl	$0, %eax
	cmovns	mx_level(%rip), %rax
	movq	%rax, mx_level(%rip)
	movq	32+tree(%rip), %rax
	cmpq	%rax, %rdx
	je	.L218
	leaq	vis(%rip), %r15
	leaq	w(%rip), %r11
	movq	%rdx, %r9
	movq	%rax, %r8
.L238:
	movq	(%r9), %rbx
	cmpq	$0, (%r15,%rbx,8)
	je	.L256
.L231:
	addq	$8, %r9
	cmpq	%r9, %r8
	jne	.L238
.L218:
	movq	104(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L257
	addq	$120, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L227:
	.cfi_restore_state
	movq	%rbp, %rdx
	call	_ZNSt6vectorIxSaIxEE17_M_realloc_insertIJRKxEEEvN9__gnu_cxx17__normal_iteratorIPxS1_EEDpOT_
	jmp	.L229
	.p2align 4
.L256:
	movq	(%r11,%rbx,8), %rax
	leaq	till(%rip), %r10
	leaq	tree(%rip), %rcx
	movq	$1, (%r15,%rbx,8)
	movq	%rcx, 16(%rsp)
	imull	%eax, %eax
	addl	8+till(%rip), %eax
	cmpq	$0, mx_level(%rip)
	movq	%rax, (%r10,%rbx,8)
	leaq	par(%rip), %rax
	movq	$1, (%rax,%rbx,8)
	leaq	level(%rip), %rax
	movq	$1, (%rax,%rbx,8)
	movl	$1, %eax
	cmovg	mx_level(%rip), %rax
	movq	%rax, mx_level(%rip)
	leaq	(%rbx,%rbx,2), %rax
	leaq	(%rcx,%rax,8), %rax
	movq	(%rax), %rdx
	movq	8(%rax), %rax
	cmpq	%rax, %rdx
	je	.L231
	movq	%rdx, %r14
	movq	%rbx, 32(%rsp)
	movq	%rax, 8(%rsp)
	movq	(%r14), %rbx
	cmpq	$0, (%r15,%rbx,8)
	je	.L258
.L232:
	addq	$8, %r14
	cmpq	%r14, 8(%rsp)
	je	.L231
	movq	(%r14), %rbx
	cmpq	$0, (%r15,%rbx,8)
	jne	.L232
.L258:
	movq	32(%rsp), %rcx
	movq	(%r11,%rbx,8), %rax
	movq	$1, (%r15,%rbx,8)
	imull	%eax, %eax
	addl	(%r10,%rcx,8), %eax
	cmpq	$2, mx_level(%rip)
	movq	%rax, (%r10,%rbx,8)
	leaq	par(%rip), %rax
	movq	%rcx, (%rax,%rbx,8)
	leaq	level(%rip), %rax
	movq	16(%rsp), %rcx
	movq	$2, (%rax,%rbx,8)
	movl	$2, %eax
	cmovge	mx_level(%rip), %rax
	movq	%rax, mx_level(%rip)
	leaq	(%rbx,%rbx,2), %rax
	leaq	(%rcx,%rax,8), %rax
	movq	(%rax), %rbp
	movq	8(%rax), %rax
	cmpq	%rax, %rbp
	je	.L232
	movq	%rax, 24(%rsp)
.L236:
	movq	0(%rbp), %r12
	cmpq	$0, (%r15,%r12,8)
	je	.L259
.L233:
	addq	$8, %rbp
	cmpq	%rbp, 24(%rsp)
	jne	.L236
	jmp	.L232
.L259:
	movq	(%r11,%r12,8), %rax
	movq	16(%rsp), %rcx
	movq	$1, (%r15,%r12,8)
	imull	%eax, %eax
	addl	(%r10,%rbx,8), %eax
	cmpq	$3, mx_level(%rip)
	movq	%rax, (%r10,%r12,8)
	leaq	par(%rip), %rax
	movq	%rbx, (%rax,%r12,8)
	leaq	level(%rip), %rax
	movq	$3, (%rax,%r12,8)
	movl	$3, %eax
	cmovge	mx_level(%rip), %rax
	movq	%rax, mx_level(%rip)
	leaq	(%r12,%r12,2), %rax
	leaq	(%rcx,%rax,8), %rax
	movq	(%rax), %r13
	movq	8(%rax), %rax
	cmpq	%rax, %r13
	je	.L233
.L235:
	movq	0(%r13), %rdi
	cmpq	$0, (%r15,%rdi,8)
	je	.L260
.L234:
	addq	$8, %r13
	cmpq	%rax, %r13
	jne	.L235
	jmp	.L233
.L260:
	movq	(%r10,%r12,8), %rcx
	movl	$4, %edx
	movq	%r12, %rsi
	movq	%rax, 72(%rsp)
	movq	%r9, 64(%rsp)
	movq	%r8, 56(%rsp)
	movq	%r11, 48(%rsp)
	movq	%r10, 40(%rsp)
	call	_Z3dfsxxxx
	movq	72(%rsp), %rax
	movq	64(%rsp), %r9
	movq	56(%rsp), %r8
	movq	48(%rsp), %r11
	movq	40(%rsp), %r10
	jmp	.L234
.L257:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE8365:
	.size	_Z4initv, .-_Z4initv
	.section	.text._ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm,"axG",@progbits,_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm
	.type	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm, @function
_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm:
.LFB9644:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA9644
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rdi, %rbp
	movq	%rsi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 48
	cmpq	$1, %rsi
	je	.L282
	movabsq	$2305843009213693951, %rax
	movq	%rdx, %r12
	cmpq	%rax, %rsi
	ja	.L283
	leaq	0(,%rsi,8), %r13
	movq	%r13, %rdi
.LEHB0:
	call	_Znwm@PLT
	movq	%r13, %rdx
	xorl	%esi, %esi
	movq	%rax, %rdi
	movq	%rax, %r12
	call	memset@PLT
	leaq	48(%rbp), %r10
.L263:
	movq	16(%rbp), %rcx
	movq	$0, 16(%rbp)
	testq	%rcx, %rcx
	je	.L265
	xorl	%r8d, %r8d
	leaq	16(%rbp), %r9
	jmp	.L268
	.p2align 4
.L266:
	movq	(%rsi), %rdx
	movq	%rdx, (%rcx)
	movq	(%rax), %rax
	movq	%rcx, (%rax)
.L267:
	testq	%rdi, %rdi
	movq	%rdi, %rcx
	je	.L265
.L268:
	movq	8(%rcx), %rax
	xorl	%edx, %edx
	movq	(%rcx), %rdi
	divq	%rbx
	leaq	(%r12,%rdx,8), %rax
	movq	(%rax), %rsi
	testq	%rsi, %rsi
	jne	.L266
	movq	16(%rbp), %rsi
	movq	%rsi, (%rcx)
	movq	%rcx, 16(%rbp)
	movq	%r9, (%rax)
	cmpq	$0, (%rcx)
	je	.L272
	testq	%rdi, %rdi
	movq	%rcx, (%r12,%r8,8)
	movq	%rdx, %r8
	movq	%rdi, %rcx
	jne	.L268
	.p2align 4
.L265:
	movq	0(%rbp), %rdi
	cmpq	%r10, %rdi
	je	.L269
	call	_ZdlPv@PLT
.L269:
	movq	%rbx, 8(%rbp)
	movq	%r12, 0(%rbp)
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L272:
	.cfi_restore_state
	movq	%rdx, %r8
	jmp	.L267
	.p2align 4
.L282:
	leaq	48(%rdi), %r12
	movq	$0, 48(%rdi)
	movq	%r12, %r10
	jmp	.L263
.L283:
	call	_ZSt17__throw_bad_allocv@PLT
.LEHE0:
.L273:
	movq	%rax, %rdi
	vzeroupper
	call	__cxa_begin_catch@PLT
	movq	(%r12), %rax
	movq	%rax, 40(%rbp)
.LEHB1:
	call	__cxa_rethrow@PLT
.LEHE1:
.L274:
	movq	%rax, %rbx
	vzeroupper
	call	__cxa_end_catch@PLT
	movq	%rbx, %rdi
.LEHB2:
	call	_Unwind_Resume@PLT
.LEHE2:
	.cfi_endproc
.LFE9644:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm,"aG",@progbits,_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm,comdat
	.align 4
.LLSDA9644:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT9644-.LLSDATTD9644
.LLSDATTD9644:
	.byte	0x1
	.uleb128 .LLSDACSE9644-.LLSDACSB9644
.LLSDACSB9644:
	.uleb128 .LEHB0-.LFB9644
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L273-.LFB9644
	.uleb128 0x1
	.uleb128 .LEHB1-.LFB9644
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L274-.LFB9644
	.uleb128 0
	.uleb128 .LEHB2-.LFB9644
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE9644:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT9644:
	.section	.text._ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm,"axG",@progbits,_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm,comdat
	.size	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm, .-_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm
	.section	.text._ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE,"axG",@progbits,_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE,comdat
	.align 2
	.p2align 4,,15
	.weak	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE
	.type	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE, @function
_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE:
.LFB9497:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA9497
	pushq	%r13
	.cfi_def_cfa_offset 16
	.cfi_offset 13, -16
	pushq	%r12
	.cfi_def_cfa_offset 24
	.cfi_offset 12, -24
	movq	%rdx, %r13
	pushq	%rbp
	.cfi_def_cfa_offset 32
	.cfi_offset 6, -32
	pushq	%rbx
	.cfi_def_cfa_offset 40
	.cfi_offset 3, -40
	movq	%rsi, %r12
	movq	%rdi, %rbx
	movq	%rcx, %rbp
	addq	$32, %rdi
	subq	$24, %rsp
	.cfi_def_cfa_offset 64
	movq	-8(%rdi), %rdx
	movq	-24(%rdi), %rsi
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	8(%rdi), %rax
	movl	$1, %ecx
	movq	%rax, (%rsp)
.LEHB3:
	call	_ZNKSt8__detail20_Prime_rehash_policy14_M_need_rehashEmmm@PLT
.LEHE3:
	testb	%al, %al
	je	.L285
	movq	%rdx, %rsi
	movq	%rbx, %rdi
	movq	%rsp, %rdx
.LEHB4:
	call	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE9_M_rehashEmRKm
.LEHE4:
	movq	%r13, %rax
	xorl	%edx, %edx
	divq	8(%rbx)
	movq	%rdx, %r12
.L285:
	movq	(%rbx), %rax
	leaq	0(,%r12,8), %rcx
	movq	(%rax,%r12,8), %rax
	testq	%rax, %rax
	je	.L286
	movq	(%rax), %rax
	movq	%rax, 0(%rbp)
	movq	(%rbx), %rax
	movq	(%rax,%r12,8), %rax
	movq	%rbp, (%rax)
.L287:
	addq	$1, 24(%rbx)
	movq	%rbp, %rax
	movq	8(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L298
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbx
	.cfi_def_cfa_offset 32
	popq	%rbp
	.cfi_def_cfa_offset 24
	popq	%r12
	.cfi_def_cfa_offset 16
	popq	%r13
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L286:
	.cfi_restore_state
	movq	16(%rbx), %rax
	movq	%rax, 0(%rbp)
	movq	%rbp, 16(%rbx)
	movq	0(%rbp), %rax
	movq	(%rbx), %rsi
	testq	%rax, %rax
	je	.L289
	movq	8(%rax), %rax
	xorl	%edx, %edx
	divq	8(%rbx)
	movq	%rbp, (%rsi,%rdx,8)
.L289:
	leaq	16(%rbx), %rax
	movq	%rax, (%rsi,%rcx)
	jmp	.L287
.L298:
	call	__stack_chk_fail@PLT
.L293:
	movq	%rax, %rdi
	vzeroupper
	call	__cxa_begin_catch@PLT
	movq	%rbp, %rdi
	call	_ZdlPv@PLT
.LEHB5:
	call	__cxa_rethrow@PLT
.LEHE5:
.L294:
	movq	%rax, %rbx
	vzeroupper
	call	__cxa_end_catch@PLT
	movq	%rbx, %rdi
.LEHB6:
	call	_Unwind_Resume@PLT
.LEHE6:
	.cfi_endproc
.LFE9497:
	.section	.gcc_except_table._ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE,"aG",@progbits,_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE,comdat
	.align 4
.LLSDA9497:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT9497-.LLSDATTD9497
.LLSDATTD9497:
	.byte	0x1
	.uleb128 .LLSDACSE9497-.LLSDACSB9497
.LLSDACSB9497:
	.uleb128 .LEHB3-.LFB9497
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB4-.LFB9497
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L293-.LFB9497
	.uleb128 0x1
	.uleb128 .LEHB5-.LFB9497
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L294-.LFB9497
	.uleb128 0
	.uleb128 .LEHB6-.LFB9497
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
.LLSDACSE9497:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT9497:
	.section	.text._ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE,"axG",@progbits,_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE,comdat
	.size	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE, .-_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE
	.text
	.p2align 4,,15
	.type	_Z8get_ans2xx.part.98, @function
_Z8get_ans2xx.part.98:
.LFB10180:
	.cfi_startproc
	pushq	%r14
	.cfi_def_cfa_offset 16
	.cfi_offset 14, -16
	pushq	%r13
	.cfi_def_cfa_offset 24
	.cfi_offset 13, -24
	xorl	%edx, %edx
	pushq	%r12
	.cfi_def_cfa_offset 32
	.cfi_offset 12, -32
	pushq	%rbp
	.cfi_def_cfa_offset 40
	.cfi_offset 6, -40
	movq	%rdi, %r12
	pushq	%rbx
	.cfi_def_cfa_offset 48
	.cfi_offset 3, -48
	movq	8+cache(%rip), %rcx
	movq	%rsi, %r13
	imulq	$100000000, %rdi, %rbx
	addq	%rsi, %rbx
	movq	%rbx, %rax
	divq	%rcx
	movq	cache(%rip), %rax
	movq	(%rax,%rdx,8), %r11
	movq	%rdx, %r14
	testq	%r11, %r11
	je	.L300
	movq	(%r11), %rdi
	movq	%rdx, %rbp
	movq	8(%rdi), %r10
	movq	%rdi, %r8
	movq	%r10, %r9
	jmp	.L302
	.p2align 4
.L333:
	movq	(%r8), %r8
	testq	%r8, %r8
	je	.L300
	movq	8(%r8), %r9
	xorl	%edx, %edx
	movq	%r9, %rax
	divq	%rcx
	cmpq	%rdx, %rbp
	jne	.L300
.L302:
	cmpq	%r9, %rbx
	jne	.L333
	jmp	.L301
	.p2align 4
.L334:
	movq	(%rdi), %rdi
	testq	%rdi, %rdi
	je	.L304
	movq	8(%rdi), %r10
	xorl	%edx, %edx
	movq	%r10, %rax
	divq	%rcx
	cmpq	%rdx, %rbp
	jne	.L304
.L301:
	cmpq	%r10, %rbx
	jne	.L334
	addq	$16, %rdi
.L311:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	movq	(%rdi), %rax
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L300:
	.cfi_restore_state
	leaq	par(%rip), %rax
	movq	(%rax,%r13,8), %rsi
	movq	(%rax,%r12,8), %rdi
	cmpq	%rdi, %rsi
	je	.L335
	call	_Z8get_ans2xx.part.98
	movq	8+cache(%rip), %rcx
	movq	%rax, %rbp
	xorl	%edx, %edx
	movq	%rbx, %rax
	divq	%rcx
	movq	cache(%rip), %rax
	movq	(%rax,%rdx,8), %r11
	movq	%rdx, %r14
.L307:
	leaq	w(%rip), %rax
	movq	(%rax,%r13,8), %rdx
	movl	%edx, %esi
	imull	(%rax,%r12,8), %esi
	testq	%r11, %r11
	movq	%rsi, %r12
	je	.L308
	movq	(%r11), %rsi
	movq	8(%rsi), %rdi
	jmp	.L310
	.p2align 4
.L336:
	movq	(%rsi), %rsi
	testq	%rsi, %rsi
	je	.L308
	movq	8(%rsi), %rdi
	xorl	%edx, %edx
	movq	%rdi, %rax
	divq	%rcx
	cmpq	%r14, %rdx
	jne	.L308
.L310:
	cmpq	%rdi, %rbx
	jne	.L336
	addq	$16, %rsi
.L312:
	leal	(%r12,%rbp), %eax
	movq	%rax, (%rsi)
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 40
	popq	%rbp
	.cfi_def_cfa_offset 32
	popq	%r12
	.cfi_def_cfa_offset 24
	popq	%r13
	.cfi_def_cfa_offset 16
	popq	%r14
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L304:
	.cfi_restore_state
	movl	$24, %edi
	call	_Znwm@PLT
	leaq	cache(%rip), %rdi
	movq	$0, (%rax)
	movq	%rbx, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rcx
	movq	%rbx, %rdx
	movq	%rbp, %rsi
	call	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE
	leaq	16(%rax), %rdi
	jmp	.L311
.L335:
	leaq	till(%rip), %rax
	movq	(%rax,%rsi,8), %rbp
	jmp	.L307
	.p2align 4
.L308:
	movl	$24, %edi
	call	_Znwm@PLT
	leaq	cache(%rip), %rdi
	movq	%r14, %rsi
	movq	$0, (%rax)
	movq	%rbx, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rcx
	movq	%rbx, %rdx
	call	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE
	leaq	16(%rax), %rsi
	jmp	.L312
	.cfi_endproc
.LFE10180:
	.size	_Z8get_ans2xx.part.98, .-_Z8get_ans2xx.part.98
	.p2align 4,,15
	.globl	_Z8get_ans2xx
	.type	_Z8get_ans2xx, @function
_Z8get_ans2xx:
.LFB8372:
	.cfi_startproc
	cmpq	%rsi, %rdi
	je	.L341
	jmp	_Z8get_ans2xx.part.98
	.p2align 4
.L341:
	leaq	till(%rip), %rax
	movq	(%rax,%rdi,8), %rax
	ret
	.cfi_endproc
.LFE8372:
	.size	_Z8get_ans2xx, .-_Z8get_ans2xx
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB8373:
	.cfi_startproc
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	call	_Z4initv
	cmpq	$1000, n(%rip)
	jle	.L343
	cmpq	$386, mx_level(%rip)
	je	.L343
	cmpq	$0, q(%rip)
	jle	.L346
	movq	query(%rip), %rsi
	leaq	query(%rip), %rbp
	leaq	level(%rip), %r14
	leaq	.LC2(%rip), %r12
	xorl	%r13d, %r13d
	.p2align 4
.L347:
	movq	%r13, %rbx
	xorl	%eax, %eax
	movq	%r12, %rdi
	salq	$5, %rbx
	addq	%rbx, %rsi
	leaq	8(%rsi), %rdx
	call	scanf@PLT
	movq	0(%rbp), %rsi
	leaq	(%rsi,%rbx), %rax
	movq	(%rax), %rdx
	movq	%r13, 16(%rax)
	addq	$1, %r13
	cmpq	%r13, q(%rip)
	movq	(%r14,%rdx,8), %rdx
	movq	%rdx, 24(%rax)
	jg	.L347
.L346:
	movq	8+cache(%rip), %r8
	xorl	%edx, %edx
	movl	$100000001, %eax
	movq	8+w(%rip), %rbp
	divq	%r8
	movq	cache(%rip), %rax
	movq	(%rax,%rdx,8), %r9
	movq	%rdx, %rbx
	testq	%r9, %r9
	je	.L348
	movq	(%r9), %rdi
	movq	8(%rdi), %rcx
	jmp	.L350
	.p2align 4
.L383:
	movq	(%rdi), %rdx
	testq	%rdx, %rdx
	je	.L348
	movq	8(%rdx), %rcx
	movq	%rdi, %r9
	movq	%rdx, %rdi
	xorl	%edx, %edx
	movq	%rcx, %rax
	divq	%r8
	cmpq	%rdx, %rbx
	jne	.L348
.L350:
	cmpq	$100000001, %rcx
	jne	.L383
	movq	(%r9), %rax
	testq	%rax, %rax
	je	.L348
	addq	$16, %rax
.L351:
	imull	%ebp, %ebp
	movq	%rbp, (%rax)
	movq	q(%rip), %rdx
	testq	%rdx, %rdx
	jle	.L345
	leaq	query(%rip), %rbp
	leaq	ans(%rip), %rbx
	leaq	till(%rip), %r14
	xorl	%r12d, %r12d
	.p2align 4
.L353:
	movq	%r12, %rax
	salq	$5, %rax
	addq	0(%rbp), %rax
	movq	8(%rax), %rsi
	movq	(%rax), %rdi
	movq	16(%rax), %r13
	cmpq	%rdi, %rsi
	jne	.L355
	movq	(%r14,%rsi,8), %rax
	addq	$1, %r12
	cmpq	%rdx, %r12
	movq	%rax, (%rbx,%r13,8)
	jl	.L353
.L356:
	testq	%rdx, %rdx
	jle	.L345
	leaq	-1(%rsp), %r13
	xorl	%r15d, %r15d
	movq	%rsp, %rbp
	movabsq	$7378697629483820647, %r14
	.p2align 4
.L354:
	movq	(%rbx,%r15,8), %rcx
	xorl	%r12d, %r12d
	jmp	.L358
	.p2align 4
.L367:
	movq	%rsi, %r12
.L358:
	movq	%rcx, %rax
	leaq	1(%r12), %rsi
	imulq	%r14
	movq	%rcx, %rax
	sarq	$63, %rax
	sarq	$2, %rdx
	subq	%rax, %rdx
	leaq	(%rdx,%rdx,4), %rax
	addq	%rax, %rax
	subq	%rax, %rcx
	addl	$48, %ecx
	testq	%rdx, %rdx
	movb	%cl, 0(%r13,%rsi)
	movq	%rdx, %rcx
	jne	.L367
	addq	%rbp, %r12
	.p2align 4
.L359:
	movq	stdout(%rip), %rdi
	movzbl	(%r12), %esi
	movq	40(%rdi), %rax
	cmpq	48(%rdi), %rax
	jnb	.L384
	leaq	1(%rax), %rdx
	movq	%rdx, 40(%rdi)
	movb	%sil, (%rax)
.L362:
	subq	$1, %r12
	cmpq	%r12, %r13
	jne	.L359
	movq	stdout(%rip), %rdi
	movq	40(%rdi), %rax
	cmpq	48(%rdi), %rax
	jnb	.L385
	leaq	1(%rax), %rdx
	addq	$1, %r15
	movq	%rdx, 40(%rdi)
	movb	$10, (%rax)
	cmpq	%r15, q(%rip)
	jg	.L354
	jmp	.L345
.L343:
	call	_Z7processv
	call	_Z6answerv
.L345:
	xorl	%eax, %eax
	movq	40(%rsp), %rbx
	xorq	%fs:40, %rbx
	jne	.L386
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
	.p2align 4
.L384:
	.cfi_restore_state
	call	__overflow@PLT
	jmp	.L362
	.p2align 4
.L355:
	call	_Z8get_ans2xx.part.98
	movq	q(%rip), %rdx
	addq	$1, %r12
	movq	%rax, (%rbx,%r13,8)
	cmpq	%rdx, %r12
	jl	.L353
	jmp	.L356
.L385:
	movl	$10, %esi
	addq	$1, %r15
	call	__overflow@PLT
	cmpq	%r15, q(%rip)
	jg	.L354
	jmp	.L345
.L348:
	movl	$24, %edi
	call	_Znwm@PLT
	leaq	cache(%rip), %rdi
	movq	$0, (%rax)
	movq	$100000001, 8(%rax)
	movq	$0, 16(%rax)
	movq	%rax, %rcx
	movl	$100000001, %edx
	movq	%rbx, %rsi
	call	_ZNSt10_HashtableIxSt4pairIKxxESaIS2_ENSt8__detail10_Select1stESt8equal_toIxESt4hashIxENS4_18_Mod_range_hashingENS4_20_Default_ranged_hashENS4_20_Prime_rehash_policyENS4_17_Hashtable_traitsILb0ELb0ELb1EEEE21_M_insert_unique_nodeEmmPNS4_10_Hash_nodeIS2_Lb0EEE
	addq	$16, %rax
	jmp	.L351
.L386:
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE8373:
	.size	main, .-main
	.p2align 4,,15
	.type	_GLOBAL__sub_I_mx_level, @function
_GLOBAL__sub_I_mx_level:
.LFB10081:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	leaq	_ZStL8__ioinit(%rip), %rdi
	leaq	tree(%rip), %rbx
	subq	$24, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	call	_ZNSt8ios_base4InitC1Ev@PLT
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi
	leaq	__dso_handle(%rip), %rdx
	leaq	_ZStL8__ioinit(%rip), %rsi
	leaq	7200024(%rbx), %rbp
	call	__cxa_atexit@PLT
	.p2align 4,,10
	.p2align 3
.L388:
	movq	%rbx, %rdi
	addq	$24, %rbx
	call	_ZNSt6vectorIxSaIxEEC1Ev
	cmpq	%rbp, %rbx
	jne	.L388
	leaq	__dso_handle(%rip), %rdx
	leaq	__tcf_0(%rip), %rdi
	xorl	%esi, %esi
	call	__cxa_atexit@PLT
	leaq	cache(%rip), %rdi
	call	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEEC1Ev
	leaq	__dso_handle(%rip), %rdx
	leaq	cache(%rip), %rsi
	leaq	_ZNSt13unordered_mapIxxSt4hashIxESt8equal_toIxESaISt4pairIKxxEEED1Ev(%rip), %rdi
	call	__cxa_atexit@PLT
	leaq	7(%rsp), %rdx
	leaq	query(%rip), %rdi
	movl	$300001, %esi
	call	_ZNSt6vectorI5QuerySaIS0_EEC1EmRKS1_
	leaq	__dso_handle(%rip), %rdx
	leaq	query(%rip), %rsi
	leaq	_ZNSt6vectorI5QuerySaIS0_EED1Ev(%rip), %rdi
	call	__cxa_atexit@PLT
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L392
	addq	$24, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L392:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE10081:
	.size	_GLOBAL__sub_I_mx_level, .-_GLOBAL__sub_I_mx_level
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_mx_level
	.globl	till
	.bss
	.align 32
	.type	till, @object
	.size	till, 2400008
till:
	.zero	2400008
	.globl	ans
	.align 32
	.type	ans, @object
	.size	ans, 2400008
ans:
	.zero	2400008
	.globl	vis
	.align 32
	.type	vis, @object
	.size	vis, 2400008
vis:
	.zero	2400008
	.globl	level
	.align 32
	.type	level, @object
	.size	level, 2400008
level:
	.zero	2400008
	.globl	par
	.align 32
	.type	par, @object
	.size	par, 2400008
par:
	.zero	2400008
	.globl	w
	.align 32
	.type	w, @object
	.size	w, 2400008
w:
	.zero	2400008
	.globl	query
	.align 16
	.type	query, @object
	.size	query, 24
query:
	.zero	24
	.globl	cache
	.align 32
	.type	cache, @object
	.size	cache, 56
cache:
	.zero	56
	.globl	tree
	.align 32
	.type	tree, @object
	.size	tree, 7200024
tree:
	.zero	7200024
	.globl	q
	.align 8
	.type	q, @object
	.size	q, 8
q:
	.zero	8
	.globl	n
	.align 8
	.type	n, @object
	.size	n, 8
n:
	.zero	8
	.globl	mx_level
	.align 8
	.type	mx_level, @object
	.size	mx_level, 8
mx_level:
	.zero	8
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
