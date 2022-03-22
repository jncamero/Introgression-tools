#include <RcppArmadillo.h>
#include <Rcpp.h>
#include <armadillo>
#include <RcppArmadilloExtensions/sample.h>

// [[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;


// [[Rcpp::export]]
NumericMatrix tetmei(NumericMatrix parents, NumericMatrix cl, NumericVector rr){

NumericMatrix progeny=no_init(parents.nrow(), cl.nrow()*4);
int size = 4; // 4 possible alleles at a locus
NumericVector pairing;
NumericVector xx; // Chromosomes positions for pairing for parent1
int ini=0; //indexing initializer
        for (int i = 0; i < cl.nrow(); i++) {
            
            //Set kernel for random number generator
            srand(time(NULL));
            
            // where to put progeny in progeny matrix
            NumericVector pro=NumericVector::create((i*4),(i*4)+1,(i*4)+2,(i*4)+3);
            int pro1 =(i*4);
            int pro2 =(i*4)+1;
            int pro3 =(i*4)+2;
            int pro4 =(i*4)+3;
            
            // Parent indices
            int par1_start = cl(i,0)*4;

            // Parent indices
            int par2_start = cl(i,1)*4;

            // number of rows
            int pr = parents.nrow();
            
            int x1; //Chromosome index for pairing/meiosis
            int x2; //Chromosome index for pairing/meiosis
            
            double temp;
            double tr;
            //Parental Chromosome pairing/ index
            xx=NumericVector::create(par1_start,par1_start+1,par1_start+2,par1_start+3);
            NumericVector pairing=sample(xx,4);
            //Index for output progeny Matrix: from i to NROW CROSSING LIST
            int ini=0; //initializer indexer
            for (int j = pro1; j <= pro2; j++) {
                
                //Seeding random number generator
              x1=pairing(ini*2);
              x2=pairing((ini*2)+1);

            for (int k = 0; k <pr; k++) {
                    tr =((double) rand() / (RAND_MAX));  //Sample random number between 0 and 1, [0,1)
                    if (tr>rr[k]){ //if no recombination...
                        progeny(k,j)=parents(k,x1);
                    }else{ //changing chromosome index if recombination occurs
                        temp=x1;
                        x1=x2;
                        x2=temp;
                        progeny(k,j)=parents(k,x1);
                        
                    }
                }
                ini=ini+1;
            }
           ini=0;
           xx=NumericVector::create(par2_start,par2_start+1,par2_start+2,par2_start+3);
           pairing=sample(xx,4);
            //Index for output progeny Matrix: from i to NROW CROSSING LIST
            for (int j = pro3; j <= pro4; j++) {
                
              x1=pairing(ini*2);
              x2=pairing((ini*2)+1);
                for (int k = 0; k <pr; k++) {
                    tr =((double) rand() / (RAND_MAX));  //Sample random number between 0 and 1, [0,1]
                    if (tr>rr[k]){ //if no recombination...
                        progeny(k,j)=parents(k,x1);
                    }else{ //changing chromosome index if recombination occurs
                        temp=x1;
                        x1=x2;
                        x2=temp;
                        progeny(k,j)=parents(k,x1);
                    }
                }
                ini=ini+1;
            }
            
}
    return progeny;
}
