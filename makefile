OBJS = sample.o vsleep.o
CC = /usr/bin/cc

sample : ${OBJS}
	${CC} -o $@ ${OBJS}

sample.o : sample.c
	${CC} -c $?

vsleep.o : vsleep.c
	${CC} -c $?

clean:
	/bin/rm -f sample ${OBJS}

