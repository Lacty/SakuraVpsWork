
main    = debug/main.o
sock    = debug/sock.o
program = debug/program.out
objs    = $(main) $(sock)

opt      = -Wall -std=c++11
compiler = clang++

$(program): $(objs)
	$(compiler) $(opt) $(objs) -o $@ 

$(main): src/main.cpp
	$(compiler) $(opt) -c src/main.cpp -o $@

$(sock): src/socket.cpp
	$(compiler) $(opt) -c src/socket.cpp -o $@

run: $(program)
	$(program)

clear: $(program) $(objs)
	rm $(program) $(objs)
