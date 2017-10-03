########################################
##
## Makefile
## LINUX compilation 
##
##############################################





#FLAGS
C++FLAG = -g -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.





#Rule for .cpp files
# .SUFFIXES : .cpp.o 

.cpp.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@




#Including
INCLUDES=  -I. 


LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 




#FIRST PROGRAM
ALL_OBJ1=paing_assignment1_main.o

PROGRAM_1=prog1
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)

#SECOND PROGRAM
#ALL_OBJ2=testMatrix.o IntCell.o
#PROGRAM_2=prog2
#$(PROGRAM_2): $(ALL_OBJ2)
#	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ2) $(INCLUDES) $(LIBS_ALL)

#THIRD PROGRAM
#ALL_OBJ3=simpleTest1.o
#PROGRAM_3=prog3
#$(PROGRAM_3): $(ALL_OBJ3)
#	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ3) $(INCLUDES) $(LIBS_ALL)

#Compiling all

all: 
	make $(PROGRAM_1)
#	make $(PROGRAM_2)
#	make $(PROGRAM_3)	
#Clean obj files

clean:
	(rm -f *.o;)



(:
