/**
 * PURPOSE:
 * ()
 *
 * LIBRARY DEPENDENCIES:
 * ((hardwareInterface/src/SerialThrustMaster2.cpp))
 */

#ifndef _SERIAL_THRUST_MASTER2_HH_
#define _SERIAL_THRUST_MASTER2_HH_

#include "SerialThrustMasterBase.hh"
#include "inputAbstraction/include/ThrustMaster2.hh"

namespace idf {

/**
 * represents a Orion-style serial ThrustMaster hand controller
 *
 * @author Derek Bankieris
 */
class SerialThrustMaster2 : public SerialThrustMasterBase, public ThrustMaster2 {

    public:

    /** constructor */
    SerialThrustMaster2(const char *path = "/dev/ttyS0", bool isMale = false);

    protected:

    /**
     * processes the byte containing button data and sets the appropriate
     * inputs
     *
     * @param buttonByte the raw button data
     */
    void processButtons(unsigned char buttonByte);

};

}

#endif
