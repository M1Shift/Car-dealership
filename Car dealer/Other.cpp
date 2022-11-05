#include "Other.h"
Realtek_R_Audio::Realtek_R_Audio() : Audio() {}

std::string Realtek_R_Audio::info() {
    return "Audio: Realtek R audio system";
}
Audio* Realtek_R_Audio::clone()
{
    return new Realtek_R_Audio;
}

HiFiAudioSystem::HiFiAudioSystem() : Audio() {}

std::string HiFiAudioSystem::info() {
    return "Audio: Realtek R audio system";
}
Audio* HiFiAudioSystem::clone() 
{
    return new HiFiAudioSystem;
}

VintageAirConditioner::VintageAirConditioner() : AirConditioner() {}

std::string VintageAirConditioner::info() {
    return "Conditioner: Vintage air conditioner";
}
AirConditioner* VintageAirConditioner::clone() {
    return new VintageAirConditioner;
}

TwoZoneClimateControl::TwoZoneClimateControl() : AirConditioner() {}

std::string TwoZoneClimateControl::info()  {
    return "Conditioner: Two Zone Climate Control and air conditioner";
}
AirConditioner* TwoZoneClimateControl::clone()  {
    return new TwoZoneClimateControl;
}

std::string StandardPropeller::getinfo()
{
    return "Propeller: Standard";
}
double StandardPropeller::getAccelerator()
{
    return 1;
}
Propeller* StandardPropeller::clone()
{
    return new StandardPropeller;
}

std::string CarbonPropeller::getinfo()
{
    return "Propeller: Carbon";
}
double CarbonPropeller::getAccelerator()
{
    return 1.5;
}
Propeller* CarbonPropeller::clone()
{
    return new CarbonPropeller;
}

std::string RTX4090::getinfo()
{
    return "Propeller: Nvidia GeForce RTX 4090";
}
double RTX4090::getAccelerator()
{
    return 999;
}
Propeller* RTX4090::clone()
{
    return new RTX4090;
}