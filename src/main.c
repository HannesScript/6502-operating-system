void video_init();
void video_send();
void add_text(int row, int col, const char* text);
void video_send_row();

int main(void) {
    // Initialize the video subsystem and draw a line of text
    video_init();
    

    // Infinite loop
    while (1) {
        
    }

    return 0;
}
