sql: sql.y sql.l
	bison -d sql.y 
	flex -o sql.l.c sql.l
	gcc -o sql sql.l.c sql.tab.c -lfl -lm 

clean:
	rm -f *.c *.h sql