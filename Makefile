main.o: main.cpp
	g++ main.cpp -o main.o

run: main.o
	./main.o

clean:
	rm main.o
