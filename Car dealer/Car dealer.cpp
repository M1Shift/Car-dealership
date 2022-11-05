#include "Creator.h"
Vehicle* Select()
{
	Selector select;
	return select.run();
}
Vehicle* Create()
{
	VehicleCreator* creator = nullptr;
	switch (mainmenu({ "Car","Motorbike","Boat" }, "Select vehicle"))
	{
	case 0:
		creator = new CarCreator;
		break;
	case 1:
		creator = new MotorBikeCreator;
		break;
	case 2:
		creator = new BoatCreator;
		break;
	}
	return creator->createVehicle();
}
Vehicle* createtypes()
{
	switch (mainmenu({ "Create car","Select one of ready cars" }, "Select creation type"))
	{
	case 0:
		return Create();
	case 1:
		return Select();
	}
}
int main()
{
	Vehicle* test = createtypes();
	test->testDrive();
	Sleep(2000);
	system("cls");
	test->info();
}
