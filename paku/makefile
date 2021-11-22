paku: paku.y paku.l
	bison -d paku.y 
	flex -o paku.l.c paku.l
	gcc -o paku paku.l.c paku.tab.c -lfl -lm 

clean:
	rm -f *.c *.h paku

debug: paku.y paku.l
	bison --debug -d paku.y 
	flex -o paku.l.c paku.l
	gcc -o paku paku.l.c paku.tab.c -lfl -lm 