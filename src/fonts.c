/**
 * @file fonts.c
 * @author João Dias (joao.dias@edge.ufal.br)
 * @brief Funções de acesso aos glifos, comuns a todas as fontes.
 * @version 0.1
 * @date 08-07-2026
 *
 * @copyright Copyright (c) 2026, Centro de Inovação EDGE
 *
 */

#include "fonts.h"

/**
 * @brief Obtém o tamanho, em bytes, de um glifo no blob de caracteres.
 *
 * @param font Fonte desejada.
 * @return Tamanho do glifo, em bytes.
 */
static size_t fonts_glyph_stride(const struct font *font) {
  const size_t data_size = font->is_scan_vertical ? font->width : font->height;

  /* Fontes proporcionais possuem um byte extra de largura por glifo. */
  return font->is_proportional ? data_size + 1 : data_size;
}

const uint8_t *fonts_glyph(const struct font *font, const char character) {
  const uint8_t index = (uint8_t)character;

  if (index < font->min_char || index > font->max_char) {
    return NULL;
  }

  const uint8_t *glyph =
      font->characters + (index - font->min_char) * fonts_glyph_stride(font);

  /* Pula o byte de largura das fontes proporcionais. */
  return font->is_proportional ? glyph + 1 : glyph;
}

uint8_t fonts_glyph_width(const struct font *font, const char character) {
  const uint8_t index = (uint8_t)character;

  if (index < font->min_char || index > font->max_char) {
    return 0;
  }

  if (!font->is_proportional) {
    return font->width;
  }

  return font->characters[(index - font->min_char) * fonts_glyph_stride(font)];
}
