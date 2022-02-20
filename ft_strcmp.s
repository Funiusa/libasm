global _ft_strcmp
		
		section		.text

_ft_strcmp:
			mov		rax, 0
			mov		rdx, 0
			mov		r11, 0
	in_loop:
			mov		dl, byte [rsi + r11]
			mov		al, byte [rdi + r11]
			cmp		dl, 0
			je		_end
			cmp		al, 0
			je		_end
			cmp		al, dl
			jne		_end
			inc		r11
			jmp		in_loop
	_end:
		sub		rax, rdx
		ret
