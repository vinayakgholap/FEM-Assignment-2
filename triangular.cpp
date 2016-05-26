
#include "triangular.h"
#define coordiante 2
#define delta 0.01

Initialisation::Initialisation(){;}

//---------------------------------  Process --------------------------

void Initialisation::process(void){

    readFile();

    k_waveNumber();

}

//---------------------------------- Read vertex and faces from file ------------
void Initialisation::readFile(void)
{

    string line,temp;
    int count=1,q=0,q_=0;
    size_t sz;

    std::ifstream input("unit_circle.txt");
        if (input.is_open())
         {
           while ( count!=3020 )
           {
            getline (input,line);
               if(count >2 && count<1042)     //read vertex
               {
               v.verNum= std::stod(line,&sz);
               v.x= std::stod(line.substr(sz));
               temp=line.substr(sz);
               q_= std::stod(temp,&sz);
               v.y=std::stod(temp.substr(sz));
               V.push_back(v);
               //std::cout<< q << '\t' << v.x << '\t' << v.y << std::endl;
               }
               else if(count >1043)
               {
               f.v1.verNum= std::stod(line,&sz);
               f.v2.verNum= std::stod(line.substr(sz));
               temp=line.substr(sz);
               q_= std::stod(temp,&sz);
               f.v3.verNum=std::stod(temp.substr(sz));

               F.push_back(f);
                //std::cout<< f.v1.verNum << '\t' << f.v2.verNum << '\t' << f.v3.verNum << std::endl;
               }
            count++;
           }
           cout<< F[0].v1.verNum << endl;
           cout<< V[F[0].v1.verNum].x <<endl;
           input.close();
         }
    else std::cout << "Unable to open file" << std::endl;

}

//---------------------------------- waveNumber store to file---------------------------

void Initialisation::k_waveNumber()
{
      real k;
      real a=(100 + delta);

      ofstream output("ksq.txt");
      if(output.is_open()){

          for(intg n=0;n<1039;n++){
             k= a*exp(-50*((V[n].x * V[n].x) + (V[n].y * V[n].y)))-100;

            K.push_back(k);

            output<<V[n].x<<"\t"<< V[n].y<<"\t"<<k<<"\n";
        }
      }
    else {cout<<"unable to open file"<<endl;}

output.close();


}
//--------------------------------------------------------------------------



