Solution.exe: solution.cpp Makefile
	g++ --std=c++11 -o Solution.exe solution.cpp

clean:
	rm -f Solution.exe

run: Solution.exe
	cat INPUT | ./Solution.exe

new: 
	touch Makefile
	make
