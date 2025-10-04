void video_init();
void video_send();
void add_text(int row, int col, const char* text);
void video_send_row();

int os_main(void) {
    return 0;
}

// Export a minimal __STARTUP__ symbol so ld65's .forceimport can be satisfied.
// Use a C wrapper instead of inline asm (which is not allowed here).
void __STARTUP__(void) {

    // Initialize the video subsystem
    video_init();

    // Call the program entry point; ignore returned int.
    (void)os_main();
}
