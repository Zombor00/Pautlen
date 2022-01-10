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
;D:	array
;D:	int
;R10:	<tipo> ::= int
;D:	[
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;D:	]
;R15:	<clase_vector> ::= array <tipo> [ <constante_entera> ]
;R7:	<clase> ::= <clase_vector>
;D:	z
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	f
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
;D:	function
;R2:	<declaraciones> ::= <declaracion>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
;R:	<escritura_TS>:
segment .bss
	__esp resd 1
	_a resd 1
	_b resd 1
	_c resd 1
	_f resd 3
	_w resd 1
	_x resd 1
	_y resd 1
	_z resd 3
segment .data
	_err_div_0 db "****Error de ejecucion: División por 0",0
	_err_indice_fuera_rango db "****Error de ejecucion: Indice fuera de rango",0
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
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	num1
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <clase> <idpf>
;D:	;
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	num2
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <clase> <idpf>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	return
;R29:	<declaraciones_funcion> ::= 
;R:	<fn_declaration> ::= <fn_name> ( <parametros> ) { <declaraciones_funcion>
; declararFuncion:
suma:
	PUSH DWORD EBP
	MOV DWORD EBP, ESP
	SUB ESP, 0
;D:	num1
;D:	+
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribirParametro:
	LEA EAX, [EBP + 12]
	PUSH DWORD EAX
;D:	num2
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribirParametro:
	LEA EAX, [EBP + 8]
	PUSH DWORD EAX
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
	POP DWORD EAX
	MOV DWORD ESP, EBP
	POP DWORD EBP
	ret
;R38:	<sentencia_simple> ::= <retorno_funcion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
;R22:	<funcion> ::=  <fn_declaration> <sentencias> }
;D:	function
;D:	int
;R10:	<tipo> ::= int
;D:	suma2
;R:	<fn_name> ::= function <tipo> TOK_IDENTIFICADOR
;D:	(
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	num1
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <clase> <idpf>
;D:	;
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	num2
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <clase> <idpf>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	return
;R29:	<declaraciones_funcion> ::= 
;R:	<fn_declaration> ::= <fn_name> ( <parametros> ) { <declaraciones_funcion>
; declararFuncion:
suma2:
	PUSH DWORD EBP
	MOV DWORD EBP, ESP
	SUB ESP, 0
;D:	num1
;D:	+
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribirParametro:
	LEA EAX, [EBP + 12]
	PUSH DWORD EAX
;D:	num2
;D:	+
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribirParametro:
	LEA EAX, [EBP + 8]
	PUSH DWORD EAX
;R72:	<exp> ::= <exp> + <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	ADD EAX, EBX
	PUSH DWORD EAX
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 1
;D:	;
;R72:	<exp> ::= <exp> + <exp>
	POP DWORD EBX
	POP DWORD EAX
	ADD EAX, EBX
	PUSH DWORD EAX
;R61:	<retorno_funcion> ::= return <exp>
	POP DWORD EAX
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
;R20:	<funciones> ::= <funcion> <funciones>
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
;D:	return
;D:	4
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 4
;D:	;
;R61:	<retorno_funcion> ::= return <exp>
