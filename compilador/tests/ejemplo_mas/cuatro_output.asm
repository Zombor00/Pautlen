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
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	a
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	x
;R2:	<declaraciones> ::= <declaracion>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
;R:	<escritura_TS>:
segment .bss
	__esp resd 1
	_a resd 1
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
;D:	13
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 13
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_x], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	y
;D:	=
;D:	54
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 54
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_y], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	a
;D:	=
;D:	(
;D:	x
;D:	<
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	y
;D:	)
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;R97:	<comparacion> ::= <exp> < <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JL es_menor_1
	PUSH DWORD 0
	JMP menor_fin_1
es_menor_1:
	PUSH DWORD 1
menor_fin_1:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_a], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _a
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
;D:	a
;D:	=
;D:	(
;D:	x
;D:	<=
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	y
;D:	)
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;R95:	<comparacion> ::= <exp> <= <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JLE es_menor_igual_2
	PUSH DWORD 0
	JMP menor_igual_fin_2
es_menor_igual_2:
	PUSH DWORD 1
menor_igual_fin_2:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_a], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _a
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
;D:	a
;D:	=
;D:	(
;D:	x
;D:	!=
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	y
;D:	)
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;R94:	<comparacion> ::= <exp> != <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JNE es_distinto_3
	PUSH DWORD 0
	JMP distinto_fin_3
es_distinto_3:
	PUSH DWORD 1
distinto_fin_3:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_a], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _a
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
;D:	a
;D:	=
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	y
;D:	)
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;R98:	<comparacion> ::= <exp> > <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JG es_mayor_4
	PUSH DWORD 0
	JMP mayor_fin_4
es_mayor_4:
	PUSH DWORD 1
mayor_fin_4:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_a], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _a
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
;D:	a
;D:	=
;D:	(
;D:	x
;D:	>=
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	y
;D:	)
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;R96:	<comparacion> ::= <exp> >= <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JGE es_mayor_igual_5
	PUSH DWORD 0
	JMP mayor_igual_fin_5
es_mayor_igual_5:
	PUSH DWORD 1
mayor_igual_fin_5:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_a], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _a
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
;D:	a
;D:	=
;D:	(
;D:	x
;D:	==
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	y
;D:	)
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;R93:	<comparacion> ::= <exp> == <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JE es_igual_6
	PUSH DWORD 0
	JMP igual_fin_6
es_igual_6:
	PUSH DWORD 1
igual_fin_6:
;R83:	<exp> ::= ( <comparacion> )
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_a], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	a
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _a
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
