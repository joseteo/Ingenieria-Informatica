/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author teo
 */
public class CasillaSorpresa extends Casilla{
    
    private Sorpresa sorpresa;
    private MazoSorpresas mazo; 
    
    CasillaSorpresa( String nombre, MazoSorpresas mazo){
        super(nombre);
        this.mazo = mazo;
    }
    
    
    @Override
    public void recibeJugador(int iactual, ArrayList<Jugador> todos){
        sorpresa = mazo.siguiente();
        super.informe(iactual, todos);
        sorpresa.aplicarAJugador(iactual, todos);
    }
    
    @Override
    public String toString(){
        String aux = "Casilla Sorpresa" + super.getNombre();
        
        return aux;
    }
    
}
