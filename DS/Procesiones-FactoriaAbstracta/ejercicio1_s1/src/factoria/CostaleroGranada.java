/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package factoria;

/**
 *
 * @author Alberto
 */
public class CostaleroGranada extends Costalero{
    
        private static int numCostalerosGranada  = 0;
    
    public CostaleroGranada(){
        this.id_costalero = numCostalerosGranada ;
        numCostalerosGranada++ ;
        this.tipo = Ciudades.GRANADA ;
         
                
                
    }
    
}
