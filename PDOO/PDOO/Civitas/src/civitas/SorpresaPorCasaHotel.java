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
public class SorpresaPorCasaHotel extends Sorpresa{

    private int valor;
    
    SorpresaPorCasaHotel(String texto, int valor) {
        super(texto);
        this.valor = valor;
    }
    
    @Override
    public String toString(){
        return "Sorpresa{" + "texto=" + super.toString()+ ", valor=" + Integer.toString(valor) + "}";
    }
    
    @Override
    void aplicarAJugador(int actual, ArrayList<Jugador> todos){
        informe(actual, todos);
        todos.get(actual).modificarSaldo(this.valor * todos.get(actual).cantidadCasasHoteles());
    }
}
