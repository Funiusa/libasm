global _ft_strcpy		
	section .text

_ft_strcpy:
	mov rax, 0
in_loop:
	cmp		byte [rsi + rax], 0
	je 		.exit
	mov		dl, byte[rsi + rax]
	mov		byte[rdi + rax], dl
	inc		rax
	jmp		in_loop
.exit:
	mov		byte[rdi + rax], 0
	mov		rax, rdi
ret