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
;D:	r
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	array
;D:	int
;R10:	<tipo> ::= int
;D:	[
;D:	44
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;D:	]
;R15:	<clase_vector> ::= array <tipo> [ <constante_entera> ]
;R7:	<clase> ::= <clase_vector>
;D:	a
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	b
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	array
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	[
;D:	32
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;D:	]
;R15:	<clase_vector> ::= array <tipo> [ <constante_entera> ]
;R7:	<clase> ::= <clase_vector>
;D:	c
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	}
;R2:	<declaraciones> ::= <declaracion>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
;R:	<escritura_TS>:
segment .bss
	__esp resd 1
	_a resd 44
	_b resd 44
	_c resd 32
	_r resd 1
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
