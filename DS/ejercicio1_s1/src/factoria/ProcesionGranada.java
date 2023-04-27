/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package factoria;

/**
 *
 * @author Alberto
 */
public class ProcesionGranada extends Procesion{
    
     private static int numProcesionesGranada  = 0;
    
    
    public ProcesionGranada(){
        this.idProcesion = numProcesionesGranada ;
        numProcesionesGranada++;
        duracion = 60 ;
        this.lugar = Ciudades.GRANADA ;
           
    }
    
    
}
