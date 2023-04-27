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
public abstract class Sorpresa {
    private String texto;

    abstract void aplicarAJugador(int actual, ArrayList<Jugador> todos);
    
    void informe(int actual, ArrayList<Jugador> todos){
        Diario.getInstance().ocurreEvento("Al jugador " + (actual+1) + " se le ha aplicado una sorpresa con informacion " + toString());
    }

    Sorpresa(String texto){
        this.texto = texto;
    }
    
    @Override
    public String toString(){
        return this.texto;
    }
    
}
