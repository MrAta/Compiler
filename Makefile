all: cython

OBJS = parser.o  \
       codegen.o \
       main.o    \
       scanner.o  \
       crf.o  \

LLVMCONFIG = llvm-config
CPPFLAGS = `$(LLVMCONFIG) --cppflags` -std=c++11
LDFLAGS = `$(LLVMCONFIG) --ldflags` -lpthread -ldl -lz -lncurses -rdynamic
LIBS = `$(LLVMCONFIG) --libs`

clean:
	$(RM) -rf parser.cpp parser.hpp cython scanner.cpp $(OBJS)

parser.cpp: Aparser.y
	bison -d -o $@ $^
	
parser.hpp: parser.cpp

scanner.cpp: Ascanner.l parser.hpp
	flex -o $@ $^

%.o: %.cpp
	g++ -c $(CPPFLAGS) -o $@ $<


cython: $(OBJS)
	g++ -o cython $(OBJS) $(LIBS) $(LDFLAGS)

test: cython
	./cython example.cy

