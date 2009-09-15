OBJECTS=main.c

CFLAGS=-Wall -ggdb `pkg-config --cflags --libs gtk+-2.0`



gtk.bin:${OBJECTS}
	${CC} -o gtk.bin ${CFLAGS} ${OBJECTS}

clean:
	rm *.o
