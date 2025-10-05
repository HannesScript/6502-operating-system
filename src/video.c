#include <stdint.h>
#include <string.h>

////////////////////////////////////////////
// Character Set
////////////////////////////////////////////

// Each character is 5 pixels wide and 6 pixels high, which can be represented in 4 bytes (32 bits)
// Each bit represents one pixel (1 = on, 0 = off)
// The first byte represents the top two rows of pixels, and the second byte represents the bottom
// This allows us to define up to 128 characters in 512 bytes

uint8_t character_set[128][6] = {
    // Define each character bitmap here
    // XXX: ONLY THE FIRST 5 BITS OF EACH BYTE ARE USED FOR THE 5 PIXELS IN WIDTH
    {0b00100000, 0b01010000, 0b10001000, 0b11111000, 0b10001000, 0b10001000}, // 'A'
    {0b11111000, 0b10001000, 0b11111000, 0b10001000, 0b10001000, 0b11111000}, // 'B'
    {0b11111000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b11111000}, // 'C'
    {0b11111000, 0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b11111000}, // 'D'
    {0b11111000, 0b10000000, 0b11111000, 0b10000000, 0b10000000, 0b11111000}, // 'E'
    {0b11111000, 0b10000000, 0b11111000, 0b10000000, 0b10000000, 0b10000000}, // 'F'
    {0b01111000, 0b10000000, 0b10000000, 0b10011000, 0b10001000, 0b01110000}, // 'G'
    {0b10001000, 0b10001000, 0b11111000, 0b10001000, 0b10001000, 0b10001000}, // 'H'
    {0b11111000, 0b00100000, 0b00100000, 0b00100000, 0b00100000, 0b11111000}, // 'I'
    {0b11111000, 0b00001000, 0b00001000, 0b00001000, 0b10001000, 0b01110000}, // 'J'
    {0b10010000, 0b10100000, 0b11000000, 0b10100000, 0b10010000, 0b10001000}, // 'K'
    {0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b11111000}, // 'L'
    {0b01010000, 0b10101000, 0b10101000, 0b10001000, 0b10001000, 0b10001000}, // 'M'
    {0b10001000, 0b11001000, 0b10101000, 0b10011000, 0b10001000, 0b10001000}, // 'N'
    {0b01110000, 0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b01110000}, // 'O'
    {0b11110000, 0b10001000, 0b10001000, 0b11110000, 0b10000000, 0b10000000}, // 'P'
    {0b01100000, 0b10010000, 0b10010000, 0b10010000, 0b01100000, 0b00011000}, // 'Q'
    {0b11110000, 0b10001000, 0b11110000, 0b10100000, 0b10010000, 0b10001000}, // 'R'
    {0b01111000, 0b10000000, 0b01110000, 0b00001000, 0b00001000, 0b11110000}, // 'S'
    {0b11111000, 0b00100000, 0b00100000, 0b00100000, 0b00100000, 0b00100000}, // 'T'
    {0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b10001000, 0b01110000}, // 'U'
    {0b10001000, 0b10001000, 0b10001000, 0b01010000, 0b01010000, 0b00100000}, // 'V'
    {0b10001000, 0b10001000, 0b10001000, 0b10101000, 0b10101000, 0b01010000}, // 'W'
    {0b10001000, 0b01010000, 0b00100000, 0b00100000, 0b01010000, 0b10001000}, // 'X'
    {0b10001000, 0b01010000, 0b00100000, 0b00100000, 0b00100000, 0b00100000}, // 'Y'
    {0b11111000, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b11111000}, // 'Z'
    {0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b00000000, 0b10000000}, // '!'
    {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10000000}, // '.'
    {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b10000000, 0b10000000}, // ','
    {0b01100000, 0b10010000, 0b00100000, 0b00100000, 0b00000000, 0b00100000}, // '?'
    {0b00000000, 0b00000000, 0b10000000, 0b00000000, 0b10000000, 0b10000000}, // ';'
    {0b00000000, 0b00000000, 0b10000000, 0b00000000, 0b10000000, 0b00000000}, // ':'
    {0b01000000, 0b10000000, 0b10000000, 0b10000000, 0b10000000, 0b01000000}, // '('
    {0b00010000, 0b00001000, 0b00001000, 0b00001000, 0b00001000, 0b00010000}, // ')'
    {0b11100000, 0b00100000, 0b00100000, 0b00100000, 0b00100000, 0b11111000}, // '1'
    {0b01110000, 0b10001000, 0b00001000, 0b01110000, 0b10000000, 0b11111000}, // '2'
    {0b11110000, 0b00001000, 0b00110000, 0b00001000, 0b00001000, 0b11110000}, // '3'
    {0b00100000, 0b01000000, 0b10100000, 0b11110000, 0b00100000, 0b11111000}, // '4'
    {0b11111000, 0b10000000, 0b11110000, 0b00001000, 0b10001000, 0b01110000}, // '5'
    {0b01110000, 0b10000000, 0b11110000, 0b10001000, 0b10001000, 0b01110000}, // '6'
    {0b11111000, 0b00001000, 0b00010000, 0b00100000, 0b01000000, 0b10000000}, // '7'
    {0b01110000, 0b10001000, 0b01110000, 0b10001000, 0b10001000, 0b01110000}, // '8'
    {0b01110000, 0b10001000, 0b10001000, 0b01111000, 0b00001000, 0b01110000}, // '9'
    {0b01110000, 0b10011000, 0b10101000, 0b11001000, 0b10001000, 0b01110000}, // '0'
    {0b00100000, 0b00100000, 0b11111000, 0b00100000, 0b00100000, 0b00000000}, // '+'
    {0b00000000, 0b00000000, 0b11111000, 0b00000000, 0b00000000, 0b00000000}, // '-'
    {0b00010000, 0b00010000, 0b00100000, 0b00100000, 0b01000000, 0b01000000}, // '/'
    {0b00000000, 0b01010000, 0b00100000, 0b01010000, 0b00000000, 0b00000000}, // '*'
    {0b00000000, 0b01110000, 0b00000000, 0b01110000, 0b00000000, 0b00000000}, // '='
    {0b01010000, 0b01010000, 0b00000000, 0b00000000, 0b00000000, 0b00000000}, // '"'
    {0b00100000, 0b01110000, 0b10100000, 0b01110000, 0b00101000, 0b01110000}, // '$'
    {0b00110000, 0b01001000, 0b11100000, 0b11100000, 0b01001000, 0b00110000}, // '€'
    {0b01110000, 0b10000000, 0b01111000, 0b10010000, 0b10010000, 0b01100000}, // '&'
    {0b01010000, 0b11111000, 0b01010000, 0b11111000, 0b01010000, 0b01010000}, // '#'
    {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b11111000}, // '_'
};

