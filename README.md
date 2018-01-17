# Term2_Proj2_UKF
Unscented Kalman Filters

The target of this project is to apply Unscented Kalman Filter to fuse data from Lidar and Radar of a self driving car using C++ (Eclipse IDE).

## Content of this repo
- `scr` source code directory:
  - `main.cpp` - communicate with simulation tool, call functions to run the Kalman filter and calculate RMSE
  - `ukf.cpp`- initializes the Unscented Kalman filter, implements predict and update steps for Radar and Lidar respectively,   calculate NIS. 
  - `tools.cpp` - calculate RMSE

## Unscented Kalman Filter Implementation

1.Initialize states with first measurement.

2.Predict:

  2.1. Parameter argumentation, find sigma points.
  
  2.2. Predict sigma points of next step using discrete process function.
  
  2.3. Calculate new mean and covariance of states in next step.
  
3.Upate:

  3.1. Calculate predicted measurements of existing sigma points using measurement function, 
  calculate mean and covariance of predicted measurements.
  
  3.2. Calculate Kalman gain.
  
  3.3. Update mean and covariance of states
  
  3.4. Calculate NIS
  
4.Tune parameters according to final NIS results


## Result

EKF

|RMSE |Lidar&Radar  |Radar      |Lidar  |
| --- | --- |--- |--- |
|Px   |0.0973       |0.2302     |0.1473 |
|Py   |0.0855       |0.3464     |0.1153 |
|Vx   |0.4513       |0.5835     |0.6383 |
|Vy   |0.4399       |0.8040     |0.5346 |


UKF

|RMSE |Lidar&Radar  |Radar      |Lidar  |
| --- | --- |--- |--- |
|Px   |0.0688       |0.1840     |0.1091 |
|Py   |0.0997       |0.2098     |0.1131 |
|Vx   |0.3239       |0.3584     |0.4455 |
|Vy   |0.2212       |0.3545     |0.3339 |

Radar: above NIS 95% line        4.8%

Lidar: above NIS 95% line        3.2%

This means the process noise is propably over estimated, but within a reaonable range.

From the results, it can be seen Lidar is more accurate, while neither of Lidar or Radar can meet the accuracy request seperately. Compared to previous proj, the result of this project is more accurate, because a more precise CTRV model is applied. 


## How to run the code
Clone this repo and perform
```
mkdir build && cd build
cmake ../src/  && make
./ExtendedKF 
./ExtendedKF 
```




