#pragma once
#include"Creator.h"
class VehicleManager
{
protected:
	std::vector<Vehicle*>vehicles;
	bool work = true;
public:
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
	std::vector<std::string> getnames()
	{
		std::vector<std::string> names;
		for (auto& i : vehicles)
		{
			names.push_back(i->getmodel());
		}
		return names;
	}
	void run()
	{
		Menu menu({ getnames(),"Welcome!" });
		while (true)
		{
			menu.generate(getnames(), "Welcome!");
			menu.drawOptions();
			menu.drawControls();
			switch (keymenu())
			{
			case VK_F1:
				system("cls");
				vehicles.push_back(Create());
				break;
			case VK_F2:
				system("cls");
				vehicles.push_back(Select());
				break;
			case VK_F3:
				vehicles.erase(vehicles.begin() + menu.getSelectedOption());
				break;
			case VK_F4:
				system("cls");
				vehicles.push_back(vehicles[menu.getSelectedOption()]->clone());
				vehicles[vehicles.size() - 1]->setModel(inputbox(BLUE, "Enter model name: "));
				break;
			case VK_F5:
				system("cls");
				vehicles[menu.getSelectedOption()]->testDrive();
				wait();
				break;
			case VK_F6:
				system("cls");
				vehicles[menu.getSelectedOption()]->info();
				wait();
				break;
			case VK_F7:				
				system("cls");
				std::cout << "Shooting mode, press Enter to shoot, ESC to leave\n";
				while (true)
				{
					switch (keymenu())
					{
					case ENTER:
						vehicles[menu.getSelectedOption()]->shoot();
						break;
					case ESC:
						system("cls");
						work = false;
					}
					if (!work) { break; }
				}
				break;
			case VK_UP:
				menu.up();
				break;
			case VK_DOWN:
				menu.down();
				break;
			case ESC:
				system("cls");
				return;
			}
		}
	}
};