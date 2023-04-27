/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package factoria;

/**
 *
 * @author Alberto
 */
public class CostaleroMalaga extends Costalero{
    private static int numCostalerosMalaga  = 0;
    
    public CostaleroMalaga(){
        this.id_costalero = numCostalerosMalaga ;
        numCostalerosMalaga++ ;
        this.tipo = Ciudades.MALAGA ;
    }
              
}
