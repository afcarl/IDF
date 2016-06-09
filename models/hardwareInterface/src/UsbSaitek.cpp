#include "hardwareInterface/include/UsbSaitek.hh"

namespace idf {

UsbSaitek::UsbSaitek(int vendorID, int productID) :
    UsbDevice("Saitek", vendorID, productID, 3) {}

void UsbSaitek::decode(const std::vector<unsigned char>& data) {
    leftPedal.setValue(data[0] & 0x7F);
    rightPedal.setValue(((data[1] << 1) & 0x7F) | (data[0] >> 7));
    twist.setValue((int)(char)data[2] << 2 | (data[1] >> 6));
}

}
