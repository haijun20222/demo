#生成目标
OBJ 			:=main
OUTPATH 		:=./obj
SRC_PATH		:=./api\
				 ./usr
HEAD_PATH		:=./include\
				  ./api
#找到所有.c文件
SRC_FILE		:=$(foreach tmp,$(SRC_PATH),$(wildcard $(tmp)/*.c))
#把所有.c文件换成.o文件
SRC_OFILE		:=$(patsubst %.c,%.o,$(SRC_FILE))
OFILE			:=$(notdir $(SRC_OFILE))
DIR_OFILE		:=$(patsubst %,$(OUTPATH)/%,$(OFILE))
#包含头文件路径
INCLUDE 		:=$(patsubst %,-I %,$(HEAD_PATH))
				
VPATH			:= $(SRC_PATH)


$(OBJ):$(DIR_OFILE)
	gcc $^ -o $@  
$(DIR_OFILE):$(OUTPATH)/%.o:%.c
	gcc $(INCLUDE) -c $< -o $@
clean:
	rm  main $(OUTPATH)/*.o
echo:
	@echo "OUTPATH"== $(OUTPATH)
