## Makefile para compilacion y ejecucion de nuestro proyecto 

# Ruta al proyecto
PROJECT := ProyectoFinal/CodigosFinales

# Directorio de construccion 

BUILD := build

#Creando directorio
$(shell mkdir -p $(BUILD))

.PHONY: all clean doxy

all: 
	@cd $(PROJECT) && qmake
	@$(MAKE) -C $(PROJECT)
	@mv $(PROJECT)/ProyectoFinal $(BUILD)/ProyectoFinal

clean:
	@$(MAKE) -C $(PROJECT) clean
	@rm -rf $(BUILD)
	@rm -f $(PROJECT)/Makefile

doxy:
	@xdg-open ProyectoFinal/Doxygen/html/index.html


.PHONY: exe

exe: all
	./$(BUILD)/ProyectoFinal

