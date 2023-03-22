lib:
	gcc -Wall -Werror -shared -fPIC libpath.c -o libpath.so

clean:
	rm -f test libpath.so

test: clean
	gcc libpath.c test.c -static -Wall -O2 -o test && ./test