compiler = g++
final_name = app

success: compile
#\	clear
	@echo "-------------------------------------"
	@echo "\tSuccessfully Compiled"
	@echo "-------------------------------------"

compile:
	$(compiler) -framework CoreFoundation -framework OpenGL main.cpp stb.cpp libglfw.3.dylib glad.c -o $(final_name)

run:
	./app

#\
#g++ -framework OpenGL main.cpp libglfw.3.dylib -o app
