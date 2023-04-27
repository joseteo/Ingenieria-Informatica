/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package factoria;

import java.util.ArrayList;

/**
 *
 * @author Alberto
 */
public class ProcesionMalaga extends Procesion {
    private static int numProcesionesMalaga  = 0;
    
    ArrayList<Costalero> Costaleros = new ArrayList<Costalero>() ;
    
    public ProcesionMalaga(){
        this.idProcesion = numProcesionesMalaga ;
        duracion = 60;
        numProcesionesMalaga++;
        this.lugar = Ciudades.MALAGA ;      
    }
}
