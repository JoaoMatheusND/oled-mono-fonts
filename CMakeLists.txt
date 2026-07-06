# Copyright (c) 2026, Centro de Inovação Edge.
# SPDX-License-Identifier: BSD-3-Clause

zephyr_library()
zephyr_include_directories(includes)

if(CONFIG_OLED_FONTS)
zephyr_library_sources_ifdef(CONFIG_OLED_FONTS_DEFAULT src/default_font.c)
zephyr_library_sources_ifdef(CONFIG_OLED_FONTS_TOMTHUMB src/tomthumb_font.c)
endif ()
