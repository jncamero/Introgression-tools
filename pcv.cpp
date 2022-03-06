#include <Rcpp.h>

using namespace Rcpp;

// [[Rcpp::export]]
NumericVector pcv(NumericMatrix pop, NumericMatrix g2, NumericVector rr) {
	int n = g2.nrow();   // No. of possible crosses
	int m = pop.nrow(); // No. of loci
 
    NumericVector val(n);
    
    for (int j = 0; j < n; j++) {
    NumericMatrix W(m,4);
    W(0,0)= 0.25 * pop(0,g2(j,0)*2);
    W(0,1)= 0.25 * pop(0,(g2(j,0)*2)+1);
    W(0,2)= 0.25 * pop(0,g2(j,1)*2);
    W(0,3)= 0.25 * pop(0,(g2(j,1)*2)+1);
    
    for (int i = 1; i <m; i++) {
   
W(i,0) =  pop(i,2*g2(j,0)) * (((pow(1-rr(i),2)) * W(i-1,0)) + (rr(i)*(1-rr(i))* W(i-1,1)) + ((0.5 * rr(i) * W(i-1,2))) + ((0.5 * (rr(i)) * W(i-1,3))));

W(i,1) =  pop(i,2*g2(j,0)+1) * ((rr(i) * (1-rr(i)) * W(i-1,0)) + (pow(1-rr(i),2) * W(i-1,1)) + (0.5 * rr(i) * W(i-1,2)) + (0.5 * rr(i) * W(i-1,3)));

W(i,2) = pop(i,2*g2(j,1)) * (((0.5 * rr(i)) * W(i-1,0)) + (0.5 * rr(i) * W(i-1,1)) + (pow(1-rr(i),2) * W(i-1,2)) + ((1-rr(i)) * rr(i) * W(i-1,3)));

W(i,3) = pop(i,2*g2(j,1)+1) * (((0.5 * rr(i)) * W(i-1,0)) + (0.5 * rr(i) * W(i-1,1)) + (((1-rr(i))) * rr(i) * W(i-1,2)) + (pow(1-rr(i),2) * W(i-1,3)));

}	
val(j)= W(m-1,0) + W(m-1,1) + W(m-1,2) + W(m-1,3);
	
}
return val;
}
