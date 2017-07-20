CFLAGS = -Wall -fpic -coverage -lm -fprofile-arcs -ftest-coverage 

testme.o: testme.c
	gcc -o test testme.c -g  $(CFLAGS)

test: testme.o
	./test

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
