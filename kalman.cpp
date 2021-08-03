#include "Arduino.h"
#include "kalman.h"
#include <math.h>

KalmanFilter::KalmanFilter(float meUn, float errUn, float procVariance)
{
    this->meUn = meUn;
    this->errUn = errUn;
    this->procVariance = procVariance;
}

double KalmanFilter::updateEstimate(double measurement)
{
    K = errUn / (errUn + meUn);
    estimate = prevEstimate + K * (measurement - prevEstimate);
    errUn = fabs(prevEstimate - estimate) + (1.0f - K) * errUn;
    prevEstimate = estimate;

    return estimate;
}

float KalmanFilter::getMeasurementUncertainty() {
    return meUn;
}

float KalmanFilter::getErrorUncertainty() {
    return errUn;
}

float KalmanFilter::getProcessVariance() {
    return procVariance;
}
