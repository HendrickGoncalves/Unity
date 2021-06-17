all:
	make -C examples/crypt

cov: 
	make cov -C examples/crypt

clean: 
	make clean -C examples/crypt

run:
	./examples/crypt/cov
