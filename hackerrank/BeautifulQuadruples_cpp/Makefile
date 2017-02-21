Solution.exe: solution.cpp Makefile
	g++ --std=c++11 -Wl,--stack,268435456 -o Solution.exe solution.cpp

playground: playground.cpp Makefile
	g++ --std=c++11 -Wl,--stack,268435456 -o playground.exe playground.cpp

clean:
	rm -f Solution.exe

run: Solution.exe
	cat INPUT | ./Solution.exe

new: 
	touch Makefile
	make
