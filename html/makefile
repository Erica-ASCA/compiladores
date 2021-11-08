html: html.y html.l
	bison -d html.y 
	flex -o html.l.c html.l
	gcc -o html html.l.c html.tab.c -lfl -lm 

clean:
	rm -f *.c *.h html