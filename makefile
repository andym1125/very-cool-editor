vce: main.cpp
	gcc main.cpp -lncurses -o vce

run:
	make
	./vce

clean:
	rm vce *.o