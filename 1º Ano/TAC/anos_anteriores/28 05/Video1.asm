.8086
.model small
.stack 2048

dados	segment	para public 'dados'
	linha	db	3
dados	ends


codigo	segment para public 'code'
	assume  cs:codigo, ds:dados

Main  proc
	mov	ax, dados
	mov	ds, ax	
	
	mov  	ax,0b800h
	mov	es,ax

	mov	cx,160
	
	mov	al,linha
        mov	bl,160
        mul	bl
        mov	bx,ax 

        mov	al,linha
	add	al,15
	mov	dl,160
        mul	dl
        mov	si,ax         

ciclo:    
	mov	ax, es:[bx]
	add	bx,2
	mov	es:[si], ax
	add	si,2
	loop	ciclo

	mov     ah,4CH
	int     21H
main	endp

codigo    ends
end     main
