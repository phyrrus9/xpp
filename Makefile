all:
	gcc -o ex exec.c
	gcc -o sh shell.c
	gcc -o xc compiler.c
clean:
	rm -rf ex
	rm -rf xc
	rm -rf *.x
	rm -rf *.o
	rm -rf multi/*.o
test: test.c ex xc
	@echo "Testing single file mode"
	gcc -c -o test.o test.c
	./xc test.x test.o
	./ex test.x testname
	@echo "Testing multi file mode"
	gcc -c -o multi/start.o multi/start.c
	gcc -c -o multi/hello.o multi/hello.c
	gcc -c -o multi/world.o multi/world.c
	./xc -l 1 -lncurses multi.x multi/start.o multi/hello.o multi/world.o
	./ex multi.x
