#include <iostream>

using namespace std;

int main()
{
    int puntos[]={25,36,21,24,23,10,21,20,23,7};
    int auxiliar[]={0,1,2,3,4,5,6,7,8,9};
    int maximo= 0;
    int imaximo= 0;
    int orden[]={0,1,2,3,4,5,6,7,8,9};
    bool flag=false;
    int contador=0;
    string paises[]={"Colombia","Brasil","Paraguay","Uruguay","Chile","Bolivia","Peru","Ecuador","Argentina","Venezuela"};
    for(int a=0;a<3;a++){
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
        for(int b=0;b<3;b++){
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
            for(int c=0;c<3;c++){
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
                for(int d=0;d<3;d++){
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
                    for(int e=0;e<3;e++){
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
                        for (int i=0;i<10;i++){
                            auxiliar[i]=puntos[i];
                        }
                        flag=false;
                        for(int i=0;i<10;i++){
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
                            if (imaximo==6){
                                if (i<5){
                                    flag = true;
                                }
                                else if(i==5 && puntos[7]==puntos[orden[4]]){
                                    flag=true;
                                }
                            }
                        }
                        if (flag==true){
                            if (a==0){
                                cout<<paises[0]<<" le gana a "<<paises[1]<<endl;
                            }
                            else if (a==1){
                                cout<<paises[0]<<" y "<<paises[1]<<" empatan"<<endl;
                            }
                            else{
                                cout<<paises[1]<<" le gana a "<<paises[0]<<endl;
                            }
                            if (b==0){
                                cout<<paises[2]<<" le gana a "<<paises[3]<<endl;
                            }
                            else if (b==1){
                                cout<<paises[2]<<" y "<<paises[3]<<" empatan"<<endl;
                            }
                            else{
                                cout<<paises[3]<<" le gana a "<<paises[2]<<endl;
                            }
                            if (c==0){
                                cout<<paises[4]<<" le gana a "<<paises[5]<<endl;
                            }
                            else if (c==1){
                                cout<<paises[4]<<" y "<<paises[5]<<" empatan"<<endl;
                            }
                            else{
                                cout<<paises[5]<<" le gana a "<<paises[4]<<endl;
                            }
                            if (d==0){
                                cout<<paises[6]<<" le gana a "<<paises[7]<<endl;
                            }
                            else if (d==1){
                                cout<<paises[6]<<" y "<<paises[7]<<" empatan"<<endl;
                            }
                            else{
                                cout<<paises[7]<<" le gana a "<<paises[5]<<endl;
                            }
                            if (e==0){
                                cout<<paises[8]<<" le gana a "<<paises[9]<<endl;
                            }
                            else if (e==1){
                                cout<<paises[8]<<" y "<<paises[9]<<" empatan"<<endl;
                            }
                            else{
                                cout<<paises[9]<<" le gana a "<<paises[8]<<endl;
                            }
                            for(int i=0;i<10;i++){
                                cout<<i+1<<")  "<< paises[orden[i]] <<"\t"<< puntos[orden[i]]<<endl;
                            }
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
    cout<<"Hay "<< contador <<" posibles resultados en los que Peru puede clasificar al mundial 2018\n";
    cout<< "Es " <<((float)contador/243)*100 << "% probable que Peru clasifique al mundial"<<endl;
    return 0;
}
