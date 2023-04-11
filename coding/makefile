#陈海军
#生成目标
OBJ 			:=main
OUTPATH 		:=./obj
SRC_PATH		:=./api\
				 ./user
				 
		  		
HEAD_PATH		:=./include\
				  ./user
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
	gcc $^ -o $@ -lpthread 
$(DIR_OFILE):$(OUTPATH)/%.o:%.c 
	gcc $(INCLUDE) -c $< -o $@ 
clean:
	rm  main $(OUTPATH)/*.o
echo:
	@echo "OBJ"== $(OBJ)
	@echo "DIR_OFILE"== $(DIR_OFILE)
	@echo "OUTPATH"== $(OUTPATH)
	@echo "INCLUDE"== $(INCLUDE)