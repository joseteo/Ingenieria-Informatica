
package civitas;

import java.util.ArrayList;
import java.util.Random;


public class Dado {
    
    private Random random;
    private int ultimoResultado;
    private Boolean debug;
    
    static final private Dado instance = new Dado();
    private static int SalidaCarcel = 5;
    
    private Dado(){
        debug = true;
        ultimoResultado = 0;
        random = new Random();
     }
    
    static public Dado getInstance(){
        return instance;
    }
    
    int tirar(){
        int resultado;
        if (debug == false){
            resultado = random.nextInt(6)+1; //el +1 es para que el dado vaya de 1 a 6 (es decir, no tome el valor 0)
        } else {
            resultado = 1;
        }
        ultimoResultado = resultado;
        return resultado;
    }
    
    Boolean salgoDeLaCarcel(){
        Boolean resultado = false;
        if (getUltimoResultado() == 6){
            resultado = true;
        }
        return resultado;
    }
    
    int quienEmpieza(int n){
        int resultado;
        resultado = random.nextInt(n);
        return resultado;
    }
    
    /*pacage*/ public void setDebug(Boolean d){
        debug = d;
        if (debug == true){
            Diario.getInstance().ocurreEvento("dado debug true");
        } else {
            Diario.getInstance().ocurreEvento("dado debug false");
        }
    }
    
    int getUltimoResultado(){
        return ultimoResultado;
    }
    
}
