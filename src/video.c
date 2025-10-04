#include <stdint.h>
#include <string.h>

// The screen is 320x200 pixels, so we need 64,000 bytes of buffer
// to hold the entire screen in 8-bit color mode, but we only have 4 KB of Video RAM!
// Therefore, we will send the screen in 8 sections of 12 rows each.
// Each section will be 320 * 5 = 1,600 bytes, which fits in 4 KB of Video RAM and still leaves some space.
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 200
#define SCREEN_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT)

uint8_t video_buffer[SCREEN_WIDTH * 5]; // Buffer for 5 rows of the screen (1,600 bytes which is a row of text)

// Special array with array to hold each row of text
// Each byte represents one character (4 x 4 pixels in size)
// this allows us to have 64 characters per row (320 / 5 = 64)
// and 40 rows of text (200 / 5 = 40)
char texts[40][64];
// 40 rows of text with 64 characters each (4 pixel Text height with
// one pixel space above and to the left, so 5 pixels per row of text)

void add_text(int row, int col, const char* text) {
    // Add text to the texts array at the specified row and column
    while (*text) {
        if ((col + strlen(text)) < 64) { // Ensure we don't overflow the row
            texts[row][col++] = *text++;
        } else {
            break; // Stop if we reach the end of the row
        }
    }
};
    
void video_init() {
    memset(texts, 0, sizeof(texts)); // Clear the texts array
    return;
};

void video_send() {
    int row;
    for (row = 0; row < 40; row++) {
        // Clear the video buffer for the new row
        memset(video_buffer, 0, sizeof(video_buffer));

        // Render Pixel data for 5 rows of pixels (one row of text)

        // Send pixel data

        // Repeat
    }
}

void video_send_row() {
    // For each byte in the frame buffer, put it in memory address 0x3ff1
    int pix_idx;
    for (pix_idx = 0; pix_idx < 1600; pix_idx++) {
        uint8_t byte = video_buffer[pix_idx];
        // Send byte to video hardware at address 0x3ff1
        *((volatile uint8_t*)0x3ff1) = byte;

        // No Op to give the video hardware time to process the byte
        __asm__("nop");
    }
};
