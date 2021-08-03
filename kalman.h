#ifndef kal_h
#define kal_h

class KalmanFilter
{
public:
    KalmanFilter(float meUn, float errUn, float procVariance);
    double updateEstimate(double measurment);
    float getMeasurementUncertainty();
    float getErrorUncertainty();
    float getProcessVariance();

private:
    float meUn;
    float errUn;
    double procVariance;
    double estimate;
    double prevEstimate;
    double K;
};

#endif
