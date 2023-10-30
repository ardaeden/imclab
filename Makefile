lib.name = imclab
s2p.class.sources := s2p.c
sss.class.sources := sss.c
#datafiles =

PDLIBBUILDER_DIR=../pd-lib-builder
include $(PDLIBBUILDER_DIR)/Makefile.pdlibbuilder 

pdincludepath=../pure-data-master/src

clean:
	rm *.pd_linux *.pd_linux.o
