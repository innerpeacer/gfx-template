#import <UIKit/UIKit.h>

int main( int argc, char *argv[] ) {

	setenv( "FILESYSTEM", argv[ 0 ], 1 );

    NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
    int retVal = UIApplicationMain(argc, argv, nil, nil);
    [pool release];
    return retVal;
}
