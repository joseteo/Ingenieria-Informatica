/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package factoria;

import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author Alberto
 */
public abstract class  Procesion extends Thread {
    
    double duracion ;
    int idProcesion ;
    Ciudades lugar ;
    boolean cancelada;
    double tiempoAbandono;
    String Nombre_procesion ; 
    ArrayList<Costalero> Costaleros = new ArrayList<Costalero>() ;
    
    
    public void anniade(Costalero costalero){
        Costaleros.add(costalero) ;
    }
    
    public double numCostaleros(){
        return Costaleros.size();
    }
    
    public void comenzarProcesion(){
        System.out.println(toString() + " ha comenzado") ;
        
        for(int i = 0; i < numCostaleros(); i++){
            Costaleros.get(i).start() ;
            
        }
        
    }
    @Override
    public String toString(){
        return "ID procesion= " + this.idProcesion + " Lugar= " + lugar +
                " Cancelada= " + cancelada ;           
    } 
    
    
    @Override
    public void run()
    {
        int num_abandonos = (int) (0.1 * numCostaleros() ) ;
        Random aleatorio = new Random();
        int tiempo_abandonar = (int)aleatorio.nextInt((int)duracion); 
        for(int i = 0 ; i < num_abandonos ; i++)
        {
            if(!Costaleros.get(i).lesionado()) 
                Costaleros.get(i).Lesionar(tiempo_abandonar);        
        }
            
        comenzarProcesion();
        
        
        //sleep
    }
    
    
    
    
    
    
}
