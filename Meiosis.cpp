#include "RcppArmadillo.h"
// [[Rcpp::depends(RcppArmadillo)]]

using namespace Rcpp;
// m in the length of the genome (i.e. number of loci)
// n is the number of vectors (i.e. 2 * number of individuals)
//rr is the recombination rate between loci
//a is the first vector (or homologous chromosome set) of parent 1
//b is the second vector(or homologous chromosome set) of parent 2

// [[Rcpp::export]]
NumericMatrix meiosis(int n, NumericVector rr,
 NumericVector a, NumericVector b) {
 	int m=rr.size();
    NumericVector temp(m);
    NumericMatrix pro(m,n*2);
    for (int j = 0; j <=(n-1); j++) {
    for (int i = 0; i <=m-1; i++) {
if (R::runif(0,1) < rr[i] )
{temp = a;
	a=b;
	b=temp;
	pro(i,2*j)=a(i);}
else
{pro(i,2*j)=a(i);}


if (R::runif(0,1) < rr[i] )
{temp = a;
	a=b;
	b=temp;
	pro(i,2*j+1)=a(i);}
else
{pro(i,2*j+1)=a(i);}
}	
}

return pro;
}

