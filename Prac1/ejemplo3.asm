segment .data
	_err_div_0 db "División por 0",0
	_err_indice_fuera_rango db "Indice fuera de rango",0
segment .bss
	__esp resd 1
	x resd 1
	y resd 1
	z resd 1
	j resd 1
segment .text
	global main
	extern print_int, print_boolean, print_string, print_blank, print_endofline
	extern scan_int, scan_boolean
main:
	MOV DWORD [__esp], ESP
	PUSH DWORD x
	CALL scan_int
	ADD ESP, 4
	PUSH DWORD z
	CALL scan_int
	ADD ESP, 4
	PUSH DWORD x
	POP DWORD ECX
	MOV DWORD EDX, [ECX]
	MOV DWORD EAX, EDX
	NEG EAX
	PUSH DWORD EAX
	POP DWORD [j]
	PUSH DWORD j
	POP DWORD ECX
	MOV DWORD EDX, [ECX]
	MOV DWORD EAX, EDX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
	PUSH DWORD x
	PUSH DWORD z
	POP DWORD ECX
	MOV DWORD EDX, [ECX]
	MOV DWORD EBX, EDX
	POP DWORD ECX
	MOV DWORD EDX, [ECX]
	MOV DWORD EAX, EDX
	SUB EAX, EBX
	PUSH DWORD EAX
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
	PUSH DWORD x
	PUSH DWORD 2
	POP DWORD EBX
	POP DWORD EAX

mov EAX, DWORD [EAX]
	CMP EBX, 0
	JE div_0
	CDQ
	IDIV EBX
	PUSH DWORD EAX
	POP DWORD [y]
	PUSH DWORD y
	POP DWORD ECX
	MOV DWORD EDX, [ECX]
	MOV DWORD EAX, EDX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
	PUSH DWORD x
	PUSH DWORD y
	POP DWORD EBX
	POP DWORD EAX

MOV EAX, [EAX]

MOV EBX, DWORD [EBX]
	IMUL DWORD EBX
	PUSH DWORD EAX
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
fin:
	MOV DWORD ESP, [__esp]
	ret
div_0:
	PUSH DWORD _err_div_0
	CALL print_string
	ADD ESP, 4
	JMP fin
fin_indice_fuera_rango:
	PUSH DWORD _err_indice_fuera_rango
	CALL print_string
	ADD ESP, 4
	JMP fin
