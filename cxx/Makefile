build: a.out

clean:
	rm -f *.o *.a a.out

foolib_c.o:
	g++ -Wall -Werror -Iinclude -c src/foolib_c.cxx -o foolib_c.o

foolib.a: foolib_c.o
	ar -rsuv foolib.a foolib_c.o

main.o:
	gcc -Wall -Werror -Iinclude -c test/main.c -o main.o

a.out: foolib.a main.o
	g++ -Wall -Werror foolib.a main.o
