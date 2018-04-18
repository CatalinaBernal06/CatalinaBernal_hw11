#include <iostream>

/* Runge-Kuta */

double valor_k(double t, double x, double delta_t);
double valor_k2(double V,  double delta_t);
double dV_dt(double t, double x);
double dx_dt(double V);

int main(){

  /*Estos valores son las condiciones iniciales del problema */
  double x0 = 100;
  double x = x0;
  double V = 0;
  double t = 0;
  double delta_t = 0.001;
  double N = x0/delta_t;

  for(int i=0; i<N; i++){

    if(x>0.01*x0){

      V = V + valor_k(t, x, delta_t);
      x = x + valor_k2(V, delta_t);
      t = t + delta_t;
     std::cout << x << " " << V << " " << t << std::endl;
    } 
   
  }
}

/* Define y retorna la segunda derivada de la posicion respecto al tiempo */

double dV_dt(double t,  double x){
  float G = 10;
  float M = 1000;
  float m = 22;
  return -1.0*(G*M)/x*x;
}

/* define la primera derivada de x respecto al tiempo, retorna la velocidad */
double dx_dt(double V){
  return V;
}

/* las dos funciones definen los valores de k_i propios del metodo de Runge-Kuta.
   EL primero corresponde a los valores para la segunda derivada, el segundo, retorna el valor correspondiente a k_i de la primera derivada */

double valor_k(double t, double x, double delta_t){
  double k1 = dV_dt(t, x);
  double k2 = dV_dt(t + delta_t/2, x+(delta_t/2)*k1);
  double k3 = dV_dt(t + delta_t/2, x+(delta_t/2)*k2);
  double k4 = dV_dt(t + delta_t, x+delta_t*k3);

  return (delta_t/6)*(k1+2*k2+2*k3+k4);
}


double valor_k2(double V,  double delta_t){
  double k1 = dx_dt(V);
  double k2 = dx_dt(V+(delta_t/2)*k1);
  double k3 = dx_dt(V+(delta_t/2)*k2);
  double k4 = dx_dt(V+delta_t*k3);

  return (delta_t/6)*(k1+2*k2+2*k3+k4);
}
