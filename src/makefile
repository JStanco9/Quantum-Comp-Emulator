IDIR = ../include
ODIR = ./obj
LDIR = ../lib
BINDIR = ../bin
CC = g++
DEBUG = -g
CFLAGS = -c -I$(IDIR) $(DEBUG)

_OBJS = Quantum_Emu.o operators.o
OBJS = $(patsubst %,$(ODIR)/%,$(_OBJS))
_DEPS = Quantum_Emu.hpp operators.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

LFLAGS = $(DEBUG)
LIBS = -larmadillo

all: quantum

quantum : $(ODIR)/runEmu.o $(ODIR)/FastFourier.o $(OBJS)
	@$(CC) -o $(BINDIR)/$@ $^ $(LFLAGS) $(LIBS)
		
$(ODIR)/runEmu.o : runEmu.cpp $(DEPS)
	@$(CC) -o $@ $< $(CFLAGS)
	
$(ODIR)/Quantum_Emu.o : Quantum_Emu.cpp $(DEPS)
	@$(CC) -o $@ $< $(CFLAGS)	
	
$(ODIR)/operators.o : operators.cpp $(IDIR)/operators.hpp
	@$(CC) -o $@ $< $(CFLAGS)

$(ODIR)/FastFourier.o : FastFourier.cpp $(IDIR)/FastFourier.hpp
	@$(CC) -o $@ $< $(CFLAGS)

	
.PHONY: clean

clean : 
	@rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	