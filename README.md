# Introgression-tools
Rcpp functions for calculating the Predicted Cross Value, and Meiosis simulator

The function pcv implements the Predicted Cross Value calculation from Han et al. 2017, indicating the probability of an ideal gamete being created from the progeny of the cross when meiosis occurs next.

The function meiosis implements diploid meiosis
####################################################################################

#Example1: Meiosis
Arguments: 1) number of random progeny to create, 2) recombination rate between loci, 3) parent A, 4) parent B

#Load Rcpp 
library(Rcpp)

#load function file
sourceCpp("Meiosis.cpp")

parentA=cbind(c(1,0,1,0,1),c(1,0,1,0,1))
parentB=cbind(c(0,1,0,1,0),c(0,1,0,1,0))

#Genetic distance (recombination rate) between loci.  Note: This vector is the same length as number of loci, and the first entry is always 0.5
#in accordance with mendelian inheritance
rr=c(0.5,0.1,0.2,0.3,0.4)

#Run the function, generating 5 random progeny from the cross of parentA and parentB, with recombination rate defined
meiosis(5,rr,parentA,parentB)

     [,1][,2] [,3][,4]
[1,]    0 1    0 0

[2,]    1 0    1 1

[3,]    1 1    1 0

[4,]    0 1    0 1

[5,]    1 0    1 0

#Each vector pair is a random progeny

#Example2: Predicted Cross Value
#Load Rcpp 
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
