#include "LineManager.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include "Utilities.h"


LineManager::LineManager(std::string& fileName, std::vector<Task*>& taskAddresses, 
	std::vector<CustomerOrder>& custOrdersToFillIn) {
	std::ifstream file(fileName);
	if (!file) {
		throw std::string("Can not open a file");
	}

	Utilities util;
	while (!file.eof()) {
		
		std::string tempString;
		std::size_t position = 0;
		bool more = true;
		std::vector<std::string> temp;

		while (std::getline(file, tempString)) {
			more = true;
			position = 0;
			std::string Task1 = util.extractToken(tempString, position, more);
			std::string Task2;
			Task *ptr1 = nullptr;

			for (auto t : taskAddresses)
			{
				if (t->getName() == Task1) {
					ptr1 = t;
				}
			}
			AssemblyLine.push_back(ptr1);
			if(more) {

				std::string Task2 = util.extractToken(tempString, position, more);

				for (auto t : taskAddresses)
				{
					if (t->getName() == Task2) {
						ptr1->setNextTask(*t);
					}
				}

			}

		}
	}

		// validate add tasks
		for (auto &task : AssemblyLine) {
			task->Validate(std::cout);
		}

		while (!custOrdersToFillIn.empty()){
			ToBeFilled.push_back(std::move(custOrdersToFillIn.back()));
			custOrdersToFillIn.pop_back();
		}
		CustomerOrder_Count = ToBeFilled.size();

	}

	bool LineManager::Run(std::ostream& os) {
		if (!ToBeFilled.empty()) { // move the customer to the next task

			*AssemblyLine.front() += std::move(ToBeFilled.back());
			ToBeFilled.pop_back();
		}

		for (auto i : AssemblyLine) {

			i->RunProcess(os);
		}

		for (auto j : AssemblyLine) {

			j->MoveTask();
		}
		
		CustomerOrder tempCust;
		if (AssemblyLine.back()->getCompleted(tempCust)) {
			Completed.push_back(std::move(tempCust));
		}
		if (Completed.size() == CustomerOrder_Count) {
			os << std::endl; 
			os << "COMPLETED" << std::endl;
			os<< std::endl;
			for (auto& i : Completed) {

				i.Display(os);
			
			}

			return true;
		}
		return false;
	}
