src = 912_sort-an-array.cpp
obj = 912_sort-an-array.o

CC = g++

targer = test 

CFLAG = -Wall

$(targer) : $(obj)
	$(CC) $^ -o $@
	rm -f $(obj) 
	@echo "end to compile!"

%.o : %.cpp
	@echo "start compiling!"
	$(CC) -c $(CFLAG) $< -o $@

.PHONY:clean
clean:
	rm -f test 
