#include <iostream>

//using namespace std;

int main()
{
    int puntos[]={25,36,21,24,23,10,21,20,23,7};//lista que almacena los puntos obtenidos a la fecha
    int auxiliar[]={0,1,2,3,4,5,6,7,8,9};//lista auxiliar que almacenara los puntos temporalmente
    int maximo= 0;//variablles para el algoritmo de ordenamiento
    int imaximo= 0;
    int mejor=10;
    int orden[]={0,1,2,3,4,5,6,7,8,9};// orden resultante despues del algoritmo de ordenamiento que indica el indice del pais en cada posicion
    bool flag=false;// booleano cuyo valor true significara que Perú tiene posibilidades de clasificar al mundial
    int contador=0;// contador que almacenara el total de cantidad de posibles resultados en los que Perú puede clasificar al mundial
    //string paises[]={"Colombia","Brasil","Paraguay","Uruguay","Chile","Bolivia","Peru","Ecuador","Argentina","Venezuela"};
    for(int a=0;a<3;a++){//primer partido con tres posibilidades gana A, gana B o empatan
        if (a==0){
            puntos[0]+=3;
        }
        else if(a==1){
            puntos[0]-=2;
            puntos[1]++;
        }
        else{
            puntos[0]--;
            puntos[1]+=2;
        }
        for(int b=0;b<3;b++){//segundo partido con tres posibilidades gana A, gana B o empatan
            if (b==0){
                puntos[2]+=3;
            }
            else if(b==1){
                puntos[2]-=2;
                puntos[3]++;
            }
            else{
                puntos[2]--;
                puntos[3]+=2;
            }
            for(int c=0;c<3;c++){//tercer partido con tres posibilidades gana A, gana B o empatan
                if (c==0){
                    puntos[4]+=3;
                }
                else if(c==1){
                    puntos[4]-=2;
                    puntos[5]++;
                }
                else{
                    puntos[4]--;
                    puntos[5]+=2;
                }
                for(int d=0;d<3;d++){//cuarto partido con tres posibilidades gana A, gana B o empatan
                    if (d==0){
                        puntos[6]+=3;
                    }
                    else if(d==1){
                        puntos[6]-=2;
                        puntos[7]++;
                    }
                    else{
                        puntos[6]--;
                        puntos[7]+=2;
                    }
                    for(int e=0;e<3;e++){//quinto partido con tres posibilidades gana A, gana B o empatan
                        if (e==0){
                            puntos[8]+=3;
                        }
                        else if(e==1){
                            puntos[8]-=2;
                            puntos[9]++;
                        }
                        else{
                            puntos[8]--;
                            puntos[9]+=2;
                        }
                        for (int i=0;i<10;i++){//duplicacion de los puntos resultantes en un auxiliar
                            auxiliar[i]=puntos[i];
                        }
                        flag=false;
                        for(int i=0;i<10;i++){//algoritmo de ordenamiento similar a insertion usando dos listas
                            imaximo=0;
                            maximo=auxiliar[0];
                            for(int j=1;j<10;j++){
                                if(auxiliar[j]>=maximo){
                                    maximo=auxiliar[j];
                                    imaximo=j;
                                }
                            }
                            orden[i]=imaximo;
                            auxiliar[imaximo]=0;
                            if (imaximo==6){//
                                if (i<mejor){
                                    mejor=i;
                                    std::cout<<"MEJOR-------------------------------\n";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
                                }
                                if (i<5){
                                    flag = true;
                                }
                                else if(i==5 && puntos[6]==puntos[orden[4]]){
                                    flag=true;
                                }
                            }
                        }
                        if (flag==true){ //se imprimen los resultados de los 5 partidos jugados
                            if (a==0){
                                std::cout<<"Colombia"<<" le gana a "<<"Brasil"<<"\n";
                            }
                            else if (a==1){
                                std::cout<<"Colombia"<<" y "<<"Brasil"<<" empatan"<<"\n";
                            }
                            else{
                                std::cout<<"Brasil"<<" le gana a "<<"Colombia"<<"\n";
                            }
                            if (b==0){
                                std::cout<<"Paraguay"<<" le gana a "<<"Uruguay"<<"\n";
                            }
                            else if (b==1){
                                std::cout<<"Paraguay"<<" y "<<"Uruguay"<<" empatan"<<"\n";
                            }
                            else{
                                std::cout<<"Uruguay"<<" le gana a "<<"Paraguay"<<"\n";
                            }
                            if (c==0){
                                std::cout<<"Chile"<<" le gana a "<<"Bolivia"<<"\n";
                            }
                            else if (c==1){
                                std::cout<<"Chile"<<" y "<<"Bolivia"<<" empatan"<<"\n";
                            }
                            else{
                                std::cout<<"Bolivia"<<" le gana a "<<"Chile"<<"\n";
                            }
                            if (d==0){
                                std::cout<<"Peru"<<" le gana a "<<"Ecuador"<<"\n";
                            }
                            else if (d==1){
                                std::cout<<"Peru"<<" y "<<"Ecuador"<<" empatan"<<"\n";
                            }
                            else{
                                std::cout<<"Ecuador"<<" le gana a "<<"Peru"<<"\n";
                            }
                            if (e==0){
                                std::cout<<"Argentina"<<" le gana a "<<"Venezuela"<<"\n";
                            }
                            else if (e==1){
                                std::cout<<"Argentina"<<" y "<<"Venezuela"<<" empatan"<<"\n";
                            }
                            else{
                                std::cout<<"Venezuela"<<" le gana a "<<"Argentina"<<"\n";
                            }
                            //for(int i=0;i<10;i++){
                            //    cout<<i+1<<")  "<< paises[orden[i]] <<"\t"<< puntos[orden[i]]<<"\n";
                            //}
                            std::cout<<"---\n";
                            contador++;
                        }
                    }
                    puntos[9]-=3;
                }
                puntos[7]-=3;
            }
            puntos[5]-=3;
        }
        puntos[3]-=3;
    }
    std::cout<<"Hay "<< contador <<" posibles resultados en los que Peru puede clasificar al mundial 2018\n";//cantidad de posibles resultados en los que Peru tiene posibilidades de clasificar
    std::cout<< "Es " <<((float)contador/243)*100 << "% probable que Peru clasifique al mundial"<<"\n";//porcentaje de posibilidades que peru tiene de clasificar
    return 0;
}
