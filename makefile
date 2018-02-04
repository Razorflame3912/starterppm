all: imagegen.c
	rm -f img.ppm
	rm -f *~
	gcc imagegen.c
	./a.out
