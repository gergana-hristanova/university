class Triangle {
    public:
    Triangle();
    Triangle(double sideA, double sideB, double sideC);
    double getPerimeter();
    double getArea();
    void printInfo();

    private:
    double sideA;
    double sideB;
    double sideC;
};