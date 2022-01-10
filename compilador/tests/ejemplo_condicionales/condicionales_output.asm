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
;D:	z
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	scanf
;R2:	<declaraciones> ::= <declaracion>
;R:	<escritura_TS>:
segment .bss
	__esp resd 1
	_x resd 1
	_y resd 1
	_z resd 1
segment .data
	_err_div_0 db "****Error de ejecucion: División por 0",0
	_err_indice_fuera_rango db "****Error de ejecucion: Indice fuera de rango",0
segment .text
	global main
	extern print_int, print_boolean, print_string, print_blank, print_endofline
	extern scan_int, scan_boolean
;R21:	<funciones> ::= 
;R:	<escritura_main>:
main:
	MOV DWORD [__esp], ESP
;D:	x
;R54:	<lectura> ::= scanf TOK_IDENTIFICADOR
	PUSH DWORD _x
	CALL scan_int
	ADD ESP, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	y
;R54:	<lectura> ::= scanf TOK_IDENTIFICADOR
	PUSH DWORD _y
	CALL scan_int
	ADD ESP, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	scanf
;D:	z
;R54:	<lectura> ::= scanf TOK_IDENTIFICADOR
	PUSH DWORD _z
	CALL scan_int
	ADD ESP, 4
;R35:	<sentencia_simple> ::= <lectura>
;D:	;
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	if
;D:	(
;D:	(
;D:	x
;D:	==
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JE es_igual_1
	PUSH DWORD 0
	JMP igual_fin_1
es_igual_1:
	PUSH DWORD 1
igual_fin_1:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	==
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JE es_igual_2
	PUSH DWORD 0
	JMP igual_fin_2
es_igual_2:
	PUSH DWORD 1
igual_fin_2:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;R77:	<exp> ::= <exp> && <exp>
;mm 0 0
	POP DWORD EBX
	POP DWORD EAX
	AND EAX, EBX
	PUSH DWORD EAX
;D:	(
;D:	z
;D:	==
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R93:	<comparacion> ::= <exp> == <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JE es_igual_3
	PUSH DWORD 0
	JMP igual_fin_3
es_igual_3:
	PUSH DWORD 1
igual_fin_3:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;R77:	<exp> ::= <exp> && <exp>
;mm 0 0
	POP DWORD EBX
	POP DWORD EAX
	AND EAX, EBX
	PUSH DWORD EAX
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_4
;D:	printf
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	;
;R56:	<escritura> ::= printf <exp>
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
;R:	<if_exp_sentencias> ::= <if_exp> <sentencias> }
	JMP NEAR ifthenelse_fin_4
fin_then_4:
;D:	{
;D:	if
;D:	(
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JG es_mayor_5
	PUSH DWORD 0
	JMP mayor_fin_5
es_mayor_5:
	PUSH DWORD 1
mayor_fin_5:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	>
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JG es_mayor_6
	PUSH DWORD 0
	JMP mayor_fin_6
es_mayor_6:
	PUSH DWORD 1
mayor_fin_6:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;R77:	<exp> ::= <exp> && <exp>
;mm 0 0
	POP DWORD EBX
	POP DWORD EAX
	AND EAX, EBX
	PUSH DWORD EAX
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_7
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JG es_mayor_8
	PUSH DWORD 0
	JMP mayor_fin_8
es_mayor_8:
	PUSH DWORD 1
mayor_fin_8:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_9
;D:	printf
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 1
;D:	;
;R56:	<escritura> ::= printf <exp>
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
;R:	<if_exp_sentencias> ::= <if_exp> <sentencias> }
	JMP NEAR ifthenelse_fin_9
fin_then_9:
;D:	{
;D:	printf
;D:	5
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 5
;D:	;
;R56:	<escritura> ::= printf <exp>
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
ifthenelse_fin_9:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_7:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JL es_menor_10
	PUSH DWORD 0
	JMP menor_fin_10
es_menor_10:
	PUSH DWORD 1
menor_fin_10:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	>
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JG es_mayor_11
	PUSH DWORD 0
	JMP mayor_fin_11
es_mayor_11:
	PUSH DWORD 1
mayor_fin_11:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;R77:	<exp> ::= <exp> && <exp>
;mm 0 0
	POP DWORD EBX
	POP DWORD EAX
	AND EAX, EBX
	PUSH DWORD EAX
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_12
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JG es_mayor_13
	PUSH DWORD 0
	JMP mayor_fin_13
es_mayor_13:
	PUSH DWORD 1
mayor_fin_13:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_14
;D:	printf
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 2
;D:	;
;R56:	<escritura> ::= printf <exp>
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
;R:	<if_exp_sentencias> ::= <if_exp> <sentencias> }
	JMP NEAR ifthenelse_fin_14
fin_then_14:
;D:	{
;D:	printf
;D:	6
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 6
;D:	;
;R56:	<escritura> ::= printf <exp>
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
ifthenelse_fin_14:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_12:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	<
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JL es_menor_15
	PUSH DWORD 0
	JMP menor_fin_15
es_menor_15:
	PUSH DWORD 1
menor_fin_15:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	<
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JL es_menor_16
	PUSH DWORD 0
	JMP menor_fin_16
es_menor_16:
	PUSH DWORD 1
menor_fin_16:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;R77:	<exp> ::= <exp> && <exp>
;mm 0 0
	POP DWORD EBX
	POP DWORD EAX
	AND EAX, EBX
	PUSH DWORD EAX
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_17
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JG es_mayor_18
	PUSH DWORD 0
	JMP mayor_fin_18
es_mayor_18:
	PUSH DWORD 1
mayor_fin_18:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_19
;D:	printf
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 3
;D:	;
;R56:	<escritura> ::= printf <exp>
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
;R:	<if_exp_sentencias> ::= <if_exp> <sentencias> }
	JMP NEAR ifthenelse_fin_19
fin_then_19:
;D:	{
;D:	printf
;D:	7
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 7
;D:	;
;R56:	<escritura> ::= printf <exp>
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
ifthenelse_fin_19:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_17:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	x
;D:	>
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _x
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JG es_mayor_20
	PUSH DWORD 0
	JMP mayor_fin_20
es_mayor_20:
	PUSH DWORD 1
mayor_fin_20:
;R83:	<exp> ::= ( <comparacion> )
;D:	&&
;D:	(
;D:	y
;D:	<
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _y
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R97:	<comparacion> ::= <exp> < <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JL es_menor_21
	PUSH DWORD 0
	JMP menor_fin_21
es_menor_21:
	PUSH DWORD 1
menor_fin_21:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;R77:	<exp> ::= <exp> && <exp>
;mm 0 0
	POP DWORD EBX
	POP DWORD EAX
	AND EAX, EBX
	PUSH DWORD EAX
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_22
;D:	if
;D:	(
;D:	(
;D:	z
;D:	>
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _z
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	)
;R98:	<comparacion> ::= <exp> > <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	CMP EAX, EBX
	JG es_mayor_23
	PUSH DWORD 0
	JMP mayor_fin_23
es_mayor_23:
	PUSH DWORD 1
mayor_fin_23:
;R83:	<exp> ::= ( <comparacion> )
;D:	)
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_24
;D:	printf
;D:	4
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 4
;D:	;
;R56:	<escritura> ::= printf <exp>
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	else
;R:	<if_exp_sentencias> ::= <if_exp> <sentencias> }
	JMP NEAR ifthenelse_fin_24
fin_then_24:
;D:	{
;D:	printf
;D:	8
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 8
;D:	;
;R56:	<escritura> ::= printf <exp>
	POP DWORD EAX
	PUSH DWORD EAX
	CALL print_int
	CALL print_endofline
	ADD ESP, 4
;R36:	<sentencia_simple> ::= <escritura>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
ifthenelse_fin_24:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	}
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_22:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;R30:	<sentencias> ::= <sentencia>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R51:	<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }
ifthenelse_fin_4:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	}
;R30:	<sentencias> ::= <sentencia>
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
