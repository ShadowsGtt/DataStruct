CC = gcc

src = $(wildcard ./*.c)
obj = $(patsubst %.c,%.o,$(src))
allobj = $(wildcard ./*.o)

.PHONY : all
all = OBJECT INSTALL 

#.PHONY : OBJECT
OBJECT:
	$(CC) -c $(src) 


#.PHONY : INSTALL
INSTALL :
	ar rcs libgttree.a $(allobj)
	mv ./libgttree.a ../../lib 
	cp ../../lib/libgttree.a  /usr/lib/
	cp ./tree.h /usr/include/

.PHONY:clean
clean:
	rm *.o
