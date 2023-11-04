lib.name = imclab
s2p.class.sources := s2p.c
#datafiles =

PDLIBBUILDER_DIR=../pd-lib-builder
include $(PDLIBBUILDER_DIR)/Makefile.pdlibbuilder 

pdincludepath=../pure-data/src

clean:
	rm *.pd_linux *.pd_linux.o
