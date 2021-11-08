#include <cstring>

#include "package_parser.hpp"

void test1() {
    size_t inputLen = 12;
    unsigned char rawInput[inputLen];
    rawInput[0] = 0x05;
    rawInput[1] = 0x3F;
    rawInput[2] = 0x80;
    rawInput[3] = 0x00;
    rawInput[4] = 0x00;
    rawInput[5] = 0x09;
    rawInput[6] = 0x01;
    rawInput[7] = 0x1C;
    rawInput[8] = 0x40;
    rawInput[9] = 0x00;
    rawInput[10] = 0x00;
    rawInput[11] = 0x00;
    PNITraxParser pniTrax(rawInput, inputLen);
    pniTrax.PNITraxShow();
}

void test2() {
    size_t inputLen = 10;
    unsigned char rawInput[inputLen];
    rawInput[0] = 0x4C;
    rawInput[1] = 0x41;
    rawInput[2] = 0xA4;
    rawInput[3] = 0x00;
    rawInput[4] = 0x00;
    rawInput[5] = 0x4B;
    rawInput[6] = 0x3F;
    rawInput[7] = 0x91;
    rawInput[8] = 0xBC;
    rawInput[9] = 0xD8;
    PNITraxParser pniTrax(rawInput, inputLen);
    pniTrax.PNITraxShow();
}

void test3() {
    size_t inputLen = 15;
    unsigned char rawInput[inputLen];
    rawInput[0] = 0x07;
    rawInput[1] = 0x41;
    rawInput[2] = 0xA4;
    rawInput[3] = 0x00;
    rawInput[4] = 0x00;
    rawInput[5] = 0x05;
    rawInput[6] = 0x3F;
    rawInput[7] = 0x91;
    rawInput[8] = 0xBC;
    rawInput[9] = 0xD8;
    rawInput[10] = 0x19;
    rawInput[11] = 0x41;
    rawInput[12] = 0x35;
    rawInput[13] = 0x47;
    rawInput[14] = 0xAE;
    PNITraxParser pniTrax(rawInput, inputLen);
    pniTrax.PNITraxShow();
}

void test4() {
    size_t inputLen = 32;
    unsigned char rawInput[inputLen];
    rawInput[0] = 0x05;
    rawInput[1] = 0x43;
    rawInput[2] = 0x0D;
    rawInput[3] = 0x08;
    rawInput[4] = 0x3B;
    rawInput[5] = 0x18;
    rawInput[6] = 0x3F;
    rawInput[7] = 0x91;
    rawInput[8] = 0xBC;
    rawInput[9] = 0xD8;
    rawInput[10] = 0x19;
    rawInput[11] = 0x3E;
    rawInput[12] = 0xDF;
    rawInput[13] = 0x4D;
    rawInput[14] = 0xE9;
    rawInput[15] = 0x4D;
    rawInput[16] = 0x42;
    rawInput[17] = 0x28;
    rawInput[18] = 0x69;
    rawInput[19] = 0xE2;
    rawInput[20] = 0x41;
    rawInput[21] = 0xF8;
    rawInput[22] = 0xF5;
    rawInput[23] = 0xC3;
    rawInput[24] = 0x41;
    rawInput[25] = 0xDE;
    rawInput[26] = 0xC2;
    rawInput[27] = 0x8F;
    rawInput[28] = 0x3C;
    rawInput[29] = 0x59;
    rawInput[30] = 0x4D;
    rawInput[31] = 0x0E;
    PNITraxParser pniTrax(rawInput, inputLen);
    pniTrax.PNITraxShow();
}

void test5() {
    size_t inputLen = 64;
    unsigned char rawInput[inputLen];
    rawInput[0] = 0x05;
    rawInput[1] = 0x43;
    rawInput[2] = 0x0D;
    rawInput[3] = 0x08;
    rawInput[4] = 0x3B;
    rawInput[5] = 0x18;
    rawInput[6] = 0x3F;
    rawInput[7] = 0x91;
    rawInput[8] = 0xBC;
    rawInput[9] = 0xD8;
    rawInput[10] = 0x19;
    rawInput[11] = 0x3E;
    rawInput[12] = 0xDF;
    rawInput[13] = 0x4D;
    rawInput[14] = 0xE9;
    rawInput[15] = 0x4F;
    rawInput[16] = 0x00;
    rawInput[17] = 0x08;
    rawInput[18] = 0x00;
    rawInput[19] = 0x15;
    rawInput[20] = 0xBC;
    rawInput[21] = 0xA4;
    rawInput[22] = 0x08;
    rawInput[23] = 0xC0;
    rawInput[24] = 0x16;
    rawInput[25] = 0x3B;
    rawInput[26] = 0xFB;
    rawInput[27] = 0x4D;
    rawInput[28] = 0xAB;
    rawInput[29] = 0x17;
    rawInput[30] = 0x3F;
    rawInput[31] = 0x80;
    rawInput[32] = 0xF5;
    rawInput[33] = 0x08;
    rawInput[34] = 0x1B;
    rawInput[35] = 0xC1;
    rawInput[36] = 0x6E;
    rawInput[37] = 0xA4;
    rawInput[38] = 0x37;
    rawInput[39] = 0x1C;
    rawInput[40] = 0xC1;
    rawInput[41] = 0x2D;
    rawInput[42] = 0x31;
    rawInput[43] = 0x27;
    rawInput[44] = 0x1D;
    rawInput[45] = 0x42;
    rawInput[46] = 0x51;
    rawInput[47] = 0x3D;
    rawInput[48] = 0x4F;
    rawInput[49] = 0x4A;
    rawInput[50] = 0x00;
    rawInput[51] = 0x00;
    rawInput[52] = 0x00;
    rawInput[53] = 0x00;
    rawInput[54] = 0x4B;
    rawInput[55] = 0x00;
    rawInput[56] = 0x00;
    rawInput[57] = 0x00;
    rawInput[58] = 0x00;
    rawInput[59] = 0x4C;
    rawInput[60] = 0x00;
    rawInput[61] = 0x00;
    rawInput[62] = 0x00;
    rawInput[63] = 0x00;
    PNITraxParser pniTrax(rawInput, inputLen);
    pniTrax.PNITraxShow();
}

void testsRun() {
    test1();
    test2();
    test3();
    test4();
    test5();
}

int main() {
    testsRun();
    return 0;
}
