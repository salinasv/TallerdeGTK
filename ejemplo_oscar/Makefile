OBJECTS=main.c

CFLAGS=-Wall -g -export-dynamic `pkg-config --cflags --libs gtk+-2.0`


gtkbuilder.bin:${OBJECTS}
	${CC} -o gtkbuilder.bin ${CFLAGS} ${OBJECTS}

clean:
	rm *.o
