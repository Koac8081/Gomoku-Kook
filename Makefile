CC = gcc

CFLAGS = -I. -Wall -g

TARGET = gomoku

OBJS = Main/main.o \
       Bancheck/bancheck.o \
       Boardprint/boardprint.o \
       Boardprint/boardreset.o \
	   Boardprint/emptyboradprint.o \
       Bancheck/bancheck.o \
       Mark/mark.o \
	   Shapecheck/fivecheck.o \
	   Shapecheck/fivepluscheck.o \
	   Shapecheck/fourcheck.o \
	   Shapecheck/twocheck.o \
	   Wincheck/wincheck.o

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)
	@echo "链接成功！生成可执行文件: $(TARGET)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)