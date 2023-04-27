/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package factoria;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Abel
 */
public abstract class Costalero extends Thread {
    int id_costalero ;
    Ciudades tipo ;
    boolean seLesiona = false;
    double duracion ;
    
    boolean lesionado(){
        return seLesiona ;
        
    }
    
    @Override
    public String toString(){
        return "El costalero " + id_costalero + " de " + tipo +  " lesionado " + seLesiona ;
    }
    
    
    void Lesionar(int tiempo){
        seLesiona = true ;
        duracion = tiempo ;   
    }
    
    @Override
    public void run() {
        
        
        try { 
            sleep(60000);
        } catch (InterruptedException ex) {
            Logger.getLogger(Costalero.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
        if(lesionado())
            System.out.println(toString() + ", se lesiono en el instante: " + duracion);
        else
            System.out.println(toString() + ", finalizo la procesion ");
    
    }
    
    
    
    
    
}
