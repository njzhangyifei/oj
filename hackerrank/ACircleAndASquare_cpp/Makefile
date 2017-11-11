ifeq ($(OS),Windows_NT)
	CCFLAG += -Wl,--stack,268435456
endif

OUTEXTENSION = .exe

Solution.exe: solution.cpp Makefile

	g++ --std=c++11 $(CCFLAG) -o Solution$(OUTEXTENSION) solution.cpp

clean:
	rm -f Solution$(OUTEXTENSION)

run: Solution.exe
	cat INPUT | ./Solution$(OUTEXTENSION)

new: 
	touch Makefile
	make
