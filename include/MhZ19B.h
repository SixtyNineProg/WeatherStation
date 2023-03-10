#include <MHZ19_uart.h>
MHZ19_uart mhz19;

#define MHZ_RX 2
#define MHZ_TX 3

#define CO2_MIN 300
#define CO2_MAX 2000

class MhZ19B
{
private:
    /* data */
public:
    MhZ19B(/* args */);
    ~MhZ19B();
    int getPPM();
    void initSensor();
};

MhZ19B::MhZ19B(/* args */)
{
}

MhZ19B::~MhZ19B()
{
}

int MhZ19B::getPPM()
{
    return mhz19.getPPM();
}

void MhZ19B::initSensor()
{
    mhz19.begin(MHZ_TX, MHZ_RX);
    mhz19.setAutoCalibration(false);
    mhz19.getStatus();
    delay(500);
    if (mhz19.getStatus() == 0)
    {
        Serial.println(F("MhZ19B OK"));
    }
    else
    {
        Serial.println(F("MhZ19B ERROR"));
    }
}
