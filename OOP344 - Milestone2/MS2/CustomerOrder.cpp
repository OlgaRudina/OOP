#include <vector>
#include <iomanip>
#include "CustomerOrder.h"
#include "Utilities.h"
#include "Item.h"

using namespace std;

char CustomerOrder::delimiter = '|';
int CustomerOrder::field_width = 0;

CustomerOrder::CustomerOrder() {

	ItemCount = 0;
	ItemList = nullptr;

};
CustomerOrder::CustomerOrder(std::string& obj) {

	Utilities u;
	std::vector<std::string> token;

	size_t next_pos = 0;
	bool more = true;
	u.setFieldWidth(field_width);

		Name = u.extractToken(obj, next_pos, more);
		if (more)
		Product = u.extractToken(obj, next_pos, more);
		
		while (more)
			token.push_back(u.extractToken(obj, next_pos, more));


ItemCount = token.size();

	ItemList = new ItemInfo*[token.size()];

	for (unsigned int i = 0; i < token.size(); i++)
	{
		ItemList[i] = new ItemInfo(token[i]);
		for (unsigned int j = 0; j < token.size(); j++)
		{
			ItemList[j] = new ItemInfo(token[j]);
		}	
	}

};
CustomerOrder::~CustomerOrder() {


	if (ItemList) {

		for (unsigned int i = 0; i < ItemCount; i++){
			delete[] ItemList[i];
	}
		ItemList = nullptr;
		ItemCount = 0;

	}


};

CustomerOrder::CustomerOrder(CustomerOrder&&customerOrder) {

	ItemList = nullptr;
	*this = std::move(customerOrder);

};


bool CustomerOrder::getOrderFillState() {
	bool TF = true;
	for (unsigned int i = 0; i < ItemCount; i++) {
		if (ItemList[i]->FillState == false) {
			TF = false;
		}
	}
	return TF;
}


bool CustomerOrder::getItemFillState(std::string itemName) {
	bool TF;
	for (unsigned int i = 0; i < ItemCount; i++) {
		if (itemName.compare(ItemList[i]->ItemName) == 0) {
			TF = ItemList[i]->FillState;
		}
	}
	return TF;
}



void CustomerOrder::fillItem(Item& _item, std::ostream& os) {
	if (_item.getQuantity() > 0) {
		for (unsigned int i = 0; i < ItemCount; i++) {
			if (_item.getName().compare(ItemList[i]->ItemName) == 0) {
				_item.updateQuantity();
				ItemList[i]->FillState = true;
				os << "Filled " << Name << ", " << Product;
				os << "[" << ItemList[i]->ItemName << "]" << endl;
			
			}
		}
	}

}
void CustomerOrder::Display(std::ostream& os) {


		os << Name << endl;
		os << Product << endl;

		for (unsigned int i = 0; i < ItemCount; i++) {

			os << setw(field_width) << '[' << ItemList[i]->SerialNumber << ']';
			os << setw(field_width) << ItemList[i]->ItemName;
			os << setw(field_width) << '-' << (ItemList[i]->FillState ? "FILLED":"MISSING") << endl;
			
		}
	
	//system("pause");
};

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& obj){

	if (this != &obj) {
		if (ItemList) {
			delete[] ItemList;
		}
		Name = obj.Name;
		Product = obj.Product;
		ItemCount = obj.ItemCount;
		ItemList = obj.ItemList;

		obj.Name.clear();
		obj.Product.clear();
		obj.ItemCount = 0;
		obj.ItemList = nullptr;
	}
	
	return move(*this);
}

