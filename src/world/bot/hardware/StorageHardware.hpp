//
// Created by Aaron on 1/4/18.
//

#ifndef IOBOTS_STORAGEHARDWARE_HPP
#define IOBOTS_STORAGEHARDWARE_HPP

#include "Hardware.hpp"

class StorageHardware: public Hardware {
private:
    int memSize;
public:
    uint8_t* mem;

    explicit StorageHardware(int memSize);
    StorageHardware() = delete;
    StorageHardware(uint8_t* buffer, size_t buffer_size);
    ~StorageHardware();

    uint8_t getHardwareID() override;
    void interrupt() override;

    void setMemWord(int loc, uint16_t set);
    uint16_t getMemWord(int loc);

    bool deserialize(uint8_t* buffer, size_t buffer_size) override;
    void serialize(uint8_t* buffer) override;
    size_t calculateSerializedSize() override;
};


#endif //IOBOTS_STORAGEHARDWARE_HPP
