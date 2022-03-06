# Introgression-tools
Rcpp functions for calculating the Predicted Cross Value, and Meiosis simulator

The function pcv implements the Predicted Cross Value calculation from Han et al. 2017, indicating the probability of an ideal gamete being created from the progeny of the cross when meiosis occurs next.

####################################################################################

#Example1
#Load Rcpp library
library(Rcpp)

#load function file
sourceCpp("pcv.cpp")

#Population: 2 diploid individuals, where allele 1 is desirable and allele 0 is undesirable
pop<-cbind(c(1,0,1),c(1,0,1),c(0,1,0),c(0,1,0))

#Cross list: the matrix of all crosses to evaluate PCV for, where each row is a cross combo

cl<-matrix(c(0,1),nrow=1,ncol=2)

#Recombination rate b/w loci: A vector of the genetic distance (cM) in the interval [0,0.5], between each pair of loci.  Note: the first entry must always be 0.5

rr=c(0.5,0.1,0.2)

pcv(pop,cl,rr)
[1] 0.01
