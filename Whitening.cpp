#include "Whitening.h"

static uint8_t WhiteningKeyMSB = 0x01; // Global variable so the value is kept after starting the
static uint8_t WhiteningKeyLSB = 0xFF; // de-whitening process


// *buffer is a char pointer indicating the data to be whiten / de-whiten
// buffer size is the number of char to be whiten / de-whiten
// >> The whitened / de-whitened data are directly placed into the pointer
void ComputeWhitening( uint8_t *buffer, uint16_t bufferSize )
{
    WhiteningKeyMSB = 0x01; // Init value for the LFSR, these values should be initisalise only
    WhiteningKeyLSB = 0xFF; // at the start of a whitening or a de-whitening process

    uint8_t i = 0;
    uint16_t j = 0;
    uint8_t WhiteningKeyMSBPrevious = 0; // 9th bit of the LFSR
    for( j = 0; j < bufferSize; j++ ) { // byte counter
        buffer[j] ^= (uint8_t) (WhiteningKeyLSB); // XOR between the data and the whitening key

        for( i = 0; i < 8; i++ ) { // 8-bit shift between each byte
            WhiteningKeyMSBPrevious = WhiteningKeyMSB;
            WhiteningKeyMSB = ( WhiteningKeyLSB & 0x01 ) ^ ( ( WhiteningKeyLSB >> 5 ) & 0x01 );
            WhiteningKeyLSB= ( ( WhiteningKeyLSB >> 1 ) & 0xFF ) | ( ( WhiteningKeyMSBPrevious << 7 ) & 0x80 );
        }
    }
}