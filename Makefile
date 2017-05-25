#------------------------------------------------------------------------------
# Jake Runyan
# RLBOT
#------------------------------------------------------------------------------

EXECBIN		= rlbot
MODULES		= auxlib rocketlib
CPP 		= g++ -g -O0 -Wall -Wextra  

HDRSRC		= ${MODULES:=.h}
CPPSRC		= ${MODULES:=.cpp} rlbot.cpp
OBJECTS		= ${CPPSRC:.cpp=.o}

all: exebin

exebin : ${OBJECTS}
	${CPP} -o ${EXECBIN}  ${OBJECTS} 

%.o : %.cpp
	${CPP} -c $<

run: ${EXECBIN}
	./${EXECBIN} 150000

debug: ${EXEBIN}
	./${EXECBIN} -dd

clean:
	-rm -f ${OBJECTS}  

spotless: clean
	-rm -f ${EXECBIN} 
