/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author joseteo
 */
public class Tablero {
    
    private ArrayList<Casilla> casillas;
    private boolean porSalida;
    
    Tablero(){
        this.casillas = new ArrayList<>();
        Casilla Salida = new Casilla("Salida");
        this.casillas.add(Salida);
        this.porSalida=false;
    }
    
    private Boolean correcto(int numCasilla){
        Boolean resultado=false;
        if (numCasilla < this.casillas.size())
            resultado = true;
        
        return resultado;
    }
    
    Boolean computarPasoPorSalida(){
        return this.porSalida;
    }
    
    void aniadeCasilla(Casilla casilla){
        this.casillas.add(casilla);
    }
    
    Casilla getCasilla(int numCasilla){
        Casilla resultado = null;
        if(correcto(numCasilla))
            resultado = this.casillas.get(numCasilla);
        
        return resultado;
    }
    
    int nuevaPosicion(int actual, int tirada){
        int resultado;
        
        resultado = actual + tirada;
        if (correcto(resultado) == false){
            resultado = resultado%this.casillas.size();
            this.porSalida=true;
        }
        return resultado;
    }
    
    
}
