

target = test

CC = g++

include = -I.include/

#src = $(wildcard ./*cpp)
src = $(wildcard ./src/*cpp) 

obj = $(patsubst ./%.cpp, ./%.o, $(src))

$(target) : $(obj)
	$(CC) $^ -o $@

%.o : %.cpp
	$(CC) -c $(include) $(CFLAG) $< -o $@

.PHONY:clean
clean:
	rm $(obj) $(target) -f
