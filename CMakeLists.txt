# Copyright (c) 2026, Centro de Inovação Edge.
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_OLED_FONTS)
    zephyr_library()
    zephyr_include_directories(includes)

    zephyr_library_sources(src/fonts.c)

    zephyr_library_sources_ifdef(CONFIG_FONT_DEFAULT  src/default_font.c)
endif()