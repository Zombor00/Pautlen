;D:	main
;D:	{
;D:	int
;D:	x
;D:	,
;D:	y
;D:	,
;D:	z
;D:	;
;D:	scanf
segment .bss
	__esp resd 1
	_x resd 1
	_y resd 1
	_z resd 1
segment .data
	_err_div_0 db "División por 0",0
	_err_indice_fuera_rango db "Indice fuera de rango",0
segment .text
	global main
	extern print_int, print_boolean, print_string, print_blank, print_endofline
	extern scan_int, scan_boolean
main:
	MOV DWORD [__esp], ESP
;D:	x
	PUSH DWORD _x
	CALL scan_int
	ADD ESP, 4
;D:	;
;D:	scanf
;D:	y
	PUSH DWORD _y
	CALL scan_int
	ADD ESP, 4
;D:	;
;D:	scanf
;D:	z
