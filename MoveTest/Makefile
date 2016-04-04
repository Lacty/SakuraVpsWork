
main    = debug/main.o
program = debug/program.out
objs    = $(main)

$(program): $(objs)
	g++ $(objs) -o $@ 

$(main): src/main.cpp
	g++ -c src/main.cpp -o $@

run: $(program)
	$(program)

clear: $(program) $(objs)
	rm $(program) $(objs)
