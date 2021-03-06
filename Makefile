#------------------------------------------------------------------------------
# Jake Runyan
# RLBOT
#------------------------------------------------------------------------------

EXECBIN		= rlbot
MODULES		= auxlib fileio rocketlib
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
	./${EXECBIN} 150000 1 0 0 0

trades: ${EXECBIN}
	./${EXECBIN} 150000 1 1 0 0

cratebuyonly: ${EXECBIN}
	./${EXECBIN} 150000 1 0 1 0

cratesellonly: ${EXECBIN}
	./${EXECBIN} 150000 1 0 0 1

crates: ${EXECBIN}
	./${EXECBIN} 150000 1 0 1 1

alltrades: ${EXECBIN}
	./${EXECBIN} 150000 1 1 1 1

debug: ${EXEBIN}
	./${EXECBIN} -dd

clean:
	-rm -f ${OBJECTS}  

spotless: clean
	-rm -f ${EXECBIN} 
