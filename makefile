GCC = g++

# a target to compile the main which depends on all object-files
# and which links all object-files into an executable

GAME: main.o Model.o Peg.o 
	$(GCC) main.o Model.o Peg.o -o GAME

# a target to compile the main.cpp into an object-file 
main.o: main.cpp
	$(GCC) -c main.cpp

# a target to compile the Model.cpp into an object-file 
Model.o: Model.cpp
	$(GCC) -c Model.cpp

# a target to compile the Peg.cpp into an object-file 
Peg.o: Peg.cpp
	$(GCC) -c Peg.cpp

# a target to delete all object-files and executables 
clean:
	rm main.o Model.o Peg.o GAME

