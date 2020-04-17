#include <iostream>
#include <stdio.h>
#include <string.h>

int main()
{
#if 0
    //test1::
    int sum=0,v1=0;
    while(v1<10)
    {
        sum += v1;
        ++v1;
    }
    std::cout<<"sum of 1 to " << v1 <<"="<< sum << std::endl;

    //test2::
    sum=0;
    for (int i = -100; i<=100; ++i)
    {
        sum += i;
//        printf("\r\n sum = %d",sum);
    }
    std::cout<<"sum of -100 to 100 =" << sum << std::endl;

    //test2::
    sum=0,v1=0;
    while(std::cin>>v1)
    {
        sum+=v1;
        //printf("\r\n sum = %d,v1= %d \n", sum, v1);
    }
    std::cout<<"sum ="<<sum<<std::endl;
#endif
    //test3::
    int currValue = 0,count=0, value =0;
    if(std::cin >> currValue)
    {
        count =1;
        while (std::cin >> value)
        {
            if (currValue == value)
                count += 1;
            else
            {
                std::cout << "value " << currValue << "occurs " <<count<<"times"<<std::endl;
                currValue = value;
                count = 1;
            }
        }
        std::cout << "value " << currValue << "occurs " <<count<<"times"<<std::endl;
    }
    return 0;

}
