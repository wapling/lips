
STD_HEADERS = /Library/Developer/CommandLineTools/SDKs/MacOSX10.15.sdk/usr/include

CXXFLAGS = -g -std=c++20 -Wall \
					 -I${STD_HEADERS} \

LDFLAGS = -stdlib=libc++ 

OBJS := main.o \
				RomanNumeralLexer.o \
				RomanNumeralAdder.o \
				Tokens.o

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