/////////////////////////////////////////////////////////
// Rendering and screen management for 5x6 characters
/////////////////////////////////////////////////////////

// Character dimensions: 5 pixels wide, 6 pixels tall.
// One pixel spacing between rows and between columns is used
// so each text row occupies 7 vertical pixels and each text column 6 horizontal pixels.
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200

#define CHAR_W 5
#define CHAR_H 6
#define COL_SPACING 1
#define ROW_SPACING 1

// Derived text grid size
#define TEXT_ROWS   (SCREEN_HEIGHT / (CHAR_H + ROW_SPACING)) // 200 / 7 = 28
#define TEXT_COLS   (SCREEN_WIDTH  / (CHAR_W + COL_SPACING))  // 320 / 6 = 53

// Frame buffer for one text row (CHAR_H + ROW_SPACING) rows high, full screen width.
// Layout: row-major, video_buffer[y * SCREEN_WIDTH + x]
static uint8_t video_buffer[SCREEN_WIDTH * (CHAR_H + ROW_SPACING)];

// Text grid: one byte per character cell. Use TEXT_ROWS x TEXT_COLS.
static char texts[TEXT_ROWS][TEXT_COLS];


// Place a NUL-terminated ASCII string into the text grid at (row, col).
// The function will not overflow the destination row.
void add_text(int row, int col, const char* text) {
    if (row < 0 || row >= TEXT_ROWS || col < 0 || col >= TEXT_COLS) return;
    while (*text && col < TEXT_COLS) {
        texts[row][col++] = *text++;
    }
}

// Clear the text grid.
void video_init(void) {
    memset(texts, 0, sizeof(texts));
}

// Render one text row into video_buffer.
// character_set is expected to be an array of 5 bytes per character
// where each byte represents one vertical column and the low CHAR_H bits
// correspond to pixels from top (bit0) to bottom (bit CHAR_H-1).
static void render_text_row_to_buffer(int text_row) {
    int col, bx, py, x;
    unsigned char c;
    int start_x;
    uint8_t const *bitmap;
    uint8_t colbits;
    const int top_padding = 1; // one pixel room above each character

    // Clear buffer (entire strip for this text row)
    memset(video_buffer, 0, sizeof(video_buffer));

    // For each text column in this row, map character columns to screen X coordinates.
    for (col = 0; col < TEXT_COLS; ++col) {
        c = (unsigned char)texts[text_row][col];
        if (c == 0) continue; // empty cell

        // Starting X position for this character on the screen.
        // Keep existing column spacing; the cell's right-most pixel is left unused
        // so there will be a one-pixel room to the right of the glyph.
        start_x = col * (CHAR_W + COL_SPACING);

        // Access character bitmap: CHAR_W columns per character
        bitmap = character_set[(c < 128) ? c : 0];

        for (bx = 0; bx < CHAR_W; ++bx) {
            x = start_x + bx;
            if (x < 0 || x >= SCREEN_WIDTH) continue;

            colbits = bitmap[bx]; // low CHAR_H bits are used
            for (py = 0; py < CHAR_H; ++py) {
                if (colbits & (1u << py)) {
                    // Apply top padding by offsetting the vertical write by top_padding.
                    // This places one blank pixel row above each character.
                    int vy = (py + top_padding);
                    if (vy >= 0 && vy < (CHAR_H + ROW_SPACING)) {
                        video_buffer[vy * SCREEN_WIDTH + x] = 0xFF;
                    }
                }
            }
            // explicit right padding: the column at start_x + CHAR_W remains unused/blank
        }
    }
}

// Send the current video_buffer to the video hardware.
// The hardware address and protocol in the original code are preserved:
// one byte written to address 0x3FF1 per pixel byte, with a small nop between writes.
static void video_send_buffer(void) {
    const int buf_size = SCREEN_WIDTH * (CHAR_H + ROW_SPACING);
    volatile uint8_t *hw = (volatile uint8_t*)0x3ff1;
    int i;
    for (i = 0; i < buf_size; ++i) {
        *hw = video_buffer[i];
        __asm__("nop");
    }
}

// Top-level: render every text row and send it to the video hardware.
// This function steps through each text row (28 rows) and streams the
// corresponding (CHAR_H + ROW_SPACING) pixel rows across the screen.
void video_send(void) {
    int row;
    for (row = 0; row < TEXT_ROWS; ++row) {
        render_text_row_to_buffer(row);
        video_send_buffer();
    }
}
