//
// Created by timas on 08.11.2021.
//

#include <cstring>
#include <iostream>

#include "package_parser.hpp"

float bigEndianToFloat(const unsigned char* bigEndianStr, size_t startDataToConvert, size_t strLen) {
    if (startDataToConvert + 4 > strLen || bigEndianStr == nullptr) {
        return 0;
    }
    float retVal;
    auto* returnFloat = (unsigned char*) &retVal;

    for (int i = 0; i < sizeof(float); ++i) {
        returnFloat[i] = bigEndianStr[startDataToConvert + sizeof(float) - 1 - i];
    }

    return retVal;
}

PNITraxParser::PNITraxParser(const unsigned char* rawBytes, size_t rawBytesLen)
        : rawData(rawBytes), rawDataLen(rawBytesLen) {
    memset(&data, 0, PNITRAX_SIZE);
    for (size_t i = 0; i < rawDataLen; i += 1) {
        switch ((int) rawData[i]) {
            case 5: {
                data.kHeading = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 24: {
                data.kPitch = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 25: {
                data.kRoll = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 79: {
                memcpy(&data.kHeadingStatus, &rawData[i + 1], sizeof(char));
                i += sizeof(char);
                break;
            }
            case 77: {
                for (float &j: data.kQuaternion) {
                    j = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                    i += sizeof(float);
                }
                break;
            }
            case 7: {
                data.kTemperature = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 8: {
                memcpy(&data.kDistortion, &rawData[i + 1], sizeof(bool));
                i += sizeof(bool);
                break;
            }
            case 9: {
                memcpy(&data.kCalStatus, &rawData[i + 1], sizeof(bool));
                i += sizeof(bool);
                break;
            }
            case 21: {
                data.kAccelX = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 22: {
                data.kAccelY = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 23: {
                data.kAccelZ = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 27: {
                data.kMagX = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 28: {
                data.kMagY = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += 4;
                break;
            }
            case 29: {
                data.kMagZ = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 74: {
                data.kGyroX = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 75: {
                data.kGyroY = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            case 76: {
                data.kGyroZ = bigEndianToFloat(rawData, i + 1, rawBytesLen);
                i += sizeof(float);
                break;
            }
            default:
                break;
        }
    }
}

void PNITraxParser::PNITraxShow() {
    for (size_t i = 0; i < rawDataLen; i += 1) {
        switch ((int) rawData[i]) {
            case 5: {
                std::cout << "kHeading : " << data.kHeading << " grad" << std::endl;
                i += sizeof(float);
                break;
            }
            case 24: {
                std::cout << "kPitch : " << data.kPitch << " grad" << std::endl;
                i += sizeof(float);
                break;
            }
            case 25: {
                std::cout << "kRoll : " << data.kRoll << " grad" << std::endl;
                i += sizeof(float);
                break;
            }
            case 79: {
                if (data.kHeadingStatus == 0) {
                    std::cout << "kHeadingStatus : " << 0 << std::endl;
                } else {
                    std::cout << "kHeadingStatus : " << data.kHeadingStatus << std::endl;
                }
                i += sizeof(char);
                break;
            }
            case 77: {
                for (size_t j = 0; j < 4; ++j) {
                    std::cout << "kQuaternion" << j << " : " << data.kQuaternion[j] << std::endl;
                    i += sizeof(float);
                }
                break;
            }
            case 7: {
                std::cout << "kTemperature : " << data.kTemperature << " grad*s" << std::endl;
                i += sizeof(float);
                break;
            }
            case 8: {
                std::cout << "kDistortion : " << (data.kDistortion ? "true" : "false") << std::endl;
                i += sizeof(bool);
                break;
            }
            case 9: {
                std::cout << "kCalStatus : " << (data.kCalStatus ? "true" : "false") << std::endl;
                i += sizeof(bool);
                break;
            }
            case 21: {
                std::cout << "kAccelX : " << data.kAccelX << " g" << std::endl;
                i += sizeof(float);
                break;
            }
            case 22: {
                std::cout << "kAccelY : " << data.kAccelY << " g" << std::endl;
                i += sizeof(float);
                break;
            }
            case 23: {
                std::cout << "kAccelZ : " << data.kAccelZ << " g" << std::endl;
                i += sizeof(float);
                break;
            }
            case 27: {
                std::cout << "kMagX : " << data.kMagX << " mT" << std::endl;
                i += sizeof(float);
                break;
            }
            case 28: {
                std::cout << "kMagY : " << data.kMagY << " mT" << std::endl;
                i += sizeof(float);
                break;
            }
            case 29: {
                std::cout << "kMagZ : " << data.kMagZ << " mT" << std::endl;
                i += sizeof(float);
                break;
            }
            case 74: {
                std::cout << "kGyroX : " << data.kGyroX << " rad/sec" << std::endl;
                i += sizeof(float);
                break;
            }
            case 75: {
                std::cout << "kGyroY : " << data.kGyroY << " rad/sec" << std::endl;
                i += sizeof(float);
                break;
            }
            case 76: {
                std::cout << "kGyroZ : " << data.kGyroZ << " rad/sec" << std::endl;
                i += sizeof(float);
                break;
            }
            default:
                break;
        }
    }
    std::cout << std::endl;
}
