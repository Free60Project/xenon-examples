#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <console/console.h>
#include <input/input.h>
#include <usb/usbmain.h>
#include <xenon_soc/xenon_power.h>
#include <xenos/xenos.h>

// main() is the entrypoint of the application.
int main()
{
    // Initialise the Xenos GPU with the default video mode.
    // This will be chosen based on the connected video cable
    // and the video region set in the Dashboard.
    xenos_init(VIDEO_MODE_AUTO);

    // Initialise a console on the framebuffer.
    console_init();

    // Sets the processor's clock speed to the full speed of 3.2GHz.
    xenon_make_it_faster(XENON_SPEED_FULL);
    
    // Initialises the USB driver and polls for new devices and inputs.
    // This is what allows both wired and wireless gamepads to work.
    usb_init();
    usb_do_poll();

    // After initialisation, you can clear the screen to remove the debug text
    // from the GPU and USB initialisation. 
    console_clrscr();
    
    // Print out some text to the console.
    printf("Hello world!\n");
    printf("Press the Guide button or Y to exit.\n");

    printf("\n");

    // Set up the structure to recieve controller data.
    struct controller_data_s pad;

    // Enter an infinite loop.
    while (true)
    {
        // Poll the USB driver every frame, to get the latest controller information.
        usb_do_poll();

        // Fetch the controller data for player 1 (pad 0).
        if (get_controller_data(&pad, 0))
        {
            // If the logo (Guide) button or Y button is pressed, exit the application.
            if (pad.logo || pad.y)
            {
                // exit(0) will either reboot into XeLL or restart the console
                // depending on if XeLL is installed
                exit(0);
            }
        }
    }
    
    // Returning from main() acts like an exit(0)
    return 0;
}
