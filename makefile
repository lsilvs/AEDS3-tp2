# Compile/Link
GCC = gcc
OPTMIZE = -g3 -O3
LIBS = -lc

#Objetos
OBJS =  src/tp2pd.c src/funcoes.c 

# Nome do aplicativo
APPNAME = tp2pd

#valgrind
VALGRIND = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

#arquivos
INPUTFILE = input.txt
INPUTFILETEST = doc/test/input.txt
OUTPUTFILE = output.txt
OUTPUTFILETEST = doc/test/output.txt

release: ; $(GCC) $(OPTMIZE) $(LIBS) $(OBJS) -o $(APPNAME)

clean:
	rm -f $(APPNAME) $(OUTPUTFILE)

run:
	make
	./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)

test:
	make
	clear
	./$(APPNAME) $(INPUTFILETEST) $(OUTPUTFILE)
	diff $(OUTPUTFILE) $(OUTPUTFILETEST)

time:
	make
	time ./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)

analysis:
	make
	$(VALGRIND) ./$(APPNAME) $(INPUTFILE) $(OUTPUTFILE)
