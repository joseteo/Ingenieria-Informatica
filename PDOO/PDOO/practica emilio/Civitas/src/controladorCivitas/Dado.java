/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Singleton.java to edit this template
 */
package controladorCivitas;

import civitas.Diario;
import civitas.Diario;
import java.util.Random;

/**
 *
 * @author emilio
 */
public class Dado {
    
    //atributos de clase
    static final private Dado instance = new Dado();
    private final int SalidaCarcel=5;
    //atributos de instancia
    private Random random = new Random();//inicializar random
    private int ultimoResultado;
    private boolean debug;
    
    
    private Dado() {
        this.debug=false;
        this.ultimoResultado=0;
    }
    
    public static Dado getInstance() {
        return instance;
    }
    
    private static class DadoHolder {

        private static final Dado INSTANCE = new Dado();
    }
    //metodos de isntancia con visibilidad de paquete
    int tirar(){
        if(this.debug){
            ultimoResultado=1;
        }else{
            Random r=new Random();
            ultimoResultado=r.nextInt(6);   
        }
        return ultimoResultado;
    }
    
    //Crear situacion de que los jugadores vayan de 3 en 3
//    int tirar3(){
//        if(this.debug){
//            ultimoResultado=1;
//        }else{
//            Random r=new Random();
//            ultimoResultado=3   
//        }
//        return ultimoResultado;
//    }
    int quienEmpieza(int n){
        int empieza;
        Random r= new Random();
        empieza=r.nextInt(n);
        return empieza;
    }
    
    void setDebug(boolean d){
        if(d){
            this.debug=d;
            Diario.getInstance().ocurreEvento("Se ha activado el modo DEBUG del Dado. Last: " + instance);
        }else{
            this.debug=d;
            Diario.getInstance().ocurreEvento("Se ha desactivado el modo DEBUG del Dado. Last: " + instance);
        }
    }
    
    int getUltimoResultado(){
        return this.ultimoResultado;
    }
    
    
    
    
    
    
}
