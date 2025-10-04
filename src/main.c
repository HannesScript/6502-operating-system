void video_init();
void video_send();
void add_text(int row, int col, const char* text);
void video_send_row();

int main(void) {
    // Initialize the video subsystem and draw a line of text
    video_init();
    add_text(0, 0, "Hello, World!");
    video_send();
    return 0;
}
