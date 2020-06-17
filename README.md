## UV Lightbox

Dual mode UV lightbox with adjustable LED brightness.
- When lid is open, only the LED stips will light, allowing safe preparation of negatives.
- When lid is closed, only the UV LED panels will light, to expose copper boards.

### Software Overview

- UVBoxManager inits user application and coordinates input control interrupts.
- EventManager implements a simple state machine.
- LedManager controls the LED PWM for the two modes.

The dependencies between files are shown below:

<p>
<center>
<img src="readme_diagrams/UvLighBox_Dependencies.svg" height="240" width="480">
</center>
</p>

## Hardware Overview

For hardware details see project: [UV_LED_DRIVER](https://github.com/cracked-machine/UV_LED_Driver/tree/master/UV_LED_Driver_Modular)
