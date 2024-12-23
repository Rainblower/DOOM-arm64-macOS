##########################################################
#
# $Id:$
#
# $Log:$
#
#

CC=gcc
CFLAGS=-O -DNORMALUNIX -DLINUX -I/opt/homebrew/Cellar/portaudio/19.7.0/include
LDFLAGS=-L/opt/homebrew/Cellar/portaudio/19.7.0/lib
LIBS=-lm -lportaudio

O=linux

clean_build: clean
			$(MAKE) all

all:	 $(O)/sndserver

clean:
	rm -f *.o *~ *.flc
	rm -f linux/*

# Target
$(O)/sndserver: \
	$(O)/soundsrv.o \
	$(O)/sounds.o \
	$(O)/wadread.o \
	$(O)/linux.o
	$(CC) $(CFLAGS) $(LDFLAGS) \
	$(O)/soundsrv.o \
	$(O)/sounds.o \
	$(O)/wadread.o \
	$(O)/linux.o -o $(O)/sndserver $(LIBS)
	echo make complete.

# Rule
$(O)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


