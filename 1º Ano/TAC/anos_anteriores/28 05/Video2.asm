.8086
.model small
.stack 2048

dados	segment	para public 'dados'
	coluna	db	3
dados	ends


codigo	segment para public 'code'
	assume  cs:codigo, ds:dados

Main  proc
	mov	ax, dados
	mov	ds, ax	
	
	mov	ax,0b800h
	mov	es,ax

	mov	cx,25

	mov	al,coluna
        mov	bl,2
        mul	bl
        mov	bx,ax      
	mov	si,bx
	add	si,40
ciclo:    
	mov	ax, es:[bx]
	mov	dx, es:[bx+2]
	add	bx,160
	mov	es:[si], ax
	mov	es:[si+2], dx
	add	si,160
	loop	ciclo

	mov     ah,4CH
	int     21H
main	endp

codigo    ends
end     main
