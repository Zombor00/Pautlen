;R:	<inicioTabla>:
;D:	main
;D:	{
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	w
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	z
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
;D:	array
;D:	int
;R10:	<tipo> ::= int
;D:	[
;D:	30
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;D:	]
;R15:	<clase_vector> ::= array <tipo> [ <constante_entera> ]
;R7:	<clase> ::= <clase_vector>
;D:	x
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	,
;D:	y
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
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
	_w resd 1
	_x resd 30
	_y resd 30
	_z resd 1
segment .data
	_err_div_0 db "División por 0",0
	_err_indice_fuera_rango db "Indice fuera de rango",0
segment .text
	global main
	extern print_int, print_boolean, print_string, print_blank, print_endofline
	extern scan_int, scan_boolean
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
;D:	suma
;R:	<fn_name> ::= function <tipo> TOK_IDENTIFICADOR
;D:	(
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	z
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <clase> <idpf>
;D:	;
;D:	int
;R10:	<tipo> ::= int
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	w
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <clase> <idpf>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	x
;R29:	<declaraciones_funcion> ::= 
;R:	<fn_declaration> ::= <fn_name> ( <parametros> ) { <declaraciones_funcion>
; declararFuncion:
suma:
	PUSH DWORD EBP
	MOV DWORD EBP, ESP
	SUB ESP, 0
;D:	[
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 2
;D:	]
;R48:	<elemento_vector> ::= TOK_IDENTIFICADOR [ <exp> ]
; escribir_elemento_vector:
	POP DWORD EAX
	CMP EAX, 0
	JL NEAR fin_indice_fuera_rango
	CMP EAX, 29
	JG NEAR fin_indice_fuera_rango
	MOV DWORD EDX, _x
	LEA EAX, [EDX + EAX*4]
	PUSH DWORD EAX
;D:	=
;D:	w
;D:	+
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribirParametro:
	LEA EAX, [EBP + 8]
	PUSH DWORD EAX
;D:	6
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 6
;D:	/
;D:	(
;D:	z
;D:	+
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribirParametro:
	LEA EAX, [EBP + 12]
	PUSH DWORD EAX
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 2
;D:	)
;R72:	<exp> ::= <exp> + <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	ADD EAX, EBX
	PUSH DWORD EAX
;R82:	<exp> ::= ( <exp> )
;R74:	<exp> ::= <exp> / <exp>
	POP DWORD EBX
	POP DWORD EAX
	CMP EBX, 0
	JE div_0
	CDQ
	IDIV EBX
	PUSH DWORD EAX
;D:	;
;R72:	<exp> ::= <exp> + <exp>
	POP DWORD EBX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	ADD EAX, EBX
	PUSH DWORD EAX
;R44:	<asignacion> ::= <elemento_vector> = <exp>
; asignarDestinoEnPilaVector:
	POP DWORD EBX
	POP DWORD EAX
	MOV DWORD [EAX], EBX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	x
;D:	[
;D:	2
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 2
;D:	]
;R48:	<elemento_vector> ::= TOK_IDENTIFICADOR [ <exp> ]
; escribir_elemento_vector:
	POP DWORD EAX
	CMP EAX, 0
	JL NEAR fin_indice_fuera_rango
	CMP EAX, 29
	JG NEAR fin_indice_fuera_rango
	MOV DWORD EDX, _x
	LEA EAX, [EDX + EAX*4]
	PUSH DWORD EAX
;R85:	<exp> ::= <elemento_vector>
;D:	;
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
;D:	return
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
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
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R22:	<funcion> ::=  <fn_declaration> <sentencias> }
;D:	w
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
	MOV DWORD [_w], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	z
;D:	=
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 1
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_z], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	w
;D:	=
;D:	suma
;D:	(
;R:	<idf_llamada_funcion> ::= TOK_IDENTIFICADOR
;D:	z
;D:	,
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _z
; operandoEnPilaAArgumento:
	POP DWORD EAX
	MOV DWORD EAX, [EAX]
	PUSH DWORD EAX
;D:	w
;D:	)
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _w
; operandoEnPilaAArgumento:
	POP DWORD EAX
	MOV DWORD EAX, [EAX]
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
; asignar:
	POP DWORD ECX
	MOV DWORD [_w], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	}
;R30:	<sentencias> ::= <sentencia>
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
