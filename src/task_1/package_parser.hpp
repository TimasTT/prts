//
// Created by timas on 08.11.2021.
//

#ifndef TASK_1_PACKAGE_PARSER_HPP
#define TASK_1_PACKAGE_PARSER_HPP

#define PNITRAX_SIZE 63

struct PNITrax {
    float kHeading;
    float kPitch;
    float kRoll;
    char kHeadingStatus;
    float kQuaternion[4];
    float kTemperature;
    bool kDistortion;
    bool kCalStatus;
    float kAccelX;
    float kAccelY;
    float kAccelZ;
    float kMagX;
    float kMagY;
    float kMagZ;
    float kGyroX;
    float kGyroY;
    float kGyroZ;
};

class PNITraxParser {
private:
    PNITrax data;

    const unsigned char* rawData;
    size_t rawDataLen;

public:
    PNITraxParser() = delete;

    explicit PNITraxParser(const unsigned char* rawBytes, size_t rawBytesLen);

    virtual ~PNITraxParser() = default;

    void PNITraxShow();
};

float bigEndianToFloat(const unsigned char* bigEndianStr, size_t startDataToConvert, size_t strLen);

#endif //TASK_1_PACKAGE_PARSER_HPP
