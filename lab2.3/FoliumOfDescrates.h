namespace lab2{

class FOD{
private:
    double n;
    //double alpha;
public:
    FOD();//пустой конструктор
    FOD(double n); //инициализирующий конструктор
    FOD& set(double n0);//set'тер
    double get() const;
    double SideOfSquare() const;
    double DistanceInPolarSystem(double alpha) const;
    double RadiusOfCurvatureTop() const;
    double RadiusOfCurvatureKnot() const;
    double AreaOfList() const;
    double LoopDiameter() const;
    double DistanceFromLoopDiameter() const;
};
}
