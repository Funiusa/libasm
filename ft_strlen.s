global		_ft_strlen
	section	.text
		
_ft_strlen:
	mov		rax, 0
in_loop:			
	cmp		byte [rdi + rax], 0
	je 		.exit
	inc		rax
	jmp		in_loop
.exit:
	ret
