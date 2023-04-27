/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;
 
/**
 *
 * @author joseteo
 */
public class Casilla {
    
    private String Nombre;

    Casilla( String nombre){
        this.Nombre = nombre;
    }
    
    public String getNombre(){
        return Nombre;
    }
    
    void informe (int iactual, ArrayList<Jugador> todos){
        Diario.getInstance().ocurreEvento("El jugador " + (iactual+1) + " ha caido en la casilla con informacion " + toString());
    }
    
    
    public void recibeJugador(int iactual, ArrayList<Jugador> todos){
        informe(iactual, todos);
    }
 
    @Override
    public String toString(){
        String aux = "Descanso";
        
        return aux;
    }
    
}
