segment .data
	_err_div_0 db "División por 0",0
segment .bss
	__esp resd 1
	x resd 1
	y resd 1
segment .text
	global main
	extern print_int, print_boolean, print_string, print_blank, print_endofline
	extern scan_int, scan_boolean
main:
	MOV DWORD [__esp], ESP
	PUSH DWORD 0
	POP DWORD [x]
	PUSH DWORD 2
	POP DWORD [y]
dowhile_ini_1:
	PUSH DWORD x
	PUSH DWORD y
	POP DWORD ECX
	MOV DWORD EDX, [ECX]
	MOV DWORD EAX, EDX
	POP DWORD ECX
	MOV DWORD EDX, [ECX]
	MOV DWORD EBX, EDX
	ADD EAX, EBX
	PUSH DWORD EAX
	POP DWORD [x]
	PUSH DWORD x
	POP DWORD ECX
	MOV DWORD EDX, [ECX]
	MOV DWORD EAX, EDX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
	PUSH DWORD 10
	PUSH DWORD x
	POP DWORD ECX
	MOV DWORD EDX, [ECX]
	MOV DWORD EAX, EDX
	POP DWORD EBX
	CMP EAX, EBX
	JL es_menor_1
	PUSH DWORD 0
	JMP menor_fin_1
es_menor_1:
	PUSH DWORD 1
menor_fin_1:
	POP DWORD EAX
	CMP EAX, 0
	JE dowhile_fin_1
	JMP dowhile_ini_1
dowhile_fin_1:
fin:
	MOV DWORD ESP, [__esp]
	ret
div_0:
	PUSH DWORD _err_div_0
	CALL print_string
	ADD ESP, 4
	JMP fin
