#CC = /home/fredy/gcc-linaro-5.3-2016.02-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-gcc			
CC = gcc

hello:hello.o
	$(CC) -g -o hello hello.o
	
hello.o:hello.c
	$(CC) -g -c hello.c

clean:
	rm hello.o hello
