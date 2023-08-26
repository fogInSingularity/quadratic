NAME_OF_SOURCE = main.cpp squareSolver.cpp talkToUser.cpp utest.cpp utils.cpp defaultm.cpp help.cpp color.cpp
NAME_OF_OBJ = main.o squareSolver.o talkToUser.o utest.o utils.o defaultm.o help.o color.o
PATH_TO_OBJ = ./objFiles/main.o ./objFiles/squareSolver.o ./objFiles/talkToUser.o ./objFiles/utest.o ./objFiles/utils.o ./objFiles/defaultm.o ./objFiles/help.o ./objFiles/color.o
NAME_OF_EXE = quadratic
OPT_LEVEL = -O0
DEFINES = _DEBUG
FLAGS = -ggdb3 -std=c++17 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations \
		-Wc++14-compat -Wmissing-declarations -Wcast-align -Wcast-qual \
		-Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy \
		-Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security \
		-Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor \
		-Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self \
		-Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo \
		-Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn \
		-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override \
		-Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code \
		-Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix \
		-Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast \
		-Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation \
		-fstack-protector -fstrict-overflow -flto-odr-type-merging \
		-fno-omit-frame-pointer -Wlarger-than=8192 -Wstack-usage=8192 \
		-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,$\
		float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,$\
		object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,$\
		undefined,unreachable,vla-bound,vptr

all: quadratic

quadratic: $(PATH_TO_OBJ)
	g++ $(PATH_TO_OBJ)  -o $(NAME_OF_EXE) $(FLAGS)

./objFiles/main.o: main.cpp
	g++ -c $(OPT_LEVEL) $(FLAGS) -D $(DEFINES) main.cpp -o ./objFiles/main.o

./objFiles/squareSolver.o: squareSolver.cpp
	g++ -c $(OPT_LEVEL) $(FLAGS) -D $(DEFINES) squareSolver.cpp -o ./objFiles/squareSolver.o

./objFiles/talkToUser.o: talkToUser.cpp
	g++ -c $(OPT_LEVEL) $(FLAGS) -D $(DEFINES) talkToUser.cpp -o ./objFiles/talkToUser.o

./objFiles/utest.o: utest.cpp
	g++ -c $(OPT_LEVEL) $(FLAGS) -D $(DEFINES) utest.cpp -o ./objFiles/utest.o

./objFiles/utils.o: utils.cpp
	g++ -c $(OPT_LEVEL) $(FLAGS) -D $(DEFINES) utils.cpp -o ./objFiles/utils.o

./objFiles/defaultm.o: defaultm.cpp
	g++ -c $(OPT_LEVEL) $(FLAGS) -D $(DEFINES) defaultm.cpp -o ./objFiles/defaultm.o

./objFiles/help.o: help.cpp
	g++ -c $(OPT_LEVEL) $(FLAGS) -D $(DEFINES) help.cpp -o ./objFiles/help.o

./objFiles/color.o: color.cpp
	g++ -c $(OPT_LEVEL) $(FLAGS) -D $(DEFINES) color.cpp -o ./objFiles/color.o
