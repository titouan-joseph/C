#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "type_bigInt.h"
#include "util_bigInt.h"
#include "io_bigInt.h"

#define DEBUG1
#define MAX(x, y) (((x) > (y)) ? (x) : (y))



/*!
************************************************
* \brief Additionne deux Grands Entiers
* \param  bN1 Grand Entier
* \param  bN2 Grand Entier
* \param  res le Grand Entier résultat
* \return  0 si l'addition est OK, 1 en cas d'overflow
* \warning res doit être déjà alloué,
* ************************************************/
int addBigInt(bigInt bN1,bigInt bN2,bigInt res)
{

    for(int i = 0; i < MAX(getNbChiffreBigInt(bN1),getNbChiffreBigInt(bN2)); i++){
        res[i] = bN1[i] + bN2[i] + res[i];
        if(res[i] >= 10){
            res[i+1] = res[i]/10;
            res[i] = res[i] - (res[i]/10)*10;
        }
    }
    if(res[getNbChiffreBigInt(res)] >= 10) return 1;
    return 0;
}





/*!
************************************************
* \brief Multiplie deux Grand Entiers avec l'algorithme suivant:
* stocker les 10 valeurs j*bN2 pour 1<=j<=9
* Pour chaque chiffre j=bN1[i] de bN1, partant de i=0,
* multiplier  j*bN2 par 10^i et l'ajouter au resultat
* \param  bN1 Grand Entier
* \param  bN2 Grand Entier
* \param  res le grand entier bN1*bN2
* \result Un entier: 1 en cas d'overflos, O sinon
* \warning res doit être déjà alloué,
* ************************************************/
int mulBigInt(bigInt bN1,bigInt bN2,bigInt res)
{
    bigInt jbN2[10];
    for(int i = 0; i < 10; i++){
        jbN2[i] = initBigInt();
    }
    jbN2[0] = 0;
    jbN2[1] = bN2;
    addBigInt(jbN2[1], jbN2[1], jbN2[2]);
    addBigInt(jbN2[1], jbN2[2], jbN2[3]);
    addBigInt(jbN2[1], jbN2[3], jbN2[4]);
    addBigInt(jbN2[1], jbN2[4], jbN2[5]);
    addBigInt(jbN2[1], jbN2[5], jbN2[6]);
    addBigInt(jbN2[1], jbN2[6], jbN2[7]);
    addBigInt(jbN2[1], jbN2[7], jbN2[8]);
    addBigInt(jbN2[1], jbN2[8], jbN2[9]);



    for(int i = 0; i <= (getNbChiffreBigInt(bN1)-1); i++){
        bigInt p = initBigInt();
        copyBigInt(jbN2[bN1[i]], p);
        bigInt shift = initBigInt();
        for(int big = 0; big < getNbChiffreBigInt(p); big++){
            shift[i+big] = p[big];
        }
        addBigInt(res, shift, res);
    }

    for(int i = 0; i < 10; i++){
        freeBigInt(jbN2[i]);
    }

    if(res[getNbChiffreBigInt(res)] >= 10) return 1;
    return 0;
 }


//int mulBigInt(bigInt bN1,bigInt bN2,bigInt res)
//{
//    int i,j,k,tailleN1,overflow=0;
//    bigInt bNT[10],bNTemp,bNTemp2;;
//
//    bNTemp=initBigInt();
//    bNTemp2=initBigInt();
//    // ne pas oublier de remettre le resultat à zero
//    zeroBigInt(res);
//    tailleN1=getNbChiffreBigInt(bN1);
//
//#ifdef DEBUG
//    int tailleN2;
//
//  tailleN2=getNbChiffreBigInt(bN2);
//  fprintf(stdout,"bN1=");
//  printBigInt(bN1);
//  fprintf(stdout,"bN2=");
//  printBigInt(bN2);
//  fprintf(stdout,"tailleN1=%d\n",tailleN1);
//  fprintf(stdout,"tailleN2=%d\n",tailleN2);
//#endif
//
//    for (i=0;i<10;i++)
//    {
//        bNT[i]=initBigInt();
//        if (i>0)
//        {//bNT[i] contains i*bN2
//            overflow=overflow || addBigInt(bNT[i-1],bN2,bNT[i]);
//        }
//    }
//
//#ifdef DEBUG
//    for (j=0;j<=9;j++)
//    {
//      fprintf(stdout,"%d*bN2=",j);
//      printBigInt(bNT[j]);
//    }
//#endif
//
//    for (i=0;i<tailleN1;i++)
//    {
//        //bN1[i]*bN2
//        copyBigInt(bNT[bN1[i]],bNTemp);
//        for (k=1;k<=i;k++)
//        {//10^i*bN1[i]*bN2
//            overflow=overflow || times10BigInt(bNTemp,bNTemp);
//        }
//        // res=res+bN
//        // attention, si votre addition remet à zero le résultat
//        // on ne peut pas utiliser res en argument et en resultat
//        // i.e. accumulateur)
//        zeroBigInt(bNTemp2);
//        overflow=overflow ||  addBigInt(res,bNTemp,bNTemp2);
//        copyBigInt(bNTemp2,res);
//
//#ifdef DEBUG
//        fprintf(stdout,"***********************************************\n");
//      fprintf(stdout,"bN1[%d]=%d,  10^%d*bN2=",i,bN1[i],i);
//      printBigInt(bNTemp);
//      fprintf(stdout,"res=");
//      printBigInt(res);
//#endif
//    }
//
//    freeBigInt(bNTemp);
//    for (j=0;j<10;j++)
//        freeBigInt(bNT[j]);
//
//    if (overflow)
//    {
//        fprintf(stderr,"Warning  overflow in multiplication\n");
//        return(1);
//    }
//    else
//        return 0;
//}