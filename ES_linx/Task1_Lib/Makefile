Src_Dir:=SourceFiles
StaticLib_Dir:=StaticLib
DynamicLib_Dir:=DynamicLib
Inc_Dir:=Include

Include_Dir:=/usr/include
Lib_Dir:=/usr/lib

.PHONY: StaticLib DynamicLib

Src_Files:=$(wildcard  $(Src_Dir)/*.c)
Obj_Files1:=$(patsubst $(Src_Dir)/%.c,$(StaticLib_Dir)/%.o,$(Src_Files))
Obj_Files2:=$(patsubst $(Src_Dir)/%.c,$(DynamicLib_Dir)/%.o,$(Src_Files))

# Creating a static Lib
StaticLib: $(Obj_Files1) 
	@ar rcs  $(StaticLib_Dir)/libOperation.a $(Obj_Files1) 

$(Obj_Files1):$(StaticLib_Dir)/%.o : $(Src_Dir)/%.c 
	@gcc -c $<  -o $@
#Creating Dynamic Lib 
DynamicLib: $(Obj_Files2) 
	@gcc -shared -o $(DynamicLib_Dir)/libOperation.so  $(Obj_Files2) 
#this rule in make  applay the command on each f.c with the corresponding  f.o
$(Obj_Files2): $(DynamicLib_Dir)/%.o : $(Src_Dir)/%.c 
	@gcc -c -fPIC $< -o $@ 
install: DynamicLib 
	@sudo cp  $(Inc_Dir)/*.h  $(Include_Dir)
	@sudo cp $(DynamicLib_Dir)/*.so  $(Lib_Dir)


build: StaticLib DynamicLib

#the  Static linking of Lib  with main.c
	@gcc -static main.c -L $(StaticLib_Dir) -l Operation -o  main.exe 
#Dynamic Link of Lib Operation with main.c
	@gcc  main.c -L $(DynamicLib_Dir) -l Operation -o  main.out

run: build
	@./main.exe
clean:
	@rm -rf $(StaticLib_Dir)/*  $(DynamicLib_Dir)/*
	@rm -rf  main.[!c]*
