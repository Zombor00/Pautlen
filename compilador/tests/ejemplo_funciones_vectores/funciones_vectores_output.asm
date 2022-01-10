;R:	<inicioTabla>:
;D:	main
;D:	{
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	resultado
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	array
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	[
;D:	3
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;D:	]
;R15:	<clase_vector> ::= array <tipo> [ <constante_entera> ]
;R7:	<clase> ::= <clase_vector>
;D:	vector
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	function
;R2:	<declaraciones> ::= <declaracion>
;R3:	<declaraciones> ::= <declaracion> <declaraciones>
;R:	<escritura_TS>:
segment .bss
	__esp resd 1
	_resultado resd 1
	_vector resd 3
segment .data
	_err_div_0 db "****Error de ejecucion: División por 0",0
	_err_indice_fuera_rango db "****Error de ejecucion: Indice fuera de rango",0
segment .text
	global main
	extern print_int, print_boolean, print_string, print_blank, print_endofline
	extern scan_int, scan_boolean
;D:	boolean
;R11:	<tipo> ::= boolean
;D:	or
;R:	<fn_name> ::= function <tipo> TOK_IDENTIFICADOR
;D:	(
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	b1
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <clase> <idpf>
;D:	;
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	b2
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <clase> <idpf>
;D:	;
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	b3
;R:	<idpf> ::= TOK_IDENTIFICADOR
;R27:	<parametro_funcion> ::= <clase> <idpf>
;D:	)
;R26:	<resto_parametros_funcion> ::= 
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R25:	<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>
;R23:	<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>
;D:	{
;D:	boolean
;R11:	<tipo> ::= boolean
;R9:	<clase_escalar> ::= <tipo>
;R5:	<clase> ::= <clase_escalar>
;D:	a
;R108:	<identificador> ::= TOK_IDENTIFICADOR
;D:	;
;R18:	<identificadores> ::= <identificador>
;R4:	<declaracion> ::= <clase> <identificadores> ;
;D:	a
;R2:	<declaraciones> ::= <declaracion>
;R28:	<declaraciones_funcion> ::= <declaraciones>
;R:	<fn_declaration> ::= <fn_name> ( <parametros> ) { <declaraciones_funcion>
; declararFuncion:
or:
	PUSH DWORD EBP
	MOV DWORD EBP, ESP
	SUB ESP, 4
;D:	=
;D:	b1
;D:	||
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribirParametro:
	LEA EAX, [EBP + 16]
	PUSH DWORD EAX
;D:	b2
;D:	||
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribirParametro:
	LEA EAX, [EBP + 12]
	PUSH DWORD EAX
;R78:	<exp> ::= <exp> || <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EAX, ECX
	OR EAX, EBX
	PUSH DWORD EAX
;D:	b3
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribirParametro:
	LEA EAX, [EBP + 8]
	PUSH DWORD EAX
;R78:	<exp> ::= <exp> || <exp>
	POP DWORD ECX
	MOV DWORD ECX, [ECX]
	MOV DWORD EBX, ECX
	POP DWORD EAX
	OR EAX, EBX
	PUSH DWORD EAX
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; escribirVariableLocal:
	LEA EAX, [EBP - 4]
	PUSH DWORD EAX
; asignarDestinoEnPila:
	POP DWORD EAX
	POP DWORD EBX
	MOV DWORD [EAX], EBX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	return
;D:	a
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribirVariableLocal:
	LEA EAX, [EBP - 4]
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
;R31:	<sentencias> ::= <sentencia> <sentencias>
;R22:	<funcion> ::=  <fn_declaration> <sentencias> }
;D:	vector
;R21:	<funciones> ::= 
;R20:	<funciones> ::= <funcion> <funciones>
;R:	<escritura_main>:
main:
	MOV DWORD [__esp], ESP
;D:	[
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	]
;R48:	<elemento_vector> ::= TOK_IDENTIFICADOR [ <exp> ]
; escribir_elemento_vector:
	POP DWORD EAX
	CMP EAX, 0
	JL NEAR fin_indice_fuera_rango
	CMP EAX, 2
	JG NEAR fin_indice_fuera_rango
	MOV DWORD EDX, _vector
	LEA EAX, [EDX + EAX*4]
	PUSH DWORD EAX
;D:	=
;D:	false
;R103:	<constante_logica> ::= false
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
; asignarDestinoEnPilaVector:
	POP DWORD EBX
	POP DWORD EAX
	MOV DWORD [EAX], EBX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector
;D:	[
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 1
;D:	]
;R48:	<elemento_vector> ::= TOK_IDENTIFICADOR [ <exp> ]
; escribir_elemento_vector:
	POP DWORD EAX
	CMP EAX, 0
	JL NEAR fin_indice_fuera_rango
	CMP EAX, 2
	JG NEAR fin_indice_fuera_rango
	MOV DWORD EDX, _vector
	LEA EAX, [EDX + EAX*4]
	PUSH DWORD EAX
;D:	=
;D:	true
;R102:	<constante_logica> ::= true
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 1
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
; asignarDestinoEnPilaVector:
	POP DWORD EBX
	POP DWORD EAX
	MOV DWORD [EAX], EBX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	vector
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
	CMP EAX, 2
	JG NEAR fin_indice_fuera_rango
	MOV DWORD EDX, _vector
	LEA EAX, [EDX + EAX*4]
	PUSH DWORD EAX
;D:	=
;D:	false
;R103:	<constante_logica> ::= false
;R99:	<constante> ::= <constante_logica>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	;
;R44:	<asignacion> ::= <elemento_vector> = <exp>
; asignarDestinoEnPilaVector:
	POP DWORD EBX
	POP DWORD EAX
	MOV DWORD [EAX], EBX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	resultado
;D:	=
;D:	or
;D:	(
;R:	<idf_llamada_funcion> ::= TOK_IDENTIFICADOR
;D:	vector
;D:	[
;D:	0
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 0
;D:	]
;R48:	<elemento_vector> ::= TOK_IDENTIFICADOR [ <exp> ]
; escribir_elemento_vector:
	POP DWORD EAX
	CMP EAX, 0
	JL NEAR fin_indice_fuera_rango
	CMP EAX, 2
	JG NEAR fin_indice_fuera_rango
	MOV DWORD EDX, _vector
	LEA EAX, [EDX + EAX*4]
	PUSH DWORD EAX
;R85:	<exp> ::= <elemento_vector>
; operandoEnPilaAArgumento:
	POP DWORD EAX
	MOV DWORD EAX, [EAX]
	PUSH DWORD EAX
;D:	,
;D:	vector
;D:	[
;D:	1
;R104:	<constante_entera> ::= TOK_CONSTANTE_ENTERA
;R100:	<constante> ::= <constante_entera>
;R81:	<exp> ::= <constante>
; escribir_operando:
	PUSH DWORD 1
;D:	]
;R48:	<elemento_vector> ::= TOK_IDENTIFICADOR [ <exp> ]
; escribir_elemento_vector:
	POP DWORD EAX
	CMP EAX, 0
	JL NEAR fin_indice_fuera_rango
	CMP EAX, 2
	JG NEAR fin_indice_fuera_rango
	MOV DWORD EDX, _vector
	LEA EAX, [EDX + EAX*4]
	PUSH DWORD EAX
;R85:	<exp> ::= <elemento_vector>
; operandoEnPilaAArgumento:
	POP DWORD EAX
	MOV DWORD EAX, [EAX]
	PUSH DWORD EAX
;D:	,
;D:	vector
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
	CMP EAX, 2
	JG NEAR fin_indice_fuera_rango
	MOV DWORD EDX, _vector
	LEA EAX, [EDX + EAX*4]
	PUSH DWORD EAX
;R85:	<exp> ::= <elemento_vector>
; operandoEnPilaAArgumento:
	POP DWORD EAX
	MOV DWORD EAX, [EAX]
	PUSH DWORD EAX
;D:	)
;R92:	<resto_lista_expresiones> ::= 
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R91:	<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>
;R89:	<lista_expresiones> ::= <exp> <resto_lista_expresiones>
;R88:	<exp> ::= <idf_llamada_funcion> ( <lista_expresiones> )
	CALL or
	ADD ESP, 12
	PUSH DWORD EAX
;D:	;
;R43:	<asignacion> ::= TOK_IDENTIFICADOR = <exp>
; asignar:
	POP DWORD ECX
	MOV DWORD [_resultado], ECX
;R34:	<sentencia_simple> ::= <asignacion>
;R32:	<sentencia> ::= <sentencia_simple> ;
;D:	printf
;D:	resultado
;D:	;
;R80:	<exp> ::= TOK_IDENTIFICADOR
; escribir_operando:
	PUSH DWORD _resultado
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
