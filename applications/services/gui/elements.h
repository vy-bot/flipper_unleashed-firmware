/**
 * @file elements.h
 * GUI: Elements API
 * 
 * Canvas helpers and UI building blocks.
 * 
 */

#pragma once

#include <stdint.h>
#include <furi.h>
#include "canvas.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ELEMENTS_MAX_LINES_NUM (7)
#define ELEMENTS_BOLD_MARKER '#'
#define ELEMENTS_MONO_MARKER '*'
#define ELEMENTS_INVERSE_MARKER '!'

/** Draw progress bar.
 *
 * @param   canvas      Canvas instance
 * @param   x           progress bar position on X axis
 * @param   y           progress bar position on Y axis
 * @param   width       progress bar width
 * @param   progress    progress (0.0 - 1.0)
 */
void elements_progress_bar(Canvas* canvas, int32_t x, int32_t y, size_t width, float progress);

/** Draw progress bar with text.
 *
 * @param   canvas      Canvas instance
 * @param   x           progress bar position on X axis
 * @param   y           progress bar position on Y axis
 * @param   width       progress bar width
 * @param   progress    progress (0.0 - 1.0)
 * @param   text        text to draw
 */
void elements_progress_bar_with_text(
    Canvas* canvas,
    int32_t x,
    int32_t y,
    size_t width,
    float progress,
    const char* text);

/** Draw scrollbar on canvas at specific position.
 *
 * @param   canvas  Canvas instance
 * @param   x       scrollbar position on X axis
 * @param   y       scrollbar position on Y axis
 * @param   height  scrollbar height
 * @param   pos     current element
 * @param   total   total elements
 */
void elements_scrollbar_pos(
    Canvas* canvas,
    int32_t x,
    int32_t y,
    size_t height,
    size_t pos,
    size_t total);

/** Draw scrollbar on canvas.
 * @note    width 3px, height equal to canvas height
 *
 * @param   canvas  Canvas instance
 * @param   pos     current element of total elements
 * @param   total   total elements
 */
void elements_scrollbar(Canvas* canvas, size_t pos, size_t total);

/** Draw rounded frame
 *
 * @param   canvas          Canvas instance
 * @param   x, y            top left corner coordinates
 * @param   width, height   frame width and height
 */
void elements_frame(Canvas* canvas, int32_t x, int32_t y, size_t width, size_t height);

/** Draw button in left corner
 *
 * @param   canvas  Canvas instance
 * @param   str     button text
 */
void elements_button_left(Canvas* canvas, const char* str);

/** Draw button in right corner
 *
 * @param   canvas  Canvas instance
 * @param   str     button text
 */
void elements_button_right(Canvas* canvas, const char* str);

/** Draw button in center
 *
 * @param   canvas  Canvas instance
 * @param   str     button text
 */
void elements_button_center(Canvas* canvas, const char* str);

/** Draw aligned multiline text
 *
 * @param   canvas                  Canvas instance
 * @param   x, y                    coordinates based on align param
 * @param   horizontal, vertical    alignment of multiline text
 * @param   text                    string (possible multiline)
 */
void elements_multiline_text_aligned(
    Canvas* canvas,
    int32_t x,
    int32_t y,
    Align horizontal,
    Align vertical,
    const char* text);

/** Draw multiline text
 *
 * @param   canvas  Canvas instance
 * @param   x, y    top left corner coordinates
 * @param   text    string (possible multiline)
 */
void elements_multiline_text(Canvas* canvas, int32_t x, int32_t y, const char* text);

/** Draw framed multiline text
 *
 * @param   canvas  Canvas instance
 * @param   x, y    top left corner coordinates
 * @param   text    string (possible multiline)
 */
void elements_multiline_text_framed(Canvas* canvas, int32_t x, int32_t y, const char* text);

/** Draw slightly rounded frame
 *
 * @param   canvas          Canvas instance
 * @param   x, y            top left corner coordinates
 * @param   width, height   size of frame
 */
void elements_slightly_rounded_frame(
    Canvas* canvas,
    int32_t x,
    int32_t y,
    size_t width,
    size_t height);

/** Draw slightly rounded box
 *
 * @param   canvas          Canvas instance
 * @param   x, y            top left corner coordinates
 * @param   width, height   size of box
 */
void elements_slightly_rounded_box(
    Canvas* canvas,
    int32_t x,
    int32_t y,
    size_t width,
    size_t height);

/** Draw bold rounded frame
 *
 * @param   canvas          Canvas instance
 * @param   x, y            top left corner coordinates
 * @param   width, height   size of frame
 */
void elements_bold_rounded_frame(Canvas* canvas, int32_t x, int32_t y, size_t width, size_t height);

/** Draw bubble frame for text
 *
 * @param   canvas  Canvas instance
 * @param   x       left x coordinates
 * @param   y       top y coordinate
 * @param   width   bubble width
 * @param   height  bubble height
 */
void elements_bubble(Canvas* canvas, int32_t x, int32_t y, size_t width, size_t height);

/** Draw bubble frame for text with corner
 *
 * @param   canvas      Canvas instance
 * @param   x           left x coordinates
 * @param   y           top y coordinate
 * @param   text        text to display
 * @param   horizontal  horizontal aligning
 * @param   vertical    aligning
 */
void elements_bubble_str(
    Canvas* canvas,
    int32_t x,
    int32_t y,
    const char* text,
    Align horizontal,
    Align vertical);

/** Trim string buffer to fit width in pixels
 *
 * @param   canvas  Canvas instance
 * @param   string  string to trim
 * @param   width   max width
 */
void elements_string_fit_width(Canvas* canvas, FuriString* string, size_t width);

/** Draw scrollable text line
 *
 * @param      canvas    The canvas
 * @param[in]  x         X coordinate
 * @param[in]  y         Y coordinate
 * @param[in]  width     The width
 * @param      string    The string
 * @param[in]  scroll    The scroll counter: 0 - no scroll, any other number - scroll. Just count up, everything else will be calculated on the inside.
 * @param[in]  ellipsis  The ellipsis flag: true to add ellipse
 */
void elements_scrollable_text_line(
    Canvas* canvas,
    int32_t x,
    int32_t y,
    size_t width,
    FuriString* string,
    size_t scroll,
    bool ellipsis);

void elements_scrollable_text_line_str(
    Canvas* canvas,
    uint8_t x,
    uint8_t y,
    uint8_t width,
    const char* string,
    size_t scroll,
    bool ellipsis,
    bool centered);

/** Draw text box element
 *
 * @param       canvas          Canvas instance
 * @param       x               x coordinate
 * @param       y               y coordinate
 * @param       width           width to fit text
 * @param       height          height to fit text
 * @param       horizontal      Align instance
 * @param       vertical        Align instance
 * @param[in]   text            Formatted text. The following formats are available:
 *                              "\e#Bold text\e#" - bold font is used
 *                              "\e*Monospaced text\e*" - monospaced font is used
 *                              "\e!Inverted text\e!" - white text on black background
 * @param      strip_to_dots    Strip text to ... if does not fit to width
 */
void elements_text_box(
    Canvas* canvas,
    int32_t x,
    int32_t y,
    size_t width,
    size_t height,
    Align horizontal,
    Align vertical,
    const char* text,
    bool strip_to_dots);

#ifdef __cplusplus
}
#endif
