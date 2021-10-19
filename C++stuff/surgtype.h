#ifndef SURGTYPECLASS_H
#define SURGTYPECLASS_H

class surgtype
{
private:
	float surgcost;
	int surgdays;
public:
	void lipinject();
	void gluteimp();
	void breastimp();
	void lipo();
	void lasik();
	void startsurg();
	float getsurgcost();
	int getsurgdays();
};
#endif
