#pragma once
#include "Engine.h"
#include "Other.h"
#include "Menu.h"
class Vehicle
{
protected:
	std::string model = "";
	Fuel* fuel = nullptr;
	AirConditioner* airConditioner = nullptr;
	Audio* audio = nullptr;
	Gearbox* gearbox = nullptr;
	int passengers;
public:
	Vehicle(Fuel* fuel, Gearbox* gearbox, std::string model, int passengers);
	Vehicle(Fuel* fuel, Gearbox* gearbox, std::string model, int passengers, Audio* audio, AirConditioner* conditioner);
	Vehicle();
	virtual std::string drive(bool road) = 0;
	virtual void info() = 0;
	virtual Vehicle* clone() = 0;
	Gearbox* gear();
	double volume();
	void setFuel(Fuel* fuel);
	void setAirConditioner(AirConditioner* airConditioner);
	void setGearbox(Gearbox* gearbox);
	void setAudio(Audio* audio);
	void setPassengers(int passengers);
	void setModel(std::string model);
	std::string getmodel();
	virtual void testDrive() = 0;
	~Vehicle();
};
class Car : public Vehicle {
protected:
	Engine* engine = nullptr;
	Wheels* wheels = nullptr;
public:
	Car();
	Car(Engine* engine, Wheels* wheels, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers);
	Car(Engine* engine, Wheels* wheels, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers, Audio* audio, AirConditioner* conditioner);
	Car(const Car& car);
	std::string drive(bool road) override;
	Gearbox* gear();
	double volume();
	void info() override;
	void setWheels(Wheels* wheels);
	~Car();
	void setEngine(Engine* engine);
	void setTurbine(Turbine* turbine);
	void testDrive() override;
	virtual Vehicle* clone() override;
};
class Motorbike : public Car
{
public:
	Motorbike();
	Motorbike(Engine* engine, Wheels* wheels, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers);
	Motorbike(Engine* engine, Wheels* wheels, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers, Audio* audio, AirConditioner* conditioner);
	void info() override;
	Vehicle* clone() override;
};
class Boat : public Vehicle
{
protected:
	BoatEngine* engine = nullptr;
public:
	Boat(BoatEngine* engine, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers);
	Boat(BoatEngine* engine, Fuel* fuel, Gearbox* gearbox, std::string model, int passengers, Audio* audio, AirConditioner* conditioner);
	Boat();
	std::string drive();
	std::string drive(bool road) override;
	void info() override;
	void setEngine(BoatEngine* engine);
	~Boat();
	Vehicle* clone() override;
	void testDrive() override;
};
