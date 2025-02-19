PROJECT:=TestFramework

CC:=clang

CERROR:= -Wall -Wextra -Werror -Walloca -Wcast-qual -Wconversion -Wdouble-promotion -Wfloat-equal -Wswitch-default -Wswitch-enum -g
CFLAGS:=-std=c2x -O3 -ffast-math $(CERROR)
LDFLAGS:=

SRC_DIR:=src
INC_DIR:=lib
OUT_DIR:=build
DEBUG_DIR:=debug

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)

$(PROJECT): $(SRC_FILES)
	mkdir -p build
	mkdir -p debug
	$(CC) $(CFLAGS) -I$(INC_DIR)/ -o $(OUT_DIR)/$(PROJECT) $(SRC_FILES) $(LDFLAGS)
	make run

.PHONY: run update check clean

run:
	./$(OUT_DIR)/$(PROJECT)

update:
	bear --output $(DEBUG_DIR)/compile_commands.json -- make
	clang-format -style=google -dump-config > $(DEBUG_DIR)/.clang-format

check:
	clang-format -style=file:$(DEBUG_DIR)/.clang-format -i $(SRC_FILES)
	clang-tidy $(SRC_FILES) -p $(DEBUG_DIR)/

clean:
	rm $(OUT_DIR)/*
