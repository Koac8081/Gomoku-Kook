# 1. 编译器和选项
CC = gcc
# -I. 确保子目录的 .c 能找到根目录下的 gomuku.h
CFLAGS = -I. -Wall -g

# 2. 目标可执行文件
TARGET = gomoku

# 3. 手动列出所有子目录中的 .o 文件（匹配你图片中的实际路径）
# 注意：路径必须和文件浏览器里的一致
OBJS = Main/main.o \
       Boardprint/boardprint.o \
       Boardprint/boardreset.o \
       Bancheck/bancheck.o \
       Mark/mark.o

# 4. 默认规则：链接
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
	@echo "链接成功！生成可执行文件: $(TARGET)"

# 5. 编译规则：确保 .o 生成在它对应的子文件夹内
# % 代表通配符，$< 是源文件，$@ 是目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 6. 清理规则
clean:
	rm -f $(OBJS) $(TARGET)