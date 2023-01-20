all: cliente_ui medico_ui balcao_ui

cliente_ui: cliente_ui.c
	@gcc -o cliente_ui cliente.c cliente_ui.c
medico_ui: medico_ui.c
	@gcc -o medico_ui medico.c medico_ui.c
balcao_ui: balcao_ui.c
	@gcc -o balcao_ui balcao.c balcao_ui.c -pthread
	@echo "Compilação feita com sucesso."
	
clean:
	@rm -f *.o balcao_ui cliente_ui medico_ui
	@echo "Limpeza feita com sucesso."