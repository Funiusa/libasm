global	_ft_strdup
	extern	_malloc
	extern	_ft_strlen
	extern 	_ft_strcpy
	extern	___error
	section	.text
					; rdi rsi
					; str
_ft_strdup:
	push	rdi
	call	_ft_strlen
	inc		rax
	mov		rdi, rax
	call	_malloc
	cmp 	rax, 0
	jc		.error
	pop		rsi
	mov		rdi, rax
	call	_ft_strcpy
ret

	.error:
		push rax
		call ___error
		mov byte [rax], 12
		pop rax
		ret

