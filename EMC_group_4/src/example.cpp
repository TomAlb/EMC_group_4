#include <iostream>
#include <emc/io.h>
#include <emc/rate.h>


int main()
{
    // Create IO object, which will initialize the io layer
    emc::IO io;

    // Create Rate object, which will help using keeping the loop at a fixed frequency
    emc::Rate r(10);

    // Loop while we are properly connected
    while(io.ok())
    {
        // Receive data from the LRF
        emc::LaserData scan;
        if (io.readLaserData(scan))
        {
            // We got new data, do something with it
            for(unsigned int i = 0; i < scan.ranges.size(); ++i)
            {
                std::cout << scan.ranges[i] << std::endl;
                if (scan.ranges[i] < 2)
                {
                    // Send a reference to the base controller (vx, vy, vtheta)
                    io.sendBaseReference(0.1, 0, 0);


                }else
                {
                    // Send a reference to the base controller (vx, vy, vtheta)
                    io.sendBaseReference(0, 0, 0);

                }

            }
            std::cout << "=========================" << std::endl;

        }
	// an other test




        // Sleep remaining time
        r.sleep();
    }
    return 0;
}
