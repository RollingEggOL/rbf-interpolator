#ifndef INTERPOLATOR_H
#define INTERPOLATOR_H

#include <vector>

class Interpolator
{
public:
    Interpolator();

    // function definition
    enum FUNCTION_TYPE {
        GAUSSIAN,         // f(r) = exp(-(epsilon*r)^2)
        THINPLATESPLINE,  // f(r) = (r^2)*log(r)
        INVERSEQUADRATIC, // f(r) = (1 + (epsilon*r)^2)^(-1)
    } functionType;

    double epsilon;
    double lambda;

    bool useRegularization;

    // API
    void    resetAll();
    void    addCenterPoint(double y, std::vector<double> x);
    void    computeWeights();
    double  getInterpolatedValue(std::vector<double> x);

    // getter
    std::vector<double>               getYs();
    std::vector<std::vector<double> > getXs();

private:

    // registered center points
    std::vector<double>               ys;
    std::vector<std::vector<double> > xs;

    // computed weights
    std::vector<double>               w;

    // for error check
    bool readyForUse;

    // returns f(r)
    double getRBFValue(double r);
    // returns f(||xj - xi||)
    double getRBFValue(std::vector<double> xi, std::vector<double> xj);
};

#endif // INTERPOLATOR_H
