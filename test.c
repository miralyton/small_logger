/*
 * Copyright (c) 2025 Mira Ly
 * SPDX-Identifier: Apache-2.0
 */

#define LOG_LEVEL 4
#define LOG_CODE_ERR                                                           \
    LOG_CODE_BOLD                                                              \
    LOG_CODE_BLINKING                                                          \
    LOG_CODE_COLOR_BRIGHT_RED

#define LOG_CODE_INFO LOG_CODE_TRUE_COLOR(190, 189, 127)
#include "small_logger.h"

int main(int argc, char *argv[]) {
    LOG_ERR("Test\n");
    LOG_WARN("Test\n");
    LOG_INFO("Test\n");
    LOG_DEBUG("Test\n");
}
