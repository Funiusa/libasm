global	_ft_write
	extern	___error
	section	.text
					; rdi, rsi, rdx
					; fd, cbuf, nbyte
_ft_write:
	mov		rax, 0x2000004 ; write
	syscall
	jc		if_error
	ret
if_error:
	push	rax
	call	___error
	pop		r12
	mov		[rax], r12
	mov		rax, -1
ret
