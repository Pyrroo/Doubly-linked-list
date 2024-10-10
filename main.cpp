#include "DCList.h"
int main()
{
    DCList<double> list;
    list.Append(1);
    list.Append(1);
    list.Append(1);
    list.Append(1);
    list.Append(1);
    list.Append(1);
    list.Append(1);
    list.Append(1);


    list.AppendByIndex(0, 2);
    list.AppendByIndex(0, 5);


    //list.CoutList();

    list.CoutList();
    


}
