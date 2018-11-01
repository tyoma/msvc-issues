IF _M_IX86
	.586
	.model flat
	.code

	__penter	proc
		push eax
		mov eax, 1h
		test eax, eax
		pop eax
		ret
	__penter	endp

	__pexit	proc
		push eax
		mov eax, 1h
		test eax, eax
		pop eax
		ret
	__pexit	endp

ELSEIF _M_X64
	.code

	_penter	proc
		push rax
		mov rax, 1h
		test rax, rax
		pop rax
		ret
	_penter	endp

	_pexit	proc
		push rax
		mov rax, 1h
		test rax, rax
		pop rax
		ret
	_pexit	endp
ENDIF

end
