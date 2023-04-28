export EXE := test
export SRC := $(wildcard *.cpp)
export OBJ := $(patsubst %.cpp, %.o, $(SRC))
$(EXE) : $(OBJ)
	gcc $^ -lm -lstdc++ -o $@

%.o : %.cpp queue.hpp
	gcc -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o $(EXE)
.PHONY: run
run: $(EXE)
	./$(EXE)
