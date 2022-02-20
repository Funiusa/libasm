extern ___error
global _ft_read
	
	section .text
					; rdi, rsi, rdx
					; fd, *buffer, nbyte
_ft_read:
	mov		rax, 0x2000003 ; read
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
