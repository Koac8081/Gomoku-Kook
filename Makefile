#检测操作系统
ifeq ($(OS), Windows_NT)
    # Windows环境
    PLATFORM = Windows
    RM = del /q /f
    TARGET = gomoku.exe
    # 将路径中的/替换为\兼容Windows命令
    FIX_PATH = $(subst /,\,$1)
else
    # Linux环境
    PLATFORM = Linux
    RM = rm -f
    TARGET = gomoku
    FIX_PATH = $1
endif

#编译器
CC = gcc
CFLAGS = -I. -Wall -g

#对象文件列表
OBJS = Main/main.o \
       Main/screenclean.o \
       Bancheck/bancheck.o \
       Boardprint/boardprint.o \
       Boardprint/boardreset.o \
       Boardprint/emptyboradprint.o \
       Mark/mark.o \
       Mark/scorereset.o \
       Shapecheck/fivecheck.o \
       Shapecheck/fivepluscheck.o \
       Shapecheck/fourcheck.o \
       Shapecheck/threecheck.o \
       Shapecheck/twocheck.o \
       Bancheck/banreset.o \
       AImove/aimove.o \
       AImove/decisiontree.o \
       AImove/findtopscore.o \
       Wincheck/wincheck.o \
       Wincheck/wincheckforai.o 

#编译规则
all: $(TARGET)
	@echo "编译成功，生成可执行文件: $(TARGET)"
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#清理规则
clean:
ifeq ($(OS), Windows_NT)
	$(RM) $(call FIX_PATH, $(OBJS)) $(TARGET)
else
	$(RM) $(OBJS) $(TARGET)
endif