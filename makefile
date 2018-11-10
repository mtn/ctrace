all:
	gcc -finstrument-functions -rdynamic example.c -I ctrace.h
