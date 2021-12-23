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
;D:	resultado
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R19:	<identificadores> ::= <identificador> , <identificadores>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
;R:	<escritura_TS>:
segment .bss
	__esp resd 1
	_x resd 1
	_y resd 1
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
;D:	suma
;R:	<fn_name> ::= function <tipo> TOK_IDENTIFICADOR
;D:	(
;D:	int
;R10:	<tipo> ::= int
;D:	num1
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <tipo> <idpf>
;D:	;
;D:	int
;R10:	<tipo> ::= int
;D:	num2
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <tipo> <idpf>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	return
;R29:	<declaraciones_funcion> ::= 
;R:	<fn_declaration> ::= <fn_name> ( <parametros> ) { <declaraciones_funcion>
suma:
	PUSH DWORD EBP
	MOV DWORD EBP, ESP
	SUB ESP, 0
;D:	num1
;D:	+
;R80:	<exp> ::= TOK_IDENTIFICADOR
	PUSH DWORD _num1
;D:	num2
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
	PUSH DWORD _num2
;R72:	<exp> ::= <exp> + <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	ADD EAX, EBX
	PUSH DWORD EAX
;R61:	<retorno_funcion> ::= return <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	MOV DWORD ESP, EBP
	POP DWORD EBP
	ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R22:	<funcion> ::=  <fn_declaration> <sentencias> }
;D:	x
;R21:	<funciones> ::= 
;R20:	<funciones> ::= <funcion> <funciones>
;R:	<escritura_main>:
main:
	MOV DWORD [__esp], ESP
;D:	=
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
	PUSH DWORD 1
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
	POP DWORD [_x]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	y
;D:	=
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
	PUSH DWORD 3
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
	POP DWORD [_y]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	resultado
;D:	=
;D:	suma
;D:	(
;R:	<idf_llamada_funcion> ::= TOK_IDENTIFICADOR
;D:	x
;D:	,
;R80:	<exp> ::= TOK_IDENTIFICADOR
	LEA EAX, [EBP + 4]
	PUSH DWORD EAX
;D:	y
;D:	)
;R80:	<exp> ::= TOK_IDENTIFICADOR
	LEA EAX, [EBP + 4]
	PUSH DWORD EAX
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <idf_llamada_funcion> ( <lista_expresiones> )
	CALL suma
	ADD ESP, 8
	PUSH DWORD EAX
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
	POP DWORD [_resultado]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
	PUSH DWORD _resultado
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
;D:	resultado
;D:	=
;D:	suma
;D:	(
;R:	<idf_llamada_funcion> ::= TOK_IDENTIFICADOR
;D:	x
;D:	,
;R80:	<exp> ::= TOK_IDENTIFICADOR
	LEA EAX, [EBP + 4]
	PUSH DWORD EAX
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
	PUSH DWORD 1
;D:	)
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <idf_llamada_funcion> ( <lista_expresiones> )
	CALL suma
	ADD ESP, 8
	PUSH DWORD EAX
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
	POP DWORD [_resultado]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
	PUSH DWORD _resultado
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
;D:	resultado
;D:	=
;D:	suma
;D:	(
;R:	<idf_llamada_funcion> ::= TOK_IDENTIFICADOR
;D:	10
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
	PUSH DWORD 10
;D:	,
;D:	y
;D:	)
;R80:	<exp> ::= TOK_IDENTIFICADOR
	LEA EAX, [EBP + 4]
	PUSH DWORD EAX
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <idf_llamada_funcion> ( <lista_expresiones> )
	CALL suma
	ADD ESP, 8
	PUSH DWORD EAX
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
	POP DWORD [_resultado]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
	PUSH DWORD _resultado
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
;D:	resultado
;D:	=
;D:	suma
;D:	(
;R:	<idf_llamada_funcion> ::= TOK_IDENTIFICADOR
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
	PUSH DWORD 3
;D:	,
;D:	5
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
	PUSH DWORD 5
;D:	)
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <idf_llamada_funcion> ( <lista_expresiones> )
	CALL suma
	ADD ESP, 8
	PUSH DWORD EAX
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
	POP DWORD [_resultado]
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
	PUSH DWORD _resultado
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
