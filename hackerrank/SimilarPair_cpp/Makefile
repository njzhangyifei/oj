Solution.exe: solution.cpp Makefile
	g++ --std=c++11 -Wl,--stack,268435456 -o Solution.exe solution.cpp

run: Solution.exe
	cat INPUT | ./Solution.exe

new: 
	touch Makefile
	make
