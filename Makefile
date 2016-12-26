build: cxx/a.out

clean:
	rm -f cxx/*.o cxx/*.a cxx/a.out

cxx/foolib_c.o:
	(cd cxx; g++ -Wall -Werror -Iinclude -c src/foolib_c.cxx -o foolib_c.o)

cxx/foolib.a: cxx/foolib_c.o
	(cd cxx; ar -rsuv foolib.a foolib_c.o)

cxx/main.o:
	(cd cxx; gcc -Wall -Werror -Iinclude -c test/main.c -o main.o)

cxx/a.out: cxx/foolib.a cxx/main.o
	(cd cxx; gcc -Wall -Werror foolib.a main.o)
