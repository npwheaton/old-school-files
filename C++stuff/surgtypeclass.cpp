#include <iostream>
#include "surgtype.h"
using namespace std;

void surgtype::lipinject()
{cout<<"The doctor will see you now for your Lip injections";
surgcost+=500;
surgdays+=0;
}
void surgtype::gluteimp()
{cout<<"The doctor will see you now for your Butt implants";
surgcost+=6500;
surgdays+=2;
}
void surgtype::breastimp()
{cout<<"The doctor will see you now for your Breast implants";
surgcost+=5000;
surgdays+=2;
}
void surgtype::lipo()
{cout<<"The doctor will see you now for your Liposuction";
surgcost+=24000;
surgdays+=5;
}
void surgtype::lasik()
{cout<<"The doctor will see you now for your Lasik surgery";
surgcost+=1000;
surgdays+=3;
}
float surgtype::getsurgcost()
{return surgcost;
}
void surgtype::startsurg()
{surgcost=0;
surgdays=0;
}
int surgtype::getsurgdays()
{return surgdays;
}
