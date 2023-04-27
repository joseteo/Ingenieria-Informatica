/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author emilio
 */
public class Tablero {
    //Relaciones 
    private ArrayList<Casilla> tablero;
    //atributos de instancia
    //private ArrayList<Casilla> casillas;
    
    private int porSalida;
    //constructor
    Tablero(){
        this.tablero = new ArrayList<>();
        Casilla salida= new Casilla("Salida");
        this.tablero.add(salida);
        this.porSalida=0;
    }
    //metodo de instancia privado
    private boolean correcto(int numCasilla){
        if(numCasilla <= tablero.size()){
            return true;
        }else{
            return false;
        }
    }
    //metodo de instancia privado
    private boolean correcto(){
        if(tablero.size() > 0){
            return true;
        }else{
            return false;
        }
    }
    //metodos de instancia --- Visibilidad de paquete
    protected boolean computarPasoPorSalida(){

        if(porSalida>0){
            porSalida--;
            return true;
            
        }else{
            return false;
        }
        
    }
    
    void añadeCasilla(Casilla casilla){
        this.tablero.add(casilla);
    }
    
   
    
    public Casilla getCasilla(int numCasilla){
        if(correcto(numCasilla)){
            return this.tablero.get(numCasilla);
        }else{
            return null;
        }
    }
    
    public ArrayList<Casilla> getCasillas(){
        return tablero;
    }
    
    int getPorSalida(){
        int aux = porSalida;
        if(porSalida > 0){
            porSalida--;
            return aux;
        }
        return porSalida;
    }
    
    
    
    protected int nuevaPosicion(int actual, int tirada){
        actual=actual+tirada;
        
            
        
        if(actual > this.tablero.size()-1){
            actual=actual % this.tablero.size();
            this.porSalida++;
        }
       
        
        
        return actual; 
    }  
}
