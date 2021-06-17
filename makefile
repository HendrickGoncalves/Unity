all:
	make -C examples/TF

cov: 
	make cov -C examples/TF

clean: 
	make clean -C examples/TF

run:
	./examples/TF/cov

gcov:
	gcov -b TF.gcno	
