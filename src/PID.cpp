#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;

	p_error = i_error = d_error = 0;
	anti_windup = 1;
	out_saturation = 1;
}

void PID::UpdateError(double cte) {
	d_error = cte - p_error;
	p_error = cte;	
	i_error += cte;
	if (i_error > anti_windup) {
		i_error = anti_windup;
	}
	else if (i_error < -anti_windup) {
		i_error = -anti_windup;
	}
}

double PID::TotalError() {
	double output = Kp*p_error + Kd*d_error + Ki*i_error;
	if (output > out_saturation) {
		return out_saturation;
	}
	else if (output < -out_saturation) {
		return -out_saturation;
	}
	else {
		return output;
	}
}

