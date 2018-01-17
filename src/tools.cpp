#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
    /**
    TODO:
      * Calculate the RMSE here.
    */
    int n = estimations.size()-1;

    //std::cout<<"estimations:"<<estimations[n](0)<<";"<<estimations[n](1)<<";"<<estimations[n](2)<<";"<<estimations[n](3)<<"\n";
	//std::cout<<"ground_truth:"<<ground_truth[n](0)<<";"<<ground_truth[n](1)<<";"<<ground_truth[n](2)<<";"<<ground_truth[n](3)<<"\n";

	VectorXd rmse(4);
	rmse << 0,0,0,0;

	// check the validity of the following inputs:
	//  * the estimation vector size should not be zero
	//  * the estimation vector size should equal ground truth vector size
	if(estimations.size() != ground_truth.size()
	|| estimations.size() == 0){
	cout << "Invalid estimation or ground_truth data" << endl;
	return rmse;
	}

	//accumulate squared residuals
	for(unsigned int i=0; i < estimations.size(); ++i){

	  VectorXd residual = estimations[i] - ground_truth[i];

	  //coefficient-wise multiplication
	  residual = residual.array()*residual.array();
	  rmse += residual;
	}

	//calculate the mean
	rmse = rmse/estimations.size();

	//calculate the squared root
	rmse = rmse.array().sqrt();

	//cout<<"RMSE"<<rmse<<"\n";

	//return the result
	return rmse;
}
