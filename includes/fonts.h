/**
 * @file fonts.h
 * @author Paulo Santos (pauloroberto.santos@edge.ufal.br)
 * @brief Interface das fontes.
 * @version 0.1
 * @date 22-05-2023
 *
 * @copyright Copyright (c) 2023, Centro de Inovação EDGE
 *
 */

#ifndef FONTS_H
#define FONTS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * @defgroup fonts Fontes.
 * @{
 */

/**
 * @brief Enumera as fontes.
 */
enum font_sizes {
#if defined(CONFIG_OLED_FONT_5x7)
  FONT_SIZE_7, /**< Fonte 5x7. */
#endif
#if defined(CONFIG_OLED_FONT_7x10)
  FONT_SIZE_10, /**< Fonte 8x10. */
#endif
#if defined(CONFIG_OLED_FONT_5x7_PROP)
  FONT_SIZE_7_PROP, /**< Fonte 5x7 proporcional. */
#endif
#if defined(CONFIG_OLED_FONT_7x10_PROP)
  FONT_SIZE_10_PROP, /**< Fonte 7x10 proporcional. */
#endif

  FONT_AMOUNT, /**< Número de fontes. */
};

/**
 * @brief Descreve uma fonte.
 */
struct font {
  const uint8_t *characters; /**< Caracteres.
                              @note: Em fontes proporcionais, o primeiro byte
                              de cada glifo é a sua largura, em pixels. */
  const uint8_t width;       /**< Largura da célula do caractere, em pixels. */
  const uint8_t height;      /**< Altura do caractere, em pixels. */
  const bool is_proportional;  /**< Fonte proporcional (não monoespaçada). */
  const bool is_scan_vertical; /**< Direção de escaneamento da fonte. */
  const uint8_t min_char;      /**< Valor do primeiro caractere. */
  const uint8_t max_char;      /**< Valor do último caractere. */
};

/**
 * @brief Obtém a fonte desejada.
 *
 * @param font Tipo de fonte desejada.
 * @return Fonte desejada.
 */
const struct font *fonts_get(enum font_sizes font);

/**
 * @brief Obtém os dados de um glifo (sem o byte de largura).
 *
 * @param font Fonte desejada.
 * @param character Caractere desejado.
 * @return Dados do glifo, ou NULL se o caractere não pertence à fonte.
 */
const uint8_t *fonts_glyph(const struct font *font, char character);

/**
 * @brief Obtém a largura de um glifo, em pixels.
 *
 * @note Para fontes monoespaçadas retorna a largura da célula.
 *
 * @param font Fonte desejada.
 * @param character Caractere desejado.
 * @return Largura do glifo, ou 0 se o caractere não pertence à fonte.
 */
uint8_t fonts_glyph_width(const struct font *font, char character);

/**
 * @}
 */

#endif /* FONTS_H */
