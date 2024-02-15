CC = gcc
CFLAGS = -Wall
LDFLAGS = 
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = calculator
DEPS = $(OBJS:.o=.d)

all: $(TARGET)

# 각각의 .c 파일에 대해 .o 파일을 생성합니다.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD

# 실행 파일을 생성합니다.
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

-include $(DEPS)

.PHONY: clean

# Windows 운영 체제에서는 'del' 명령어를 사용하여 파일을 삭제합니다.
RM = del /Q
# 그 외의 운영 체제에서는 'rm' 명령어를 사용하여 파일을 삭제합니다.
clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET)