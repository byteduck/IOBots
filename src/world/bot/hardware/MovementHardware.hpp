//
//  MovementHardware.hpp
//  IOBots
//
//  Created by Aaron on 10/16/19.
//

#ifndef MovementHardware_h
#define MovementHardware_h

#include "Hardware.hpp"

class MovementHardware: public Hardware {
private:
public:
    explicit MovementHardware();
    ~MovementHardware();

    uint8_t getHardwareID() override;

    /**
     * Movement related functions.
     * A = 0: Move forward.
     * A = 1: Rotate clockwise.
     * A = 2: Rotate counter-clockwise.
     * A = 3: Query position/rotation. Pushes to stack in order of x,y,rotation
     *  Rotation: 0 = north, 1 = east, 2 = south, 3 = west.
    */
    void interrupt() override;

    bool deserialize(uint8_t* buffer, size_t buffer_size);
    void serialize(uint8_t* buffer);
    size_t calculateSerializedSize();
};

#endif /* MovementHardware_hpp */
