#include "templateApp.h"

TEMPLATEAPP templateApp = {
							templateAppInit,
                            templateAppDraw,
                            templateAppToucheBegan,
							templateAppToucheMoved,
                            templateAppToucheEnded,
    
							/* This function will be called everytime the accelerometer values are refreshed. Please take
							not that the accelerometer can only work on a real device, and not on the simulator. In addition
							you will have to turn ON the accelerometer functionality to be able to use it. This will be
							demonstrated in the book later on. */
							//templateAppAccelerometer // Turned off by default.
						  };


void templateAppInit(int width, int height)
{
	// Setup the exit callback function.
	atexit(templateAppExit);
	
	// Initialize GLES.
	GFX_start();
	
	// Setup a GLES viewport using the current width and height of the screen.
	glViewport( 0, 0, width, height );
	
	/* Insert your initialization code here */
}


void templateAppDraw(void)
{
	glClear( GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT );

	/* Insert your drawing code here */
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    
//    console_print("templateAppDraw\n");
}


void templateAppToucheBegan(float x, float y, unsigned int tap_count)
{
    console_print("templateAppTouchBegan, touch: %f, %f, tap: %d\n", x, y, tap_count);
}


void templateAppToucheMoved(float x, float y, unsigned int tap_count)
{
    console_print("templateAppToucheMoved, touch: %f, %f, tap: %d\n", x, y, tap_count);
}


void templateAppToucheEnded(float x, float y, unsigned int tap_count)
{
    console_print("templateAppToucheEnded, touch: %f, %f, tap: %d\n", x, y, tap_count);
}


void templateAppAccelerometer(float x, float y, float z)
{

}


void templateAppExit(void)
{
    console_print("templateAppExit...\n");
}
