OBJECTS=main.o player.o

CFLAGS=-Wall -ggdb `pkg-config --cflags --libs gtk+-2.0 gstreamer-app-0.10 gstreamer-plugins-base-0.10`



gtk.bin:${OBJECTS}
	${CC} -o gtk.bin ${CFLAGS} ${OBJECTS}

clean:
	rm *.o
