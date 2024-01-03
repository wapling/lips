
STD_HEADERS = /Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include

CXXFLAGS = -g -std=c++17 -Wall \
					 -I${STD_HEADERS} \
					 -I${ANTLR_HEADERS} \

LDFLAGS = -stdlib=libc++ \
					-L${ANTLR_LIBS} \
					-lantlr4-runtime \


OBJS := main.o \
				Symbol.o \
				SymbolTable.o \


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

