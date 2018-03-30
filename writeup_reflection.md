#  PID Controller

---

**PID Controller Project**

The goals of this project are the following:

* The code should compile.
* The PID procedure follows what was taught in the lessons.
* A reflection/discussion on the implementation and tuning of hyperparameters should be included.
* The vehicle must successfully drive a lap around the track in the simulation tool.

## [Rubric](https://review.udacity.com/#!/rubrics/824/view) Points


---

### Reflection

#### Describe the effect each of the P, I, D components had in your implementation


1.	The proportional term provides an overall control action proportional to the error signal.
2.	The integral term reduces steady-state error through low-frequency compensation.
3.	The derivative term improves transient response through high-frequency compensation, its purpose it to improve the closed-loop stability.


#### Describe how the final hyperparameters were chosen.

A “twiddle knobs” approach can be used to tune the controller (or to fine tune upon application of structured empirical tuning methods), though it should be used with caution for a good understanding of the influence of each gain on the system’s dynamics is needed (as explained in the previous section).

The effects of the modification of the gains values on the performance speci-fications of a closed-loop system are summarized in the following table:

|				|Rise Time		|Overshoot	|Settling Time	|Steady-State Error	|Stability	|
|:-------------:|:-------------:|:---------:|:-------------:|:-----------------:|:---------:|
|Increasing K_P	|Decrease		|Increase	|Small Increase	|Decrease			|Degrade	|
|Increasing K_I	|Small Decrease	|Increase	|Increase		|Large Decrease		|Degrade	|
|Increasing K_D	|Small Decrease	|Decrease	|Decrease		|Minor Change		|Improve	|

 
This table can be used as a base guideline for the process of fine re-tuning a PID controller without a dynamic model of the plant. A caveat to be taken into considera-tion about the derivative term: when the sensor signals are noisy (even after appropriate signal conditioning and filtering) the derivative term can detract from system stability. For this reason, often the controller is reduced to a PI in a number of applications. The derivative action is often more difficult to tune empirically.





