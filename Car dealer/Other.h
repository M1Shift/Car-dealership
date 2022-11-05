#pragma once
#include <iostream>
class Audio {
public:
    virtual std::string info() = 0;
    virtual Audio* clone() = 0;
};
class Realtek_R_Audio : public Audio
{
public:
    Realtek_R_Audio();
    
    std::string info() override;
    Audio* clone() override;
};
class HiFiAudioSystem : public Audio {
public:
    HiFiAudioSystem();

    std::string info() override;
    Audio* clone() override;
};

class AirConditioner {
public:
    virtual std::string info() = 0;
    virtual AirConditioner* clone() = 0;
};
class VintageAirConditioner : public AirConditioner
{
public:
    VintageAirConditioner();

    std::string info() override;
    AirConditioner* clone() override;
};
class TwoZoneClimateControl : public AirConditioner {
public:
    TwoZoneClimateControl();

    std::string info() override;
    AirConditioner* clone() override;
};

class Propeller
{
public:
    virtual std::string getinfo() = 0;
    virtual double getAccelerator() = 0;
    virtual Propeller* clone () = 0;
};
class StandardPropeller : public Propeller
{
    std::string getinfo() override;
    double getAccelerator() override;
    Propeller* clone() override;
};
class CarbonPropeller : public Propeller
{
    std::string getinfo() override;
    double getAccelerator() override;
    Propeller* clone() override;
};
class RTX4090 : public Propeller
{
    std::string getinfo() override;
    double getAccelerator() override;
    Propeller* clone() override;
};
