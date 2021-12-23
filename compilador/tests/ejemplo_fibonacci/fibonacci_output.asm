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
;D:	resultado
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
;R:	<escritura_TS>:
segment .bss
	__esp resd 1
	_x resd 1
	_resultado resd 1
segment .data
	_err_div_0 db "División por 0",0
	_err_indice_fuera_rango db "Indice fuera de rango",0
segment .text
	global main
	extern print_int, print_boolean, print_string, print_blank, print_endofline
	extern scan_int, scan_boolean
;D:	int
;R10:	<tipo> ::= int
;D:	fibonacci
;R:	<fn_name> ::= function <tipo> TOK_IDENTIFICADOR
;D:	(
;D:	int
;R10:	<tipo> ::= int
;D:	num1
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <tipo> <idpf>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	res1
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	res2
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	if
;R2:	<declaraciones> ::= <declaracion>
;R28:	<declaraciones_funcion> ::= <declaraciones>
;R:	<fn_declaration> ::= <fn_name> ( <parametros> ) { <declaraciones_funcion>
fibonacci:
	PUSH DWORD EBP
	MOV DWORD EBP, ESP
	SUB ESP, 0
;D:	(
;D:	(
;D:	num1
;D:	==
;R80:	<exp> ::= TOK_IDENTIFICADOR
	PUSH DWORD _num1
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
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
;D:	)
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_2
;D:	return
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
	PUSH DWORD 0
;D:	;
;R61:	<retorno_funcion> ::= return <exp>
	POP DWORD EAX
	MOV DWORD ESP, EBP
	POP DWORD EBP
	ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	if
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_2:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	(
;D:	(
;D:	num1
;D:	==
;R80:	<exp> ::= TOK_IDENTIFICADOR
	PUSH DWORD _num1
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
	PUSH DWORD 1
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
;D:	{
;R:	<if_exp> ::= if ( <exp> ) {
	POP DWORD EAX
	CMP EAX, 0
	JE NEAR fin_then_4
;D:	return
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
	PUSH DWORD 1
;D:	;
;R61:	<retorno_funcion> ::= return <exp>
	POP DWORD EAX
	MOV DWORD ESP, EBP
	POP DWORD EBP
	ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;D:	res1
;R50:	<condicional> ::= if ( <exp> ) { <sentencias> }
fin_then_4:
;R40:	<bloque> ::= <condicional>
;R33:	<sentencia> ::= <bloque>
;D:	=
;D:	fibonacci
;D:	(
;R:	<idf_llamada_funcion> ::= TOK_IDENTIFICADOR
;D:	num1
;D:	-
;R80:	<exp> ::= TOK_IDENTIFICADOR
	LEA EAX, [EBP + 4]
	PUSH DWORD EAX
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
	PUSH DWORD 1
;D:	)
;R73:	<exp> ::= <exp> - <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	SUB EAX, EBX
	PUSH DWORD EAX
;R92:	<resto_lista_expresiones> ::= 
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <idf_llamada_funcion> ( <lista_expresiones> )
