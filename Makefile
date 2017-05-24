#------------------------------------------------------------------------------
# Jake Runyan
# RLBOT
#------------------------------------------------------------------------------

EXECBIN		= rlbot
MODULES		= auxlib 
CPP 		= g++ -g -O0 -Wall -Wextra  
OPENCV		= /mnt/c/Users/Jake/Desktop/rlbot-cpp/opencv/
OPENCV2		= /mnt/c/Users/Jake/Desktop/rlbot-cpp/opencv2/
LIBINCLUDES	= -iquote ${OPENCV2} -iquote ${OPENCV}

HDRSRC		= ${MODULES:=.h}
CPPSRC		= ${MODULES:=.cpp} rlbot.cpp
OBJECTS		= ${CPPSRC:.cpp=.o}

all: exebin

exebin : ${OBJECTS}
	${CPP} ${LIBINCLUDES} -o ${EXECBIN}  ${OBJECTS} 

%.o : %.cpp
	${CPP} -c $<

run: ${EXECBIN}
	./${EXECBIN}

debug: ${EXEBIN}
	./${EXECBIN} -dd

clean:
	-rm -f ${OBJECTS}  

spotless: clean
	-rm -f ${EXECBIN} 
