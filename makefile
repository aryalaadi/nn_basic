all:
	mkdir -p target
	cc SLPnn_exp.c -o target/SLPnn_exp -lm -std=c11
	cc SLPnn_twice.c -o target/SLPnn_twice -lm -std=c11
