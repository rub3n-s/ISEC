;--------------------------------------------------------------
; 	Imprime valor da tecla numa posi��o do ecran na posi��o linha,coluna
;	Move o cursor com as setas do teclado
;--------------------------------------------------------------

.8086
.model small
.stack 2048

dseg	segment para public 'data'

		POSy	db	5	; a linha pode ir de [1 .. 25]
		POSx	db	10	; POSx pode ir [1..80]	
	
dseg	ends

cseg	segment para public 'code'
assume	cs:cseg, ds:dseg



;########################################################################
goto_xy		macro	POSx,POSy
		mov	ah,02h
		mov	bh,0
		mov	dl,POSx
		mov	dh,POSy
		int	10h
endm

;########################################################################
;ROTINA PARA APAGAR ECRAN

apaga_ecran		proc
		xor		bx,bx
		mov		cx,25*80
		
apaga:	mov		byte ptr es:[bx],' '
		mov		byte ptr es:[bx+1],7
		inc		bx
		inc 	bx
		loop	apaga
		ret
apaga_ecran	endp


;########################################################################
; LE UMA TECLA	

LE_TECLA	PROC
		; al - registo que le tecla, devolve a tecla
		; ah - ecra
		mov		ah,08h
		int		21h
		mov		ah,0
		cmp		al,0
		jne		SAI_TECLA
		mov		ah, 08h
		int		21h
		mov		ah,1
SAI_TECLA:		RET
LE_TECLA	endp
;########################################################################

	Main  proc
		mov		ax, dseg
		mov		ds,ax
		mov		ax,0B800h
		mov		es,ax

		call	apaga_ecran

		;Obter a posi��o
		dec		POSy		; linha = linha -1
		dec		POSx		; POSx = POSx -1

	CICLO:	
		
		goto_xy	POSx,POSy
		call 	LE_TECLA
		cmp		ah,1
		je		ESTEND
		CMP 	AL,27		; ESCAPE
		JE		FIM

		mov		dl, al		; imprime caracter no ecran 
        mov     ah,02h
		int		21h
		
		jmp	CICLO

	ESTEND:		cmp 	al,48h
		jne		BAIXO
		dec		POSy		;cima
		jmp		CICLO

	BAIXO:		cmp	al,50h
		jne		ESQUERDA
		inc 	POSy		;Baixo
		jmp		CICLO

	ESQUERDA:
		cmp		al,4Bh
		jne		DIREITA
		dec		POSx		;Esquerda
		jmp		CICLO

	DIREITA:
		cmp		al,4Dh
		jne		CICLO 
		inc		POSx		;Direita
		jmp		CICLO

	fim:	
		mov		ah,4CH
		INT		21H
Main	endp
Cseg	ends
end	Main
