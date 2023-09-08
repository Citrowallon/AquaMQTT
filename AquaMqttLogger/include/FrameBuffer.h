#ifndef AQUAMQTT_FRAMEBUFFER_H
#define AQUAMQTT_FRAMEBUFFER_H

#include "../.pio/libdeps/nanoatmega328new/FastCRC/FastCRC.h"
#include "../.pio/libdeps/nanoatmega328new/RingBuffer/src/RingBuf.h"
#include "FrameHandler.h"

#define HEATPUMP_MAX_FRAME_LENGTH 50

class FrameBuffer
{
public:
    explicit FrameBuffer(FrameHandler* handler);

    ~FrameBuffer() = default;

    void pushByte(int val);

private:
    void handleFrame();

    bool isSync();

    RingBuf<int, HEATPUMP_MAX_FRAME_LENGTH> mBuffer;

    FastCRC16 mCRC;

    FrameHandler* mFrameHandler;
};

#endif  // AQUAMQTT_FRAMEBUFFER_H
