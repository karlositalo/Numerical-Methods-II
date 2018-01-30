CC		= g++
CFLAGS	= -c -g

EXECALL	        = execAll
EXECPOWER       = execPowerIteration
EXECINVERSE     = execInverseIteration
EXECSHIFT       = execShiftIteration


EIGENVALUE       = Eigenvalue.cpp
POWERITERATION   = PowerIteration.cpp 
INVERSEITERATION = InverseIteration.cpp
SHIFTITERATION   = ShiftIteration.cpp


METHODS	= \
	$(EIGENVALUE) \
	$(POWERITERATION) \
	$(INVERSEITERATION) \
	$(SHIFTITERATION) 

RM		= rm -rf

%.o: %.cpp
	$(CC) $(CFLAGS) $<


# Executaveis

$(EXECALL): \
	$(EXECPOWER) \
	$(EXECINVERSE) \
	$(EXECSHIFT) 

	
$(EXECPOWER): $(POWERITERATION:.cpp = .o) $(EIGENVALUE:.cpp = .o) main_powerIteration.cpp
	$(CC) $^ -o $@
	
$(EXECINVERSE): $(INVERSEITERATION:.cpp = .o) $(POWERITERATION:.cpp = .o) $(EIGENVALUE:.cpp = .o) main_inverseIteration.cpp
	$(CC) $^ -o $@
	
$(EXECSHIFT): $(SHIFTITERATION:.cpp = .o) $(POWERITERATION:.cpp = .o) $(EIGENVALUE:.cpp = .o) main_shiftIteration.cpp
	$(CC) $^ -o $@
	
	
# make's individuais

all: $(EXECALL)

powerIteration: $(EXECPOWER)

inverseIteration: $(EXECINVERSE)

shiftInteration: $(EXECSHIFT)


# outra opcoes

.PHONY: clean cleanall

clean:
	$(RM) *.o *~

cleanall:
	$(RM) $(EXECPOWER) $(EXECINVERSE) $(EXECSHIFT)  *.o *~

help:
	@echo "# "
	@echo "# ----- MAKE HELP -----"
	@echo "# "
	@echo "#     make     : Compila todos os arquivos e gera varios executaveis."
	@echo "#     make all : O mesmo que make."
	@echo "# "
	@echo "#     make powerIteration   : Compila os arquivos do metodo da potencia."
	@echo "#                               Gera executavel execPowerIteration."
	@echo "#     make inverseIteration : Compila os arquivos do metodo da potencia inversa."
	@echo "#                               Gera executavel execInverseIteration."
	@echo "#     make shiftInteration  : Compila os arquivos do metodo da potencia deslocada."
	@echo "#                               Gera executavel execShiftIteration."
	@echo "#     make clean     : Elimina os arquivos criados no processo de compilacao."
	@echo "#     make cleanall  : O mesmo que make clean e elimina tambem os executaveis."
	@echo "#     make help      : Mostra esta ajuda."
	@echo "# "
	@echo "# "
