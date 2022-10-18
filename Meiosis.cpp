#include "RcppArmadillo.h"
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
// n of progeny to create
//rr is the recombination rate between loci
//a is the first parent (or homologous chromosome set) of parent 1
//b is the second parent(or homologous chromosome set) of parent 2

// [[Rcpp::export]]
NumericMatrix meiosis(int n, NumericVector rr,
 NumericMatrix a, NumericMatrix b) {
 	int m=rr.size();
    NumericVector temp(m);
    NumericMatrix pro(m,n*2);

    int ind1b=1;
    int ind2b=1;  
    int ind1=0;
    int ind2=0;
    int temp1;
    int temp2;
    for (int j = 0; j <=(n-1); j++) {    
  
    for (int i = 0; i <=m-1; i++) {

if(R::runif(0,1) < rr[i]){
temp1=ind1;
ind1=ind1b;
ind1b=temp1;
}
if(R::runif(0,1) < rr[i]){
temp2=ind2;
ind2=ind2b;
ind2b=temp2;
}

pro(i,2*j)=a(i,ind1);
pro(i,2*j+1)=b(i,ind2);
}	
}

return pro;
}

