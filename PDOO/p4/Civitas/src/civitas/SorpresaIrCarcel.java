/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package civitas;

import java.util.ArrayList;

/**
 *
 * @author aida
 */
public class SorpresaIrCarcel extends Sorpresa {
    
    private Tablero tablero;
    
    @Override
    void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            informe(actual, todos);
            todos.get(actual).encarcelar(tablero.getCarcel());
        }
    }
    
    SorpresaIrCarcel(Tablero tablero){
        //Para constuir la sorpresa que envia a la carcel
        super("Debes ir a la carcel");
        this.tablero = tablero;
    }
    
    @Override
    public String toString(){
        return "Sorpresa{" + "texto=" + super.getTexto() + "}";
    }
}
