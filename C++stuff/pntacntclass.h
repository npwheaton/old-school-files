#ifndef PNTACNTCLASS_H
#define PNTACNTCLASS_H


class ptntacntclass
{private:
	float charges;
	int daysspent;
public:
	float getcharges();
	int getdays();
	void initial();
	void addtocharges(float x);
	void addtodays(int x);
};



#endif
