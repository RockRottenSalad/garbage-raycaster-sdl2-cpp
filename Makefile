

debug:
	clang++ -c src/*.cpp -m64 -g -Wall -I include && clang++ *.o -o bin/debug/main -lSDL2 -lSDL2main && ./bin/debug/main
	rm *.o

# NOTE: clang++ compiler optimizations break 2D mode, stick with debug when compiling with clang++
release:
	clang++ -c src/*.cpp -m64 -O3 -Wall -I include && clang++ *.o -o bin/release/main -s -lSDL2main -lSDL2  && ./bin/release/main
	rm *.o

debug_g:
	g++ -c src/*.cpp -m64 -g -Wall -I include && g++ *.o -o bin/debug/main -lSDL2 -lSDL2main && ./bin/debug/main
	rm *.o

release_g:
	g++ -c src/*.cpp -m64 -O3 -Wall -I include && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2  && ./bin/release/main
	rm *.o
