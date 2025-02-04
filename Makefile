# Copyright (c) 2025 Mira Ly
# SPDX-Identifier: Apache-2.0

CC = gcc
CFLAGS = -Og -Iinclude -DLOG_CODE_WARN='LOG_CODE_BOLD LOG_CODE_COLOR_BRIGHT_YELLOW'

.PHONY: run clean format

test/test: test.c | test
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBES) $(LDLIBS)

run: test/test
	$<

test:
	mkdir -p $@

format:
	clang-format -i --verbose test.c include/small_logger.h

clean:
	rm -rf test
