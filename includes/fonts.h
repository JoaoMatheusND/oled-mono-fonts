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
#include <stdint.h>

/**
 * @defgroup fonts Fontes.
 * @{
 */

/**
 * @brief Enumera as fontes.
 */
enum font_sizes {
#if defined(CONFIG_OLED_FONT_4x6)
  FONT_SIZE_6, /**< Fonte 4x6. */
#endif
#if defined(CONFIG_OLED_FONT_5x7)
  FONT_SIZE_7, /**< Fonte 5x7. */
#endif
#if defined(CONFIG_OLED_FONT_7x10)
  FONT_SIZE_10,    /**< Fonte 8x10. */
#endif

  FONT_AMOUNT, /**< Número de fontes. */
};

/**
 * @brief Descreve uma fonte.
 */
struct font {
  const uint8_t *characters; /**< Caracteres. */
  struct {
    const uint8_t width : 3;         /**< Largura do caractere. */
    const uint8_t height : 4;        /**< Altura do caractere. */
    const bool is_scan_vertical : 1; /**< Direção de escaneamento da fonte. */
  };
  const uint8_t min_char; /**< Valor do primeiro caractere. */
  const uint8_t max_char; /**< Valor do último caractere. */
};

/**
 * @brief Obtém a fonte desejada.
 *
 * @param font Tipo de fonte desejada.
 * @return Fonte desejada.
 */
const struct font *fonts_get(enum font_sizes font);

#endif /* FONTS_H */