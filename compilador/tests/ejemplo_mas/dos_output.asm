;R:	<inicioTabla>:
;D:	main
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	x
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	y
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	w
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	a
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	b
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	c
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	x
;R2:	<declaraciones> ::= <declaracion>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
;R:	<escritura_TS>:
segment .bss
	__esp resd 1
	_a resd 1
	_b resd 1
	_c resd 1
	_w resd 1
	_x resd 1
	_y resd 1
segment .data
	_err_div_0 db "División por 0",0
	_err_indice_fuera_rango db "Indice fuera de rango",0
segment .text
	global main
	extern print_int, print_boolean, print_string, print_blank, print_endofline
	extern scan_int, scan_boolean
;R21:	<funciones> ::= 
;R:	<escritura_main>:
main:
	MOV DWORD [__esp], ESP
;D:	=
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 3
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_x], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	y
;D:	=
;D:	x
;D:	*
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 2
;R75:	<exp> ::= <exp> * <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	IMUL DWORD EBX
	PUSH DWORD EAX
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_y], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	w
;D:	=
;D:	x
;D:	/
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	y
;D:	+
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;R74:	<exp> ::= <exp> / <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EBX, 0
	JE div_0
	CDQ
	IDIV EBX
	PUSH DWORD EAX
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 3
;D:	*
;D:	x
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;R75:	<exp> ::= <exp> * <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD EAX
	IMUL DWORD EBX
	PUSH DWORD EAX
;R72:	<exp> ::= <exp> + <exp>
	POP DWORD EBX
	POP DWORD EAX
	ADD EAX, EBX
	PUSH DWORD EAX
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_w], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	w
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _w
;R56:	<escritura> ::= printf <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	a
;D:	=
;D:	true
;R102:	<constante_logica> ::= true
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 1
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_a], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	b
;D:	=
;D:	false
;R103:	<constante_logica> ::= false
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	||
;D:	a
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _a
;R78:	<exp> ::= <exp> || <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD EAX
	OR EAX, EBX
	PUSH DWORD EAX
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_b], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	c
;D:	=
;D:	a
;D:	&&
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _a
;D:	(
;D:	b
;D:	||
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _b
;D:	false
;R103:	<constante_logica> ::= false
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R78:	<exp> ::= <exp> || <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	OR EAX, EBX
	PUSH DWORD EAX
;R82:	<exp> ::= ( <exp> )
; escribir_operando:
	PUSH DWORD 1
;D:	||
;R77:	<exp> ::= <exp> && <exp>
;mm 1 0
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	AND EAX, EBX
	PUSH DWORD EAX
;D:	false
;R103:	<constante_logica> ::= false
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	;
;R78:	<exp> ::= <exp> || <exp>
	POP DWORD EBX
	POP DWORD EAX
	OR EAX, EBX
	PUSH DWORD EAX
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_c], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	c
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _c
;R56:	<escritura> ::= printf <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	PUSH DWORD EAX
	CALL print_boolean
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R1:	<programa> ::= <inicioTabla> main { <declaraciones> <escritura_TS> <funciones> <escritura_main> <sentencias> }
fin:
	MOV DWORD ESP, [__esp]
	ret
div_0:
	PUSH DWORD _err_div_0
	CALL print_string
	ADD ESP, 4
	CALL print_endofline
	JMP fin
fin_indice_fuera_rango:
	PUSH DWORD _err_indice_fuera_rango
	CALL print_string
	ADD ESP, 4
	CALL print_endofline
	JMP fin
