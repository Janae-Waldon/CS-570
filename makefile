EXEC = filem

$(EXEC):
	gcc -o filem *.c -w
	rm -f *.o
	./filem
	
clean:
	rm -f *.o core a.out $(EXEC)
	
	
