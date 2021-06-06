all:
	make -C examples/identifier

cov: 
	make cov -C examples/identifier

clean: 
	make clean -C examples/identifier

run:
	./examples/identifier/cov

gcov:
	gcov -b identifier.gcno	
