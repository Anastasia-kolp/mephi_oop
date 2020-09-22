#include <iostream>
#include "FoliumOfDescrates.h"
#include "utility.h"

using namespace lab2;

int main() {

    int check;
    FOD List;

    while (true){
        print_menu();
        getNum(check);
        if(!check)
            break;
        else if(check == 1){
            std::cout<<"----------------------------------------------------------------"<<std::endl;
            std::cout<<"n = "<<List.get()<<std::endl;
            std::cout<<"Side of square: "<<List.SideOfSquare()<<std::endl;
            std::cout<<"Radius of curvature at the top of the sheet: "<<List
            .RadiusOfCurvatureTop()<<std::endl;
            std::cout<<"Radius of curvature at anchor point: "<<List
            .RadiusOfCurvatureKnot()<<std::endl;
            std::cout<<"Leaf loop area: "<<List.AreaOfList()<<std::endl;
            std::cout<<"Length of the largest diameter of the loop: "<<List
            .LoopDiameter()<<std::endl;
            std::cout<<"Distance from the largest diameter of the loop to anchor point:"
                       " "<<List.DistanceFromLoopDiameter()<<std::endl;
        }
        else if(check == 2){
            double m;
            std::cout<<"Enter the parameter n:"<<std::endl;
            getNum(m);
            try{
              List.set(m);
            }
            catch(const char *ex) {
              std::cerr<< "Error: " << ex << std::endl;
              List.set(1);
            }
        }
        else if(check == 3){
            double alpha;
            std::cout<<"Enter the angle:"<<std::endl;
            getNum(alpha);
            std::cout<<"Distance to center in polar coordinate system: "<<List
            .DistanceInPolarSystem(alpha)<<std::endl;
        }
        else
            std::cout<<"Enter the correct number! Please try again!"<<std::endl;
    }
    return 0;
}
