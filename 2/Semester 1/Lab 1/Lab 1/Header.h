#pragma once

#pragma once

class Component
{
private:
	char designation[20];
	char type;
	double nominal;
	int quantity;

public:
	Component();

	char getType() const;
	const char* getDesignation() const;
	double getNominal() const;
	int getQuantity() const;

	void setNominal(double newNominal);
	void setDesignation(const char* newDesignation);
	void setType(char newType);
	void setQuantity(int newQuantity);

};