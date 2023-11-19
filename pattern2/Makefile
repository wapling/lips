CXXFLAGS = -g -std=c++20 -Wall \
					 -I/Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include \

LDFLAGS = -stdlib=libc++ 

OBJS := main.o \
				ListLexer.o \

all: example 

example: $(OBJS) 
	${CXX} ${LDFLAGS} $(OBJS) -o $@ 

-include $(OBJS:.o=.d)

%.o: %.cpp
	${CXX} -c ${CXXFLAGS} $*.cpp -o $*.o
	${CXX} -MM ${CXXFLAGS} $*.cpp > $*.d

clean:		
	rm -f *.o *.d example
	rm -rf *.dSYM

