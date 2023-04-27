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
public class SorpresaPagarCobrar extends Sorpresa {
    
    private int valor;
    
    @Override
    void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        if (jugadorCorrecto(actual, todos)){
            informe(actual, todos);
            todos.get(actual).modificarSaldo(valor);
        }
    }
    
    SorpresaPagarCobrar(int valor, String texto){
        //Para el resto de sorpresas
        super(texto);
        this.valor = valor;
    }
    
    @Override
    public String toString(){
        return "Sorpresa{" + "texto=" + super.getTexto() + ", valor=" + Integer.toString(valor) + "}";
    }
}
